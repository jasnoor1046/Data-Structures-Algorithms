/*
Problem:
Find the second maximum element in an array.

Data Structure:
Array

Approach:
Traverse the array while maintaining the largest and second largest
elements seen so far.
This avoids sorting and keeps the solution efficient.

Time Complexity:
O(n)

Space Complexity:
O(1)

Edge Cases:
- Array with less than two elements
- Duplicate maximum values
- All elements equal
*/

#include <bits/stdc++.h>
using namespace std;

int secondMax(vector<int> &a)
{
    int mx = INT_MIN, smx = INT_MIN;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > mx)
        {
            smx = mx;
            mx = a[i];
        }
        else if (a[i] > smx && a[i] != mx)
        {
            smx = a[i];
        }
    }
    return smx;
}

int main()
{

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (n < 2)
    {
        cout << "Edge Case: Array has less than two elements. Second maximum not defined." << endl;
        return 0;
    }

    vector<int> a(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Edge Case: All elements equal
    bool allEqual = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[0])
        {
            allEqual = false;
            break;
        }
    }
    if (allEqual)
    {
        cout << "Edge Case: All elements are equal. Second maximum not defined." << endl;
        return 0;
    }

    // Edge Case: Duplicate maximum values
    int maxVal = *max_element(a.begin(), a.end());
    int countMax = count(a.begin(), a.end(), maxVal);
    if (countMax > 1)
    {
        cout << "Edge Case: Duplicate maximum values exist." << endl;
    }

    int ans = secondMax(a);
    if (ans == INT_MIN)
        cout << "Second maximum not found." << endl;
    else
        cout << "Second maximum element is: " << ans << endl;

    return 0;
}
