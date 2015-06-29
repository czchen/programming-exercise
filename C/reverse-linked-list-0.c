/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *res = 0;

    while (head) {
        struct ListNode *current = head;
        head = head->next;
        current->next = res;
        res = current;
    }

    return res;
}
