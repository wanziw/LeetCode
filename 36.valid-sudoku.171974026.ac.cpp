class Solution {
public:
    bool checkCol(vector<vector<char>>& board, int row, int col) {
	int times = 0;
	for(int i = 0; i < 9; i++) {
	    if(board[i][col] == board[row][col])
		times++;
	}
	if(times >= 2) return false;
	else return true;
    }

    bool checkRow(vector<vector<char>>& board, int row, int col) {
	int times = 0;
	for(int i = 0; i < 9; i++) {
	    if(board[row][i] == board[row][col])
		times++;
	}
	if(times >= 2) return false;
	else return true;
    }

    bool checkSquare(vector<vector<char>>& board, int row, int col) {
	int times = 0;
	int r = (row / 3) * 3;
	int c = (col / 3) * 3;
	for(int i = 0; i < 3; i++) {
	    for(int j = 0; j < 3; j++) {
		if(board[r + i][c + j] == board[row][col])
		    times++;
	    }
	}
	if(times >= 2) return false;
	else return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
	for(int i = 0; i < 9; i++) {
	    for(int j = 0; j < 9; j++) {
		if(board[i][j] != '.') {
		    bool r1 = checkCol(board, i, j);
		    bool r2 = checkRow(board, i, j);
		    bool r3 = checkSquare(board, i, j);

		    if(!(r1 && r2 && r3)) return false;
		}
	    }
	}
        
	return true;
    }
};
