
"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order
and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
"""


def build_list(str_num):

    list_num = [int(i) for i in str_num]
    temp_list = None
    ret = ListNode(list_num[0])
    for i in list_num[1:]:
        temp_list = ListNode(i)
        temp_list.next = ret
        ret = temp_list
    return ret


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        p = root = ListNode(0)
        while l1 or l2 or carry:
            n1 = n2 = 0
            if l1:
                n1 = l1.val
                l1 = l1.next
            if l2:
                n2 = l2.val
                l2 = l2.next
            carry, s = divmod(n1+n2+carry, 10)
            p.next = ListNode(s)
            p = p.next

        return root.next




if __name__ == '__main__':

    l1 = build_list('342')
    l2 = build_list('465')
    ret = Solution().addTwoNumbers(l1, l2)

    print(ret)