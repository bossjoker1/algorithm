 for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b+1,b+1+n);
    int len = unique(b+1,b+1+n)-(b+1);   //len就是去重之后的数组长度,unique用法可以去网上看看，用法简单
    for(int i=1; i<=n; i++)
    {
          a[i] = lower_bound(b+1,b+1+len,a[i])-b;   //a[i]就是直接离散化出来的数组

    }
}