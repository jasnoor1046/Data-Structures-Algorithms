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

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Third maximum element is: " << thirdMax(nums) << endl;

    return 0;
}
