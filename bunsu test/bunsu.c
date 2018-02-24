#define KETASUU 100
#include <stdio.h>
int search(int r[], int key, int n);
#define LF putchar('\n')

int main(void)
{
int i, j, k, x, n, m, mn, seisuubu;
int ir, from, to, repeat=0;
int f[KETASUU]; // 小数点以下の数を順に入れる
int r[KETASUU]; // 余りを順に入れる

printf("分数 m/n を計算します\n");
do{
printf("分子 m を入れてください：");
scanf("%d", &m);
}while(m<0);
do{
printf("分母 n を入れてください：");
scanf("%d", &n);
}while(n<=0);

LF;
mn=m/n;
seisuubu=mn;
if(mn < 1){ // 真分数
printf("0.");
}
else{// 過分数
printf("%d.", mn);
m %= n;
}
ir=0;
r[ir++] = m;
m *= 10;
for(i=0; i<KETASUU; i++){
if(m==0){
printf("…… 割り切れた\n");// 計算結果（有限小数）
return 0;
}
if(m < n){
m *= 10;
putchar('0');
f[i]=0;
if(!repeat){
r[ir] = r[ir-1] * 10;// 余りを控える
ir++;
}
}
else{
mn=m/n;
printf("%d", mn);
f[i]=mn;
m %= n;
if(!repeat && m !=0){
from = search(r,m,ir);
if(from>=0){
repeat=1;
to=ir-1;
}
r[ir++]=m;// 余りを控える
}
m *= 10;
}
}
LF;
printf("\n循環小数：%d～%d桁を繰り返します。\n", from+1, to+1);
// 計算結果(循環小数)
printf("%d.",seisuubu);
for(i=0; i<=to; i++){
if(i==from && from == to){
printf("(%d)\n",f[i]);
break;
}
if(i != from && i != to)
printf("%d",f[i]);
else if(i==from)
printf("(%d",f[i]);
else if(i==to)
printf("%d)\n",f[i]);
}
LF;
return 0;
}
int search(int r[], int key, int n)
{
int i;
for(i=0; i<n; i++)
if(r[i] == key)
return i; // すでに現れている余り
return -1; // 今まで現れていない余り
}