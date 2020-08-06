import heapq

def sliding_window(arr, k, n):
    heap = []
    for i in range(k):
        heap.append(arr[i])
        
    heapq._heapify_max(heap)
    last = 0
    print(heap, heap[0])

    for a in range(k, n):
        heap[heap.index(arr[last])] = arr[a]
        heapq._heapify_max(heap)
        print(heap, heap[0])
        last+=1   
        
n, k = 10, 3
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 
sliding_window(arr, k, n) 