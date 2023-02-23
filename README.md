CPL (Command Planning Language), 命令规划语言

CPL旨在为用户提供统一的命令协作关系描述方法，以
控制无人系统完成用户任务。CPL目前基于flex和bison
开发，目前提供基本的数据类型int, float, char数组。

CPL程序主要包括三个部分：
(1) 任务属性
  用于定义任务的属性，以及变量声明。
(2) 组件列表
  说明任务用到了那些组件。
(3) OODA
  OODA部分又分为observation，orientation，decision，action
四个部分，各部分包括对应任务的指令。

变量声明
  变量只能在任务属性部分声明。目前支持的数据类型有int, float, char数组。变量
可在声明时赋值初值，或无初值。对于int和float变量，可在变量声明之后给其赋值，但
char数组只能在声明时赋值，后续不允许赋值操作。另外，对于int和float变量不支持
隐式类型转换，即不允许将浮点数赋值给整型变量，反之亦然。

项目目录文件
1、cpl.l为cpl的词法规则描述文件。
2、cpl.y为cpl的语法规则描述文件。
3、cpl_lexer.c, cpl_lexer.h为flex的输出，实现cpl的词法分析功能。
4、cpl_parser.c,cpl_parser.h为bison的输出文件，实现cpl的语法分析功能。
5、Makefile为项目的构建文件
6、test目录包含相关的测试文件

项目构建
项目使用flex和bison来实现词法和语法解析，所以需提前安装flex和bison。
编译项目可使用目录中提供的Makefile，在项目根目录下执行：
$make

或者单步编译，在项目根目录下执行：
$bison cpl.y -d
$flex cpl.l
$gcc cpl main.c cpl_lexer.c cpl_parser.c

测试
目前还为构建自动化的测试，可使用test目录下的测试用例进行测试，
测试成功会输出对应的cmd_info信息，证明程序中没有语法错误。
$./cpl test/test1.cpl 

-----The following are cmd_info data----
priority : 1

The following are symblelist data
symblelist_lenth : 14
Num.0 symbol in symblelist
ooda_symble name : x
ooda_symble ooda_reg_type 1
ooda_symble ooda_reg_value 1
ooda_symble initialised 1

Num.1 symbol in symblelist
ooda_symble name : y
ooda_symble ooda_reg_type 2
ooda_symble ooda_reg_value 1.9
ooda_symble initialised 1

Num.2 symbol in symblelist
ooda_symble name : aa
ooda_symble ooda_reg_type 0
ooda_symble ooda_reg_value -1
ooda_symble initialised -1

Num.3 symbol in symblelist
ooda_symble name : a
ooda_symble ooda_reg_type 1
ooda_symble ooda_reg_value -1
ooda_symble initialised -1

Num.4 symbol in symblelist
ooda_symble name : b
ooda_symble ooda_reg_type 2
ooda_symble ooda_reg_value -1
ooda_symble initialised -1

Num.5 symbol in symblelist
ooda_symble name : c
ooda_symble ooda_reg_type 2
ooda_symble ooda_reg_value -1
ooda_symble initialised -1

Num.6 symbol in symblelist
ooda_symble name : www
ooda_symble ooda_reg_type 1
ooda_symble ooda_reg_value -1
ooda_symble initialised -1

Num.7 symbol in symblelist
ooda_symble name : abc
ooda_symble ooda_reg_type 1
ooda_symble ooda_reg_value -1
ooda_symble initialised -1

Num.8 symbol in symblelist
ooda_symble name : j
ooda_symble ooda_reg_type 2
ooda_symble ooda_reg_value -1
ooda_symble initialised -1

Num.9 symbol in symblelist
ooda_symble name : k
ooda_symble ooda_reg_type 2
ooda_symble ooda_reg_value 8
ooda_symble initialised 1

Num.10 symbol in symblelist
ooda_symble name : m
ooda_symble ooda_reg_type 2
ooda_symble ooda_reg_value -1
ooda_symble initialised -1

Num.11 symbol in symblelist
ooda_symble name : l
ooda_symble ooda_reg_type 2
ooda_symble ooda_reg_value 1
ooda_symble initialised 1

Num.12 symbol in symblelist
ooda_symble name : req
ooda_symble ooda_reg_type 1
ooda_symble ooda_reg_value -1
ooda_symble initialised -1

Num.13 symbol in symblelist
ooda_symble name : res
ooda_symble ooda_reg_type 1
ooda_symble ooda_reg_value -1
ooda_symble initialised -1

The following are componment list data
needed_nodes_cmp_lenth : 1
name : "controller"

The following are this_OB_topics data
this_OB_topics_lenth : 3
sub_topic_name : "add_a"
target_reg : 
reg_name a
reg_type 1
reg_value -1
sub_topic_name : "add_b"
target_reg : 
reg_name b
reg_type 2
reg_value -1
sub_topic_name : "get_request"
target_reg : 
reg_name req
reg_type 1
reg_value -1

The following are this_AC_topics data
this_AC_topics_lenth : 2
pub_topic_name : "add_res"
source_reg : 
reg_name a
reg_type 1
reg_value -1
pub_topic_name : "add_res"
source_reg : 
reg_name a
reg_type 1
reg_value -1

The following are this_OR_cmd_list data
this_OR_cmd_list_lenth : 1
 OP : 0
rs1 reg_name a
rs1 reg_type 1
rs1 reg_value -1
rs2 reg_name b
rs2 reg_type 2
rs2 reg_value -1
rd reg_name res
rd reg_type 1
rd reg_value -1

The following are this_DE_cmd_list data 
this_DE_cmd_list_lenth : 1
 OP : 4
rs1 reg_name req
rs1 reg_type 1
rs1 reg_value -1
rs2 reg_name x
rs2 reg_type 1
rs2 reg_value 1
------End of cmd_info data----




