// DP solution by hxdone

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == 0 || len2 == 0)
            return len1+len2;
        int** memo = new int*[len1+1];
        for (int i = 0; i < len1; ++i) {
            memo[i] = new int[len2+1];
            for (int j = 0 ; j < len2; ++j)
                memo[i][j] = -1;
            memo[i][len2] = len1-i;
        }
        memo[len1] = new int[len2+1];
        for (int j = 0; j <= len2; ++j)
            memo[len1][j] = len2-j;
        
        int ret = minDistance(word1, 0, word2, 0, memo);
        for (int i = 0; i <= len1; ++i)
            delete[] memo[i];
        delete[] memo;
        return ret;
    }
    
    int minDistance(const string& word1, int start1, const string& word2, int start2, int** memo) {
        if (memo[start1][start2] != -1)
            return memo[start1][start2];
        if (word1[start1] == word2[start2])
            return minDistance(word1, start1+1, word2, start2+1, memo);
        else {
            int min_distance = 1 + min(minDistance(word1, start1+1, word2, start2, memo),
                                        minDistance(word1, start1, word2, start2+1, memo));
            min_distance = min(min_distance, 1+minDistance(word1, start1+1, word2, start2+1, memo));
            memo[start1][start2] = min_distance;
            return min_distance;
        }
    }
};
