# 简单说明

## 文件介绍

**division_by_zero.cpp** : 一个简单的例子，展示零作除数时的异常处理

**read_file.cpp** : 一个简单的例子，展示读取文件时的异常处理

**bad_allocation.cpp** : `bad_allocation` 异常与指针

**out_of_range.cpp** : `out_of_range` 异常与索引

## Q & A

**Q：**一个基础的问题，在 **division_by_zero.cpp** 文件中，为什么 `catch()` 中的类型写 `const char*` ？

**A：**因为被 `""` 包裹起来的字符串的类型自动为 `const char*` ，如果要使用 `std::string` 需要类型转换。详细的内容可以参考[官方文档](https://learn.microsoft.com/zh-cn/cpp/cpp/string-and-character-literals-cpp)。

**Q：**在 **bad_allocation.cpp** 中，如果将 `shared_int_vec.push_back(shared_int);` 这一句代码删去会怎么样？为什么？

**A：**如果删去，代码将不会出现任何错误信息或异常，这是因为智能指针会被自动释放，具体可以参考智能指针的[官方文档](https://learn.microsoft.com/zh-cn/cpp/cpp/smart-pointers-modern-cpp)。

**Q：**在 **bad_allocation.cpp** 中，如果将 `std::shared_ptr` 都改成 `std::unique_ptr` 会怎么样？为什么？

**A：**如果使用 `std::unique_ptr` ，代码会出错，甚至过不了编译。此时代码变为：

```cpp

    std::vector<std::unique_ptr<int>> unique_int_vec;
    while (1)
    {
        std::unique_ptr<int> unique_int(new int[10e6]());
        unique_int_vec.push_back(unique_int);
    }

```

很容易发现 `push_back` 会尝试对 `unique_int` 进行拷贝，而 `std::unique_ptr` 并不能拥有拷贝构造函数，所以会出现错误，如果非要使用的话可以使用如下的办法：

```cpp

    std::vector<std::unique_ptr<int>> unique_int_vec;
    while (1)
    {
        std::unique_ptr<int> unique_int(new int[10e6]());
        unique_int_vec.push_back(std::move(unique_int));
    }

```

**Q：**在 **out_of_range.cpp** 中，如果将 `int_vec.at(10)` 修改为 `int_vec[10]` 会怎么样？为什么？

**A：**直接使用 `[]` 来访问容器或数组的元素的行为，如果下标越界就会出现未定义行为这个问题，程序会立刻终值，但使用 `at()` 则会先进行一个下标越界检测，如果越界就抛出一个异常，这时候就可以用 `try ... catch` 来捕获了。在 **out_of_range.cpp** 文件的命名空间 `how_to_avoid_error` 中，提供了一种可能的解决思路。
