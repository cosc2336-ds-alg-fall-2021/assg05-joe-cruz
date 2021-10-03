/** @file List.cpp
 * @brief Implementations of member functions of the List
 *   of strings class for the Assignment Sorting and Searching
 *
 * @author Jane Programmer
 * @note   cwid : 123 45 678
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Sorting and Searching
 * @date   June 1, 2021
 *
 * Implementations of a List of strings ADT.  Sort of a preview
 * of some of the data structures and abstract data types we
 * will be learning to build and understand.
 */
#include "List.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/** @brief Default constructor
 *
 * Construct an empty list.  Probably not useful for this
 * assignment, but it is often required to have a default
 * constructor for various reasons by the C++ language.
 *
 * @param size We use a default parameter size of 0, so if not specified
 *   this function works as default constructor with no parameter.
 *   But if size is specified, create a list of all empty values of the indicated
 *   size.
 */
List::List(int size)
{
  // we will allow a size 0 list to be defined and used by this data type
  this->size = size;
  values = nullptr;

  // initialize with empty values if size is > 0
  if (size > 0)
  {
    this->values = new string[size];

    for (int index = 0; index < size; index++)
    {
      this->values[index] = "";
    }
  }
}

/** @brief Standard constructor
 *
 * Construct a list of integer values from a (statically) defined and
 * provided array of integers.  We simply allocate a block of memory
 * dynamically large enough to hold the values, then copy the values
 * from the input parameter into our own private array of values.
 *
 * @param size The size of the input values were are given as well as the
 *   size of the new list we are to construct.
 * @param values The (static) array of string values to use to construct
 *   this List values with.
 */
List::List(int size, string values[])
{
  // dynamically allocate a block of memory on the heap large enough to copy
  // the given input values into
  this->size = size;
  this->values = new string[size];

  // copy the values from the input paramter into our new shiny block of memory
  for (int index = 0; index < size; index++)
  {
    this->values[index] = values[index];
  }
}

/** @brief Copy constructor
 *
 * Provide a copy constructor for the List class.  A copy constructor
 * will be invoked whenver you assign one instance of a List to another.
 * For example
 *   List newList = existingList;
 * Where of course existingList was a previously created List.  This copy
 * constructor, as the name suggests, should make a copy of the values from
 * the given input list into a new List instance.
 *
 * @param list The other List type we are to make a copy of in this
 *   constructor.
 */
List::List(const List& list)
{
  // copy the size of the existing list and allocate memory to hold
  // values we will copy
  size = list.size;
  values = new string[size];

  // copy the values from the input List into this list
  for (int i = 0; i < size; i++)
  {

    values[i] = list.values[i];
  }
}
/** @brief Sublist Copy constructor
 *
 * Provide a sublist copy constructor for the List class.  A copy constructor
 * copies and indicates sub portion of the original list to be the new list we are creating.
 *
 * @param list The other List type we are to make a copy of in this
 *   constructor.
 * @param begin The begin index of the sublist to make a copy of for this
 * new list
 * @param end The begin index of the sublist to make a copy of for this
 * new list
 */
List::List(const List& list, int begin, int end)
{
    if ((begin < 0) || (begin >= list.size) || (end<0) || (end>=list.size))
  {
    ostringstream out;
    out << "Error: illegal bounds access";

    throw ListMemoryBoundsException(out.str());
  }

  int temp;
  temp = 0;
  size = 0;
  for (int i = begin; i<=end; i++)
  {
    size++;
  }
  values = new string[size];

  for (int i = begin; i <= end; i++)
  {
    values[temp] = list.values[i];
    temp++;
  }

}

/** @brief Class destructor
 *
 * Destructor for the List class.  A List may (or may not) have
 * a dynamically allocated block of memory associated with it.
 * Free up this block on destruction of a List instance.
 */
List::~List()
{
  // if values is not null, it points to a dynamic block of memory, so
  // delete that block.
  if (values != nullptr)
  {
    delete[] values;
  }
}

/** @brief Size accessor
 *
 * Accessor method to get the current size of this List of integers.
 *
 * @returns int Returns the current size of the list of integers.
 */
int List::getSize() const
{
  return size;
}

/** @brief List to string
 *
 * Accessor method to construct and return a string representation
 * of the current values and status of this List instance.
 *
 * @returns string Returns the string constructed with the information
 *   about this List.
 */
string List::str() const
{
  ostringstream out;

  // stream list information into the output stream
  out << "<list> size: " << size << " [ ";

  // stream the current value sof the list to the output stream
  for (int index = 0; index < size; index++)
  {
    out << values[index];

    // separate the values of the list, last one does not need , separator
    if (index == size - 1)
    {
      out << " ";
    }
    else
    {
      out << ", ";
    }
  }
  out << "]";

  // convert the string stream into a concrete string to return
  return out.str();
}

/** @brief Indexing operator
 *
 * Provide a way to index individual values in our private
 * internal array of integers.  This allows code to, for the
 * most part, treated an instance of our List as if it were
 * an array, though we also provide bounds checking to ensure
 * no illegal access beyond the list bounds is attempted.
 *
 * @param index The index of the value it is desired to access from
 *   this List.
 *
 * @returns int& Returns a reference to the requested List item at
 *   the requested index.
 *
 * @throws ListMemoryBoundsException if a request for an index beyond
 *   the end of the array (or less than 0) is made.
 */
string& List::operator[](int index)
{
  // first check that the requsted index is legally
  // within the bounds of the current size of our list
  if ((index < 0) or (index >= size))
  {
    ostringstream out;
    out << "Error: illegal bounds access, list size: " << size << " tried to access index address: " << index;

    throw ListMemoryBoundsException(out.str());
  }

  // otherwise it is safe to return the reference to this value
  return values[index];
}

/** @brief Boolean equals operator
 * Check if this List is equal to the right hand side (rhs)
 * list.  The lists are equal if their sizes are equal, and if
 * all elements in both lists are equal.
 *
 * @param rhs The other list on the right hand side of the
 *   boolean comparison that we are comparing this List to.
 *
 * @returns bool true if the lists are equal, false if the are not.
 */
bool List::operator==(const List& rhs) const
{
  // first the lists have to be of the same size, or else they
  // cannot be equal
  if (size != rhs.size)
  {
    return false;
  }

  // otherwise, lists are equal if all elements are equal.
  // compare each element, and if we find a pair that is no
  // equal then the answer is false
  for (int index = 0; index < size; index++)
  {
    if (values[index] != rhs.values[index])
    {
      return false;
    }
  }

  // if we get to this point, all values were the same in both
  // lists, so the answer is true, the lists are equal
  return true;
}

/** @brief List output operator
 *
 * Overload the output stream operator so that we can display current
 * values of a List on standard output.
 *
 * @param out The output stream we should send the representation
 *   of the current List to.
 * @param rhs The List object to create and return a string
 *   representation of on the output stream.
 *
 * @returns ostream& Returns a reference to the originaly provided
 *   output stream, but after we  have inserted current List
 *   values / representation onto the stream
 */
ostream& operator<<(ostream& out, const List& rhs)
{
  // reuse List str() method to stream to output stream
  out << rhs.str();

  // return the modified output stream as our result
  return out;
}

/** @brief merge two sorted list into this list
 * 
 * Given two sorted smaller list, merge them into the values of this list.
 * We assum that the two input list are already sorted for this merge
 * to work. And we assume that this list has enough room for the merge.
 * If this list is not big enough, we simply throw an exception saying
 * we can't perform the merge.
 * 
 * @param lower A constant reference to a list. One of the two list we 
 * are merging into this list.
 * 
 * @param upper A constant reference to a list. One of the two list we 
 * are merging into this list.
 * 
 * @throws ListMemoryBoundsException if this list is not big enough
 * to hold all of the mergerd values
 * 
*/
void List::merge(const List& lower, const List& upper)
{
  int iU = 0;
  int iL = 0;
  int i = 0;
  int mergeSize = lower.getSize() + upper.getSize();
  if (size < mergeSize)
  {
    ostringstream msg;
    msg << "Error: lower size: " << lower.getSize() << endl
    << " upper size: " << upper.getSize() << endl
    << " this object not big enough to hold result size" << endl;

    throw ListMemoryBoundsException(msg.str());
  }  
  while (iL < lower.getSize() and iU < upper.getSize())
  {
  if (upper.values[iU] < lower.values[iL])
    {
      values[i] = upper.values[iU];
      iU++;
    }
  else
    {
      values[i] = lower.values[iL];
      iL++;
    }
      i++;
  }
  do
  {
    if (iL < lower.getSize())
    {
      values[i] = lower.values[iL];
      iL++;
    }
    if (iU < upper.getSize())
    {
      values[i] = upper.values[iU];
      iU++;
    }
    i++;
  } while( i < size);
}
/** @brief Splits two list and sorts them.
 * 
 * Split the current list into two sublists of as equal as possible number of values.
 * The sort() method will take no input parameters, and it is a void function.
 * It wil split two sublist, sort them out by calling itself, and merge them.
 * 
 * 
*/
void List::sort()
{
  if (size <= 1)
  {
    return;
  }
  int split = size / 2;
  List lower = List(*this, 0, split-1);
  List upper = List(*this, split, size-1);
  lower.sort(); 
  upper.sort();
  merge(lower, upper);
}



/** @brief Memory bounds exception constructor
 *
 * Constructor for exceptions used for our List class.
 *
 * @param message The exception message thrown when an error occurs.
 */
ListMemoryBoundsException::ListMemoryBoundsException(const string& message)
{
  this->message = message;
}

/** @brief Memory bounds exception destructor
 *
 * Destructor for exceptions used for our ListMemoryBoundsException
 * class.
 */
ListMemoryBoundsException::~ListMemoryBoundsException() {}

/** @brief Memory bounds exception message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* ListMemoryBoundsException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}

/** @brief A binary search method
 *
 * A recursive binary search.The base case is, if end is less than or 
 * equal to begin, then there is 1 or less items left in the list to search. 
 * In that case you should test the item in the begin index and if the item 
 * is what we were looking for, you return the begin index where it was found. 
 * But if the item is not what was being looked for, then you return NOT_FOUND
 * to indicate a failed search.
 * 
 * @param sear A constant reference to a string to be searched.
 * 
 * @param begin The begining of an index that is being searched.
 * 
 * @param end The ending of an index that is being searched.
 * 
 * @returns What is being searched within the string
 */
int List::search (const string sear,int begin, int end)
{
  if (size < 1)
  {
    return NOT_FOUND;
  }

  if(begin < end)
  {
    int total = (begin+end);
    int middle = total/2;
    if (values[middle]== sear)
    {
      return middle;
    }
    if (values[middle] > sear)
    {
      return search(sear, begin, middle-1);
    }
    else
    {
      return search(sear, middle+1, end);
    }
  }
  if (operator[](begin)==sear)
  {
    return begin;
  }
  else
  {
    return NOT_FOUND;
  }
}
/**
 * @brief Checks to see if a list is sorted or not.
 * 
 * isSorted() member function which will return true if 
 * the List is currently sorted, and false if it is not. 
 * This function should calculate its result dynamically, 
 * it should not rely on adding or setting a new member 
 * variable that is set to try after sort() is called, but 
 * instead checks pairs of items of the List to see if any 
 * are out of order, and thus the list is not sorted.
 * 
 * @returns true if a list is sorted.
 **/
bool List::isSorted() const
{
  for (int i=0; i < size-1; i++)
  {
    if (values[i] > values[i+1])
    {
      return false;
    }
  }
  return true;
}

/**
 * @brief Checks to see if a list is sorted or not.
 * 
 * This method takes a string to search for in
 *  the list, and it returns the index where the value
 *  is found in the list. This method checks if the list is 
 * sorted using the isSorted() method, and if not, it calls sort() 
 *  to make sure the list becomes sorted before doing the
 *  search.
 * 
 * @returns the index where the value is found in the list.
 **/
int List::search(const string sear)
{
  if (isSorted()== false)
  {
    sort();
  }
  return search(sear, 0 , size-1);
}


