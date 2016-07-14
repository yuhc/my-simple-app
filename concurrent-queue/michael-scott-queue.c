#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>

typedef struct __node_t {
    int             value;
    struct __node_t *next;
} node_t;

typedef struct __queue_t {
    node_t          *head;
    node_t          *tail;
    pthread_mutex_t headLock;
    pthread_mutex_t tailLock;
} queue_t;

void Queue_Init(queue_t *q) {
    node_t *tmp = (node_t*)malloc(sizeof(node_t));
    tmp->next = NULL;
    q->head = q->tail = tmp;
    pthread_mutex_init(&q->headLock, NULL);
    pthread_mutex_init(&q->tailLock, NULL);
}

void Queue_Enqueue(queue_t *q, int value) {
    node_t *tmp = (node_t*)malloc(sizeof(node_t));
    assert(tmp != NULL);
    tmp->value = value;
    tmp->next = NULL;

    pthread_mutex_lock(&q->tailLock);
    q->tail->next = tmp;
    q->tail = tmp;
    pthread_mutex_unlock(&q->tailLock);
}

int Queue_Dequeue(queue_t *q, int *value) {
    pthread_mutex_lock(&q->headLock);
    node_t *tmp = q->head;
    node_t *newHead = tmp->next;
    if (newHead == NULL) {
        pthread_mutex_unlock(&q->headLock);
        return -1;
    }

    *value = newHead->value;
    q->head = newHead;
    pthread_mutex_unlock(&q->headLock);
    free(tmp);
    return 0;
}

int main() {
    queue_t *q = (queue_t*)malloc(sizeof(queue_t));
    Queue_Init(q);

    int i, t;
    for (i = 0; i < 20; i++) {
        Queue_Enqueue(q, i);
        printf("Enqueue: %d\n", i);
    }
    for (i = 0; i < 10; i++) {
        Queue_Dequeue(q, &t);
        printf("Dequeue: %d\n", t);
    }

    return 0;
}
