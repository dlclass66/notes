//输入格式 字符串数组 字符串之间用空格隔开
//因为重复的也算所以一个hash数组不行 需要两个 一个用来统计前面n个的各个字符出现的频率 一个统计当前的 再用最小值更新 
//思想有点类似于动态规划
//char转换成string 利用string的构造函数 string（1， char）


#include <iostream>
#include <vector>

using namespace std;

 
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for (int i = 0; i < words[0].size(); i++) {
            hash1[words[0][i] - 'a']++;
        }
        for (int i = 1; i < words.size(); i++) {
            hash2 = vector<int>(26, 0);
            for (int j = 0; j < words[i].size(); j++) {
                hash2[words[i][j] - 'a']++;
            }
            for (int k = 0; k < hash1.size(); k++) {
                hash1[k] = min(hash1[k], hash2[k]);
            }
        }
        for (int i = 0; i < hash1.size(); i++) {
            if (hash1[i] > 0) {
                char temp = 'a' + i;
                int j = hash1[i];
                while (j > 0) {
                    ans.push_back(string(1, temp));
                    j--;
                }
            }
        }
        return ans;
    }
};

int main() {
    string s;
    vector<string> strs;
    while (cin >> s) {
        strs.push_back(s);
    }

    vector<string> ans = Solution().commonChars(strs);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}