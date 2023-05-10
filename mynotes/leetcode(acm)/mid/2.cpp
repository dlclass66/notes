//输入格式 以数组构建链表 每行一个数组 
//用一个布尔变量表示是否进位 从头往尾遍历
//开始时考虑先转换为数字 但是位数过多



#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        :val(0), next(nullptr){}
    ListNode(int x)
        :val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode;
        help(pre, l1, l2, false);
        return pre->next;
    }
    void help(ListNode* pre, ListNode* l1, ListNode* l2, bool ten) {
        if (l1 == nullptr && l2 == nullptr) {
            if (ten) {
                ListNode* cur = new ListNode(1);
                pre->next = cur;
            }
            return;
        }
        if (l1 == nullptr) {
            pre->next = l2;
            if (ten) {
                int num = l2->val + 1;
                if (num < 10) {
                    l2->val = num;
                    return;
                }
                else {
                    l2->val = 0;
                    help(l2, l1, l2->next, ten);
                }
            }
            return;
        }
        if (l2 == nullptr) {
            help(pre, l2, l1, ten);
            return;
        }
        pre->next = l1;
        l1->val += l2->val;
        if (ten) {
            l1->val++;
        }
        if (l1->val >= 10) {
            ten = true;
            l1->val %= 10;
        }
        else {
            ten = false;
        }
        help(l1, l1->next, l2->next, ten);
    }
};

ListNode* creat(const vector<int>& vec) {
    int size = vec.size();
    if (size == 0) {
        return nullptr;
    }
    ListNode* head = new ListNode(vec[0]);
    ListNode* ans = head;
    for (int i = 1; i < size; i++) {
        ListNode* cur = new ListNode(vec[i]);
        head->next = cur;
        head = cur;
    }
    
    return ans;
}

int main() {
    int num = 0;
    vector<int> nums1;
    while (cin >> num) {
        nums1.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    vector<int> nums2;
    while (cin >> num) {
        nums2.push_back(num);
    }
    ListNode* l1(creat(nums1));
    ListNode* l2(creat(nums2));
    ListNode* ans =  Solution().addTwoNumbers(l1, l2);
    while (ans != nullptr) {
        cout << ans->val << ' ';
        ans = ans->next;
    }
    while (1);
}