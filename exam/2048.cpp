#include <iostream>

int match2048()
{
	int n;
	std::cin >> n;

	int sum = 0;
	int val = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> val;
		sum += val;
	}

	int total = 1;
	while (total < sum) {
		total *= 2;
	}

	return total / 2;
}

int main()
{
	std::cout << match2048();
	return 0;
}
