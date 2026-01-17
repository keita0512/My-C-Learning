#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 1. 言葉のリスト（辞書）を作る
    // 配列の数は、{}の中身の数に合わせて自動で決まります
    const char* omikuji[] = { "大吉", "中吉", "小吉", "末吉", "凶" };

    srand((unsigned int)time(NULL));

    printf("今日の運勢を占うに！\n");
    printf("Enterキーを押してな...");
    getchar(); // キー入力を待つ

    // 2. 0～4の乱数を作る
    int result = rand() % 5;

    // 3. 数字を言葉に変換して表示！
    printf("結果は... 【 %s 】 やに！\n", omikuji[result]);

    return 0;
}

