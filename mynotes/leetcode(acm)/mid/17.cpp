//可以用字符串数组完成数字到字符串的映射
//需要循环的只是每个数字对应的字符


#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> ans;
    string temp;
    vector<string> strmap{
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return ans;
        }
        backtrack(digits, 0);
        return ans;
    }
    void backtrack(string& str, int cur) {
        if (cur == str.size()) {
            ans.push_back(temp);
            return;
        }
        int num = str[cur] - '0';
        for (int j = 0; j < strmap[num].size(); j++) {
            temp.push_back(strmap[num][j]);
            backtrack(str, cur + 1);
            temp.pop_back();
        }
    }
};
int main() {
    string str;
    cin >> str;
    vector<string> ans = Solution().letterCombinations(str);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    while (1);
}