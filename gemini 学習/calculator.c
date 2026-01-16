#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;

    printf("--- 繰り返し計算機 (終了するには q を入力) ---\n");

    // while (1) は「ずっと繰り返せ」という命令
    while (1) {
        printf("\n式を入力してください: ");

        // 入力を受け取る
        if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) {
            // 数字以外のもの（例えば 'q'）が入力されたら、ループを抜ける
            printf("計算機を終了します。また使ってな！\n");
            break;
        }

        switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 == 0) {
                printf("エラー：0では割れやんよ！\n");
                continue; // 今回の計算は飛ばして、次の入力へ戻る
            }
            result = num1 / num2;
            break;
        default:
            printf("エラー：そんな記号は知らんわ…\n");
            continue;
        }

        printf("結果: %.2f\n", result);
    }

    return 0;
}