#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	int index = 0;
		for (int i = 0; i < n-1; i++) {
			if (A[i] != A[i+1]) {
				A[index] = A[i];
				index++;
			}
		}
		if (A[n-1] != A[index-1]) {
			A[index] = A[n-1];
			return index+1;
		} else {
			return index;
		}
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	int a[] = {1, 1, 2, 2, 4};
	cout << s->removeDuplicates(a, 5) << endl;
}