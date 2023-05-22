//排序去重 使用了的做标记 回溯算法


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<string> ans;
    string str;
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        help(s);
        return ans;
    }
    void help(string& s) {
        if (str.size() == s.size()) {
            ans.push_back(str);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && s[i] == s[i - 1] || s[i] == '0') {
                continue;
            }
            else {
                str.push_back(s[i]);
                char temp = s[i];
                s[i] = '0';
                help(s);
                s[i] = temp;
                str.pop_back();
            }
        }
    }
};


int main() {
    string str;
    cin >> str;
    vector<string> ans = Solution().permutation(str);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    while (1);
}