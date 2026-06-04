#include <stdio.h>

void subset(int n, int d, int w[])
{
    int s, k, i, x[10];

    for(i = 0; i < n; i++)
        x[i] = 0;

    s = 0;
    k = 0;
    x[k] = 1;

    while(1)
    {
        if(k < n && x[k] == 1)
        {
            if(s + w[k] == d)
            {
                printf("Solution: ");

                for(i = 0; i < n; i++)
                {
                    if(x[i] == 1)
                        printf("%d ", w[i]);
                }

                printf("\n");
                x[k] = 0;
            }
            else if(s + w[k] < d)
            {
                s = s + w[k];
            }
            else
            {
                x[k] = 0;
            }
        }
        else
        {
            k--;

            while(k >= 0 && x[k] == 0)
                k--;

            if(k < 0)
                break;

            x[k] = 0;
            s = s - w[k];
        }

        k++;

        if(k >= n)
            break;

        x[k] = 1;
    }
}

int main()
{
    int n, i, d, w[10], s = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter set elements in ascending order:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        s += w[i];
    }

    printf("Enter target sum: ");
    scanf("%d", &d);

    if(s < d || w[0] > d)
    {
        printf("No subset possible\n");
        return 0;
    }

    subset(n, d, w);

    return 0;
}
