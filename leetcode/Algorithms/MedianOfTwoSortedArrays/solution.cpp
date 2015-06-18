class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int idx_sum = (m+n-1)/2;
		int low = std::max(0, idx_sum-n);
		int high = std::min(m-1, idx_sum+1);
		while (low <= high) {
			int i = (low+high)/2;
			int j = idx_sum-i;
			if (j < 0)
				high = i-1;
			else if (j >= n) {
				if (j-1 < 0 || nums1[i] >= nums2[j-1])
					return (m+n)%2 ? nums1[i] : (nums1[i]+nums1[i+1])/2.0;
				else
					low = i+1;
			} else {
				if (nums1[i] <= nums2[j]) {
					if (j-1 < 0 || nums1[i] >= nums2[j-1]) {
						if ((m+n) % 2 == 1)
							return nums1[i];
						else {
							int up_median = nums2[j];
							if (i+1 < m)
								up_median = std::min(up_median, nums1[i+1]);
							return (nums1[i]+up_median)/2.0;
						}
					} else
						low = i+1;
				} else {
					if (i-1 < 0 || nums2[j] >= nums1[i-1]) {
						if ((m+n) % 2 == 1)
							return nums2[j];
						else {
							int up_median = nums1[i];
							if (j+1 < n)
								up_median = std::min(up_median, nums2[j+1]);
							return (nums2[j]+up_median)/2.0;
						}
					} else
						high = i-1;	
				}
			}
		}
		int k = (low==m) ? idx_sum-m : idx_sum;
		if (k < 0 || k >= n)
			return 0;
		return (m+n)%2 ? nums2[k] : (nums2[k]+nums2[k+1])/2.0; 
	}
};

