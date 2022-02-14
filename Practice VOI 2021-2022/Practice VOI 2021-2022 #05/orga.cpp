#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "orga"
#define inf 1e9
#define mod 2021
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

#define maxVal(s) (s.empty() ? 0 : *s.rbegin())

template<class T>
void maximize(T& x, T y){
    if(x < y) x = y;
}

class segmentTree{
private:
    int n;
    vector<int> a, delta;

    void lazyUpdate(int id){
        delta[id * 2 + 1] += delta[id];
        a[id * 2 + 1] += delta[id];
        delta[id * 2 + 2] += delta[id];
        a[id * 2 + 2] += delta[id];
        delta[id] = 0;
    }

    void _update(int id, int l, int r, int u, int v, int d){
        if(u > r || v < l) return;
        if(l >= u && r <= v){
            a[id] += d;
            delta[id] += d;
            return;
        }
        int mid = (l + r) / 2;
        lazyUpdate(id);
        _update(id * 2 + 1, l, mid, u, v, d);
        _update(id * 2 + 2, mid + 1, r, u, v, d);
        a[id] = max(a[id * 2 + 1], a[id * 2 + 2]);
    }

public:
    segmentTree(){}
    segmentTree(int _n, int arr[]): n(_n){
        a.resize((n + 1) * 4);
        delta.resize((n + 1) * 4);
        build(0, 1, n, arr);
    }

    void build(int id, int l, int r, int arr[]){
        if(l == r){
            a[id] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2 + 1, l, mid, arr);
        build(id * 2 + 2, mid + 1, r, arr);
        a[id] = max(a[id * 2 + 1], a[id * 2 + 2]);
    }

    void update(int x, int d){
        _update(0, 1, n, x, x, d);
    }

    void update(int l, int r, int d){
        _update(0, 1, n, l, r, d);
    }

    int getMax(){
        return a[0];
    }
};

int k, d, q;
int n[maxn];
pii lr[1000001];

namespace subtask1{
    void subtask1(){
        if(d == 2) cout << max(n[1], n[2]) << "\n";
        else cout << n[1] + n[2] << "\n";

        for(int i = 1; i <= q; i ++){
            for(int j = lr[i].first; j <= lr[i].second; j ++){
                n[j] --;
            }

            if(d == 2) cout << i + max(n[1], n[2]) << "\n";
            else cout << i + n[1] + n[2] << "\n";
        }
    }
}

namespace subtask2{
    void subtask2(){
        ll sum = 0;
        int mx = 0;
        for(int i = 1; i <= k; i ++){
            sum += n[i];
            maximize(mx, n[i]);
        }
        if(sum % d == 0) sum /= d;
        else sum = sum / d + 1;
        cout << max(sum, 1ll *  mx) << "\n";

        for(int i = 1; i <= q; i ++){
            for(int j = lr[i].first; j <= lr[i].second; j ++){
                n[j] --;
            }

            sum = 0;
            mx = 0;
            for(int j = 1; j <= k; j ++){
                sum += n[j];
                maximize(mx, n[j]);
            }
            if(sum % d == 0) sum /= d;
            else sum = sum / d + 1;
            cout << i + max(sum, 1ll *  mx) << "\n";
        }
    }
}

namespace subtask3{
    bool check(){
        for(int i = 1; i <= q; i ++) {
            if(lr[i].first != lr[i].second) return 0;
        }
        return 1;
    }

    segmentTree st;

    void subtask3(){
        ll sum = 0;
        ll s, mx;
        st = segmentTree(k, n);
        for(int i = 1; i <= k; i ++) sum += n[i];

        if(sum % d == 0) s = sum / d;
        else s = sum / d + 1;
        mx = st.getMax();
        cout << max(s, mx) << "\n";
        
        for(int i = 1; i <= q; i ++){
            sum --;
            st.update(lr[i].first, -1);
            if(sum % d == 0) s = sum / d;
            else s = sum / d + 1;
            mx = st.getMax();
            cout << i + max(s, mx) << "\n";
        }
    }
}

namespace subtask4{
    segmentTree st;

    void subtask4(){
        ll sum = 0;
        ll s, mx;
        st = segmentTree(k, n);
        for(int i = 1; i <= k; i ++) sum += n[i];

        if(sum % d == 0) s = sum / d;
        else s = sum / d + 1;
        mx = st.getMax();
        cout << max(s, mx) << "\n";
        
        for(int i = 1; i <= q; i ++){
            sum -= lr[i].second - lr[i].first + 1;
            st.update(lr[i].first, lr[i].second, -1);
            if(sum % d == 0) s = sum / d;
            else s = sum / d + 1;
            mx = st.getMax();
            cout << i + max(s, mx) << "\n";
        }
    }
}

void process(){
    cin >> k >> d >> q;
    lr[0] = {0, 0};
    for(int i = 1; i <= k; i ++) cin >> n[i];
    for(int i = 1; i <= q; i ++) cin >> lr[i].first >> lr[i].second;

    //if(k == 2 && q <= 100) return subtask1::subtask1();
    //if(q <= 100) return subtask2::subtask2();
    //if(subtask3::check()) return subtask3::subtask3();
    //assert(1 < 0);
    subtask4::subtask4();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    process();
    return 0;
}