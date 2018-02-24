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
	puts("1.出勤時間+1時間後券 1050円");
	puts("2.勤務時間-1時間券   1050円");
	puts("3.一日わがまま券     10500円");
	puts("4.会社で居眠り1時間券1663円");
	puts("5.会社で休憩1時間券  9961円");
	puts("6.シャープペン       1050円");
	puts("7.ボールペン         840円");
	puts("8.メモ帳             630円");
	puts("購入する商品を選んで番号を入力");
	scanf("%d", &items);
	puts("数量を入力");
	scanf("%d", &num);
	switch(items){
		case 1:
		price = 1050*num;
		printf("出勤時間+1時間後券が%d枚で計%d円になります", num,price);
		break;
		case 2:
		price = 1050*num;
		printf("勤務時間-1時間券が%d枚で計%d円になります",num,price);
		break;
		case 3:
		price = 10500*num;
		printf("一日わがまま券が%d枚で計%d円になります", num,price);
		break;
		case 4:
		price = 1663*num;
		printf("会社で居眠り1時間券が%d枚で計%d円になります", num,price);
		break;
		case 5:
		price = 9961*num;
		printf("会社で休憩1時間券が%d枚で計%d円になります", num,price);
		break;
		case 6:
		price = 1050*num;
		printf("シャープペンが%d個で計%d円になります", num,price);
		break;
		case 7:
		price = 840*num;
		printf("ボールペンが%d個で計%d円になります", num,price);
		break;
		case 8:
		price = 630*num;
		printf("メモ帳が%d個で計%d円になります", num,price);
		break;
		default:
		puts("入力された値が不正です");
		return main();
	}
	puts("お支払い方法を選んでください");
	puts("1.給料から天引");
	puts("2.現金");
	puts("3.ICカード");
	puts("4.クレジットカード");
	scanf("%d", &h2p);
	switch(h2p){
		case 1:
		puts("天引手続きが完了しました");
		break;
		case 2:
		while (cash < price){
			puts("現金を入れてください");
			scanf("%d", &cash);
		}
		change = cash-price;
		printf("合計金額は%dでお預かりは%dでお釣りは%dです", price,cash,change);
		break;
		case 3:
		puts("残高から引き落としが完了しました");
		break;
		case 4:
		puts("お会計が完了しました");
		break;
		default:
		puts("不正な数字が入力されました。最初からやり直して下さい");
		return main();
	}
	puts("購入を続けますか？y/n");
	scanf("%s", &yesno);
	if (yesno=='y'){
		return main();
	}
	else{
		puts("お買い上げありがとうございました。");
	}
	return 0;
}
			