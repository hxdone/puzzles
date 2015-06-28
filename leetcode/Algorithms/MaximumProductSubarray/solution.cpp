// O(n) solution by hxdone

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_minus_product_adj = min(0,nums[0]);
        int max_product_adj = nums[0];
        int max_product = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int last_max_adj = max_product_adj;
            max_product_adj = max(max_product_adj*nums[i], nums[i]);
            max_product_adj = max(max_product_adj, max_minus_product_adj*nums[i]);

            max_minus_product_adj = min(0, max_minus_product_adj*nums[i]);
            max_minus_product_adj = min(max_minus_product_adj, nums[i]);
            max_minus_product_adj = min(max_minus_product_adj, last_max_adj*nums[i]);
            
            max_product = max(max_product, max_product_adj);
        }
        return max_product;
    }
};
