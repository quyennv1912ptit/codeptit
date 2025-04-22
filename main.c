#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

void strrev(char s[])
{
    int l = 0, r = strlen(s) - 1;
    while (l < r)
    {
        char temp = s[l];
        s[l++] = s[r];
        s[r--] = temp;
    }
}

void multiply(char a[], int b, char kq[])
{
    int res[MAX_LEN] = {0};
    int carry = 0, idx = 0;
    int len = strlen(a);

    strrev(a);
    for (int i = 0; i < len; i++)
    {
        int prod = (a[i] - '0') * b + carry;
        res[idx++] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        res[idx++] = carry % 10;
        carry /= 10;
    }

    for (int i = 0; i < idx; i++)
        kq[i] = res[idx - i - 1] + '0';
    kq[idx] = '\0';
    strrev(a);
}

int is_rotation(char a[], char b[])
{
    if (strlen(a) != strlen(b))
        return 0;
    char temp[MAX_LEN * 2];
    strcpy(temp, a);
    strcat(temp, a);
    return strstr(temp, b) != NULL;
}

int is_cyclic(char s[])
{
    int len = strlen(s);
    char result[MAX_LEN];
    for (int i = 2; i <= len; i++)
    {
        multiply(s, i, result);
        if (!is_rotation(s, result))
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char s[MAX_LEN];
        scanf("%s", s);
        if (is_cyclic(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
