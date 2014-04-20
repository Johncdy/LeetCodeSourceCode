#include <iostream>

using namespace std;

void reverse(string &s, int begin, int end) {
	while (begin < end) {
		char tmp = s[begin];
		s[begin++] = s[end];
		s[end--] = tmp;
	}
}

class Solution {
public:
    void reverseWords(string &s) {
		int len = s.length();
		string str = "";
        for (int i = len-1; i >= 0; i--) {
			while (s[i] == ' ' && i >= 0) {
				i--;
			}
			if (i < 0) {
				break;
			}
			if (str != "") {
				str += ' ';
			}
			string tmp;
			while (s[i] != ' ' && i >= 0) {
				tmp += s[i];
				i--;
			}
			reverse(tmp, 0, tmp.length()-1);
			str += tmp;	
		}
		s = str;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	string str = "   a   ";
	s->reverseWords(str);
}