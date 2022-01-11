# 方法1：起点终点同时开始bfs，因为block最大为200，所以存在搜索上界
EDGE = int(1e6)
class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        block = {p[0] * EDGE + p[1] for p in blocked}
        n = len(blocked)
        MAX = (n-1)*n//2

        def check(s, t):
            vis = {s[0] * EDGE + s[1]}
            d = deque([s])
            while len(d) and len(vis) <= MAX:
                x, y = d.popleft()
                if x == t[0] and y == t[1]:
                    return True
                for nx, ny in [[x-1,y], [x+1,y],[x,y+1], [x,y-1]]:
                    if nx < 0 or nx >= EDGE or ny < 0 or ny >= EDGE:
                        continue
                    h = nx * EDGE + ny
                    if h in block or h in vis:
                        continue
                    d.append((nx, ny))
                    vis.add(h)
            return len(vis) > MAX
        return check(source, target) and check(target, source)
    
# 方法2：离散化，因为block最大为200远小于1e6，所以可以根据某一行是否含block点，将其进行压缩实现O(n)的复杂度
# 给个c++题解
# class Solution {
# private:
#     static constexpr int BOUNDARY = 1000000;
#     static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
# public:
#     bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
#         if (blocked.size() < 2) {
#             return true;
#         }
#         vector<int> rows, columns;
#         for (const auto& pos: blocked) {
#             rows.push_back(pos[0]);
#             columns.push_back(pos[1]);
#         }
#         rows.push_back(source[0]);
#         rows.push_back(target[0]);
#         columns.push_back(source[1]);
#         columns.push_back(target[1]);
        
#         // 离散化
#         sort(rows.begin(), rows.end());
#         sort(columns.begin(), columns.end());
#         rows.erase(unique(rows.begin(), rows.end()), rows.end());
#         columns.erase(unique(columns.begin(), columns.end()), columns.end());
#         unordered_map<int, int> r_mapping, c_mapping;

#         int r_id = (rows[0] == 0 ? 0 : 1);
#         r_mapping[rows[0]] = r_id;
#         for (int i = 1; i < rows.size(); ++i) {
#             r_id += (rows[i] == rows[i - 1] + 1 ? 1 : 2);
#             r_mapping[rows[i]] = r_id;
#         }
#         if (rows.back() != BOUNDARY - 1) {
#             ++r_id;
#         }

#         int c_id = (columns[0] == 0 ? 0 : 1);
#         c_mapping[columns[0]] = c_id;
#         for (int i = 1; i < columns.size(); ++i) {
#             c_id += (columns[i] == columns[i - 1] + 1 ? 1 : 2);
#             c_mapping[columns[i]] = c_id;
#         }
#         if (columns.back() != BOUNDARY - 1) {
#             ++c_id;
#         }

#         vector<vector<int>> grid(r_id + 1, vector<int>(c_id + 1));
#         for (const auto& pos: blocked) {
#             int x = pos[0], y = pos[1];
#             grid[r_mapping[x]][c_mapping[y]] = 1;
#         }
        
#         int sx = r_mapping[source[0]], sy = c_mapping[source[1]];
#         int tx = r_mapping[target[0]], ty = c_mapping[target[1]];

#         queue<pair<int, int>> q;
#         q.emplace(sx, sy);
#         grid[sx][sy] = 1;
#         while (!q.empty()) {
#             auto [x, y] = q.front();
#             q.pop();
#             for (int d = 0; d < 4; ++d) {
#                 int nx = x + dirs[d][0], ny = y + dirs[d][1];
#                 if (nx >= 0 && nx <= r_id && ny >= 0 && ny <= c_id && grid[nx][ny] != 1) {
#                     if (nx == tx && ny == ty) {
#                         return true;
#                     }
#                     q.emplace(nx, ny);
#                     grid[nx][ny] = 1;
#                 }
#             }
#         }
#         return false;
#     }
# };



