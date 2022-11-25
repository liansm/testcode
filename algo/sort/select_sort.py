import random

def swap(arr, idx1, idx2):
    arr[idx1], arr[idx2] = arr[idx2], arr[idx1]



def select_sort(arr, n):
    for i in range(0, n):
        min_idx = i        
        for j in range(i+1, n):
            if  arr[j] < arr[min_idx]:
                min_idx = j
        swap(arr, i, min_idx)



arr = []
for idx in range(0, 20):
    val = random.randint(0, 100)
    arr.append(val)


print(arr)

select_sort(arr, 20)

print(arr)