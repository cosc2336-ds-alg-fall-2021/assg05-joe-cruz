---
name: 'Task 5: Implement `isSorted()` Member Function for Search API Improvements'
about: Task 5 for Students
title: 'Task 5: Implement `isSorted()` Member Function for Search API Improvements'
labels: enhancement
assignees: ''

---

**Description**

Task 5 is to implement an `isSorted()` member function which will return `true` if the `List` is currently sorted, and `false` if it is not.  This  function should calculate its result dynamically, it should not rely on adding or setting a new member variable that is set to try after `sort()` is called, but instead checks pairs of items of the `List` to see if any are out of order, and thus the list is not sorted.

We are really implementing the `isSorted()` method so we can improve the API for our `search()` method somewhat.  Once `isSorted()` is working, create a second (overloaded) version of the `search()` member method.  This method will only take the `string` value to be searched for.  This method will first check whether the list is sorted or not using your `isSorted()` function you just wrote.  If the list is not sorted, it should first call `sort()` on itself to sort the list, before calling the other `search()` that implements the actual binary search.  You should of course perform a binary search on the whole list of values.

**Suggested Solution**

To determine if a list is sorted or not, you can start by looking at the first two values in index 0 and 1.  If they are out of order (e.g. value in 0 is greater than the value in 1), then we can return `false` immediately, the list is not sorted.  If they are in the correct order, we can test indexes 1 and 2 to see if they are in order, etc. and iterate through all adjacent pairs of values to see if we find any out of order.  If we test all pairs and don't find any out of order then the list is sorted.

**Additional Requirements**

- Be careful that you do not go past the end of your `values` array
  bounds when testing adjacent pairs of items to see if in order
  or not.  It is easy to access a value 1 beyond the end of the
  `values` array if you are not careful with your indexing.
  

