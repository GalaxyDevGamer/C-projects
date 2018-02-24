#include <stdio.h>
#include <stdlib.h>	 // for rand(),srand()
#include <time.h>		 // for time()

#define	NTRY	100	 /* �S���s�� */

int main()
{
char		cd[5][9]={"A","B","C","D","E"}; /*�J�[�h�̎��*/
int		h[5]={0}; /*�J�[�h�ʔr�o������*/
int		p[5]={50,40,7,2,1}; /*�m�����z*/
int		s[5]; 	/*�ݐϊm�����z*/
int		np=5; 	/*n.prob:���z�\�T�C�Y*/
int		ip;	 	/*���z�\�J�E���^*/
int		nt;	 	/*n.trial:�S���s��*/
int		it;	 	/* ���s�J�E���^ */
int		rn;		/*����:0<=rn<100*/

/* ������ */
nt = NTRY;
srand((unsigned)time(NULL));
/* �ݐϊm���\����� */
s[0] = p[0];
for(ip=1;ip<np;ip++){
	s[ip] = s[ip-1]+p[ip];
}
/*�m���\��\��*/
printf("�m���\�F\n��� �m�� �ݐϊm��\n");
for(ip=0;ip<np;ip++){
	printf("%4s %4d %8d\n",cd[ip],p[ip],s[ip]);
}
/*���s���[�v*/
printf("\n���s�����F\n���s�ʔԁQ�Q�Q�����Q�Q��\n");
for(it=0;it<nt;it++){
	rn = rand()%100;
/*�m���I�r�o�J�[�h�I��*/
for(ip=0;ip<np;ip++){
	if(s[ip]>rn) break;
}
/* �r�o�����񐔃J�E���g�C�񍐁i��ʕ\���j*/
h[ip]++;
printf("trial No.%3d: card[%s] %4d\n",it+1,cd[ip],h[ip]);
}
/* ���r�o�����񐔕\��*/
printf("\n�r�o�������v�F\n������� �� ���Ίm��\n");	
for(ip=0;ip<np;ip++){
	printf("%8s %4d %f\n",cd[ip],h[ip],(double)h[ip]/nt);
}
/* �I��*/
printf("\n-normal end-\n");
return 0;
}