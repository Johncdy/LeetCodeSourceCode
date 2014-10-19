/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
    	int lt = 0, rt = num.size()-1;
    	if (num[lt] > num[rt]) {
    		while(lt != rt-1) {
    			int mid = (lt+rt)/2;
    			if (num[mid] < num[lt]) {
    				rt = mid;
    			} else {
    				lt = mid;
    			}
    		}
    		return min(num[lt], num[rt]);
    	}
        return num[0];
    }
};

int main(int argc, char *argv[])
{
	Solution *s = new Solution;
	vector<int> num;
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	num.push_back(1);
	num.push_back(2);
	cout << s->findMin(num) << endl;
	return 0;
}