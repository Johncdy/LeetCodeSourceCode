#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.size() == 0) {
			return 0;
		}
	
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
        vector<vector<int> > res;
		res.resize(m, vector<int>(n));
		
		int flag = 1;
		for (int i = 0; i < m; i++) {
			if (obstacleGrid[i][0] == 1) {
				flag = 0;
			}
			res[i][0] = flag;
		}
		flag = 1;
		for (int j = 0; j < n; j++) {
			if (obstacleGrid[0][j] == 1) {
				flag = 0;	
			}
			res[0][j] = flag;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 0) {
					res[i][j] = res[i-1][j] + res[i][j-1];
				} else {
					res[i][j] = 0;
				}
			}
		}
		
		return res[m-1][n-1];
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	vector<vector<int> > res;
	res.resize(3, vector<int>(3));
	res[0][0] = 0;
	res[0][1] = 1;
	res[0][2] = 0;
	res[1][0] = 0;
	res[1][1] = 1;
	res[1][2] = 0;
	res[2][0] = 0;
	res[2][1] = 1;
	res[2][2] = 0;
	cout << s->uniquePathsWithObstacles(res) << endl;
}