#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
	int pos;
	int val;
};

bool cmp(Node a, Node b)
{
	return a.val < b.val;
}

class Solution {
public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//		map<int, int> hash_map;
//		vector<int> result;
//		
//		for (int i = 0; i < nums.size(); i++) {
//			if (!hash_map.count(nums[i])) {
//				hash_map.insert(pair<int, int>(nums[i], i));
//			}
//			if (hash_map.count(target-nums[i])) {
//				int tmp = hash_map[target-nums[i]];
//				if (tmp != i) {
//					result.push_back(min(i+1, tmp+1));
//					result.push_back(max(i+1, tmp+1));					break;
//				}
//			}
//		}
//		
//		return result;
//    }

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		vector<Node> array;
		for (int i = 0; i < nums.size(); i++) {
			Node tmp;
			tmp.pos =i;
			tmp.val = nums[i];
			array.push_back(tmp);	
		}
		sort(array.begin(), array.end(), cmp);
		int start = 0;
		int end = (array.size()-1);
		while (start != end) {
			int sum = array[start].val + array[end].val;
			if (sum == target) {
				result.push_back(min(array[start].pos+1, array[end].pos+1));
				result.push_back(max(array[start].pos+1, array[end].pos+1));
				break;
			} else if (sum < target) {
				start++;
			} else if (sum > target) {
				end--;
			}
		}
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	vector<int> tmp = s->twoSum(nums, 6);
	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << endl;
	}
	return 0;
}