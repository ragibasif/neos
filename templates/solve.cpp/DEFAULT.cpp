/**
 * @file DEFAULT.cpp
 * @author Ragib Asif
 */

/******************************************************************************/
/*                                                                   INCLUDES */
/******************************************************************************/

#include <algorithm>        // sort, binary_search, lower_bound, upper_bound
#include <bitset>           // bitset - for binary data
#include <cassert>          // assert - for debugging
#include <climits>          // INT_MAX, INT_MIN
#include <cmath>            // sqrt, pow, abs
#include <cstdint>          // int64_t, uint64_t, etc. - fixed-width integer types
#include <functional>       // greater, less - function objects and operations
#include <iostream>         // cout, cin, endl - Input/Output
#include <iterator>         // iterators and related items
#include <map>              // map, multimap - (non-hashed, tree) ordered key-value pairs
#include <numeric>          // accumulate, gcd, lcm - numeric operations
#include <queue>            // queue, priority_queue
#include <set>              // set, multiset - (non-hashed, tree) ordered set
#include <stack>            // stack
#include <string>           // string
#include <tuple>
#include <unordered_map>    // unordered_map - hash map
#include <unordered_set>    // unordered_set - hash set
#include <utility>          // pair
#include <vector>           // vector - dynamic array

/******************************************************************************/
/*                                                                     MACROS */
/******************************************************************************/

#define RED "\033[0;91m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define BLUE "\033[0;94m"
#define MAGENTA "\033[0;95m"
#define CYAN "\033[0;96m"
#define RESET "\033[0m"

#define DLOG(...) debugLog(BLUE,__FILE__,__LINE__,__func__,__VA_ARGS__)

/******************************************************************************/
/*                                                                   TYPEDEFS */
/******************************************************************************/

using namespace std;        // removes the need to use std::

/******************************************************************************/
/*                                                                      ENUMS */
/******************************************************************************/

/******************************************************************************/
/*                                                                    STRUCTS */
/******************************************************************************/

/******************************************************************************/
/*                                                      FUNCTION DECLARATIONS */
/******************************************************************************/

void solve(void);
void fastIO(void);
void debugLog(const char *color, const char *file, unsigned int line, const char *function, const char *format, ...);

/******************************************************************************/
/*                                                                      SOLVE */
/******************************************************************************/

void solve(void) {
    int n;
    cin >> n;
    DLOG("%d\n",n);
}


/******************************************************************************/
/*                                                                      MAIN  */
/******************************************************************************/

int main(void) {

    fastIO();

    int t;
    t = 1;
    /*cin >> t;*/
    while (t--) {
        solve();
    }

    return 0;
}

/******************************************************************************/
/*                                                       FUNCTION DEFINITIONS */
/******************************************************************************/

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void debugLog(const char *color, const char *file, unsigned int line, const char *function, const char *format, ...) {
    va_list args;
    va_start(args, format);
    printf("(%s%s%s) ", MAGENTA, "DLOG",
            RESET);
    printf("[%s%s %u %s%s] ", CYAN, file, line,
            function, RESET);
    printf("%s", color);
    vprintf(format, args); // Print the actual message
    printf("%s", RESET);
    va_end(args);
}



/******************************************************************************/
/*                                                                     AUTHOR */
/******************************************************************************/

/**
 * Author:              Ragib Asif
 * Email:               ragib.asif30@myhunter.cuny.edu
 * GitHub:              https://github.com/ragibasif
 * LinkedIn:            https://www.linkedin.com/in/ragibasif/
 */

/******************************************************************************/
/*                                                                    PROBLEM */
/******************************************************************************/

/**
 * <Problem link/ description>
 */

/******************************************************************************/
/*                                                                      NOTES */
/******************************************************************************/

/**
 *  - <Notes go here.>
 *  - <TODO: Example 'todo'.>
 *  - <FIXME: Example 'fixme'.>
 */


/******************************************************************************/
/*                                                                 REFERENCES */
/******************************************************************************/

/**
 * <References (if applicable)>
 */

/******************************************************************************/
/*                                                                    LICENSE */
/******************************************************************************/

/**
 * The MIT License
 *
 * Copyright (c) 2025 Ragib Asif
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

