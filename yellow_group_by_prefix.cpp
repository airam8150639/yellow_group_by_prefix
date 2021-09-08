#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
    auto it_first = lower_bound(range_begin, range_end, prefix, 
        [](const string& a, const string& b) {
            string c = a;
            if (c.size() >= b.size()) {
                c.resize(b.size());
            }
            return (c < b);
        }
    );
    auto it_second = upper_bound(range_begin, range_end, prefix,
        [](const string& a, const string& b) {
            string c = b;
            if (b.size() >= a.size()) {
                c.resize(a.size());
            }
            return (a < c);
        }
    );
    return make_pair(it_first, it_second);
}