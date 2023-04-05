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

bool IsMatch(std::vector<int>& curQueens)
{
	int queenSize = (int)curQueens.size();
	for (int i = 1; i <= queenSize; ++i) {
		for (int j = 1; j <= queenSize; ++j) {
			if (i != j && IsConflict(i, curQueens[i - 1], j, curQueens[j - 1])) {
				return false;
			}
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


void Traverse(std::vector<int>& curQueens, int maxQueenSize, int& totalSolution)
{
	int queenSize = (int)curQueens.size();
	for (int i = 1; i <= maxQueenSize; i++) {
		curQueens.push_back(i);
		if (curQueens.size() == maxQueenSize){
			if(IsMatch(curQueens)){
				++totalSolution;
				PrintQueens(curQueens, totalSolution);
			}		
			curQueens.pop_back();
		}
		else {
			Traverse(curQueens, maxQueenSize, totalSolution);
		}
	}
	if (!curQueens.empty()) curQueens.pop_back();
}



int main()
{
	int maxQueenSize = 10;
	int totalSolution = 0;
	std::vector<int> curQueens;

	Traverse(curQueens, maxQueenSize, totalSolution);
}

