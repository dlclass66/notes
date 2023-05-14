//输入格式 数组 
//利用分段有序性实现二分查找



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            //说明没有调整
            if (numbers[left] < numbers[right]) {
                return numbers[left];
            }
            //说明mid在左侧
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            }
            //说明mid在右侧
            else if (numbers[mid] < numbers[right]) {
                right = mid;
            }
            //无法判断 退出 线性查找
            else if (numbers[mid] == numbers[right]) {
                break;
            }
        }
        while (right >= left && right - 1 >= 0) {
            if (numbers[right] < numbers[right - 1]) {
                return numbers[right];
            }
            right--;
        }
        return numbers[0];
    }
};



int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().minArray(nums);
    cout << ans;
    while (1);
}