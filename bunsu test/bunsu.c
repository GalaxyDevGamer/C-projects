#define KETASUU 100
#include <stdio.h>
int search(int r[], int key, int n);
#define LF putchar('\n')

int main(void)
{
int i, j, k, x, n, m, mn, seisuubu;
int ir, from, to, repeat=0;
int f[KETASUU]; // �����_�ȉ��̐������ɓ����
int r[KETASUU]; // �]������ɓ����

printf("���� m/n ���v�Z���܂�\n");
do{
printf("���q m �����Ă��������F");
scanf("%d", &m);
}while(m<0);
do{
printf("���� n �����Ă��������F");
scanf("%d", &n);
}while(n<=0);

LF;
mn=m/n;
seisuubu=mn;
if(mn < 1){ // �^����
printf("0.");
}
else{// �ߕ���
printf("%d.", mn);
m %= n;
}
ir=0;
r[ir++] = m;
m *= 10;
for(i=0; i<KETASUU; i++){
if(m==0){
printf("�c�c ����؂ꂽ\n");// �v�Z���ʁi�L�������j
return 0;
}
if(m < n){
m *= 10;
putchar('0');
f[i]=0;
if(!repeat){
r[ir] = r[ir-1] * 10;// �]����T����
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
r[ir++]=m;// �]����T����
}
m *= 10;
}
}
LF;
printf("\n�z�����F%d�`%d�����J��Ԃ��܂��B\n", from+1, to+1);
// �v�Z����(�z����)
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
return i; // ���łɌ���Ă���]��
return -1; // ���܂Ō���Ă��Ȃ��]��
}