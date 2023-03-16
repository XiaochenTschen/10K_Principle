#include <iostream>
#include <vector>

using namespace std;

int starting(vector<int>& nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while(l < r)
    {
        int mid = l + (r - l)/2;
        if(nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    return nums[l] == target?l:-1;
}
int ending(vector<int>& nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while(l < r)
    {
        int mid = l + (r - l )/2 + 1;
        if(nums[mid] > target)
            r = mid - 1;
        else
            l = mid;
    }
    return nums[r] == target?r:-1;
}

int main()
{
    vector<int> nums = {5,7,7,8,8,8,10};
    int target = 8;
    std::cout << starting(nums, target) << std::endl;
    std::cout << ending(nums, target) << std::endl;

    return 0;
}