#include <stdio.h>
main()
{
char ch;
char item[5][]{
"Aitem"; //アイテム名
"Bitem"; //アイテム名
"Citem"; //アイテム名
"Ditem"; //アイテム名
"Eitem"; //アイテム名
}
int i;	/*乱数SEED設定*/
srand(time(NULL));

/*int型変数iに、5で除算をした余り（つまり、０〜４）に１を足した数（１〜５）を代入させる*/
while(ch != 'Q'){
i = (rand()%5)+1;	/*itemを表示*/
printf(item[i]);	/*chにQが入ったら終わるループ*/
ch = getchar();
}

/*確率の件ですが、すべてを足しても100%になりません。
もし、A=20% B=30% C=10% D=5% E=35%と書いたつもりでしたら、答えます。
こちらにも乱数を使います。
20%と言うのは、0.2の事ですから、分数なら100分の20と言うことです。
srandは済んだ物として*/
i = (rand()%100)+1;
/*これで1から100までの数値をiへ代入。iはint型とします。*/
if(i<=20){
printf(item[0]);
}
/*これで、iが20以下だと、Aを表示。*/
if( i >= 20 ) printf(item[0]);
/*これで、iが20以上50未満（つまり、B)だった場合、Bitemを表示します。*/
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