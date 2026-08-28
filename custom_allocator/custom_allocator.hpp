#pragma once
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iterator>
#include <memory>
#include <new>
#include <stdexcept>

template <typename T, size_t N>
class PoolAllocator
{
   private:
    struct Node
    {
        T*     data;
        size_t capacity;
        size_t used;
        Node*  next;

        explicit Node (size_t count)
            : data (static_cast<T*> (::operator new (count * sizeof (T)))), capacity (count), used (0), next (nullptr)
        {
        }

        ~Node () { ::operator delete (data); }
    };

    struct Pool
    {
        Node* head = nullptr;
        Node* tail = nullptr;

        Pool ()                       = default;
        Pool (const Pool&)            = delete;
        Pool& operator= (const Pool&) = delete;

        T* allocate (size_t count)
        {
            if (tail && tail->used + count <= tail->capacity)
            {
                T* ptr = tail->data + tail->used;
                tail->used += count;
                return ptr;
            }

            size_t new_cap = tail ? tail->capacity * 2 : N;
            new_cap        = std::max (new_cap, count);

            auto* chunk = new Node (new_cap);
            if (tail)
            {
                tail->next = chunk;
            }
            else
            {
                head = chunk;
            }
            tail = chunk;

            T* ptr     = tail->data;
            tail->used = count;
            return ptr;
        }

        ~Pool ()
        {
            auto* cur = head;
            while (cur)
            {
                auto* next = cur->next;
                delete cur;
                cur = next;
            }
        }
    };

    std::shared_ptr<Pool> mem;

   public:
    using value_type = T;

    PoolAllocator () : mem (std::make_shared<Pool> ()) {}

    ~PoolAllocator () = default;

    T* allocate (size_t count) { return mem->allocate (count); }

    void deallocate (T* /*unused*/, size_t /*unused*/) noexcept {}

    template <typename U>
    struct rebind
    {
        using other = PoolAllocator<U, N>;
    };

    template <typename U>
    PoolAllocator (const PoolAllocator<U, N>&) : mem (std::make_shared<Pool> ())
    {
    }

    PoolAllocator (const PoolAllocator&)            = default;
    PoolAllocator (PoolAllocator&&)                 = default;
    PoolAllocator& operator= (const PoolAllocator&) = delete;

    template <typename U, size_t M>
    bool operator!= (const PoolAllocator<U, M>& other) const noexcept
    {
        return !(*this == other);
    }

    template <typename U, size_t M>
    bool operator== (const PoolAllocator<U, M>& other) const noexcept
    {
        return mem.get () == other.mem.get ();
    }

    using propagate_on_container_copy_assignment = std::true_type;
    using propagate_on_container_move_assignment = std::true_type;
    using propagate_on_container_swap            = std::true_type;

    template <typename U, size_t M>
    friend class PoolAllocator;
};
