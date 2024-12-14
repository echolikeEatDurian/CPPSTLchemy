#include "../include/numeric.h"

namespace  my_stl{

    /**
     *以初始值init对每个元素累加,++first是因为这样的方式更快
     * @tparam InputPointer 迭代器类型
     * @tparam T 返回值
     * @param first 起点
     * @param last 终点
     * @param init 初始值
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
     *指定运算符号 计算每个元素的累计
     * @tparam InputPointer
     * @tparam T 类型模板
     * @tparam _operator 运算符模板
     * @param first 起点
     * @param last 终点
     * @param init 初始值
     * @param op 运算符号
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
     *计算两个元素之间的插值,auto自动推导值
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
     *计算两个元素之间的插值,auto自动推导值
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
     *计算内积
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
     *计算内积
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
     *将value值填充到first到last的内存区域
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
     *计算迭代器的前缀和
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
     *计算迭代器的前缀和
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