//输入格式 第一行为链表 数字用空格隔开 第二行为环开始的位置
//输出格式 输出环开始的位置的值
//需要用到一快一慢两个指针 快的速度是慢的两倍 运用数学等式
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int a) :val(a), next(nullptr) {}
    ListNode(int a, ListNode* ptr) :val(a), next(ptr) {}
    ~ListNode() {}
};
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            if (fast == slow) {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        ListNode* cur = head;
        while (cur != slow) {
            slow = slow->next;
            cur = cur->next;
        }
        return cur;
    }
};
int main() {
    ListNode* dummy = new ListNode;
    int num = 0;
    int pos = 0;
    ListNode* cur = dummy;
    while (cin >> num) {
        cur->next = new ListNode(num);
        cur = cur->next;
        if (getchar() == '\n') {
            break;
        }
    }
    cin >> pos;
    ListNode* temp = dummy->next;
    while (pos > 0) {
        temp = temp->next;
        pos--;
    }
    cur->next = temp;
    cout << Solution().detectCycle(dummy->next)->val;
    while (1);
}