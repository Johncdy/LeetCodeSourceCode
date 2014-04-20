#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
		if (len == 0) {
			return 0;
		}
		
		int hash[256];
		memset(hash, -1, sizeof(hash));
		int start = 0, end = 1, maxVal = 1;
		hash[s[0]] = 0;
		
		while (end < len) {
			if (hash[s[end]] >= start) {
				start = hash[s[end]] + 1;
			}
			maxVal = max(maxVal, end-start+1);
			hash[s[end]] = end;
			end++;
		}
		return maxVal;
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
}