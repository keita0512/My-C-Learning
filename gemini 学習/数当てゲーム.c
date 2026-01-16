#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer, guess;
    int count = 0;
    const int MAX_ATTEMPTS = 10; // 最大回数を10回に設定

    srand((unsigned int)time(NULL));
    answer = rand() % 100 + 1;

    printf("--- 数当てゲーム（1～100） ---\n");
    printf("10回以内に当ててみてな！\n");

    while (1) {
        printf("\n[%d回目] 予想を入力：", count + 1);
        if (scanf("%d", &guess) != 1) {
            printf("数字を入力してな！\n");
            break;
        }

        count++; // 入力回数をカウント

        // 判定処理
        if (guess == answer) {
            printf("お見事！%d回目で正解やに！\n", count);
            break; // 正解なので終了
        }

        // --- ここからが「回数制限」の追加部分 ---
        if (count >= MAX_ATTEMPTS) {
            printf("残念！%d回以内に当てられませんでした…。\n", MAX_ATTEMPTS);
            printf("正解は【 %d 】でした！また挑戦してな。\n", answer);
            break; // 10回超えたので終了
        }
        // ---------------------------------------

        // まだ回数がある場合はヒントを出す
        if (guess > answer + 5) {
            printf("もっと【小さい】ですよ。\n");
        }
        else if (guess < answer - 5) {
            printf("もっと【大きい】ですよ。\n");
        }
        else {
            printf("めちゃくちゃ惜しい！あとちょっと！\n");
        }
    }

    return 0;
}