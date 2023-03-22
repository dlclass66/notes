//输入格式 一行为链表 数字之间用空格隔开
//注意对结尾的处理 奇数偶数不一样 也可以使用虚拟头节点
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* ans = head->next;
        ListNode* cur = head;
        ListNode* curn = head->next;
        while (curn != nullptr && curn->next != nullptr) {
            ListNode* tempcur = curn->next;
            ListNode* tempcurn = curn->next->next;
            curn->next = cur;
            if (tempcurn == nullptr) {
                cur->next = tempcur;
                break;
            }//最后三个节点
            cur->next = tempcurn;
            cur = tempcur;
            curn = tempcurn;
        }
        if (curn->next == nullptr) {
            curn->next = cur;
            cur->next = nullptr;
        }//最后两个节点
        return ans;
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
    ListNode* ans = Solution().swapPairs(dummy->next);
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