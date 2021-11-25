#include <stdio.h>

int main()
{
    auto int x;      //Local Variable

    int m;           //m in scope

    scanf("%d", &m);
    {
        int i;      //both m and i in scope

        int n = 5;

        for(i = m; i < n; i++)
        {
            int i;
        }

    }

    return 0;
}

char *myFunction()
{
    char x[] = "orange";

    return x;
}

int function()
{
    auto int y;     //Local Variable

    return y;
}