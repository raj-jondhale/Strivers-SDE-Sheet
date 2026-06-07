// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:

// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

// Constraints:

// 1 <= m, n <= 100

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to solve the problem using space optimization.
    int func(int m, int n)
    {
        /* Initialize a vector to represent
        the previous row of the grid.*/
        vector<int> prev(n, 0);

        // Iterate through the rows of the grid.
        for (int i = 0; i < m; i++)
        {
            /* Create a temporary vector to
            represent the current row.*/
            vector<int> temp(n, 0);

            for (int j = 0; j < n; j++)
            {
                // Base case
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                /* Initialize variables to store the number
                of ways from the cell above (up) and left (left).*/
                int up = 0;
                int left = 0;

                /* If we are not at the first row (i > 0), update
                'up' with the value from the previous row.*/
                if (i > 0)
                    up = prev[j];

                /* If we are not at the first column (j > 0),
                update 'left' with the value from current row.*/
                if (j > 0)
                    left = temp[j - 1];

                /* Calculate the number of ways to reach the
                current cell by adding 'up' and 'left'.*/
                temp[j] = up + left;
            }

            /* Update the previous row with values
            calculated for the current row.*/
            prev = temp;
        }

        /* The result is stored in the last
        cell of the previous row (n-1).*/
        return prev[n - 1];
    }

public:
    /*Function to count the total ways
    to reach (0,0) from (m-1,n-1)*/
    int uniquePaths(int m, int n)
    {

        // Return the total count(0 based indexing)
        return func(m, n);
    }
};
int main()
{
    int m = 3;
    int n = 2;

    // Create an instance of Solution class
    Solution sol;

    // Call the countWays function and print the result.
    cout << "Number of ways: " << sol.uniquePaths(m, n) << endl;

    return 0;
}