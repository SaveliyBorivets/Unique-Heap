#ifndef DOP_AISD__UNIVERSAL_HEAP_H_
#define DOP_AISD__UNIVERSAL_HEAP_H_

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

enum Heap_mode {
  MIN,
  MAX
};

class UniversalHeap {
 private:
  vector<int> heap;
  Heap_mode heap_mode;
  void heapify(int index);
  void sort_heap();
 public:
  UniversalHeap(vector<int>& array, Heap_mode);
  void change_mode();
  void insert(int key);
  int extract_special_item();
  int get_special_item();
  string get_mode();
  void print_array();
  void print_heap(int index = 0, int level = 0);
};

#endif //DOP_AISD__UNIVERSAL_HEAP_H_
