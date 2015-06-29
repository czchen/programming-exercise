/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *swapPairs(struct ListNode *head) {
    struct ListNode **prev;
    struct ListNode **curr;
    struct ListNode **next;
    struct ListNode *tmp;

    prev = &head;

    while (*prev) {
        if (!*prev) break;
        curr = &(*prev)->next;
        if (!*curr) break;
        next = &(*curr)->next;

        tmp = *prev;
        *prev = *curr;
        *curr = *next;
        *next = tmp;

        prev = &tmp->next;
    }

    return head;
}
