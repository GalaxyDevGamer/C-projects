#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int main(void)
{
    int     n, d, ds[10];
    float   rnd;

    srand(time(NULL));       /* 乱数の初期化 */
    for(n = 0; n < 10; ++n)      /* 回数カウント用配列の初期化 */
        ds[n] = 0;
    for(n = 0; n < MAX; ++n){
        rnd = (float)rand() / 32768.0;     /* 1未満の乱数計算 */
        d = (int)(rnd * 10.0);     /* 10未満の乱数計算 */
        ++ds[d];      /* 回数カウント */
    }
    for(n = 0; n < 10; ++n)
        printf("%d : %8d (%5.2f%%)\n", n, ds[n], (float)ds[n] / MAX * 100.0);
    return 0;
}