# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        current = head
        carry = 0

        while l1 or l2:
            value = carry
            if l1:
                value += l1.val
                l1 = l1.next

            if l2:
                value += l2.val
                l2 = l2.next

            carry = value // 10
            value %= 10

            current.next = ListNode(value)
            current = current.next

        if carry:
            current.next = ListNode(carry)
            current = current.next

        return head.next
