#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
			return "";
		}
		for (int i = 0; i < strs[0].length(); i++) {
			for (int j = 0; j < strs.size(); j++) {
				if (strs[j].length()-1 < i || strs[j][i] != strs[0][i]) {
					return strs[0].substr(0, i);
				}
			}
		}
		return strs[0];
    }
};

int main(int argc, char *argv[]) {
	Solution *s;
	vector<string> strs;
	strs.push_back("abddcc");
	strs.push_back("abdadaldjf");
	strs.push_back("abcdd");
	printf("%s\n", s->longestCommonPrefix(strs).c_str());
	return 0;
}