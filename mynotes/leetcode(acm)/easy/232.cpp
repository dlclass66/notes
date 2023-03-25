//注意栈的pop（）没有返回值
//可以优化peek函数 相当于pop之后再push回去
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int a = st2.top();
        st2.pop();
        return a;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
private:
    stack<int> st1;
    stack<int> st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main() {
    while (1);
}

//改写peek函数实现复用
int peek() {
        int peeknum = pop();
        st2.push(peeknum);
        return peeknum;
    }