class Solution:
    def lengthLongestPath(self, input: str) -> int:
        res = 0
        depth_length_map = {-1: 0}
        for line in input.split('\n'):
            print(line)
            depth = line.count('\t')
            #每行空格最后要被去掉
            depth_length_map[depth] = depth_length_map[depth - 1] + len(line) - depth
            if line.count('.'):
                # 每层都要添加depth个 / 
                res = max(res, depth_length_map[depth] + depth)
        return res
