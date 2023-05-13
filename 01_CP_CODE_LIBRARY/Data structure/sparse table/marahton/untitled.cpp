void solve()
{
    for(int i=1;i<=n;i++)
    {
	  int ed=i,l,r,m,pos;
	  while(ed<=n)
	  {
	     int xx=getgcd(i,ed);
	     l=ed,r=n,pos=-1;
	     while(l<=r)
	     {
		 if(r-l<=1)
		 {
		 if(getgcd(i,r)==xx)
		 {
		 	pos=r;
		 }
		 else if(getgcd(i,l)==xx)
		 {
		 	pos=l;
		 }
		 break;
		}
		m=l+r>>1;
		if(getgcd(i,m)==xx)
		{
			l=m ;
		}
		else
		{
		    r=m;
	    }
	    ans[xx]+=pos-ed+1;
	    ed=pos+1;
	  }
    }
}