#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine);


int main() {
    char* ransomNote = "aa";
    char* magazine = "ab";

    

    return 0;
}

bool canConstruct(char* ransomNote, char* magazine) {
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        bool got = false;

        for (int j = 0; magazine[j] != '\0'; j++) {
            if (ransomNote[i] == magazine[j]) {
                magazine[j] = '0'; 
                got = true;
                break;
            }
        }

        if (!got) {
            return false;
        }
    }

    return true; 
}