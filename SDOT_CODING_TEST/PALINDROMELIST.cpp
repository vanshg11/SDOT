#include <iostream>
#include <stack>

struct ListNode
{
    char val;
    ListNode *next;
    ListNode(char x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode *head)
{
    std::stack<char> s;
    ListNode *temp = head;

    while (temp != nullptr)
    {
        s.push(temp->val);
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr)
    {
        if (temp->val != s.top())
            return false;
        s.pop();
        temp = temp->next;
    }
    return true;
}

ListNode *createList()
{
    ListNode *head = nullptr;
    ListNode *temp = nullptr;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        char val;
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
    ListNode *head = createList();

    if (isPalindrome(head))
        std::cout << "True\n";
    else
        std::cout << "False\n";

    return 0;
}
