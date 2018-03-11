# Binary Heap
A Binary Heap is a Binary Tree with following properties.
- It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

- A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to Min Heap.


## How is Binary Heap represented?
A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as array.

The root element will be at Arr[0].

Below table shows indexes of other nodes for the ith node, i.e., Arr[i]:

- Arr[i/2]	Returns the parent node
- Arr[(2*i)+1]	Returns the left child node
- Arr[(2*i)+2]	Returns the right child node


## Operations on Min/Max Heap:
1) getMin()/ getMax(): It returns the root element of Min/Max Heap. Time Complexity of this operation is O(1).

2) extractMin()/ extractMax(): Removes the minimum/maximum element from Min/Max Heap. Time Complexity of this Operation is O(Logn) as this operation needs to maintain the heap property (by calling heapify()) after removing root.

3) decreaseKey()/ increaseKey(): Decreases/increase value of key. Time complexity of this operation is O(Logn). If the decreases/increases key value of a node is greater than parent of the node, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.

4) insert(): Inserting a new key takes O(Logn) time. We add a new key at the end of the tree. IF new key is greater than its parent, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.

5) delete(): Deleting a key also takes O(Logn) time. We replace the key to be deleted with minum infinite by calling decreaseKey()/increaseKey(). After decreaseKey()/increaseKey(), the minus infinite/ plus infinite value must reach root, so we call extractMin()/extractMax() to remove key.

## Code 

- [Binary Min Heap](./cpp/binary_min_heap.h)
- [Binary Max Heap](./cpp/binary_max_heap.h)
- [Heap Sort](./cpp/heap_sort.cpp)