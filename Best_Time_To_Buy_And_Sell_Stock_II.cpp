#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
			return 0;
		}
		
		int res = 0;
		int profit = 0;
		for (int i = 1; i < prices.size(); i++) {
			profit = prices[i] - prices[i-1];
			res = res + (profit > 0 ? profit : 0);
		}
		
		return res;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	vector<int> p;
	p.push_back(-2);
	p.push_back(1);
	p.push_back(3);
	p.push_back(2);
	p.push_back(1);
	p.push_back(3);
	cout << s->maxProfit(p) << endl;
}