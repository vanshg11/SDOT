#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k <= 0) return head;

    int length = 1;
    ListNode* tail = head;

    // Calculate the length of the linked list and find the tail node
    while (tail->next) {
        length++;
        tail = tail->next;
    }

    // Adjust k to the effective rotations needed
    k %= length;

    if (k == 0) return head;

    // Move the tail node to the original head position
    tail->next = head;

    // Traverse to the new tail node (length - k - 1) positions
    for (int i = 0; i < length - k - 1; i++) {
        head = head->next;
    }

    // Set the new head and break the link
    ListNode* new_head = head->next;
    head->next = nullptr;

    return new_head;
}

ListNode* createList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = createList();
    int k;
    std::cin >> k;

    ListNode* rotatedList = rotateRight(head, k);

    printList(rotatedList);

    return 0;
}
