//直接的办法是遍历 
//因为有序（局部）可以采用二分 



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                //已经符合条件了
                return mid;
            }
            else if (arr[mid] > arr[mid - 1]) {
                //mid在左侧
                left = mid;
            }
            else {
                //mid在右侧
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    int num = 0;
    vector<int> arr;
    while (cin >> num) {
        arr.push_back(num);
    }
    int ans = Solution().peakIndexInMountainArray(arr);
    cout << ans;
    while (1);
}