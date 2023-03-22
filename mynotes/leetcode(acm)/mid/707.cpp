//由于是结构的实现 所以不用处理输入输出了
//要注意一些情况中的下标溢出

#include <iostream>
using namespace std;

struct listNode {
    int val;
    listNode* next;
    listNode() :val(0), next(nullptr) {}
    listNode(int a) :val(a), next(nullptr) {}
    listNode(int a, listNode* ptr) :val(a), next(ptr) {}
    ~listNode() {}
};
class MyLinkedList {
public:
    MyLinkedList() {

    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        listNode* cur = dummy.next;
        while (index > 0) {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        listNode* temp = dummy.next;
        dummy.next = new listNode(val);
        dummy.next->next = temp;
        size++;
    }

    void addAtTail(int val) {
        listNode* cur = &dummy;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new listNode(val);
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        listNode* cur = &dummy;
        for (; index > 0; index--) {
            cur = cur->next;
        }
        listNode* temp = cur->next;
        cur->next = new listNode(val);
        cur->next->next = temp;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        listNode* cur = &dummy;
        for (; index > 0; index--) {
            cur = cur->next;
        }
        listNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        size--;
    }
private:
    listNode dummy;
    int size = 0;
};
int main() {
    while (1);
}