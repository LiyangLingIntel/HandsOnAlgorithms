"""
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
"""
from typing import List
class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        n = len(ratings)
        cds = [1 for i in range(n)]
        for i in range(1, n):
            if ratings[i] > ratings[i-1]:
                cds[i] = cds[i-1] + 1
        for i in range(1, n):
            if ratings[-i-1] > ratings[-i]:
                cds[-i-1] = max(cds[-i] + 1,  cds[-i-1])
        return sum(cds)

"""
对这道hard难度的题目, 我觉得最重要的就是能够理解题目的意思.
其中一个容易被错误理解的点就是: 当相邻两个人rating相同时, 他们的candy是可以有差异的.
"""