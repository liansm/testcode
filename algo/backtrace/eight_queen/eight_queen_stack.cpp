#include <vector>
#include <iostream>

bool IsConflict(int r, int r_val, int j, int j_val)
{
	if (r_val == j_val) {
		return true;
	}
	if (j - r == j_val - r_val || j - r == r_val - j_val) {
		return true;
	}
	return false;
}

bool CanPut(int row, int value, std::vector<int>& curQueens)
{
	int queenSize = (int)curQueens.size();
	for (int j = 0; j < queenSize; ++j) {
		if (IsConflict(row, value, j + 1, curQueens[j])) {
			return false;
		}
	}
	return true;
}


void PrintQueens(std::vector<int>& curQueens, int totalSolution)
{
	int queenSize = (int)curQueens.size();
	std::cout << "[" << totalSolution << "]";
	for (size_t i = 0; i < queenSize; ++i) {
		std::cout << curQueens[i] << "\t";
	}
	std::cout << "\n";
}

int main()
{
	int maxQueenSize = 8;
	int totalSolution = 0;
	int start_index = 1;
	std::vector<int> curQueens;
	bool need_backtrace = true;

	while (!curQueens.empty() || start_index <= maxQueenSize) {
		int curQueenSize = (int)curQueens.size();
		need_backtrace = true;
		for (int i = start_index; i <= maxQueenSize; ++i) {
			if (CanPut(curQueenSize + 1, i, curQueens)) {
				curQueens.push_back(i);
				need_backtrace = false;
				break;
			}
		}
		if (curQueens.size() == maxQueenSize) {
			totalSolution++;
			PrintQueens(curQueens, totalSolution);
			need_backtrace = true;
		}

		if (need_backtrace == true) {
			start_index = curQueens[curQueens.size() - 1] + 1;
			curQueens.pop_back();
		}	
		else {
			start_index = 1;
		}
	}
}
