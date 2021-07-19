# https://leetcode.com/problems/is-subsequence/

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        seqIndex = 0
        for str in t:
            if seqIndex == len(s):
                break
            if s[seqIndex] == str:
                seqIndex += 1
        return seqIndex == len(s)
            