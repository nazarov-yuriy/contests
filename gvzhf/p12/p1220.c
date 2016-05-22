#include <stdio.h>
#include <stdlib.h>

#define PACKED
#pragma pack(push,1)
//struct __attribute__((__packed__)) node {
struct node {
    unsigned int val;
    unsigned short int next;
};
#pragma pack(pop)
#undef PACKED

struct node *arr;
int heads[1001];

void push(int *current, unsigned int a, unsigned int b) {
    arr[*current].val = b;
    arr[*current].next = heads[a] & 0xffff;
    arr[*current].val |= (heads[a] >> 16) << 31;
    heads[a] = *current;
    (*current)++;
}

int pop(int a) {
    int res = arr[heads[a]].val & 0x7fFFffFF;
    heads[a] = arr[heads[a]].next | (arr[heads[a]].val >> 31) << 16;
    return res;
}

int main() {
    unsigned int n;
    int current = 0;
    int i;
    scanf("%d", &n);
    arr = (struct node *) malloc(sizeof(struct node) * n);
    for (i = 0; i < n; i++) {
        char cmd[10];
        unsigned int a, b;
        scanf("%s %d", cmd, &a);
        if (cmd[0] == 'P' && cmd[1] == 'U') {
            scanf("%d", &b);
            push(&current, a, b);
        } else {
            printf("%d\n", pop(a));
        }
    }
    return 0;
}