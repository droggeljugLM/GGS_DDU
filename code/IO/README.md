# Q&A

Q：关于 `cin` 和 `fstream` 的两个文件都有类似的 `while` 语句，`while` 语句中的逗号运算符本身是什么语法、在这里起什么作用，这个 `while` 对整个代码又起什么作用？

A：逗号运算符的基本概念可以参阅[官方文档](https://learn.microsoft.com/zh-cn/cpp/cpp/comma-operator)。在这里逗号运算符首先分别执行了逗号连接的部分，并使得 `while` 关键字括号里返回值为 `!std::cin.eof()` ，为关键字提供了运行条件。而 `while` 保证了这个代码可以一直运行直到用户决定终止。

Q：`<iostream>` 已经包括了 `<string>` 大部分的功能，为什么在 `fstream` 的使用过程中要引入 `<string>` ？

A：官方文档在这里：[iostream](https://learn.microsoft.com/zh-cn/cpp/standard-library/iostream) [string](https://learn.microsoft.com/zh-cn/cpp/standard-library/string)。在这里，引入 `<string>` 的目的是使用 `std::getline()` 这个函数。注意和 `cin.getline()` 进行区分。

Q：一个基本问题的回顾， `'\n'` 和 `"\n"` 有什么区别？

A：这个问题在[官方文档](https://learn.microsoft.com/zh-cn/cpp/cpp/string-and-character-literals-cpp)有非常好的解答。

Q：为什么 `ofstream` 是写文件，`ifstream` 是读文件呢，这里io的主体是谁呢？

A：在这里，io 的主体是程序，或者说是内存。所以 `ofstream` 是程序向文件输出数据，`ifstream` 是程序从文件输入数据。
