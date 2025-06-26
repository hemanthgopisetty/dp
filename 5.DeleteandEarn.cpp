#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> dp;
    vector<int> val;

public:
    int fn(int i)
    {
        if (i >= val.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int dontPick = fn(i + 1);
        int pick = val[i] + fn(i + 2);

        return dp[i] = max(dontPick, pick);
    }
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        // Store the freq
        int maxVal = *max_element(nums.begin(), nums.end());
        // create a val array with maxVal
        this->val = vector<int>(maxVal + 1, 0);
        for (int i = 0; i < n; i++)
            val[nums[i]] += nums[i];

        // Store the subpoblems
        // this->dp=vector<int>(maxVal+1, -1);
        // dp[i] -> max value 0 to upto i'th index
        // this can be used for dp[i+1] right if it need instead of
        // re compute again

        // return fn(0);
        this->dp = vector<int>(maxVal + 1, 0);
        dp[0] = 0;
        if (maxVal >= 1)
        {
            dp[1] = val[1];
        }

        for (int i = 2; i <= maxVal; i++)
        {

            int dontPick = dp[i-1];
            int pick = val[i] + dp[i - 2];

            dp[i] = max(dontPick, pick);
        }
        return dp[maxVal];
    }
};
int main()
{

    vector<int> nums{2, 2, 3, 3, 4, 4};
    Solution sol;
    int result = sol.deleteAndEarn(nums);
    cout << result << endl;
    return 0;
}

/**
 *
 *
 * greedy solution is to pick the larget number each time
 * and do the operation
 * at the end whatever the value we are endiing up with t
 * that is the answer
 *
 * but this is greedy
 * descion to pick a number
 * a ripple effect on the future choices
 * by removing it's neighbours
 *
 * locally optimal choice
 * doesn;t gurante the global optimal
 * solution
 *
 *
 * better approach is dp
 * optimal solution of larger problem
 * can be built from optimal solutions of
 * smaller problems
 * and overlapping sub problems
 *
 *
 * the idea is store all frequencies
 * and sort the unique numbers
 * and pick the number with freq
 * if not then don't pick the number
 * go with next element dude
 *
 *
 *
 *
 * let's have an hashmap
 * let's have a dp to store the
 * subproblems(overlapping )
 *
 *
 * []->2,2,3,3,4,4
 * 2(2),3(2),4(2)
 *
 * let'start i choose 2, then i choose 4
 * since according to the question i+1 , i-1 was deleted right
 *
 * if suppose i skipped the 2 and i choose 3
 * then
 * i-1 -> 2 should be deleted
 * i+1 -> 4 should be deleted
 * right
 *
 * it tell us that chhose elements base on  the
 * logic I+2 elements right
 * since u delete i-1 and i+1
 * isn't
 *
 *
 * this is nothing but house robber right
 *
 * max(fn(i),val[i]+fn(i+2))
 *
 *
 * yes
 * 
 * the core idea of any dp problem is
 * the optimal solution of smaller problems is optimal solution
 * of larger problem
 * during this process
 * problems can come again due
 * to optimal solution of smaller version of same problem
 * for this we will cache by array
 * 
 * this is the opposite of
 * greedy , going the 
 * local optimal solution
 * can ripple the whole solution
 * impact's global solution and doesn't gurantee 
 * the local solution
 *
 */