#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string expand(string s, int p1, int p2) {
		int len = s.length();
		while (p1 > -1 && p2 < len && s[p1] == s[p2]) {
			p1--;
			p2++;
		}
		return s.substr(p1+1, p2-p1-1);
	}
	
    string longestPalindrome(string s) {
		string longest_substr = "";
		for (int i = 0; i < s.length(); i++) {
			string str = expand(s, i, i);
			if (str.length() > longest_substr.length()) {
				longest_substr = str;
			}
			
			str = expand(s, i, i+1);
			if (str.length() > longest_substr.length()) {
				longest_substr = str;
			}
		}
		return longest_substr;
    }

//	string longestPalindrome(string s) {
//		int len = s.size();
//		int max_val = 0, pos = 0;
//		
//		vector<int> last_row(len);
//		last_row.assign(len, 0);
//		vector<int> cur_row(len);
//		
//		for (int i = 0; i < len; i++) {
//			string s_char = s.substr(len-i-1, 1);
//			cur_row.assign(len, 0);
//			for (int j = 0; j < len; j++) {
//				if (s_char == s.substr(j, 1)) {
//					cur_row[j] = j > 0 ? last_row[j-1] + 1 : 1;
//					if (cur_row[j] > max_val) {
//						max_val = cur_row[j];
//						pos = j;
//					}
//				} else {
//					cur_row[j] = 0;
//				}
//			}
//			last_row = cur_row;
//		}
//		return s.substr(pos-max_val+1, max_val);
//	}
};

int main(int argc, char *argv[]) {
	Solution* s = new Solution;
//	string str = "aa";
	string str = "abcdedcbaabbdd";
//	string str = "ccabba";
	cout << s->longestPalindrome(str) << endl;
}