#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // 文字列操作（strcpyなど）に必要

#define MAX_TASKS 5      // 最大タスク数
#define MAX_LENGTH 50    // 1つのタスクの最大文字数

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH]; // 2次元配列（タスクの保管庫）
    int taskCount = 0;                 // 現在のタスク数
    int choice;

    printf("--- シンプルToDoリスト ---\n");

    while (1) {
        printf("\n1:追加, 2:表示, 3:終了 ＞ ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            // タスクの追加
            if (taskCount < MAX_TASKS) {
                printf("タスクを入力してな：");
                scanf("%s", tasks[taskCount]); // 配列の[taskCount]番目に保存
                taskCount++;
                printf("追加したに！\n");
            }
            else {
                printf("もういっぱいやわ。整理してな。\n");
            }
        }
        else if (choice == 2) {
            // タスクの表示
            printf("\n【 現在のタスク一覧 】\n");
            if (taskCount == 0) {
                printf("タスクは一つもないよ。\n");
            }
            else {
                for (int i = 0; i < taskCount; i++) {
                    printf("%d: %s\n", i + 1, tasks[i]);
                }
            }
        }
        else if (choice == 3) {
            printf("お疲れさん！終了するに。\n");
            break;
        }
        else {
            printf("1から3で選んでな。\n");
        }
    }

    return 0;
}