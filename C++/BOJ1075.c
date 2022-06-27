#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n,m;
    bool check = true;
    scanf("%d",&n);
    scanf("%d",&m);
    n = (n/100)*100;
    for(int i = 0; i < 100; i++)
    {
        if ((n + i)%m == 0)
        {
            check = false;
        }
        if(check == false)
        {
            n = n + i;
            break;
        }
    }
    n = n % 100;
    if(n < 10)
    {
        printf("0%d",n);
    }
    else
    {
        printf("%d",n);
    }

    return 0;
}