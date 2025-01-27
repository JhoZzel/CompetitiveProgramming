#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

using ll = long long;

struct MIN_Queue{
    stack<pair<int,int>> s1,s2;
    int query() {
        if (s1.empty() or s2.empty()) {
            return s1.empty() ? s2.top().ss : s1.top().ss;
        }
        return min(s1.top().ss, s2.top().ss);
    }
    void add(int x) {
        int mn = s1.empty() ? x : min(x, s1.top().ss);
        s1.emplace(x, mn);
    }
    void pop() {
        if (s2.empty()) {
            while(!s1.empty()) {
                int e = s1.top().ff;
                s1.pop();
                int mn = s2.empty() ? e : min(e, s2.top().ss);
                s2.emplace(e, mn);
            }
        }
        s2.pop();
    }
    void clean() {
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
    }
};


int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, L; 
    cin >> n >> L;

    vector<int> a(n);
    for (int &e : a) cin >> e;

    MIN_Queue Q;
    for (int i = 0; i < n; i++) {
        Q.add(a[i]);
        if (i < L - 1) continue;
        cout << Q.query() << ' ';
        Q.pop();
    }
    cout << '\n';

    return 0;
}
