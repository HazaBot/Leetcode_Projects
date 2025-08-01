from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = []
        for n in range(numRows):
            if n == 0:
                triangle.append([1])
                continue
            if n == 1:
                triangle.append([1, 1])
                continue
            row = [1] * (n + 1)
            for k in range(n + 1):
                if k == 0 or k == n:
                    row[k] = 1 
                else:
                    row[k] = triangle[n - 1][k - 1] + triangle[n - 1][k]
            triangle.append(row)
        return triangle

sol = Solution()
print(sol.generate(10))