/**
 *
 * give n house find out the minimum cost of the paiting house such
 * that no adjacent house would have same colour
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;

    int minCost(vector<vector<int>> &costs, int houses)
    {

        if (houses == 0)
            return 0;
        this->n = houses;
        this->costs = costs;
        return bottomUp();
        // bottom up
        // we will come from bottom up means
        // from base case to n-1

        int house = 0;
        int answer = INT_MAX;
        for (int currentColor = 0; currentColor < 3; currentColor++)
        {
            int currentHouseCost = this->costs[house][currentColor];
            int nextHousesCost = helper(house + 1, currentColor);
            if (nextHousesCost != INT_MAX)
            {
                answer = min(answer, currentHouseCost + nextHousesCost);
            }
        }
        return answer;
        // above is top down approach
    }

private:
    vector<vector<int>> costs;
    map<pair<int, int>, int> dp;
    int bottomUp()
    {

        // Start from the bottom
        dp[{0, 0}] = costs[0][0];
        dp[{0, 1}] = costs[0][1];
        dp[{0, 2}] = costs[0][2];
        for (int i = 1; i < n; i++)
        {
            dp[{i, 0}] = costs[i][0] + min(costs[i - 1][1], costs[i - 1][2]);
            dp[{i, 1}] = costs[i][1] + min(costs[i - 1][0], costs[i - 1][2]);
            dp[{i, 2}] = costs[i][2] + min(costs[i - 1][0], costs[i - 1][1]);
        }
        int ans = INT_MAX;
        ans = min(ans, dp[{n - 1, 0}]);
        ans = min(ans, dp[{n - 1, 1}]);
        ans = min(ans, dp[{n - 1, 2}]);

        return ans;
    }
    int helper(int currentHouse, int prevColor)
    {
        if (currentHouse == this->n)
            return 0;

        if (dp.count({currentHouse, prevColor}))
            return dp[{currentHouse, prevColor}];

        int answer = INT_MAX;

        for (int currentColor = 0; currentColor < 3; currentColor++)
        {
            if (currentColor == prevColor)
                continue;

            int currentHouseCost = this->costs[currentHouse][currentColor];
            int nextHousesCost = helper(currentHouse + 1, currentColor);

            if (nextHousesCost != INT_MAX)
            {
                answer = min(answer, currentHouseCost + nextHousesCost);
            }
        }
        return dp[{currentHouse, prevColor}] = answer;
    }
};
int main()
{
    vector<vector<int>> cost{
        {1, 0, 3},
        {1, 4, 6},
    }; // answer is 3
    int houses = 2;
    Solution sol;
    int result = sol.minCost(cost, houses);
    cout << result << endl;
    return 0;
}
/**
 * if we pick the minimum in cost[i]
 * and we should not pick the same colour again
 * and should pick the next minimum in cost[i+1]
 *
 * what if in i+1 , the same colour has
 * the minimum out of all colors
 *
 * and if we pick that next min the cost increase right
 * instead we will pick the this minimum i+1
 * and we pick another minimum colour in i-1
 *
 * this tells us that local optimal solution can;t give gurantee that
 * global optimal solution
 *
 * this is known as greedy approach
 *
 * so we should try out lot of descions based
 * search known as exhaustive search which can give the correct minimum
 *
 * this is known as dynamic programming
 *
 * for each house
 * we need to find the minimum by trying all
 * clours
 * and repeat this
 *
 *
 *
 */