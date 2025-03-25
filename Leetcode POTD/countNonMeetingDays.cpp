#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countDays(int days, vector<vector<int>> &meetings)
{
    vector<int> vec(days, 0);

    for (auto &elem : meetings)
    {

        for (int j = elem[0]; j <= elem[1]; j++)
        {
            vec[j - 1] = 1;
        }
    }

    int cnt = 0;
    for (auto &elem : vec)
    {
        if (elem == 0)
            cnt++;
    }

    return cnt;
}

int countDays2(int days, vector<vector<int>> &meetings)
{
    map<int, int> dayMap;
    int prefixSum = 0, freeDays = 0, previousDay = days;
    bool hasGap = false;

    for (auto &meeting : meetings)
    {
        // Set first day of meetings
        previousDay = min(previousDay, meeting[0]);

        // Process start and end of meeting
        dayMap[meeting[0]]++;
        dayMap[meeting[1] + 1]--;
    }

    // Add all days before the first day of meetings
    freeDays += (previousDay - 1);
    for (auto &day : dayMap)
    {
        int currentDay = day.first;
        // Add current range of days without a meeting
        if (prefixSum == 0)
        {
            freeDays += currentDay - previousDay;
        }
        prefixSum += day.second;
        previousDay = currentDay;
    }

    // Add all days after the last day of meetings
    freeDays += days - previousDay + 1;
    return freeDays;
}

int main()
{

    return 0;
}