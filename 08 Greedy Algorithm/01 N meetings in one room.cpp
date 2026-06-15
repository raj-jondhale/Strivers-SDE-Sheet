// Given two arrays s[] and f[], where s[i] denotes the start time and f[i] denotes the finish time of the i-th meeting. There is only one meeting room, find the maximum number of meetings that can be scheduled in the room such that no two selected meetings overlap in time. Return the indices(1-based) of the selected meetings in sorted (increasing) order.

// Note: If two meetings can be chosen for the same slot then choose meeting that finishes earlier.

// Examples:

// Input: s[] = [1, 3, 0, 5, 8, 5], f[] = [2, 4, 6, 7, 9, 9]
// Output: [1, 2, 4, 5]
// Explanation:
// We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.
// Input: s[] = [3] , f[] = [7]
// Output: [1]
// Explanation:
// Since there is only one meeting, we can attend the meeting.
// Constraints:
// 1 ≤ s.size() = f.size() ≤ 105
// 0 ≤ s[i] ≤ f[i] ≤ 109

class Solution
{
public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f)
    {
        // code here
        int N = s.size();
        vector<tuple<int, int, int>> res;
        for (int i = 0; i < N; i++)
        {
            res.push_back({f[i], s[i], i}); // (end, start, original index)
        }
        sort(res.begin(), res.end()); // sort by end time

        vector<int> ans;
        int lastEnd = -1;
        for (auto &[end, start, idx] : res)
        {
            if (start > lastEnd)
            {
                ans.push_back(idx + 1); // +1 for 1-based index
                lastEnd = end;
            }
        }

        sort(ans.begin(), ans.end()); // if the problem expects indices in increasing order
        return ans;
    }
};