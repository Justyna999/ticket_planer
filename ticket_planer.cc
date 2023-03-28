#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int last_day = days[n-1];
        vector<int> dp(last_day+1, 0); // initialize dp array

        for (int i = 1; i <= last_day; i++) {
            if (find(days.begin(), days.end(), i) != days.end()) { // if i is a travel day
                int one_day_cost = dp[i-1] + costs[0];
                int seven_day_cost = i >= 7 ? dp[i-7] + costs[1] : costs[1];
                int thirty_day_cost = i >= 30 ? dp[i-30] + costs[2] : costs[2];
                dp[i] = min(one_day_cost, min(seven_day_cost, thirty_day_cost));
            } else {
                dp[i] = dp[i-1]; // if i is not a travel day, copy the cost from the previous day
            }
        }

        return dp[last_day]; // return the cost of travel till the last day
    }
};

void quicksort(vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quicksort(arr, left, j);
    }
    if (i < right) {
        quicksort(arr, i, right);
    }
}

int main() {
    vector<int> days;
    int day;
    cout << "Enter days when you will travel (1-365), followed by -1 to end input: ";
   while (cin >> day && day >= 1 && day <= 365){

        days.push_back(day);
    }

      quicksort(days, 0, days.size()-1);

    vector<int> costs(3);
    cout << "Enter cost of one-day, seven-day, and thirty-day tickets: ";
    for (int i = 0; i < 3; i++) {
        cin >> costs[i];
    }

    Solution sol;
    int min_cost = sol.mincostTickets(days, costs);
    cout << "Minimum cost: " << min_cost << endl;

    return 0;
}
