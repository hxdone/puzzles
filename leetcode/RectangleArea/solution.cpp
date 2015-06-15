// add by huangxiaodong

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area_1 = (C-A)*(D-B);
		int area_2 = (G-E)*(H-F);
		int joint_area = std::max(0, std::min(C,G)-std::max(A,E)) * std::max(0, std::min(D,H)-std::max(B,F));
		return area_1 + area_2 - joint_area;
	}
};
