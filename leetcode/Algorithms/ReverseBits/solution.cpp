// by hxdone

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t mask = 1;
		uint32_t m = 0;
		for (int i = 0; i < 32; ++i) {
			m |= ((n&mask)>>i)<<(31-i);
			mask <<= 1;
		}
		return m;
	}
};
