
#include "../include/constructor.h"

namespace my_stl{
    template<typename T>
    void constructor<T>::construct(T* ptr){

    }

    template<typename T>
    template<typename T2>
    void constructor<T>::construct(T* ptr,const T2& value){


    }


    template<typename T>
    template<typename... Args>
    void constructor<T>::construct(T* ptr,Args&& ...args){


    }

    template<typename T>
    void constructor<T>::destroy(T* ptr,std::true_type){


    }

    template<typename T>
    void constructor<T>::destroy(T* ptr,std::false_type){


    }
    template<typename T>
    template <typename ForwardIter>
    void constructor<T>::destroy(ForwardIter,ForwardIter,std::true_type ){


    }

    template<typename T>
    template <typename ForwardIter>
    void constructor<T>::destroy(ForwardIter first,ForwardIter last,std::false_type ){


    }



}