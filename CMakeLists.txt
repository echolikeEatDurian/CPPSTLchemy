cmake_minimum_required(VERSION 3.29)
project(my_cpp_stl_by_clion)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_cpp_stl_by_clion test/main.cpp
        include/allocator.h
        include/basic_string.h
        include/deque.h
        include/list.h
        include/queue.h
        include/set.h
        include/stack.h
        include/utils.h
        include/constructor.h
        include/map.h
        source/allocator.cpp
        source/constructor.cpp
        include/exception.h
        include/numeric.h
        source/numeric.cpp
        include/iterator.h
        include/functional.h
        include/type_traits.h
        include/astring.h
        source/finctional.cpp
        source/exception.cpp
        source/type_traits.cpp
)

