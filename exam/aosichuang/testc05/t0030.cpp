#include <iostream>

void swap(int & a, int & b)
{
    int c = b;
    b = a;
    a = c;
}


void bubble_sort(int a[], int n)
{
    for(int i = 0; i < n; ++i){
        for(int j = 0 ; j < n-i-1; ++j){
            if(a[j] < a[j +1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

void print_arr(int a[], int n)
{
    for(int i = 0; i < n; ++i){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    int n, k;
    std::cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    bubble_sort(a, n);
    int last_val = a[k-1];
    int count = k;
    for(int j =  k; j < n; ++j){
        if(a[j] == last_val){
            count++;
        }
        else if(a[j] < last_val){
            break;
        }
    }
    
    std::cout << count;    
    return 0;
}