#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode* next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode* midNode(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* reverseLL(ListNode* head) {

    if (head == nullptr or head->next == nullptr) {
        return head;
    }

    ListNode* prev = nullptr, *curr = head;

    while (curr != nullptr) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

int Length(ListNode* head) {

    int len = 0;

    ListNode* curr = head;

    while (curr != nullptr) {
        len++;
        curr = curr->next;
    }

    return len;
}

ListNode* subtract_TwoNumbers(ListNode* l1, ListNode* l2) {

    l1 = reverseLL(l1);
    l2 = reverseLL(l2);

    ListNode* h1 = nullptr;
    ListNode* p1 = nullptr;

    int borrow = 0;

    // Let us assume that the first linked list is greater than the second Linked List.

    while (l1 != nullptr and l2 != nullptr) {
        int x = (l1->val);
        int y = (l2->val);

        x -= borrow;

        if (x >= y) {
            l1->val = (x - y);
            borrow = 0;
        } else {
            x += 10;

            l1->val = (x - y);

            borrow = 1;
        }

        if (h1 == nullptr) {
            h1 = l1;
            p1 = h1;
        } else {
            p1 = l1;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != nullptr) {

        int x = (l1->val);

        x -= borrow;

        if (x >= 0) {
            l1->val = (x - 0);
            borrow = 0;
        } else {
            x += 10;

            l1->val = (x - 0);

            borrow = 1;
        }

        if (h1 == nullptr) {
            h1 = l1;
            p1 = h1;
        } else {
            p1 = l1;
        }

        l1 = l1->next;
    }

    if (borrow) {
        ListNode* n = new ListNode(borrow);
        p1->next = n;
        p1 = p1->next;
    }

    return reverseLL(h1);
}

ListNode* subtractTwoNumbers(ListNode* l1, ListNode* l2) {

    int len1 = Length(l1);
    int len2 = Length(l2);

    ListNode *lNode = NULL, *sNode = NULL;

    ListNode* temp1 = l1;
    ListNode* temp2 = l2;

    if (len1 != len2) {
        lNode = len1 > len2 ? l1 : l2;
        sNode = len1 > len2 ? l2 : l1;
    } else {
        while (temp1 && temp2) {
            if (temp1->val != temp2->val) {
                lNode = temp1->val > temp2->val ? temp1 : temp2;
                sNode = temp1->val > temp2->val ? temp2 : temp1;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    if (lNode == nullptr and sNode == nullptr) {

        ListNode* n = new ListNode(0);

        return n;
    }

    return subtract_TwoNumbers(lNode, sNode);
}

// Input_code===================================================

ListNode* makeList(int n)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

void printList(ListNode* node)
{
    ListNode* curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListNode* head1 = makeList(n);

    int m;
    cin >> m;
    ListNode* head2 = makeList(m);

    ListNode* head = subtractTwoNumbers(head1, head2);
    printList(head);

    return 0;
}