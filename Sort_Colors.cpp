#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
  		int i = 0;
		int j = n-1;
		int k = n-1;
		while (i <= j) {
			if (A[i] == 2) {
				int tmp = A[k];
				A[k] = A[i];
				A[i] = tmp;
				k--;
				if (k < j) {
					j = k;
				}
			 } else if (A[i] == 1) {
				int t = A[j];
				A[j] = A[i];
				A[i] = t;
				j--;
			} else {
				i++;
			}
		}      
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	int a[1] = {0};
	s.sortColors(a, 1);
}