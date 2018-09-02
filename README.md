# STL与泛函编程
## STL体系结构基础介绍
STL六大部件
容器（containers）, 分配器(allocators), 算法, 迭代器, 适配器, 仿函式
## 容器之分类与各种测试
## vector
## array
## list
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

