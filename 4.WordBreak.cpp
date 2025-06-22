/**
 * Given string s , find wether you can
 * segment the string s in dict succesfully
 * if it's true
 * else false
 *
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<bool> dp;
    string s;
    unordered_set<string> dict;

    bool dfs(int start)
    {
        if (start == s.size())
            return true;
        if (dp[start] != -1)
            return dp[start];

        for (int end = start + 1; end <= s.size(); end++)
        {
            string sub = s.substr(start, end - start);

            if (dict.count(sub))
            {
                if (dfs(end))
                {
                    return dp[start] = true;
                }
            }
        }

        return dp[start] = false;
    }

public:
    bool wordBreak(string &s, vector<string> &wordDict)
    {
        // Top Down Code
        //  this->dp = vector<int>(s.size(), -1);
        //  this->s = s;
        //  for (auto &word : wordDict)
        //  {
        //      dict.insert(word);
        //  }
        //  return dfs(0);

        // Bottom Up
        this->dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        this->dp = vector<bool>(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <=s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j])
                {
                    if (dict.count(s.substr(j, i - j)))
                    {
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
    string s = "catsandog";
    Solution sol;
    bool result = sol.wordBreak(s, wordDict);
    cout << boolalpha << result << endl; // Output: true
    return 0;
}

/**
 *
 * if we choose a word and move forward then we will get result out of that
 * path
 *
 * better to try many paths that will give the overall answer
 * break the problem and solve the small and use that for large
 * in this process we need so many function calls we use
 * dp cache array to store the results
 *
 * that will solve exponential recursion
 * at each index i we have more than one call
 *
 * so the time complexity is 2^n
 *
 * and s.c is O(n)
 *
 * cache the rework by storing
 *
 * we will choose one character
 * check is that in dict
 * ift's not add one character
 * again
 * checkk ... if it's in dict
 * then new call from that index
 * repeat if we found false in this journey
 * then we add one more character and start the journey
 * if we didn't found anything then false return or return true
 *
 * that's it dudee
 *
 * we need to do botto up too dudee
 *
 */