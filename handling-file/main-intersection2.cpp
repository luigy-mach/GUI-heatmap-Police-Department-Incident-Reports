// set_intersection example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_intersection, std::sort
#include <vector>       // std::vector

using namespace std;

vector<string> intersection(vector<string> &v1, vector<string> &v2)
{

    vector<string> v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

    return v3;
}

int main()
{

    std::vector<string> v1 {"a","b","c"};
    std::vector<string> v2 {"b","c"};

    auto v3 = intersection(v1, v2);


    for(string n : v3)
        std::cout << n << ' ';
}
