#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<unistd.h>
int play; //���[�U�[�ɓ��͂������v���C��
int user;
int cnt; //play�Ɖ񐔂��r���邽��
int score; //���_���L�^
int ans; //���̉�
int syurui; //3�̗����𔭐������A*,+,-�̋�ʂ��s��
int difficulty; //��Փx
int max; //�R���s���[�^�Ƃ̑Ό��Ŏg�p
int counter; //����
int multi;
double times1; //�o�ߎ��Ԃ̌v��
double times2; //����
clock_t start, cstart, cstart2, end, cend, cend2; //�o�ߎ��Ԃ̎擾
/*�ȉ��͓����������܂ފ֐����������݂��邽�߁A�p�^�[�����Ƃ炵���킹�ė������邱��*/
void vscom(){
	double second;
	double minute;
	double hour;
	int num3; //�����̒�`
	int num4; //����
	srand((unsigned)time(NULL)); //�����̏�����
	sleep(1);
	num3 = rand() % 100+1; //1����101�܂ł̐��������_���Ŏ擾
	num4 = rand() % 100+1; //����
	if(cnt<play+1){
		switch(syurui){
			case 1:
			printf("%d��ځF%d+%d=", cnt, num3, num4);
			scanf("%d", &ans);
			if(num3+num4==ans){
				puts("Correct!");
				score=score+=1; //���_��1�𑫂�
			}
			else{
				puts("Wrong");
			}
			break;
			case 2:
			printf("%d��ځF%d-%d=", cnt, num3, num4);
			scanf("%d", &ans);
			if(num3-num4==ans){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong");
			}
			break;
			case 3:
			printf("%d��ځF%d*%d=", cnt, num3, num4);
			scanf("%d", &ans);
			if(num3*num4==ans){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong");
			}
			break;
		}
	}
	if(cnt==play){
		cend = clock(); //�o�ߎ��Ԃ��擾
		max=cnt;
		multi=1000*max;
		times1 = ((double)(cend-start)-multi); //���܂ł̎��Ԃ���X�^�[�g�O�̎��Ԃ�����
		hour=floor((double)(times1/3600000)); //�~���b�����Ԃ�
		minute=floor((double)((times1-hour*3600000)/60000)); //�~���b�𕪂�
		second=floor((double)((times1-hour*3600000-minute*60000)/1000)); //�~���b��b��
		printf("���� %d/%d �|���������� %.0f����%.0f��%.0f�b\n", score, play, hour, minute, second); //.0�ŏ����_�������Ă���
		puts("�����ăR���s���[�^�̌v�Z");
		cstart2=clock();
	}
}
int com(){
	int num1;
	int num2;
	int comran; //�R���s���[�^���v�Z���鎮�𗐐��ɂ���Č��߂�
	double seconds;
	double minutes;
	double hours;
	double answer;
	char yesno;
	srand((unsigned)time(NULL));
	sleep(1); //���͂�҂����Ɏ擾����ƁA�������������ĐV���ȗ������擾�ł��Ȃ�����1�b�ҋ@
	num1 = rand(); //1000����11000�܂ł̗������擾
	num2 = rand(); //����
	comran = rand() % 3+1; //3�܂ł̗������擾
	while(counter<=max){
		counter = counter+=1; //�������s�����񐔂�1����
		if(counter>max){
			cend2 = clock(); //�R���s���[�^���v�Z���I����܂ł̎��Ԃ��擾
			times2 = ((double)(cend2-cstart2)-multi); //�ォ��cstart2�Ƒҋ@���Ԃ�����
			seconds=((double)(times2/1000));
			printf("�|���������� %.5f�b\n", seconds);
			if(times1<times2){
				if(score==max){
					puts("���[�U�[�̏����I");
				}
				else{
					puts("���x�͑����Ă����𐔂���萔�ɖ����Ȃ��̂ŃR���s���[�^�̏����ł�");
				}
			}
			if(times2<times1){
				puts("�R���s���[�^�̏���...");
			}
			puts("������x���܂����Hy/n");
			scanf("%s", &yesno);
			if(yesno!='n'){
				return main();
			}
			else{
				exit(1);
			}
			return 0;
		}
		switch(comran){
			case 1:
			printf("%d��ځF%d+%d=", counter, num1, num2);
			printf("%d\n", num1+num2);
			break;
			case 2:
			printf("%d��ځF%d-%d=\n", counter, num1, num2);
			printf("%d\n", num1-num2);
			break;
			case 3:
			printf("%d��ځF%d*%d=\n", counter, num1, num2);
			answer=floor((double)(num1*num2));
			printf("%.0f\n", answer);
			break;
		}
		return com();
	}
}
int lunatic(){
	int num1;
	int num2;
	srand((unsigned)time(NULL));
	num1 = rand() % 10000+1001;
	num2 = rand() % 10000+1001;
	while(counter<=play){
		counter=counter+=1;
		if(counter>play){
			return 0;
		}
		switch(syurui){
			case 1:
			printf("%d��ځF%d+%d=", counter, num1, num2);
			scanf("%d", &ans);
			if(num1+num2==ans){
				puts("Correct!");
				score=score+=1;
			}	
			else{
				puts("Wrong");
			}
			break;
			case 2:
			printf("%d��ځF%d-%d=", counter, num1, num2);
			scanf("%d", &ans);
			if(ans==num1-num2){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong...");
			}
			break;
			case 3:
			printf("%d��ځF%d*%d=", counter, num1, num2);
			scanf("%f", &ans);
			if(ans==num1*num2){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong...");
			}
			break;
		}
		return lunatic();
	}
}
int rikei(){
	int num1;
	int num2;
	srand((unsigned)time(NULL));
	num1 = rand() % 1000+101;
	num2 = rand() % 1000+101;
	while(counter<=play){
		counter=counter+=1;
		if(counter>play){
			return 0;
		}
		switch(syurui){
			case 1:
			printf("%d��ځF%d+%d=", counter, num1, num2);
			scanf("%d", &ans);
			if(num1+num2==ans){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong");
			}
			break;
			case 2:
			printf("%d��ځF%d-%d=", counter, num1, num2);
			scanf("%d", &ans);
			if(ans==num1-num2){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong...");
			}
			break;
			case 3:
			printf("%d��ځF%d*%d=", counter, num1, num2);
			scanf("%f", &ans);
			if(ans==num1*num2){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong...");
			}
			break;
		}
		return rikei();
	}
}
int normal(){
	int num1;
	int num2;
	int num3;
	int num4;
	srand((unsigned)time(NULL));
	num1 = rand() % 100 + 1;
	num2 = rand() % 100 + 1;
	num3 = rand() % 20 + 1;
	num4 = rand() % 20 + 1;
	while(counter<=play){
		counter=counter+=1;
		if(counter>play){
			return 0;
		}
		switch(syurui){
			case 1:
			printf("%d��ځF%d+%d=", counter, num1, num2);
			scanf("%d", &ans);
			if(ans==num1+num2){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong...");
			}
			break;
			case 2:
			if(num1>num2){
				printf("%d��ځF%d-%d=", counter, num1, num2);
				scanf("%d", &ans);
				if(ans==num1-num2){
					puts("Correct!");
					score=score+=1;
				}	
				else{
					puts("Wrong...");
				}
				break;
			}
			if(num2>num1){
				printf("%d��ځF%d-%d=", counter, num2, num1);
				scanf("%d", &ans);
				if(ans==num2-num1){
					puts("Correct!");
					score=score+=1;
				}
				else{
					puts("Wrong...");
				}
			}
			else{
				return normal();
			}
			break;
			case 3:
			printf("%d��ځF%d*%d=", counter, num3, num4);
			scanf("%d", &ans);
			if(ans==num3*num4){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong...");
			}
			break;
		}
		return normal();
	}
}
int gaki(){
	int num1;
	int num2;
	srand((unsigned)time(NULL));
	num1 = rand() % 10+1;
	num2 = rand() % 10+1;
	while(counter<=play){
		counter=counter+=1;
		if(counter>play){
			return 0;
		}
		switch(syurui){
			case 1:
			printf("%d��ځF%d+%d=", counter, num1, num2);
			scanf("%d", &ans);
			if(num1+num2==ans){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong");
			}
			break;
			case 2:
			if(num1>num2){
				printf("%d��ځF%d-%d=", counter, num1, num2);
				scanf("%d", &ans);
				if(ans==num1-num2){
					puts("Correct!");
					score=score+=1;
				}
				else{
					puts("Wrong...");
				}
			}	
			if(num2>num1){
				printf("%d��ځF%d-%d=", counter, num2, num1);
				scanf("%d", &ans);
				if(ans==num2-num1){
					puts("Correct!");
					score=score+=1;
				}
				else{
					puts("Wrong...");
				}
			}
			else{
				return gaki();
			}
			break;
			case 3:
			printf("%d��ځF%d*%d=", counter, num1, num2);
			scanf("%d", &ans);
			if(ans==num1*num2){
				puts("Correct!");
				score=score+=1;
			}
			else{
				puts("Wrong...");
			}
			break;
		}
		return gaki();
	}
}
int main(){
	int go; //���[�h�I��
	char yesno; //������x��邩�̎���
	double second;
	double minute;
	double hour;
	int times;
	cnt=0;
	score=0;
	counter=0;
	puts("���̑̑� System 1.0.1");
	puts("�����F�����_���Ɍv�Z�����o�Ă���̂ŁA���������߂�");
	puts("�o�萔�͖��񎩐g�Őݒ�ł��܂�");
	puts("1�������ăX�^�[�g�A����ȊO�Ȃ�I��");
	scanf("%d", &go);
	if(go!=1){
		exit(1); //�I��
	}
	puts("��Փx�I���F");
	puts("1. �K�L 2. �펯�l 3. �v�Z�ɂȂꂽ���n 4. Lunatic 5. �R���s���[�^�ƑΌ�(�V��)");
	scanf("%d", &difficulty); 
	puts("����o�肵�܂����H");
	scanf("%d", &play);
	puts("�X�^�[�g�F");
	start = clock(); //�v���O�������s�J�n���炱���܂ł̎��Ԃ��擾
	while(cnt<=play){
		cnt=cnt+=1;
		if(cnt>play){
			break;
		}
		srand((unsigned)time(NULL));
		syurui = rand() % 3 + 1;
		switch(difficulty){
			case 1:
			gaki();
			break;
			case 2:
			normal();
			break;
			case 3:
			rikei();
			break;
			case 4:
			lunatic();
			break;
			case 5:
			vscom();
			if(cnt==play){
				com();
			}
			break;
		}
	}
	end = clock(); //���܂ł̏����Ɋ|���������Ԃ��擾
	puts("�I��");
	times=((double)(end-start));
	hour=floor((double)(times/3600000));
	minute=floor((double)((times-hour*3600000)/60000));
	second=floor((double)((times-hour*3600000-minute*60000)/1000));
	printf("���� %d/%d �|���������� %.0f����%.0f��%.0f�b ������x���܂����Hy/n", score, play, hour, minute, second);
	scanf("%s", &yesno);
	if(yesno!='n'){
		return main(); //������x���ꍇ�͍ŏ��ɖ߂�
	}
	else{
		exit(1);
	}
	return 0;
}