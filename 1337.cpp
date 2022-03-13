//
// Created by John on 2022/3/13.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> a;
        for (int i = 0; i < mat.size(); ++i) {
            vector<int> v = mat[i];
            int t = 0;
            for (int j = 0; j < v.size(); ++j) {
                t += v[j];
            }
            a.emplace_back(t, i);
        }

        vector<int> v;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution;
    vector<vector<int>> mat = {
            {1,1,0,0,0},
            {1,1,1,1,0},
            {1,0,0,0,0},
            {1,1,0,0,0},
            {1,1,1,1,1}
    };
    vector<int> v = s->kWeakestRows(mat, 3);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
}