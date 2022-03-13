//
// Created by John on 2022/3/12.
//

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> umap = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };

        int c = 0;
        for (int i = 0; i < s.length()-1; i++)
        {
            if (umap[s[i]] >= umap[s[i+1]]) c += umap[s[i]];
            else c -= umap[s[i]];
        }
        c += umap[s[s.length()-1]];

        return c;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution;
    cout << s->romanToInt("III") << endl;
    cout << s->romanToInt("IV") << endl;
    cout << s->romanToInt("IX") << endl;
    cout << s->romanToInt("LVIII") << endl;
    cout << s->romanToInt("MCMXCIV") << endl;
}