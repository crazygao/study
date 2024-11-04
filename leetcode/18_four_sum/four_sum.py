from typing import List

# Somehow difficult.
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        if n < 4:
            return []
        nums.sort()
        res = set()
        for i in range(n - 3):
            for j in range(i + 1, n - 2):
                l, r = j + 1, n - 1
                while l < r:
                    s = nums[i] + nums[j] + nums[l] + nums[r]
                    if s == target:
                        res.add((nums[i], nums[j], nums[l], nums[r]))
                        l += 1
                        r -= 1
                    elif s < target:
                        l += 1
                    else:
                        r -= 1
        return list(res)



if __name__ == "__main__":
    sol = Solution()
    print(sol.fourSum([3, 2, 4], 6))