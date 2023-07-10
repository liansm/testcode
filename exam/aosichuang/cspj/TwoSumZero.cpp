#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void two_num_zero()
{
	int n;
	cin >> n;

	vector<int> arr;
	arr.reserve(n);

	int val;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		arr.push_back(val);
	}

	sort(arr.begin(), arr.end());

	int front = 0;
	int end = arr.size()-1;

	long long total_match = 0;
	while (front < end) {
		if (arr[front] > 0 || arr[end] < 0) {
			break;
		}
		if (arr[front] == 0 && arr[end] == 0) {
			int zero_count = 2;
			while (++front < end && arr[front] == 0) {
				zero_count++;
			}
			total_match += ((zero_count) * (zero_count-1) /2 );
			break;
		}
		else if (-arr[front] == arr[end]) {		
			int neg_count = 1;
			int neg_val = arr[front];
			while (arr[++front] == neg_val) {
				neg_count++;
			}

			int positive_count = 1;
			int positive_val = arr[end];
			while (arr[--end] == positive_val) {
				positive_count++;
			}
			total_match += (neg_count * positive_count);

		}
		else if (-arr[front] < arr[end]) {
			end--;
		}
		else if (-arr[front] > arr[end]) {
			front++;
		}
	}

	cout << total_match;
}

int main()
{
	two_num_zero();
	return 0;
}
