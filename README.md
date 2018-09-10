# STL与泛函编程
## STL体系结构基础介绍
### STL六大部件
容器（containers）, 分配器(allocators), 算法(ALgorithm), 迭代器(Iteration)(泛化的指针), 适配器(Adapters), 仿函式(Functors).
### 复杂度，Complexity， Big-oh, N 要很大，工业级的（大于10W）
### "前闭后开“ 区间，c.begin(), c.end().
begin 指向第一个元素，end 只想最后一个元素的下一个位置（涵盖第一个，不含最后一个元素）。
```
Container<T> c:
...
Container<T>::iterator ite = c.begin();
for (i; ite != c.end(); ++ite)
...
```
### range-based for statement (since C++11)
```
for (decl : coll) {
  statement
 }
```
example
```
for (int i : {2,3,45,7,9,11,13,17,19}{
  std::cout << i << std::endl;
 }
```
```
std::vector<double> vec;
...
for(auto elem : vec){
  std::cout <<< elem << std::endl;
}
for(auto elem : vec){
  elem *= 3;
}
```
### auto keyword (since C++11)
```
list<string> c;
...
auto ite = :: find(c.begin(), c.end(),tanger);
```

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

## Iterator 需要遵循的原则
rotate() 需要知道iterators 的三种 associated types
1. iteractor_traits<_Iter>::iteractor_category() ; 分类
2. iterator_traits<_rRandomAccessIterator>::difference_type_Distance; 距离
3. iterator_traits<_rRandomAccessIterator>::value_type_ValueType; 什么值
4. reference
5. pointer
4 和 5 从来没有被使用过
iterators 必须提供的五种 associated types
__list_iterator
iterator_category; value_type; pointer; reference; difference_typr; 
algorithm 
I::iterator_category; I::value_type; I::pointer; I::reference; I::difference_typr;
value_type主要目的是来声明变量

## vector

## array
## forward_list
## deque<T>::insert()
允许指定一个位置，在这个位置上放新的元素进去。
  
  
## 关联式容器
容器 rb_tree(Red-Black tree, 红黑树)
