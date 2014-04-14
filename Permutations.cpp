#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
    	ans.clear();
		if (num.size() == 0) {
			return ans;
		}
		perm(num, 0);
		return ans;
    }

	void perm(vector<int> &num, int begin) {
		if (begin == num.size()) {
			ans.push_back(num);
			return;
		} else {
			for (int i = begin; i < num.size(); i++) {
				swap(num[begin], num[i]);
				perm(num, begin+1);
				swap(num[begin], num[i]);
			}
		}
	}

private:
	vector<vector<int> > ans;
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	vector<vector<int> > t = s->permute(num);
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < t[i].size(); j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
}