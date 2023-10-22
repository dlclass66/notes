//输入格式 数组 数字间用空格隔开
//先排序 从小到大遍历 这样可以得到比当前引用数大的文章数 


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0;
        int n = citations.size();
        for (int i = 0; i < n; i++) {
            ans = max(ans,
                min(n - i, citations[i]));
        }
        return ans;
    }
};

int main() {
    vector<int> nums;
    int num = 0;
    while (cin >> num) {
        nums.push_back(num);
    }
    int h =  Solution().hIndex(nums);
    cout << h;
    while (1);
}
