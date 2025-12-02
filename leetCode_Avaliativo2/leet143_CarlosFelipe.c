#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void reorderList(struct ListNode* head) {
    struct ListNode* ini = head;
    struct ListNode* last = NULL;
    struct ListNode* firstHalf = NULL;
    int top = -1;
    int count = 0;
    
    struct ListNode* stack[50000];
    
    while (ini != NULL) {
        ini = ini->next;
        count++;
    }

    ini = head;
    int half = count/2;
    count = 0;

    while (ini != NULL) {
        count++;
        if(count >= half) {
            top++;
            stack[top] = ini;
            ini = ini->next;
        } else {
            ini = ini->next;
        }
    }
    
    ini = head;

    for (int i = 0; i < count / 2; i++) {
        last = stack[top];
        top--;

        firstHalf = ini->next;
        ini->next = last;
        last->next = firstHalf;

        ini = firstHalf;
    }

    ini->next = NULL;
    

}