#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int max_val = (n+1)*100;
    int count = 0;
    for(int i = 100; i < max_val; ++i){
        //俺是奇数
        if(i % 2 == 1){
            int c1 = i / 10;
            int b1 = i % 10;
            int b2 = c1 % 10;
            int b3 = c1 / 10;

            //各不相同
            if(b1 <= n && b2 <= n && b3 <= n && b1 != b2 && b1 != b3 && b2 != b3){
                count++;
            } 
        }
    }
    std::cout << count;
    return 0;
}
