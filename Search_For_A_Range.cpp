#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
  		int leftPos = binarySearch(A, 0, n-1, target, true);
		int rightPos = binarySearch(A, 0, n-1, target, false);
		
		vector<int> res;
		res.push_back(leftPos);
		res.push_back(rightPos);
		
		return res;
    }

	int binarySearch(int a[], int l, int r, int target, bool isLeft) {
		if (l > r) {
			return -1;
		}
		int mid = (r+l)/2;
		if (a[mid] == target) {
			int pos = isLeft ? binarySearch(a, l, mid-1, target, isLeft) : binarySearch(a, mid+1, r, target, isLeft);
			return pos == -1 ? mid : pos;
		} else if (a[mid] > target) {
			return binarySearch(a, l, mid-1, target, isLeft);
		} else {
			return binarySearch(a, mid+1, r, target, isLeft);
		}
	}
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	int a[] = {5, 7, 7, 8, 8, 10};
	vector<int> res = s->searchRange(a, 6, 8);
}