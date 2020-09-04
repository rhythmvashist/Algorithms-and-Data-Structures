# Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.


# Example 1:

# Input: nums = [1,2,3,1], k = 3, t = 0
# Output: true
# Example 2:

# Input: nums = [1,0,1,1], k = 1, t = 2
# Output: true
# Example 3:

# Input: nums = [1,5,9,1,5,9], k = 2, t = 3
# Output: false


class Solution:
    def getId(self, n, w):
        if n >= 0:
            return n // w
        else:
            return n // w - 1

    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        if k <= 0 or t < 0:
            return False

        w = t + 1
        buckets = dict()
        for i in range(len(nums)):
            n = nums[i]
            id = self.getId(n, w)
            if id in buckets:
                return True
            if id - 1 in buckets and -t <= n - buckets[id - 1] <= t:
                return True
            if id + 1 in buckets and -t <= n - buckets[id + 1] <= t:
                return True
            buckets[id] = n
            if i >= k:
                del buckets[self.getId(nums[i - k], w)]

        return False