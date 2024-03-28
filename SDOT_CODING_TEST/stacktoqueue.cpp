#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty())
            return -1;

        // Move elements from q1 to q2 except the last one
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Retrieve the top element from q1
        int topElement = q1.front();
        q1.pop();

        // Move elements back to q1 from q2
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return topElement;
    }
};

int main() {
    Stack stack;
    int queries;
    cin >> queries;

    while (queries--) {
        int type;
        cin >> type;

        if (type == 1) { // push
            int x;
            cin >> x;
            stack.push(x);
        } else if (type == 2) { // pop
            int topElement = stack.pop();
            cout << topElement << endl;
        }
    }

    return 0;
}
