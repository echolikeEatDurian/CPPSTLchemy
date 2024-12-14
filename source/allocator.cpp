#include "../include/allocator.h"



namespace my_stl{
    /**
     * 该函数定义一个内存分配器
     * @tparam T 参数类型
     * @return 指针
     */
    template<typename T>
    T* allocator<T>::allocate(){
        return static_cast<T*>(::operator new(sizeof(T)));
    }

    /**
     * 分配多个对象的内存
     * @tparam T
     * @param n
     * @return
     */
    template<typename T>
    T* allocator<T>::allocate(size_type n){
        if( n == 0 )
            return nullptr;
        return static_cast<T*>(::operator new(sizeof(T) * n));
    }

    /**
     * 销毁内存
     * @tparam T
     * @param ptr
     */
    template<typename T>
    void allocator<T>::deallocate(T *ptr) {
        if(nullptr == ptr)
            return;
        ::operator delete(ptr);
    }

    /**
     * 释放多个对象的内存
     * @tparam T
     * @param ptr
     * @param n
     */
    template<typename T>
    void allocator<T>::deallocate(T *ptr, size_type n) {
        if( nullptr == ptr || n == 0 )
            return;
        ::operator delete(ptr);
    }

    /**
     * 在定义的内存区域上分配对象
     * @tparam T
     * @param ptr
     */
    template <typename T>
    void allocator<T>::construct(T *ptr) {

    }


    /**
     * 分配对象，并且将value复制给ptr
     * @tparam T
     * @param ptr
     * @param value
     */
    template <typename T>
    void allocator<T>::construct(T *ptr,const T& value) {


    }

    /**
     * 移动复制构造函数
     * @tparam T
     * @param ptr
     * @param value
     */
    template <typename T>
    void allocator<T>::construct(T *ptr,const T&& value) {


    }



    /**
     * 完美转发
     * @tparam T
     * @tparam Args
     * @param ptr
     * @param args
     */
    template<typename T>
    template<class ... Args>
    void allocator<T>::construct(T *ptr,Args&& ...args) {


    }

    /**
     * 释放内存
     * @tparam T
     * @param ptr
     */
    template<typename T>
    void allocator<T>::destroy(T *ptr) {
        constructor<T>::destroy(ptr);

    }


    /***
     * 释放连续的内存块
     * @tparam T
     * @tparam T
     * @param first
     * @param last
     */
    template<typename T>
    void allocator<T>::destroy(T *first,T*last) {
        constructor<T>::destroy(first,last);
    }
}