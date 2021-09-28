---
name: 'Task 4: Implement `search()` Member Function'
about: Task 4 for Students
title: 'Task 4: Implement `search()` Member Function'
labels: enhancement
assignees: ''

---

**Description**

The fourth task is to implement the binary `search()` member method as described. You will implement this using a recursive version of binary search.  This method for task 4 takes the `string` item to search for, and a `begin` and `end` index of the unsearched portion of the list.  A normal external user would usually call the search with `begin = 0` and `end = size - 1` to search the whole list.  But the recursive binary search algorithm uses these indexes on subsequent recursive calls to keep track of the unsearched portion of the list.

**Suggested Solution**

The recursive algorithm for the binary search is as follows.  The base case is, if `end` is less than or equal to `begin`, then there is 1 or less items left in the list to search.  In that case you should test the item in the `begin` index and if the item is what we were looking for, you return the `begin` index where it was found.  But if the item is not what was being looked for, then you return `NOT_FOUND` to indicate a failed search.

The recursive general case is another example of a divide-and-conquer approach. The algorithm is as follows:

1. calculate the middle index of the remaining portion of the list, e.g.
   $\frac{begin + end}{2}$
2. test the value at the middle index.  If it is what we are searching for, return
   the middle index to indicate success.
3. otherwise the value must either be in the portion of the list before the middle or
   after the middle.
   - if the value we are searching for is less than the value in the middle index,
     recursively call the search again on the list from begin to middle - 1.
   - else the value should be greater than the value in the middle index, so recursively
     search from middle + 1 to end.

**Additional Requirements**

- You are required to implement a recursive version of the binary search.  This
  algorithm can be implemented iteratively with a loop, but you must use
  recursion in this implementation.

