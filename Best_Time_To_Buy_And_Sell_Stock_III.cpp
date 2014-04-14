#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
			return 0;
		}
		
		int local[3];
		int global[3];
		memset(local, 0, sizeof(int)*3);
		memset(global, 0, sizeof(int)*3);
		for (int i = 0; i < prices.size()-1; i++) {
			int diff = prices[i+1] - prices[i];
			for (int j = 2; j >= 1; j--) {
				local[j] = max(local[j]+diff, global[j-1]+(diff > 0 ? diff : 0));
				global[j] = max(local[j], global[j]);
			}
		}
		
		return global[2];
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	vector<int> p;
	p.push_back(0);
	p.push_back(1);
	p.push_back(0);
	p.push_back(2);
	p.push_back(0);
	p.push_back(3);
	cout << s->maxProfit(p) << endl;
}