#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int main(void)
{
    int     n, d, ds[10];
    float   rnd;

    srand(time(NULL));       /* �����̏����� */
    for(n = 0; n < 10; ++n)      /* �񐔃J�E���g�p�z��̏����� */
        ds[n] = 0;
    for(n = 0; n < MAX; ++n){
        rnd = (float)rand() / 32768.0;     /* 1�����̗����v�Z */
        d = (int)(rnd * 10.0);     /* 10�����̗����v�Z */
        ++ds[d];      /* �񐔃J�E���g */
    }
    for(n = 0; n < 10; ++n)
        printf("%d : %8d (%5.2f%%)\n", n, ds[n], (float)ds[n] / MAX * 100.0);
    return 0;
}