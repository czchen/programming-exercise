/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast;
    struct ListNode *slow;

    if (!head) {
        return false;
    }

    slow = head->next;

    if (!slow) {
        return false;
    }
    fast = slow->next;


    while (fast != slow) {
        if (!slow) {
            return false;
        }
        slow = slow->next;

        if (!fast) {
            return false;
        }
        fast = fast->next;
        if (!fast) {
            return false;
        }
        fast = fast-> next;
    }

    return true;
}
