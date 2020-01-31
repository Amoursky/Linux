#include<iostream>
#include<vector>
using namespace std;

// int main()
// {
//     // int a = 0;
//     // a = 'A' + 1.6;
//     // cout << a << endl;
//     int x = 10, y = 10;
//     x = y = ++y;
//     cout << x << " " << y << endl;
//     return 0;
// }

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int length = nums.size();
        for(int i = 0; i < length; i++)
        {
            if(nums[i] == target)
                return i;
            else if(target <= nums[i])
                return i;
        }
        if(target > nums[length - 1])
            return length;
     //return 0;
    }
};

int main()
{
    Solution A;
    std::vector<int> nums = {1,2,3,4,5};
    int b = 6;
    cout << A.searchInsert(nums,b) << endl; 
    return 0;
}