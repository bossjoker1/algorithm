// .650
//label为dp，但实际上抽象出来的是素数分解为最少步骤的问题
class Solution {
public:

    int findMax(int n){
        if(n == 1) return 1;
        for(int i = n/2;i > 1;i--){
            if(n%i == 0) return i;
        }
        return 1;
    }

    int minSteps(int n) {
        int sum = 0;
        while(n!=1){
            int d = findMax(n);
            sum += n/d;
            n = d;
        }
        return sum;
    }
};