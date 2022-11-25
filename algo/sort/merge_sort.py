import random

def merge_sort(arr):
    sep = 1
    n = len(arr)
    while True:
        idx = 0
        while idx+sep <= n:                        
            arr[idx:idx+sep+sep] = merge(arr[idx:idx+sep], arr[idx+sep:idx+sep+sep])
            idx = idx+ sep*2
        if sep > (int)(n/2):
            break   
        sep *= 2
        print(arr)                       
    return


def divide(arr):
    arr_len = len(arr)
    if arr_len == 1:
        return arr

    middle = (int)(arr_len / 2)
    arr_left = arr[0:middle]
    arr_right = arr[middle:arr_len]
    return arr_left, arr_right

def merge(arr1, arr2):
    arr1_len = len(arr1)
    arr2_len = len(arr2)
    i = 0
    j = 0
    arr3 = []
    while i < arr1_len and j < arr2_len:
        if arr1[i] <= arr2[j]:
            arr3.append(arr1[i])
            i = i + 1
        else:
            arr3.append(arr2[j])
            j = j + 1

    if i < arr1_len:        
       for idx in range(i, arr1_len):
            arr3.append(arr1[idx])

    if j < arr2_len:
        for idx in range(j, arr2_len):
            arr3.append(arr2[idx])

    return arr3


def make_rand_arr(num, max_value):
    arr = []
    for idx in range(0, num):
        val = random.randint(0, max_value)
        arr.append(val)
    return arr


def test_merge():
    arr1 = make_rand_arr(20, 100)
    arr1.sort()
    print(arr1)

    arr2 = make_rand_arr(30, 200)
    arr2.sort()
    print(arr2)

    arr3 = merge(arr1, arr2)
    print(arr3)


def test_divide():
    arr = make_rand_arr(20, 100)
    print(arr)
    print(divide(arr))


def test_merge_sort():
    arr = make_rand_arr(100, 10000)
    print(arr)
    merge_sort(arr)
    print(arr)

test_merge_sort()
