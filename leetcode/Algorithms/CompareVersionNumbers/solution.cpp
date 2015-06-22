// by hxdone

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.length() || j < version2.length()) {
            int b1 = i, b2 = j;
            for (;i < version1.length() && version1[i] != '.'; ++i);
            string nums1 = version1.substr(b1, i-b1);
            if (i < version1.length())
                ++i;
            for (;j < version2.length() && version2[j] != '.'; ++j);
            string nums2 = version2.substr(b2, j-b2);
            if (j < version2.length())
                ++j;
            int v1 = 0, v2 = 0;
            for (int k = 0; k < nums1.length(); ++k)
                v1 = v1*10 + (nums1[k]-'0');
            for (int k = 0; k < nums2.length(); ++k)
                v2 = v2*10 + (nums2[k]-'0');
            if (v1 == v2) continue;
            else
                return (v1 > v2) ? 1 : -1;
        }
        return 0;
    }
};
