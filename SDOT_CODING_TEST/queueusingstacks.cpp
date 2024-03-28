#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:
    void push(int x) {
        s1.push(x);
    }

    void pop() {
        if (s2.empty()) {
            // Move elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (!s2.empty()) {
            cout << s2.top() << endl;
            s2.pop();
        } else {
            cout << "-1" << endl;
        }
    }
};

int main() {
    Queue queue;
    int queries;
    cin >> queries;

    while (queries--) {
        int type;
        cin >> type;

        if (type == 1) { // push
            int x;
            cin >> x;
            queue.push(x);
        } else if (type == 2) { // pop
            queue.pop();
        }
    }

    return 0;
}
