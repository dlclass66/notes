//输入格式 一行为链表 数字用空格隔开 输出一行为链表
//注意链表的读取创建 最后不要有一个多的节点
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* cur = head;
        ListNode* curn = head->next;
        while (curn != nullptr) {
            ListNode* temp = curn->next;
            curn->next = cur;
            cur = curn;
            curn = temp;
        }
        head->next = nullptr;
        return cur;
    }
};
int main() {
    int num = 0;
    ListNode* dummy = new ListNode;
    ListNode* cur = dummy;
    while (cin >> num) {
        cur->next = new ListNode;
        cur->next->val = num;
        cur = cur->next;
    }
    ListNode* ans = Solution().reverseList(dummy->next);
    dummy->next = ans;
    while (ans) {
        cout << ans->val << ' ';
        ans = ans->next;
    }
    while (dummy) {
        ListNode* temp = dummy;
        dummy = dummy->next;
        delete temp;
    }
    while (1);
}


//下面是递归 就是把移动过程用递归完成
//可以在最开始有一个null节点 这样就不用最后把head的next设置为nullptr了
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* ans = revers(head, head->next);
        head->next = nullptr;
        return ans;
    }
    ListNode* revers(ListNode* cur, ListNode* curn) {
        if (curn == nullptr) {
            return cur;
        }
        ListNode* temp = curn->next;
        curn->next = cur;
        return revers(curn, temp);
    }
};
int main() {
    int num = 0;
    ListNode* dummy = new ListNode;
    ListNode* cur = dummy;
    while (cin >> num) {
        cur->next = new ListNode;
        cur->next->val = num;
        cur = cur->next;
    }
    ListNode* ans = Solution().reverseList(dummy->next);
    dummy->next = ans;
    while (ans) {
        cout << ans->val << ' ';
        ans = ans->next;
    }
    while (dummy) {
        ListNode* temp = dummy;
        dummy = dummy->next;
        delete temp;
    }
    while (1);
}