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

//		int len = s.length();
//		if (len == 0) {
//			return 0;
//		}
		
//		int start = 0, end = 1, maxVal = 1;
//		string str = s.substr(start, 1);
//		while (end < len) {
//			if (str.find(s[end]) == string::npos) {
//				end++;
//				str = s.substr(start, end-start);
//				maxVal = end - start > maxVal ? end - start : maxVal;
//			} else {
//				maxVal = end - start > maxVal ? end - start : maxVal;
//				start = start + 1;
//				end = start + 1;
//				str = s.substr(start, 1);
//			}
//		}
//		return maxVal;
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.lengthOfLongestSubstring("dvdf") << endl;
}