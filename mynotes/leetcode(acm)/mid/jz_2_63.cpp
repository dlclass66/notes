//输入格式 第一行sentence 后续每一个单词一行
//可以使用unordered_set 存储词典 双指针遍历sentence 找到单词就把sentence中单词后续标记为1 然后删除1




#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> root(dictionary.begin(), dictionary.end());
        int start = 0;
        int end = 0;
        while (end < sentence.size()) {
            while (end < sentence.size() && sentence[end] != ' ') {
                auto it = root.find
                (sentence.substr(start, end - start + 1));
                if (it != root.end()) {
                    end++;
                    while (end < sentence.size()
                        && sentence[end] != ' ') {
                        sentence[end] = '1';
                        end++;
                    }
                    break;
                }
                else {
                    end++;
                }
            }
            end++;
            start = end;
        }
        int i = 0;
        while (i < sentence.size()) {
            if (sentence[i] == '1') {
                int tempi = i;
                int j = 1;
                i++;
                while (i < sentence.size() && sentence[i] == '1') {
                    i++;
                    j++;
                }
                sentence.erase(tempi, j);
                i = tempi;
            }
            else {
                i++;
            }
        }
        return sentence;
    }
};

int main() {
    string sentence;
    getline(cin, sentence);
    string str;
    vector<string> dictionary;
    while (cin >> str) {
		dictionary.push_back(str);
	}
    string ans = Solution().replaceWords(dictionary, sentence);
    cout << ans;
    while (1);
}
