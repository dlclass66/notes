//需要考虑嵌套的形式 使用递归完成 也可以使用栈
//遍历 如果是小写字母 就添加到答案中 如果是数字 就把数字的位数++ 如果是[ 就往右找对应的] 找到了把之间的字符串解码 把前面的数字提取出来 往答案中加数字对应的次数



#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    string decodeString(string s) {
        string str;
        int numcount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' <= 9 && s[i] - '0' >= 0) {
                numcount++;
            }
            else if (s[i] - 'a' <= 26 && s[i] - 'a' >= 0) {
                str += s[i];
            }
            else if (s[i] == '[') {
                int tempi = i + 1;
                int leftnum = 1;
                while (tempi < s.size()) {
                    if (s[tempi] == '[') {
                        leftnum++;
                    }
                    if (s[tempi] == ']') {
                        leftnum--;
                        if (leftnum == 0) {
                            break;
                        }
                    }
                    tempi++;
                }
                string temp = decodeString(s.substr(i + 1, tempi - i - 1));
                int num = stoi(s.substr(i - numcount, numcount));
                while (num > 0) {
                    str += temp;
                    num--;
                }
                numcount = 0;
                i = tempi;
            }
        }
        return str;
    }
};



int main() {
    string str;
    cin >> str;
    string ans = Solution().decodeString(str);
    cout << ans;
    while (1);
}