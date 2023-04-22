//付款金额
//
//
#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> arr;
	int val;
	for (int i = 0; i < n; ++i) {
		std::cin >> val;
		arr.push_back(val);
	}

	int sum = 0;
	for (int i = 0; i < arr.size(); ++i) {
		sum += arr[i];
	}

	int min_val = sum;
	for (int i = 0; i < arr.size(); ++i) {
		int cur_val = arr[i];
		int total_val = sum - cur_val;

		if ((total_val % 2) == 0) {
			if (total_val < min_val) {
				min_val = total_val;
			}
		}
	}

	int avg_val = (int)(((float)min_val/n) + 0.5);
	std::cout << min_val << std::endl;
	std::cout << avg_val << std::endl;
	return 0;
}
