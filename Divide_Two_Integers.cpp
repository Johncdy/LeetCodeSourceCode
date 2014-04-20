#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:


//	long long mult(long long p, long long num) {  
//		if (p == 0) {  
//        	return 0;  
//	    }  
//        long long temp = add(p >> 1, num) << 1;  
//        if ((p & 1) != 0) {  
//            temp += num;  
//        }  
//        return temp;  
//    } 

    int divide(int dividend, int divisor) {
        long long a = abs((double)dividend);
		long long b = abs((double)divisor);
		long long res = 0;
		
		while (a >= b) {
			long long c = b;
			for (int i = 0; a >= c; i++, c <<= 1) {
				a -= c;
				res += 1<<i;
			}
		}
		
		return ((dividend ^ divisor) >> 31) ? -res : res;
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	cout << s->divide(-1, 1) << endl;
}