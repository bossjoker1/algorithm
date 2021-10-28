// 区间修改 加上x
// 区间和查询
#include<cstdio>
#include<cstdlib>
#define ll(x) (x<<1)
#define rr(x) (x<<1|1)
using namespace std;
const int N=400000+5;
typedef long long ll;

ll n, m;
ll w[N];

struct seg_tree{
  ll sum, l, r, lazy;
}t[N];

inline ll read(){
  ll ans = 0 , f = 1; char i=getchar();
  while(i<'0'||i>'9'){if(i=='-')f=-1;i=getchar();}
  while(i>='0'&&i<='9'){ans=ans*10+i-'0';i=getchar();}
  return ans * f;
}

void up(ll root){
  t[root].sum = t[ll(root)].sum + t[rr(root)].sum;
}

void build(ll root,ll l,ll r){
  int mid = l+r>>1;
  t[root].l = l , t[root].r = r;
  if(l == r){
    t[root].sum = w[l];
    return;
  }
  build(ll(root),l,mid);
  build(rr(root),mid+1,r);
  up(root);
}

void pushdown(ll root){
  ll mid = t[root].l + t[root].r >> 1;
  t[ll(root)].lazy += t[root].lazy;
  t[rr(root)].lazy += t[root].lazy;
  t[ll(root)].sum += t[root].lazy*(mid-t[root].l+1);
  t[rr(root)].sum += t[root].lazy*(t[root].r-mid);
  t[root].lazy = 0;
}

void update(ll root,ll l,ll r,ll val){
  ll mid = t[root].l+t[root].r>>1;
  if(l<=t[root].l && t[root].r<=r){
    t[root].sum += val * (t[root].r-t[root].l+1);
    t[root].lazy += val;
    return;
  }
  if(t[root].lazy) pushdown(root);
  if(l <= mid) update(ll(root),l,r,val);
  if(mid < r) update(rr(root),l,r,val);
  up(root);
}

ll query(ll root,ll l,ll r){
  if(l<=t[root].l && t[root].r<=r) return t[root].sum;
  if(r<t[root].l || t[root].r<l) return 0;
  if(t[root].lazy) pushdown(root);
  return query(ll(root),l,r)+query(rr(root),l,r);
}

int main(){
  ll f, x, y, val; n = read(); m = read();
  for(ll i=1;i<=n;i++) w[i] = read();
  build(1,1,n);
  for(ll i=1;i<=m;i++){
    f = read(); x = read(); y = read();
    if(f == 1) val = read() , update(1,x,y,val);
    else printf("%lld\n",query(1,x,y));
  }
  return 0;
}