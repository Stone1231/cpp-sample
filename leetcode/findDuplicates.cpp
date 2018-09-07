#include <vector>
#include <iostream>
#include "../stdafx.h"
using namespace std;

//Given an array of integers, 1 ? a[i] ? n (n = size of array), 
//some elements appear twice and others appear once.
vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1] > 0) 
                res.push_back(abs(nums[i]));
        }
        return res;
}

int main()
{
    vector<int> nums{4,3,2,7,8,2,3,1};
    vector<int> ans = findDuplicates(nums);
    
    for (int x : ans)
        cout << x << " ";

    system("pause");

    return 0;
}