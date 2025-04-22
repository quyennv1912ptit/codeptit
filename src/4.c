#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        double kq = (double)1 / x;
        printf("%.15lf\n", kq);
    }
    return 0;
}