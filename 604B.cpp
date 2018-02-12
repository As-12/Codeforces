//604B - first attempt
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
B. More Cowbell
time limit per test
2 seconds
memory limit per test
256 megabytes
input
standard input
output
standard output

Kevin Sun wants to move his precious collection of n cowbells from Naperthrill to Exeter, where there is actually grass instead of corn. Before moving, he must pack his cowbells into k boxes of a fixed size. In order to keep his collection safe during transportation, he won't place more than two cowbells into a single box. Since Kevin wishes to minimize expenses, he is curious about the smallest size box he can use to pack his entire collection.

Kevin is a meticulous cowbell collector and knows that the size of his i-th (1 ≤ i ≤ n) cowbell is an integer si. In fact, he keeps his cowbells sorted by size, so si - 1 ≤ si for any i > 1. Also an expert packer, Kevin can fit one or two cowbells into a box of size s if and only if the sum of their sizes does not exceed s. Given this information, help Kevin determine the smallest s for which it is possible to put all of his cowbells into k boxes of size s.
Input

The first line of the input contains two space-separated integers n and k (1 ≤ n ≤ 2·k ≤ 100 000), denoting the number of cowbells and the number of boxes, respectively.

The next line contains n space-separated integers s1, s2, ..., sn (1 ≤ s1 ≤ s2 ≤ ... ≤ sn ≤ 1 000 000), the sizes of Kevin's cowbells. It is guaranteed that the sizes si are given in non-decreasing order.
Output

Print a single integer, the smallest s for which it is possible for Kevin to put all of his cowbells into k boxes of size s.*/



/*
My strategy
---------------

This is a search problem. The largest possible box size is probably smallest cowbell + biggest cowbell.
The smallest possible box size is the smallest cowbell.

So we will search the inclusive number between  smallest cowbell and sum of smallest and biggest cowbell, then test
each search wether it is too small or too big, until we get the right number.


Assertions
-----------

Since only two boxes can be stored in a box.
The number of box >= (number of bell / 2)

*/



/*Assumption
Biggest cowbell size <= box_size

*/


short compareBoxSize(const vector<int> & cowbells, const int box_size, int num_box)
{
/* 0 : perfect
   1 : too big
   -1 : too small
*/
    bool too_big = true;
    /* Loop through vector */
    for (vector<int>::const_iterator iter = cowbells.begin(); iter != cowbells.end(); ++iter)
    {
        //Last elements
        if((iter + 1) == cowbells.end())
        {
            if (*iter == box_size)
                too_big = false;
            --num_box;
            break;
        }
        //Test if we we can reduce two boxes
        else if(*iter + *(iter + 1) < box_size)
        {
            too_big = true;
            --num_box;
            ++iter;
        }
        else if(*iter + *(iter + 1) == box_size)
        {
            too_big = false;
            --num_box;
            ++iter;
        }
        //Reduce 1 box instead
        else
        {
            too_big = true;
            --num_box;
        }
    }
    if (num_box < 0)
        return -1;
    else if (num_box > 0 || too_big)
        return 1;
    else
        return 0;
}


int binary_search(const vector<int> & cowbells, int lower, int upper, int num_box)
{
    int guess = (lower + upper)/2;
    switch(compareBoxSize(cowbells, guess, num_box))
    {
        case 0:
            return guess;
        case 1:
            return  binary_search(cowbells,lower, guess - 1, num_box);
        case -1:
            return binary_search(cowbells, guess + 1 , upper, num_box);
    }
}
int main()
{
    vector<int> cowbells;
    int num_cowbells = 0, num_box = 0;
    cin >> num_cowbells >> num_box;
    for (int i = 0,temp = 0; i != num_cowbells; ++i)
    {
        cin >> temp;
        cowbells.push_back(temp);
    }
    int low_bound = cowbells.back();
    int up_bound = cowbells.front() + cowbells.back();

    cout<<binary_search(cowbells, low_bound, up_bound, num_box)<<endl;
    return 0;
}