/*
1. Given a singly linklist, Segregate 01 Node of LinkedList and return pivot node of linkedlist.
2. After segregation zero nodes should come first and followed by ones node.

Input Format
1->0->1->0->0->1->1->1->1->1->1->null
Output Format
0->0->0->1->1->1->1->1->1->1->1->null
*/

// -10^6 <= size Of LinkedList <= 10^6

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *segregate01(ListNode *head) {

    if (head == nullptr or head->next == nullptr) {
        return head;
    }

    ListNode* z = nullptr, *o = nullptr;
    ListNode* z_p = nullptr, *o_p = nullptr;

    ListNode* curr = head;

    while (curr != nullptr) {
        if (curr->val == 0) {
            if (z == nullptr) {
                z = curr;
                z_p = curr;
            } else {
                z_p->next = curr;
                z_p = z_p->next;
            }
        } else {
            if (o == nullptr) {
                o = curr;
                o_p = curr;
            } else {
                o_p->next = curr;
                o_p = o_p->next;
            }
        }
        curr = curr->next;
    }

    if (z == nullptr or o == nullptr) {
        return head;
    }

    o_p->next = nullptr;
    z_p->next = o;

    return z;
}

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    ListNode *h1 = createList(n);
    h1 = segregate01(h1);
    printList(h1);

    return 0;
}