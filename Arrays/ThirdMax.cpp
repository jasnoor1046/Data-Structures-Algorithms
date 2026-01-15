/*
Problem:
Find the third maximum distinct element in an array.

Data Structure:
Array

Approach:
Track the top three distinct maximum values while traversing the array.
This avoids sorting and ensures linear time complexity.

Time Complexity:
O(n)

Space Complexity:
O(1)

Edge Cases:
- Less than three distinct elements
- Duplicate values
- Negative numbers
*/

#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int> &nums)
{
    long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
    // here we are using long so LONG_MIN is smaller than any int, so any real number can replace it.

    for (int x : nums)
    {
        if (x == first || x == second || x == third) // this step prevents the duplicate elements
            continue;

        if (x > first)
        {
            third = second;
            second = first;
            first = x;
        }
        else if (x > second)
        {
            third = second;
            second = x;
        }
        else if (x > third)
        {
            third = x;
        }
    }

    return (third == LONG_MIN) ? first : third;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n == 0)
    {
        cout << "Edge case: Empty array. Third maximum not defined." << endl;
        return 0;
    }
    if (n < 3)
    {
        cout << "Less than 3 elements, third maximum not defined" << endl;
        return 0;
    }

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    bool allEqual = true;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[0])
        {
            allEqual = false;
            break;
        }
    }
    if (allEqual)
    {
        cout << "Edge Case:All elements are equal.Third max not defined." << endl;
        return 0;
    }
    cout << "Third maximum element is: " << thirdMax(nums) << endl;
    return 0;
}
