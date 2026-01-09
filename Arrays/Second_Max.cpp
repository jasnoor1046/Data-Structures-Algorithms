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

    vector<int> a(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = secondMax(a);
    cout << "second maximum element is: " << ans << endl;
    return 0;
}