import random

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

    
def bubble_sort(arr):
    n = len(arr)
    
    for i in range(0, n):
        for j in range(0, n-i-1):
            if arr[j+1] < arr[j]:
                swap(arr, j+1, j) 


def make_rand_arr(num, max_value):
    arr = []
    for idx in range(0, num):
        val = random.randint(0, max_value)
        arr.append(val)
    return arr


def test_bubble():
    arr = make_rand_arr(20, 100)
    print(arr)
    bubble_sort(arr)
    print(arr)

test_bubble()

