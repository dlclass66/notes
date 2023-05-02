//输入格式 数组 数字之间用空格隔开
//先排序 这样相等的会在一起 用hash数组确定是否有出现次数相同的
//也可以先用hash数组统计每个数字出现的次数


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


 
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> hash(1001, 0);
        int count = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            }
            else {
                if (hash[count] == 1) {
                    return false;
                }
                hash[count] = 1;
                count = 1;
            }
        }
        if (hash[count] == 1) {
            return false;
        }
        return true;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    bool ans = Solution().uniqueOccurrences(nums);
    cout << ans;
    while (1);
}