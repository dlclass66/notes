//输入格式 第一行数组 中间用空格隔开 第二行为k
//频率前k高 考虑使用优先队列（小顶堆）
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue> //优先队列在这里面

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        ans.reserve(k);
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> pri; //底层是vector
        unordered_map<int, int> mymap;
        for (int i : nums) {
            mymap[i]++;
        }
        for (auto& i : mymap) {
            pri.push(i);
            if (pri.size() > k) {
                pri.pop();
            }
        }
        while (!pri.empty()) {
            ans.push_back(pri.top().first); //注意顶部是top（） 不是front（）
            pri.pop();
        }
        return ans;
    }
private:
    class mycomp {
    public:  //注意必须是public
        bool operator() (const pair<int, int>& pa1, const pair<int, int>& pa2) {
            return pa1.second > pa2.second;
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
    vector<int> ans = Solution().topKFrequent(nums, k);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}