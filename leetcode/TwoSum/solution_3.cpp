// Solve it with unordered_map.
// author: hxdone

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	typedef unordered_map<int, vector<int>*> kv_map;	
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;

		// add nums to a map
		kv_map value_map;
		int cnt = nums.size();
		kv_map::iterator iter;
		vector<int>* plist = NULL;
		for (int i = 0; i < cnt; ++i) {
			int v = nums[i];
			iter = value_map.find(v);
			if (iter != value_map.end())
				iter->second->push_back(i);
			else {
				plist = new vector<int>();
				plist->push_back(i);
				value_map.insert(pair<int, vector<int>*>(v, plist));
			}
		}
		// find the diff value in map
		bool found = false;
		for (int i = 0; i < cnt && !found; ++i) {
			int diff = target - nums[i];
			iter = value_map.find(diff);
			if (iter != value_map.end()) {
				int list_len = iter->second->size();
				for (int j = 0; j < list_len; ++j) {
					if ((*(iter->second))[j] != i) {
						ret.push_back(i+1);
						ret.push_back((*(iter->second))[j]+1);
						found = true;
						break;
					}
				}
			}
		}

		// delete vectors in map
		for (iter = value_map.begin(); iter != value_map.end(); ++iter) {
			delete iter->second;
			iter->second = NULL;
		}

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
