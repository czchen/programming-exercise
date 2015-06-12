/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool moveToChild(struct ListNode **node)
{
    if (!*node) {
        return false;
    }

    *node = (*node)->next;
    if (!*node) {
        return false;
    }

    return true;
}

bool moveToGrandChild(struct ListNode **node)
{
    bool ret;

    ret = moveToChild(node);
    if (!ret) {
        return ret;
    }

    return moveToChild(node);
}

bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    bool ret;

    ret = moveToChild(&slow);
    if (!ret) {
        return ret;
    }

    ret = moveToGrandChild(&fast);
    if (!ret) {
        return ret;
    }

    while (fast != slow) {
        ret = moveToChild(&slow);
        if (!ret) {
            return ret;
        }

        ret = moveToGrandChild(&fast);
        if (!ret) {
            return ret;
        }
    }

    return true;
}
