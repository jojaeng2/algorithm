#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int n,len;
    char li[51][51];
    bool check = true;

    scanf("%d",&n);
    for(int i = 0; i < n;i++)
    {
        scanf("%s",li[i]);
    }
    len = strlen(li[0]);

    if (n == 1)
    {
        printf("%s",li[0]);
    }
    else
    {
        for(int i = 0; i < len;i++)
        {
            check = true;
            for(int j = 0; j < n; j++)
            {
                if(li[j][i] != li[0][i]){
                    check = false;
                }
            }
            if(check == false)
            {
                li[0][i] = '?';
            }
        }
        printf("%s",li[0]);
    }

    return 0;
}