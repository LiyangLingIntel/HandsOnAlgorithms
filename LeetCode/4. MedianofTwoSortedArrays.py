"""
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
"""


class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        l1, l2 = len(nums1), len(nums2)
        if l1 > l2:
            nums1, nums2, l1, l2 = nums2, nums1, l2, l1

        i_max, i_min, half_len = l1, 0, (l1+l2+1)//2
        while i_max >= i_min:
            i = (i_min + i_max) // 2
            j = half_len - i
            if i < l1 and nums1[i] < nums2[j-1]:
                i_min = i + 1
            elif i > 0 and nums1[i-1] > nums2[j]:
                i_max = i - 1
            else:
                if i == 0:
                    left_max = nums2[j-1]
                elif j == 0:
                    left_max = nums1[i-1]
                else:
                    left_max = max(nums1[i-1], nums2[j-1])

                if (l1 + l2) % 2 == 1:
                    return left_max

                if i == l1:
                    right_min = nums2[j]
                elif j == l2:
                    right_min = nums1[i]
                else:
                    right_min = min(nums1[i], nums2[j])
                return (left_max + right_min) / 2


if __name__ == '__main__':

    nums1 = []
    nums2 = [4, 6, 7]
    median = Solution().findMedianSortedArrays(nums1, nums2)
    print(median)