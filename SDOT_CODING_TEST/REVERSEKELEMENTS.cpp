#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *current = head;
    ListNode *next = nullptr;
    ListNode *prev = nullptr;
    int count = 0;

    // Count the number of nodes in the current group
    while (current != nullptr && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // If count is less than k, reverse the nodes back to their original positions
    if (count < k)
    {
        current = prev;
        prev = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    // Recursively reverse the remaining groups
    if (next != nullptr)
    {
        head->next = reverseKGroup(next, k);
    }

    return prev;
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

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *head = createList();
    int k;
    std::cin >> k;

    ListNode *reversedList = reverseKGroup(head, k);

    printList(reversedList);

    return 0;
}
