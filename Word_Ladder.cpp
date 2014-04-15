#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> que;
		unordered_set<string> visited;
		que.push(start);
		int depth = 1;
		int cur = 0;
		int last = 1;
		visited.insert(start);
		while (!que.empty()) {
			string str = que.front();
			que.pop();
			last--;
			for (int i = 0; i < str.size(); i++) {
				string tmp = str;
				for (int j = 0; j < 26; j++) {
					tmp[i] = 'a'+j;
					if (tmp == end) {
						return depth+1;
					}
					if (dict.find(tmp) != dict.end() && visited.find(tmp) == visited.end()) {
						cur++;
						que.push(tmp);
						visited.insert(tmp);
					}
				}
			}
			if (last == 0) {
				last = cur;
				cur = 0;
				depth++;
			}
		}
		return 0;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	string start = "hit";
	string end = "cog";
	cout << s->ladderLength(start, end, dict) << endl;;
}