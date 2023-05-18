//全加器 有进位 尽量用一个while处理所有情况




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    string addBinary(string a, string b) {
        int indexa = a.size() - 1;
        int indexb = b.size() - 1;
        int add = 0;
        string ans;
        while (indexa >= 0 || indexb >= 0 || add > 0) {
            int numa = 0;
            int numb = 0;
            if (indexa >= 0) {
                numa = a[indexa] - '0';
            }
            if (indexb >= 0) {
                numb = b[indexb] - '0';
            }
            int cur = numa ^ numb ^ add;
            if (numa + numb + add > 1) {
                add = 1;
            }
            else {
                add = 0;
            }
            ans.insert(ans.begin(), '0' + cur);
            indexa--;
            indexb--;
        }
        return ans;
    }
};



int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;
    string ans = Solution().addBinary(a, b);
    cout << ans;
    while (1);
}