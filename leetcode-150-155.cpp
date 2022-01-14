//leetcode-150
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> Stack;
        for (string c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int a = Stack.top();
                Stack.pop();
                int b = Stack.top();
                Stack.pop();
                int res = 0;
                if (c == "+")
                    res = a + b;
                if (c == "-")
                    res = a - b;
                if (c == "*")
                    res = a * b;
                if (c == "/")
                    res = a / b;
                Stack.push(res);
            }
            else {
                Stack.push(stoi(c));
            }
        }
        return Stack.top();
    }
};

int main() {
    Solution s;
    vector<string> vs;
    vs.push_back("4");
    vs.push_back("13");
    vs.push_back("5");
    vs.push_back("/");
    vs.push_back("+");
    int i = s.evalRPN(vs);
    return 0;
}

//leetcode-155
class MinStack {
    stack<int> Stack;
    stack<int> Minstack;
public:
    MinStack() {
        Minstack.push(INT_MAX);
    }

    void push(int val) {
        Stack.push(val);
        Minstack.push(min(val, Minstack.top()));
    }

    void pop() {
        Minstack.pop();
        Stack.pop();
    }

    int top() {
        return Stack.top();
    }

    int getMin() {
        return Minstack.top();
    }
};