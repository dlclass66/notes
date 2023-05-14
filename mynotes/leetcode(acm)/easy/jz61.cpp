//输入格式 数组
//用hash数组 找到最小的牌（除0） 判断连续的5个是否能用0把没有的牌填上


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<int> hash(14, 0);
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
            if (nums[i] != 0 && hash[nums[i]] > 1) {
                return false;
            }
        }
        int count = hash[0];
        int j = 1;
        while (j < hash.size()) {
            if (hash[j] == 1) {
                for (int i = j; i < hash.size() && i < j + nums.size(); i++) {
                    if (hash[i] != 1) {
                        count--;
                    }
                }
                if (count < 0) {
                    return false;
                }
                break;
            }
            j++;
        }
        return true;
    }
};



int main() {
    int num = 0;
    vector<int> nums;
    nums.reserve(5);
    while (cin >> num) {
        nums.push_back(num);
    }
    bool ans = Solution().isStraight(nums);
    cout << ans;
    while (1);
}