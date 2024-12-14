//
// Created by echo on 2024/11/24.

#ifndef MY_CPP_STL_BY_CLION_TYPE_TRAITS_H
#define MY_CPP_STL_BY_CLION_TYPE_TRAITS_H
namespace  my_stl{
    template <class T, T v>
    struct m_integral_constant
    {
        static constexpr T value = v;
    };

    template <bool b>
    using m_bool_constant = m_integral_constant<bool, b>;

    typedef m_bool_constant<true>  m_true_type;
    typedef m_bool_constant<false> m_false_type;


    template <class T1, class T2>
    struct pair; // 前置声明

    template <class T>
    struct is_pair : my_stl::m_false_type {};  // 默认不是 pair 类型

    template <class T1, class T2>
    struct is_pair<my_stl::pair<T1, T2>> : my_stl::m_true_type {};  // 如果是 pair 类型，返回 true
}

#endif //MY_CPP_STL_BY_CLION_TYPE_TRAITS_H
