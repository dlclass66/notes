//按题目要求没有大数直接添加即可 如果有大数要使用string dfs 注意第一位不能是0即可


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        int num = pow(10, n);
        ans.reserve(num);
        for (int i = 1; i < num; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};



int main() {
    int num = 0;
    cin >> num;
    vector<int> ans = Solution().printNumbers(num);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}