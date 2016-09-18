#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
		int r = height.size() - 1;
		int max = 0, result = 0;
		while (l < r) {
			result = (r-l) * min(height[l], height[r]);
			if (result > max) {
				max = result;
			}
			if (height[l] > height[r]) {
				r--;
			} else {
				l++;
			}
		}
		return max;
    }
};

int main(int argc, char *argv[]) {
	Solution* s;
	vector<int> test;
	test.push_back(4);
	test.push_back(2);
	test.push_back(7);
	test.push_back(9);
	test.push_back(1);
	test.push_back(12);
	printf("maxArea: %d", s->maxArea(test));
}