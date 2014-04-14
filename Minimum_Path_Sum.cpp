#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0) {
			return 0;
		}
		int m = grid.size();
		int n = grid[0].size();
		
		vector<vector<int> > res;
		res.resize(m, vector<int>(n));
		res[0][0] = grid[0][0];
		
		for (int i = 1; i < m; i++) {
			res[i][0] = res[i-1][0] + grid[i][0];
		}
		for (int j = 1; j < n; j++) {
			res[0][j] = res[0][j-1] + grid[0][j];
		}
		
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				res[i][j] = min(res[i-1][j]+grid[i][j], res[i][j-1]+grid[i][j]);
			}
		}
		
		return res[m-1][n-1];
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
//	vector<vector<int> > vec;
//	vector<int> v1;
//	vec.push_back(v1);
//	v1.push_back(1);
//	v1.push_back(2);
//	vector<int> v2;
//	vec.push_back(v2);
//	v2.push_back(1);
//	v2.push_back(2);
	vector<vector<int> > vec;
	vec.resize(2, vector<int>(2));
	vec[0][0] = 1;
	vec[0][1] = 2;
	vec[1][0] = 1;
	vec[1][1] = 2;
//	cout << "v1 " << v1.size() << endl;
	cout << vec[0].size() << endl;
	cout << s->minPathSum(vec) << endl;
}