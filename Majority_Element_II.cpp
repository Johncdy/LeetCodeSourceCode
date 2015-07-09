#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> m;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			if (m.find(nums[i]) == m.end()) {
				m[nums[i]] = 1;
			} else {
				m[nums[i]]++;
			}
		}
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
			if (it->second > nums.size()/2) {
				result.push_back(it->first);
			}
		}
		return result;
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
	
	vector<int> tmp = s->majorityElement(v);
	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << endl;
	}
}