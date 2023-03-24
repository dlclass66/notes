//输入格式 第一行为字符串1 第二行为字符串2
//第一种方法是先找到第一个字符相同的 然后利用substr 比较与模式串是否相同
//第二种方法是运用kmp算法
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        while (i < haystack.length()) {
            if (haystack[i] != needle[0]) {
                i++;
                continue;
            }
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
            i++;
        }
        return -1;
    }
};
int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    cout << Solution().strStr(s1, s2);
    while (1);
}

// kmp算法 还不够熟悉
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next(needle.length());
        init_next(next, needle);
        int h = 0;
        int n = 0;
        while (h < haystack.length() && n < needle.length()) {
            if (haystack[h] == needle[n]) {
                h++;
                n++;
            }
            else if(n > 0) {
                n = next[n - 1]; //都与next中索引减一有关
            }
            else {
                h++;
            }
        }
        if (n == needle.length()) {
            return h - needle.length();
        }
        else {
            return -1;
        }
    }
private:
    void init_next(vector<int>& next, const string& parttern) {
        int index = 1;
        while (index < parttern.length()) {
            int compindex = next[index - 1];
            while (compindex > 0 && parttern[index] != parttern[compindex]) {
                compindex = next[compindex - 1]; //都与next中索引减一有关
            }
            if (compindex == 0) {
                if (parttern[index] == parttern[0]) {
                    next[index] = 1;
                }
                else {
                    next[index] = 0;
                }
            } else {
                next[index] = compindex + 1;
            }
            index++;
        }
    }
};