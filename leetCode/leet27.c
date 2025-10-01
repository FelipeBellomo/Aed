#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int removeElement(int* nums, int numsSize, int val);


int main() {
    int nums[4] = {3,2,2,3};
    int numsSize = 4;
    int val = 3;

    int out = removeElement(nums,numsSize,val);

    for (int i = 0; i < out; i++){
        printf("%d ",nums[i]);
    }
    
    printf("%d\n",out);

    return 0;
}

int removeElement(int* nums, int numsSize, int val) {
    int count = 0;

    for (int i = 0; i < numsSize; i++){
        if (nums[i] != val){
            nums[count] = nums[i];
            count++;          
        }
    }

    return count;
    
}