//
// Created by John on 2022/3/13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> cnt;
        for (int i = 1; i < n+1; ++i) {
            int a = i % 3, b = i % 5;
            if (a == 0 && b == 0) cnt.push_back("FizzBuzz");
            else if (a == 0) cnt.push_back("Fizz");
            else if (b == 0) cnt.push_back("Buzz");
            else cnt.push_back(to_string(i));
        }
        return cnt;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution;
    vector<string> cnt = s->fizzBuzz(15);
    for (int i = 0; i < cnt.size(); ++i) {
        cout << cnt[i] << " ";
    }
}