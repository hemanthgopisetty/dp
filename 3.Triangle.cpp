/**
 * Find minimum path sum from top to bottom
 *
 *
 * for each step if you are at index i on the
 * current row , you may have to move either
 * index i or index i+1 on the next row
 *
 *
 *
 */

#include <bits/stdc++.h>

using namespace std;
class Solution
{
private:
    vector<vector<int>> dp;
    int n;

    // Top Down Approach
    int dfs(vector<vector<int>> &triangle, int i, int j)
    {
        // base case
        if (i >= (int)triangle.size())
            return 0;
        // check if already calculated
        if (dp[i][j] != -1)
            return dp[i][j];
        // at each i
        int left = triangle[i][j] + dfs(triangle, i + 1, j);
        int right = triangle[i][j] + dfs(triangle, i + 1, j + 1);
        return dp[i][j] = min(left, right);
    }

    // Bottom Up Approach
    //2D DP
    int bfs(vector<vector<int>> &triangle)
    {
        n = triangle.size();
        dp = vector<vector<int>>(n);
        // Resize the array
        for (int i = 0; i < n; i++)
        {
            dp[i].resize(triangle[i].size());
        }
        // Intialize the base case
        for (int j = 0; j < triangle[n-1].size(); j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Fill the Table by building the sol
        // from large problems to smaller problems
        // bottom - up
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                int element = triangle[i][j];
                dp[i][j]=element+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }

public:
    Solution() {}

    int minimumTotal(vector<vector<int>> &triangle)
    {
        // n = triangle.size();
        // dp = vector<vector<int>>(n, vector<int>(n, -1));
        // return dfs(triangle, 0, 0);
        return bfs(triangle);
    }
};

int main()
{
    vector<vector<int>> nums{
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    Solution sol;
    int result = sol.minimumTotal(nums);
    cout << result << endl;
    return 0;
}

/**
 *
 * Solution :
 *
 * aim is to find the minimum path sum
 * from i'th index
 *
 * we can choose minimum element and step forward each time
 * but this will effect later path where going forward
 * we can have maximum elements
 *
 * so it's better to try all paths
 * out of all paths we can choose min sum
 *
 * to traverse all paths we can
 * at current index i
 * we have two options
 *  current i in next row
 *  next i in next row
 *  traversing all the indexe's we will reach out of index
 *
 * thus base case is
 * if(i>=n)return 0;
 *
 * at each i
 * i->min(fn(triangle,i+1,j)+fn(triangle,i+1,j+1))
 *
 * the above recurrence has many overlapping or re occuring
 * functional call or sub problems
 *
 *
 *
 *
 *
 * int dfs(vector<vector<int>> &triangle, int i, int j)
    {
        //base case
        if (i >= (int)triangle.size())
            return 0;
        // at each i
        int left = triangle[i][j] + dfs(triangle, i + 1, j);
        int right = triangle[i][j] + dfs(triangle, i + 1, j + 1);
        return min(left, right);
    }

 *
 */