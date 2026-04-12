#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
	using ll = long long;
	ll ub = 2 * 1e5;
	int range;

	vector<int> sieve = vector<int>(ub + 1, 1);

public:
	Solution(int range)
	{
		this->range = range;
		sieve[0] = 0;
		sieve[1] = 1;
	}
	void buildSieve()
	{
		for (int i = 2; i * i <= range; i++)
		{
			// looping from 2 till sqrt(range) (inclusive).
			if (sieve[i])
			{
				// If the ith number is marked as prime, then mark all it's multiples as non prime.
				// We start the inner loop from i^2. This is because every element < i^2, had already been marked by some number that ocurred before i, so we can safely start from i^2, rather than starting from 2 for each number.

				// In this loop, the increment step is incrementing x by i. Let's take an arbitrary number 'i'.
				// multiples of i = i , 2 * i, 3 * i, 4 * i....and so on. So we are just simulating this pattern.
				for (int x = i * i; x <= range; x += i)
				{
					sieve[x] = 0;
				}
			}
		}
	}

	void printPrimes()
	{
		buildSieve();
		for (int i = 2; i <= range; i++)
		{
			if (sieve[i])
				cout << i << ", ";
		}
	}
};

int main()
{
	Solution *s = new Solution(500);
	s->printPrimes();

	return 0;
}
