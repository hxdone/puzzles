// map solution by hxdone

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<long, int> nums_map;
        for (int i = 0; i < nums.size(); ++i)
            nums_map[nums[i]]++;
        vector<vector<int>> ret;
        for (auto iter = nums_map.begin();iter != nums_map.end(); ++iter) {
            for (auto iter2 = iter; iter2 != nums_map.end(); ++iter2) {
                if (iter2 == iter && iter->second < 2)
                    continue;
                long remain = 0-(iter->first)-(iter2->first);
                if (remain < iter2->first)
                    continue;
                auto iter3 = nums_map.find(remain);
                if (iter3 != nums_map.end()) {
                    int remain_cnt = iter3->second;
                    if (iter->first == remain) --remain_cnt;
                    if (iter2->first == remain) -- remain_cnt;
                    if (remain_cnt > 0) {
                        vector<int> tuple;
                        tuple.push_back(iter->first);
                        tuple.push_back(iter2->first);
                        tuple.push_back(iter3->first);
                        ret.push_back(tuple);
                    }
                }
            }
        }
        return ret;
    }
}; 
