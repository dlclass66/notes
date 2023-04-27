//输入格式 每行一个ticket 两个字符串之间用空格隔开
//使用hashmap 保留起飞机场（字符串）到可到达目的地（字符串数组）之间的映射
//字符串数组按字典顺序排序 因为题目要求按字典顺序输出 选择之后将选择的目的地暂时从字符串数组中移除



#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<string> ans;
    int count = 0;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        count = tickets.size();
        unordered_map<string, vector<string>> hash;
        for (int i = 0; i < tickets.size(); i++) {
            hash[tickets[i][0]].push_back(tickets[i][1]);
        }
        for (auto iter = hash.begin(); iter != hash.end(); iter++) {
            sort((*iter).second.begin(), (*iter).second.end());
        }
        string start("JFK");
        dfs(hash, start);
        return ans;
    }
    bool dfs(unordered_map<string, vector<string>>& hash, string& start) {
        if (count == 0) {
            ans.push_back(start);
            return true;
        }
        for (int i = 0; i < hash[start].size(); i++) {
            string str = hash[start][i];
            hash[start].erase(hash[start].begin() + i);
            ans.push_back(start);
            count--;
            if (dfs(hash, str)) {
                return true;
            }
            hash[start].insert(hash[start].begin() + i, str);
            count++;
            ans.pop_back();
        }
        return false;
    }
};
int main() {
    string str;
    vector<string> vec(2);
    vector<vector<string>> tickets;
    int i = 0;
    while (cin >> str) {
        vec[i] = str;
        i++;
        if (i == 2) {
            tickets.push_back(vec);
            i = 0;
        }
    }
    
    vector<string> ans = Solution().findItinerary(tickets);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}