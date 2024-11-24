//
// Created by echo on 2024/11/23.
#ifndef MY_CPP_STL_BY_CLION_ALLOCATOR_H
#define MY_CPP_STL_BY_CLION_ALLOCATOR_H
#include "constructor.h"
#include "utils.h"
#include <cstddef>

namespace  my_stl{
    template<typename T>
    class allocator{
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
    public:
        static  T* allocate();
        static T* allocate(size_type n);
        static void deallocate(T* ptr);
        static void deallocate(T* ptr,size_type n);
        static void construct(T* ptr);
        static void construct(T* ptr,const T& value);
        static void construct(T* ptr,const T&& value);

        template<typename... Args>
        static void construct(T* ptr,Args&& ...args);
        static void destroy(T* ptr);
        static void destroy(T* first,T* last);




    };


}





#endif //MY_CPP_STL_BY_CLION_ALLOCATOR_H
