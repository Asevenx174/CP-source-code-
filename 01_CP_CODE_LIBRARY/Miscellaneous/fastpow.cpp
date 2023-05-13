ll fastpow(ll a,ll b,ll m)
{
    a %= m ;
    ll res = 1;
    while (b > zz) 
    {
        if (b & qq) { res = res * a % m ; }
        a = a * a % m;
        b >>= qq ;
    }
    return res;
}