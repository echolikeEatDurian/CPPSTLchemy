//
// Created by echo on 2024/11/23.

#ifndef MY_CPP_STL_BY_CLION_NUMERIC_H
#define MY_CPP_STL_BY_CLION_NUMERIC_H
namespace my_stl{
    template<typename InputPointer, typename T>
    class numeric{
    public:

        T accumulate(InputPointer first,InputPointer last ,T init);//求和
        template<typename _operator>
        T accumulate(InputPointer first,InputPointer last ,T init,_operator op);//指定运算符计算

        template<typename OutPutPointer>
        T adjacent_difference(InputPointer first,InputPointer last,OutPutPointer result); //计算插值

        template<typename OutPutPointer,typename _operator>
        T adjacent_difference(InputPointer first,InputPointer last,_operator op,OutPutPointer result); //计算指定运算符号的插值

        T inner_product(InputPointer first,InputPointer last,InputPointer first1,InputPointer last1,T init); //计算内积

        template<typename _operator1,typename _operator2>
        T inner_product(InputPointer first,InputPointer last,_operator1 op1,InputPointer first1,InputPointer last1,
                        _operator2 op2,T init); //计算内积
        void iota(InputPointer first,InputPointer last,T value); //赋值

        template<typename OutPutPointer>
        OutPutPointer partial_sum(InputPointer first,InputPointer last,OutPutPointer result); //计算前缀和

        template<typename OutPutPointer,typename _operator>
        OutPutPointer partial_sum(InputPointer first,InputPointer last,_operator op,OutPutPointer result); //计算前缀数学运算

    };
}


#endif //MY_CPP_STL_BY_CLION_NUMERIC_H
