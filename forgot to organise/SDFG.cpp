void solve()
{
    int n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    // Calculate net displacement after each command
    vector<int> prefix(n + 1, 0);
    prefix[0] = x;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + (s[i - 1] == 'L' ? -1 : 1);
    }

    // Count zero crossings
    int ans = 0;
    int pos = x;
    int time = 0;

    // If robot starts at 0, it immediately resets
    if (pos == 0)
    {
        // Calculate how many full sequences can be executed
        ans = k / n;
        cout << ans << endl;
        return;
    }

    // First cycle: simulate until robot reaches 0 or completes sequence
    while (time < min(k, (long long)n))
    {
        if (s[time] == 'L')
            pos--;
        else
            pos++;

        time++;

        if (pos == 0)
        {
            ans++;
            break;
        }
    }

    // If robot never reaches 0 or we've used all time
    if (pos != 0 || time == k)
    {
        cout << ans << endl;
        return;
    }

    // Robot is now at position 0 after reset
    // Find how long it takes to reach 0 again from position 0
    pos = 0;
    int cycle_start = time;
    int zeros_in_cycle = 0;

    while (time < min(k, (long long)(n + cycle_start)))
    {
        if (s[time % n] == 'L')
            pos--;
        else
            pos++;

        time++;

        if (pos == 0)
        {
            zeros_in_cycle++;
            break;
        }
    }

    // If robot never reaches 0 again
    if (pos != 0)
    {
        cout << ans << endl;
        return;
    }

    // Calculate total zero crossings
    int cycle_length = time - cycle_start;
    long long remaining_time = k - time;
    long long full_cycles = remaining_time / cycle_length;

    ans += full_cycles * zeros_in_cycle;

    cout << ans << endl;
}
