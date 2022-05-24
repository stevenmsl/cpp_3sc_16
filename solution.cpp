#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol1209;
using namespace std;

/*takeaways
  - sort the array so we can optimize a bit in picking
    the second and third numbers from the array
*/

int Solution::threeSumCloset(vector<int> &nums, int target)
{
  int n = nums.size();
  auto result = target;
  auto minDiff = INT_MAX;

  sort(begin(nums), end(nums));
  /* make sure there are at least
     two numbers left on your right
     as we are picking the very first
     number in the outer loop
  */
  for (auto i = 0; i < n - 2; i++)
  {
    auto j = i + 1, k = n - 1;
    /* second and third */
    while (j < k)
    {
      auto s = nums[i] + nums[j] + nums[k];
      if (s == target)
        return target;
      auto d = abs(s - target);
      if (d < minDiff)
        result = s, minDiff = d;
      /* we sorted the array
         - use that so we can come closer to the target
           quicker
      */
      if (s > target)
        k--;
      else
        j++;
    }
  }

  return result;
}