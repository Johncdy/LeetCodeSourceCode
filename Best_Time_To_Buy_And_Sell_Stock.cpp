#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
			return 0;
		}
		
		int local = 0;
		int global = 0;
		for (int i = 0; i < prices.size()-1; i++) {
			local = max(0, local+prices[i+1]-prices[i]);
			global = max(local, global);
		}
		
		return global;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	vector<int> p;
	p.push_back(2);
	p.push_back(1);
//	p.push_back(-3);
//	p.push_back(4);
//	p.push_back(-1);
//	p.push_back(2);
//	p.push_back(1);
//	p.push_back(-5);
//	p.push_back(4);
	cout << s->maxProfit(p) << endl;
}