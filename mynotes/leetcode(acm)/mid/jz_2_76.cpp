//优先队列在queue头文件中 默认是大顶堆 
//使用堆即可



#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        struct cmp {
            bool operator()(int a, int b) {
                return a > b;
            }
        };
        priority_queue<int, vector<int>, cmp> pq;
        for (int i : nums) {
            if (pq.size() < k) {
                pq.push(i);
            }
            else {
                if (i > pq.top()) {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        return pq.top();
    }
};

int main() {
    int num = 0;
    vector<int>vec;
    while (cin >> num) {
        vec.push_back(num);
        if(getchar() == '\n')
			break;
    }
    int k = 0;
    cin >> k;
    int ans = Solution().findKthLargest(vec, k);
    cout << ans;
    while (1);
}