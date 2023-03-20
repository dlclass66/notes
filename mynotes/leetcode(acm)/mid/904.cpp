//输入格式 一行数组 数字间用空格隔开
//对左边收缩的判断需要知道水果的种类和数量
#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() < 3) {
            return fruits.size();
        }
        int maxlength = 2;
        array<int, 2> kind{ -1, -1 };
        array<int, 2> count{ 0, 0 };
        int left = 0;
        int right = 1;
        kind[0] = fruits[0];
        while (right < fruits.size() && fruits[right] == fruits[0]) {
            right++;
        }
        if (right == fruits.size()) {
            return fruits.size();
        }
        kind[1] = fruits[right];
        count[0] = right - left;
        count[1] = 1;
        right++;
        for (; right < fruits.size(); right++) {
            if (count[0] + count[1] > maxlength) {
                maxlength = count[0] + count[1];
            }
            if (fruits[right] == kind[0] || fruits[right] == kind[1]) {
                if (fruits[right] == kind[0]) {
                    count[0]++;
                }
                else {
                    count[1]++;
                }
            }
            else {
                if (fruits[right - 1] == kind[0]) {
                    while (count[1] > 0) {
                        if (fruits[left] == kind[1]) {
                            count[1]--;
                        }
                        else {
                            count[0]--;
                        }
                        left++;
                    }
                    kind[1] = fruits[right];
                    count[1] = 1;
                }
                else {
                    while (count[0] > 0) {
                        if (fruits[left] == kind[0]) {
                            count[0]--;
                        }
                        else {
                            count[1]--;
                        }
                        left++;
                    }
                    kind[0] = fruits[right];
                    count[0] = 1;
                }
            }
        }
        return max(count[0] + count[1], maxlength);
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().totalFruit(nums);
    cout << ans;
    while (1);
}