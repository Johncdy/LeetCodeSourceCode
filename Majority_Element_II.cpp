#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		vector<int> result;
		int m1 = 0, m2 = 0;
		int cnt1 = 0, cnt2 = 0;
		for (auto &a : nums) {
			if (a == m1) {
				cnt1++;
			} else if (a == m2) {
				cnt2++;
			} else if (cnt1 == 0) {
				m1 = a;
				cnt1 = 1;
			} else if (cnt2 == 0) {
				m2 = a;
				cnt2 = 1;
			} else {
				cnt1--;
				cnt2--;
			}
		}
		cnt1 = 0, cnt2 = 0;
		for (auto &a : nums) {
			if (a == m1) {
				cnt1++;
			} else if (a == m2) {
				cnt2++;
			}
		}
		if (cnt1 > nums.size()/3) {
			result.push_back(m1);
		}
		if (cnt2 > nums.size()/3) {
			result.push_back(m2);
		}
		return result;
    }
};

int main(int argc, char *argv[]) {
	Solution* s = new Solution;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	
	vector<int> tmp = s->majorityElement(v);
	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << endl;
	}
}