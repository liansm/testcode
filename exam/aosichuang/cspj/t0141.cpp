#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int peak_point = 0;
    int max_peak_count = 0;

    if(n <= 2){
        std::cout << peak_point << " " << max_peak_count;
    }

    int arr[n];
    for(int i =0; i < n; ++i){
        std::cin >> arr[i];
    }

    bool flag1 = false;
    int prev_val = arr[0];
    int cur_peak_count = 0;
    for(int i = 1; i < n; ++i){
        if(arr[i] > prev_val && flag1 == false){
            flag1 = true;
        }    
        else if(arr[i] == prev_val){
            if(flag1 == true){
                cur_peak_count++;
            }           
        }    
        else if(arr[i] < prev_val){
            if(flag1 == true){
                peak_point++;
                if(cur_peak_count > max_peak_count){
                    max_peak_count = cur_peak_count;
                }
                cur_peak_count = 0;
                flag1 = false;
            }
        }
        prev_val = arr[i];
    }
    
    std::cout << peak_point << " " << max_peak_count+1;
    return 0;
}