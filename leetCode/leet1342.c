#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfSteps(int num);

int main() {
    int num = 14;

    int result = numberOfSteps(num);

    printf("%d",result);

    return 0;
}

int numberOfSteps(int num) {
    int div = num;
    int count = 0;

    while(div != 0){
        if ((div % 2) == 0)
        {
            div = div / 2;
        }else{
            div = div - 1;
        }
        count++;
    }

    return count;
}