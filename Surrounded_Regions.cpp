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
        
    }
    
    void flood_fill(vector<vector<char> > &board, int i, int j) {
    	if (board[i][j] != 'O')
    		return;
    	queue<int> que;
    	int index = i*board[0].size() + j;
    	que.push(index);
    	while (!que.empty()) {
    		index = que.front();
    		int row = index/board[0].size();
    		int col = index%board[0].size();
    		
    		if (row > 0 && board[row-1][col] == 'O' )
    			board[row-1][col] = 'C';
    		if (row < board[0].size()-1 && board[row+1][col] == 'O')
    			board[row+1][col] = 'C';
    		if (col > 0 && board[row][col-1] == 'O')
    			board[row][col-1] = 'C'
    		if (col < board[0])
    		
    		que.pop();
    	}
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	return 0;
}
