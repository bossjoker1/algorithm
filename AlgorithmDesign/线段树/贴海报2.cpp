# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

# define M 100005

int lr[M << 2], rr[M << 2];
int x[M << 2];
int arr[M << 4];
int Hash[M << 4];
int result;

inline int read(){
  int ans = 0 , f = 1; char i=getchar();
  while(i<'0'||i>'9'){if(i=='-')f=-1;i=getchar();}
  while(i>='0'&&i<='9'){ans=ans*10+i-'0';i=getchar();}
  return ans * f;
}

int DoubleSearch(int start, int end, int num)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (x[mid] == num)
        {
            return mid;
        }
        else if (x[mid] > num)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

void PushDown(int node)
{
    if (arr[node] != -1)
    {
        arr[node * 2] = arr[node * 2 + 1] = arr[node];
        arr[node] = -1;
    }
}

void Update(int node, int nstart, int nend, int ustart, int uend, int updatenum)
{
    if (ustart <= nstart && uend >= nend)
    {
        arr[node] = updatenum;
        return;
    }
    PushDown(node);
    int mid = (nstart + nend) / 2;

    if (ustart <= mid)
    {
        Update(node * 2, nstart, mid, ustart, uend, updatenum);
    }
    if (uend > mid)
    {
        Update(node * 2 + 1, mid + 1, nend, ustart, uend, updatenum);
    }
}

void Query(int node, int nstart, int nend)
{
    if (nstart == nend)
    {
        if (!Hash[arr[node]])
        {
            result++;
            Hash[arr[node]] = 1;
        }
        return;
    }
    PushDown(node);
    int mid = (nstart + nend) / 2;
    Query(node * 2, nstart, mid);
    Query(node * 2 + 1, mid + 1, nend);
}

int main(void)
{
    int i, m, n;
    memset(arr, -1, sizeof(arr));
    memset(Hash, 0, sizeof(Hash));
    m = read(), n = read();
    int xn = 0;
    for (i = 1; i <= n; i++)
    {
        lr[i] = read(), rr[i] = read();
        x[++xn] = lr[i];
        x[++xn] = rr[i];
    }
    sort(x + 1, x + xn + 1);
    int xm = 1;
    for (i = 2; i <= xn; i++)
    {
        if (x[i] != x[i - 1])
        {
            x[++xm] = x[i];
        }
    }
    for (i = xm; i > 1; i--)
    {
        if (x[i] - x[i - 1] > 1)
        {
            x[++xm] = x[i] - 1;
        }
    }
    sort(x + 1, x + xm + 1);
    for (i = 1; i <= n; i++)
    {
        int l = DoubleSearch(1, xm, lr[i]);
        int r = DoubleSearch(1, xm, rr[i]);
        Update(1, 1, xm, l, r, i);
    }
    result = 0;
    Query(1, 1, xm);
    printf("%d\n", result);
    return 0;
}