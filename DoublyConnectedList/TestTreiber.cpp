////////////////////////////////////////////////////////////////////////////////////
//    Workfile: TestTreiber.cpp
//      Author: mb, FH-Hagenberg / HSD / SEN1
//        Date: 02.12.25 11:35
//    Revision: 42
// Description: Testdriver for Exercise 9, SEN1, HSD
//              Use this testdriver to verify your implementation of
//              modul 'DoublyConnectedList'.
////////////////////////////////////////////////////////////////////////////////////


// System and Project Header Files
// -------------------------------
   #if !defined _DEBUG
      #error COMPILER-EINSTELLUNGEN: Bitte mit Debug-Information �bersetzen!
   #endif

   #include <iostream>
   #include <stdarg.h>
   #include <string>
   #include <exception>

   #include "DoublyConnectedList.h"    // this is the header file of *your* modul


// Local Function Prototypes
// -------------------------
   static void    clear_dump          (TList & list, bool reverse);
   static bool    contains            (TList & list, std::size_t size, int reference []);
   static void    count_dump          (TList & list, std::size_t size, int reference []);
   static void    dump                (TList & list, bool reverse);
   static void    erase_all_dump      (TList & list, int data, bool reverse);
   static void    erase_dump          (TList & list, int data, bool reverse);
   static void    erase_lower_dump    (TList & list, int data, bool reverse);
   static void    init_dump           (TList & list, bool reverse);
   static void    insert_after_dump   (TList & list, int data, TNode * pNode, bool reverse);
   static void    insert_before_dump  (TList & list, int data, TNode * pNode, bool reverse);
   static TNode * insert_sorted_dump  (TList & list, int data, bool reverse);
   static int *   make_reference      (std::size_t size, ...);
   static void    push_back_dump      (TList & list, int data, bool reverse);
   static void    push_back_sort_dump (TList & list, int data, bool reverse);
   static void    push_front_dump     (TList & list, int data, bool reverse);
   static void    rotate_left_dump    (TList & list, bool reverse);
   static void    rotate_right_dump   (TList & list, bool reverse);
   static void    sort_dump           (TList & list, bool reverse);
   static void    test_case_01        ();
   static void    test_case_02        ();
   static void    test_case_03        ();
   static void    test_case_04        ();
   static void    test_case_05        ();
   static void    test_case_06        ();
   static void    test_case_07        ();
   static void    test_case_08        ();
   static void    test_case_09        ();
   static void    test_case_10        ();
   static void    test_case_11        ();
   static void    test_case_12        ();
   static void    test_case_13        ();
   static void    test_case_14        ();
   static void    test_case_15        ();
   static void    test_case_16        ();
   static void    test_case_17        ();
   static void    test_case_dump      (int test);


// Global Variables
// ----------------
   static char const * gpLocation = "unknown";


// Exception Class
// ---------------
class DclException: public std::exception {
public:
    DclException(std::string const & location, int lineNr):mLocation(location), mLineNr(lineNr) {}

    ~DclException() throw() {}

    int GetLineNr() const {
        return mLineNr;
    }

    std::string const & GetLocation() const {
        return mLocation;
    }

    virtual const char* what() const throw() {
        return "Doubly Connected List Exception";
    }
private:
    std::string mLocation;
    int         mLineNr;
};


// Generic Algorithms
// ------------------

template <typename T> inline void assert (T const & expression) {
   if (!expression) {
      throw gpLocation;
   }
}


template <typename T> inline void assert (T const & expression, int lineNr) {
   if (!expression) {
      throw DclException(gpLocation, lineNr);
   }
}

template <typename T> inline std::size_t Length (T const & v) {
   return sizeof (v) / sizeof (*v);
}



// Global Function Definitions
// ---------------------------

int main () {
   try {
      test_case_01 ();
      test_case_02 ();
      test_case_03 ();
      test_case_04 ();
      test_case_05 ();
      test_case_06 ();
      test_case_07 ();
      test_case_08 ();
      test_case_09 ();
      test_case_10 ();
      test_case_11 ();
      test_case_12 ();
      test_case_13 ();
      test_case_14 ();
      test_case_15 ();
      test_case_16 ();
      test_case_17 ();
   }
   catch (char const * pError) {
      std::cout << std::endl
                << "*** ERROR occurred in " << pError << "!" << std::endl
                << std::endl;
   }
   catch (DclException & e) {
       std::cout << std::endl
                 << "### Error occurred in " << e.GetLocation()
                 << ". Assertion failed on line " << e.GetLineNr() << "."
                 << std::endl;
   }
   catch (std::bad_alloc & e) {
       std::cout << std::endl
                 << e.what() << ": out-of-memory exception occurred. This should not happen."
                 << std::endl;
   }

   return 0;
}


// Local Helper Function Definitions
// ---------------------------------

void clear_dump (TList & list, bool reverse) {
   clear (list); assert (consistent (list), __LINE__); dump (list, reverse);
}


bool contains (TList & list, std::size_t Size, int reference []) {
   if (list.size != Size) return false;

   std::size_t i     = 0;
   TNode *     pNode = list.pHead;

   while (pNode != nullptr) {
      if (pNode->data != reference[i]) return false;

      i    += 1;
      pNode = pNode->pNext;
   }

   return true;
}


void count_dump (TList & list, std::size_t Size, int reference []) {
   bool comma = false;

   for (std::size_t i = 0; i < Size; i += 2) {
      int         v = reference[i];
      int         c = reference[i + 1];
      std::size_t a = count (list, v);

      assert (c == static_cast <int> (a), __LINE__);

      if (comma) {
         std::cout << ", ";
      }

      std::cout << static_cast <int> (v) << ": " << static_cast <int> (a); comma = true;
   }

   std::cout << std::endl;
}


void dump (TList & list, bool reverse) {
   int  n = static_cast <int> (size (list)); assert (consistent (list), __LINE__);
   bool s = sorted (list);                   assert (consistent (list), __LINE__);

   print (list, reverse); assert (consistent (list), __LINE__);

   std::cout << ", " << n << " node" << (n == 1 ? "" : "s")
             << ", " << (s ? "" : "not ") << "sorted"
             << std::endl;
}


void erase_dump (TList & list, int data, bool reverse) {
   erase (list, data); assert (consistent (list), __LINE__); dump (list, reverse);
}


void erase_all_dump (TList & list, int data, bool reverse) {
   erase_all (list, data); assert (consistent (list), __LINE__); dump (list, reverse);
}


void erase_lower_dump (TList & list, int limit, bool reverse) {
    erase_lower (list, limit); assert (consistent (list), __LINE__); dump (list, reverse);
}


void init_dump (TList & list, bool reverse) {
   init (list); assert (consistent (list), __LINE__); dump (list, reverse);
}


void insert_after_dump (TList & list, int data, TNode * pNode, bool reverse) {
   assert (pNode != nullptr, __LINE__);
   assert (valid_node (list, pNode), __LINE__);

   insert_after (list, data, pNode); assert (consistent (list), __LINE__); dump (list, reverse);
}


void insert_before_dump (TList & list, int data, TNode * pNode, bool reverse) {
   assert (pNode != nullptr, __LINE__);
   assert (valid_node (list, pNode), __LINE__);

   insert_before (list, data, pNode); assert (consistent (list), __LINE__); dump (list, reverse);
}


TNode * insert_sorted_dump (TList & list, int data, bool reverse) {
   TNode * p = insert_sorted (list, data);

   assert (p != nullptr, __LINE__);
   assert (consistent (list), __LINE__);

   dump (list, reverse); return p;
}


int * make_reference (std::size_t size, ...) {
   va_list    args;
   static int reference [32]; assert (size <= Length (reference), __LINE__);

   va_start (args, size);

   for (std::size_t i = 0; i < size; ++i) {
      reference[i] = va_arg (args, int);
   }

   va_end (args); return reference;
}


void push_back_dump (TList & list, int data, bool reverse) {
   push_back (list, data); assert (consistent (list), __LINE__); dump (list, reverse);
}


void push_back_sort_dump (TList & list, int data, bool reverse) {
   push_back (list, data); assert (consistent (list), __LINE__);
   sort      (list);       assert (consistent (list), __LINE__);

   dump (list, reverse);
}


void push_front_dump (TList & list, int data, bool reverse) {
   push_front (list, data); assert (consistent (list), __LINE__); dump (list, reverse);
}


void rotate_left_dump(TList & list, bool reverse) {
    rotate_left(list); assert (consistent (list), __LINE__); dump (list, reverse);
}


void rotate_right_dump(TList & list, bool reverse) {
    rotate_right(list); assert (consistent (list), __LINE__); dump (list, reverse);
}


void sort_dump (TList & list, bool reverse) {
   sort (list); assert (consistent (list), __LINE__); dump (list, reverse);
}


void test_case_01 () {
   gpLocation = "test_case_01"; test_case_dump (1);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   dump (l1, false);

   push_front_dump (l1,  5, false); assert (contains (l1, 1, make_reference (1,              5)), __LINE__);
   push_front_dump (l1,  4, false); assert (contains (l1, 2, make_reference (2,           4, 5)), __LINE__);
   push_front_dump (l1, -2, false); assert (contains (l1, 3, make_reference (3,       -2, 4, 5)), __LINE__);
   push_front_dump (l1,  8, false); assert (contains (l1, 4, make_reference (4,    8, -2, 4, 5)), __LINE__);
   push_front_dump (l1,  3, false); assert (contains (l1, 5, make_reference (5, 3, 8, -2, 4, 5)), __LINE__);

   std::cout << std::endl;

   dump (l2, true);

   push_front_dump (l2, 15, true); assert (contains (l2, 1, make_reference (1,                    15)), __LINE__);
   push_front_dump (l2,  6, true); assert (contains (l2, 2, make_reference (2,                 6, 15)), __LINE__);
   push_front_dump (l2,  6, true); assert (contains (l2, 3, make_reference (3,              6, 6, 15)), __LINE__);
   push_front_dump (l2,  3, true); assert (contains (l2, 4, make_reference (4,           3, 6, 6, 15)), __LINE__);
   push_front_dump (l2,  2, true); assert (contains (l2, 5, make_reference (5,        2, 3, 6, 6, 15)), __LINE__);
   push_front_dump (l2,  1, true); assert (contains (l2, 6, make_reference (6,     1, 2, 3, 6, 6, 15)), __LINE__);
   push_front_dump (l2, -3, true); assert (contains (l2, 7, make_reference (7, -3, 1, 2, 3, 6, 6, 15)), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_02 () {
   gpLocation = "test_case_02"; test_case_dump (2);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   TNode * p1 = nullptr;
   TNode * p2 = nullptr;

   std::cout << std::endl;

   push_front (l1,  5); assert (contains (l1, 1, make_reference (1,              5)), __LINE__);
   push_front (l1,  4); assert (contains (l1, 2, make_reference (2,           4, 5)), __LINE__);
   push_front (l1, -2); assert (contains (l1, 3, make_reference (3,       -2, 4, 5)), __LINE__);
   push_front (l1,  8); assert (contains (l1, 4, make_reference (4,    8, -2, 4, 5)), __LINE__);
   push_front (l1,  3); assert (contains (l1, 5, make_reference (5, 3, 8, -2, 4, 5)), __LINE__);

   push_front (l2, 15); assert (contains (l2, 1, make_reference (1,                    15)), __LINE__);
   push_front (l2,  6); assert (contains (l2, 2, make_reference (2,                 6, 15)), __LINE__);
   push_front (l2,  6); assert (contains (l2, 3, make_reference (3,              6, 6, 15)), __LINE__);
   push_front (l2,  3); assert (contains (l2, 4, make_reference (4,           3, 6, 6, 15)), __LINE__);
   push_front (l2,  2); assert (contains (l2, 5, make_reference (5,        2, 3, 6, 6, 15)), __LINE__);
   push_front (l2,  1); assert (contains (l2, 6, make_reference (6,     1, 2, 3, 6, 6, 15)), __LINE__);
   push_front (l2, -3); assert (contains (l2, 7, make_reference (7, -3, 1, 2, 3, 6, 6, 15)), __LINE__);

   count_dump (l1, 8, make_reference (8, -2, 1, 15, 0, 6, 0, 3, 1));
   count_dump (l2, 8, make_reference (8, -2, 0, 15, 1, 6, 2, 3, 1));

   p1 = search_first (l1, -2); assert (consistent (l1), __LINE__);
   p2 = search_last  (l1, -2); assert (consistent (l1), __LINE__);

   assert (p1 != nullptr, __LINE__);
   assert (p2 != nullptr, __LINE__);
   assert (valid_node (l1, p1), __LINE__);
   assert (valid_node (l1, p2), __LINE__);
   assert (p1 == p2, __LINE__);
   assert (p1->data == -2, __LINE__);

   p1 = search_first (l1, 2); assert (consistent (l1), __LINE__);
   p2 = search_last  (l1, 2); assert (consistent (l1), __LINE__);

   assert (p1 == nullptr, __LINE__);
   assert (p2 == nullptr, __LINE__);
   assert (valid_node (l1, p1), __LINE__);
   assert (valid_node (l1, p2), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_03 () {
   gpLocation = "test_case_03"; test_case_dump (3);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   push_front (l1,  5); assert (contains (l1, 1, make_reference (1,              5)), __LINE__);
   push_front (l1,  4); assert (contains (l1, 2, make_reference (2,           4, 5)), __LINE__);
   push_front (l1, -2); assert (contains (l1, 3, make_reference (3,       -2, 4, 5)), __LINE__);
   push_front (l1,  8); assert (contains (l1, 4, make_reference (4,    8, -2, 4, 5)), __LINE__);
   push_front (l1,  3); assert (contains (l1, 5, make_reference (5, 3, 8, -2, 4, 5)), __LINE__);

   push_front (l2, 15); assert (contains (l2, 1, make_reference (1,                    15)), __LINE__);
   push_front (l2,  6); assert (contains (l2, 2, make_reference (2,                 6, 15)), __LINE__);
   push_front (l2,  6); assert (contains (l2, 3, make_reference (3,              6, 6, 15)), __LINE__);
   push_front (l2,  3); assert (contains (l2, 4, make_reference (4,           3, 6, 6, 15)), __LINE__);
   push_front (l2,  2); assert (contains (l2, 5, make_reference (5,        2, 3, 6, 6, 15)), __LINE__);
   push_front (l2,  1); assert (contains (l2, 6, make_reference (6,     1, 2, 3, 6, 6, 15)), __LINE__);
   push_front (l2, -3); assert (contains (l2, 7, make_reference (7, -3, 1, 2, 3, 6, 6, 15)), __LINE__);

   sort_dump (l1, false); assert (contains (l1, 5, make_reference (5, -2, 3, 4, 5, 8)), __LINE__);
   sort_dump (l2, false); assert (contains (l2, 7, make_reference (7, -3, 1, 2, 3, 6, 6, 15)), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_04 () {
   gpLocation = "test_case_04"; test_case_dump (4);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_05 () {
   gpLocation = "test_case_05"; test_case_dump (5);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   count_dump (l1, 8, make_reference (8, -2, 0, 15, 0, 6, 0, 3, 0));
   count_dump (l2, 8, make_reference (8, -2, 0, 15, 0, 6, 0, 3, 0));

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_06 () {
   gpLocation = "test_case_06"; test_case_dump (6);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   push_back_dump (l1,  5, false); assert (contains (l1, 1, make_reference (1, 5             )), __LINE__);
   push_back_dump (l1,  4, false); assert (contains (l1, 2, make_reference (2, 5, 4          )), __LINE__);
   push_back_dump (l1, -2, false); assert (contains (l1, 3, make_reference (3, 5, 4, -2      )), __LINE__);
   push_back_dump (l1,  8, false); assert (contains (l1, 4, make_reference (4, 5, 4, -2, 8   )), __LINE__);
   push_back_dump (l1,  3, false); assert (contains (l1, 5, make_reference (5, 5, 4, -2, 8, 3)), __LINE__);

   std::cout << std::endl;

   push_back_dump (l2, 15, true); assert (contains (l2, 1, make_reference (1, 15                   )), __LINE__);
   push_back_dump (l2,  6, true); assert (contains (l2, 2, make_reference (2, 15, 6                )), __LINE__);
   push_back_dump (l2,  6, true); assert (contains (l2, 3, make_reference (3, 15, 6, 6             )), __LINE__);
   push_back_dump (l2,  3, true); assert (contains (l2, 4, make_reference (4, 15, 6, 6, 3          )), __LINE__);
   push_back_dump (l2,  2, true); assert (contains (l2, 5, make_reference (5, 15, 6, 6, 3, 2       )), __LINE__);
   push_back_dump (l2,  1, true); assert (contains (l2, 6, make_reference (6, 15, 6, 6, 3, 2, 1    )), __LINE__);
   push_back_dump (l2, -3, true); assert (contains (l2, 7, make_reference (7, 15, 6, 6, 3, 2, 1, -3)), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_07 () {
   gpLocation = "test_case_07"; test_case_dump (7);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   insert_sorted_dump (l1, 1, false); assert (contains (l1, 1, make_reference (1, 1                  )), __LINE__);
   insert_sorted_dump (l1, 2, false); assert (contains (l1, 2, make_reference (2, 1, 2               )), __LINE__);
   insert_sorted_dump (l1, 3, false); assert (contains (l1, 3, make_reference (3, 1, 2, 3            )), __LINE__);
   insert_sorted_dump (l1, 3, false); assert (contains (l1, 4, make_reference (4, 1, 2, 3, 3         )), __LINE__);
   insert_sorted_dump (l1, 3, false); assert (contains (l1, 5, make_reference (5, 1, 2, 3, 3, 3      )), __LINE__);
   insert_sorted_dump (l1, 4, false); assert (contains (l1, 6, make_reference (6, 1, 2, 3, 3, 3, 4   )), __LINE__);
   insert_sorted_dump (l1, 5, false); assert (contains (l1, 7, make_reference (7, 1, 2, 3, 3, 3, 4, 5)), __LINE__);

   std::cout << std::endl;

   insert_sorted_dump (l2, 5, false); assert (contains (l2, 1, make_reference (1, 5                  )), __LINE__);
   insert_sorted_dump (l2, 4, false); assert (contains (l2, 2, make_reference (2, 4, 5               )), __LINE__);
   insert_sorted_dump (l2, 3, false); assert (contains (l2, 3, make_reference (3, 3, 4, 5            )), __LINE__);
   insert_sorted_dump (l2, 2, false); assert (contains (l2, 4, make_reference (4, 2, 3, 4, 5         )), __LINE__);
   insert_sorted_dump (l2, 2, false); assert (contains (l2, 5, make_reference (5, 2, 2, 3, 4, 5      )), __LINE__);
   insert_sorted_dump (l2, 2, false); assert (contains (l2, 6, make_reference (6, 2, 2, 2, 3, 4, 5   )), __LINE__);
   insert_sorted_dump (l2, 1, false); assert (contains (l2, 7, make_reference (7, 1, 2, 2, 2, 3, 4, 5)), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_08 () {
   gpLocation = "test_case_08"; test_case_dump (8);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   insert_sorted_dump (l1, 3, false); assert (contains (l1, 1, make_reference (1, 3                  )), __LINE__);
   insert_sorted_dump (l1, 6, false); assert (contains (l1, 2, make_reference (2, 3, 6               )), __LINE__);
   insert_sorted_dump (l1, 1, false); assert (contains (l1, 3, make_reference (3, 1, 3, 6            )), __LINE__);
   insert_sorted_dump (l1, 9, false); assert (contains (l1, 4, make_reference (4, 1, 3, 6, 9         )), __LINE__);
   insert_sorted_dump (l1, 5, false); assert (contains (l1, 5, make_reference (5, 1, 3, 5, 6, 9      )), __LINE__);
   insert_sorted_dump (l1, 6, false); assert (contains (l1, 6, make_reference (6, 1, 3, 5, 6, 6, 9   )), __LINE__);
   insert_sorted_dump (l1, 5, false); assert (contains (l1, 7, make_reference (7, 1, 3, 5, 5, 6, 6, 9)), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_09 () {
   gpLocation = "test_case_09"; test_case_dump (9);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   push_back_sort_dump (l1, 15, false); assert (contains (l1, 1, make_reference (1, 15                        )), __LINE__);
   push_back_sort_dump (l1,  6, false); assert (contains (l1, 2, make_reference (2,  6, 15                    )), __LINE__);
   push_back_sort_dump (l1,  6, false); assert (contains (l1, 3, make_reference (3,  6,  6, 15                )), __LINE__);
   push_back_sort_dump (l1,  3, false); assert (contains (l1, 4, make_reference (4,  3,  6,  6, 15            )), __LINE__);
   push_back_sort_dump (l1,  2, false); assert (contains (l1, 5, make_reference (5,  2,  3,  6,  6, 15        )), __LINE__);
   push_back_sort_dump (l1,  1, false); assert (contains (l1, 6, make_reference (6,  1,  2,  3,  6,  6, 15    )), __LINE__);
   push_back_sort_dump (l1, -3, false); assert (contains (l1, 7, make_reference (7, -3,  1,  2,  3,  6,  6, 15)), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_10 () {
   gpLocation = "test_case_10"; test_case_dump (10);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   TNode * p1 = nullptr;
   TNode * p2 = nullptr;

   std::cout << std::endl;

   p1 = insert_sorted_dump (l1, 3, false); assert (contains (l1, 1, make_reference (1, 3)), __LINE__);

   assert (p1 != nullptr, __LINE__);
   assert (valid_node (l1, p1), __LINE__);

   insert_before_dump (l1, 1, p1, false); assert (contains (l1, 2, make_reference (2, 1, 3         )), __LINE__);
   insert_before_dump (l1, 2, p1, false); assert (contains (l1, 3, make_reference (3, 1, 2, 3      )), __LINE__);
   insert_before_dump (l1, 8, p1, false); assert (contains (l1, 4, make_reference (4, 1, 2, 8, 3   )), __LINE__);
   insert_before_dump (l1, 7, p1, false); assert (contains (l1, 5, make_reference (5, 1, 2, 8, 7, 3)), __LINE__);

   std::cout << std::endl;

   p2 = insert_sorted_dump (l2, 3, false); assert (contains (l2, 1, make_reference (1, 3)), __LINE__);

   assert (p2 != nullptr, __LINE__);
   assert (valid_node (l2, p2), __LINE__);

   insert_after_dump (l2, 8, p2, false); assert (contains (l2, 2, make_reference (2, 3, 8         )), __LINE__);
   insert_after_dump (l2, 4, p2, false); assert (contains (l2, 3, make_reference (3, 3, 4, 8      )), __LINE__);
   insert_after_dump (l2, 2, p2, false); assert (contains (l2, 4, make_reference (4, 3, 2, 4, 8   )), __LINE__);
   insert_after_dump (l2, 7, p2, false); assert (contains (l2, 5, make_reference (5, 3, 7, 2, 4, 8)), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_11 () {
   gpLocation = "test_case_11"; test_case_dump (11);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   push_back (l1, 1); assert (contains (l1, 1, make_reference (1, 1                  )), __LINE__);
   push_back (l1, 3); assert (contains (l1, 2, make_reference (2, 1, 3               )), __LINE__);
   push_back (l1, 2); assert (contains (l1, 3, make_reference (3, 1, 3, 2            )), __LINE__);
   push_back (l1, 9); assert (contains (l1, 4, make_reference (4, 1, 3, 2, 9         )), __LINE__);
   push_back (l1, 3); assert (contains (l1, 5, make_reference (5, 1, 3, 2, 9, 3      )), __LINE__);
   push_back (l1, 4); assert (contains (l1, 6, make_reference (6, 1, 3, 2, 9, 3, 4   )), __LINE__);
   push_back (l1, 4); assert (contains (l1, 7, make_reference (7, 1, 3, 2, 9, 3, 4, 4)), __LINE__);

   dump (l1, false);

   erase_dump (l1, 3, false); assert (contains (l1, 6, make_reference (6, 1, 2, 9, 3, 4, 4)), __LINE__);
   erase_dump (l1, 9, false); assert (contains (l1, 5, make_reference (5, 1, 2, 3, 4, 4   )), __LINE__);
   erase_dump (l1, 4, false); assert (contains (l1, 4, make_reference (4, 1, 2, 3, 4      )), __LINE__);
   erase_dump (l1, 4, false); assert (contains (l1, 3, make_reference (3, 1, 2, 3         )), __LINE__);
   erase_dump (l1, 1, false); assert (contains (l1, 2, make_reference (2, 2, 3            )), __LINE__);
   erase_dump (l1, 3, false); assert (contains (l1, 1, make_reference (1, 2               )), __LINE__);
   erase_dump (l1, 2, false); assert (contains (l1, 0, make_reference (0                  )), __LINE__);
   erase_dump (l1, 1, false); assert (contains (l1, 0, make_reference (0                  )), __LINE__);

   std::cout << std::endl;

   push_back (l1, 1); assert (contains (l1, 1, make_reference (1, 1                  )), __LINE__);
   push_back (l1, 3); assert (contains (l1, 2, make_reference (2, 1, 3               )), __LINE__);
   push_back (l1, 2); assert (contains (l1, 3, make_reference (3, 1, 3, 2            )), __LINE__);
   push_back (l1, 9); assert (contains (l1, 4, make_reference (4, 1, 3, 2, 9         )), __LINE__);
   push_back (l1, 3); assert (contains (l1, 5, make_reference (5, 1, 3, 2, 9, 3      )), __LINE__);
   push_back (l1, 4); assert (contains (l1, 6, make_reference (6, 1, 3, 2, 9, 3, 4   )), __LINE__);
   push_back (l1, 4); assert (contains (l1, 7, make_reference (7, 1, 3, 2, 9, 3, 4, 4)), __LINE__);

   dump (l1, false);

   erase_all_dump (l1, 4, false); assert (contains (l1, 5, make_reference (5, 1, 3, 2, 9, 3)), __LINE__);
   erase_all_dump (l1, 3, false); assert (contains (l1, 3, make_reference (3, 1, 2, 9)), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_12 () {
   gpLocation = "test_case_12"; test_case_dump (12);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   push_back (l1, 1); assert (contains (l1, 1, make_reference (1, 1            )), __LINE__);
   push_back (l1, 2); assert (contains (l1, 2, make_reference (2, 1, 2         )), __LINE__);
   push_back (l1, 3); assert (contains (l1, 3, make_reference (3, 1, 2, 3      )), __LINE__);
   push_back (l1, 4); assert (contains (l1, 4, make_reference (4, 1, 2, 3, 4   )), __LINE__);
   push_back (l1, 0); assert (contains (l1, 5, make_reference (5, 1, 2, 3, 4, 0)), __LINE__);

   push_back (l2, 9); assert (contains (l2, 1, make_reference (1, 9            )), __LINE__);
   push_back (l2, 2); assert (contains (l2, 2, make_reference (2, 9, 2         )), __LINE__);
   push_back (l2, 3); assert (contains (l2, 3, make_reference (3, 9, 2, 3      )), __LINE__);
   push_back (l2, 4); assert (contains (l2, 4, make_reference (4, 9, 2, 3, 4   )), __LINE__);
   push_back (l2, 5); assert (contains (l2, 5, make_reference (5, 9, 2, 3, 4, 5)), __LINE__);

   dump (l1, false); erase_all_dump (l1, 0, false); assert (contains (l1, 4, make_reference (4, 1, 2, 3, 4)), __LINE__);

   std::cout << std::endl;

   dump (l2, false); erase_all_dump (l2, 9, false); assert (contains (l2, 4, make_reference (4, 2, 3, 4, 5)), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_13 () {

   gpLocation = "test_case_13"; test_case_dump (13);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;
   std:: cout << "Testfall entfaellt." << std::endl;
   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_14 () {
   gpLocation = "test_case_14"; test_case_dump (14);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   TNode * p1 = nullptr;
// TNode * p2 = nullptr;

   std::cout << std::endl;

   for (int i = 0; i < 250000; ++i) {
      push_back  (l1, 4); assert ((i > 0) || (consistent (l1) && contains (l1,  1, make_reference ( 1, 4                              ))), __LINE__);
      push_back  (l1, 7); assert ((i > 0) || (consistent (l1) && contains (l1,  2, make_reference ( 2, 4, 7                           ))), __LINE__);
      push_front (l1, 2); assert ((i > 0) || (consistent (l1) && contains (l1,  3, make_reference ( 3, 2, 4, 7                        ))), __LINE__);
      push_front (l1, 9); assert ((i > 0) || (consistent (l1) && contains (l1,  4, make_reference ( 4, 9, 2, 4, 7                     ))), __LINE__);
      push_back  (l1, 7); assert ((i > 0) || (consistent (l1) && contains (l1,  5, make_reference ( 5, 9, 2, 4, 7, 7                  ))), __LINE__);
      push_front (l1, 3); assert ((i > 0) || (consistent (l1) && contains (l1,  6, make_reference ( 6, 3, 9, 2, 4, 7, 7               ))), __LINE__);
      push_front (l1, 9); assert ((i > 0) || (consistent (l1) && contains (l1,  7, make_reference ( 7, 9, 3, 9, 2, 4, 7, 7            ))), __LINE__);
      push_back  (l1, 7); assert ((i > 0) || (consistent (l1) && contains (l1,  8, make_reference ( 8, 9, 3, 9, 2, 4, 7, 7, 7         ))), __LINE__);
      push_front (l1, 3); assert ((i > 0) || (consistent (l1) && contains (l1,  9, make_reference ( 9, 3, 9, 3, 9, 2, 4, 7, 7, 7      ))), __LINE__);
      push_front (l1, 2); assert ((i > 0) || (consistent (l1) && contains (l1, 10, make_reference (10, 2, 3, 9, 3, 9, 2, 4, 7, 7, 7   ))), __LINE__);
      push_back  (l1, 3); assert ((i > 0) || (consistent (l1) && contains (l1, 11, make_reference (11, 2, 3, 9, 3, 9, 2, 4, 7, 7, 7, 3))), __LINE__);

      p1 = search_last (l1, 7);

      assert ((i > 0) || (p1 != nullptr), __LINE__);
      assert ((i > 0) || valid_node (l1, p1), __LINE__);
      assert ((i > 0) || (p1->data == 7), __LINE__);

      insert_before (l1, 8, p1); assert ((i > 0) || (consistent (l1) && contains (l1, 12, make_reference (12, 2, 3, 9, 3, 9, 2, 4, 7, 7, 8, 7, 3   ))), __LINE__);
      insert_after  (l1, 8, p1); assert ((i > 0) || (consistent (l1) && contains (l1, 13, make_reference (13, 2, 3, 9, 3, 9, 2, 4, 7, 7, 8, 7, 8, 3))), __LINE__);

//    dump (l1, false);

      erase_all (l1, 8); assert ((i > 0) || (consistent (l1) && contains (l1, 11, make_reference (11, 2, 3, 9, 3, 9, 2, 4, 7, 7, 7, 3))), __LINE__);
      erase     (l1, 7); assert ((i > 0) || (consistent (l1) && contains (l1, 10, make_reference (10, 2, 3, 9, 3, 9, 2, 4, 7, 7, 3   ))), __LINE__);
      erase_all (l1, 9); assert ((i > 0) || (consistent (l1) && contains (l1,  8, make_reference ( 8, 2, 3, 3, 2, 4, 7, 7, 3         ))), __LINE__);
      erase     (l1, 7); assert ((i > 0) || (consistent (l1) && contains (l1,  7, make_reference ( 7, 2, 3, 3, 2, 4, 7, 3            ))), __LINE__);

//    dump (l1, false);

      sort   (l1); assert ((i > 0) || (consistent (l1) && contains (l1, 7, make_reference (7, 2, 2, 3, 3, 3, 4, 7))), __LINE__);   // dump (l1, false);

      clear (l1); assert ((i > 0) || consistent (l1), __LINE__);
   }

// std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_15 () {
   gpLocation = "test_case_15"; test_case_dump (15);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   push_back (l1, 1); assert (contains (l1, 1, make_reference (1, 1            )), __LINE__);
   push_back (l1, 2); assert (contains (l1, 2, make_reference (2, 1, 2         )), __LINE__);
   push_back (l1, 3); assert (contains (l1, 3, make_reference (3, 1, 2, 3      )), __LINE__);
   push_back (l1, 4); assert (contains (l1, 4, make_reference (4, 1, 2, 3, 4   )), __LINE__);
   push_back (l1, 0); assert (contains (l1, 5, make_reference (5, 1, 2, 3, 4, 0)), __LINE__);

   push_back (l2, 9); assert (contains (l2, 1, make_reference (1, 9            )), __LINE__);
   push_back (l2, 2); assert (contains (l2, 2, make_reference (2, 9, 2         )), __LINE__);
   push_back (l2, 3); assert (contains (l2, 3, make_reference (3, 9, 2, 3      )), __LINE__);
   push_back (l2, 4); assert (contains (l2, 4, make_reference (4, 9, 2, 3, 4   )), __LINE__);
   push_back (l2, 5); assert (contains (l2, 5, make_reference (5, 9, 2, 3, 4, 5)), __LINE__);

   dump (l1, false);
   erase_lower_dump (l1, 1, false); assert (contains (l1, 4, make_reference (4, 1, 2, 3, 4)), __LINE__);
   erase_lower_dump (l1, 4, false); assert (contains (l1, 1, make_reference (1,          4)), __LINE__);
   erase_lower_dump (l1, 5, false); assert (contains (l1, 0, make_reference (0            )), __LINE__);

   std::cout << std::endl;

   dump (l2, false);
   erase_lower_dump (l2, 6, false); assert (contains (l2, 1, make_reference (1, 9         )), __LINE__);
   erase_lower_dump (l2,10, false); assert (contains (l2, 0, make_reference (1            )), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}

void test_case_16 () {
   gpLocation = "test_case_16"; test_case_dump (16);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   push_back (l1, 1); assert (contains (l1, 1, make_reference (1, 1            )), __LINE__);
   push_back (l1, 2); assert (contains (l1, 2, make_reference (2, 1, 2         )), __LINE__);
   push_back (l1, 3); assert (contains (l1, 3, make_reference (3, 1, 2, 3      )), __LINE__);
   push_back (l1, 4); assert (contains (l1, 4, make_reference (4, 1, 2, 3, 4   )), __LINE__);
   push_back (l1, 0); assert (contains (l1, 5, make_reference (5, 1, 2, 3, 4, 0)), __LINE__);

   push_back (l2, 9); assert (contains (l2, 1, make_reference (1, 9            )), __LINE__);
   push_back (l2, 7); assert (contains (l2, 2, make_reference (2, 9, 7         )), __LINE__);

   dump (l1, false);
   rotate_left_dump (l1, false); assert (contains (l1, 5, make_reference (5, 2, 3, 4, 0, 1)), __LINE__);

   std::cout << std::endl;

   dump (l2, false);
   rotate_left_dump (l2, false); assert (contains (l2, 2, make_reference (2, 7, 9         )), __LINE__);
   erase_dump(l2, 7, false);
   rotate_left_dump (l2, false); assert (contains (l2, 1, make_reference (1, 9            )), __LINE__);
   erase_dump(l2, 9, false);
   rotate_left_dump (l2, false); assert (contains (l2, 0, make_reference (0               )), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_17 () {
   gpLocation = "test_case_17"; test_case_dump (17);

   TList l1; init_dump (l1, false);
   TList l2; init_dump (l2, false);

   std::cout << std::endl;

   push_back (l1, 1); assert (contains (l1, 1, make_reference (1, 1            )), __LINE__);
   push_back (l1, 2); assert (contains (l1, 2, make_reference (2, 1, 2         )), __LINE__);
   push_back (l1, 3); assert (contains (l1, 3, make_reference (3, 1, 2, 3      )), __LINE__);
   push_back (l1, 4); assert (contains (l1, 4, make_reference (4, 1, 2, 3, 4   )), __LINE__);
   push_back (l1, 0); assert (contains (l1, 5, make_reference (5, 1, 2, 3, 4, 0)), __LINE__);

   push_back (l2, 9); assert (contains (l2, 1, make_reference (1, 9            )), __LINE__);
   push_back (l2, 7); assert (contains (l2, 2, make_reference (2, 9, 7         )), __LINE__);

   dump (l1, false);
   rotate_right_dump (l1, false); assert (contains (l1, 5, make_reference (5, 0, 1, 2, 3, 4)), __LINE__);

   std::cout << std::endl;

   dump (l2, false);
   rotate_right_dump (l2, false); assert (contains (l2, 2, make_reference (2, 7, 9         )), __LINE__);
   erase_dump(l2, 7, false);
   rotate_right_dump (l2, false); assert (contains (l2, 1, make_reference (1, 9            )), __LINE__);
   erase_dump(l2, 9, false);
   rotate_right_dump (l2, false); assert (contains (l2, 0, make_reference (0               )), __LINE__);

   std::cout << std::endl;

   clear_dump (l1, true);
   clear_dump (l2, true);
}


void test_case_dump (int test) {
   std::cout << std::endl
             << "----------" << (test > 9 ? "-" : "") << std::endl
             << "Testfall "  << test << std::endl
             << "----------" << (test > 9 ? "-" : "") << std::endl;
}
