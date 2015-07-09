#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, int> tmps;
		map<string, int>::iterator it;
		vector<string> vec;
		for (int i = 0; i < strs.size(); i++) {
			string s = strs[i];
			sort(s.begin(), s.end());
			it = tmps.find(s);
			if (it == tmps.end()) {
				tmps[s] = i;
			} else {
				if (tmps[s] == -1) {
					vec.push_back(strs[i]);
				} else {
					vec.push_back(strs[tmps[s]]);
					tmps[s] = -1;
					vec.push_back(strs[i]);
				}
			}
		}
		return vec;
    }
};

class A {
public:
	 explicit A(int n) {
		s = n;
	}
	
private:
	int s;
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
}