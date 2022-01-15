//leetcode-232
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {}

    void push(int x) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int pop() {
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        return s2.top();
    }

    bool empty() {
        return s2.empty();
    }
};

//leetcode-225
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};