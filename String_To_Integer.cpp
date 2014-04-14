#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
  		if (str == NULL) {
			return 0;
		}
		
		int i = 0;
		while (str[i] != '\0' && str[i] == ' ') {
			i++;
		}
		
		int signal = 1;
		if (str[i] == '+') {
			signal = 1;
			i++;
		} else if (str[i] == '-') {
			signal = -1;
			i++;
		}
		
		int MAX = 0x7fffffff;
		int MIN = 0x80000000;
		
		long long sum = 0;
		while (str[i] != '\0') {
			if (str[i] >= '0' && str[i] <= '9') {
				sum = sum * 10 + signal * (str[i] - '0');
			} else {
				return sum;
			}
			
			if (sum > MAX || sum < MIN) {
				return sum > 0 ? MAX : MIN;
			}
			i++;
		}
		return sum;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	cout << s->atoi("12314") << endl;
}