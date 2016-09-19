#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		int res = 0, l = 0;
		while (l < s.length()-1) {
			if (toNumber(s[l]) >= toNumber(s[l+1])) {
				res += toNumber(s[l]);
			} else {
				res -= toNumber(s[l]);
			}
			l++;
		}
		res += toNumber(s[l]);
		return res;
    }

	int toNumber(char s) {
		switch (s) {
			case 'I':
				return 1;
				break;
			case 'V':
				return 5;
				break;
			case 'X':
				return 10;
				break;
			case 'L':
				return 50;
				break;
			case 'C':
				return 100;
				break;
			case 'D':
				return 500;
				break;
			case 'M':
				return 1000;
				break;
			default:
				return 0;
				break;
		}
	}
};

int main(int argc, char *argv[]) {
	Solution *s;
	printf("Int :%d\n", s->romanToInt("MMMDCCXXVI"));
}