#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (A == NULL || n == 0) {
			return 0;
		}
		
		int local = A[0];
		int global = A[0];
		for (int i = 1; i < n; i++) {
			local = max(A[i], local+A[i]);
			global = max(local, global);
		}
		
		return global;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	cout << s->maxSubArray(a, 9) << endl;
}