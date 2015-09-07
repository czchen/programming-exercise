/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head1 = l1;
    struct ListNode* head2 = l2;

    struct ListNode *ans = NULL;
    struct ListNode **curr = &ans;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            *curr = l1;
            l1 = l1->next;
        } else {
            *curr = l2;
            l2 = l2->next;

        }

        curr = &(*curr)->next;
    }

    if (l1) {
        *curr = l1;
    } else if (l2) {
        *curr = l2;
    }

    return ans;
}
