#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main(void)
{
	int rarerity[10]{
		normal, rare, super, ultimate, sec, sec2, 1, 2, 3, 4
	}
    int     d, ds[10];
    float   rnd;

    srand(time(NULL));       /* �����̏����� */
    rnd = (float)rand() / 32768.0;     /* 1�����̗����v�Z */
    d = (int)(rnd * 10.0);     /* 10�����̗����v�Z */
    ++ds[d];      /* �񐔃J�E���g */
    printf("%d : %8d (%5.2f%%)\n", rarerity, ds[rarerity], (float)ds[rarerity] / MAX * 100.0);
    return 0;
}