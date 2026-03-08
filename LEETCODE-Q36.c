// Problem: Design Circular Deque
// Name: Aditya Gautam

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int *q;
    int f,r,s,c;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k){
    MyCircularDeque* o = malloc(sizeof(*o));
    o->q = malloc(k*sizeof(int));
    o->f = 0;
    o->r = -1;
    o->s = 0;
    o->c = k;
    return o;
}

bool myCircularDequeInsertFront(MyCircularDeque* o,int v){
    if(o->s==o->c) return false;
    o->f=(o->f-1+o->c)%o->c;
    o->q[o->f]=v;
    if(!o->s) o->r=o->f;
    o->s++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* o,int v){
    if(o->s==o->c) return false;
    o->r=(o->r+1)%o->c;
    o->q[o->r]=v;
    o->s++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* o){
    if(!o->s) return false;
    o->f=(o->f+1)%o->c;
    o->s--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* o){
    if(!o->s) return false;
    o->r=(o->r-1+o->c)%o->c;
    o->s--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* o){
    return o->s ? o->q[o->f] : -1;
}

int myCircularDequeGetRear(MyCircularDeque* o){
    return o->s ? o->q[o->r] : -1;
}

bool myCircularDequeIsEmpty(MyCircularDeque* o){
    return o->s == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* o){
    return o->s == o->c;
}

void myCircularDequeFree(MyCircularDeque* o){
    free(o->q);
    free(o);
}

/* ---------- Test Program ---------- */

int main(){
    MyCircularDeque* dq = myCircularDequeCreate(3);

    printf("%d\n", myCircularDequeInsertLast(dq,1));
    printf("%d\n", myCircularDequeInsertLast(dq,2));
    printf("%d\n", myCircularDequeInsertFront(dq,3));
    printf("%d\n", myCircularDequeInsertFront(dq,4));

    printf("Rear: %d\n", myCircularDequeGetRear(dq));
    printf("IsFull: %d\n", myCircularDequeIsFull(dq));

    printf("%d\n", myCircularDequeDeleteLast(dq));
    printf("%d\n", myCircularDequeInsertFront(dq,4));

    printf("Front: %d\n", myCircularDequeGetFront(dq));

    myCircularDequeFree(dq);
}
