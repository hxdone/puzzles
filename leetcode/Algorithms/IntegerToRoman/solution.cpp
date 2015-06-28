// by hxdone

class Solution {
public:
    string intToRoman(int num) {
        // I, V, X, L, C, D, M
        string ret;
        while (num > 0) {
            if (num >= 1000) {
                ret.append("M");
                num -= 1000;
            } else  if (num >= 900) {
                ret.append("CM");
                num -= 900;
            } else if (num >= 500) {
                ret.append("D");
                num -= 500;
            } else if (num >= 400) {
                ret.append("CD");
                num -= 400;
            } else if (num >= 100) {
                ret.append("C");
                num -= 100;
            } else if (num >= 90) {
                ret.append("XC");
                num -= 90;
            } else if (num >= 50) {
                ret.append("L");
                num -= 50;
            } else if (num >= 40) {
                ret.append("XL");
                num -= 40;
            } else if (num >= 10) {
                ret.append("X");
                num -= 10;
            } else if (num == 9) {
                ret.append("IX");
                num -= 9;
            } else if (num >= 5) {
                ret.append("V");
                num -= 5;
            } else if (num == 4) {
                ret.append("IV");
                num -= 4;
            } else {
                ret.append("I");
                num -= 1;
            }
        }
        return ret;
    }
}; 
