#include <stdio.h>
main()
{
char ch;
char item[5][]{
"Aitem"; //�A�C�e����
"Bitem"; //�A�C�e����
"Citem"; //�A�C�e����
"Ditem"; //�A�C�e����
"Eitem"; //�A�C�e����
}
int i;	/*����SEED�ݒ�*/
srand(time(NULL));

/*int�^�ϐ�i�ɁA5�ŏ��Z�������]��i�܂�A�O�`�S�j�ɂP�𑫂������i�P�`�T�j����������*/
while(ch != 'Q'){
i = (rand()%5)+1;	/*item��\��*/
printf(item[i]);	/*ch��Q����������I��郋�[�v*/
ch = getchar();
}

/*�m���̌��ł����A���ׂĂ𑫂��Ă�100%�ɂȂ�܂���B
�����AA=20% B=30% C=10% D=5% E=35%�Ə���������ł�����A�����܂��B
������ɂ��������g���܂��B
20%�ƌ����̂́A0.2�̎��ł�����A�����Ȃ�100����20�ƌ������Ƃł��B
srand�͍ς񂾕��Ƃ���*/
i = (rand()%100)+1;
/*�����1����100�܂ł̐��l��i�֑���Bi��int�^�Ƃ��܂��B*/
if(i<=20){
printf(item[0]);
}
/*����ŁAi��20�ȉ����ƁAA��\���B*/
if( i >= 20 ) printf(item[0]);
/*����ŁAi��20�ȏ�50�����i�܂�AB)�������ꍇ�ABitem��\�����܂��B*/
if( i >= 20 || i <= 50 ){
printf(item[1]);
}if else( i <= 50 || i >= 60 ){
printf(item[2]);
}if else( i <=60 || i >= 65){
printf(item[3]);
}else{
printf(item[4]);
}
}