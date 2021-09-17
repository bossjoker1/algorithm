class Solution {
public:
struct cmp{
    // < 是大根堆
    bool operator () (pair<double, int> p1, pair<double, int> p2) const {return p1.first < p2.first;}
};
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // init the graph
        vector<vector<pair<double, int>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            graph[e[0]].emplace_back(succProb[i], e[1]);
            graph[e[1]].emplace_back(succProb[i], e[0]);
        }
        // priority_queue<pair<double, int>> que;
        priority_queue<pair<double,int>, vector<pair<double, int>>,cmp> que;

        // end到不了即返回0
        vector<double> prob(n, 0);

        que.emplace(1, start);
        prob[start] = 1;
        while (!que.empty()) {
            auto [pr, node] = que.top();
            que.pop();
            if (pr < prob[node]) {
                continue;
            }
            for (auto& [prNext, nodeNext] : graph[node]) {
                if (prob[nodeNext] < prob[node] * prNext) {
                    prob[nodeNext] = prob[node] * prNext;
                    que.emplace(prob[nodeNext], nodeNext);
                }
            }
        }
        return prob[end];
    }

};

// 一个任意pair类型的自定义排序

/*
    struct cmp
    {template <typename T, typename U>
        bool operator()(T const &left, U const &right)
        {
        // 以 second 比较。输出结果为 Second 较大的在前 Second 相同时，先进入队列的元素在前。
            if (left.second < right.second)
                return true;
            return false;
        }
    };
    // new.
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
*/