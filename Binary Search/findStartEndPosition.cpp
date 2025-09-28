#include <vector>
using namespace std;

class Solution
{
public:
    int findFirst(vector<int> &nums, int target)
    {

        int low = 0, high = (int)nums.size() - 1, ans = -1;

        while (high >= low)
        {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                high = mid - 1;
            }

            else if (nums[mid] > target)
                high = mid - 1;

            else
                low = mid + 1;
        }

        return ans;
    }

    int findLast(vector<int> &nums, int target)
    {
        int low = 0, high = (int)nums.size() - 1, ans = -1;

        while (high >= low)
        {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                low = mid + 1;
            }

            else if (nums[mid] < target)
            {
                low = mid + 1;
            }

            else
                high = mid - 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int> nums, int target)
    {

        int st = findFirst(nums, target);
        int end = findLast(nums, target);

        return {st, end};
    }
};