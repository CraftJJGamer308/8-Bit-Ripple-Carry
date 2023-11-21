#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool *ha(bool x, bool y)
{
    bool r[2];
    r[0] = x && y;
    r[1] = x != y;
    return r;
}

bool *va(bool x, bool y, bool c)
{
    bool r[2];
    bool c1 = ha(x, y)[0];
    bool s1 = ha(x, y)[1];
    bool c2 = ha(s1, c)[0];
    bool s2 = ha(s1, c)[1];

    r[0] = c1 || c2;
    r[1] = s2;

    return r;
}

int main()
{
    char ai[9], bi[9];
    bool a[8]; // 15
    bool b[8]; // 3
    bool s[8] = {0};
    bool c[8] = {0};

    printf("input 8 bits of a: ");
    scanf("%s", ai);

    printf("\ninput 8 bits of b: ");
    scanf("%s", bi);

    if (strlen(ai) != 8 || strlen(bi) != 8)
    {
        printf("input should be 8 bit long!\n");
        return -1;
    }

    for (int i = 0; i < 8; i++)
    {
        a[7 - i] = ai[i] == '0' ? 0 : 1;
        b[7 - i] = bi[i] == '0' ? 0 : 1;
    }

    s[0] = va(a[0], b[0], 0)[1];
    c[0] = va(a[0], b[0], 0)[0];
    for (int i = 1; i < 8; i++)
    {
        c[i] = va(a[i], b[i], c[i - 1])[0];
        s[i] = va(a[i], b[i], c[i - 1])[1];
    }

    for (int i = 7; i >= 0; i--)
    {
        printf("%5d ", a[i]); // print a
    }

    printf("\n");
    for (int i = 7; i >= 0; i--)
    {
        printf("%5d ", b[i]); // print b
    }

    printf("\n-------------------------------------------------\n");
    for (int i = 7; i >= 0; i--)
    {
        printf("c%d:%2d ", i, c[i]); // print carry
    }

    printf("\n");
    for (int i = 7; i >= 0; i--)
    {
        printf("s%d:%2d ", i, s[i]); // print sum
    }

    return 0;
}
