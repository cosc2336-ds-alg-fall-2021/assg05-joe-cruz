---
name: 'Task 3: Implement `sort()` Member Function'
about: Task 3 for Students
title: 'Task 3: Implement `sort()` Member Function'
labels: enhancement
assignees: ''

---

**Description**

Implement the described member function to sort the `List` of values.  This function is a `void` function and it takes no parameters as input.  Its sole purpose is to sort all of the current `values` of the list into ascending order.

**Suggested Solution**

The merge sort algorithm is a recursive algorithm.  Your base case is that, if you are asked to sort a list of size 1 or an empty list of size 0 then the list is already trivially sorted, so simply return and do nothing.

But if the list has 2 or more items you need to

1. Split this instance into 2 equally sized lists, the lower and upper copies of
   the halves of this list.
2. Call `sort()` recursively on both of these new copied sublists.
3. Call `merge()` on this instance with the returned, now sorted, `lower` and `upper`
   list copies.
   
**Additional Requirements**

- You are required to reuse your sub list copy constructor when splitting the
  list into two halves for the recursive sorts and merge.
- You are required, of course, to reuse your `merge()` function to perform the
  merge of the now sorted half sublists.
- You are required to implement this sort using a recursive merge sort.


