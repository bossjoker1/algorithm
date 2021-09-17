//树形数组
//维护两个算法
//1. 给定i, 求a1+a2+...+ai的和
//2. 给定i, x, 执行ai+=x

//由树形数组的特性，只需要取每个子树的左节点即可，因此比线段树效率更高，且与位运算相关

int bit[MAX_N+1], n;

int sum(int i){
    int s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i; //减去最尾端的1表示的幂
    }
    return s;
}

void add(int i, int x){
    while( i <= n){
        bit[i] += x;
        i += i & -i;
    } 
}