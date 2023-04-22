#include <iostream>
#include <string>

void keyboard_hero()
{
	std::string input_str;
	std::cin >> input_str;

	char keyboard_region[][9] = {{'`', '1', 'Q', 'A', 'Z'}, {'2', 'W', 'S', 'X'}, {'3', 'E', 'D', 'C'}, {'4', 'R', 'F', 'V', '5', 'T', 'G', 'B'},
		{'6', 'Y', 'H', 'N', '7', 'U', 'J', 'M'}, {'8', 'I', 'K', ','}, {'9', 'O', 'L', '.'}, {'0', 'P', ';', '/', '-', '[', '\'', '=', ']'}};

	int hit_count[8] = {0};

	for (size_t i = 0; i < input_str.size(); ++i) {
		char c = input_str[i];

		for (int j = 0; j < 8; ++j) {
			for (int k = 0; k < sizeof(keyboard_region[j]) / sizeof(char); ++k) {
				if (keyboard_region[j][k] == c) {					
					hit_count[j]++;
					continue;
				}
			}

		}
	}
	
	for (size_t i = 0; i < 8; ++i) {
		std::cout << hit_count[i] << std::endl;
	}
}

int main()
{
	keyboard_hero();
	return 0;
}

