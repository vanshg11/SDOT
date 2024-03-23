#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct CompareNodes
{
    bool operator()(ListNode *const &n1, ListNode *const &n2)
    {
        return n1->val > n2->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, CompareNodes> minHeap;

    // Push the head of each list into the minHeap
    for (ListNode *listHead : lists)
    {
        if (listHead)
            minHeap.push(listHead);
    }

    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (!minHeap.empty())
    {
        ListNode *smallest = minHeap.top();
        minHeap.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next)
            minHeap.push(smallest->next);
    }

    return dummy.next;
}

ListNode *createList()
{
    ListNode *head = nullptr;
    ListNode *temp = nullptr;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
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
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int k;
    cin >> k;

    vector<ListNode *> lists;
    for (int i = 0; i < k; ++i)
    {
        ListNode *listHead = createList();
        lists.push_back(listHead);
    }

    ListNode *mergedList = mergeKLists(lists);

    printList(mergedList);

    return 0;
}
