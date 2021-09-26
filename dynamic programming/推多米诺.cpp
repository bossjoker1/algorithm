// 几种状态：
//  1头部的[.]：紧挨着如果是L，全替换，否则不变, 
//  2尾部的[.]:紧挨着如果是R,全替换，否则不变, 
//  3中间的[.]: 
//     3.1如果两头一样，全替换， 
//     3.2两头不一样：左L右R的,不变 
//     3.3左R右L的计算.个数n,前1/2n为R,后1/2为L,最中间整除不了的不变

// 模拟了下
// 执行用时：28 ms, 在所有 C++ 提交中击败了74.80% 的用户
// 内存消耗：12.3 MB, 在所有 C++ 提交中击败了84.55% 的用户
class Solution {
public:

    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int l = 0, r = n-1;
        // 处理状态1
        while(l!=r){
            if(dominoes[l] != '.')
                break;
            l++;
        }
        if(dominoes[l] == 'L'){
            for(int i = 0 ; i < l; i++){
                dominoes[i] = 'L';
            }
        }

        // 处理状态2
        while(r!=l){
            if(dominoes[r] != '.')
                break;
            r--;
        }

        if(dominoes[r] == 'R'){
            for(int i = r; i < n ;i++){
                dominoes[i] = 'R';
            }
        }


        // 处理状态3
        int l_f = l;
        for(int i = l+1; i <= r ; i++){
            if(dominoes[i] != '.'){
                if(dominoes[l_f] == dominoes[i]){
                    for(int k = l_f+1; k < i; k++){
                        dominoes[k] = dominoes[i];
                    }
                }

                if(dominoes[l_f]  == 'L'&& dominoes[i] == 'R'){
                    l_f = i;
                    continue;
                }
                if(dominoes[l_f]  == 'R'&&dominoes[i] == 'L'){
                    for(int k = l_f+1; k <= (i - l_f - 1)/2 + l_f;k++){
                        dominoes[k] = 'R';
                    }
                    for(int k = i - (i - l_f - 1)/2; k <= i ; k++){
                        dominoes[k] = 'L';
                    }
                }
                l_f = i;
            }
        }

        return dominoes;

    }
};