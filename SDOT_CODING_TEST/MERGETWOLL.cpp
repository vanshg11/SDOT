#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    ListNode *mergedList = nullptr;

    if (l1->val <= l2->val)
    {
        mergedList = l1;
        mergedList->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        mergedList = l2;
        mergedList->next = mergeTwoLists(l1, l2->next);
    }

    return mergedList;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

ListNode *createList()
{
    ListNode *head = nullptr;
    ListNode *temp = nullptr;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int val;
        std::cin >> val;
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

int main()
{
    ListNode *l1 = createList();
    ListNode *l2 = createList();

    ListNode *mergedList = mergeTwoLists(l1, l2);

    printList(mergedList);

    return 0;
}
