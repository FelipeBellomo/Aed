#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

int main() {
    int nums1[] = {4,1,2};
    int nums2[] = {1,3,4,2};
    int nums1Size = 3;
    int nums2Size = 4;
    int returnSize = 0;

    int* rep = nextGreaterElement(nums1,nums1Size,nums2,nums2Size,&returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d",rep[i]);
    }
    
    return 0;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int* ans = (int*)calloc(nums1Size,sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * nums2Size);
    int top = -1;

    for (int i = 0; i < nums2Size; i++) {
        
            
    }
    
}
    


    
