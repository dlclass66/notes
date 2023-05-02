//输入格式 数组 数字间用空格隔开
//简单的方法是用一个vector存储反转的链表然后比较 （需要额外空间）
//复杂的是反转链表的后半部分 然后双指针比较 （不需要额外空间） 见下文



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
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        int size = 0;
        while (cur != nullptr) {
            size++;
            cur = cur->next;
        }
        vector<int> vec(size, 0);
        cur = head;
        int i = size - 1;
        while (i >= 0) {
            vec[i] = cur->val;
            cur = cur->next;
            i--;
        }
        cur = head;
        i = 0;
        while (cur != nullptr) {
            if (cur->val != vec[i]) {
                return false;
            }
            cur = cur->next;
            i++;
        }
        return true;
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
    bool ans = Solution().isPalindrome(head);
    cout << ans;
    while (1);
}


//反转后半部分链表 再比较
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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        ListNode* left = head;
        ListNode* right = slow->next;
        while (right != nullptr) {
            if (right->val != left->val) {
                return false;
            }
            right = right->next;
            left = left->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* cur = head;
        ListNode* cnext = head->next;
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
    bool ans = Solution().isPalindrome(head);
    cout << ans;
    while (1);
}