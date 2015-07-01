// map-solution by hxdone

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        int sum = nums[0]+nums[1]+nums[2];
        map<long, int> nums_map;
        for (int i = 0; i < nums.size(); ++i)
            nums_map[nums[i]]++;
        for (auto iter = nums_map.begin(); iter != nums_map.end(); ++iter)
            for (auto iter2 = iter; iter2 != nums_map.end(); ++iter2) {
                if (iter2 == iter && iter2->second < 2)
                    continue;
                long remain = target-(iter->first)-(iter2->first);
                auto iter3 = nums_map.lower_bound(remain);
                if (iter3 != nums_map.begin()) {
                    --iter3;
                    long num3 = iter3->first;
                    int cnt = iter3->second;
                    if (iter->first == num3)
                        --cnt;
                    if (iter2->first == num3)
                        --cnt;
                    if (cnt > 0 && abs(remain-num3) < abs(target-sum))
                        sum = num3-remain+target;
                    ++iter3;
                }
                while (iter3 != nums_map.end()) {
                    long num3 = iter3->first;
                    int cnt = iter3->second;
                    if (iter->first == num3)
                        --cnt;
                    if (iter2->first == num3)
                        --cnt;
                    if (cnt <= 0)
                        ++iter3;
                    else {
                        if (abs(remain-num3) < abs(target-sum))
                            sum = num3-remain+target;
                        if (sum == target)
                            return target;
                        break;
                    }
                } 
            }   
        return sum;
};
