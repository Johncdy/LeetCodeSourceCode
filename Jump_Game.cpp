#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if (A == NULL || n == 0) {
			return false;
		}
		
		int local = 0;
		int global = 0;
		for (int i = 0; i <= global && i < n; i++) {
			global = max(A[i]+i, global);
		}
		
		if (global < n-1) {
			return false;
		} else {
			return true;
		}
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	int a[] = {2,3,1,1,4};
	int b[] = {3,2,1,0,4};
	cout << s->canJump(a, 5) << endl;
	cout << s->canJump(b, 5) << endl;
}