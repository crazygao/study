struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // very nice idea, careful that two lists will always join in nullptr.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA;
        ListNode *pb = headB;
        if (pa == nullptr && pb == nullptr) return nullptr;
        while (pa != pb && pa != nullptr && pb != nullptr) {
            pa = pa->next;
            pb = pb->next;
            if (pa == pb) // happen also in nullptr, and first round
                return pa;
            if (pa == nullptr) {
                pa = headB;
            }
            if (pb == nullptr) {
                pb = headA;
            }
        }
        return pa;
    }
};
