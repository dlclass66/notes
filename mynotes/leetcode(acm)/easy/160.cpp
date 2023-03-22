//输入比较复杂 就不进行设计了 
//注意移动之后一开始就相等的情况
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int sizea = 0;
        int sizeb = 0;
        ListNode* cura = headA;
        ListNode* curb = headB;
        while (cura != nullptr) {
            cura = cura->next;
            sizea++;
        }
        while (curb != nullptr) {
            curb = curb->next;
            sizeb++;
        }
        cura = headA;
        curb = headB;
        if (sizea < sizeb) {
            cura = headB;
            curb = headA;
            int temp = sizea;
            sizea = sizeb;
            sizeb = temp;
        }
        while (sizea > sizeb) {
            cura = cura->next;
            sizea--;
        }
        while (cura != nullptr && curb != nullptr) {
            if (cura == curb) {
                return cura;
            }
            if (cura->next == curb->next) {
                return cura->next;
            }
            cura = cura->next;
            curb = curb->next;
        }
        return nullptr;
    }
};
int main() {
    
}