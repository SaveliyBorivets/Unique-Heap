#include <iostream>
#include <random>
#include "universal_heap.h"

int main() {
  vector<int> array;
  int array_size = 14;
  srand(time(nullptr));
  for (int i = 0; i < array_size; i++) {
    array.push_back(1 + rand() % 99);
  }
  UniversalHeap UH = UniversalHeap(array, MIN);
  cout << "=============== PRINT MIN HEAP OF " << array_size << " RANDOM NUMBERS ===============\n";
  UH.print_heap();
  cout << "=============== CHANGE MODE ===============\n";
  UH.change_mode();
  UH.print_heap();
  cout << "=============== INSERT 50 ===============\n";
  UH.insert(50);
  UH.print_array();
  UH.print_heap();
  cout << "=============== EXTRACT UNIQUE ITEM ===============\n";
  cout << "EXTRACTED SPECIAL ITEM OF " << UH.get_mode() << " MODE IS: " << UH.extract_special_item() << "\n";
  UH.print_heap();
  return 0;
}
