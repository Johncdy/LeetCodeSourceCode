#include <iostream>

using namespace std;


    bool isPalindrome(int x) {
        if (x < 0) { return false; }

		int lownum = 1, highnum = 1, temp = x, count = 0;
		while (temp) {
			count++;
			temp /= 10;
			if (temp) {
				highnum *= 10;
			}
		}
		
		for (int i = 0; i < count/2; i++) {
			int low = (x / lownum) % 10;
			int high = (x / highnum) % 10;
			if (low != high) { return false; }
			
			lownum *= 10;
			highnum /= 10;
		}
		
		return true;
    };

int main(int argc, char *argv[]) {
	bool IsTest = isPalindrome(10);
	cout << IsTest << endl;
}