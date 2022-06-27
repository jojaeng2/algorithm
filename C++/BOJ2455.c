#include <stdio.h>

int main(void)
{
    int n,m,sum = 0,result = 0;
    char dat[4][2];
    for (int i = 0; i < 4; i ++)
    {
        scanf("%d %d",&n,&m);
        sum -= n;
        sum += m;
        if(result < sum)
        {
            result = sum;
        }
    }
    printf("%d\n",result);
    return 0;
}