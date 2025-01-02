#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Range
{
    ll a, b;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        int special = -1;
        bool has1 = false, hasMinus1 = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                has1 = true;
            if (a[i] == -1)
                hasMinus1 = true;
            if (a[i] != 1 && a[i] != -1)
            {
                special = i;
            }
        }
        vector<Range> rnge;
        if (special == -1)
        {
            ll currmax = a[0];
            ll maxi = a[0];
            for (int i = 1; i < n; i++)
            {
                currmax = max(a[i], currmax + a[i]);
                maxi = max(maxi, currmax);
            }
            ll currmin = a[0];
            ll m = a[0];
            for (int i = 1; i < n; i++)
            {
                currmin = min(a[i], currmin + a[i]);
                m = min(m, currmin);
            }
            if (has1 && hasMinus1)
            {
                rnge.push_back(Range{m, maxi});
            }
            else if (has1)
            {
                rnge.push_back(Range{1, (ll)n});
            }
            else
            {
                rnge.push_back(Range{(ll)(-n), -1LL});
            }
            rnge.push_back(Range{0, 0});
        }
        else
        {
            ll x = a[special];
            vector<ll> left, right;
            for (int i = 0; i < special; i++)
                left.push_back(a[i]);
            for (int i = special + 1; i < n; i++)
                right.push_back(a[i]);
            ll m_left = 0, maxi_left = 0;
            if (left.empty())
            {
                m_left = 0;
                maxi_left = 0;
            }
            else
            {
                // Max sum
                ll currmax = left[0];
                maxi_left = left[0];
                for (int i = 1; i < left.size(); i++)
                {
                    currmax = max(left[i], currmax + left[i]);
                    maxi_left = max(maxi_left, currmax);
                }
                // Min sum
                ll currmin = left[0];
                m_left = left[0];
                for (int i = 1; i < left.size(); i++)
                {
                    currmin = min(left[i], currmin + left[i]);
                    m_left = min(m_left, currmin);
                }
            }
            ll m_right = 0, maxi_right = 0;
            if (right.empty())
            {
                m_right = 0;
                maxi_right = 0;
            }
            else
            {
                ll currmax = right[0];
                maxi_right = right[0];
                for (int i = 1; i < right.size(); i++)
                {
                    currmax = max(right[i], currmax + right[i]);
                    maxi_right = max(maxi_right, currmax);
                }
                ll currmin = right[0];
                m_right = right[0];
                for (int i = 1; i < right.size(); i++)
                {
                    currmin = min(right[i], currmin + right[i]);
                    m_right = min(m_right, currmin);
                }
            }
            ll min_suffix_left = LLONG_MAX, max_suffix_left = LLONG_MIN;
            if (left.empty())
            {
                min_suffix_left = 0;
                max_suffix_left = 0;
            }
            else
            {
                ll sum = 0;
                for (int i = left.size() - 1; i >= 0; i--)
                {
                    sum += left[i];
                    min_suffix_left = min(min_suffix_left, sum);
                    max_suffix_left = max(max_suffix_left, sum);
                }
                min_suffix_left = min(min_suffix_left, 0LL);
                max_suffix_left = max(max_suffix_left, 0LL);
            }
            ll min_prefix_right = LLONG_MAX, max_prefix_right = LLONG_MIN;
            if (right.empty())
            {
                min_prefix_right = 0;
                max_prefix_right = 0;
            }
            else
            {
                ll sum = 0;
                for (auto num : right)
                {
                    sum += num;
                    min_prefix_right = min(min_prefix_right, sum);
                    max_prefix_right = max(max_prefix_right, sum);
                }
                min_prefix_right = min(min_prefix_right, 0LL);
                max_prefix_right = max(max_prefix_right, 0LL);
            }
            ll m_containing_x = min_suffix_left + x + min_prefix_right;
            ll maxi_containing_x = max_suffix_left + x + max_prefix_right;
            // Collect rnge
            rnge.push_back(Range{m_left, maxi_left});
            rnge.push_back(Range{m_right, maxi_right});
            rnge.push_back(Range{m_containing_x, maxi_containing_x});
            rnge.push_back(Range{0, 0});
        }
        // Sort rnge
        sort(rnge.begin(), rnge.end(), [&](const Range &a, const Range &b) -> bool
             {
            if(a.a != b.a) return a.a < b.a;
            return a.b < b.b; });
        // Merge rnge
        vector<Range> merged;
        for (auto &r : rnge)
        {
            if (merged.empty())
            {
                merged.push_back(r);
            }
            else
            {
                Range &last = merged.back();
                if (r.a <= last.b + 1)
                {
                    last.b = max(last.b, r.b);
                }
                else
                {
                    merged.push_back(r);
                }
            }
        }
        vector<ll> sums;
        for (auto &r : merged)
        {
            for (ll val = r.a; val <= r.b; val++)
                sums.push_back(val);
        }
        sort(sums.begin(), sums.end());
        sums.erase(unique(sums.begin(), sums.end()), sums.end());
        // Output
        cout << sums.size() << endl;
        for (auto val : sums)
            cout << val << " ";
        cout << endl;
    }
}
