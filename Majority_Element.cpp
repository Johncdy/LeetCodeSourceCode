#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
//	int majorityElement(vector<int> &nums) {
//		map<int, int> m;
//		for (int i = 0; i < nums.size(); i++) {
//			if (m.find(nums[i]) == m.end()) {
//				m[nums[i]] = 1;
//			} else {
//				m[nums[i]]++;
//			}
//			if (m[nums[i]] > nums.size()/2) {
//				return nums[i];
//			}
//		}
//		return 0;
//	}
	
	int majorityElement(vector<int> &nums) {
		int majority;
		int cnt = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (cnt == 0) {
				majority = nums[i];
				cnt++;
			} else {
				majority == nums[i] ? cnt++ : cnt--;
				if (cnt > nums.size()/2) {
					return majority;
				}
			}
		}
		return majority;
	}
};

int main(int argc, char *argv[]) {
	Solution* s = new Solution;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v.push_back(3);
	v.push_back(9);
	v.push_back(9);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
		
	cout << s->majorityElement(v) << endl;
}