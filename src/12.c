#include <stdio.h>
#include <math.h>

typedef struct
{
    int cao, rong;
} HCN;

void HCN_Xoay(HCN *hcn)
{
    int temp = hcn->cao;
    hcn->cao = hcn->rong;
    hcn->rong = temp;
}

int HCN_Dientich(const HCN *hcn)
{
    return hcn->cao * hcn->rong;
}

int ghephinh(const HCN *a, const HCN *b, const HCN *c, int canh)
{
    if (a->cao == b->cao && b->cao == c->cao && c->cao == canh && a->rong + b->rong + c->rong == canh)
        return 1;
    if (a->rong + b->rong == c->rong && c->rong == canh && a->cao == b->cao && a->cao + c->cao == canh)
        return 1;
    if (a->rong == b->rong && a->rong + c->rong == canh && a->cao + b->cao == c->cao && c->cao == canh)
        return 1;
    return 0;
}

int hoanvi(HCN a, HCN b, HCN c, int canh)
{
    for (int i = 0; i < 2; i++)
    {
        if (i)
            HCN_Xoay(&a);
        for (int j = 0; j < 2; j++)
        {
            if (j)
                HCN_Xoay(&b);
            for (int k = 0; k < 2; k++)
            {
                if (k)
                    HCN_Xoay(&c);
                if (ghephinh(&a, &b, &c, canh))
                    return 1;
            }
        }
    }
    return 0;
}

int kiemtra(HCN a, HCN b, HCN c)
{
    int tongdt = HCN_Dientich(&a) + HCN_Dientich(&b) + HCN_Dientich(&c);
    int canh = sqrt(tongdt);
    if (canh != sqrt(tongdt))
        return 0;

    // hoan vi va thu tat ca cac cach ghep
    if (hoanvi(a, b, c, canh))
        return 1;
    if (hoanvi(a, c, b, canh))
        return 1;
    if (hoanvi(b, a, c, canh))
        return 1;
    if (hoanvi(b, c, a, canh))
        return 1;
    if (hoanvi(c, a, b, canh))
        return 1;
    if (hoanvi(c, b, a, canh))
        return 1;

    return 0;
}

int main()
{
    HCN a, b, c;
    scanf("%d%d%d%d%d%d", &a.rong, &a.cao, &b.rong, &b.cao, &c.rong, &c.cao);
    printf("%s", kiemtra(a, b, c) ? "YES" : "NO");
    return 0;
}