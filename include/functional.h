//
// Created by echo on 2024/11/23.

#ifndef MY_CPP_STL_BY_CLION_FUNCTIONAL_H
#define MY_CPP_STL_BY_CLION_FUNCTIONAL_H
#include "cstddef"
namespace my_stl{
    template<typename T>
    class functional{

        /**
         * ����һԪ�����Ľṹ��
         * @tparam Arg
         * @tparam Result
         */
        template<typename Arg,typename Result>
        struct unary_function{
            typedef  Arg argument_type;
            typedef  Result result_type;
        };

        /**
         * ��Ԫ�����Ľṹ��
         * @tparam Arg1
         * @tparam Arg2
         * @tparam Result
         */
        template<typename Arg1,typename Arg2,typename Result>
        struct binary_function{
            typedef  Arg1 first_argument_type;
            typedef  Arg2 second_argument_type;
            typedef  Result result_type;
        };

        /**
         * �ӷ�
         */
        struct plus:public binary_function<T,T,T>{
            T operator() (const T&x,const T &y) const {return  x + y ; }

        };

        /**
         * ����
         */
        struct minus:public binary_function<T,T,T>{
            T operator() (const T&x,const T &y) const {return  x - y ; }

        };

        /**
         * �˷�
         */
        struct multiples:public binary_function<T,T,T>{
            T operator() (const T&x,const T &y) const {return  x * y ; }

        };

        /**
         * ����
         */
        struct divides:public binary_function<T,T,T>{
            T operator() (const T&x,const T &y) const {return  x / y ; }

        };

        /**
         * ģ����
         */
        struct modulus:public binary_function<T,T,T>{
            T operator() (const T&x,const T &y) const {return  x % y ; }

        };

        /**
         * ȡ�෴��
         */
        struct negate:public unary_function<T,T>{
            T operator()(const T&x) const {return  -x;}
        };

        /**
         * ȡ�ӷ��ĵ�λԪ
         * @return
         */
        T identity_element(plus) { return T(0); }

        /**
         * ȡ�˷��ĵ�λԪ
         * @return
         */
        T identity_element(multiples){return T(1);}

        /**
         * ���
         */
        struct equal_to:public binary_function<T,T,T>{
            bool operator() (const T& x,const T&y) const {return x == y ;}

        };

        /**
         * �����
         */
        struct no_equal_to:public binary_function<T,T,T>{
            bool operator() (const T& x,const T&y) const {return x != y ;}

        };

        /**
         * ����
         */
        struct greater:public binary_function<T,T,T>{
            bool operator() (const T& x,const T&y) const {return x > y ;}

        };

        /**
         * С��
         */
        struct less:public binary_function<T,T,T>{
            bool operator() (const T& x,const T&y) const {return x < y ;}

        };

        /**
         * ���ڵ���
         */
        struct greater_equal:public binary_function<T,T,T>{
            bool operator() (const T& x,const T&y) const {return x >= y ;}

        };


        /**
         * С�ڵ���
         */
        struct less_equal:public binary_function<T,T,T>{
            bool operator() (const T& x,const T&y) const {return x <= y ;}

        };

        /**
         * �߼���
         */
        struct logic_and:public binary_function<T,T,T>{
            bool operator() (const T&x,const T&y) const {return  x && y ;}
        };

        /**
         * �߼���
         */
        struct  logic_or:public binary_function<T,T,T>{
            bool operator() (const T&x ,const T&y ) const {return  x || y ;}
        };

        /**
         * �߼���
         */
        struct  logic_not :public  unary_function<T,T>{
            bool operator() (const T&x ) const {return  !x;}
        };

        /**
         * ����Ԫ�ر���
         */
        struct  identity:public unary_function<T,T>{
            const T& operator() (const T& x) const {return  x;}
        };

        /**
         * ��ȡ��һ��Ԫ��
         * @tparam pair
         */
        template<typename pair>
        struct select_first:public unary_function<pair,typename pair::first_type>{
            const typename pair::first_type& operator()(const pair& x) const {return x.first;}
        };

        /**
         * ��ȡ�ڶ���Ԫ��
         * @tparam pair
         */
        template<typename pair>
        struct select_second:public unary_function<pair,typename pair::second_type>{
            const typename pair::second_type& operator()(const pair& x) const {return x.second;}
        };

        /**
         * ͶӰ������ȡ��һ������
         * @tparam Arg1
         * @tparam Arg2
         */
        template<typename Arg1,typename Arg2>
        struct project_first:public binary_function<Arg1,Arg2,Arg2>{
            Arg1 operator() (const Arg1& x,const Arg2&y) const {return  x;}
        };

        /**
         * ͶӰ������ȡ�ڶ�������
         * @tparam Arg1
         * @tparam Arg2
         */
        template<typename Arg1,typename Arg2>
        struct project_second:public binary_function<Arg1,Arg2,Arg2>{
            Arg2 operator() (const Arg1& x,const Arg2&y) const {return  y;}
        };

        /**
         * ��ϣ����
         */
        template<typename key>
        struct hash {};


        template<typename key>
        struct hash<key*>{
            size_t operator()(T* p) const noexcept{
                return reinterpret_cast<size_t>(p);
            }

        };

        #define MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(Type) \
                template<> struct hash<Type> \
                {                            \
                    size_t operator() (Type value) const noexcept \
                    {return static_cast<size_t> (value);}         \
                };
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(bool)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(char)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(signed char)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(unsigned char)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(wchar_t)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(char16_t)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(char32_t)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(short)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(unsigned short)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(int)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(unsigned int)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(long)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(unsigned long)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(long long)
                MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN(unsigned long long)
        #undef  MY_CPP_STL_BY_CLION_TRIVIAL_HASH_FCN

        static inline size_t bitwise_hash(const unsigned char* first,size_t count){
        #if (_MSC_VER && _WIN64) || ((__GNUC__ || __clang__) &&__SIZEOF_POINTER__ == 8)
                    const size_t fnv_offset = 14695981039346656037ull;
                    const size_t fnv_prime = 1099511628211ull;
        #else
                    const size_t fnv_offset = 2166136261u;
                    const size_t fnv_prime = 16777619u;
        #endif
                    size_t result = fnv_offset;
                    for (size_t i = 0; i < count; ++i)
                    {
                        result ^= (size_t)first[i];
                        result *= fnv_prime;
                    }
                    return result;
        }

        template<>
        struct hash<float>{
                    size_t operator()(const float& val){
                        return val == 0.0f ? 0: bitwise_hash((const unsigned char*)&val,sizeof(float));
                    }
                };

        template<>
        struct hash<double>{
            size_t operator()(const float& val){
                return val == 0.0f ? 0: bitwise_hash((const unsigned char*)&val,sizeof(double));
            }
        };

        template<>
        struct hash<long double>{
            size_t operator()(const float& val){
                return val == 0.0f ? 0: bitwise_hash((const unsigned char*)&val,sizeof(long double));
            }
        };


    };
}
#endif //MY_CPP_STL_BY_CLION_FUNCTIONAL_H
