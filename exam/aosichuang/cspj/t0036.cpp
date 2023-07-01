#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int l[26];
	string x;
	int cnt = 0;

	for (int i = 0; i < 26; i++) {
		l[i] = 0;
	}

	while (std::getline(std::cin, x)) {
		if (x.empty()) {
			break;
		}

		transform(x.begin(), x.end(), x.begin(), ::toupper);
		if (l[x[0] - 'A'] == 0) {
			cnt++;
		}
		l[x[0] - 'A'] += 1;
	}

	cout << cnt << endl;
	for (int i = 0; i < 26; i++) {
		if (l[i] != 0) {
			//cout << 'A' + i << " " << l[i] << endl;
			printf("%c %d\n", 'A' + i, l[i]);
		}
	}

}