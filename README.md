# STL与泛函编程
## STL体系结构基础介绍
STL六大部件
容器（containers）, 分配器(allocators), 算法, 迭代器, 适配器, 仿函式
## 容器之分类与各种测试
## vector
## array
## list 
双向列表
## forward-list
## slist
## deque
deque<string> c;
左右扩充，分段连续, 双向进出 push_front,push_back, pop_front, pop_back
排序用全局的sort, ::sort(c.begin(), c.end());
deque 涵盖了 stack 和 queue.

## stack
c.push(), c.pop(), 先进后出

## queue
c.push(), c.pop() 先进先出

## multiset 
小型的关联数据库, 红黑树
insert 
c.find() 比 ::find() 快很多

## multimap
key, value
multimap<long, string> c; 
c.insert(pair<long, string>(i, buf));

## unordered_multiset
篮子一定比元素多
散列表
## unordered_multimap

## set
0 ~32768个元素 没有重复
## map
放进去的没有重复 1000000个元素
## unordered_set
## unordered_map

## 使用容器 hash_set hash_map hash_multiset hash_multimap (hash == unordered) 

## 使用分配器 allocator
std::allocator

# 源码之前了无秘密

## OOP(Object-Oriented programming) vs. GP (Generic Programming)
OOP企图将datas 和methods 关联在一起， GP 是将datas 和methods 分散开
::sort(c.begin(),c.end());
采用GP：
容器和算法可以各自闭门造车，其间以Iterator 连通即可
## Operator Overloading 操作符重载

## CLass Templates, 类模板
### Specialization， 特化
### Partial Specialization 偏特化
个数偏特化，范围偏特化
## FUnctionTemplates, 函数模板
## Member Templates, 成员模板

# 分配器 allocators
先谈 operator new() 和 malloc()
