#include <iostream>

int main()
{
    int max_val = 0;
    int min_val = 0;
    int total_val = 0;

    int value = 0;
    for(int i = 0; i < 10; ++i){
        std::cin >> value;
        total_val += value;

        if(value > max_val || max_val == 0){
            max_val = value;
        }

        if(value < min_val || min_val == 0){
            min_val = value;
        }
    }

    std::cout << max_val << "," << min_val << "," << (float)total_val / 10.0;
    return 0;
}