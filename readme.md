## KoppJson2.0 -- Json解析库的实践

> **Author** wq
>
> **Data** 23.12.10

---

> 以C++作为主要开发语言，Linux为主要开发平台，CMake + G++作为开发工具开发的一整套Json解析库内容。
>
> 本库包括Json的解析、获取、删除、修改等功能，并在速度上有一定优化。
>
> 本库对比python采用的Json解析库（以C库为基础），在解析速度上有40%的提升。

## 目录结构

目录

> KoppJson 2.0
> ├─include
> │  ├─KoppJson.h      和json处理相关的定义
> │  └─KoppTemplate    函数模板实现
> ├─src
> │  ├─Json.cpp   Json类的静态方法，涉及打开和保存。
> │  ├─KoppBuild.cpp   从字符串构建json相关
> │  ├─KoppJsonPtr.cpp 指向处理位置的指针（基本已弃用）
> │  ├─KoppTools.cpp   json处理工具的实现
> │  └─KoppValue.cpp   json数值操作相关(增删改查)
> ├─test      过去的测试文件
> ├─build     cmake文件
> ├─Test.cpp  测试文件
> ├─readme.md
> └─CMakeLists.txt

## 部分用法

> ```C++
> //从文件中读取Json文件
> KoppValue* val = (Kopp::Json::ReadJsonFile("../json/china.json"));
>
> // 从目标位置取值
> Kopp::KoppValue* ret;
> int error_code = val->get(ret , 1 , "key" , "key" , 1);
>
> // 新建、修改并保存
> Kopp::KoppObject obj = new Kopp::KoppObject();
> obj.push_back( Kopp::KoppPair(Kopp::KoppValue ("key") , *ret) );
> Kopp::KoppValue myval(obj);
> Kopp::Json::SaveJsonFile(myval , "../json/china2.json")
> ```

## 鸣谢

从零开始的 JSON 库教程(C语言) https://github.com/miloyip/json-tutorial

本库的解析部分借鉴于此。
