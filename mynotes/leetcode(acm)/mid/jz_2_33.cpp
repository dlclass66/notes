//利用异位词排序后相同 作为key值 用hash表存储 用index记录其在ans的下标



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hash;
        int index = 0;
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (hash.find(temp) != hash.end()) {
                ans[hash[temp]].push_back(strs[i]);
            }
            else {
                ans.push_back({ strs[i] });
                hash[temp] = index;
                index++;
            }
        }
        return ans;
    }
};



int main() {
    string str;
    vector<string> strs;
    while (cin >> str) {
        strs.push_back(str);
	}
    vector<vector<string>> ans = Solution().groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
    
    while (1);
}