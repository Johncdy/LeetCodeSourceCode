#include <iostream>
#include <unordered_map>

using namespace std;

//
// Created by John on 2022/3/13.
//

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map1 = {};
        unordered_map<char, int> map2 = {};
        for (int i = 97; i < 123; i++)
        {
            map1.insert({i-'0', 0});
            map2.insert({i-'0', 0});
        }
        for (int i = 0; i < magazine.length(); ++i) {
            map2[magazine[i]] = map2[magazine[i]] + 1;
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            map1[ransomNote[i]] = map1[ransomNote[i]] + 1;
        }
        for (pair<char, int> kv:map1) {
            if (kv.second > map2[kv.first]) return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution;
    cout << s->canConstruct("aa", "aab") << endl;
}