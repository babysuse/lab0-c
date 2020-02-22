#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

bool check_malloc(void *mem)
{
    if (!mem) {
        perror("malloc failed");
        return false;
    }
    return true;
}

bool check_queue(queue_t *q)
{
    if (!q) {
        printf("the queue is null\n");
        return false;
    }
    return true;
}

void free_node(list_ele_t **node)
{
    if (*node) {
        free((*node)->value);
        free(*node);
        *node = NULL;
    }
}

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (check_malloc(q))
        return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    list_ele_t **trav = &q->head;
    while (*trav) {
        list_ele_t *temp = *trav;
        trav = &(*trav)->next;
        free_node(&temp);
    }
    free(q);
}

list_ele_t *create_node(char *s)
{
    list_ele_t *new_node = malloc(sizeof(list_ele_t));
    if (!check_malloc(new_node))
        return NULL;

    size_t len = strlen(s);
    new_node->value = malloc(len + 1);
    if (!check_malloc(new_node->value))
        return NULL;
    memset(new_node->value, '\0', len);
    memcpy(new_node->value, s, len);
    new_node->next = NULL;
    return new_node;
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (!check_queue(q))
        return false;

    list_ele_t *newh;
    if (!(newh = create_node(s)))
        return false;
    newh->next = q->head;
    if (!q->head)
        q->tail = newh;
    q->head = newh;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    if (!check_queue(q))
        return false;

    list_ele_t *newt;
    if (!(newt = create_node(s)))
        return false;
    q->tail->next = newt;
    q->tail = newt;
    return false;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if (!q || !q->head)
        return false;
    list_ele_t *target = q->head;
    strncpy(sp, target->value, bufsize - 1);
    sp[bufsize - 1] = '\0';

    q->head = q->head->next;
    --q->size;
    free_node(&target);
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (check_queue(q))
        return 0;
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
