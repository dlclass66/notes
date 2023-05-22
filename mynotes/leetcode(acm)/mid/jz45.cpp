//其实是排序问题 首先想到字典排序 但是对于没有数字的位数不一定就小 要看和有数字的数的对应的位数相比 如果比完了都没有结果 说明靠前的位数都相同 就比较靠后的位数 



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



class Solution {
public:
    struct cmp {
        bool operator()(int a, int b) {
            string astr = to_string(a);
            string bstr = to_string(b);
            int i = 0;
            int j = max(astr.size(), bstr.size());
            while (i < j) {
                //都有的 字典排序
                if (i < astr.size() && i < bstr.size()) {
                    if (astr[i] != bstr[i]) {
                        return astr[i] < bstr[i];
                    }
                }
                //b没有的 比较和a对应的
                else if (i < astr.size()) {
                    if (astr[i] != astr[i - bstr.size()]) {
                        return astr[i] < astr[0];
                    }
                } // a没有的
                else {
                    if (bstr[i] != bstr[0]) {
                        return bstr[i] > bstr[i - astr.size()];
                    }
                }
                i++;
            }
            //靠前的比较完了都没有结果 
            if (astr.size() < bstr.size()) {
                int aa = 0;
                int bb = bstr.size() - astr.size();
                while (aa < astr.size()) {
                    if (astr[aa] != bstr[bb]) {
                        return astr[aa] > bstr[bb];
                    }
                    aa++;
                    bb++;
                }
            }
            else {
                int aa = astr.size() - bstr.size();
                int bb = 0;
                while (aa < astr.size()) {
                    if (astr[aa] != bstr[bb]) {
                        return astr[aa] > bstr[bb];
                    }
                    aa++;
                    bb++;
                }
            }
            return a < b;
        }
    };
    string minNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), cmp());
        for (int i = 0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    string ans = Solution().minNumber(nums);
    cout << ans;
    while (1);
}