#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxConsecutiveAnswers(string answerKey, int k)
{
    int finalAns = 0;
    int left = 0, trueCnt = 0, falseCnt = 0;

    for (int j = 0; j < answerKey.size(); j++)
    {
        if (answerKey[j] == 'T')
            trueCnt++;
        else
            falseCnt++;

        while (min(trueCnt, falseCnt) > k)
        {
            if (answerKey[left] == 'T')
                trueCnt--;
            else
                falseCnt--;

            left++;
        }
        finalAns = max(finalAns, j - left + 1);
    }

    return finalAns;
}
int main()
{

    return 0;
}