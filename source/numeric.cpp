#include "../include/numeric.h"

namespace  my_stl{

    /**
     *�Գ�ʼֵinit��ÿ��Ԫ���ۼ�,++first����Ϊ�����ķ�ʽ����
     * @tparam InputPointer ����������
     * @tparam T ����ֵ
     * @param first ���
     * @param last �յ�
     * @param init ��ʼֵ
     * @return
     */
    template<typename InputPointer, typename T>
    T numeric<InputPointer,T>::accumulate(InputPointer first,InputPointer last ,T init){
        for( ; first != last ; ++first ){
            init += *first;
        }
        return  first;
    }

    /**
     *ָ��������� ����ÿ��Ԫ�ص��ۼ�
     * @tparam InputPointer
     * @tparam T ����ģ��
     * @tparam _operator �����ģ��
     * @param first ���
     * @param last �յ�
     * @param init ��ʼֵ
     * @param op �������
     * @return
     */
    template<typename InputPointer, typename T>
    template<typename _operator>
    T numeric<InputPointer,T>::accumulate(InputPointer first,InputPointer last ,T init,_operator op){
            for( ; first != last ; ++first){
                init = op(init,*first);
            }
    }

    /**
     *��������Ԫ��֮��Ĳ�ֵ,auto�Զ��Ƶ�ֵ
     * @tparam InputPointer
     * @tparam T
     * @tparam OutPutPointer
     * @param first
     * @param last
     * @param result
     * @return
     */
    template<typename InputPointer, typename T>
    template<typename OutPutPointer>
    T numeric<InputPointer,T>::adjacent_difference(InputPointer first,InputPointer last,OutPutPointer result){
        if( first == last ) return result;
        auto temp = *first;
        while( ++first != last ){
           T value = *first;
            * (++result) = value - temp;
        }
    }

    /**
     *��������Ԫ��֮��Ĳ�ֵ,auto�Զ��Ƶ�ֵ
     * @tparam InputPointer
     * @tparam T
     * @tparam OutPutPointer
     * @tparam _operator
     * @param first
     * @param last
     * @param op
     * @param result
     * @return
     */
    template<typename InputPointer, typename T>
    template<typename OutPutPointer,typename _operator>
    T numeric<InputPointer,T>::adjacent_difference(InputPointer first,InputPointer last,_operator op,OutPutPointer result){
        if( first == last ) return result;
        auto temp = *first;
        while( ++first != last ){
            T value = *first;
            * (++result) = op(value,temp);
        }
    }


    /**
     *�����ڻ�
     * @tparam InputPointer
     * @tparam T
     * @param first
     * @param last
     * @param first1
     * @param last1
     * @param init
     * @return
     */
    template<typename InputPointer, typename T>
    T numeric<InputPointer,T>::inner_product(InputPointer first,InputPointer last,InputPointer first1,InputPointer last1,T init){
        while( first != last && first1 != last1){
            init += (*first) * (*first1);
            ++first;
            ++first1;
        }
    }


    /**
     *�����ڻ�
     * @tparam InputPointer
     * @tparam T
     * @tparam _operator1
     * @tparam _operator2
     * @param first
     * @param last
     * @param op1
     * @param first1
     * @param last1
     * @param op2
     * @param init
     * @return
     */
    template<typename InputPointer, typename T>
    template<typename _operator1,typename _operator2>
    T numeric<InputPointer,T>::inner_product(InputPointer first,InputPointer last,_operator1 op1,InputPointer first1,InputPointer last1,
                    _operator2 op2,T init){
        while( first != last && first1 != last1){
            T value = op1(*first,*first1);
            init = op2(init,value);
            ++first;
            ++first1;
        }
    }

    /**
     *��valueֵ��䵽first��last���ڴ�����
     * @tparam InputPointer
     * @tparam T
     * @param first
     * @param last
     * @param value
     */
    template<typename InputPointer, typename T>
    void numeric<InputPointer,T>::iota(InputPointer first,InputPointer last,T value){
        for(; first !=last ; ++first,++value){
            *first = value;
        }
    }

    /**
     *�����������ǰ׺��
     * @tparam InputPointer
     * @tparam T
     * @tparam OutPutPointer
     * @param first
     * @param last
     * @param result
     * @return
     */
    template<typename InputPointer, typename T>
    template<typename OutPutPointer>
    OutPutPointer numeric<InputPointer,T>::partial_sum(InputPointer first,InputPointer last,OutPutPointer result){
        if( first == last ) return  result ;
        *result = *first;
        auto value = *first;
        while (++first != last ){
            value = value + *first;
            *(++result) = value;
        }
        return ++ result;
    }


    /**
     *�����������ǰ׺��
     * @tparam InputPointer
     * @tparam T
     * @tparam OutPutPointer
     * @tparam _operator
     * @param first
     * @param last
     * @param op
     * @param result
     * @return
     */
    template<typename InputPointer, typename T>
    template<typename OutPutPointer,typename _operator>
    OutPutPointer numeric<InputPointer,T>::partial_sum(InputPointer first,InputPointer last,_operator op,OutPutPointer result){
        if( first == last ) return  result ;
        *result = *first;
        auto value = *first;
        while (++first != last ){
            value =op(value,*first);
            *(++result) = value;
        }
        return ++ result;
    }
}