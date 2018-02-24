#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<unistd.h>
int play; //ユーザーに入力させたプレイ回数
int user;
int cnt; //playと回数を比較するため
int score; //得点を記録
int ans; //問題の回答
int syurui; //3つの乱数を発生させ、*,+,-の区別を行う
int difficulty; //難易度
int max; //コンピュータとの対決で使用
int counter; //同じ
int multi;
double times1; //経過時間の計測
double times2; //同じ
clock_t start, cstart, cstart2, end, cend, cend2; //経過時間の取得
/*以下は同じ処理を含む関数が複数存在するため、パターンを照らし合わせて理解すること*/
void vscom(){
	double second;
	double minute;
	double hour;
	int num3; //乱数の定義
	int num4; //同じ
	srand((unsigned)time(NULL)); //乱数の初期化
	sleep(1);
	num3 = rand() % 100+1; //1から101までの数をランダムで取得
	num4 = rand() % 100+1; //同じ
	if(cnt<play+1){
		switch(syurui){
			case 1:
			printf("%d問目：%d+%d=", cnt, num3, num4);
			scanf("%d", &ans);
			if(num3+num4==ans){
				puts("Correct!");
				score=score+=1; //得点に1を足す
			}
			else{
				puts("Wrong");
			}
			break;
			case 2:
			printf("%d問目：%d-%d=", cnt, num3, num4);
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
			printf("%d問目：%d*%d=", cnt, num3, num4);
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
		cend = clock(); //経過時間を取得
		max=cnt;
		multi=1000*max;
		times1 = ((double)(cend-start)-multi); //今までの時間からスタート前の時間を引く
		hour=floor((double)(times1/3600000)); //ミリ秒を時間に
		minute=floor((double)((times1-hour*3600000)/60000)); //ミリ秒を分に
		second=floor((double)((times1-hour*3600000-minute*60000)/1000)); //ミリ秒を秒に
		printf("正解数 %d/%d 掛かった時間 %.0f時間%.0f分%.0f秒\n", score, play, hour, minute, second); //.0で小数点を消している
		puts("続いてコンピュータの計算");
		cstart2=clock();
	}
}
int com(){
	int num1;
	int num2;
	int comran; //コンピュータが計算する式を乱数によって決める
	double seconds;
	double minutes;
	double hours;
	double answer;
	char yesno;
	srand((unsigned)time(NULL));
	sleep(1); //入力を待たずに取得すると、処理が早すぎて新たな乱数が取得できないため1秒待機
	num1 = rand(); //1000から11000までの乱数を取得
	num2 = rand(); //同じ
	comran = rand() % 3+1; //3までの乱数を取得
	while(counter<=max){
		counter = counter+=1; //処理を行った回数を1足す
		if(counter>max){
			cend2 = clock(); //コンピュータが計算を終えるまでの時間を取得
			times2 = ((double)(cend2-cstart2)-multi); //上からcstart2と待機時間を引く
			seconds=((double)(times2/1000));
			printf("掛かった時間 %.5f秒\n", seconds);
			if(times1<times2){
				if(score==max){
					puts("ユーザーの勝利！");
				}
				else{
					puts("速度は速くても正解数が問題数に満たないのでコンピュータの勝利です");
				}
			}
			if(times2<times1){
				puts("コンピュータの勝利...");
			}
			puts("もう一度やりますか？y/n");
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
			printf("%d問目：%d+%d=", counter, num1, num2);
			printf("%d\n", num1+num2);
			break;
			case 2:
			printf("%d問目：%d-%d=\n", counter, num1, num2);
			printf("%d\n", num1-num2);
			break;
			case 3:
			printf("%d問目：%d*%d=\n", counter, num1, num2);
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
			printf("%d問目：%d+%d=", counter, num1, num2);
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
			printf("%d問目：%d-%d=", counter, num1, num2);
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
			printf("%d問目：%d*%d=", counter, num1, num2);
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
			printf("%d問目：%d+%d=", counter, num1, num2);
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
			printf("%d問目：%d-%d=", counter, num1, num2);
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
			printf("%d問目：%d*%d=", counter, num1, num2);
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
			printf("%d問目：%d+%d=", counter, num1, num2);
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
				printf("%d問目：%d-%d=", counter, num1, num2);
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
				printf("%d問目：%d-%d=", counter, num2, num1);
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
			printf("%d問目：%d*%d=", counter, num3, num4);
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
			printf("%d問目：%d+%d=", counter, num1, num2);
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
				printf("%d問目：%d-%d=", counter, num1, num2);
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
				printf("%d問目：%d-%d=", counter, num2, num1);
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
			printf("%d問目：%d*%d=", counter, num1, num2);
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
	int go; //モード選択
	char yesno; //もう一度やるかの質問
	double second;
	double minute;
	double hour;
	int times;
	cnt=0;
	score=0;
	counter=0;
	puts("頭の体操 System 1.0.1");
	puts("やり方：ランダムに計算式が出てくるので、答えを求める");
	puts("出題数は毎回自身で設定できます");
	puts("1を押してスタート、それ以外なら終了");
	scanf("%d", &go);
	if(go!=1){
		exit(1); //終了
	}
	puts("難易度選択：");
	puts("1. ガキ 2. 常識人 3. 計算になれた理系 4. Lunatic 5. コンピュータと対決(天才)");
	scanf("%d", &difficulty); 
	puts("何問出題しますか？");
	scanf("%d", &play);
	puts("スタート：");
	start = clock(); //プログラム実行開始からここまでの時間を取得
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
	end = clock(); //今までの処理に掛かった時間を取得
	puts("終了");
	times=((double)(end-start));
	hour=floor((double)(times/3600000));
	minute=floor((double)((times-hour*3600000)/60000));
	second=floor((double)((times-hour*3600000-minute*60000)/1000));
	printf("正解数 %d/%d 掛かった時間 %.0f時間%.0f分%.0f秒 もう一度やりますか？y/n", score, play, hour, minute, second);
	scanf("%s", &yesno);
	if(yesno!='n'){
		return main(); //もう一度やる場合は最初に戻る
	}
	else{
		exit(1);
	}
	return 0;
}