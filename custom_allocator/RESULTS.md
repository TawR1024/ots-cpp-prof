```bash
std:map std::alloc
0 1
1 1
2 2
3 6
4 24
5 120
6 720
7 5040
8 40320
9 362880

% time     seconds  usecs/call     calls      function
------ ----------- ----------- --------- --------------------
 50.23    0.001078         107        10 malloc
 39.52    0.000848          84        10 free
 10.25    0.000220         220         1 exit_group
------ ----------- ----------- --------- --------------------
100.00    0.002146                    21 total
```
```bash
heaptrack output will be written to "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75839.gz"
starting application, this might take some time...
default map
0 1
1 1
2 2
3 6
4 24
5 120
6 720
7 5040
8 40320
9 362880

heaptrack stats:
        allocations:            12
        leaked allocations:     1
        temporary allocations:  1
Heaptrack finished! Now run the following to investigate the data:

  heaptrack --analyze "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75839.gz"
root@lrn-7513-kulakov:~/ots-cpp-prof-3.0.2/build# heaptrack --analyze "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75839.gz"
reading file "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75839.gz" - please wait, this might take some time...
Debuggee command was: ./hw3-custom-allocator
finished reading file, now analyzing data:

MOST CALLS TO ALLOCATION FUNCTIONS
10 calls to allocation functions with 400B peak consumption from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
10 calls with 400B peak consumption from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_M_get_node()
      at /usr/include/c++/15/bits/stl_tree.h:1170
    std::_Rb_tree_node<>* std::_Rb_tree<>::_M_create_node<>(std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:1253
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Auto_node::_Auto_node<>(std::_Rb_tree<>&, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:2285
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_iterator<> std::_Rb_tree<>::_M_emplace_hint_unique<>(std::_Rb_tree_const_iterator<>, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:3084
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::map<>::operator[](int const&)
      at /usr/include/c++/15/bits/stl_map.h:536
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

1 calls to allocation functions with 73.73K peak consumption from
0x7edb452bf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1 calls with 73.73K peak consumption from:
    0x7edb4563e7ce
      in /lib64/ld-linux-x86-64.so.2
    0x7edb4563e8e3
      in /lib64/ld-linux-x86-64.so.2
    0x7edb4565b39f
      in /lib64/ld-linux-x86-64.so.2

1 calls to allocation functions with 1.02K peak consumption from
_IO_file_doallocate
  in /usr/lib/x86_64-linux-gnu/libc.so.6
1 calls with 1.02K peak consumption from:
    _IO_doallocbuf
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_overflow
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_xsputn
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_fwrite
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    std::basic_ostream<>& std::__ostream_insert<>(std::basic_ostream<>&, char const*, long)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    std::basic_ostream<>& std::operator<< <>(std::basic_ostream<>&, char const*)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:18
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator


PEAK MEMORY CONSUMERS
73.73K peak memory consumed over 1 calls from
0x7edb452bf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
73.73K consumed over 1 calls from:
    0x7edb4563e7ce
      in /lib64/ld-linux-x86-64.so.2
    0x7edb4563e8e3
      in /lib64/ld-linux-x86-64.so.2
    0x7edb4565b39f
      in /lib64/ld-linux-x86-64.so.2

1.02K peak memory consumed over 1 calls from
_IO_file_doallocate
  in /usr/lib/x86_64-linux-gnu/libc.so.6
1.02K consumed over 1 calls from:
    _IO_doallocbuf
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_overflow
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_xsputn
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_fwrite
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    std::basic_ostream<>& std::__ostream_insert<>(std::basic_ostream<>&, char const*, long)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    std::basic_ostream<>& std::operator<< <>(std::basic_ostream<>&, char const*)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:18
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

400B peak memory consumed over 10 calls from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
400B consumed over 10 calls from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_M_get_node()
      at /usr/include/c++/15/bits/stl_tree.h:1170
    std::_Rb_tree_node<>* std::_Rb_tree<>::_M_create_node<>(std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:1253
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Auto_node::_Auto_node<>(std::_Rb_tree<>&, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:2285
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_iterator<> std::_Rb_tree<>::_M_emplace_hint_unique<>(std::_Rb_tree_const_iterator<>, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:3084
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::map<>::operator[](int const&)
      at /usr/include/c++/15/bits/stl_map.h:536
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator


MOST TEMPORARY ALLOCATIONS
1 temporary allocations of 1 allocations in total (100.00%) from
0x7edb452bf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1 temporary allocations of 1 allocations in total (100.00%) from:
    0x7edb4563e7ce
      in /lib64/ld-linux-x86-64.so.2
    0x7edb4563e8e3
      in /lib64/ld-linux-x86-64.so.2
    0x7edb4565b39f
      in /lib64/ld-linux-x86-64.so.2

1 temporary allocations of 10 allocations in total (10.00%) from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
1 temporary allocations of 10 allocations in total (10.00%) from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_M_get_node()
      at /usr/include/c++/15/bits/stl_tree.h:1170
    std::_Rb_tree_node<>* std::_Rb_tree<>::_M_create_node<>(std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:1253
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Auto_node::_Auto_node<>(std::_Rb_tree<>&, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:2285
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_iterator<> std::_Rb_tree<>::_M_emplace_hint_unique<>(std::_Rb_tree_const_iterator<>, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:3084
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::map<>::operator[](int const&)
      at /usr/include/c++/15/bits/stl_map.h:536
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator


total runtime: 0.00s.
calls to allocation functions: 12 (12000/s)
temporary memory allocations: 2 (2000/s)
peak heap memory consumption: 75.15K
peak RSS (including heaptrack overhead): 5.14M
total memory leaked: 1.02K
```bash

```
---
```bash
std::map custom_alloc
0 1
1 1
2 2
3 6
4 24
5 120
6 720
7 5040
8 40320
9 362880

% time     seconds  usecs/call     calls      function
------ ----------- ----------- --------- --------------------
 41.44    0.000358         119         3 malloc
 31.37    0.000271          90         3 free
 27.20    0.000235         235         1 exit_group
------ ----------- ----------- --------- --------------------
100.00    0.000864                     7 total
```
```bash
heaptrack stats:
        allocations:            5
        leaked allocations:     1
        temporary allocations:  0
Heaptrack finished! Now run the following to investigate the data:

  heaptrack --analyze "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75397.gz"
root@lrn-7513-kulakov:~/ots-cpp-prof-3.0.2/build# heaptrack --analyze "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75397.gz"
reading file "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75397.gz" - please wait, this might take some time...
Debuggee command was: ./hw3-custom-allocator
finished reading file, now analyzing data:

MOST CALLS TO ALLOCATION FUNCTIONS
1 calls to allocation functions with 32B peak consumption from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
1 calls with 32B peak consumption from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__allocated_ptr<> std::__allocate_guarded<>(std::allocator<>&)
      at /usr/include/c++/15/bits/allocated_ptr.h:102
    std::__shared_count<>::__shared_count<>(PoolAllocator<>::Pool*&, std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:967
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__shared_ptr<>::__shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:1719
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<>::shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr.h:463
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<> std::make_shared<>()
      at /usr/include/c++/15/bits/shared_ptr.h:1008
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::PoolAllocator()
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:83
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Rb_tree_impl<>::_Rb_tree_impl()
      at /usr/include/c++/15/bits/stl_tree.h:1314
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Rb_tree()
      at /usr/include/c++/15/bits/stl_tree.h:1553
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::map<>::map()
      at /usr/include/c++/15/bits/stl_map.h:200
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:18
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

1 calls to allocation functions with 32B peak consumption from
PoolAllocator<>::Pool::allocate(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
1 calls with 32B peak consumption from:
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_M_get_node()
      at /usr/include/c++/15/bits/stl_tree.h:1170
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_node<>* std::_Rb_tree<>::_M_create_node<>(std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:1253
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Auto_node::_Auto_node<>(std::_Rb_tree<>&, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:2285
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_iterator<> std::_Rb_tree<>::_M_emplace_hint_unique<>(std::_Rb_tree_const_iterator<>, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:3084
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::map<>::operator[](int const&)
      at /usr/include/c++/15/bits/stl_map.h:536
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:21
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

1 calls to allocation functions with 400B peak consumption from
PoolAllocator<>::Node::Node(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:22
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
1 calls with 400B peak consumption from:
    PoolAllocator<>::Pool::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_M_get_node()
      at /usr/include/c++/15/bits/stl_tree.h:1170
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_node<>* std::_Rb_tree<>::_M_create_node<>(std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:1253
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Auto_node::_Auto_node<>(std::_Rb_tree<>&, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:2285
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_iterator<> std::_Rb_tree<>::_M_emplace_hint_unique<>(std::_Rb_tree_const_iterator<>, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:3084
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::map<>::operator[](int const&)
      at /usr/include/c++/15/bits/stl_map.h:536
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:21
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

1 calls to allocation functions with 73.73K peak consumption from
0x7b78652bf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1 calls with 73.73K peak consumption from:
    0x7b78656777ce
      in /lib64/ld-linux-x86-64.so.2
    0x7b78656778e3
      in /lib64/ld-linux-x86-64.so.2
    0x7b786569439f
      in /lib64/ld-linux-x86-64.so.2

1 calls to allocation functions with 1.02K peak consumption from
_IO_file_doallocate
  in /usr/lib/x86_64-linux-gnu/libc.so.6
1 calls with 1.02K peak consumption from:
    _IO_doallocbuf
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_overflow
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_xsputn
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_fwrite
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    std::ostreambuf_iterator<> std::num_put<>::_M_insert_int<>(std::ostreambuf_iterator<>, std::ios_base&, char, long) const
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    std::ostream& std::ostream::_M_insert<>(long)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:26
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator


PEAK MEMORY CONSUMERS
73.73K peak memory consumed over 1 calls from
0x7b78652bf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
73.73K consumed over 1 calls from:
    0x7b78656777ce
      in /lib64/ld-linux-x86-64.so.2
    0x7b78656778e3
      in /lib64/ld-linux-x86-64.so.2
    0x7b786569439f
      in /lib64/ld-linux-x86-64.so.2

1.02K peak memory consumed over 1 calls from
_IO_file_doallocate
  in /usr/lib/x86_64-linux-gnu/libc.so.6
1.02K consumed over 1 calls from:
    _IO_doallocbuf
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_overflow
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_xsputn
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_fwrite
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    std::ostreambuf_iterator<> std::num_put<>::_M_insert_int<>(std::ostreambuf_iterator<>, std::ios_base&, char, long) const
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    std::ostream& std::ostream::_M_insert<>(long)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:26
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

400B peak memory consumed over 1 calls from
PoolAllocator<>::Node::Node(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:22
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
400B consumed over 1 calls from:
    PoolAllocator<>::Pool::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_M_get_node()
      at /usr/include/c++/15/bits/stl_tree.h:1170
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_node<>* std::_Rb_tree<>::_M_create_node<>(std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:1253
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Auto_node::_Auto_node<>(std::_Rb_tree<>&, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:2285
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_iterator<> std::_Rb_tree<>::_M_emplace_hint_unique<>(std::_Rb_tree_const_iterator<>, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:3084
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::map<>::operator[](int const&)
      at /usr/include/c++/15/bits/stl_map.h:536
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:21
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

32B peak memory consumed over 1 calls from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
32B consumed over 1 calls from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__allocated_ptr<> std::__allocate_guarded<>(std::allocator<>&)
      at /usr/include/c++/15/bits/allocated_ptr.h:102
    std::__shared_count<>::__shared_count<>(PoolAllocator<>::Pool*&, std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:967
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__shared_ptr<>::__shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:1719
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<>::shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr.h:463
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<> std::make_shared<>()
      at /usr/include/c++/15/bits/shared_ptr.h:1008
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::PoolAllocator()
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:83
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Rb_tree_impl<>::_Rb_tree_impl()
      at /usr/include/c++/15/bits/stl_tree.h:1314
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Rb_tree()
      at /usr/include/c++/15/bits/stl_tree.h:1553
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::map<>::map()
      at /usr/include/c++/15/bits/stl_map.h:200
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:18
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

32B peak memory consumed over 1 calls from
PoolAllocator<>::Pool::allocate(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
32B consumed over 1 calls from:
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_M_get_node()
      at /usr/include/c++/15/bits/stl_tree.h:1170
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_node<>* std::_Rb_tree<>::_M_create_node<>(std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:1253
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree<>::_Auto_node::_Auto_node<>(std::_Rb_tree<>&, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:2285
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::_Rb_tree_iterator<> std::_Rb_tree<>::_M_emplace_hint_unique<>(std::_Rb_tree_const_iterator<>, std::piecewise_construct_t const&, std::tuple<>&&, std::tuple<>&&)
      at /usr/include/c++/15/bits/stl_tree.h:3084
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::map<>::operator[](int const&)
      at /usr/include/c++/15/bits/stl_map.h:536
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:21
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator


MOST TEMPORARY ALLOCATIONS
1 temporary allocations of 1 allocations in total (100.00%) from
0x7b78652bf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1 temporary allocations of 1 allocations in total (100.00%) from:
    0x7b78656777ce
      in /lib64/ld-linux-x86-64.so.2
    0x7b78656778e3
      in /lib64/ld-linux-x86-64.so.2
    0x7b786569439f
      in /lib64/ld-linux-x86-64.so.2


total runtime: 0.00s.
calls to allocation functions: 5 (5000/s)
temporary memory allocations: 1 (1000/s)
peak heap memory consumption: 75.22K
peak RSS (including heaptrack overhead): 5.08M
total memory leaked: 1.02K
```

---
```bash
custom vector std:alloc
0
1
2
3
4
5
6
7
8
9

% time     seconds  usecs/call     calls      function
------ ----------- ----------- --------- --------------------
 45.51    0.000618         123         5 malloc
 32.40    0.000440          88         5 free
 22.09    0.000300         300         1 exit_group
------ ----------- ----------- --------- ---------
```

```bash
heaptrack stats:
        allocations:            9
        leaked allocations:     1
        temporary allocations:  0
Heaptrack finished! Now run the following to investigate the data:

  heaptrack --analyze "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75697.gz"
root@lrn-7513-kulakov:~/ots-cpp-prof-3.0.2/build# heaptrack --analyze "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75697.gz"
reading file "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75697.gz" - please wait, this might take some time...
Debuggee command was: ./hw3-custom-allocator
finished reading file, now analyzing data:

MOST CALLS TO ALLOCATION FUNCTIONS
3 calls to allocation functions with 96B peak consumption from
PoolAllocator<>::Pool::allocate(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
3 calls with 96B peak consumption from:
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::reallocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:35
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::ensure_capacity(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:61
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::push_back(int const&)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:240
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

3 calls to allocation functions with 280B peak consumption from
PoolAllocator<>::Node::Node(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:22
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
3 calls with 280B peak consumption from:
    PoolAllocator<>::Pool::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::reallocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:35
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::ensure_capacity(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:61
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::push_back(int const&)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:240
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

1 calls to allocation functions with 32B peak consumption from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
1 calls with 32B peak consumption from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__allocated_ptr<> std::__allocate_guarded<>(std::allocator<>&)
      at /usr/include/c++/15/bits/allocated_ptr.h:102
    std::__shared_count<>::__shared_count<>(PoolAllocator<>::Pool*&, std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:967
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__shared_ptr<>::__shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:1719
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<>::shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr.h:463
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<> std::make_shared<>()
      at /usr/include/c++/15/bits/shared_ptr.h:1008
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::PoolAllocator()
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:83
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::CustomVector()
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:80
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:19
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

1 calls to allocation functions with 73.73K peak consumption from
0x71887cabf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1 calls with 73.73K peak consumption from:
    0x71887ce487ce
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce488e3
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce6539f
      in /lib64/ld-linux-x86-64.so.2

1 calls to allocation functions with 1.02K peak consumption from
_IO_file_doallocate
  in /usr/lib/x86_64-linux-gnu/libc.so.6
1 calls with 1.02K peak consumption from:
    _IO_doallocbuf
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_overflow
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_xsputn
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_fwrite
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    std::basic_ostream<>& std::__ostream_insert<>(std::basic_ostream<>&, char const*, long)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    std::basic_ostream<>& std::operator<< <>(std::basic_ostream<>&, char const*)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:18
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

PEAK MEMORY CONSUMERS
73.73K peak memory consumed over 1 calls from
0x71887cabf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
73.73K consumed over 1 calls from:
    0x71887ce487ce
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce488e3
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce6539f
      in /lib64/ld-linux-x86-64.so.2

1.02K peak memory consumed over 1 calls from
_IO_file_doallocate
  in /usr/lib/x86_64-linux-gnu/libc.so.6
1.02K consumed over 1 calls from:
    _IO_doallocbuf
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_overflow
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_xsputn
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_fwrite
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    std::basic_ostream<>& std::__ostream_insert<>(std::basic_ostream<>&, char const*, long)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    std::basic_ostream<>& std::operator<< <>(std::basic_ostream<>&, char const*)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:18
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

280B peak memory consumed over 3 calls from
PoolAllocator<>::Node::Node(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:22
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
280B consumed over 3 calls from:
    PoolAllocator<>::Pool::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::reallocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:35
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::ensure_capacity(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:61
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::push_back(int const&)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:240
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

96B peak memory consumed over 3 calls from
PoolAllocator<>::Pool::allocate(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
96B consumed over 3 calls from:
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::reallocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:35
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::ensure_capacity(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:61
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::push_back(int const&)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:240
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

32B peak memory consumed over 1 calls from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
32B consumed over 1 calls from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__allocated_ptr<> std::__allocate_guarded<>(std::allocator<>&)
      at /usr/include/c++/15/bits/allocated_ptr.h:102
    std::__shared_count<>::__shared_count<>(PoolAllocator<>::Pool*&, std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:967
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__shared_ptr<>::__shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:1719
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<>::shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr.h:463
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<> std::make_shared<>()
      at /usr/include/c++/15/bits/shared_ptr.h:1008
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::PoolAllocator()
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:83
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::CustomVector()
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:80
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:19
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator


MOST TEMPORARY ALLOCATIONS
1 temporary allocations of 1 allocations in total (100.00%) from
0x71887cabf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1 temporary allocations of 1 allocations in total (100.00%) from:
    0x71887ce487ce
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce488e3
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce6539f
      in /lib64/ld-linux-x86-64.so.2


total runtime: 0.00s.
calls to allocation functions: 9 (9000/s)
temporary memory allocations: 1 (1000/s)
peak heap memory consumption: 75.16K
peak RSS (including heaptrack overhead): 5.07M
total memory leaked: 1.02K
root@lrn-7513-kulakov:~/ots-cpp-prof-3.0.2/build# heaptrack --analyze "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75542.gz"
reading file "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75542.gz" - please wait, this might take some time...
Debuggee command was: ./hw3-custom-allocator
finished reading file, now analyzing data:

MOST CALLS TO ALLOCATION FUNCTIONS
5 calls to allocation functions with 96B peak consumption from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
5 calls with 96B peak consumption from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::reallocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:35
    vector::CustomVector<>::ensure_capacity(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:61
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::push_back(int const&)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:240
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

1 calls to allocation functions with 73.73K peak consumption from
0x7f78bccbf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1 calls with 73.73K peak consumption from:
    0x7f78bd0887ce
      in /lib64/ld-linux-x86-64.so.2
    0x7f78bd0888e3
      in /lib64/ld-linux-x86-64.so.2
    0x7f78bd0a539f
      in /lib64/ld-linux-x86-64.so.2

1 calls to allocation functions with 1.02K peak consumption from
_IO_file_doallocate
  in /usr/lib/x86_64-linux-gnu/libc.so.6
1 calls with 1.02K peak consumption from:
    _IO_doallocbuf
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_overflow
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_xsputn
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_fwrite
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    std::basic_ostream<>& std::__ostream_insert<>(std::basic_ostream<>&, char const*, long)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    std::basic_ostream<>& std::operator<< <>(std::basic_ostream<>&, char const*)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:18
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator


PEAK MEMORY CONSUMERS
73.73K peak memory consumed over 1 calls from
0x7f78bccbf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
73.73K consumed over 1 calls from:
    0x7f78bd0887ce
      in /lib64/ld-linux-x86-64.so.2
    0x7f78bd0888e3
      in /lib64/ld-linux-x86-64.so.2
    0x7f78bd0a539f
      in /lib64/ld-linux-x86-64.so.2

1.02K peak memory consumed over 1 calls from
_IO_file_doallocate
  in /usr/lib/x86_64-linux-gnu/libc.so.6
1.02K consumed over 1 calls from:
    _IO_doallocbuf
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_overflow
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_xsputn
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_fwrite
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    std::basic_ostream<>& std::__ostream_insert<>(std::basic_ostream<>&, char const*, long)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    std::basic_ostream<>& std::operator<< <>(std::basic_ostream<>&, char const*)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:18
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

96B peak memory consumed over 5 calls from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
96B consumed over 5 calls from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::reallocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:35
    vector::CustomVector<>::ensure_capacity(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:61
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::push_back(int const&)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:240
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator


MOST TEMPORARY ALLOCATIONS
1 temporary allocations of 1 allocations in total (100.00%) from
0x7f78bccbf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1 temporary allocations of 1 allocations in total (100.00%) from:
    0x7f78bd0887ce
      in /lib64/ld-linux-x86-64.so.2
    0x7f78bd0888e3
      in /lib64/ld-linux-x86-64.so.2
    0x7f78bd0a539f
      in /lib64/ld-linux-x86-64.so.2


total runtime: 0.00s.
calls to allocation functions: 7 (3500/s)
temporary memory allocations: 1 (500/s)
peak heap memory consumption: 74.85K
peak RSS (including heaptrack overhead): 5.08M
total memory leaked: 1.02K
```

---

```bash
custom vector custom_alloc
0
1
2
3
4
5
6
7
8
9
% time     seconds  usecs/call     calls      function
------ ----------- ----------- --------- --------------------
 44.59    0.000684          97         7 malloc
 40.48    0.000621          88         7 free
 14.93    0.000229         229         1 exit_group
------ ----------- ----------- --------- --------------------
100.00    0.001534                    15 total
```

```bash
heaptrack stats:
        allocations:            9
        leaked allocations:     1
        temporary allocations:  0
Heaptrack finished! Now run the following to investigate the data:

  heaptrack --analyze "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75697.gz"
root@lrn-7513-kulakov:~/ots-cpp-prof-3.0.2/build# heaptrack --analyze "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75697.gz"
reading file "/root/ots-cpp-prof-3.0.2/build/heaptrack.hw3-custom-allocator.75697.gz" - please wait, this might take some time...
Debuggee command was: ./hw3-custom-allocator
finished reading file, now analyzing data:

MOST CALLS TO ALLOCATION FUNCTIONS
3 calls to allocation functions with 96B peak consumption from
PoolAllocator<>::Pool::allocate(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
3 calls with 96B peak consumption from:
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::reallocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:35
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::ensure_capacity(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:61
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::push_back(int const&)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:240
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

3 calls to allocation functions with 280B peak consumption from
PoolAllocator<>::Node::Node(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:22
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
3 calls with 280B peak consumption from:
    PoolAllocator<>::Pool::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::reallocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:35
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::ensure_capacity(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:61
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::push_back(int const&)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:240
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

1 calls to allocation functions with 32B peak consumption from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
1 calls with 32B peak consumption from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__allocated_ptr<> std::__allocate_guarded<>(std::allocator<>&)
      at /usr/include/c++/15/bits/allocated_ptr.h:102
    std::__shared_count<>::__shared_count<>(PoolAllocator<>::Pool*&, std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:967
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__shared_ptr<>::__shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:1719
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<>::shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr.h:463
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<> std::make_shared<>()
      at /usr/include/c++/15/bits/shared_ptr.h:1008
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::PoolAllocator()
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:83
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::CustomVector()
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:80
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:19
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

1 calls to allocation functions with 73.73K peak consumption from
0x71887cabf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1 calls with 73.73K peak consumption from:
    0x71887ce487ce
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce488e3
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce6539f
      in /lib64/ld-linux-x86-64.so.2

1 calls to allocation functions with 1.02K peak consumption from
_IO_file_doallocate
  in /usr/lib/x86_64-linux-gnu/libc.so.6
1 calls with 1.02K peak consumption from:
    _IO_doallocbuf
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_overflow
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_xsputn
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_fwrite
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    std::basic_ostream<>& std::__ostream_insert<>(std::basic_ostream<>&, char const*, long)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    std::basic_ostream<>& std::operator<< <>(std::basic_ostream<>&, char const*)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:18
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator


PEAK MEMORY CONSUMERS
73.73K peak memory consumed over 1 calls from
0x71887cabf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
73.73K consumed over 1 calls from:
    0x71887ce487ce
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce488e3
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce6539f
      in /lib64/ld-linux-x86-64.so.2

1.02K peak memory consumed over 1 calls from
_IO_file_doallocate
  in /usr/lib/x86_64-linux-gnu/libc.so.6
1.02K consumed over 1 calls from:
    _IO_doallocbuf
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_overflow
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_file_xsputn
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    _IO_fwrite
      in /usr/lib/x86_64-linux-gnu/libc.so.6
    std::basic_ostream<>& std::__ostream_insert<>(std::basic_ostream<>&, char const*, long)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    std::basic_ostream<>& std::operator<< <>(std::basic_ostream<>&, char const*)
      in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:18
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

280B peak memory consumed over 3 calls from
PoolAllocator<>::Node::Node(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:22
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
280B consumed over 3 calls from:
    PoolAllocator<>::Pool::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::reallocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:35
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::ensure_capacity(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:61
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::push_back(int const&)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:240
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

96B peak memory consumed over 3 calls from
PoolAllocator<>::Pool::allocate(unsigned long)
  at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:50
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
96B consumed over 3 calls from:
    PoolAllocator<>::allocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:87
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::allocator_traits<>::allocate(PoolAllocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:385
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::reallocate(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:35
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::ensure_capacity(unsigned long)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:61
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::push_back(int const&)
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:240
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:22
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator

32B peak memory consumed over 1 calls from
std::__new_allocator<>::allocate(unsigned long, void const*)
  at /usr/include/c++/15/bits/new_allocator.h:151
  in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
32B consumed over 1 calls from:
    std::allocator_traits<>::allocate(std::allocator<>&, unsigned long)
      at /usr/include/c++/15/bits/alloc_traits.h:614
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__allocated_ptr<> std::__allocate_guarded<>(std::allocator<>&)
      at /usr/include/c++/15/bits/allocated_ptr.h:102
    std::__shared_count<>::__shared_count<>(PoolAllocator<>::Pool*&, std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:967
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::__shared_ptr<>::__shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr_base.h:1719
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<>::shared_ptr<>(std::_Sp_alloc_shared_tag<>)
      at /usr/include/c++/15/bits/shared_ptr.h:463
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    std::shared_ptr<> std::make_shared<>()
      at /usr/include/c++/15/bits/shared_ptr.h:1008
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    PoolAllocator<>::PoolAllocator()
      at /root/ots-cpp-prof-3.0.2/custom_allocator/custom_allocator.hpp:83
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    vector::CustomVector<>::CustomVector()
      at /root/ots-cpp-prof-3.0.2/custom_vector/custom_vector.cpp:80
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator
    main
      at /root/ots-cpp-prof-3.0.2/main.cpp:19
      in /root/ots-cpp-prof-3.0.2/build/hw3-custom-allocator


MOST TEMPORARY ALLOCATIONS
1 temporary allocations of 1 allocations in total (100.00%) from
0x71887cabf8f6
  in /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1 temporary allocations of 1 allocations in total (100.00%) from:
    0x71887ce487ce
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce488e3
      in /lib64/ld-linux-x86-64.so.2
    0x71887ce6539f
      in /lib64/ld-linux-x86-64.so.2


total runtime: 0.00s.
calls to allocation functions: 9 (9000/s)
temporary memory allocations: 1 (1000/s)
peak heap memory consumption: 75.16K
peak RSS (including heaptrack overhead): 5.07M
total memory leaked: 1.02K
```