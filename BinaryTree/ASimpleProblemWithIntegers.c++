//《挑战程序设计竞赛》 P179
// 这题暴力很简单，但亲测会卡你时间，不然也不会出这种题
// 用树形数组解这道题，如果构建好了的话，每一次操作仅为O(logn)，而且代码量极少
/*
* 题目：一个长为n的数列，Q个操作，分为两种
* 1、给出l, r, x, 对该区间每一个Ai都加上x
* 2、给出l, r, 求该区间的和
*
* 解法如下：
* 考虑到这个定义：
* s(i) = 加上x之前的Σ(j=1, i)aj
* s'(i) = 加上x之后的Σ(j=1, i)aj
* 我们分区间进行操作
* 则对于i < l, s'(i) = s(i) + 0, 即不变
* 对于l<=i<=r, 则s'(i) = s(i) + x*(i-l+1)
* 对于i > r, 则s'(i) = s(i) + x*(r-l+1)
* 可以看到s'(i)均与s(i)和后面的一段表达式有关，对此我们就想到对这两段分别构建两个树形数组
* 关键来了 Σ(j=1, i)aj = sum(bit1, i)*i + sum(bit0, i) 这里bit0对应上一行的s(i), bit1对应表达式
* 那么如何更新了？ 在[l, r]上加x，对i<l是没有影响的，对i>r的影响我们可以加在bit0的r+1位置上，因为>=r+1的所有s'(i)
* 求和的影响均相同，所以对于bit0, 我们在r+1位置上加上x*r, 在l位置上加上-x*(l-1)
* 对bit1, 则它对应于l<=i<=j，即在bit1的l位置加上x, 在r+1位置加上-x，即在其它区间内是求和只由bit0决定 
* 如果还不能理解，可以代入后与上面的数学表达式对照，你就会明白这样定义完美等价
* 这两个维护与BIT.c++定义的传统树形数组一致
* 所以我们可以轻松的完成这个任务啦！！！
*/
#include<BIT.c++>
typedef long long ll;

int N, Q;
int A[MAX_N+1]
char T[MAX_Q];
int L[MAX_Q], R[MAX_Q], X[MAX_Q];

ll bit0[MAX_N+1], bit1[MAX_N+1]

void solve(){
    for(int i = 1; i <= N; i++){
        //构建bit0, bit1没有+X操作时均为为0
        add(bit, 0, A[i]);
    }

    for(int i = 0; i < Q; i++){
        if(T[i] == "C"){
            //按照上面进行更新操作
            add(bit0, L[i], -X[i]*(L[i]-1));
            add(bit0, R[i]+1, X[i]*R[i]);
            add(bit1, L[i], X[i]);
            add(bit1, R[i]+1, -X[i]);
        }else{
            ll res = sum(bit0, R[i]) + sum(bit1, R[i])*R[i] - sum(bit0, L[i]-1)- sum(bit1, L[i]-1)*(L[i]-1);
            printf("%lld\n", res);
        }
    }
}