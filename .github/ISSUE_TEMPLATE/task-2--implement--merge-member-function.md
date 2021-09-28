---
name: 'Task 2: Implement `merge()` Member Function'
about: Task 2 for Students
title: 'Task 2: Implement `merge()` Member Function'
labels: enhancement
assignees: ''

---

**Description**

Implement the described member function to merge two given sorted lists back into the this `List` instance.  The two lists that are passed in as parameters should be passed in as `const` referenc eparameters.  This function is a `void` function because it doesn't return an explicit result.  Instead, the result of calling this function is that the two sublists are merged together and overwrite the original contents of this `List` instance.

You do not need to error check for now if the lists are indeed sorted or not before attempting the merge.  But if they are not sorted, the resulting merge will not end up being sorted correctly either.

**Suggested Solution**

The algorithm to do the merge is as follows

1. Start at the beginning index of both `lower` and `upper` lists.
2. Compare the current index of the two input arrays, 
   - copy whichever value is smaller to the destination.
   - increment the index of whichever array we just copied from
   - repeat 2 until we have exhausted all of the values in one of the input arrays
3. After the loop, one of the arrays `lower` or `upper` will still have
   values left in it. Copy all remaining values from the array to the
   destination.

**Additional Requirements**

- You are required to test if a merge is attempted that is too big for the
  existing `List` instance memory allocation.  We are not allocating new memory
  to hold the result of merging the two given input lists.  Instead, you are to
  reuse the existing allocated memory for the `values` array.  However, if the
  combined size of the two input lists is bigger than the current size of
  `values`, then you need to throw an exception indicating this.  The unit
  tests for this method are checking for this requirement.
