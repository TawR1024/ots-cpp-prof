#pragma once
#include <cstddef>
#include <cstdlib>
#include <memory>
#include <new>
#include <stdexcept>

template <typename T, std::size_t N>
class PoolAllocator
{
   private:
    struct PoolState
    {
        T*          pool;
        std::size_t offset = 0;
        ~PoolState () { ::operator delete (pool); }
    };
    std::shared_ptr<PoolState> state_;

    T* pool () const noexcept { return state_ ? state_->pool : nullptr; }

   public:
    using value_type = T;

    PoolAllocator () : state_ (std::make_shared<PoolState> ())
    {
        state_->pool = static_cast<T*> (::operator new (N * sizeof (T)));
        if (!state_->pool)
            throw std::bad_alloc ();
    }

    ~PoolAllocator () = default;

    T* allocate (std::size_t size)
    {
        if (size != 1 || state_->offset >= N)
            throw std::bad_alloc ();
        return &state_->pool[state_->offset++];
    }

    void deallocate (T*, std::size_t) noexcept
    {
        // cannot deallocate for 1 element
    }

    template <typename U>
    struct rebind
    {
        using other = PoolAllocator<U, N>;
    };

    // rebind construct — отдельный пул для другого типа
    template <typename U>
    PoolAllocator (const PoolAllocator<U, N>&) : state_ (std::make_shared<PoolState> ())
    {
        state_->pool = static_cast<T*> (::operator new (N * sizeof (T), std::nothrow));
        if (!state_->pool)
            throw std::bad_alloc ();
    }

    // copy construct — разделяет тот же пул
    PoolAllocator (const PoolAllocator&) = default;
    // move construct
    PoolAllocator (PoolAllocator&&) = default;

    PoolAllocator& operator= (const PoolAllocator&) = delete;

    template <typename U, std::size_t M>
    bool operator!= (const PoolAllocator<U, M>& other) const noexcept
    {
        return !(*this == other);
    }

    template <typename U, std::size_t M>
    bool operator== (const PoolAllocator<U, M>& other) const noexcept
    {
        return pool () == other.pool ();
    }

    using propagate_on_container_copy_assignment = std::true_type;
    using propagate_on_container_move_assignment = std::true_type;
    using propagate_on_container_swap_assignment = std::true_type;

    template <typename U, std::size_t M>
    friend class PoolAllocator;
};
