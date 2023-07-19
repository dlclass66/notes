//用一个栈 正数直接入栈 负数就判段栈顶元素和负数的大小
//因为最后的结果要用响应的顺序返回 所以用deque



#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        ans.reserve(asteroids.size());
        deque<int> de;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                de.push_back(asteroids[i]);
            }
            else {
                while (!de.empty() && de.back() > 0 && de.back() + asteroids[i] < 0) {
                    de.pop_back();
                }
                if (de.empty() || de.back() < 0) {
                    de.push_back(asteroids[i]);
                }
                else if (de.back() + asteroids[i] == 0) {
                    de.pop_back();
                }
            }
        }
        while (!de.empty()) {
            ans.push_back(de.front());
            de.pop_front();
        }
        return ans;
    }
};

int main() {
    int num = 0;
    vector<int>vec;
    while (cin >> num) {
        vec.push_back(num);
    }
    vector<int> ans = Solution().asteroidCollision(vec);
    for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
    while (1);
}