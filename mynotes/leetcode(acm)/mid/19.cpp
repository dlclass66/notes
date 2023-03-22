//输入格式 第一行为链表 第二行为倒数第几个数
//要注意删除头节点的情况
//双指针一快一慢拉出间隔
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (n > 0) {
            fast = fast->next;
            n--;
        }
        if (fast == nullptr) {
            return head->next;
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next->next;
        delete slow->next;
        slow->next = temp;
        return head;
    }
};
int main() {
    int num = 0;
    int target = 0;
    ListNode* dummy = new ListNode;
    ListNode* cur = dummy;
    while (cin >> num) {
        cur->next = new ListNode;
        cur->next->val = num;
        cur = cur->next;
        if (getchar() == '\n') {
            break;
        }
    }
    cin >> target;
    ListNode* ans = Solution().removeNthFromEnd(dummy->next, target);
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