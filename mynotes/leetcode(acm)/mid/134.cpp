//输入格式 第一行为gas数组 数字间用空格隔开 第二行为cost数组 数字间用空格隔开
//遍历每个可能的出发位置 注意发现无法绕圈后 中间已经到达的点也不可能是出发点



#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int mygas = 0;
        int start = 0;
        int count = 0;
        while (start < gas.size()) {
            int cur = start;
            while (mygas >= 0) {
                if (cur - start == gas.size()) {
                    return start;
                }
                mygas += gas[cur % gas.size()] - cost[cur % gas.size()];
                cur++;
            }
            start = cur;
            mygas = 0;
        }
        return -1;
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    vector<int> cost;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    while (cin >> num) {
        cost.push_back(num);
    }
    int ans = Solution().canCompleteCircuit(nums, cost);
    cout << ans << endl;
    while (1);
}