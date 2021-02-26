#include <stdio.h>

int main(void)
{
    while(1)
    {
        int a,b,c;
        scanf("%d %d",&a,&b);
        if (a == 0 && b == 0)
        {
            break;
        }
        else
        {
            c = 2*a-b;
            printf("%d\n",c);
        }
    }
    
    return 0;
}