#include "../inc/libmx.h"

void mx_pop_back(t_list**head) {
    
    t_list *tmp;

    if (*head == NULL || head == NULL)
        return;

    tmp = *head;

    if (tmp->next == NULL) {
        free(tmp);
        *head = NULL;
    } else { 
        while (tmp->next->next != NULL)
            tmp = tmp->next;

        free(tmp->next);
        tmp->next = NULL;
    }
}

