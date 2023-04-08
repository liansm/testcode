from collections import Counter

class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        count = Counter(sum(map(int, str(i))) for i in range(lowLimit, highLimit + 1))
        return max(count.values())


s = Solution();
print(s.countBalls(1, 15))

