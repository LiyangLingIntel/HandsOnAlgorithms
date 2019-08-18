
"""
These three cases are possible with string a and b:-

* a = b. 
    If both the strings are identical, 
    it is obvious that no subsequence will be uncommon. 
    Hence, return -1.

* length(a)=length(b) and a != b
    Example: abc and abd. 
    In this case we can consider any string 
    i.e. abc or abd as a required subsequence, 
    as out of these two strings one string will never be a subsequence of other string. 
    Hence, return length(a) or length(b).

length(a) != length(b)
    Example abcd and abc. 
    In this case we can consider bigger string as a required subsequence because bigger string
     can't be a subsequence of smaller string. 
     Hence, return max(length(a),length(b)).
"""

class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        
        if a == b:
            return -1
        if len(a) == len(b):
            return len(a)
        else:
            return max(len(a), len(b))