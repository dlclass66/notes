//输入格式 第一行数组 第二行 k
//用map或者unordered_map来存储元素和出现次数
//用小根堆来存储出现次数最多的k个元素
//注意优先队列的第二个模板参数是容器默认vector， 比较是第三个参数


#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        struct cmp {
            bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
                return p1.second < p2.second;
            }
        };
        priority_queue<pair<int, int>,vector<pair<int, int>>, cmp> pq;
        for (auto p : mp) {
            if (pq.size() < k) {
                pq.push(p);
            }
            else {
                if (pq.top().second < p.second) {
                    pq.pop();
                    pq.push(p);
                }
            }
        }
        vector<int> ans;
        ans.reserve(k);
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if(getchar() == '\n')
			break;
    }
    int k = 0;
    cin >> k;
    vector<int> ans = Solution().topKFrequent(nums, k);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}