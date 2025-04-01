#include <algorithm>  // sort, binary_search, lower_bound, upper_bound
#include <bitset>     // bitset - for binary data
#include <cassert>    // assert - for debugging
#include <climits>    //INT_MAX, INT_MIN
#include <cmath>      // sqrt, pow, abs
#include <cstdint>    // int64_t, uint64_t, etc. - fixed-width integer types
#include <functional> // greater, less - function objects and operations
#include <iostream>   // cout, cin, endl - Input/Output
#include <iterator>   // iterators and related items
#include <map>     // map, multimap - (non-hashed, tree) ordered key-value pairs
#include <numeric> // accumulate, gcd, lcm - numeric operations
#include <queue>   // queue, priority_queue
#include <set>     // set, multiset - (non-hashed, tree) ordered set
#include <stack>   // stack
#include <string>  // string
#include <tuple>
#include <unordered_map> // unordered_map - hash map
#include <unordered_set> // unordered_set - hash set
#include <utility>       // pair
#include <vector>        // vector - dynamic array

using namespace std; // removes the need to use std::

/*Fast Input/Output*/
#define FASTIO                                                                 \
  do {                                                                         \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
  } while (0)

void solve(void) {
  int n;
  cin >> n;
  cout << "n: " << n;
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  FASTIO;

  int t;
  t = 1;
  /*cin >> t;*/
  while (t--) {
    solve();
    cout << "\n";
  }
  cout << endl;

  return 0;
}
