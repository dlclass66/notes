//输入格式 第一行是数组 数字间用空格隔开
//使用单调队列（队列中元素单调）front会是最大的 加入元素时弹出尾部比它小的（这些都不可能后面成为最大值）
//弹出元素时 如果需要移除的是front 就弹出 否则无动作
//底层用deque实现
//时间复杂度为n 每个元素最多被加入或者弹出一次
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        ans.reserve(nums.size() - k + 1);
        upque myque;
        for (int i = 0; i < nums.size(); i++) {
            myque.push(nums[i]);
            if (i >= k) {
                if (nums[i - k] == myque.front()) {
                    myque.pop();
                }
            }
            if (i >= k - 1) {
                ans.push_back(myque.front());
            }
        }
        return ans;
    }
private:
    class upque {
    private:
        deque<int> m_deque;
    public:
        void pop() {
            m_deque.pop_front();
        }
        void push(int x) {
            while (!m_deque.empty() && x > m_deque.back()) {
                m_deque.pop_back();
            }
            m_deque.push_back(x);
        }
        int front() {
            return m_deque.front();
        }
    };
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    int k = 0;
    cin >> k;
    vector<int> ans = Solution().maxSlidingWindow(nums, k);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}