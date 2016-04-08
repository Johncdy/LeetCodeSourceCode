#include <iostream>
#include <vector>

using namespace std;

//#define INT_MIN 0x80000000

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums;
		int m = nums1.size(), n = nums2.size();
		bool guard = m > n ? true : false;
		int i = 0, j = 0;
		while (true) {
			if (i < m && j < n) {
				if (nums1[i] > nums2[j]) {
					nums.push_back(nums2[j]);
					j++;
				} else {
					nums.push_back(nums1[i]);
					i++;
				}	
			} else if (i == m) {
				if (j < n) {
					nums.push_back(nums2[j]);
					j++;
				} else {
					break;
				}
			} else if (j == n) {
				if (i < m) {
					nums.push_back(nums1[i]);
					i++;
				} else {
					break;
				}
			} else {
				break;
			}
		}
		if ((m+n)&1) {
			return nums[(m+n-1)/2];
		} else {
			return (nums[(m+n)/2]+nums[(m+n)/2-1])/2.0;
		}
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	vector<int> v1, v2;
//	v1.push_back(1);
//	v1.push_back(5);
//	v1.push_back(7);
	v2.push_back(2);
	v2.push_back(3);
//	v2.push_back(4);
//	v2.push_back(6);
	cout << s->findMedianSortedArrays(v1, v2) << endl;
}