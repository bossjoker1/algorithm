// 无符号运算结果 a ^ b
// 进位结果 (unsigned int) (a & b) << 1 因为所有进位结果作用于高一位
// 所有进位计算完毕，即无进位后，退出得到最终结果


class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1; 
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
