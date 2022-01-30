# 278 4 压轴题
# 并查集 + 字符串 + 状压？
# 不会

# 以后会了再来填坑

# 贴个大神题解
# class Solution {
# public:
#     vector<int> groupStrings(vector<string>& words) {
#         unordered_map<int, int> F;
#         vector<int> v;
#         for (int i = 0; i < words.size(); ++i)
#         {
#             int tmp = 0;
#             for (int j = 0; j < words[i].size(); ++j)
#                 tmp |= 1 << (words[i][j] - 'a');
#             F[tmp] += 1;
#         }
#         for (auto [x, y] : F)
#             v.push_back(x);
#         sort(v.begin(), v.end());
        
#         int cnt = 0;
#         int best = 0;
#         for (auto x : v)
#         {
#             if (F.find(x) == F.end()) continue;
#             cnt += 1;
#             int tmp = F[x];
#             F.erase(x);
#             queue<int> q;
#             q.push(x);
#             while (!q.empty())
#             {
#                 int x = q.front();
#                 q.pop();
#                 for (int i = 0; i < 26; ++i)
#                 {
#                     if (x >> i & 1)
#                     {
#                         int y = x - (1 << i);
#                         if (F.find(y) != F.end())
#                         {
#                             q.push(y);
#                             tmp += F[y];
#                             F.erase(y);
#                         }
#                         for (int j = 0; j < 26; ++j) if (!(y >> j & 1))
#                         {
#                             int z = y + (1 << j);
#                             if (F.find(z) != F.end())
#                             {
#                                 q.push(z);
#                                 tmp += F[z];
#                                 F.erase(z);
#                             }
#                         }
#                     }
#                     else
#                     {
#                         int y = x + (1 << i);
#                         if (F.find(y) != F.end())
#                         {
#                             q.push(y);
#                             tmp += F[y];
#                             F.erase(y);
#                         }
#                     }
#                 }
#             }
#             best = max(best, tmp);
#         }
        
#         return {cnt, best};
#     }
# };

