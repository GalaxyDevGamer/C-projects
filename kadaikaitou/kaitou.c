#include <stdio.h>

int main(){
	int items;
	int num;
	int price;
	int h2p;
	int cash;
	int change;
	char yesno;
	items = 0;
	h2p = 0;
	num = 0;
	price = 0;
	cash = 0;
	change = 0;
	puts("1.�o�Ύ���+1���Ԍ㌔ 1050�~");
	puts("2.�Ζ�����-1���Ԍ�   1050�~");
	puts("3.����킪�܂܌�     10500�~");
	puts("4.��Ђŋ�����1���Ԍ�1663�~");
	puts("5.��Ђŋx�e1���Ԍ�  9961�~");
	puts("6.�V���[�v�y��       1050�~");
	puts("7.�{�[���y��         840�~");
	puts("8.������             630�~");
	puts("�w�����鏤�i��I��Ŕԍ������");
	scanf("%d", &items);
	puts("���ʂ����");
	scanf("%d", &num);
	switch(items){
		case 1:
		price = 1050*num;
		printf("�o�Ύ���+1���Ԍ㌔��%d���Ōv%d�~�ɂȂ�܂�", num,price);
		break;
		case 2:
		price = 1050*num;
		printf("�Ζ�����-1���Ԍ���%d���Ōv%d�~�ɂȂ�܂�",num,price);
		break;
		case 3:
		price = 10500*num;
		printf("����킪�܂܌���%d���Ōv%d�~�ɂȂ�܂�", num,price);
		break;
		case 4:
		price = 1663*num;
		printf("��Ђŋ�����1���Ԍ���%d���Ōv%d�~�ɂȂ�܂�", num,price);
		break;
		case 5:
		price = 9961*num;
		printf("��Ђŋx�e1���Ԍ���%d���Ōv%d�~�ɂȂ�܂�", num,price);
		break;
		case 6:
		price = 1050*num;
		printf("�V���[�v�y����%d�Ōv%d�~�ɂȂ�܂�", num,price);
		break;
		case 7:
		price = 840*num;
		printf("�{�[���y����%d�Ōv%d�~�ɂȂ�܂�", num,price);
		break;
		case 8:
		price = 630*num;
		printf("��������%d�Ōv%d�~�ɂȂ�܂�", num,price);
		break;
		default:
		puts("���͂��ꂽ�l���s���ł�");
		return main();
	}
	puts("���x�������@��I��ł�������");
	puts("1.��������V��");
	puts("2.����");
	puts("3.IC�J�[�h");
	puts("4.�N���W�b�g�J�[�h");
	scanf("%d", &h2p);
	switch(h2p){
		case 1:
		puts("�V���葱�����������܂���");
		break;
		case 2:
		while (cash < price){
			puts("���������Ă�������");
			scanf("%d", &cash);
		}
		change = cash-price;
		printf("���v���z��%d�ł��a�����%d�ł��ނ��%d�ł�", price,cash,change);
		break;
		case 3:
		puts("�c������������Ƃ����������܂���");
		break;
		case 4:
		puts("����v���������܂���");
		break;
		default:
		puts("�s���Ȑ��������͂���܂����B�ŏ������蒼���ĉ�����");
		return main();
	}
	puts("�w���𑱂��܂����Hy/n");
	scanf("%s", &yesno);
	if (yesno=='y'){
		return main();
	}
	else{
		puts("�������グ���肪�Ƃ��������܂����B");
	}
	return 0;
}
			