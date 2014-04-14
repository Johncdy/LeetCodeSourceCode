#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
  		if (m < 0 || n < 0) {
			return 0;
		}
		
//		vector<vector<int> > res;
//		res.resize(m, vector<int>(n));
//		
//		for (int i = 0; i < m; i++) {
//			res[i][0] = 1;
//		}
//		for (int j = 0; j < n; j++) {
//			res[0][j] = 1;
//		}
//		
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				res[i][j] = res[i-1][j] + res[i][j-1];
//			}
//		}
//		return res[m-1][n-1];

		int *res = new int[n];
//		vector<int> res;
//		res.resize(n, 0);
		res[0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 1; j < n; j++) {
				res[j] += res[j-1];
			}
		}
		return res[n-1];
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	cout << s->uniquePaths(20, 20) << endl;
	cout << s->uniquePaths(20, 20) << endl;
	cout << s->uniquePaths(1, 10) << endl;
}