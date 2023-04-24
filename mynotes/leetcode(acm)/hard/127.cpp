//输入格式 第一行为beginword 第二行为endword 第三行为字符串数组 字符串之间用空格隔开
//要找最短路径 用bfs 要记录长度 可以是用unordered_map做字符串和路径长度的映射 也可以用队列元素的个数控制循环
//要用visited数组标记 避免死循环


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 0;
        unordered_map<string, int> hash;
        vector<int> visited(wordList.size(), 0);
        for (int i = 0; i < wordList.size(); i++) {
            hash.insert({ wordList[i], i });
        }
        if (hash.find(endWord) == hash.end()) {
            return ans;
        }
        ans = bfs(wordList, hash, visited, beginWord, endWord);
        return ans;
    }
    int bfs(vector<string>& wordList, unordered_map<string, int>& hash,
        vector<int>& visited, string& stra, string& endWord) {
        queue<int> qu;
        int ans = 1;
        qu.push(-1);
        while (!qu.empty()) {
            int qsize = qu.size();
            ans++;
            if (ans > wordList.size() + 1) {
                return 0;
            }
            for (int k = 0; k < qsize; k++) {
                int strnum = qu.front();
                string str;
                if (strnum == -1) {
                    str = stra;
                }
                else {
                    str = wordList[strnum];
                }
                qu.pop();
                for (int i = 0; i < str.size(); i++) {
                    char temp = str[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        if (j == temp) {
                            continue;
                        }
                        str[i] = j;
                        if (str == endWord) {
                            return ans;
                        }
                        if (hash.find(str) != hash.end()) {
                            int newstrnum = hash[str];
                            if (visited[newstrnum] == 1) {
                                continue;
                            }
                            qu.push(newstrnum);
                            visited[newstrnum] = 1;
                        }
                    }
                    str[i] = temp;
                }
            }
        }
        return 0;
    }
};
int main() {
    string beginword;
    cin >> beginword;
    string endword;
    cin >> endword;
    string str;
    vector<string> strs;
    while (cin >> str) {
        strs.push_back(str);   
    }
    int ans = Solution().ladderLength(beginword, endword, strs);
    cout << ans;
    while (1);
}