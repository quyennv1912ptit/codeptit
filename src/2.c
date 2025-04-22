#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        long long x;
        scanf("%lld", &x);
        printf("%lld\n", x * 2);
    }
    return 0;
}