#include <iostream>
#include <algorithm>
using namespace std;


int m[100][100];
int dp[100][100];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> m[i][j];
		}
	}

	int max_path = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0) {
				dp[i][j] = m[i][j];
			}
			else if (j == 0) {
				dp[i][j] = dp[i - 1][j] + m[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + m[i][j];
			}

			if (dp[i][j] > max_path) {
				max_path = dp[i][j];
			}
		}
	}

	cout << max_path;
	return 0;
}