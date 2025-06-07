#include <bits/stdc++.h>
using namespace std;
int dfs(vector<int> &nums, int i, int prevI,vector<vector<int>>&dp)
{
    if (i >= nums.size())return 0;

    if(dp[i][prevI+1]!=-1)return dp[i][prevI+1];

    int pick = 0;
    int dontPick = dfs(nums, i + 1, prevI,dp);

    if (prevI==-1 or nums[i] > nums[prevI])
    {
        pick = 1 + dfs(nums, i + 1, i,dp);
    }
    return dp[i][prevI+1]=max(pick, dontPick);
}

int lengthOfLIS(vector<int> &nums)
{
    int n=nums.size();

    //Top Down Approach 

    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return dfs(nums, 0, -1,dp);

    //Bottom Up
    if(n==0)return 0;
    vector<vector<int>>dp(n,vector<int>(n,0));
    //Base Case
    dp[0][0]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j];

            for(int k=0;k<j;k++){
                if(nums[k]<nums[j]){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+1);
                }
            }

            if(j==i){
                dp[i][j]=max(dp[i][j],1);
            }
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<n;j++)
        {

            ans=max(ans,dp[i][j]);
        }
    }
    return ans ;
}

int main()
{
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    int result = lengthOfLIS(nums);
    cout << result << endl;
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
 * -> Top Down Approach
 * Recursion Done
 * Cache Done in Recursion
 *  
 * -> Bottom Up Approach
 *  in top down we are storing the results as
 * dp[i][prevI] -> where it stores the longest increasing 
 * sub sequence  from i to last prevI 
 * 
 * we can further reduce this to dp[i] -> where it stores the longest Increasing
 * sub sequence upto i
 * 
 * every element is itself a lis right ...........
 * to compute this we need to look at all the indices till i
 * for i to n :
 *  for j to i :
 *      if nums[i]>nums[j]
 */