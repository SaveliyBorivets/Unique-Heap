#include "universal_heap.h"

void UniversalHeap::heapify(int index) {
  int left;
  int right;
  int largest;
  while(true) {
    left = 2 * index + 1;
    right = 2 * index + 2;
    largest = index;
    if (heap_mode == MAX) {
      if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
      }

      if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
      }
    } else if (heap_mode == MIN) {
      if (left < heap.size() && heap[left] < heap[largest]) {
        largest = left;
      }

      if (right < heap.size() && heap[right] < heap[largest]) {
        largest = right;
      }
    }

    if (largest == index) {
      break;
    }

    int temp = heap[index];
    heap[index] = heap[largest];
    heap[largest] = temp;
    index = largest;
  }
}

void UniversalHeap::sort_heap() {
  for (int i = heap.size() / 2; i >= 0; i--) {
    heapify(i);
  }
}

UniversalHeap::UniversalHeap(vector<int>& array, Heap_mode mode) : heap(array) {
  heap_mode = mode;
  sort_heap();
}

void UniversalHeap::change_mode() {
  if (heap_mode == MAX) {
    heap_mode = MIN;
  } else {
    heap_mode = MAX;
  }
  sort_heap();
}

void UniversalHeap::insert(int key) {
  heap.insert(heap.begin(), key);
  heapify(0);
}

int UniversalHeap::extract_special_item() {
  int result = heap[0];
  heap[0] = heap[heap.size() - 1];
  heap.pop_back();
  heapify(0);
  return result;
}

int UniversalHeap::get_special_item() {
  return heap[0];
}

string UniversalHeap::get_mode() {
  switch (heap_mode) {
    case MIN:
      return "MIN";
    case MAX:
      return "MAX";
  }
  return "UNDENIFIED";
}

void UniversalHeap::print_array() {
  for (int i = 0; i < heap.size(); i++) {
    cout << heap[i] << " ";
  }
  cout << "\n";
}

void UniversalHeap::print_heap(int index, int level) {
  if (heap.empty()) {
    cout << "Куча пуста" << endl;
    return;
  }

  if (index >= heap.size())
    return;

  print_heap(2 * index + 2, level + 1);  // сначала выводим правую ветвь
  for (int i = 0; i < level; ++i)
    cout << "\t";
  cout << heap[index] << endl;
  print_heap(2 * index + 1, level + 1);  // затем левую ветвь
}