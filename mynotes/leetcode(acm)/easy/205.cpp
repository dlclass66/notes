//双向映射 使用两个hash数组来映射 


#include <iostream>
#include <vector>

using namespace std;

 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> hashs(200, -1);
        vector<int> hasht(200, -1);
        for (int i = 0; i < s.size(); i++) {
            if (hashs[s[i] - 0] != -1 && hashs[s[i] - 0] != t[i] - 0) {
                return false;
            }
            if (hasht[t[i] - 0] != -1 && hasht[t[i] - 0] != s[i] - 0) {
                return false;
            }
            hashs[s[i] - 0] = t[i] - 0;
            hasht[t[i] - 0] = s[i] - 0;
        }
        return true;
    }
};

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    bool ans = Solution().isIsomorphic(s, t);
    cout << ans;
    while (1);
}