// O(n^2) solution by hxdone

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> ret;
        if (buildings.size() == 0)
            return ret;
        
        list<pair<int,int>> skyline_list;
        int left = buildings[0][0], right = buildings[0][1], height = buildings[0][2];
        skyline_list.push_back(pair<int, int>(left, height));
        skyline_list.push_back(pair<int, int>(right, 0));
        
        int num = buildings.size();
        for (int i = 1; i < num; ++i) {
            left = buildings[i][0];
            right = buildings[i][1];
            height = buildings[i][2];
            int skyline_left, skyline_height = 0, skyline_right = INT_MAX;
            auto iter = skyline_list.rbegin();
            for (; iter != skyline_list.rend(); ++iter, skyline_right=skyline_left) {
                skyline_left = iter->first;
                skyline_height = iter->second;
                if (height > skyline_height) {
                    if (left <= skyline_left) {
                        if (right <= skyline_left) {
                            continue;
                        } else if (right < skyline_right) { // split into two pieces
                            iter->second = height;
                            skyline_list.insert(iter.base(), pair<int,int>(right, skyline_height));
                        } else {
                            iter->second = height;
                            auto right_iter = iter.base();
                            if (right_iter != skyline_list.end() && right_iter->second == height)
                                skyline_list.erase(right_iter);
                        }
                    } else { // left > skyline_left
                        if (right < skyline_right) {
                            auto tmp_iter = skyline_list.insert(iter.base(), pair<int, int>(right, skyline_height));
                            skyline_list.insert(tmp_iter, pair<int, int>(left, height));
                        } else { // right >= skyline_right
                            if (left < skyline_right) {
                                auto right_iter = skyline_list.insert(iter.base(), pair<int, int>(left, height));
                                ++right_iter;
                                if (right_iter != skyline_list.end() && right_iter->second == height)
                                    skyline_list.erase(right_iter);
                            }
                        }
                        break;
                    }
                } else if (left >= skyline_left)
                    break;
            }
            if (iter == skyline_list.rend()) {
                auto right_iter = iter.base();
                skyline_list.insert(right_iter, pair<int, int>(left, height));
                if (right_iter->second == height)
                    skyline_list.erase(right_iter);
            }
        }
        
        for (auto iter = skyline_list.begin(); iter != skyline_list.end(); ++iter) {
            if (ret.empty() || iter->second != ret.back().second)
                ret.push_back(*iter);
        }
        if (ret.back().second > 0)
            ret.push_back(pair<int, int>(INT_MAX, 0));
        return ret;
    }
    
};
