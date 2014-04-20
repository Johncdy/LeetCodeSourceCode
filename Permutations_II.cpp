#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int> > ans;
        if (num.size() == 0) {
			return ans;
		}
		sort(num.begin(), num.end());
		bool used[num.size()];
		vector<int> item;
		perm(num, used, item, ans);
		
		return ans;
    }

	void perm(vector<int> &num, bool used[], vector<int> &item, vector<vector<int> > &res) {
		if (item.size() == num.size()) {
			res.push_back(item);
			return;
		}
		for (int i = 0; i < num.size(); i++) {
			if (i > 0 && !used[i-1] && (num[i] == num[i-1])) {
				continue;
			}
			if (!used[i]) {
				used[i] = true;
				item.push_back(num[i]);
				perm(num, used, item, res);
				item.pop_back();
				used[i] = false;
			}
		}
	}
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(2);
	vector<vector<int> > t = s->permuteUnique(num);
	
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < t[i].size(); j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
}