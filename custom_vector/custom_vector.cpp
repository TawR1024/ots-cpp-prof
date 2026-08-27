#pragma once
#include <algorithm>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <utility>

namespace vector
{
template <typename T, typename Allocator = std::allocator<T>>
class CustomVector
{
   public:
    using value_type      = T;
    using allocator_type  = Allocator;
    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference       = T&;
    using const_reference = const T&;
    using pointer         = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer   = typename std::allocator_traits<Allocator>::const_pointer;
    using const_iterator  = const_pointer;
    using iterator        = pointer;

    using alloc_traits = std::allocator_traits<Allocator>;

   private:
    pointer   data_     = nullptr;
    size_type size_     = 0;
    size_type capacity_ = 0;
    Allocator alloc_;

    void reallocate (size_type new_capacity)
    {
        pointer new_data = alloc_traits::allocate (alloc_, new_capacity);
        for (size_type i = 0; i < size_; ++i)
        {
            alloc_traits::construct (alloc_, new_data + i, std::move_if_noexcept (data_[i]));
            alloc_traits::destroy (alloc_, data_ + i);
        }

        if (data_)
        {
            alloc_traits::deallocate (alloc_, data_, capacity_);
        }

        data_     = new_data;
        capacity_ = new_capacity;
    }

    void ensure_capacity (size_type required)
    {
        if (required <= capacity_)
        {
            return;
        }

        size_type new_cap = (capacity_ == 0) ? 1 : capacity_ * 2;
        new_cap           = std::max (new_cap, required);

        reallocate (new_cap);
    }

    void destroy_deallocate ()
    {
        for (size_type i = 0; i < size_; ++i)
        {
            alloc_traits::destroy (alloc_, data_ + i);
        }
        if (data_)
        {
            alloc_traits::deallocate (alloc_, data_, capacity_);
        }
        data_     = nullptr;
        size_     = 0;
        capacity_ = 0;
    }

   public:
    CustomVector () noexcept (noexcept (Allocator ())) : alloc_ (), data_ (nullptr) {};

    explicit CustomVector (const Allocator& alloc) noexcept : alloc_ (alloc), data_ (nullptr) {}

    explicit CustomVector (size_type count, const T& value = T (), const Allocator& alloc = Allocator ())
        : alloc_ (alloc), data_ (nullptr)
    {
        if (count > 0)
        {
            reallocate (count);
            for (size_type i = 0; i < count; ++i)
            {
                alloc_traits::construct (alloc_, data_ + i, value);
            }
            size_ = count;
        }
    }

    // Copy constructor
    CustomVector (const CustomVector& other)
        : alloc_ (alloc_traits::select_on_container_copy_construction (other.alloc_)), data_ (nullptr)
    {
        if (other.size_ > 0)
        {
            reallocate (other.size_);
            for (size_type i = 0; i < other.size_; ++i)
            {
                alloc_traits::construct (alloc_, data_ + i, other.data_[i]);
            }
            size_ = other.size_;
        }
    }

    // Move constructor
    CustomVector (CustomVector&& other) noexcept
        : alloc_ (std::move (other.alloc_)), data_ (other.data_), size_ (other.size_), capacity_ (other.capacity_)
    {
        other.data_     = nullptr;
        other.size_     = 0;
        other.capacity_ = 0;
    }

    ~CustomVector () { destroy_deallocate (); }

    // Copy assignment
    CustomVector& operator= (const CustomVector& other)
    {
        if (this == &other)
        {
            return *this;
        }

        if constexpr (alloc_traits::propagate_on_container_copy_assignment::value)
        {
            if (alloc_ != other.alloc_)
            {
                destroy_deallocate ();
                alloc_ = other.alloc_;
            }
        }

        if (other.size_ > capacity_)
        {
            if (!alloc_traits::propagate_on_container_copy_assignment::value || data_ == nullptr)
            {
                // Аллокатор не менялся — освобождаем через него
                destroy_deallocate ();
            }
            reallocate (other.size_);
        }
        else
        {
            for (size_type i = 0; i < size_; ++i)
            {
                alloc_traits::destroy (alloc_, data_ + i);
            }
        }

        for (size_type i = 0; i < other.size_; ++i)
        {
            alloc_traits::construct (alloc_, data_ + i, other.data_[i]);
        }
        size_ = other.size_;

        return *this;
    }

    // Move assignment
    CustomVector& operator= (CustomVector&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        if constexpr (alloc_traits::propagate_on_container_move_assignment::value)
        {
            // Аллокатор перемещается → забираем ресурсы
            destroy_deallocate ();
            alloc_    = std::move (other.alloc_);
            data_     = other.data_;
            size_     = other.size_;
            capacity_ = other.capacity_;
        }
        else
        {
            if (alloc_ == other.alloc_)
            {
                destroy_deallocate ();
                data_     = other.data_;
                size_     = other.size_;
                capacity_ = other.capacity_;
            }
            else
            {
                destroy_deallocate ();
                if (other.size_ > 0)
                {
                    reallocate (other.size_);
                    for (size_type i = 0; i < other.size_; ++i)
                    {
                        alloc_traits::construct (alloc_, data_ + i, std::move (other.data_[i]));
                        alloc_traits::destroy (other.alloc_, other.data_ + i);
                    }
                    size_ = other.size_;
                }
                other.alloc_traits::deallocate (other.alloc_, other.data_, other.capacity_);
            }
        }

        other.data_     = nullptr;
        other.size_     = 0;
        other.capacity_ = 0;

        return *this;
    }

    reference       operator[] (size_type index) { return data_[index]; }
    const_reference operator[] (size_type index) const { return data_[index]; }

    reference at (size_type index)
    {
        if (index >= size_)
        {
            throw std::out_of_range ("CustomVector::at — index out of range");
        }
        return data_[index];
    }

    const_reference at (size_type index) const
    {
        if (index >= size_)
        {
            throw std::out_of_range ("CustomVector::at — index out of range");
        }
        return data_[index];
    }

    void push_back (const T& value)
    {
        ensure_capacity (size_ + 1);
        alloc_traits::construct (alloc_, data_ + size_, value);
        ++size_;
    }

    void push_back (T&& value)
    {
        ensure_capacity (size_ + 1);
        alloc_traits::construct (alloc_, data_ + size_, std::move (value));
        ++size_;
    }

    template <typename... Args>
    reference emplace_back (Args&&... args)
    {
        ensure_capacity (size_ + 1);
        alloc_traits::construct (alloc_, data_ + size_, std::forward<Args> (args)...);
        return data_[size_++];
    }

    void pop_back ()
    {
        if (size_ > 0)
        {
            --size_;
            alloc_traits::destroy (alloc_, data_ + size_);
        }
    }

    void clear () noexcept
    {
        for (size_type i = 0; i < size_; ++i)
        {
            alloc_traits::destroy (alloc_, data_ + i);
        }
        size_ = 0;
    }

    void swap (CustomVector& other) noexcept
    {
        using std::swap;

        if constexpr (alloc_traits::propagate_on_container_swap::value)
        {
            swap (alloc_, other.alloc_);
        }

        swap (data_, other.data_);
        swap (size_, other.size_);
        swap (capacity_, other.capacity_);
    }

    iterator       begin () noexcept { return data_; }
    const_iterator begin () const noexcept { return data_; }
    iterator       end () noexcept { return data_ + size_; }
    const_iterator end () const noexcept { return data_ + size_; }

    size_type size () const noexcept { return size_; }
    size_type capacity () const noexcept { return capacity_; }
    bool      empty () const noexcept { return size_ == 0; }

    allocator_type get_allocator () const noexcept { return alloc_; }
};
}  // namespace vector