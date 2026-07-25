from functools import cache

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: list[list[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])

        @cache
        def paths(r, c):
            # 1. Out of bounds or hit an obstacle
            if r == m or c == n or obstacleGrid[r][c] == 1:
                return 0
            
            # 2. Reached the exact bottom-right cell
            if r == m - 1 and c == n - 1:
                return 1
            
            # 3. Recurse Down and Right
            return paths(r + 1, c) + paths(r, c + 1)
        
        return paths(0, 0)