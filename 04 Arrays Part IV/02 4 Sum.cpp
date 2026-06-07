// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

class Solution
{
public:
    // Function to find all unique quadruplets
    vector<vector<int>> fourSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        set<vector<int>> st;

        // First loop - pick first number
        for (int i = 0; i < n; i++)
        {
            // Second loop - pick second number
            for (int j = i + 1; j < n; j++)
            {
                // HashSet to store numbers between j and k
                unordered_set<int> seen;

                // Third loop - pick third number
                for (int k = j + 1; k < n; k++)
                {
                    // Find required fourth number
                    long long required = (long long)target - arr[i] - arr[j] - arr[k];

                    // If required number is already in set, we found a quadruplet
                    if (seen.count(required))
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], (int)required};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    // Add current third number into set
                    seen.insert(arr[k]);
                }
            }
        }

        // Convert set into vector and return
        return vector<vector<int>>(st.begin(), st.end());
    }
};