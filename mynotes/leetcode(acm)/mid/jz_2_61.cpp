//选出和最小的 用大根堆 自定义优先队列的排序方式即可
//因为有大小关系 并不需要遍历所有组合 




#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        struct cmp {
            bool operator()(vector<int>& v1, vector<int>& v2) {
                return v1[0] + v1[1] < v2[0] + v2[1];
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (pq.size() < k) {
                    pq.push({ nums1[i], nums2[j] });
                }
                else if (nums1[i] + nums2[j] >= pq.top()[0] + pq.top()[1]) {
                    break;
                }
                else {
                    pq.pop();
                    pq.push({ nums1[i], nums2[j] });
                }
            }
        }
        vector<vector<int>> ans;
        ans.reserve(k);
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int num = 0;
    vector<int> nums1;
    while (cin >> num) {
        nums1.push_back(num);
        if(getchar() == '\n')
			break;
    }
    vector<int> nums2;
    while (cin >> num) {
        nums2.push_back(num);
        if (getchar() == '\n')
            break;
    }
    int k = 0;
    cin >> k;
    vector<vector<int>> ans = Solution().kSmallestPairs(nums1, nums2, k);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
    while (1);
}