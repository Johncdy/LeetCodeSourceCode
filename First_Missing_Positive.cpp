/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
    	if (A == NULL || n == 0) {
    		return 1;
    	}
    	
        for (int i = 0; i < n; i++) {
        	while (A[i] != i+1 && A[i] > 0 && A[i] < n && A[i] != A[A[i]-1]) {
        		swap(A[i], A[A[i]-1]);
        	}	
        }
        
        for (int i = 0; i < n; i++) {
        	if (A[i] != i + 1) {
				return i + 1; 
			} 
        }
        return n+1;
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	int a[] = {1, 2, 0};
	int b[] = {3, 4, -1, 1};
	int c[] = {1, 1};
	int d[] = {-1,4,2,1,9,10};
	cout << s.firstMissingPositive(a, 3) << endl;
	cout << s.firstMissingPositive(b, 4) << endl;
	cout << s.firstMissingPositive(c, 2) << endl; 
	cout << s.firstMissingPositive(d, 6) << endl; 
} 
