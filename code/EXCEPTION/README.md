# 简单说明

## 文件介绍

**division_by_zero.cpp** : 一个简单的例子，展示零作除数时的异常处理

**read_file.cpp** : 一个简单的例子，展示读取文件时的异常处理

**bad_allocation.cpp** : `bad_allocation` 异常与指针

**out_of_range.cpp** : `out_of_range` 异常与索引

## Q & A

Q：一个基础的问题，在 **division_by_zero.cpp** 文件中，为什么 `catch()` 中的类型写 `const char*` ？

Q：在 **bad_allocation.cpp** 中，如果将 `shared_int_vec.push_back(shared_int);` 这一句代码删去会怎么样？为什么？

Q：在 **bad_allocation.cpp** 中，如果将 `std::shared_ptr` 都改成 `std::unique_ptr` 会怎么样？为什么？

Q：在 **out_of_range.cpp** 中，如果将 `int_vec.at(10)` 修改为 `int_vec[10]` 会怎么样？为什么？
