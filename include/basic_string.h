//
// Created by echo on 2024/11/23.
#ifndef MY_CPP_STL_BY_CLION_BASIC_STRING_H
#define MY_CPP_STL_BY_CLION_BASIC_STRING_H


#include <cstddef>

namespace my_stl {
    template<typename CharType>
    struct char_traits {
        typedef CharType char_type;

        static size_t length(const char_type *str);//计算长度
        static int compare(const char_type *s1, const char_type *s2, size_t n);//比较函数
        static char_type *copy(char_type *dst, const char_type *src, size_t n);//复制函数
        static char_type *move(char_type *dst, const char_type *src, size_t n);//移动函数
        static char_type *fill(char_type *dst, char_type ch, size_t count);//填充函数
    };

    template<>
    struct char_traits<char> {
        typedef char char_type;

        static size_t length(const char_type *str);//计算长度
        static int compare(const char_type *s1, const char_type *s2, size_t n);//比较函数
        static char_type *copy(char_type *dst, const char_type *src, size_t n);//复制函数
        static char_type *move(char_type *dst, const char_type *src, size_t n);//移动函数
        static char_type *fill(char_type *dst, char_type ch, size_t count);//填充函数
    };


    template<>
    struct char_traits<wchar_t> {
        typedef wchar_t char_type;

        static size_t length(const char_type *str);//计算长度
        static int compare(const char_type *s1, const char_type *s2, size_t n);//比较函数
        static char_type *copy(char_type *dst, const char_type *src, size_t n);//复制函数
        static char_type *move(char_type *dst, const char_type *src, size_t n);//移动函数
        static char_type *fill(char_type *dst, char_type ch, size_t count);//填充函数
    };

    template<>
    struct char_traits<char16_t> {
        typedef char16_t char_type;
        static size_t length(const char_type *str);//计算长度
        static int compare(const char_type *s1, const char_type *s2, size_t n);//比较函数
        static char_type *copy(char_type *dst, const char_type *src, size_t n);//复制函数
        static char_type *move(char_type *dst, const char_type *src, size_t n);//移动函数
        static char_type *fill(char_type *dst, char_type ch, size_t count);//填充函数
    };


    template<>
    struct char_traits<char32_t> {
        typedef char32_t char_type;

        static size_t length(const char_type *str);//计算长度
        static int compare(const char_type *s1, const char_type *s2, size_t n);//比较函数
        static char_type *copy(char_type *dst, const char_type *src, size_t n);//复制函数
        static char_type *move(char_type *dst, const char_type *src, size_t n);//移动函数
        static char_type *fill(char_type *dst, char_type ch, size_t count);//填充函数
    };

#define  STING_INIT_SIZE 32
    template<class CharType, class CharTraits = my_stl::char_traits<CharType>>
    class basic_string {
                

    };

}


#endif //MY_CPP_STL_BY_CLION_BASIC_STRING_H
