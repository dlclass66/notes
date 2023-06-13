// 首先利用容斥原理 如果timepoints的长度大于24 * 60 那么必定有两个时间点的差值小于等于0
// 排序 比较相邻两个时间点的差值 取最小值 
// 注意最后一个时间点和第一个时间点的差值也要比较 可以把第一个时间点在最后也插入一份



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int ans = 12 * 60;
        int day = 24 * 60;
        if (timePoints.size() > day) {
            return 0;
        }
        sort(timePoints.begin(), timePoints.end());
        timePoints.push_back(timePoints[0]);
        for (int i = 1; i < timePoints.size(); i++) {
            int left = stoi(timePoints[i - 1].substr(0, 2)) * 60 +
                stoi(timePoints[i - 1].substr(3, 2));
            int right = stoi(timePoints[i].substr(0, 2)) * 60 +
                stoi(timePoints[i].substr(3, 2));
            int dif = min(abs(right - left), day - abs(right - left));
            ans = min(dif, ans);
        }
        return ans;
    }
};



int main() {
    string str;
    vector<string> strs;
    while (cin >> str) {
        strs.push_back(str);
	}
    int ans = Solution().findMinDifference(strs);
    cout << ans;
    
    while (1);
}