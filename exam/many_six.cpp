#include <iostream>
#include <vector>

int main()
{
	std::string n;
	std::cin >> n;
	int count = 0;
	for (size_t i = 0; i < n.size(); ++i) {
		int sum = 0;
		int cur_val = n[i] - '0';
		if (cur_val % 6 == 0) {
			count ++;
		}
		sum += cur_val;
		for (int j = i + 1; j < n.size(); ++j) {
			cur_val = n[j] - '0';
			sum += cur_val;
			if (cur_val % 2 == 0 && sum % 3 == 0) {
				count++;
			}

		}
	}
	std::cout << count;
	return 0;
}
