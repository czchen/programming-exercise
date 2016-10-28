/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ans = 0;
    struct ListNode **ptr = &ans;
    int carry = 0;

    while (l1 || l2) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum %= 10;

        *ptr = malloc(sizeof(**ptr));
        if (!*ptr) {
            break;
        }

        (*ptr)->val = sum;
        (*ptr)->next = 0;
        ptr = &(*ptr)->next;
    }

    if (carry) {
        *ptr = malloc(sizeof(**ptr));
        if (*ptr) {
            (*ptr)->val = 1;
            (*ptr)->next = 0;
            ptr = &(*ptr)->next;
        }
    } else if (!ans) {
        ans = malloc(sizeof(*ans));
        ans->val = 0;
        ans->next = 0;
    }


    return ans;
}
