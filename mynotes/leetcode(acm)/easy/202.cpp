//关键是注意到无限循环 使用unordered_set判断是否重复
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        while (n != 1) {
            if (hash.find(n) != hash.end()) {
                return false;
            }
            hash.insert(n);
            n = next(n);
        }
        return true;
    }
    int next(int x) {
        int sum = 0;
        while (x > 0) {
            int num = x % 10;
            sum += num * num;
            x /= 10;
        }
        return sum;
    }
};
int main() {
    int target = 0;
    cin >> target;
    cout << Solution().isHappy(target);
    while (1);
}