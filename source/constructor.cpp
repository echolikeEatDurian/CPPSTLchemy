
#include "../include/constructor.h"

namespace my_stl{
    /**
     *
     * @tparam T
     * @param ptr
     */
    template<typename T>
    void constructor<T>::construct(T* ptr){

    }

    /**
     *
     * @tparam T
     * @tparam T2
     * @param ptr
     * @param value
     */
    template<typename T>
    template<typename T2>
    void constructor<T>::construct(T* ptr,const T2& value){


    }

    /**
     *
     * @tparam T
     * @tparam Args
     * @param ptr
     * @param args
     */
    template<typename T>
    template<typename... Args>
    void constructor<T>::construct(T* ptr,Args&& ...args){


    }

    /**
     *
     * @tparam T
     * @param ptr
     */
    template<typename T>
    void constructor<T>::destroy(T* ptr,std::true_type){


    }
    /**
     *
     * @tparam T
     * @param ptr
     */
    template<typename T>
    void constructor<T>::destroy(T* ptr,std::false_type){


    }

    /**
     *
     * @tparam T
     * @tparam ForwardIter
     */
    template<typename T>
    template <typename ForwardIter>
    void constructor<T>::destroy(ForwardIter,ForwardIter,std::true_type ){


    }

    /**
     *
     * @tparam T
     * @tparam ForwardIter
     * @param first
     * @param last
     */
    template<typename T>
    template <typename ForwardIter>
    void constructor<T>::destroy(ForwardIter first,ForwardIter last,std::false_type ){


    }



}