# BTree-vs-HashTable-Comparison

This repository stores my project of comparing two data structures: B-Tree and Hash-Table.
We are inserting, displaying and searching in these two data structures.

In this project, I am revealing the following in a way that is understandable for most of the people:

Hash Table:
1. Hash Table are faster for insertion and searching data.
2. But to store large data in Hash Table we need more memory, so Hash Table are not good if we have limited memory resources
3. Hash Table only works good as long as we know the size of hash table in advance. Because increasing size will cause rehashing the complete table, which is too expensive in terms of performance.

B-Tree:
1. B-Tree are slower than hash table in single search case, but in range search b-tree are a lot faster.
2. B-Tree does not need to take extra memory as hash table, as it will only take memory as much as it need.
3. B-Tree can provide us the sorted values just by a pre-order/post-order traversal, which gives an extra credit to b-tree

Summary:
1. Hash Table should be use where out data is limited and we know the size of data in advance.
2. B-Tree should be use where our memory resources are limited and we have to search data in ranges at large scale.
