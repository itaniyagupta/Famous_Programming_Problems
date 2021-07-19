#https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        result = [0 for _ in nums]
        left = 0
        right = len(nums)-1
        for index in reversed(range(len(nums))):
            leftval = nums[left]
            rightval = nums[right]
            if abs(leftval) > abs(nums[right]):
                result[index] = leftval * leftval
                left += 1
            else:
                result[index] = rightval * rightval
                right -= 1
        return result
            
            