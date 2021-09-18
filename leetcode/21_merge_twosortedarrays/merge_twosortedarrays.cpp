#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (l1 == l2) return l1;
            if (l1 == nullptr) return l2;
            if (l2 == nullptr) return l1;
            ListNode* start = nullptr, *p = nullptr, *p1 = l1, *p2 = l2;
            while (p1 != nullptr || p2 != nullptr) {
                if (p == nullptr) {
                    start = p = p1->val <= p2-> val ? p1: p2;
                }
                if (p == p1) {
                    p1 = p1->next;
                    if (p1 == nullptr) {
                        p->next = p2;
                        break;
                    }
                    if (p1->val > p2->val) {
                        p->next = p2;
                        p = p2;
                    }
                    if (p1->val <= p2->val) {
                        p = p1;
                    }
                }
                if (p == p2) {
                    p2 = p2->next;
                    if (p2 == nullptr) {
                        p->next = p1;
                        break;
                    }
                    if (p2->val > p1->val) {
                        p->next = p1;
                        p = p1;
                    }
                    if (p2->val <= p1->val) {
                        p = p2;
                    }
                }
            }

            return start;
        }
};

ostream& operator<<(ostream& os, ListNode* p) {
    if(p == nullptr) return os;
    while(p != nullptr) {
        os << p->val << ' ';
        p = p->next;
    }
    return os;
}

int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    ListNode* pk = nullptr;

    p1->next = p3;
    p3->next = p4;
    p2->next = p5;
    cout << p1 << endl;
    cout << p2 << endl;

    Solution* sol = new Solution();

    /*ListNode* sort2 = sol->mergeTwoLists(p1, pk);
    cout << sort2 << endl;
    ListNode* sort3 = sol->mergeTwoLists(pk, pk);
    cout << sort3 << endl;
    ListNode* sort4 = sol->mergeTwoLists(p2, p2);
    cout << sort4 << endl;*/
    ListNode* sort1 = sol->mergeTwoLists(p1, p2);
    cout << sort1 << endl;
}
