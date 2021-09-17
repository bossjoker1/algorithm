//1011, 典型的二分查找问题，没什么说的
class Solution {
public:

    bool check(vector<int>& weights, int target, int D){
        int sum = 0, count = 1;   
        for(int i  = 0;i < weights.size();i++){
            if(sum + weights[i] > target){
                sum = weights[i];
                count++;
            }else{
                sum += weights[i];
            }
        }
        return count <= D;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        //上界为weights和，D=1
        int r = accumulate(weights.begin(), weights.end(), 0), l = *max_element(weights.begin(), weights.end());
        //cout<<r<<endl;
        while(l < r){
            int mid = (l + r) >> 1;
            //cout<<"mid:"<<mid<<endl;
            if(check(weights, mid, D)){
                //target太大了可以缩小
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};