#include <stdio.h>
#include <stdlib.h>

struct act
{
     int s;
     int e;
};

int cmp(const void *a, const void *b)
{
     struct act *x = (struct act *)a;
     struct act *y = (struct act *)b;
     if (x->e > y->e)
     {
          return 1;
     }
     else if (x->e == y->e)
     {
          return 0;
     }
     else
     {
          return -1;
     }
}

int main()
{
     int n;
     printf("Enter n:");
     scanf("%d", &n);
     struct act a[n];
     printf("Enter start and end time for every activity:\n");
     for (int i = 0; i < n; i++)
     {
          scanf("%d%d", &a[i].s, &a[i].e);
     }
     qsort(a, n, sizeof(struct act), cmp);
     int i = 0, c = 1;
     for (int j = 1; j < n; j++)
     {
          if (a[j].s >= a[i].e)
          {
               c++;
               i = j;
          }
     }
     printf("The maximum number of activities that can be performed is %d", c);
     return 0;
}