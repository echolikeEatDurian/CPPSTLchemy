//
// Created by echo on 2024/11/23.

#ifndef MY_CPP_STL_BY_CLION_NUMERIC_H
#define MY_CPP_STL_BY_CLION_NUMERIC_H
namespace my_stl{
    template<typename InputPointer, typename T>
    class numeric{
    public:

        T accumulate(InputPointer first,InputPointer last ,T init);//���
        template<typename _operator>
        T accumulate(InputPointer first,InputPointer last ,T init,_operator op);//ָ�����������

        template<typename OutPutPointer>
        T adjacent_difference(InputPointer first,InputPointer last,OutPutPointer result); //�����ֵ

        template<typename OutPutPointer,typename _operator>
        T adjacent_difference(InputPointer first,InputPointer last,_operator op,OutPutPointer result); //����ָ��������ŵĲ�ֵ

        T inner_product(InputPointer first,InputPointer last,InputPointer first1,InputPointer last1,T init); //�����ڻ�

        template<typename _operator1,typename _operator2>
        T inner_product(InputPointer first,InputPointer last,_operator1 op1,InputPointer first1,InputPointer last1,
                        _operator2 op2,T init); //�����ڻ�
        void iota(InputPointer first,InputPointer last,T value); //��ֵ

        template<typename OutPutPointer>
        OutPutPointer partial_sum(InputPointer first,InputPointer last,OutPutPointer result); //����ǰ׺��

        template<typename OutPutPointer,typename _operator>
        OutPutPointer partial_sum(InputPointer first,InputPointer last,_operator op,OutPutPointer result); //����ǰ׺��ѧ����

    };
}


#endif //MY_CPP_STL_BY_CLION_NUMERIC_H
