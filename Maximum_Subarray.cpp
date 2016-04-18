#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
//    int maxSubArray(int A[], int n) {
//        if (A == NULL || n == 0) {
//			return 0;
//		}
//		
//		int local = A[0];
//		int global = A[0];
//		for (int i = 1; i < n; i++) {
//			local = max(A[i], local+A[i]);
//			global = max(local, global);
//		}
//		
//		return global;
//    }

	int maxRec(int a[], int left, int right)
	{
		if (left == right) {
			if (a[left] > 0) {
				return a[left];
			} else {
				return 0;
			}
		}
		
		int center = (left + right) / 2;
		int maxLeftSum = maxRec(a, left, center);
		int maxRightSum = maxRec(a, center+1, right);
		int leftBoardSum = 0, rightBoardSum = 0, maxLeftBoardSum = 0, maxRightBoardSum = 0;
		for (int i = center; i >= left; i--) {
			leftBoardSum += a[i];
			if (leftBoardSum > maxLeftBoardSum) {
				maxLeftBoardSum = leftBoardSum;
			}
		}
		for (int i = center+1; i <= right; i++) {
			rightBoardSum += a[i];
			if (rightBoardSum > maxRightBoardSum) {
				maxRightBoardSum = rightBoardSum;
			}
		}
		return max3(maxLeftSum, maxRightSum, maxLeftBoardSum + maxRightBoardSum);
	}
	
	int max3(int a, int b, int c)
	{
		return max(a, max(b, c));
	}

	int maxSubArray(int A[], int n) {
		return maxRec(A, 0, n-1);
	}
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	cout << s->maxSubArray(a, 9) << endl;
}