// Given a string s, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.

// Examples:

// Input: s = "geek"
// Output: 2
// Explanation: We need to make minimum 2 cuts, i.e., "g | ee | k".
// Input: s = "aaaa"
// Output: 0
// Explanation: The string is already a palindrome.
// Input: s = "ababbbabbababa"
// Output: 3
// Explanation: We need to make minimum 3 cuts, i.e., "aba | bb | babbab | aba".
// Constraints:
// 1 ≤ |s| ≤ 103

// User function Template for C++

class Solution
{
public:
    bool isPalindrome(int start, int end, string &s)
    {

        while (start < end)
        {

            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    int solve(int ind, string &s, vector<int> &dp)
    {

        int n = s.size();

        if (ind == n)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int mini = INT_MAX;

        for (int i = ind; i < n; i++)
        {

            if (isPalindrome(ind, i, s))
            {

                int cost = 1 + solve(i + 1, s, dp);

                mini = min(mini, cost);
            }
        }

        return dp[ind] = mini;
    }

    int palPartition(string &s)
    {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, dp) - 1;
    }
};