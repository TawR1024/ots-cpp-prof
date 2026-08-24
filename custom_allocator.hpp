#pragma once
#include "cstdlib"
#include "stdexcept"

template <typename T, std::size_t N>
class PoolAllocator
{
   private:
    T*          pool_;      // pool head
    std::size_t offset_;    // current allocated size;
    bool        is_owner_;  // defines whether allocator is ovwner of memory pool
   public:
    PoolAllocator () : pool_ (static_cast<T*> (::operator new (N * sizeof (T)))), offset_ (0), is_owner_ (true)
    {
        if (!pool_)
            throw std::bad_alloc;
    }
    ~PoolAllocator() {
        if(is_owner_){
            ::operator delete(pool_);
        }
    }

    T *allocate(std::size_t size) {
        if (size !=1 ||offset_ >= N) {
            throw std::bad_alloc;
        }else {
            return pool_[offset_++];
        }
    }

    void deallocate(T*, std::size_t) noexcept {
        // cannot deallocate for 1 element
    }

};