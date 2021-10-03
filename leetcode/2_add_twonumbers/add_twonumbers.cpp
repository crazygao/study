#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool overflowIn = false, overflowOut = false;
        ListNode* newHead = nullptr, *ptNewHead = newHead;
        while(l1 != nullptr || l2 != nullptr || overflowIn == true) {
            overflowOut = false;
            if (newHead == nullptr) {
                newHead = addTwoDigits(overflowIn, l1, l2, overflowOut);
                ptNewHead = newHead;
            } else {
                ptNewHead->next = addTwoDigits(overflowIn, l1, l2, overflowOut);
                ptNewHead = ptNewHead->next;
            }
            overflowIn = overflowOut;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return newHead;
    }
    ListNode* addTwoDigits(bool overflowIn, ListNode* d1, ListNode* d2, bool& overflowOut) {
        int sum = (overflowIn ? 1 : 0) + (d1 == nullptr ? 0: d1->val) + (d2 == nullptr ? 0: d2->val);
        if (sum >= 10) overflowOut = true;
        ListNode* curNode = new ListNode(sum % 10);
        return curNode;
    }
};

int main() {
    ListNode* n1 = new ListNode(9);
    n1->next = new ListNode(9);
    
    ListNode* n2 = new ListNode(9);
    n2->next = new ListNode(9);
    n2->next->next = new ListNode(9);

    Solution* sol = new Solution();
    ListNode* n3 = sol->addTwoNumbers(n1, n2);
    while(n3 != nullptr) {
        cout << n3->val << endl;
        n3 = n3->next;
    }
}
