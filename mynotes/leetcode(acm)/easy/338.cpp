//直接的想法 分别计算每个i的1的数量 
//更高效的方法 使用动态规划



#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = bitcount(i);
        }
        return ans;
    }
    int bitcount(int x) {
        int count = 0;
        while (x != 0) {
            x &= (x - 1);
            count++;
        }
        return count;
    }
};


int main() {
    int num = 0;
    cin >> num;
    vector<int> ans =  Solution().countBits(num);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}


//动态规划的办法
//如果i是奇数 1的个数比前一个数多1
//如果i是偶数 1的个数和i/2相同

#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                ans[i] = ans[i - 1] + 1;
            }
            else {
                ans[i] = ans[i / 2];
            }
        }
        return ans;
    }
};


int main() {
    int num = 0;
    cin >> num;
    vector<int> ans =  Solution().countBits(num);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}