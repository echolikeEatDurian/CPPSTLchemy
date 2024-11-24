# my_cpp_stl_by_clion
Basic version c++ stl library implemented based on clion editor

# allocator
## �������ĺ���
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

��Щ `typedef` ������ C++ ��Ϊģ���� `allocator` �ṩ��һЩ���������ڶ��峣�õ����͡����ַ�ʽ��Ϊ����������Ŀɶ��Ժ�ͨ���ԣ��������ڷ��ͱ���и��Եñ�Ҫ��������ÿ�����͵ľ��庬������ã�

---

### **1. `typedef T value_type`**
- ������ģ�����������Ļ������͡�
- **����**��
    - ��ʾ `allocator` �з����ڴ������Ķ��������� `T`��
    - �ṩ��һ��ͳһ��������ʽ�����㷺���������㷨ʹ�á�
- **����**��
  ```cpp
  allocator<int>::value_type x;  // x ��һ�� int ����
  ```

---

### **2. `typedef T* pointer`**
- ������ָ��ģ������ `T` ��ָ�롣
- **����**��
    - �ṩ��һ�ּ��ķ�ʽ��ʾָ�����ͣ����ٴ��븴�Ӷȡ�
- **����**��
  ```cpp
  allocator<int>::pointer p = allocator<int>::allocate(); // p �� int* ����
  ```

---

### **3. `typedef const T* const_pointer`**
- ������ָ���� `T` �����ָ�롣
- **����**��
    - ��ʾָ��Ķ����ܱ��޸ģ�`*const_pointer` ���ܸı���ָ���ֵ����
    - �������밲ȫ�ԣ�����ֻ��������
- **����**��
  ```cpp
  allocator<int>::const_pointer cp;  // cp �� const int* ����
  ```

---

### **4. `typedef T& reference`**
- ������ģ������ `T` �����á�
- **����**��
    - �ṩһ�ֶԶ�����в����ķ�ʽ��������ʹ��ָ�롣
    - ���������㷨�У������� `reference` ������Ԫ�ء�
- **����**��
  ```cpp
  allocator<int>::reference r = someInt; // r �� int& ����
  ```

---

### **5. `typedef const T& const_reference`**
- �����˳������� `T` �����á�
- **����**��
    - ��ʾ���õ�ֵ���ܱ��޸ģ�`const_reference` �� `const T&`����
    - �������밲ȫ�ԣ�����ֻ�����ʡ�
- **����**��
  ```cpp
  allocator<int>::const_reference cr = someConstInt; // cr �� const int& ����
  ```

---

### **6. `typedef size_t size_type`**
- ������һ���޷����������ͣ����ڱ�ʾ��С��ͨ��������ʾ�����Ĵ�С������ڴ����������
- **����**��
    - ��ʾ�ڴ��С������������ʺ��ڸ���ƽ̨��`size_t` �Ǳ�׼������޷������ͣ���
- **����**��
  ```cpp
  allocator<int>::size_type n = 10; // n �� size_t ����
  allocator<int>::allocate(n);     // ���� n �� int ���ڴ�
  ```

---

### **7. `typedef ptrdiff_t difference_type`**
- �������з����������ͣ����ڱ�ʾ����ָ��֮��ľ��루������ָ���ƫ��������
- **����**��
    - ��������ָ��֮��Ĳ�ֵ���ʺϸ���ƽ̨��`ptrdiff_t` �Ǳ�׼������з������ͣ���
- **����**��
  ```cpp
  allocator<int>::difference_type diff = &array[5] - &array[2]; // diff �� ptrdiff_t ����
  ```

---

### **��;�ܽ�**
1. **һ���Ժ�ͨ����**��
    - ��Щ���Ͷ���Ϊģ�����ṩ��ͳһ�Ľӿڣ����ڱ�׼�������� `std::vector`��`std::map`���ȸ��á�
    - `allocator` ����������ʱ������������ľ���� `T` ���ͣ�ֻ��ͨ����Щ������ `allocator` ͨ�š�

2. **��ߴ���ɶ���**��
    - ʹ����Щ������ֱ��ʹ�õײ����ͣ��� `int*`��`size_t`�������廯�������˴������塣

3. **ƽ̨������**��
    - ͨ�� `size_t` �� `ptrdiff_t`����֤�˲�ͬƽ̨��32 λ�� 64 λ���ϵĴ���һ���ԡ�

4. **����ģ�����**��
    - Ϊ֧�ַ��ͱ���ṩ��һ��ͨ�ýӿ���ʽ��ʹ `allocator` �������� STL ���Э����

---

### **��������**
��Щ���ͱ����� STL �����б��㷺ʹ�ã����磺

- `std::vector` ʹ�� `allocator` �� `value_type` ֪����洢��Ԫ�����͡�
- `size_type` ���ڱ�ʾ�����Ĵ�С���ڴ�����������
- `difference_type` ���ڵ�����֮��ľ�����㡣
- `pointer` �� `const_pointer` ���ڹ���ײ����ݴ洢ָ�롣

���ǹ�����ģ�����뷺������֮���������������ǿ�˴��������ԺͿ���ֲ�ԡ�

��Щ������ `allocator` ģ�����������ڴ����Ͷ����������ڲ����ľ�̬��Ա���������� **�����ڴ�**��**�ͷ��ڴ�**��**�������** �� **��������**�������ǶԵײ�����ķ�װ���ṩ���߲�εĳ��󣬱������ STL �������������ʹ���ʹ�á�

---
## �ӿڵĶ���
        static  T* allocate();
        static T* allocate(size_type n);
        static void deallocate(T* ptr);
        static void deallocate(T* ptr,size_type n);
        static void construct(T* ptr);
        static void construct(T* ptr,const T& value);
        static void construct(T* ptr,const T&& value);

        template<typename... Args>
        static void construct(T* ptr,Args&& ...args);
        static void destory(T* ptr);
        static void destory(T* first,T* last);
### **1. `static T* allocate()`**
- **����**��
  ����һ��δ��ʼ�����ڴ棬���Դ洢һ�� `T` ���͵Ķ���
- **ʵ��**��
  ```cpp
  return static_cast<T*>(::operator new(sizeof(T)));
  ```
- **����**��
    - ʹ��ȫ�� `::operator new` ����һ��ԭʼ�ڴ棬����ָ�롣
    - û�е��� `T` �Ĺ��캯�����ڴ�����δ��ʼ����
- **���ó���**��
  ������Ҫ��̬���䵥�������ڴ�ʱ��

---

### **2. `static T* allocate(size_type n)`**
- **����**��
  ����һ��δ��ʼ�����ڴ棬���Դ洢 `n` �� `T` ���͵Ķ���
- **ʵ��**��
  ```cpp
  if (n == 0) return nullptr;
  return static_cast<T*>(::operator new(n * sizeof(T)));
  ```
- **����**��
    - �뵥����汾���ƣ���֧�ַ�����������ڴ档
    - ��� `n == 0`������ `nullptr`��������Ч���䡣
- **���ó���**��
  ������Ҫ��̬�����������ڴ�ʱ������������չ������

---

### **3. `static void deallocate(T* ptr)`**
- **����**��
  �ͷ�ͨ�� `allocate()` ����ĵ���������ڴ档
- **ʵ��**��
  ```cpp
  if (ptr == nullptr) return;
  ::operator delete(ptr);
  ```
- **����**��
    - ʹ��ȫ�� `::operator delete` �ͷ��ڴ档
    - ��� `ptr` �Ƿ�Ϊ `nullptr`�������ͷ���Чָ�롣
- **���ó���**��
  �����ͷ� `allocate()` ������ڴ档

---

### **4. `static void deallocate(T* ptr, size_type n)`**
- **����**��
  �ͷ�ͨ�� `allocate(size_type n)` ����Ķ��������ڴ档
- **ʵ��**��
    - �뵥����汾��ͬ���ײ�ʵ�ֲ����� `n`��
- **����**��
    - �������汾�� `deallocate` �ǽӿ��ϵ����֣���ҪΪ���� `allocate` ��Ӧ��
- **���ó���**��
  �����ͷŶ�����ڴ档

---

### **5. `static void construct(T* ptr)`**
- **����**��
  �ڸ������ڴ��ַ `ptr` �ϵ���Ĭ�Ϲ��캯��������һ�� `T` ����
- **ʵ��**��
  ```cpp
  mystl::construct(ptr);
  ```
- **����**��
    - `construct` �� `mystl` ��һ������������ͨ������ `new (ptr) T()`��
    - ���ö�λ `new` ��ָ��λ�ù������
- **���ó���**��
  ���ڳ�ʼ������õ��ڴ档

---

### **6. `static void construct(T* ptr, const T& value)`**
- **����**��
  �� `ptr` ָ����ڴ��ַ��ʹ�ø��ƹ��캯��������һ���� `value` ��ȵ� `T` ����
- **ʵ��**��
  ```cpp
  mystl::construct(ptr, value);
  ```
- **����**��
    - ���ø��ƹ��캯���������µĶ���
- **���ó���**��
  ���ڽ����ж����ֵ�������µĶ���

---

### **7. `static void construct(T* ptr, T&& value)`**
- **����**��
  �� `ptr` ָ����ڴ��ַ��ʹ���ƶ����캯��������һ���� `value` �ƶ������� `T` ����
- **ʵ��**��
  ```cpp
  mystl::construct(ptr, mystl::move(value));
  ```
- **����**��
    - �����ƶ����캯�����ٿ���������
    - `mystl::move` ��һ���򻯰�� `std::move`������ֵת��Ϊ��ֵ��
- **���ó���**��
  �����ƶ�����ĳ�����

---

### **8. `template<typename... Args> static void construct(T* ptr, Args&&... args)`**
- **����**��
  �� `ptr` ָ����ڴ��ַ�Ϲ���һ�� `T` ���󣬲����� `args` ת����
- **ʵ��**��
  ```cpp
  mystl::construct(ptr, mystl::forward<Args>(args)...);
  ```
- **����**��
    - ֧����������Ĺ��캯����
    - `mystl::forward` �Ǽ򻯰�� `std::forward`������ת��������
- **���ó���**��
  �����κι��캯�����ó�������ͨ�õĹ��췽����

---

### **9. `static void destroy(T* ptr)`**
- **����**��
  �� `ptr` ָ����ڴ��ַ�ϵ�����������������һ������
- **ʵ��**��
  ```cpp
  mystl::destroy(ptr);
  ```
- **����**��
    - ���ö��������������
    - ͨ��ʵ��Ϊ `ptr->~T()`��
- **���ó���**��
  �������ٵ�������

---

### **10. `static void destroy(T* first, T* last)`**
- **����**��
  ���ٴ� `first` �� `last` ��Χ�ڵĶ���
- **ʵ��**��
  ```cpp
  mystl::destroy(first, last);
  ```
- **����**��
    - ���÷�Χ��ÿ�����������������
    - ͨ��ʵ��Ϊ���� `[first, last)` ��Χ������ `destroy(T* ptr)`��
- **���ó���**��
  �������ٶ������

---

### **�ܽ�**
| **������**         | **����**                   | **���ó���**                            |
|-------------------|--------------------------|---------------------------------------|
| `allocate()`       | ���䵥�������ڴ�            | �������䵥��Ԫ��������ڴ�                |
| `allocate(n)`      | �����������ڴ�            | ������չ����ʱ�����������ڴ�               |
| `deallocate(ptr)`  | �ͷŵ��������ڴ�            | ����ɾ������Ԫ��ʱ�ͷ��ڴ�                |
| `deallocate(ptr, n)`| �ͷŶ�������ڴ�            | �������������ʱ�ͷ��ڴ�                  |
| `construct(ptr)`   | ����Ĭ�Ϲ��캯��            | ��ʼ������õ��ڴ�                      |
| `construct(ptr, value)`| ���ø��ƹ��캯��           | �������ж������ڴ���                   |
| `construct(ptr, value)`| �����ƶ����캯��           | ��Ч�ؽ���ʱ�������Դת�Ƶ����ڴ�         |
| `construct(ptr, args...)`| ʹ����������������      | ֧�����⸴�ӹ���ĳ���                   |
| `destroy(ptr)`     | ������������               | ���ٵ�������                            |
| `destroy(first, last)`| ���ٶ������              | ������ջ����ٷ�Χ�����ж���               |

��Щ���������˷������ĺ��Ĺ��ܣ�ʹ���ܸ�Ч�����ڴ�Ͷ����������ڣ�������ָ��ӳ������������ڷ���������ʵ���С�


