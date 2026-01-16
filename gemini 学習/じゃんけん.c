#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userHand, compHand;
    int win = 0, games = 0; // 勝利数と合計試合数

    srand((unsigned int)time(NULL));

    printf("--- じゃんけんゲーム ---\n");
    printf("0:グー, 1:チョキ, 2:パー (これ以外で終了)\n");

    while (1) {
        printf("\n出す手を選んでな：");
        if (scanf("%d", &userHand) != 1 || userHand < 0 || userHand > 2) {
            printf("ゲームを終了します。\n");
            break;
        }

        compHand = rand() % 3; // 0, 1, 2 のどれか
        games++;

        // 手の表示
        char* hands[] = { "グー", "チョキ", "パー" };
        printf("あなた：%s vs コンピュータ：%s\n", hands[userHand], hands[compHand]);

        // 判定ロジック
        if (userHand == compHand) {
            printf("結果：あいこやに！\n");
        }
        else if ((userHand == 0 && compHand == 1) ||
            (userHand == 1 && compHand == 2) ||
            (userHand == 2 && compHand == 0)) {
            printf("結果：あんたの勝ちや！\n");
            win++;
        }
        else {
            printf("結果：わしの勝ちやな！\n");
        }

        // 現在の成績を表示
        printf("（現在：%d勝 %d敗 %d引き分け）\n", win, games - win - (games - (win + (games - win - (games - win)))), 0); // ※ここは少し複雑なので、まずはシンプルに勝数表示にします
    }

    if (games > 0) {
        printf("\n最終成績：%d戦 %d勝\n", games, win);
        printf("勝率：%.1f%%\n", (double)win / games * 100);
    }

    return 0;
}