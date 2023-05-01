#include <iostream>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    if(n % 2 == 0){
        std::cout << 0;
    }
    else{
        std::cout << 1;
    }

    return 0;
}