/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0') {
        	return 0;
        } 
        
        int res1 = 1, res2 = 1, res3 = 1;
        for (int i = 1; i < s.length(); i++) {
        	if (s[i] == '0') {
        		if (s[i-1] == '1' || s[i-1] == '2') {
        			res3 = res1; 
        		} else {
        			return 0;
        		}
        	} else {
        		if (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')) {
        			res3 = res1 + res2;
        		} else {
        			res3 = res2;
        		}
        	}
        	res1 = res2;
        	res2 = res3;
        }
        
        return res3;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.numDecodings("26") << endl;
	return 0;
}
