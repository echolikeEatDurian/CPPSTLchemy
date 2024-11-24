#include "../include/numeric.h"

namespace  my_stl{

    /**
     *
     * @tparam InputPointer
     * @tparam T
     * @param first
     * @param last
     * @param init
     * @return
     */
    template<typename InputPointer, typename T>
    T numeric<InputPointer,T>::accumulate(InputPointer first,InputPointer last ,T init){


    }

    /**
     *
     * @tparam InputPointer
     * @tparam T
     * @tparam _operator
     * @param first
     * @param last
     * @param init
     * @param op
     * @return
     */
    template<typename InputPointer, typename T>
    template<typename _operator>
    T numeric<InputPointer,T>::accumulate(InputPointer first,InputPointer last ,T init,_operator op){


    }

    /**
     *
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


    }

    /**
     *
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


    }


    /**
     *
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


    }


    /**
     *
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


    }

    /**
     *
     * @tparam InputPointer
     * @tparam T
     * @param first
     * @param last
     * @param value
     */
    template<typename InputPointer, typename T>
    void numeric<InputPointer,T>::iota(InputPointer first,InputPointer last,T value){


    }

    /**
     *
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


    }


    /**
     *
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


    }



}