#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main() {
    char** strs = {"flower","flow","fligth"};
    int strsSize = 3;

    char* prefix = longestCommonPrefix(strs,strsSize);

    printf("%s\n",prefix);

    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    char* prefix = (char*)malloc(sizeof(char) * 100);
    prefix[0] = '\0';  

    
    if (strsSize < 3)
        return strs[0];

    
    if (strs[0][0] != '\0' && strs[1][0] != '\0' && strs[2][0] != '\0' &&
        strs[0][0] == strs[1][0] && strs[0][0] == strs[2][0]) {
        
        char temp[2] = { strs[0][0], '\0' };
        strcat(prefix, temp);
        i++;

        
        if (strs[0][i] != '\0' && strs[1][i] != '\0' && strs[2][i] != '\0' &&
            strs[0][i] == strs[1][i] && strs[0][i] == strs[2][i]) {
            
            char temp2[2] = { strs[0][i], '\0' };
            strcat(prefix, temp2);
        }
    }

    return prefix;
}