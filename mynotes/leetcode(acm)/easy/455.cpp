//输入格式 第一行是数组g 数字间用空格隔开 第二行是数组s 数字间用空格隔开
//贪心 尽量用最小的饼干满足孩子的胃口 所以把饼干和胃口都排序 然后遍历饼干即可


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int j = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j >= g.size()) {
                break;
            }
            else {
                if (s[i] < g[j]) {
                    continue;
                }
                else {
                    ans++;
                    j++;
                }
            }
        }
        return ans;
    }
};
int main() {
    int num = 0;
    vector<int> g;
    vector<int> s;
    while (cin >> num) {
        g.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    while (cin >> num) {
        s.push_back(num);
    }
    int ans = Solution().findContentChildren(g,s);
    cout << ans << endl;
    while (1);
}