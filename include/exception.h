//
// Created by echo on 2024/11/23.

#ifndef MY_CPP_STL_BY_CLION_EXCEPTION_H
#define MY_CPP_STL_BY_CLION_EXCEPTION_H
#include <stdexcept>
#include <cassert>

namespace my_stl{
#define MY_STL_DEBUG(exp)\ assert(exp)

#define THROW_LENGTH_ERROR_IF(exp,what)\
    if ((exp)) throw std::length_error(what)


#define THROW_OUT_OF_RANGE_IF(exp,what) \
    if ((exp)) throw std::out_of_range(what)

#define THROW_RUN_TIME_ERROR(exp,what) \
    if ((exp)) throw std::runtime_error(what)

}

#endif //MY_CPP_STL_BY_CLION_EXCEPTION_H
