#include <iostream>
#include <vector>

long long sleep_enough(int a, int b, int c, int d)
{
	//一开始就睡饱了
	if (a <= b) {
		return b;
	}

	//补不过来
	if (c <= d) {
		return -1;
	}

	//初始时间
	long long t = b;
	a -= b;

	//每一轮睡这么久
	int e = c - d;
	
	//一共需要睡多少轮, 向上取整
	int n = a / (c-d) + (a % (c-d) == 0 ? 0 : 1);
	
	//总时间
	t = t + (long long)n*c;
	return t;
}

int main()
{
	int n;
	std::cin >> n;

	int a, b, c, d;
	std::vector<long long> arr;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b >> c >>d;
		arr.push_back(sleep_enough(a, b, c, d));
	}

	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << std::endl;
	}
	return 0;
}


