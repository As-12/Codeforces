//600B -- Unsolved
#include <iostream>
#include <vector>
#include <algorithm>

/*
You are given two arrays of integers a and b. For each element of the second array bj you should find the number of elements in array a that are less than or equal to the value bj.
Input

The first line contains two integers n, m (1 ≤ n, m ≤ 2·105) — the sizes of arrays a and b.

The second line contains n integers — the elements of array a ( - 109 ≤ ai ≤ 109).

The third line contains m integers — the elements of array b ( - 109 ≤ bj ≤ 109).
Output

Print m integers, separated by spaces: the j-th of which is equal to the number of such elements in array a that are less than or equal to the value bj.

*/

using namespace std;

int main()
{
    // Building size
    long long size_a, size_b;
    cin >> size_a >> size_b;

    // Building array size_a
    vector<long long> array_a;

    for (int i = 0, temp = 0; i != size_a; ++i)
    {
        cin>>temp;
        array_a.push_back(temp);
    }

    //Building array size_b
    vector<long long> array_b;

    for (int i = 0, temp = 0; i != size_b; ++i)
    {
        cin>>temp;
        array_b.push_back(temp);
    }
    //Sort the array, so binary_search operations can be used
    sort(array_a.begin(), array_a.end());
    for(vector<long long>::iterator iter = array_b.begin(); iter != array_b.end(); ++iter)
    {
        //http://www.cplusplus.com/reference/algorithm/upper_bound/
        vector<long long>::iterator index = upper_bound(array_a.begin(), array_a.end(), *iter);
        cout<<array_a.end() - index<<" ";
    }
    return 0;
}

