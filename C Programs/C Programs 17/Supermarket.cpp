#include <cstdio>

#define min(a, b) (a < b ? a : b)

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    double ans = 1E9;
    while(n--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        ans = min(ans, (a*1.0*m)/(b*1.0));
    }

    printf("%lf\n", ans);
    return 0;
}

