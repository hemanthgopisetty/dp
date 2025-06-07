#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
    bool canPartition(vector<int>&nums)
    {

        int n=nums.size();
        if(n==0)return false;
        int totalSum=0;
        for(int i=0;i<n;i++)totalSum+=nums[i];
        if(totalSum%2!=0)return false;

        vector<vector<bool>>dp(n+1,vector<bool>(totalSum+1,false));
        int target = totalSum/2;
        //base case 
        for(int i=0;i<n;i++)dp[i][0]=1;

        for(int i=1;i<=n;i++)
        {
            int val=nums[i-1];
            for(int sum=0;sum<=target;sum++)
            {
                
            }
        }

    }
};

int main()
{

    vector<int>nums{};
    Solution sol;
    auto result = sol.canPartition(nums);
    cout<<boolalpha<<result<<endl;
    return 0;
}

/*

->partition the array into two parts(subsets) such that
sum of the two parts is equal 
return true or false

1,5,11,5 => 1,5,5 11 (true)
2,4,2    => 4,2 (true)

->subset is not contigous

if any point if we choose set of elements
then if sum of the set is equal to remaning sum of the elements in the array then
return true else false

ButeForce :-

bool canPartition(vector<int>&nums,int i=0,int sum1=0,int sum2=0){
        if(i>=nums.size()){
            return sum1==sum2;
        }

        bool subset1 = canPartition(nums,i+1,sum1+nums[i],sum2);
        bool subset2 = canPartition(nums,i+1,sum1,sum2+nums[i]);

        return subset1 || subset2;
    }


Optimise Buteforce :
we can only partition the array if sum is even ,it it's odd then we can't divide right 
if we can make half sum then other sum is in another subset sum
 let's find half sum if we can make half sum return true else false


    bool subsetSum(vector<int>&nums,int sum,int i=0){

        if(sum==0)return true;
        if(i>=nums.size() || sum<0)return false ;
        bool subset1=subsetSum(nums,sum-nums[i],i+1);
        bool subset2=subsetSum(nums,sum,i+1);

        return subset1 || subset2 ;
    }
    bool canPartition(vector<int>&nums){
        int n=nums.size();
        if(n==0)return false;

        int totalSum=0;
        for(int i=0;i<n;i++)totalSum+=nums[i];
        if(totalSum%2!=0)return false;
        return subsetSum(nums,totalSum/2);
    }

even this code takes lot of time to calcualte -> 2^n exponential 

subproblems occuring more than once so we need to store the subproblems and use this

Cache the sub problems 


vector<vector<int>> dp = vector<vector<int>>(201,vector<int>(10001,-1));
    bool subsetSum(vector<int>& nums, int sum, int i = 0) {
        if (sum == 0)return true;

        if (i >= nums.size() || sum < 0)return false;

        if(dp[i][sum]!=-1)return dp[i][sum];

        bool subset1 = subsetSum(nums, sum - nums[i], i + 1);

        bool subset2 = subsetSum(nums, sum, i + 1);

        return dp[i][sum]= (subset1 || subset2);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return false;

        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += nums[i];
        if (totalSum % 2 != 0)
            return false;
        return subsetSum(nums, totalSum / 2);
    }

Now the time complexity is o(n*sum) and sc is o(n)



*/