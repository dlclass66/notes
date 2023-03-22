//输入格式 第一行为链表 数字间用空格隔开 第二行为val
//acm模式要注意链表的创建
//最后的delete部分似乎也可以不要
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode()
        :val(0) ,next(nullptr){}
    ListNode(int x)
        :val(0), next(nullptr) {}
    ListNode(int x, ListNode* ptr)
        :val(0), next(ptr) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy;
        dummy.next = head;
        ListNode* ptr = &dummy;
        while (ptr->next != nullptr) {
            if (ptr->next->val == val) {
                ptr->next = ptr->next->next;
            }
            else {
                ptr = ptr->next;
            }
        }
        return dummy.next;
    }
};
int main() {
    int num = 0;
    int val = 0;
    ListNode dummy;
    dummy.next = new ListNode;
    ListNode* cur = dummy.next;
    while (cin >> num) {
        cur->val = num;
        cur->next = new ListNode;
        cur = cur->next;
        if (getchar() == '\n') {
            break;
        }
    }
    cin >> val;
    ListNode* ans = Solution().removeElements(dummy.next, val);
    while (ans->next != nullptr) {
        cout << ans->val << ' ';
        ans = ans->next;
    }
    ListNode* curd = dummy.next;
    while (curd->next != nullptr) {
        ListNode* temp = curd;
        curd = curd->next;
        delete temp;
    }
    while (1);
}