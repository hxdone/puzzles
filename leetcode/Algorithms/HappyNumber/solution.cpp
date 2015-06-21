// by hxdone

class Solution {
public:
    bool isHappy(int n) {
        set<int> track;
        while(1) {
            if (n == 1)
                return true;
            else if (track.find(n) != track.end())
                return false;
            track.insert(n);
            n = reform(n);
        }
    }
private:
    int reform(int n) {
        int ret = 0;
        while (n) {
            int d = n%10;
            ret += d*d;
            n = n/10;
        }
        return ret;
    }
};
