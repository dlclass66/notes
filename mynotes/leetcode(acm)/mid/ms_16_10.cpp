//用一个数组统计每年的人口变化数 然后遍历（从前往后） 得到现有人口最多的最小年份
//注意统计方法 减少的人口应该是上一年去世的 增加的人口是今年出生的




#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<vector<int>> year(1002, vector<int>(2, 0));
        for (int i = 0; i < birth.size(); i++) {
            year[birth[i] - 1900 + 1][0]++;
            year[death[i] - 1900 + 1][1]++;
        }
        int ans = 0;
        int count = 0;
        int maxcount = 0;
        for (int i = 1; i < year.size(); i++) {
            count = count + year[i][0] - year[i - 1][1];
            if (count > maxcount) {
                maxcount = count;
                ans = i + 1900 - 1;
            }
        }
        return ans;
    }
};



int main() {
    int num = 0;
    vector<int> birth;
    vector<int> death;
    while (cin >> num) {
		birth.push_back(num);
        if(getchar() == '\n')
			break;
	}
    while (cin >> num) {
        death.push_back(num);
    }
    int ans = Solution().maxAliveYear(birth, death);
    cout << ans;
    
    while (1);
}