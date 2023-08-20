//使用一个unordered_map存储字典 用vaule bool变量表示是否已经访问过
//最短路径 使用bfs



#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 1;
        unordered_map<string, bool> hash;
        for (string& str : wordList) {
            hash[str] = true;
        }
        if (hash.find(endWord) == hash.end()) {
            return 0;
        }
        if (beginWord == endWord) {
            return 1;
        }
        queue<string> qu;
        qu.push(beginWord);
        while (!qu.empty()) {
            int num = qu.size();
            ans++;
            for (int j = 0; j < num; j++) {
                beginWord = qu.front();
                qu.pop();
                for (int i = 0; i < beginWord.size(); i++) {
                    char temp = beginWord[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == temp) {
                            continue;
                        }
                        beginWord[i] = ch;
                        if (beginWord == endWord) {
                            return ans;
                        }
                        if (hash.find(beginWord) != hash.end()
                            && hash[beginWord] == true) {
                            hash[beginWord] = false;
                            qu.push(beginWord);
                        }
                    }
                    beginWord[i] = temp;
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
    vector<string> wordlist;
    string str;
    while (cin >> str) {
		wordlist.push_back(str);
	}
    int ans = Solution().ladderLength(beginword, endword, wordlist);
    cout << ans;
    while (1);
}
