//
//   COPYRIGHT (C) vincent@zips.uakron.edu, 2020  All rights reserved.
//   student name
//   Purpose: This is myCode and is based upon what we study for Comp Sci
//
// eliminate or add to this list
#include <cassert>
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <limits>  // numeric_limits<std::streamsize> for validations
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <initializer_list>

// our memory management implementations
#include "myMemory.hpp"

// our class implementations
#include "myString.hpp"
#include "myStringVector.hpp"

#define DEEP_DEBUGGING_DRIVER (0)

template<typename I1, typename I2>
inline bool
my_equal(I1 first1, I1 limit1, I2 first2, I2 limit2)
{
  
  while (first1 != limit1 && first2 != limit2) {
    
    #if DEEP_DEBUGGING_DRIVER
      std::cout << *first1 << std::endl;
      std::cout << *first2 << std::endl;
    #endif

    if (*(first1->data()) != *(first2->data()))
    {
      std::cout << "Got here" << std::endl;
      return false;
    }
    ++first1;
    ++first2;
  }
  return first1 == limit1 && first2 == limit2;
}



// Encapsulate all of the myString vector tests.
struct Test_myStringVector
{
  void default_ctor()
  {
    myStringVector v;
    assert(v.empty());
    std::cout << "Passed default ctor" << std::endl;
  }
  // we need copy_ctor AND list initialize
  void copy_ctor()
  {
    myStringVector v1 {"a", "b", "c"};
    myStringVector v2 = v1; // WE DON'T HAVE AN EXPLICITLY DEFINED COPY CTOR 
    
    assert(v1 == v2);
    
    
    std::cout << "Passed copy ctor" << std::endl;
  }
  
  
  void copy_assign()
  {
    myStringVector v1 {"a", "b", "c"};
    myStringVector v2;
    v2 = v1;
    assert(v1 == v2);
    std::cout << "Passed copy assign" << std::endl;
  }

  
  void self_assign()
  {
    myStringVector v {"a", "b", "c"};
    v = v;
    std::cout << "Passed self assign" << std::endl;
  }
  
  void empty()
  {
    myStringVector const v1;
    myStringVector const v2 {"a"};
    assert(v1.empty());
    assert(!v2.empty());
    std::cout << "Passed both empty cases" << std::endl;
  }
  
  void size()
  {
    myStringVector const v1;
    myStringVector const v2 {"a"};
    assert(v1.size() == 0);
    assert(v2.size() == 1);
    std::cout << "Passed both size cases" << std::endl;
  }

  
  void reserve()
  {
    myStringVector v;
    myStringVector const& cv = v;
    assert(cv.capacity() == 0);
    v.reserve(20);
    assert(cv.capacity() >= 20);
    v.reserve(5);
    assert(cv.capacity() >= 20);
    std::cout << "Passed capacity" << std::endl;
  }
  
  
  void resize()
  {
    myStringVector v1 {"", "", ""};
    myStringVector v2;
    
    v2.resize(3);
    assert(v1.size() == 3);
    // assert(v1 == v2); // TODO: redesign test case for this portion 
    std::cout << "Passed resize" << std::endl;
  }

  
  void clear()
  {
    myStringVector v {"a", "b", "c"};
    v.clear();
    assert(v.empty());
    assert(v.capacity() != 0);
    std::cout << "Passed clear case" << std::endl;
  }
  
  void push_back()
  {
    myStringVector v;
    v.push_back("a"); 
    assert(v.size() == 1);

    // assert(v[0] == "a"); // TODO: take a look at this lol

    std::cout << "Passed push_back" << std::endl;
  }
  
  void pop_back()
  {
    myStringVector v1 {"a", "b", "c"};
    v1.pop_back();
    assert(v1.size() == 2);
    std::cout << "Passed pop_back" << std::endl;
  }
  
  void access()
  {
    myStringVector v {"a", "b", "c"};
    myStringVector const& cv = v;

    assert(v[0] == "a");
    assert(cv[0] == "a");

    v[0] = "q";
    assert(v[0] == "q");
    std::cout << "Passed access case" << std::endl;
  }

  
  void iterators()
  {
    myStringVector v {"a", "b", "c"};
    myStringVector const& cv = v;
    using I = myStringVector::iterator;
    using C = myStringVector::const_iterator;
    I first1 = v.begin(), limit1 = v.end();
    C first2 = cv.begin(), limit2 = cv.end();
    assert(my_equal(first1, limit1, first2, limit2));
    std::cout << "Passed iterators" << std::endl;
  }
  
  
  void ordering()
  {
    myStringVector const v1 {"a", "b", "c"};
    myStringVector const v2 {"d", "e", "f"};

    assert(v1 < v2);
    assert(v2 > v1);
    assert(v1 <= v1);
    assert(v2 >= v1);
    std::cout << "Passed ordering" << std::endl;
  }

  /*
  void moving()
  {
    myStringVector v1 {"a", "b", "c", "d"};
    myStringVector v2 = std::move(v1);
    myStringVector v3;
    assert(v1 == v2);
    v3 = std::move(v1);
    assert(v1 == v3);
    std::cout << "Passed moving" << std::endl;
  }
  void reitering()
  {
    myStringVector v1 {"q", "u", "i", "t"};
    myStringVector::iterator i = v1;
    assert(*i == "q");
    myStringVector::iterator j = v1.insert(i, "a");
    assert(v1.size() == 5);
    myStringVector::iterator j = v1.erase(i, "a");
    assert(v1.size() == 4);
    std::cout << "Passed reitering" << std::endl;
  }

  */
  // The test runner for this test class.
  void run()
  {
    default_ctor();
    copy_ctor();
    copy_assign();
    self_assign();
    empty();
    size();
    reserve();
    resize();
    clear();
    push_back();
    pop_back();
    access();
    iterators();
    ordering();
    // moving();
    // reitering();
  }
};


int main()
{
  Test_myStringVector test;
  test.run();
  return 0;
}
