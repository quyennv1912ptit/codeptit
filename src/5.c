#include <stdio.h>

int main()
{
    long long a, b;
    scanf("%lld%lld", &a, &b);
    long long tong, hieu, tich, div, mod;
    float thuong;
    tong = a + b;
    hieu = a - b;
    tich = a * b;
    div = a / b;
    mod = a % b;
    thuong = (float)a / b;
    printf("%lld\n%lld\n%lld\n%lld\n%lld\n%.2f", tong, hieu, tich, div, mod, thuong, mod);
    return 0;
}