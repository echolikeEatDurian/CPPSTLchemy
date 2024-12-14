# my_cpp_stl_by_clion
Basic version c++ stl library implemented based on clion editor

# allocator
## 变量名的含义
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

这些 `typedef` 定义在 C++ 中为模板类 `allocator` 提供了一些别名，用于定义常用的类型。这种方式是为了提升代码的可读性和通用性，尤其是在泛型编程中更显得必要。以下是每个类型的具体含义和作用：

---

### **1. `typedef T value_type`**
- 定义了模板类所操作的基本类型。
- **作用**：
    - 表示 `allocator` 中分配内存或操作的对象类型是 `T`。
    - 提供了一种统一的命名方式，方便泛型容器和算法使用。
- **例子**：
  ```cpp
  allocator<int>::value_type x;  // x 是一个 int 类型
  ```

---

### **2. `typedef T* pointer`**
- 定义了指向模板类型 `T` 的指针。
- **作用**：
    - 提供了一种简洁的方式表示指针类型，减少代码复杂度。
- **例子**：
  ```cpp
  allocator<int>::pointer p = allocator<int>::allocate(); // p 是 int* 类型
  ```

---

### **3. `typedef const T* const_pointer`**
- 定义了指向常量 `T` 对象的指针。
- **作用**：
    - 表示指向的对象不能被修改（`*const_pointer` 不能改变其指向的值）。
    - 提升代码安全性，用于只读操作。
- **例子**：
  ```cpp
  allocator<int>::const_pointer cp;  // cp 是 const int* 类型
  ```

---

### **4. `typedef T& reference`**
- 定义了模板类型 `T` 的引用。
- **作用**：
    - 提供一种对对象进行操作的方式，而无需使用指针。
    - 在容器或算法中，经常用 `reference` 来操作元素。
- **例子**：
  ```cpp
  allocator<int>::reference r = someInt; // r 是 int& 类型
  ```

---

### **5. `typedef const T& const_reference`**
- 定义了常量类型 `T` 的引用。
- **作用**：
    - 表示引用的值不能被修改（`const_reference` 是 `const T&`）。
    - 提升代码安全性，用于只读访问。
- **例子**：
  ```cpp
  allocator<int>::const_reference cr = someConstInt; // cr 是 const int& 类型
  ```

---

### **6. `typedef size_t size_type`**
- 定义了一个无符号整数类型，用于表示大小（通常用来表示容器的大小或分配内存的数量）。
- **作用**：
    - 表示内存大小或对象数量，适合于各种平台（`size_t` 是标准定义的无符号整型）。
- **例子**：
  ```cpp
  allocator<int>::size_type n = 10; // n 是 size_t 类型
  allocator<int>::allocate(n);     // 分配 n 个 int 的内存
  ```

---

### **7. `typedef ptrdiff_t difference_type`**
- 定义了有符号整数类型，用于表示两个指针之间的距离（即两个指针的偏移量）。
- **作用**：
    - 用来描述指针之间的差值，适合各种平台（`ptrdiff_t` 是标准定义的有符号整型）。
- **例子**：
  ```cpp
  allocator<int>::difference_type diff = &array[5] - &array[2]; // diff 是 ptrdiff_t 类型
  ```

---

### **用途总结**
1. **一致性和通用性**：
    - 这些类型定义为模板类提供了统一的接口，便于标准容器（如 `std::vector`、`std::map`）等复用。
    - `allocator` 与容器合作时，容器无需关心具体的 `T` 类型，只需通过这些别名与 `allocator` 通信。

2. **提高代码可读性**：
    - 使用这些别名比直接使用底层类型（如 `int*`、`size_t`）更语义化，减少了代码歧义。

3. **平台兼容性**：
    - 通过 `size_t` 和 `ptrdiff_t`，保证了不同平台（32 位或 64 位）上的代码一致性。

4. **辅助模板设计**：
    - 为支持泛型编程提供了一种通用接口形式，使 `allocator` 可与其他 STL 组件协作。

---

### **常见场景**
这些类型别名在 STL 容器中被广泛使用，例如：

- `std::vector` 使用 `allocator` 的 `value_type` 知道其存储的元素类型。
- `size_type` 用于表示容器的大小或内存分配的数量。
- `difference_type` 用于迭代器之间的距离计算。
- `pointer` 和 `const_pointer` 用于管理底层数据存储指针。

它们构成了模板类与泛型容器之间的桥梁，显著增强了代码的灵活性和可移植性。

这些函数是 `allocator` 模板类中用于内存管理和对象生命周期操作的静态成员函数，负责 **分配内存**、**释放内存**、**构造对象** 和 **析构对象**。它们是对底层操作的封装，提供更高层次的抽象，便于配合 STL 容器或其他泛型代码使用。

---
## 接口的定义
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
- **功能**：
  分配一块未初始化的内存，足以存储一个 `T` 类型的对象。
- **实现**：
  ```cpp
  return static_cast<T*>(::operator new(sizeof(T)));
  ```
- **解释**：
    - 使用全局 `::operator new` 分配一块原始内存，返回指针。
    - 没有调用 `T` 的构造函数，内存内容未初始化。
- **适用场景**：
  用于需要动态分配单个对象内存时。

---

### **2. `static T* allocate(size_type n)`**
- **功能**：
  分配一块未初始化的内存，足以存储 `n` 个 `T` 类型的对象。
- **实现**：
  ```cpp
  if (n == 0) return nullptr;
  return static_cast<T*>(::operator new(n * sizeof(T)));
  ```
- **解释**：
    - 与单对象版本类似，但支持分配多个对象的内存。
    - 如果 `n == 0`，返回 `nullptr`，避免无效分配。
- **适用场景**：
  用于需要动态分配多个对象内存时，例如容器扩展容量。

---

### **3. `static void deallocate(T* ptr)`**
- **功能**：
  释放通过 `allocate()` 分配的单个对象的内存。
- **实现**：
  ```cpp
  if (ptr == nullptr) return;
  ::operator delete(ptr);
  ```
- **解释**：
    - 使用全局 `::operator delete` 释放内存。
    - 检查 `ptr` 是否为 `nullptr`，避免释放无效指针。
- **适用场景**：
  用于释放 `allocate()` 分配的内存。

---

### **4. `static void deallocate(T* ptr, size_type n)`**
- **功能**：
  释放通过 `allocate(size_type n)` 分配的多个对象的内存。
- **实现**：
    - 与单对象版本相同，底层实现不关心 `n`。
- **解释**：
    - 这两个版本的 `deallocate` 是接口上的区分，主要为了与 `allocate` 对应。
- **适用场景**：
  用于释放多对象内存。

---

### **5. `static void construct(T* ptr)`**
- **功能**：
  在给定的内存地址 `ptr` 上调用默认构造函数，构造一个 `T` 对象。
- **实现**：
  ```cpp
  mystl::construct(ptr);
  ```
- **解释**：
    - `construct` 是 `mystl` 的一个辅助函数，通常调用 `new (ptr) T()`。
    - 利用定位 `new` 在指定位置构造对象。
- **适用场景**：
  用于初始化分配好的内存。

---

### **6. `static void construct(T* ptr, const T& value)`**
- **功能**：
  在 `ptr` 指向的内存地址上使用复制构造函数，构造一个与 `value` 相等的 `T` 对象。
- **实现**：
  ```cpp
  mystl::construct(ptr, value);
  ```
- **解释**：
    - 调用复制构造函数，生成新的对象。
- **适用场景**：
  用于将现有对象的值拷贝到新的对象。

---

### **7. `static void construct(T* ptr, T&& value)`**
- **功能**：
  在 `ptr` 指向的内存地址上使用移动构造函数，构造一个从 `value` 移动过来的 `T` 对象。
- **实现**：
  ```cpp
  mystl::construct(ptr, mystl::move(value));
  ```
- **解释**：
    - 利用移动构造函数减少拷贝开销。
    - `mystl::move` 是一个简化版的 `std::move`，将左值转换为右值。
- **适用场景**：
  用于移动语义的场景。

---

### **8. `template<typename... Args> static void construct(T* ptr, Args&&... args)`**
- **功能**：
  在 `ptr` 指向的内存地址上构造一个 `T` 对象，参数由 `args` 转发。
- **实现**：
  ```cpp
  mystl::construct(ptr, mystl::forward<Args>(args)...);
  ```
- **解释**：
    - 支持任意参数的构造函数。
    - `mystl::forward` 是简化版的 `std::forward`，完美转发参数。
- **适用场景**：
  用于任何构造函数调用场景，最通用的构造方法。

---

### **9. `static void destroy(T* ptr)`**
- **功能**：
  在 `ptr` 指向的内存地址上调用析构函数，销毁一个对象。
- **实现**：
  ```cpp
  mystl::destroy(ptr);
  ```
- **解释**：
    - 调用对象的析构函数。
    - 通常实现为 `ptr->~T()`。
- **适用场景**：
  用于销毁单个对象。

---

### **10. `static void destroy(T* first, T* last)`**
- **功能**：
  销毁从 `first` 到 `last` 范围内的对象。
- **实现**：
  ```cpp
  mystl::destroy(first, last);
  ```
- **解释**：
    - 调用范围内每个对象的析构函数。
    - 通常实现为遍历 `[first, last)` 范围并调用 `destroy(T* ptr)`。
- **适用场景**：
  用于销毁多个对象。

---

### **总结**
| **函数名**         | **功能**                   | **常用场景**                            |
|-------------------|--------------------------|---------------------------------------|
| `allocate()`       | 分配单个对象内存            | 容器分配单个元素所需的内存                |
| `allocate(n)`      | 分配多个对象内存            | 容器扩展容量时，批量分配内存               |
| `deallocate(ptr)`  | 释放单个对象内存            | 容器删除单个元素时释放内存                |
| `deallocate(ptr, n)`| 释放多个对象内存            | 容器析构或清空时释放内存                  |
| `construct(ptr)`   | 调用默认构造函数            | 初始化分配好的内存                      |
| `construct(ptr, value)`| 调用复制构造函数           | 拷贝现有对象到新内存中                   |
| `construct(ptr, value)`| 调用移动构造函数           | 高效地将临时对象的资源转移到新内存         |
| `construct(ptr, args...)`| 使用任意参数构造对象      | 支持任意复杂构造的场景                   |
| `destroy(ptr)`     | 调用析构函数               | 销毁单个对象                            |
| `destroy(first, last)`| 销毁多个对象              | 容器清空或销毁范围内所有对象               |

这些函数构成了分配器的核心功能，使其能高效管理内存和对象生命周期，适配各种复杂场景，尤其是在泛型容器的实现中。


# type_trait
这个头文件 `type_traits.h` 定义了用于类型信息提取的一些工具和类型特征（type traits）。它主要包含两个部分：

1. **`m_integral_constant` 及其扩展**：用于创建常量类型特征。
2. **类型特征（type traits）**：如 `is_pair`，用于检查某个类型是否为特定类型。

### 1. `m_integral_constant` 和 `m_bool_constant`

#### `m_integral_constant`
这是一个模板结构体，允许定义一个常量的类型特征：

```cpp
template <class T, T v>
struct m_integral_constant
{
  static constexpr T value = v;
};
```

- `T` 是类型，`v` 是一个常量值。
- `m_integral_constant` 通过 `value` 成员暴露了一个常量值 `v`，它具有类型 `T`。

  例如，可以定义一个整数常量类型：

  ```cpp
  typedef m_integral_constant<int, 42> my_constant;
  // my_constant::value 是 42，类型是 int
  ```

#### `m_bool_constant`
`m_bool_constant` 是 `m_integral_constant` 的一个特化，用于表示布尔常量。它通过类型别名实现：

```cpp
template <bool b>
using m_bool_constant = m_integral_constant<bool, b>;
```

- 它专门为 `bool` 类型的常量值提供了一种简便的方式。

  例如：

  ```cpp
  typedef m_bool_constant<true>  m_true_type;  // 类型表示 true
  typedef m_bool_constant<false> m_false_type; // 类型表示 false
  ```

  这样，`m_true_type` 和 `m_false_type` 就是表示 `true` 和 `false` 的类型特征。

### 2. `is_pair` 类型特征

`is_pair` 是一个类型特征（type trait），用于检查一个类型是否是 `pair` 类型：

```cpp
template <class T1, class T2>
struct pair; // 前置声明

template <class T>
struct is_pair : mystl::m_false_type {};  // 默认不是 pair 类型

template <class T1, class T2>
struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};  // 如果是 pair 类型，返回 true
```

- `is_pair` 是一个模板结构体，用于判断一个类型是否是 `pair<T1, T2>` 类型。
- 默认情况下，`is_pair` 继承自 `m_false_type`，表示它不是 `pair` 类型。
- 当类型是 `pair<T1, T2>` 时，`is_pair` 会继承自 `m_true_type`，表示它是 `pair` 类型。

例如，使用这个类型特征来检查类型是否为 `pair` 类型：

```cpp
static_assert(is_pair<mystl::pair<int, double>>::value, "It's a pair!");
static_assert(!is_pair<int>::value, "It's not a pair!");
```

### 总结

- **`m_integral_constant`** 和 **`m_bool_constant`** 用于定义常量值和布尔常量类型特征，可以在模板元编程中用来传递类型信息。
- **`is_pair`** 是一个示例类型特征，它帮助判断一个类型是否是 `pair` 类型，这对于模板编程非常有用，可以根据类型进行不同的处理。