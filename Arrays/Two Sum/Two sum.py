# https://leetcode.com/problems/two-sum/

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        values = {}  # hashmap for lookup diff values
        for index,num in enumerate(nums):
            val = target - num 
            if val in values:   # check if the difference is seen so far 
                return [index,values[val]] # if it is then return the current index and index of corresponding difference
            else:
                values[num] = index # if not, then add it to hashmap
        return []