/**
 * we have to place all the books in the given shelf
 * we are given shelfwidth
 *
 * we have place the books in such a way that is less than or equal to the selfWidth
 * and and then build another level of shelf and place in such a way the
 * total height of the bookcase has increased by maximum height of the books
 * we just put down
 *
 *
 * note that each step of the above process ,
 * the order of the books we place is the same order
 * as the given sequence of the books
 *
 *
 * aim is to minimize the possible height
 * that bookshelf can be after placing shelves in this manner
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<vector<int>> books;
    int shelfWidth = 0;
    vector<vector<int>>dp;
    int dfs(int remaningWidth, int currentHeight, int i)
    {
        if (i == this->books.size())
            return currentHeight;
        if(dp[i][remaningWidth]!=-1)return dp[i][remaningWidth];
        int currentBookThickness = books[i][0];
        int currentBookHeight = books[i][1];

        int currentShelf = INT_MAX;

        if (remaningWidth >= currentBookThickness)
        {
            int newHeight = max(currentBookHeight, currentHeight);
            currentShelf = dfs(remaningWidth - currentBookThickness, newHeight, i + 1);
        }

        int newShelf = currentHeight + dfs(this->shelfWidth - currentBookThickness, currentBookHeight, i + 1);

        return dp[i][remaningWidth]=min(currentShelf, newShelf);
    }
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        this->books = books;
        this->shelfWidth = shelfWidth;
        this->dp = vector<vector<int>>(this->books.size(),vector<int>(shelfWidth+1,-1));
        // this is the shelf with no books
        return dfs(shelfWidth, 0, 0);
    }
};

int main()
{
    vector<vector<int>> books{
        {1, 1},
        {2, 3},
        {2, 3},
        {1, 1},
        {1, 1},
        {1, 1},
        {1, 2}};
    int shelfWidth = 2;
    Solution sol;
    int result = sol.minHeightShelves(books, shelfWidth);
    cout << result << endl;
    return 0;
}

/**
 * it's a good dp question
 * in minimum height we have to arrange all the books in such a way
 * there should be no more than the shelfwidth of the books we arrange
 * total height of the bookcase has increased by the maximum height of the books
 * we just put down
 *
 * which means
 *
 * 1,1 2,2 and w = 1
 * then
 *  b1
 *
 * all the books should be less than or equal to the shelfWidth thickness
 *
 * w=1
 * 1,1 1,2
 *
 * b2
 * b1  w=1 and height
 *
 * this question is basically we can summarize like
 * Given array , divide the array into groups such that a group should have at max lenght
 * and return the minimum possible maximum in all the groups by summing up
 *
 * the smartest way to arrange
 * these books so that our bookcase ends up being as short as possible.
 *
 * We start with all the books and make decisions one by one,
 *
 * from the first book to the last.
 *
 * For each book, we have two choices:
 *
 * a) Put it on the current shelf if there's space.
 *
 * b) Start a new shelf with this book.
 *
 *
 * We recursively explore both these options (when possible)
 * and choose the one that gives us the minimum overall height.
 *
 *
 * The key insight is that once we've made a decision for a book,
 * the problem becomes smaller
 *
 * we now have to make decisions for fewer books.
 *
 * This recursive structure naturally leads us to a top-down solution.
 *
 *
 *
 * books -> [1,2] , shelfWidth = 2
 *
 *
 */