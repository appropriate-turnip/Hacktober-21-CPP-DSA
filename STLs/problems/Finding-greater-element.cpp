#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);

    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; i--)
    {

        while (!s.empty() && nums[s.top()] <= nums[i % n])
        {
            s.pop();
        }

        res[i % n] = (s.empty() ? -1 : nums[s.top()]);
        s.push(i % n);
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans = nextGreaterElements(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    

    return 0;
}