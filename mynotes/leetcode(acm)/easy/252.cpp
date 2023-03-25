//注意queue提供的4个接口
//可以只使用一个队列模拟栈
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        qu1.push(x);
    }

    int pop() {
        if (qu1.empty()) {
            while (qu2.size() > 1) {
                int popnum = qu2.front();
                qu2.pop();
                qu1.push(popnum);
            }
            int popnum = qu2.front();
            qu2.pop();
            return popnum;
        }
        while (qu1.size() > 1) {
            qu2.push(qu1.front());
            qu1.pop();
        }
        int popnum = qu1.front();
        qu1.pop();
        return popnum;
    }

    int top() {
        if (qu1.empty()) {
            return qu2.back();
        }
        return qu1.back();
    }

    bool empty() {
        return qu1.empty() && qu2.empty();
    }
private:
    queue<int> qu1;
    queue<int> qu2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main() {
    
    while (1);
}

//只使用一个队列实现
class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        qu.push(x);
    }
    
    int pop() {
        int size = qu.size();
        for (; size > 1; size--) {
            qu.push(qu.front());
            qu.pop();
        }
        int popnum = qu.front();
        qu.pop();
        return popnum;
    }
    
    int top() {
        return qu.back();
    }
    
    bool empty() {
        return qu.empty();
    }
private:
    queue<int> qu;
};