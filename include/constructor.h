// Created by echo on 2024/11/23.
#ifndef MY_CPP_STL_BY_CLION_CONSTRUCTOR_H
#define MY_CPP_STL_BY_CLION_CONSTRUCTOR_H

#include <iostream>

namespace my_stl{
    template<typename T>

   class constructor{
   public:
       void construct(T* ptr); //构造函数
       template<typename T2>
       void construct(T* ptr,const T2& value);//构造函数
       template<typename... Args>
       void construct(T* ptr,Args&& ...args);//构造函数

       void destroy_one(T* ptr,std::true_type);//析构函数
       void destroy_one(T* ptr,std::false_type );//析构函数

       template <typename ForwardIter>
       void destroy_cat(ForwardIter,ForwardIter,std::true_type );//析构函数
       template <typename ForwardIter>
       void destroy_cat(ForwardIter first,ForwardIter last,std::false_type );//析构函数

        void destroy(T* ptr); // 析构函数
        template <typename ForwardIter>
        void destroy(ForwardIter first,ForwardIter last); //析构函数

   };
}
#endif //MY_CPP_STL_BY_CLION_CONSTRUCTOR_H
