/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode **pos = &head;

    while (*pos) {
        if ((*pos)->val == val) {
            *pos = (*pos)->next;
        } else {
            pos = &(*pos)->next;
        }
    }

    return head;
}
