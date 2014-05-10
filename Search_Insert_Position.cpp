#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (A == NULL || n == 0) {
			return 0;
		}

		int low = 0, high = n-1;

		while(low <= high) {
			int mid = (low+high) / 2;
			if (A[mid] == target)
			{
				return mid;
			} else if (A[mid] > target) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return low;
    }
};

int main(int argc, char *argv[]) {
	int a[] = {1,3,5,6};
	Solution s;
	cout << "EHHEHEHEH " << endl;
	cout << s.searchInsert(a, 4, 2) << endl;
}