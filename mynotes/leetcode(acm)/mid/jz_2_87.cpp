//使用回溯算法 要注意对str的修改 以免回溯时出错



#include <iostream>
#include <vector>
#include <string>


using namespace std;



class Solution {
    vector<string> ans;
    string str;
public:
    vector<string> restoreIpAddresses(string s) {
        str = s;
        help(s, 0, 0);
        return ans;
    }

    bool qualify(string& s, int start, int end) {
        if (s[start] == '0' && end - start > 0) {
            return false;
        }
        int i = stoi(s.substr(start, end - start + 1));
        return i <= 255;
    }

    void help(string& s, int add, int start) {
        if (add == 4 && start == s.size()) {
            ans.push_back(str);
            ans.back().pop_back();
            return;
        }
        if (start >= s.size() || add >= 4) {
            return;
        }
        for (int i = start; i < start + 3; i++) {
            if (i >= s.size()) {
                break;
            }
            if (qualify(s, start, i)) {
                int temp = i + 1 + add;
                str.insert(str.begin() + temp, '.');
                add++;
                help(s, add, i + 1);
                add--;
                str.erase(str.begin() + temp);
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    vector<string> ans = Solution().restoreIpAddresses(s);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    while (1);
}