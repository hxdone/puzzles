// O(n) solution by hxdone

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int max_area = 0;
        while (i < j) {
            if (height[i] <= height[j]) {
                max_area = max(max_area, (j-i)*height[i]);
                int k;
                for (k = i+1; k < j && height[k] <= height[i]; ++k);
                i = k;
            } else {
                max_area = max(max_area, (j-i)*height[j]);
                int k;
                for (k = j-1; k > i && height[k] <= height[j]; --k);
                j = k;
            }
        }
        return max_area;
    }
};
