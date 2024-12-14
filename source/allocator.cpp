#include "../include/allocator.h"



namespace my_stl{
    /**
     * �ú�������һ���ڴ������
     * @tparam T ��������
     * @return ָ��
     */
    template<typename T>
    T* allocator<T>::allocate(){
        return static_cast<T*>(::operator new(sizeof(T)));
    }

    /**
     * ������������ڴ�
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
     * �����ڴ�
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
     * �ͷŶ��������ڴ�
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
     * �ڶ�����ڴ������Ϸ������
     * @tparam T
     * @param ptr
     */
    template <typename T>
    void allocator<T>::construct(T *ptr) {

    }


    /**
     * ������󣬲��ҽ�value���Ƹ�ptr
     * @tparam T
     * @param ptr
     * @param value
     */
    template <typename T>
    void allocator<T>::construct(T *ptr,const T& value) {


    }

    /**
     * �ƶ����ƹ��캯��
     * @tparam T
     * @param ptr
     * @param value
     */
    template <typename T>
    void allocator<T>::construct(T *ptr,const T&& value) {


    }



    /**
     * ����ת��
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
     * �ͷ��ڴ�
     * @tparam T
     * @param ptr
     */
    template<typename T>
    void allocator<T>::destroy(T *ptr) {
        constructor<T>::destroy(ptr);

    }


    /***
     * �ͷ��������ڴ��
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