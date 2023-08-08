# 简单说明

## 文件介绍

**thread_func.cpp** : 线程可以使用的函数类型

**thread_para.cpp** : 比较线程可以使用的函数的传参情况

**thread_mutex.cpp** : 使用 `mutex` 对多线程中互斥情况进行处理

## Q & A

**Q：** 在 **thread_func.cpp** 文件中，为什么 `std::thread testThread3(&TestClass::testClassFunction, &testClass)` 中写 `&testClass` 而不是 `testClass`？

**A：** 这样写可以防止生成临时变量，通过引用的方式调用更加节约资源。
