---
name: 'Task 1: Implement Sub List Copy Constructor'
about: Task 1 for Students
title: 'Task 1: Implement Sub List Copy Constructor'
labels: enhancement, good first issue
assignees: ''

---

**Description**

Implement a new copy constructor for the `List` class.  The class already contains a copy constructor that will create a whole copy of an existing list to make a new one. The sub list copy constructor takes a range of indexes `begin` and `end` that define a sublist of the values that are to be copied into the newly constructed list.



**Suggested Solution**

The existing copy constructor that copies the whole list is a good place to start.  You need only modify it to copy the values from the begin to the end index, instead of copying the whole list of values.  Of course before that, you need to calculate the correct size for the new list that is being created, and dynamically allocate only enough memory to hold this sublist size of values.

**Additional Requirements**

- You need to test for attempts to specify begin or end indexes that are illegal (beyond the bounds of the `values` array).  If an illegal access is attempted, you are required to throw and exception.  The unit tests for this method have tests that expect this behavior of your copy constructor.
- Be careful that you are handling empty sublists correctly.  Again this is tested in the test case for this constructor.  A request for an empty sublist should yield a new empty list (with no memory allocation).
