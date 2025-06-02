#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
    bool canPartition(vector<int>&nums){
        
    }
};

int main(){

    
    vector<int>nums{1,5,11,5};
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




















*/