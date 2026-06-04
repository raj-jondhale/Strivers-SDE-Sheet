// Given an array of integers arr[]. You have to find the Inversion Count of the array.
// Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
// Input: arr[] = [2, 3, 4, 5, 6]
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.
// Input: arr[] = [10, 10, 10]
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104

class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        // Temporary array to store merged elements
        vector<int> temp;

        // Starting index of left half
        int left = low;
        // Starting index of right half
        int right = mid + 1;

        // Variable to count inversions
        int cnt = 0;

        // Merge elements in sorted order and count inversions
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); // All remaining left elements are inversions
                right++;
            }
        }

        // If left half still has elements
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        // If right half still has elements
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy back to original array
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        // Return inversion count
        return cnt;
    }

    // Merge sort function that counts inversions
    int mergeSort(vector<int> &arr, int low, int high)
    {
        // Variable to store inversion count
        int cnt = 0;

        // Base case
        if (low >= high)
            return cnt;

        int mid = (low + high) / 2;

        // Count inversions in left half
        cnt += mergeSort(arr, low, mid);
        // Count inversions in right half
        cnt += mergeSort(arr, mid + 1, high);
        // Count inversions during merge
        cnt += merge(arr, low, mid, high);

        return cnt;
    }
    int inversionCount(vector<int> &arr)
    {
        // Code Here
        return mergeSort(arr, 0, arr.size() - 1);
    }
};