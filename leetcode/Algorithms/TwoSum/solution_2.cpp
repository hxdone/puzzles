// Solve it with stl map.
// author: hxdone

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    typedef map<int, int> kv_map; // value is largest element index for key
    vector<int> twoSum(vector<int>& nums, int target) {
        // find the diff value in hash table
        // and add nums to a hash table
        int cnt = nums.size();
        kv_map value_map;
        for (int i = 0; i < cnt; ++i) {
            auto iter = value_map.find(target-nums[i]);
            if (iter != value_map.end())
                return vector<int>({iter->second+1, i+1});
            value_map[nums[i]] = i;
        }
        return vector<int>();
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
