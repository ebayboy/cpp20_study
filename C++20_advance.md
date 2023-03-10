
# C++20高级编程
## 第I部分  专业的C 简介
### 第1章  C 和标准库速成   3
1.1  C 速成   3
1.1.1  小程序“Hello World”   4
1.1.2  名称空间   7
1.1.3  字面量   9
1.1.4  变量   9
1.1.5  运算符   12
1.1.6  枚举类型   14
1.1.7  结构体   16
1.1.8  条件语句   17
1.1.9  条件运算符   19
1.1.10  逻辑比较运算符   20
1.1.11  三向比较运算符   21
1.1.12  函数   22
1.1.13  属性   23
1.1.14  C风格的数组   26
1.1.15  std::array   27
1.1.16  std::vector   28
1.1.17  std::pair   28
1.1.18  std::optional   29
1.1.19  结构化绑定   30
1.1.20  循环   30
1.1.21  初始化列表   31
1.1.22  C 中的字符串   32
1.1.23  作为面向对象语言的C   32
1.1.24  作用域解析   35
1.1.25  统一初始化   36
1.1.26  指针和动态内存   39
1.1.27  const的用法   43
1.1.28  constexpr关键字   45
1.1.29  consteval关键字   46
1.1.30  引用   47
1.1.31  const_cast()   55
1.1.32  异常   56
1.1.33  类型别名   56
1.1.34  类型定义   57
1.1.35  类型推断   58
1.1.36  标准库   60
1.2  个大型的C 程序   61
1.2.1  雇员记录系统   61
1.2.2  Employee类   61
1.2.3  Database类   64
1.2.4  用户界面   67
1.2.5  评估程序   69
1.3  本章小结   69
1.4  练习   69

### 第2章  使用string和string_view   71
2.1  动态字符串   71
2.1.1  C风格字符串   71
2.1.2  字符串字面量   73
2.1.3  C std::string类   75
2.1.4  数值转换   78
2.1.5  std::string_view类   81
2.1.6  非标准字符串   84
2.2  字符串格式化   84
2.2.1  格式说明符   85
2.2.2  格式说明符错误   87
2.2.3  支持自定义类型   87
2.3  本章小结   90
2.4  练习   90

### 第3章  编码风格   91
3.1  良好外观的重要性   91
3.1.1  事先考虑   91
3.1.2  良好风格的元素   92
3.2  为代码编写文档   92
3.2.1  使用注释的原因   92
3.2.2  注释的风格   96
3.3  分解   99
3.3.1  通过重构分解   100
3.3.2  通过设计分解   101
3.3.3  本书中的分解   101
3.4  命名   101
3.4.1  选择恰当的名称   101
3.4.2  命名约定   102
3.5  使用具有风格的语言特性   103
3.5.1  使用常量   104
3.5.2  使用引用代替指针   104
3.5.3  使用自定义异常   104
3.6  格式   105
3.6.1  关于大括号对齐的争论   105
3.6.2  关于空格和圆括号的争论   106
3.6.3  空格、制表符、换行符   106
3.7  风格的挑战   107
3.8  本章小结   107
3.9  练习   107

## 第II部分  专业的C 软件设计
### 第4章  设计专业的C 程序   113
4.1  程序设计概述   113
4.2  程序设计的重要性   114
4.3  C 设计   116
4.4  C 设计的两个原则   116
4.4.1  抽象   116
4.4.2  重用   118
4.5  重用现有代码   119
4.5.1  关于术语的说明   119
4.5.2  决定是否重用代码   120
4.5.3  重用代码的指导原则   121
4.6  设计一个国际象棋程序   127
4.6.1  需求   127
4.6.2  设计步骤   127
4.7  本章小结   132
4.8  练习   133
### 第5章  面向对象设计   135
5.1  过程化的思考方式   135
5.2  面向对象思想   136
5.2.1  类   136
5.2.2  组件   136
5.2.3  属性   136
5.2.4  行为   137
5.2.5  综合考虑   137
5.3  生活在类的世界里   138
5.3.1  过度使用类   138
5.3.2  过于通用的类   139
5.4  类之间的关系   139
5.4.1  “有一个”关系   139
5.4.2  “是一个”关系(继承)   140
5.4.3  “有一个”与“是一个”的
区别   142
5.4.4  not-a关系   144
5.4.5  层次结构   145
5.4.6  多重继承   146
5.4.7  混入类   147
5.5  本章小结   147
5.6  练习   148

### 第6章  设计可重用代码   149
6.1  重用哲学   149
6.2  如何设计可重用代码   150
6.2.1  使用抽象   150
6.2.2  构建理想的重用代码   151
6.2.3  设计有用的接口   157
6.2.4  设计成功的抽象   162
6.2.5  SOLID原则   162
6.3  本章小结   163
6.4  练习   163

## 第III部分  C 编码方法
### 第7章  内存管理   167
7.1  使用动态内存   167
7.1.1  如何描绘内存   168
7.1.2  分配和释放   169
7.1.3  数组   170
7.1.4  使用指针   177
7.2  数组-指针的对偶性   178
7.2.1  数组就是指针   178
7.2.2  并非所有指针都是数组   180
7.3  底层内存操作   180
7.3.1  指针运算   180
7.3.2  自定义内存管理   181
7.3.3  垃圾回收   181
7.3.4  对象池   182
7.4  常见的内存陷阱   182
7.4.1  数据缓冲区分配不足以及
内存访问越界   182
7.4.2  内存泄漏   183
7.4.3  双重释放和无效指针   186
7.5  智能指针   186
7.5.1  unique_ptr   187
7.5.2  shared_ptr   190
7.5.3  weak_ptr   193
7.5.4  向函数传递参数   193
7.5.5  从函数中返回   194
7.5.6  enable_shared_from_this   194
7.5.7  过时的、移除的auto_ptr   195
7.6  本章小结   195
7.7  练习   195

### 第8章  类和对象   197
8.1  电子表格示例介绍   197
8.2  编写类   198
8.2.1  类定义   198
8.2.2  定义方法   200
8.2.3  使用对象   203
8.3  对象的生命周期   205
8.3.1  创建对象   205
8.3.2  销毁对象   219
8.3.3  对象赋值   220
8.3.4  编译器生成的拷贝构造函数和
拷贝赋值运算符   223
8.3.5  复制和赋值的区别   223
8.4  本章小结   224
8.5  练习   225

### 第9章  精通类和对象   227
9.1  友元   227
9.2  对象中的动态内存分配   228
9.2.1  Spreadsheet类   228
9.2.2  使用析构函数释放内存   231
9.2.3  处理复制和赋值   231
9.2.4  使用移动语义处理移动   237
9.2.5  零规则   246
9.3  与方法有关的更多内容   246
9.3.1  static方法   246
9.3.2  const方法   247
9.3.3  方法重载   248
9.3.4  内联方法   251
9.3.5  默认参数   252
9.4  不同的数据成员类型   252
9.4.1  静态数据成员   253
9.4.2  const static数据成员   254
9.4.3  引用数据成员   255
9.5  嵌套类   256
9.6  类内的枚举类型   257
9.7  运算符重载   258
9.7.1  示例：为SpreadsheetCell
实现加法   258
9.7.2  重载算术运算符   261
9.7.3  重载比较运算符   262
9.7.4  创建具有运算符重载的类型   266
9.8  创建稳定的接口   266
9.9  本章小结   270
9.10  练习   270

### 第10章  揭秘继承技术   271
10.1  使用继承构建类   271
10.1.1  扩展类   272
10.1.2  重写方法   275
10.2  使用继承重用代码   282
10.2.1  WeatherPrediction类   282
10.2.2  在派生类中添加功能   283
10.2.3  在派生类中替换功能   284
10.3  利用父类   285
10.3.1  父类构造函数   285
10.3.2  父类的析构函数   286
10.3.3  使用父类方法   287
10.3.4  向上转型和向下转型   289
10.4  继承与多态性   290
10.4.1  回到电子表格   290
10.4.2  设计多态性的电子表格
单元格   291
10.4.3  SpreadsheetCell基类   291
10.4.4  独立的派生类   293
10.4.5  利用多态性   294
10.4.6  考虑将来   295
10.5  多重继承   296
10.5.1  从多个类继承   296
10.5.2  名称冲突和歧义基类   297
10.6  有趣而晦涩的继承问题   300
10.6.1  修改重写方法的返回类型   300
10.6.2  派生类中添加虚基类方法的
重载   301
10.6.3  继承的构造函数   302
10.6.4  重写方法时的特殊情况   306
10.6.5  派生类中的复制构造函数和
赋值运算符   312
10.6.6  运行期类型工具   313
10.6.7  非public继承   314
10.6.8  虚基类   315
10.7  类型转换   316
10.7.1  static_cast()   316
10.7.2  reinterpret_cast()   317
10.7.3  std::bit_cast()   318
10.7.4  dynamic_cast()   318
10.7.5  类型转换小结   319
10.8  本章小结   319
10.9  练习   320

### 第11章  零碎的工作   321
11.1  模块   321
11.1.1  模块接口文件   322
11.1.2  模块实现文件   324
11.1.3  从实现中分离接口   325
11.1.4  可见性和可访问性   326
11.1.5  子模块   326
11.1.6  模块划分   327
11.1.7  头文件单元   329
11.2  头文件   330
11.2.1  重复定义   330
11.2.2  循环依赖   330
11.2.3  查询头文件是否存在   331
11.3  核心语言特性的特性测试宏   331
11.4  STATIC关键字   332
11.4.1  静态数据成员和方法   332
11.4.2  静态链接   332
11.4.3  函数中的静态变量   334
11.4.4  非局部变量的初始化顺序   335
11.4.5  非局部变量的销毁顺序   335
11.5  C的实用工具   335
11.5.1  变长参数列表   336
11.5.2  预处理器宏   337
11.6  本章小结   338
11.7  练习   338

### 第12章  利用模板编写泛型代码   341
12.1  模板概述   341
12.2  类模板   342
12.2.1  编写类模板   342
12.2.2  编译器处理模板的原理   349
12.2.3  将模板代码分布到多个
文件中   350
12.2.4  模板参数   351
12.2.5  方法模板   355
12.2.6  类模板的特化   359
12.2.7  从类模板派生   361
12.2.8  继承还是特化   362
12.2.9  模板别名   362
12.3  函数模板   363
12.3.1  函数模板的重载   364
12.3.2  类模板的友元函数模板   365
12.3.3  对模板参数推导的更多介绍   366
12.3.4  函数模板的返回类型   367
12.4  简化函数模板的语法   368
12.5  变量模板   369
12.6  概念   369
12.6.1  语法   369
12.6.2  约束表达式   370
12.6.3  预定义的标准概念   372
12.6.4  类型约束的auto   372
12.6.5  类型约束和函数模板   373
12.6.6  类型约束和类模板   375
12.6.7  类型约束和类方法   375
12.6.8  类型约束和模板特化   376
12.7  本章小结   376
12.8  练习   377

### 第13章  C I/O揭秘   379
13.1  使用流   379
13.1.1  流的含义   380
13.1.2  流的来源和目的地   381
13.1.3  流式输出   381
13.1.4  流式输入   386
13.1.5  对象的输入输出   392
13.1.6  自定义的操作算子   393
13.2  字符串流   393
13.3  文件流   394
13.3.1  文本模式与二进制模式   395
13.3.2  通过seek()和tell()在文件中
转移   395
13.3.3  将流链接在一起   397
13.4  双向I/O   398
13.5  文件系统支持库   399
13.5.1  路径   399
13.5.2  目录条目   401
13.5.3  辅助函数   401
13.5.4  目录遍历   401
13.6  本章小结   402
13.7  练习   403

### 第14章  错误处理   405
14.1  错误与异常   405
14.1.1  异常的含义   405
14.1.2  C 中异常的优点   406
14.1.3  建议   407
14.2  异常机制   407
14.2.1  抛出和捕获异常   408
14.2.2  异常类型   410
14.2.3  按const引用捕获异常对象   411
14.2.4  抛出并捕获多个异常   411
14.2.5  未捕获的异常   414
14.2.6  noexcept说明符   415
14.2.7  noexcept(expression)说明符   415
14.2.8  noexcept(expression)运算符   415
14.2.9  抛出列表   416
14.3  异常与多态性   416
14.3.1  标准异常层次结构   416
14.3.2  在类层次结构中捕获异常   418
14.3.3  编写自己的异常类   419
14.3.4  源码位置   421
14.3.5  日志记录的源码位置   422
14.3.6  异常的源码位置   422
14.3.7  嵌套异常   423
14.4 重新抛出异常   425
14.5  堆栈的释放与清理   426
14.5.1  使用智能指针   427
14.5.2  捕获、清理并重新抛出   428
14.6  常见的错误处理问题   428
14.6.1  内存分配错误   428
14.6.2  构造函数中的错误   430
14.6.3  构造函数的function-try-blocks   432
14.6.4  析构函数中的错误   435
14.7  本章小结   435
14.8  练习   435

### 第15章  C 运算符重载   437
15.1  运算符重载概述   437
15.1.1  重载运算符的原因   438
15.1.2  运算符重载的限制   438
15.1.3  运算符重载的选择   438
15.1.4  不应重载的运算符   440
15.1.5  可重载运算符小结   440
15.1.6  右值引用   443
15.1.7  优先级和结合性   444
15.1.8  关系运算符   444
15.2  重载算术运算符   445
15.2.1  重载一元负号和一元正号
运算符   445
15.2.2  重载递增和递减运算符   446
15.3  重载按位运算符和二元逻辑
运算符   446
15.4  重载插入运算符和提取运算符   447
15.5  重载下标运算符   448
15.5.1  通过operator[]提供只读访问   451
15.5.2  非整数数组索引   452
15.6  重载函数调用运算符   452
15.7  重载解除引用运算符   453
15.7.1  实现operator*   454
15.7.2  实现operator->   455
15.7.3  operator.*和operator ->*的
含义   455
15.8  编写转换运算符   456
15.8.1  auto运算符   456
15.8.2  使用显式转换运算符解决
多义性问题   457
15.8.3  用于布尔表达式的转换   457
15.9  重载内存分配和内存释放
运算符   459
15.9.1  new和delete的工作原理   459
15.9.2  重载operator new和
operator delete   461
15.9.3  显式地删除/默认化operator new
和operator delete   463
15.9.4  重载带有额外参数的operator new
和operator delete   463
15.9.5  重载带有内存大小参数的
operator delete   464
15.9.6  重载用户定义的字面量
运算符   464
15.9.7  cooked模式字面量运算符   465
15.9.8  raw模式字面量运算符   465
15.9.9  标准用户定义的字面量   466
15.10  本章小结   466
15.11  练习   466

### 第16章  C 标准库概述   469
16.1  编码原则   470
16.1.1  使用模板   470
16.1.2  使用运算符重载   470
16.2  C 标准库概述   470
16.2.1  字符串   470
16.2.2  正则表达式   471
16.2.3  I/O流   471
16.2.4  智能指针   471
16.2.5  异常   471
16.2.6  数学工具   472
16.2.7  时间和日期工具   473
16.2.8  随机数   473
16.2.9  初始化列表   474
16.2.10  Pair和Tuple   474
16.2.11  词汇类型   474
16.2.12  函数对象   474
16.2.13  文件系统   474
16.2.14  多线程   475
16.2.15  类型萃取   475
16.2.16  标准整数类型   475
16.2.17  标准库特性测试宏   475
16.2.18     476
16.2.19  源位置   476
16.2.20  容器   476
16.2.21  算法   482
16.2.22  范围库   488
16.2.23  标准库中还缺什么   488
16.3  本章小结   489
16.4  练习   489

### 第17章  理解迭代器与范围库   491
17.1  迭代器   491
17.1.1  获取容器的迭代器   494
17.1.2  迭代器萃取   495
17.1.3  示例   495
17.2  流迭代器   496
17.2.1  输出流迭代器   497
17.2.2  输入流迭代器   497
17.3  迭代器适配器   498
17.3.1  插入迭代器   498
17.3.2  逆向迭代器   499
17.3.3  移动迭代器   500
17.4  范围   502
17.4.1  基于范围的算法   502
17.4.2  视图   504
17.4.3  范围工厂   508
17.5  本章小结   509
17.6  练习   509

### 第18章  标准库容器   511
18.1  容器概述   511
18.1.1  对元素的要求   512
18.1.2  异常和错误检查   513
18.2  顺序容器   514
18.2.1  vector   514
18.2.2  vector特化   531
18.2.3  deque   532
18.2.4  list   532
18.2.5  forward_list   535
18.2.6  array   537
18.2.7  span   538
18.3  容器适配器   540
18.3.1  queue   540
18.3.2  priority_queue   542
18.3.3  stack   545
18.4  有序关联容器   545
18.4.1  pair工具类   545
18.4.2  map   546
18.4.3  multimap   554
18.4.4  set   556
18.4.5  multiset   558
18.5  无序关联容器/哈希表   558
18.5.1  哈希函数   559
18.5.2  unordered_map   560
18.5.3  unordered_multimap   563
18.5.4  unordered_set/
unordered_multiset   564
18.6  其他容器   564
18.6.1  标准C风格数组   564
18.6.2  string   565
18.6.3  流   566
18.6.4  bitset   566
18.7  本章小结   570
18.8  练习   570

### 第19章  函数指针，函数对象，lambda
表达式   571
19.1  函数指针   571
19.2  指向方法(和数据成员)的指针   573
19.3  函数对象   576
19.3.1  编写个函数对象   576
19.3.2  标准库中的函数对象   576
19.4  lambda表达式   582
19.4.1  语法   583
19.4.2  lambda表达式作为参数   587
19.4.3  泛型lambda表达式   587
19.4.4  lambda捕获表达式   587
19.4.5  模板化lambda表达式   588
19.4.6  lambda表达式作为返回类型   589
19.4.7  未计算上下文中的lambda
表达式   589
19.4.8  默认构造、拷贝和赋值   589 19.5  调用   590
19.6  本章小结   590
19.7  练习   590

### 第20章  掌握标准库算法   593
20.1  算法概述   593
20.1.1  find()和find_if()算法   594
20.1.2  accumulate()算法   596
20.1.3  在算法中使用移动语义   597
20.1.4  算法回调   597
20.2  算法详解   598
20.2.1  非修改序列算法   598
20.2.2  修改序列算法   603
20.2.3  操作算法   611
20.2.4  分区算法   613
20.2.5  排序算法   614
20.2.6  二分查找算法   615
20.2.7  集合算法   616
20.2.8  小/算法   618
20.2.9  并行算法   619
20.2.10  约束算法   620
20.2.11  数值处理算法   621
20.3  本章小结   622
20.4  练习   622

### 第21章  字符串的本地化与正则表达式   625
21.1  本地化   625
21.1.1  宽字符   625
21.1.2  本地化字符串字面量   626
21.1.3  非西方字符集   626
21.1.4  locale和facet   628
21.1.5  转换   631
21.2  正则表达式   632
21.2.1  ECMAScript语法   632
21.2.2  regex库   637
21.2.3  regex_match()   638
21.2.4  regex_search()   640
21.2.5  regex_iterator   641
21.2.6  regex_token_iterator   642
21.2.7  regex_replace()   644
21.3  本章小结   646
21.4  练习   646

### 第22章  日期和时间工具   647
22.1  编译期有理数   647
22.2  持续时间   649
22.3  时钟   653
22.4  时间点   655
22.5  日期   656
22.6  时区   658
22.7  本章小结   659
22.8  练习   659

### 第23章  随机数工具   661
23.1  C风格随机数生成器   661
23.1.1  随机数引擎   662
23.1.2  随机数引擎适配器   663
23.1.3  预定义的随机数引擎和
引擎适配器   664
23.1.4  生成随机数   664
23.1.5  随机数分布   666
23.2  本章小结   668
23.3  练习   669

### 第24章  其他库工具   671
24.1  variant   671
24.2  any   673
24.3  元组   674
24.3.1  分解元组   676
24.3.2  串联   677
24.3.3  比较   677
24.3.4  make_from_tuple()   678
24.3.5  apply()   678
24.4  本章小结   678
24.5  练习   678

## 第IV部分  掌握C 的高级特性
### 第25章  自定义和扩展标准库   683
25.1  分配器   683
25.2  扩展标准库   684
25.2.1  扩展标准库的原因   685
25.2.2  编写标准库算法   685
25.2.3  编写标准库容器   686
25.2.4  将directed_graph实现为
标准库容器   696
25.2.5  添加分配器支持   712
25.2.6  改善graph_node   716
25.2.7  附加的标准库类似功能   717
25.2.8  进一步改善   719
25.2.9  其他容器类型   719
25.3  本章小结   720
25.4  练习   720

### 第26章  高级模板   721
26.1  深入了解模板参数   721
26.1.1  深入了解模板类型参数   721
26.1.2  template template参数介绍   724
26.1.3  深入了解非类型模板参数   725
26.2  类模板部分特例化   727
26.3  通过重载模拟函数部分特例化   730
26.4  模板递归   731
26.4.1  N维网格：初次尝试   731
26.4.2  真正的N维网格   732
26.5  可变参数模板   734
26.5.1  类型安全的变长参数列表   734
26.5.2  可变数目的混入类   736
26.5.3  折叠表达式   737
26.6  模板元编程   739
26.6.1  编译时阶乘   739
26.6.2  循环展开   740
26.6.3  打印元组   741
26.6.4  类型trait   744
26.6.5  模板元编程结论   752
26.7  本章小结   752
26.8  练习   752

### 第27章  C 多线程编程   753
27.1  多线程编程概述   754
27.1.1  争用条件   755
27.1.2  撕裂   756
27.1.3  死锁   756
27.1.4  伪共享   757
27.2  线程   757
27.2.1  通过函数指针创建线程   758
27.2.2  通过函数对象创建线程   759
27.2.3  通过lambda创建线程   760
27.2.4  通过成员函数创建线程   760
27.2.5  线程本地存储   761
27.2.6  取消线程   761
27.2.7  自动join线程   761
27.2.8  从线程获得结果   762
27.2.9  复制和重新抛出异常   762
27.3  原子操作库   764
27.3.1  原子操作   766
27.3.2  原子智能指针   767
27.3.3  原子引用   767
27.3.4  使用原子类型   767
27.3.5  等待原子变量   769
27.4  互斥   770
27.4.1  互斥体类   770
27.4.2  锁   772
27.4.3  std::call_once   774
27.4.4  互斥体对象的用法示例   776
27.5  条件变量   779
27.5.1  虚假唤醒   780
27.5.2  使用条件变量   780
27.6  latch   781
27.7  barrier   782
27.8  semaphore   782
27.9  future   783
27.9.1  std::promise和std::future   784
27.9.2  std::packaged_task   784
27.9.3  std::async   785
27.9.4  异常处理   786
27.9.5  std::shared_future   786
27.10  示例：多线程的Logger类   787
27.11  线程池   791
27.12  协程   792
27.13  线程设计和实践   793
27.14  本章小结   794
27.15  练习   794

## 第V部分  C 软件工程
### 第28章  充分利用软件工程方法   799
28.1  过程的必要性   799
28.2  软件生命周期模型   800
28.2.1  瀑布模型   800
28.2.2  生鱼片模型   802
28.2.3  螺旋类模型   802
28.2.4  敏捷   804
28.3  软件工程方法论   805
28.3.1  UP   805
28.3.2  RUP   806
28.3.3  Scrum   806
28.3.4  极限编程   808
28.3.5  软件分流   812
28.4  构建自己的过程和方法   812
28.4.1  对新思想采取开放态度   812
28.4.2  提出新想法   812
28.4.3  知道什么行得通、什么行不通   812
28.4.4  不要逃避   813
28.5  源代码控制   813
28.6  本章小结   814
28.7  练习   814

### 第29章  编写高效的C 程序   817
29.1  性能和效率概述   817
29.1.1  提升效率的两种方式   818
29.1.2  两种程序   818
29.1.3  C 是不是低效的语言   818
29.2  语言层次的效率   818
29.2.1  高效地操纵对象   819
29.2.2  预分配内存   823
29.2.3  使用内联方法和函数   823
29.3  设计层次的效率   823
29.3.1  尽可能多地缓存   823
29.3.2  使用对象池   824
29.4  剖析   829
29.4.1  使用gprof的剖析示例   829
29.4.2  使用Visual C 2019的剖析示例   836
29.5  本章小结   838
29.6  练习   838

### 第30章  熟练掌握测试技术   841
30.1  质量控制   841
30.1.1  谁负责测试   842
30.1.2  bug的生命周期   842
30.1.3  bug跟踪工具   843
30.2  单元测试   844
30.2.1  单元测试方法   844
30.2.2  单元测试过程   845
30.2.3  实际中的单元测试   848
30.3  模糊测试   855
30.4  高级测试   855
30.4.1  集成测试   855
30.4.2  系统测试   856
30.4.3  回归测试   857
30.5  用于成功测试的建议   857
30.6  本章小结   858
30.7  练习   858

### 第31章  熟练掌握调试技术   859
31.1  调试的基本定律   859
31.2  bug分类学   860
31.3  避免bug   860
31.4  为bug做好规划   861
31.4.1  错误日志   861
31.4.2  调试跟踪   862
31.4.3  断言   869
31.4.4  崩溃转储   870
31.5  调试技术   870
31.5.1  重现bug   870
31.5.2  调试可重复的bug   871
31.5.3  调试不可重现的bug   871
31.5.4  调试退化   872
31.5.5  调试内存问题   872
31.5.6  调试多线程程序   876
31.5.7  调试示例：文章引用   876
31.5.8  从ArticleCitations示例中总结出的教训   887
31.6  本章小结   887
31.7  练习   887

### 第32章  使用设计技术和框架   889
32.1  容易忘记的语法   890
32.1.1  编写类   890
32.1.2  派生类   891
32.1.3  编写lambda表达式   892
32.1.4  使用“复制和交换”惯用语法   892
32.1.5  抛出和捕捉异常   893
32.1.6  写入文件   894
32.1.7  读取文件   894
32.1.8  写入类模板   895
32.1.9  约束模板参数   895
32.2  始终存在更好的方法   896
32.2.1  RAII   896
32.2.2  双分派   898
32.2.3  混入类   902
32.3  面向对象的框架   904
32.3.1  使用框架   904
32.3.2  MVC范型   905
32.4  本章小结   906
32.5  练习   906

### 第33章  应用设计模式   907
33.1  依赖注入   908
33.1.1  示例：日志机制   908
33.1.2  依赖注入logger的实现   908
33.1.3  使用依赖注入   909
33.2  抽象工厂模式   910
33.2.1  示例：模拟汽车工厂   910
33.2.2  实现抽象工厂   911
33.2.3  使用抽象工厂   912
33.3  工厂方法模式   913
33.3.1  示例：模拟第二个汽车工厂   913
33.3.2  实现工厂   914
33.3.3  使用工厂   915
33.3.4  工厂的其他类型   917
33.3.5  工厂的其他用法   917
33.4  适配器模式   918
33.4.1  示例：适配Logger类   918
33.4.2  实现适配器   919
33.4.3  使用适配器   920
33.5  代理模式   920
33.5.1  示例：隐藏网络连接问题   920
33.5.2  实现代理   921
33.5.3  使用代理   922
33.6  迭代器模式   922
33.7  观察者模式   923
33.7.1  示例：从主题中暴露事件   923
33.7.2  实现观察者   923
33.7.3  使用观察者   924
33.8  装饰器模式   925
33.8.1  示例：在网页中定义样式   926
33.8.2  装饰器的实现   926
33.8.3  使用装饰器   927
33.9  责任链模式   928
33.9.1  示例：事件处理   928
33.9.2  实现责任链   928
33.9.3  使用责任链   929
33.10  单例模式   930
33.10.1  日志记录机制   931
33.10.2  实现单例   931
33.10.3  使用单例   933
33.11  本章小结   933
33.12  练习   933

### 第34章  开发跨平台和跨语言的应用程序   935
34.1  跨平台开发   935
34.1.1  架构问题   935
34.1.2  实现问题   938
34.1.3  平台专用功能   940
34.2  跨语言开发   940
34.2.1  混用C和C   941
34.2.2  改变范型   941
34.2.3  链接C代码   944
34.2.4  从C#调用C 代码   946
34.2.5  C /CLI在C 中使用C#代码和在C#中使用C 代码   947
34.2.6  在Java中使用JNI调用C 代码   948
34.2.7  从C 代码调用脚本   950
34.2.8  从脚本调用C 代码   950
34.2.9  从C 调用汇编代码   952
34.3  本章小结   953
34.4  练习   953

## 第VI部分  附录
附录A  C 面试   957
在线资源(扫描封底二维码下载)
附录B  标准库头文件   977
附录C  UML简介   983
附录D  带注解的参考文献   989
