#include <iostream>
using namespace std;

int main()
{
    long long a;
    std::cin >> a;

    long long b, c;
    std::cin >> b >> c;

    long long area = a * a;
    long long perimeter = (b+c) *2;

    if(perimeter > area){
        std::cout << "RECTANGLE";
    }
    else if(perimeter < area){
        std::cout << "SQUARE";
    }
    else{
        std::cout << "SAME";
    }

    return 0;
}
