class Solution {
public:
//检验是否存在环，，
//图中是否存在环有两种解法：1.拓扑排序。2.DFS
//拓扑排序算法只需要判断是否存在环就可以啦，别的不需要考虑的。。。
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,set<int>>mp;
        vector<int>indegree(numCourses+1,0);
        for(auto v:prerequisites){
            int a=v[1];
            int b=v[0];
            mp[a].insert(b);//构建a-->b的有向图
            ++indegree[b];//初始化入度
        }
        //拓扑排序，采用的是队列，存放的是入度为0的点，即准备释放的点。
        queue<int>que;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)que.push(i);
        }
        vector<int> res;
        int count=0;
        while(!que.empty()){
            int v=que.front();
            res.push_back(v);
            que.pop();
            ++count;
            //下面就是将出队之后，与那个点相邻的点入度减少一个，其中入度为0的点，入队列
            auto x=mp[v];//x是一个数组
            for(auto t:x){
                indegree[t]--;
                if(indegree[t]==0){
                    que.push(t);
                }
            }

        }
        return count == numCourses ? res : vector<int>();
    }
};
