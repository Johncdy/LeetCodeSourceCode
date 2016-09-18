#include <iostream>
#include<assert.h>

using namespace std;

class Solution {
public:
    bool isMatch(std::string a, std::string b) {
		const char *s = a.c_str();
		const char *p = b.c_str();
		assert(s && p);
		if (*p == '\0') {
			return *s == '\0';
		}
		
		if (*(p+1) != '*') {
			if (*s != '\0' && (*s == *p || *p == '.')) {
				return isMatch(s+1, p+1);
			} else {
				return false;
			}
		} else {
			while (*s != '\0' && (*s == *p || *p == '.')) {
				if (isMatch(s, p+2)) {
					return true;
				}
				s++;
			}
			return isMatch(s, p+2);
		}
	}
};

int main(int argc, char *argv[]) {
	Solution *s;
	
//	printf("%d\n", s->isMatch("aa", "a"));
//	printf("%d\n", s->isMatch("aa", "aa"));
//	printf("%d\n", s->isMatch("aaa", "aa"));
//	printf("%d\n", s->isMatch("aa", "a*"));
//	printf("%d\n", s->isMatch("aa", ".*"));
	printf("%d\n", s->isMatch("ab", ".*"));
	
	return 0;
}