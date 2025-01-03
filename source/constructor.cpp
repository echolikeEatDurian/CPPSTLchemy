
#include "../include/constructor.h"
#include "../include/type_traits.h"

namespace my_stl{
    /**
     *
     * @tparam T
     * @param ptr
     */
    template<typename T>
    void constructor<T>::construct(T* ptr){
        return ::new ((void*)ptr) T();
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
        ::new ((void*)ptr) T(value);
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
    void constructor<T>::destroy_one(T* ptr,std::true_type){


    }
    /**
     *
     * @tparam T
     * @param ptr
     */
    template<typename T>
    void constructor<T>::destroy_one(T* ptr,std::false_type){
        if(nullptr == ptr ) return;
        ptr->~T();
    }

    /**
     *û��ʵ��
     * @tparam T
     * @tparam ForwardIter
     */
    template<typename T>
    template <typename ForwardIter>
    void constructor<T>::destroy_cat(ForwardIter,ForwardIter,std::true_type ){


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
    void constructor<T>::destroy_cat(ForwardIter first,ForwardIter last,std::false_type ){
        for( ; first  != last ; ++first){
            destroy_one(&*first);
        }
    }

    /**
     *
     * @tparam T
     * @tparam ForwardIter
     * @param ptr
     */
    template<typename T>
    void constructor<T>::destroy(T *ptr) {
        destroy_one(ptr,std::is_trivially_destructible<T>());
    }

    /**
     *
     * @tparam T
     * @tparam ForwardIter
     * @param ptr
     */
    template<typename T>
    template <typename ForwardIter>
    void constructor<T>::destroy(ForwardIter first,ForwardIter last) {

    }
}