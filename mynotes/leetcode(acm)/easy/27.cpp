//双指针 不是很难 从后往前比较方便 注意异或符号
//这种方法交换次数最少
#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int valp = nums.size() - 1;
        int nvalp = valp;
        while (nvalp >= 0 && nums[nvalp] == val) {
            nvalp--;
            length--;
        }
        if (nvalp == -1) {
            return 0;
        }
        valp = nvalp - 1;
        while (valp >= 0) {
            while (valp >= 0 && nums[valp] != val) {
                valp--;
            }
            if (valp == -1) {
                break;
            }
            swap(nums, valp, nvalp);
            length--;
            valp--;
            nvalp--;
        }
        return length;
    }
private:
    void swap(vector<int>& nums, int a, int b) {
        nums[a] ^= nums[b];
        nums[b] ^= nums[a];
        nums[a] ^= nums[b];
        //int temp = nums[a];
        //nums[a] = nums[b];
        //nums[b] = temp;
    }
};
int main() {
    int num = 0;
    int target = 0;
    vector<int> myvec;
    while (cin >> num) {
        myvec.push_back(num);
        if (getchar() == '\n') {
            cin >> target;
            break;
        }
    }
    int count = Solution().removeElement(myvec, target);
    for (int i = 0; i < count; i++) {
        cout << myvec[i] << ' ';
    }
    while (1);
}