#include <stdio.h>
#include <stdlib.h>

typedef struct list_element {
    int element_value;
    struct list_element *next;
} list_element;

int get_element_value_from_index (int index,list_element *current_element_of_list_elements){
    for (int i=0; i <= index; i++) {
        printf("%d\n", current_element_of_list_elements-> element_value);
        current_element_of_list_elements = current_element_of_list_elements -> next;
    }
    return current_element_of_list_elements -> element_value;

}

void show_value_of_element (list_element *element){
    printf("The value of the element is : %d\n", element -> element_value);
    printf("The value of the next element is : %d\n", element -> next -> element_value);

    if(element -> next -> next != NULL) {
        printf("The value of the next next element is : %d\n", element -> next -> next -> element_value);
    }
}

void happen(int value, list_element **head) {
    list_element *new_element = malloc(sizeof(list_element));
    new_element->element_value = value;
    new_element->next = *head;
    *head = new_element;
}

void pop(list_element **head) {
    if (*head == NULL) {
        return;
    }
    list_element *temp = *head;
    *head = (*head)->next;
    free(temp);
}



int main (int argc, const char *argv[]) {

    list_element *temporary_element = NULL;
    list_element *first_value_element = NULL;

    for (int i=0; i<11; i++) {
        list_element *temporary_value = malloc(sizeof(list_element));
        temporary_value->element_value=i;

        if(temporary_element != NULL) {
            temporary_element -> next = temporary_value ;
        }

        if (temporary_element == NULL) {
            first_value_element = temporary_value;
        }

        temporary_element = temporary_value;
    }

    show_value_of_element(first_value_element);

    printf("Choose an index :\n");
    int choice;
    scanf("%d",&choice);

    printf("The value at the index %d is %d.\n",choice, get_element_value_from_index(choice,first_value_element));


    printf("Congrats !!\n");
    return 0;
}