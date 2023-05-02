//先上升后下降 遇到不符合条件的就return false

#include <iostream>
#include <vector>

using namespace std;


 
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        int i = 1;
        for (; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                return false;
            }
            if (arr[i] < arr[i - 1]) {
                break;
            }
        }
        if (i >= arr.size() || i == 1) {
            return false;
        }
        for (; i < arr.size(); i++) {
            if (arr[i] >= arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    bool ans = Solution().validMountainArray(nums);
    cout << ans;
    while (1);
}