#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {

    t_list *tmp;

    if (*head == NULL || head == NULL)
        return; 
    
    tmp = *head;
    *head = tmp->next;
    free(tmp);
}

