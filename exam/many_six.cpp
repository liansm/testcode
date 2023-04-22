#include <iostream>
#include <vector>

bool is_match(std::string& sub_str)
{
	int val = atoi(sub_str.c_str());
	return val != 0 && val % 6 == 0;
}

int main()
{
	std::string n;
	std::cin >> n;
	int count = 0;
	for (size_t i = 0; i < n.size(); ++i) {
		std::string sub_str;
		sub_str.push_back((n[i]));
		if (is_match(sub_str)) {
			count++;
		}
		
		for (int j = i+1; j < n.size(); ++j) {
			sub_str.push_back(n[j]);
			if (is_match(sub_str)) {
				count++;
			}
		}
	}
	std::cout << count;
	return 0;
}


