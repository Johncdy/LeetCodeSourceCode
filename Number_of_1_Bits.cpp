#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
  		uint32_t count;
		for (count = 0; n; count++) {
			n &= n-1;
		}
		return count;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	cout << s->hammingWeight(29) << endl;
	cout << s->hammingWeight(1) << endl;
	cout << s->hammingWeight(0) << endl;
	cout << s->hammingWeight(5) << endl;
	cout << s->hammingWeight(0x11101) << endl;
}