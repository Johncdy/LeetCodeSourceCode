#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        const int MAX = 0x7fffffff;
		const int MIN = 0x80000000;
		long long sum = 0;
		
		while (x) {
			int tmp = x % 10;
			sum = sum * 10 + tmp;
			if (sum > MAX || sum < MIN) {
				sum = sum > 0 ? MAX : MIN;
				return sum;
			}
			x /= 10;
		}
		return sum;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	cout << s->reverse(123) << endl;;
	cout << s->reverse(-123) << endl;
}