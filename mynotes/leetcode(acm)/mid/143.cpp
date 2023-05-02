//输入格式 数组 数字间用空格隔开
//反转后半链表 一个一个插入 如果使用额外空间也可以用deque直接放入结点


#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode()
        :val(0), next(nullptr){}
    ListNode(int x)
        :val(x), next(nullptr){}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        ListNode* left = head;
        ListNode* right = slow->next;
        slow->next = nullptr;
        ListNode* lnext;
        ListNode* rnext;
        while (right != nullptr) {
            lnext = left->next;
            left->next = right;
            rnext = right->next;
            right->next = lnext;
            left = lnext;
            right = rnext;
        }
    }
    ListNode* reverse(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* cnext = head->next;
        ListNode* cur = head;
        while (cnext != nullptr) {
            ListNode* temp = cnext->next;
            cnext->next = cur;
            cur = cnext;
            cnext = temp;
        }
        head->next = nullptr;
        return cur;
    }
};

ListNode* creatlist(vector<int>& nums) {
    ListNode* dummy = new ListNode;
    ListNode* pre = dummy;
    for (int i = 0; i < nums.size(); i++) {
        ListNode* cur = new ListNode(nums[i]);
        pre->next = cur;
        pre = cur;
    }
    return dummy->next;
}
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    ListNode* head(creatlist(nums));
    Solution().reorderList(head);
    while (head != nullptr) {
        cout << head->val << ' ';
        head = head->next;
    }
    while (1);
}