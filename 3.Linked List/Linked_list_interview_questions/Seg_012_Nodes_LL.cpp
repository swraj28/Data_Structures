/*

1. Given a singly linklist, Segregate 012 Node of LinkedList and return pivot node of linkedlist.
2. After segregation zero nodes should come first and then ones node followed by two's nodes.
Input Format
1->0->1->0->0->1->2->1->1->1->2->1->1->null
Output Format
0->0->0->1->1->1->1->1->1->1->1->2->2->null
*/

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

ListNode *segregate012(ListNode *head) {

    if (head == nullptr or head->next == nullptr) {
        return nullptr;
    }

    ListNode* zero = new ListNode(-1);
    ListNode* p_zero = zero;

    ListNode* one = new ListNode(-1);
    ListNode* p_one = one;

    ListNode* two = new ListNode(-1);
    ListNode* p_two = two;

    ListNode* curr = head;

    while (curr != nullptr) {
        if (curr->val == 0) {
            p_zero->next = curr;
            p_zero = p_zero->next;
        } else if (curr->val == 1) {
            p_one->next = curr;
            p_one = p_one->next;
        } else {
            p_two->next = curr;
            p_two = p_two->next;
        }
        curr = curr->next;
    }

    p_two->next = nullptr;
    p_one->next = two->next;
    p_zero->next = p_one->next;

    return zero->next;
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
    h1 = segregate012(h1);
    printList(h1);

    return 0;
}