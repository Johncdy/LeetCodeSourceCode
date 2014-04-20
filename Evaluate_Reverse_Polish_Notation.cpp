#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
  		stack<int> s;
		for (int i = 0; i < tokens.size(); i++) {
			int res = 0;
			if (tokens[i].length() == 1 && (tokens[i][0] > '9' || tokens[i][0] < '0')) {
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				if (tokens[i][0] == '+') {
					res = b + a;
				} else if (tokens[i][0] == '-') {
					res = b - a;
				} else if (tokens[i][0] == '*') {
					res = b * a;
				} else {
					res = b / a;
				}
			} else {
				for (int j = 0; j < tokens[i].length(); j++) {
					if (tokens[i][j] >= '0' && tokens[i][j] <= '9') {
						res = res * 10 + (tokens[i][j] - '0');
					}
				}
				if (tokens[i][0] == '-') {
					res = -res;
				}
			}
			s.push(res);
		}
		return s.top();
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	vector<string> t;
	t.push_back("3");
	t.push_back("-4");
	t.push_back("+");
//	t.push_back("/");
//	t.push_back("+");
	cout << s->evalRPN(t) << endl;
}