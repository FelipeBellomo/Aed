#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximumGain(char* s, int x, int y);

int main() {
    char s[] = "cdbcbbaaabab";
    int x = 4, y = 5;

    int value = maximumGain(s,x,y);

    printf("%d",value);
    return 0;
}

int maximumGain(char* s, int x, int y) {
    int size = strlen(s);
    char* stack1 = (char*)malloc(sizeof(char) * size);
    int top = -1;
    int score = 0;

    
    if(y > x) {
        for(int i = 0; i < size;i++) {
            char c = s[i];
            if(top != -1 && stack1[top] == 'b' && c == 'a') {
                top--;
                score += y;
            } else {
                stack1[++top] = c;
            }

        } 

        int size2 = top + 1;
        char* stack2 = (char*)malloc(sizeof(char) * size2);
        int top2 = -1;

        for(int j = 0; j < size2;j++) {
            char c = stack1[j];

            if(top2 != -1 && stack2[top2] == 'a' && c == 'b') {
                top--;
                score += x;
            } else {
                stack2[++top2] = c;
            }

        } 
        free(stack2);

    } else {
        for(int i = 0; i < size;i++) {
            char c = s[i];
            if(top != -1 && stack1[top] == 'a' && c == 'b') {
                top--;
                score += x;
            } else {
                stack1[++top] = c;
            }

        } 

        int size2 = top + 1;
        char* stack2 = (char*)malloc(sizeof(char) * size2);
        int top2 = -1;

        for(int j = 0; j < size2;j++) {
            char c = stack1[j];

            if(top2 != -1 && stack2[top2] == 'b' && c == 'a') {
                top2--;
                score += y;
            } else {
                stack2[++top2] = c;
            }

        } 
        free(stack2);
    }

    free(stack1);
    return score;

}