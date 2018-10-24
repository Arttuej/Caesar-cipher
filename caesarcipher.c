#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int ans_state = 0;

void check_answer();

int main(void) {
    int i;
    char str[100];
    char caesarCipher, selection, ans;
    int len;
    int x = 0;

    do {
        puts("Give a sentence: ");

        if (fgets(str, sizeof(str), stdin) == NULL) {
           break;
    	}

        // cuts too long strings

    	// int overflow_check = 0;

        if(str[sizeof(str) - 1] == '\0' && str[sizeof(str) - 2] != '\n') {
  			 int ch;
             while((ch = fgetc(stdin)) != '\n' && ch != EOF) {
                 // overflow_check = 1;
  			 }
  		}

        puts("");
        puts("Select encrypt or decrypt (e/d): ");
        selection = getchar();
        caesarCipher = tolower(selection);

        switch(caesarCipher) {
            // encoder
            case 'e':
                len = strlen(str);
                for(i = 0; i < len; i++) {
                    char c = str[i];
                    if(c == 'A' || c == 'B' || c == 'C' || c == 'a' || c == 'b' || c == 'c') {
                        c = c+23;
                        putchar(c);
                    }
                    else if(c == ' ') {
                        putchar(c);
                    }
                    else {
                        c = c-3;
                        putchar(c);
                    }
                }
                break;
            // decoder
            case 'd':
                len = strlen(str);
                for(i = 0; i < len; i++) {
                    char c = str[i];
                    if(c == 'X' || c == 'Y' || c == 'Z' || c == 'x' || c == 'y' || c == 'z') {
                        c = c-23;
                        putchar(c);
                    }
                    else if(c == ' ') {
                        putchar(c);
                    }
                    else {
                        c = c+3;
                        putchar(c);
                    }
                }
                break;
            default:
                printf("Wrong Input\n");
            }
        puts("\n");
        puts("Cipher again? (y/n): ");
        getchar();

        check_answer();

        puts("");

    }

    while(ans_state);

    puts("Bye!");

    return 0;
}

void check_answer() {
    char ans[5];
    int ch;
    fgets(ans, sizeof(ans), stdin);
    ans[strcspn(ans, "\n")] = '\0';

    char valid_answers[4][5] = {"y", "yes", "n", "no"};

    if (strcmp(ans, valid_answers[0]) == 0 || strcmp(ans, valid_answers[1]) == 0) {
        ans_state = 1;
        // valid_ans = 1;
        // getchar();
    }
    else if (strcmp(ans, valid_answers[2]) == 0 || strcmp(ans, valid_answers[3]) == 0) {
        ans_state = 0;
        // valid_ans = 1;
        // getchar();
    }
    else {
        puts("Invalid input!");

        // clears overflow
        if (strlen(ans) > 3) {
            while((ch = getchar()) != '\n' && ch != EOF) {
                // overflow_check = 1;
            }
        }
        check_answer();
    }
    return;
}
