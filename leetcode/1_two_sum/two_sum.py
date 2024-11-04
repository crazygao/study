from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_pos_dict = {}
        for i, num in enumerate(nums):
            num_pos_dict[num] = i

        for i, num in enumerate(nums):
            left = target - num
            if num_pos_dict.get(left, -1) == -1 or num_pos_dict.get(left) == i:
                continue
            else:
                return [i, num_pos_dict[left]]


if __name__ == "__main__":
    sol = Solution()
    print(sol.twoSum([3, 2, 4], 6))