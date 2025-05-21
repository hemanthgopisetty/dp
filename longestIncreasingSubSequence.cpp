#include <bits/stdc++.h>
using namespace std;
int dfs(vector<int> &nums,int i,int prev)
{
    if(i>=nums.size())return 0;
    int pick=0;
    int dontPick=dfs(nums,i+1,prev);
    if(nums[i]>prev)
    {
        pick=1+dfs(nums,i+1,nums[i]);
    }
    return max(pick,dontPick);
}
int lengthOfLIS(vector<int> &nums)
{
    return dfs(nums,0,-1);    
}


int main()
{
    vector<int> nums{1,7,2,6,3,4};
    cout << lengthOfLIS(nums);
    return 0;
}

/**
 *
 * to find the largest increasing sub sequence in the given nums array
 * sub sequence -> derived from another array by deleting some or no elements   
 *                 without changing the order of the remaining elements.
 *
 * that sequence should be increasing 
 * 1,7,2,6,3,4 -> 1,2,3,4
 * 
 * if we observe the sequence is depended on prev number
 * by this we can say we need to try all the possibilites 
 * and generate longest sequence on that observation
 * 
 * to build the sequence we have barely
 * two opitons 
 *      -> pick the current if prev greater than curr
 *      -> don't pick the current number  
 * 
 * Recursion Done 
 */