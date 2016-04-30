#include <stdio.h>

struct node{
	int val;
	struct node *l;
	struct node *r;
};

struct node tree[3000] = {};
int empty=0;

int buff[3000] = {};

void put(struct node *a, int val){
	if(val<a->val){
		if(a->l){
			put(a->l, val);
		}else{
			tree[empty].val = val;
			tree[empty].l = 0;
			tree[empty].r = 0;
			a->l = &tree[empty++];
		}
	}else{
		if(a->r){
			put(a->r, val);
		}else{
			tree[empty].val = val;
			tree[empty].l = 0;
			tree[empty].r = 0;
			a->r = &tree[empty++];
		}
	}
}

void print(struct node *a){
	if(a->r)
		print(a->r);
	if(a->l)
		print(a->l);
	printf("%d ", a->val);
}

int main(){
	int i, n, t;
	scanf("%d", &n);
	if(n==0)
		return 0;
	for(i=0;i<n;i++){
		scanf("%d", &buff[i]);
	}

	tree[empty].val=buff[n-1];
	tree[empty].l = 0;
	tree[empty++].r = 0;
	for(i=1;i<n;i++){
		put(&tree[0], buff[n-i-1]);
	}
	print(&tree[0]);
	return 0;
}

