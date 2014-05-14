/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if (board.size() <= 1 || board[0].size() <= 1)
        	return;
        	
        for (int i = 0; i < board.size(); i++) {
        	flood_fill(board, i, 0); 
        	flood_fill(board, i, board[i].size()-1);
        }
        
        for (int i = 0; i < board[0].size(); i++) {
        	flood_fill(board, 0, i);
        	flood_fill(board, board.size()-1, i);
        }
        
        for (int i = 0; i < board.size(); i++) {
        	for (int j = 0; j < board[i].size(); j++) {
        		if (board[i][j] == 'O')
        			board[i][j] = 'X';
        		else if (board[i][j] == 'C')
        			board[i][j] = 'O';
        	}
        }
    }
    
    void flood_fill(vector<vector<char> > &board, int i, int j) {
    	if (board[i][j] != 'O')
    		return;
    	
    	queue<int> que;
    	int index = i*board[0].size() + j;
    	que.push(index);
    	while (!que.empty()) {
    		index = que.front();
    		que.pop();
    		int row = index/board[0].size();
    		int col = index%board[0].size();
    		
    		board[row][col] = 'C';
    		
    		if (row > 0 && board[row-1][col] == 'O' ) {
    			board[row-1][col] = 'C';
    			que.push((row-1)*board[0].size()+col);
    		}
    		if (row < board.size()-1 && board[row+1][col] == 'O'){
    			board[row+1][col] = 'C';
    			que.push((row+1)*board[0].size()+col);
    		}
    		if (col > 0 && board[row][col-1] == 'O') {
    			board[row][col-1] = 'C';
    			que.push(row*board[0].size()+col-1);
    		}
    		if (col < board[0].size()-1 && board[row][col+1] == 'O') {
    			board[row][col+1] = 'C';
				que.push(row*board[0].size()+col+1);	
    		}
    	}
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<vector<char> > vec;
	for (int i = 0; i < 5; i++) {
		vector<char> v1;	
		v1.push_back('X');
		if (i == 1 || i == 3) {
			v1.push_back('O');
		} else {
			v1.push_back('X');
		}
		if (i == 1 || i == 2) {
			v1.push_back('O');
		} else {
			v1.push_back('X');
		}
		v1.push_back('X');
		vec.push_back(v1);
	}
	
	for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
        	cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
	
	s.solve(vec);
	
	return 0;
}
