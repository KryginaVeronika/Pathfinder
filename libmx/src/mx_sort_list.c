#include "../inc/libmx.h"

t_list *mx_sort_list(t_list*list, bool(*cmp)(void *a, void *b)) { 
    if(cmp == NULL || list == NULL)
        return list;
    t_list *tmp = list;

    int size = mx_list_size(tmp);

    for(int i = 0; i < size; i++) {
		tmp = list;
        for(int j = 0; j < size - i; j++) {
	        if(cmp(tmp->data,tmp->next->data)) {
				int *data = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = data;
			}
			tmp = tmp->next;
        }
    }

	return list;
}

