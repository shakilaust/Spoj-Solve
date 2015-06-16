 
const int MX = 1e7 + 10 ; // limit y index value 
const int XX =  50000 + 10 ; // limit query
const int open = 1 ;
const int point = 2 ;
const int close = 3 ;

struct abc
{
    int x , y , val ,  priority , lim ;
};

abc inp[MX];
Long tree[MX];
Long ans[XX];
bool cmp( abc A  , abc B )
{
    if( A.x == B.x )
    {

            return A.priority < B.priority ;

    }
    return A.x < B.x ;
}
void add( int x , int v )
{
    while( x < MX )
    {
        tree[x] += v ;
        x += ( x & -x );
    }
}
Long sum( int x )
{
    Long ans = 0 ;
    while( x )
    {
        ans += tree[x];
        x -= ( x & -x );
    }
    return ans ;
}
void solve()
{
 
 int cs , t ;
    scanf("%d",&t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        int n ;
        scanf("%d",&n);
        rep( i , n )
        {
            scanf("%d %d %d",&inp[i].x,&inp[i].y,&inp[i].val);
            inp[i].x++;
            inp[i].y++;
            inp[i].priority = point ;
        }
        int idx = n ;
        int r = II ;
        rep( i , r )
        {
            scanf("%d %d",&inp[i].x,&inp[i].y);
            inp[idx].x++;
            inp[idx].y++;
            inp[idx].priority = open ;
            inp[idx].val = i ;
            idx++;
            scanf("%d %d",&inp[i].x,&inp[i].y);
            inp[idx].x++;
            inp[idx].y++;
            inp[idx].priority = close ;
            inp[idx].val = i ;
            inp[idx-1].lim = inp[idx].y ;
            inp[idx].lim = inp[idx-1].y ;
            idx++;
        }
        sort ( inp , inp + idx , cmp );
        ms( tree , 0 );
        ms( ans , 0 );
        rep( i , idx )
        {
            if(inp[i].priority == point ) add( inp[i].y , inp[i].val );
            else if( inp[i].priority == open ) ans[inp[i].val] -= ( sum( inp[i].lim ) - sum( inp[i].y - 1 ) );
            else ans[inp[i].val] += ( sum(inp[i].y ) -  sum( inp[i].lim - 1 ) );
        }
        rep( i , r ) printf("%lld\n",ans[i]);
    }
}
