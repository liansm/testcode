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


void Backtrace(std::vector<int>& curQueens, int maxQueenSize, int& totalSolution)
{
	int queenSize = (int)curQueens.size();
	for (int i = 1; i <= maxQueenSize; i++) {
		if (CanPut(queenSize + 1, i, curQueens)) {
			curQueens.push_back(i);
			if (curQueens.size() == maxQueenSize) {
				++totalSolution;
				//PrintQueens(curQueens, totalSolution);
			}
			Backtrace(curQueens, maxQueenSize, totalSolution);
		}
	}
	if(!curQueens.empty()) curQueens.pop_back();
}



int main()
{
	int maxQueenSize = 14;
	int totalSolution = 0;
	std::vector<int> curQueens;

	Backtrace(curQueens, maxQueenSize, totalSolution);

  std::cout << "total solutions: " << totalSolution << std::endl;
}

