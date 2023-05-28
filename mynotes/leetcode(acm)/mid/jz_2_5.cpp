//使用hash数组保存每个string出现的字符 然后两层循环 开始准备先排序 但是排序并不能保证先遍历到的乘积大




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<bool>> hash(words.size(), vector<bool>(26, false));
        for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i]) {
                hash[i][ch - 'a'] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                int product = words[i].size() * words[j].size();
                if (product <= ans) {
                    continue;
                }
                bool qualify = true;
                for (char ch : words[j]) {
                    if (hash[i][ch - 'a']) {
                        qualify = false;
                        break;
                    }
                }
                if (qualify) {
                    ans = product;
                }
            }
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
    int ans = Solution().maxProduct(strs);
    cout << ans;
    while (1);
}