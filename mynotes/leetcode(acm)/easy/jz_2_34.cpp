//用一个hash数组表示每个字母在单词表中的位置 由题设 可把空白的位置设为-1
//输入格式 第一行order 后面每行一个字符




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> hash(27, 0);
        for (int i = 0; i < order.size(); i++) {
            hash[order[i] - 'a'] = i;
        }
        hash[26] = -1;
        for (int i = 0; i < 20; i++) {
            char prech = 'a' + 26;
            if (words[0].size() > i) {
                prech = words[0][i];
            }
            int count = 0;
            //统计当前字符比前一个字符靠后的情况的个数
            for (int j = 1; j < words.size(); j++) {
                char curch = 'a' + 26;
                if (words[j].size() > i) {
                    curch = words[j][i];
                }
                if (hash[curch - 'a'] < hash[prech - 'a']) {
                    return false;
                    //发现例外情况 直接false
                }
                else if (hash[curch - 'a'] > hash[prech - 'a']) {
                    count++;
                }
                prech = curch;
                if (count == words.size() - 1) {
                    return true;
                    //已经全部靠后 
                }
            }
        }
        return true;
    }
};



int main() {
    string order;
    cin >> order;
    string str;
    vector<string> strs;
    while (cin >> str) {
        strs.push_back(str);
    }
    bool ans = Solution().isAlienSorted(strs, order);
    cout << ans;
    while (1);
}