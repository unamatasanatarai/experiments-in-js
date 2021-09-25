#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    int w = 20;
    int h = 10;
    char out[200];
    char chars[] = "123\n";
    char reset[] = "\e[0;0H";
    char visible[] = "\e[?25h";
    char invisible[] = "\e[?25l";
int off = 0;
void calc(){
    int cnt = 0;
    int ecnt = 0;
    int y = 0;
    int x = 0;
    for(y =0; y < h; y++){
        for(x = 0; x < w; x++){
            out[cnt] = chars[(off+cnt)%3];
            cnt++;
            ecnt++;
        }
        out[cnt-1] = chars[3];
    }
    off++;
}

int main() {
    fputs(invisible, stdout);
    //fputs(reset, stdout);
    //fputs(out, stdout);
    int i = 0;
      for (i=0;i<100000;i++){
calc();
        fputs(reset, stdout);
          fwrite(out, sizeof(char), sizeof(out), stdout);
          fflush(stdout);
      }
    fputs(visible, stdout);

   return 0;
}
