#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int strStr(char* haystack, char* needle);


int main() {
    
    char* input1 = "sadbutsad";
    char* input2 = "sad";

    strStr(input1,input2);

}


int strStr(char* haystack, char* needle) {
    int contHay = strlen(haystack);
    int contNee = strlen(needle);

    if (contNee == 0) 
        return 0; 

    for (int i = 0; i <= contHay - contNee; i++) {
        if (strncmp(&haystack[i], needle, contNee) == 0) {
            return i; 
        }
    }

    return -1; 
}