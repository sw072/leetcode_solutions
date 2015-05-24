#include <iostream>
#include <vector>
#include <string.h>
#include <string.h>
using namespace std;

class Solution {
public:
	bool isValidRow(vector<vector<char> >& board) {
		bool mark[10];
		int v = 0;
		for (int r = 0; r < 9; ++r) {
			memset(mark, 0, sizeof(mark));
			for (int c = 0; c < 9; ++c) {
				if (board[r][c] == '.') continue;
				v = board[r][c] - '0';
				if (mark[v]) return false;
				mark[v] = true;
			}
		}
		return true;
	}

	bool isValidCol(vector<vector<char> >& board) {
		bool mark[10];
		int v = 0;
		for (int c = 0; c < 9; ++c) {
			memset(mark, 0, sizeof(mark));
			for (int r = 0; r < 9; ++r) {
				if (board[r][c] == '.') continue;
				v = board[r][c] - '0';
				if (mark[v]) return false;
				mark[v] = true;
			}
		}
		return true;
	}

	bool isValidSquare(vector<vector<char> >& board) {
		bool mark[10];
		int v = 0;
		int row = 0, col = 0;
		for (int idx = 0; idx < 9; ++idx) {
			row = idx / 3;
			col = idx % 3;
			memset(mark, 0, sizeof(mark));
			for (int r = 0; r < 3; ++r) {
				for (int c = 0; c < 3; ++c) {
					if (board[3 * row + r][3 * col + c] == '.') continue;
					v = board[3 * row + r][3 * col + c] - '0';
					if (mark[v]) return false;
					mark[v] = true;
				}
			}
		}
		return true;
	}

    bool isValidSudoku(vector<vector<char> >& board) {
		if (isValidRow(board) && isValidCol(board) && isValidSquare(board)) return true;
		return false;
    }
};

int main() {
	vector<vector<char> >board;
	string str;
	for (int idx = 0; idx < 9; ++idx) {
		cin >> str;
		vector<char> line;
		for (int c = 0; c < 9; ++c) {
			line.push_back(str[c]);
		}
		board.push_back(line);
	}
	Solution s;
	cout << s.isValidSudoku(board) << endl;

	return 0;
}
