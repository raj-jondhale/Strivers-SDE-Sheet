// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]

// Constraints:

// 1 <= numRows <= 30

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;
        if (numRows == 0)
            return triangle;

        triangle.push_back({1});

        for (int i = 1; i < numRows; ++i)
        {
            vector<int> prev_row = triangle.back();
            vector<int> new_row = {1};

            for (int j = 1; j < prev_row.size(); ++j)
            {
                new_row.push_back(prev_row[j - 1] + prev_row[j]);
            }

            new_row.push_back(1);
            triangle.push_back(new_row);
        }

        return triangle;
    }
};