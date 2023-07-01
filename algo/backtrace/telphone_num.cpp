#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution
{
public:
	void travel(string & digits,  size_t cur_index, string & cur_result, vector<string> & result, vector<string> & phoneNumbers)
	{
		if (cur_index == digits.size()) {
			result.push_back(cur_result);
			return;			
		}

		int cur_phone_number = digits[cur_index] - '2';
		string cur_phone_str = phoneNumbers[cur_phone_number];
		for (size_t i = 0; i < cur_phone_str.size(); ++i) {
			cur_result.push_back(cur_phone_str[i]);
			travel(digits, cur_index + 1, cur_result, result, phoneNumbers);
			cur_result.pop_back();
		}
	}


	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.empty()) {
			return result;
		}
		
		string cur_str;
		vector<string> phoneNumbers;

		phoneNumbers.push_back("abc");
		phoneNumbers.push_back("def");
		phoneNumbers.push_back("ghi");
		phoneNumbers.push_back("jkl");
		phoneNumbers.push_back("mno");
		phoneNumbers.push_back("pqrs");
		phoneNumbers.push_back("tuv");
		phoneNumbers.push_back("wxyz");

		travel(digits, 0, cur_str, result, phoneNumbers);
		return result;	
	}

	void printResult(vector<string>& result)
	{
		for (size_t i = 0; i < result.size(); ++i) {
			cout << result[i] << endl;
		}
	}
};


int main()
{
	Solution* s = new Solution();
	string str="23";
	vector<string> result;
	result = s->letterCombinations(str);
	s->printResult(result);

	return 0;
}
