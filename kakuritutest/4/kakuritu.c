#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define my_rand(n) (int)((n) * (rand() / (RAND_MAX + 0.1)))

int func(const int *prov, int n)
{
int i, j = my_rand(100);

for(i = 0; i < n && (j -= prov[i]) >= 0; ++ i) ;
return i;
}

int main(void)
{
const int prov[5] = {50, 40, 7, 2, 1};
int a[5] = {0}, i;

srand((unsigned)time(NULL));
for(i = 0; i < 10000; ++ i) ++ a[func(prov, 5)];
for(i = 0; i < 5; ++ i) printf("%d ", a[i]);
putchar('\n');
return 0;
}