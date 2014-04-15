#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
		string str = "";
		int flag = 1;
  		while (*s != '\0') {
			if (s[0] != ' ') {
				if (!flag) {
					flag = 1;
					str = "";
				}
				str += s[0];
			} else {
				flag = 0;
			}
			s++;
		} 
		return str.length();
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	const char *str = "  a  ";
	cout << s->lengthOfLastWord(str) << endl;
}