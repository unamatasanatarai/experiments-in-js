#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int w = 80;
int h = 40;
char chars[] = "123\n";
char reset[] = "\e[0;0H";
char visible[] = "\e[?25h";
char invisible[] = "\e[?25l";
int off = 0;

void calc(char* out){
    int cnt = 0;
    int y = 0;
    int x = 0;
    for(y =0; y < h; y++){
        for(x = 0; x < w; x++){
            cnt= y * w + x;
            out[cnt] = chars[ (off+cnt)%3];
        }
        out[cnt] = *"\n";
    }
    off++;
}

int main() {
    // +1 for NUL in chars arrays
    char *out = malloc(sizeof(char)*w*h+1);
    if (out == NULL) {printf("I FAILED"); exit(1);};
    fputs(invisible, stdout);
    int i = 0;
    for (i=0;i<100000;i++){
        calc(out);
        fputs(reset, stdout);
        fputs(out, stdout);
        //fwrite(out, sizeof(char), w*h, stdout);
        fflush(stdout);
    }
    fputs(visible, stdout);
    free(out);

    return 0;
}
