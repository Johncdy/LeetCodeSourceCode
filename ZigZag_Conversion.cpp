/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	int len = s.length(), index = 0, flag = -1;
		if (numRows == 1) {
			flag = 0;
		}
		vector<string> v(numRows, "");
		for (int i = 0; i < len; i++) {
			v[index] += s[i];
			if (index == numRows-1 || index == 0) {
				flag = -flag;
			}
			index += flag;
		}
		string res = "";
		for (int i = 0; i < numRows; i++) {
			res += v[i];
		}
//		cout << res << endl;
		return res;
    }
};

int main(int argc, char *argv[]) {
	Solution* s = new Solution;
	s->convert("PAYPALISHIRING", 3);
	s->convert("ABC", 1);
}