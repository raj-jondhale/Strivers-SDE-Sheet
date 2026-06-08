// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

// Examples:

// Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
// Output: 6
// Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
// Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
// Output: 5
// Explanation: Subarrays with sum = -5 are [-5] and [-5, 8, -14, 2, 4]. The length of the longest subarray with a sum of -5 is 5.
// Input: arr[] = [10, -10, 20, 30], k = 5
// Output: 0
// Explanation: No subarray with sum = 5 is present in arr[].
// Constraints:
// 1 ≤ arr.size() ≤ 105
// -104 ≤ arr[i] ≤ 104
// -109 ≤ k ≤ 109

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        map<long long, int> preSumMap;

        int maxLen = 0;
        long long sum = 0;

        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }
            long long rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if (preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
        }
        return maxLen;
    }
};

class Solution
{
public:
    // Function to find the length of longest subarray having sum k
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        // To store the maximum length of the subarray
        int maxLen = 0;

        // Pointers to mark the start and end of window
        int left = 0, right = 0;

        // To store the sum of elements in the window
        int sum = nums[0];

        // Traverse all the elements
        while (right < n)
        {

            // If the sum exceeds K, shrink the window
            while (left <= right && sum > k)
            {
                sum -= nums[left];
                left++;
            }

            // store the maximum length
            if (sum == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
            if (right < n)
                sum += nums[right];
        }

        return maxLen;
    }
};
