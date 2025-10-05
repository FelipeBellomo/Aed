#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

int main() {
    
    return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* ini = head;
   // struct ListNode* percorre;
    int count = 0;

    while (ini != NULL)
    {
        ini = ini->next; 
        count++;
    }

    ini = head;

    if((count % 2) == 0)
        count = count + 1;


    for (int i = 0; i < count / 2; i++) {
            head = head->next;
        }    
   
    return head;


}