class Solution {
    public:
	bool sudokuSolver(vector<vector<char>>& board, int row, int col) {
	    if(row == 9) return true;
	    if(col == 9) return sudokuSolver(board, row + 1, 0);

	    if(board[row][col] == '.') {
		for(int k = 1; k <= 9; k++) {
		    board[row][col] = '0' + k;
		    if(checkCol(board, row, col) && checkRow(board, row, col) && 
		       checkSquare(board, row, col) && sudokuSolver(board, row, col + 1))
			return true;
		    board[row][col] = '.';
		}
	    }else{
		return sudokuSolver(board, row, col + 1);
	    }

	    return false;
	}

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

	void solveSudoku(vector<vector<char>>& board) {
	    sudokuSolver(board, 0, 0);
	}
};
