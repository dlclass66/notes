//先遍历 得到每个字符最后出现的位置 （利用hash数组）
//再遍历 记录当前遍历过的字符的最后出现位置 若该位置等于当前位置 则此处可以分隔 （作为最后一个）


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> far(26, 0);
        for (int i = s.size() - 1; i >= 0; i--) {
            if (i > far[s[i] - 'a']) {
                far[s[i] - 'a'] = i;
            }
        }
        vector<int> ans;
        ans.reserve(s.size());
        int curmax = -1;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count++;
            if (far[s[i] - 'a'] > curmax) {
                curmax = far[s[i] - 'a'];
            }
            if (curmax == i) {
                ans.push_back(count);
                count = 0;
            }
        }
        return ans;
    }
};
int main() {
    string s;
    cin >> s;
    vector<int> ans = Solution().partitionLabels(s);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}