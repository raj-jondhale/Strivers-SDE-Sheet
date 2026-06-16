// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        // Create two vectors for previous and current rows
        vector<int> prev(amount + 1, 0);
        vector<int> cur(amount + 1, 0);

        // Initialize base case for the first row
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            // Very large value if not possible
            else
                prev[i] = 1e9;
        }

        // Fill table using bottom-up approach
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= amount; target++)
            {

                // Option 1: Not take the current element
                int notTake = prev[target];

                // Option 2: Take the current element if possible
                int take = 1e9;
                if (coins[ind] <= target)
                    take = 1 + cur[target - coins[ind]];

                // Store minimum of take and notTake
                cur[target] = min(notTake, take);
            }

            // Update previous row with current row values
            prev = cur;
        }

        // Retrieve answer from the last row
        int ans = prev[amount];

        // Return -1 if target cannot be formed
        if (ans >= 1e9)
            return -1;

        // Return minimum number of elements required
        return ans;
    }
};