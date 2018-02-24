#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define my_rand(n) (int)(n * (rand() / (RAND_MAX + 1.0)))

int main(void)
{
int i;
char *s[] = {"¸”s‚µ‚Ü‚µ‚½", "¬Œ÷‚µ‚Ü‚µ‚½"};

scanf("%d", &i);
srand((unsigned)time(NULL));
puts(s[my_rand(100) < i]);
return 0;
}