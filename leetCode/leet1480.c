#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* runningSum(int* nums, int numsSize, int* returnSize);

int main() {
    int nums[4] = {1,2,3,4};
    int size = 4;
    int retunrSize;
    

    int* ret = runningSum(nums,size,&retunrSize);

    for (int i = 0; i < retunrSize; i++){
        printf("%d",ret[i]);
    }
    

}

int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int)* (*returnSize));
 

    result[0] = nums[0];

    for (int i = 1; i < numsSize; i++){
        result[i] = result[i - 1] + nums[i]; 
        printf("%d\n",result[i]);
    }

    return result;
    
}