#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
	
        string r[4][10] = {
			{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
			{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
			{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
			{"", "M", "MM", "MMM",}
		};
		
		string roman;
		roman.append(r[3][num / 1000 % 10]);
		roman.append(r[2][num / 100 % 10]);
		roman.append(r[1][num / 10 % 10]);
		roman.append(r[0][num % 10]);
		
		return roman;
    }
};

int main(int argc, char *argv[]) {
	Solution *s;
	printf("Roman: %s\n", s->intToRoman(74).c_str());
	printf("Roman: %s\n", s->intToRoman(3726).c_str());
	printf("Roman: %s\n", s->intToRoman(400).c_str());
}