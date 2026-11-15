#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std ;
typedef long long ll;

int main() {
    int  n;

    scanf ("%d", &n);
    priority_queue<ll, vector<ll>, greater<ll> > q;
    for (int i = 0;i < n;i++) {
        ll x;
        scanf("%lld",  &x);
        q.push(x) ;
    }
    ll ans =  0;

    while (q.size() >  1) {
        ll a = q.top();q.pop();
        ll b = q.top(); q.pop();
        ans += a + b;
        q.push(a + b);
    }
    
    printf("%lld\n", ans);
    return 0;
}