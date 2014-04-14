#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
    	const int len1 = word1.size();
		const int len2 = word2.size();
		
		vector<vector<int> > dp(len1+1, vector<int>(len2+1));
		dp[0][0] = 0;
		
		for (int i = 1; i <= len1; i++) {
			dp[i][0] = i;
		}
		
		for (int j = 1; j <=len2; j++) {
			dp[0][j] = j;
		}
		
		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				dp[i][j] = std::min(std::min(dp[i-1][j]+1, dp[i][j-1]+1), 
					dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1));
			}
		}
		
		return dp[len1][len2];
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	cout << s->minDistance("ab", "ab") << endl;
}