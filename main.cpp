#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1209;

/*
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

tuple<vector<int>, int, int>
testFixture1()
{
  auto nums = vector<int>{-1, 2, 1, -4};
  return make_tuple(nums, 1, 2);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.threeSumCloset(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  return 0;
}