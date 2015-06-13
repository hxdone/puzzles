// Solve it with unordered_map and a successor array.
// author: hxdone

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	typedef unordered_map<int, int> kv_map; // value is an index
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		int cnt = nums.size();
		int* next = new int[cnt]; // an array to record the successors
		for (int i = 0; i < cnt; ++i) {
			next[i] = -1;
		}

		// add nums to a hash table
		kv_map value_map;
		kv_map::iterator iter;
		for (int i = 0; i < cnt; ++i) {
			int v = nums[i];
			iter = value_map.find(v);
			if (iter == value_map.end()) {
				value_map.insert(pair<int, int>(v, i));
			}
			else {
				int j = iter->second;
				while (next[j] != -1)
					j = next[j];
				next[j] = i;
			}
		}
		// find the diff value in hash table
		bool found = false;
		for (int i = 0; i < cnt && !found; ++i) {
			int diff = target - nums[i];
			iter = value_map.find(diff);
			if (iter != value_map.end()) {
				for (int j = iter->second; j != -1; j = next[j]) {
					if (j != i) {
						ret.push_back(i+1);
						ret.push_back(j+1);
						found = true;
						break;
					}
				}
			}
		}
		delete[] next;
		return ret;
	}

};

int main() {
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(0);
	int target = 7;

	cout << "[";
	for(int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ", ";
	cout << "] => " << target << endl;

	vector<int> result = Solution().twoSum(nums, target);
	for(int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
