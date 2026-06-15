// Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places.

// Examples :

// Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
// Output: 240.000000
// Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240
// Input: val[] = [500], wt[] = [30], capacity = 10
// Output: 166.670000
// Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 of it, yielding value 166.670000.
// Constraints:
// 1 ≤ val.size = wt.size ≤ 105
// 1 ≤ capacity ≤ 109
// 1 ≤ val[i], wt[i] ≤ 104

class Solution
{
public:
    static bool compare(pair<int, int> &a, pair<int, int> &b)
    {

        double r1 = (1.0 * a.first) / a.second;
        double r2 = (1.0 * b.first) / b.second;

        return r1 > r2;
    }

    double fractionalKnapsack(vector<int> &val,
                              vector<int> &wt,
                              int capacity)
    {

        int n = val.size();

        vector<pair<int, int>> items;

        for (int i = 0; i < n; i++)
        {
            items.push_back({val[i], wt[i]});
        }

        sort(items.begin(), items.end(), compare);

        double res = 0;

        for (int i = 0; i < n; i++)
        {

            if (items[i].second <= capacity)
            {

                res += items[i].first;

                capacity -= items[i].second;
            }

            else
            {

                res += (1.0 * items[i].first / items[i].second) * capacity;

                break;
            }
        }

        return res;
    }
};