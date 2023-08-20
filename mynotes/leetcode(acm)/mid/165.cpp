//输入格式 每行一个字符串
//写了一个函数得到每个修订号和下一个修订号的开始位置


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<int> getnum_end(string& str, int start) {
        if (start == -1 || start > str.size()) {
            return { 0, -1 };
        }
        while (start < str.size() && str[start] == '0') {
            if (str[start] == '.') {
                break;
            }
            start++;
        }
        if (start >= str.size()) {
            return { 0, -1 };
        }
        else if (str[start] == '.') {
            return { 0, start + 1 };
        }
        else {
            int end = start;
            while (end < str.size()) {
                if (str[end] == '.') {
                    break;
                }
                end++;
            }
            int num = stoi(str.substr(start, end - start));
            if (end == str.size()) {
                return { num, -1 };
            }
            else {
                return { num, end + 1 };
            }
        }
    }
public:
    int compareVersion(string version1, string version2) {
        int start1 = 0;
        int start2 = 0;
        while (start1 < version1.size() || start2 < version2.size()) {
            vector<int> v1 = getnum_end(version1, start1);
            vector<int> v2 = getnum_end(version2, start2);
            if (v1[0] < v2[0]) {
                return -1;
            }
            else if (v1[0] > v2[0]) {
                return 1;
            }
            else {
                start1 = v1[1];
                start2 = v2[1];
            }
        }
        return 0;
    }
};

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int a = Solution().compareVersion(s1, s2);
    cout << a;
    while(1);
}
