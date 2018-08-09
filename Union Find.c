#include <stdio.h>
#include <stdlib.h>

#define N 10

int ID[N];
int size[N];

void init(){
    int i;
    for(i=0; i<N; i++){
        // N array accesses
        ID[i] = i;
        // only used in weighted Quick-Union
        size[i] = 1;
    }
}

void print_ID(){
    int i;
    for(i=0; i<N; i++){
        printf("%d ", ID[i]);
    }
    printf("\n");
}
//#----------Quick-Find----------#
void QF_union(int p, int q){
    // for every element which has the same set id wit p,
    // assign id of q to it.
    // 2*N + 2 array accesses
    int i;
    int pid = ID[p];
    int qid = ID[q];
    for(i=0; i<N; i++){
        if(ID[i] == pid)
            ID[i] = qid;
    }
}

int QF_find(int p, int q){
    // ID[i] is the set id of ith element
    // The elements which have the same set id is connected
    // 2 array accesses
    return ID[p] == ID[q];
}
//#------------------------------#

//#----------Quick-Union----------#
int QU_root(int i){
    // depth of i array accesses
    while(ID[i] != i) i = ID[i];
    return i;
}

void QU_union(int p, int q){
    // change the root of p to point to the root of q
    // depth of p and q array accesses
    int p_root = QU_root(p);
    int q_root = QU_root(q);
    ID[p_root] = q_root;
}

int QU_find(int p, int q){
    // ID[i] is the parent of i
    // check whether p and q have same root
    // depth of p and q array accesses
    return QU_root(p) == QU_root(q);
}
//#------------------------------#

//#----------Weighted Quick-Union----------#
int WQU_root(int i){
    // Identical to Quick-Union
    while(ID[i] != i) i = ID[i];
    return i;
}

void WQU_union(int p, int q){
    // change the root with smaller size to the larger one
    // depth of any node is at most lg N
    int p_root = WQU_root(p);
    int q_root = WQU_root(q);
    if (p_root == q_root) return;
    if(size[p_root] < size[q_root]){
        ID[p_root] = q_root;
        size[q_root] += size[p_root];
    }
    else{
        ID[q_root] = p_root;
        size[p_root] += size[q_root];
    }
}

int WQU_find(int p, int q){
    // Identical to Quick-Union
    return WQU_root(p) == WQU_root(q);
}
//#----------------------------------------#

//#----------Weighted Quick-Union with Path Compression----------#
int WQUPC_root(int i){
    while(ID[i] != i){
        // make every other node in path
        // point to its grandparent (thereby halving path length)
        ID[i] = ID[ID[i]];
        i = ID[i];
    }
    return i;
}

void WQUPC_union(int p, int q){
    // Identical to weighted Quick-Union
    int p_root = WQUPC_root(p);
    int q_root = WQUPC_root(q);
    if (p_root == q_root) return;
    if(size[p_root] < size[q_root]){
        ID[p_root] = q_root;
        size[q_root] += size[p_root];
    }
    else{
        ID[q_root] = p_root;
        size[p_root] += size[q_root];
    }
}

int WQUPC_find(int p, int q){
    // Identical to Quick-Union
    return WQUPC_root(p) == WQUPC_root(q);
}
//#--------------------------------------------------------------#


void union_fc(int p, int q){
    printf("Union(%d, %d) -> ", p, q);
    // Use Quick-Find
    QF_union(p, q);

    // Use Quick-Find
    // QU_union(p, q);

    // Use Weighted Quick-Find
    // WQU_union(p, q);

    // Use Weighted Quick-Find with Path Compression
    // WQUPC_union(p, q);
    print_ID();
}

void find_fc(int p, int q){
    int connected;
    // Use Quick-Find
    connected = QF_find(p, q);

    // Use Quick-Union
    // connected = QU_find(p, q);

    // Use Weighted Quick-Find
    // connected = WQU_find(p, q);

    // Use Weighted Quick-Find with Path Compression
    // connected = WQUPC_find(p, q);
    if(connected)
        printf("Find(%d, %d), YES.\n", p, q);
    else
        printf("Find(%d, %d), NO.\n", p, q);
}

int main()
{
    int p, q;
    /*
    You need goto union_fc() function and find_fc() function to
    select which method you want to use (the default method is Quick-Find).
    And then you can run the code.
    */
    init();
    printf("Initialize  -> ");
    print_ID();

    p = 4; q = 3;
    union_fc(p, q);

    p = 3; q = 8;
    union_fc(p, q);

    p = 6; q = 5;
    union_fc(p, q);

    p = 9; q = 4;
    union_fc(p, q);

    p = 2; q = 1;
    union_fc(p, q);

    p = 8; q = 9;
    find_fc(p, q);

    p = 5; q = 0;
    find_fc(p, q);

    p = 5; q = 0;
    union_fc(p, q);

    p = 7; q = 2;
    union_fc(p, q);

    p = 6; q = 1;
    union_fc(p, q);

    p = 5; q = 0;
    find_fc(p, q);

    p = 7; q = 3;
    union_fc(p, q);

}
