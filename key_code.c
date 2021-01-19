#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>

#define QUIT_CHAR 0x04 /* CTRL-D を押すと終了する．*/

// 端末設定保存用大域変数
struct termios CookedTermIos; // cooked モード用
struct termios RawTermIos; // raw モード用

int main(void) {
    int c;

    // 初期状態の端末設定 (cooked モード) を取得・保存する．
    tcgetattr(STDIN_FILENO, &CookedTermIos);

    // raw モードの端末設定を作成・保存する．
    RawTermIos = CookedTermIos;
    cfmakeraw(&RawTermIos);

    // 端末を raw モードに設定する．
    tcsetattr(STDIN_FILENO, 0, &RawTermIos);

    system("clear");
    
    // １文字入力されるごとに標準出力にエコーする．
    while((c = getchar()) != QUIT_CHAR) {
        if(isprint(c)) {
            // 印字可能文字の場合：そのまま表示．
            printf("char %c\f\r", c);
        } else {
            // 制御文字の場合：16進で出力．
            printf("<%04X>\f\r", c);
            if(c == '\n') fputs("\r\n", stdout);
        }
    }

    // 端末設定を元に戻す．
    tcsetattr(STDIN_FILENO, 0, &CookedTermIos);
    putchar('\n');
    return 0;
}