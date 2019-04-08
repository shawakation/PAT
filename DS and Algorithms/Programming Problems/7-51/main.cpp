#include <cstdio>
using namespace std;
struct node {
	int data;
	struct node *next;
	node(int x) {
		data=x;
		next=NULL;
	}
};
int main()
{
	int num;
	node *A=new node(-1),*B=new node(-1);
	node *r=A;
	while (1) {
		scanf("%d",&num);
		if (num==-1) break;
		node *s=new node(num);
		r->next=s;
		r=s;
	}
	r=B;
	while (1) {
		scanf("%d",&num);
		if (num==-1) break;
		node *s=new node(num);
		r->next=s;
		r=s;
	}
	node *r1=A->next,*r2=B->next,*ans=new node(-1);
	r=ans;
	while (r1!=NULL&&r2!=NULL) {
		if (r1->data<=r2->data) {
			node *s=new node(r1->data);
			r->next=s;
			r=s;
			r1=r1->next;
		} else {
			node *s=new node(r2->data);
			r->next=s;
			r=s;
			r2=r2->next;
		}
	}
	while (r1!=NULL) {
		node *s=new node(r1->data);
		r->next=s;
		r=s;
		r1=r1->next;
	}
	while (r2!=NULL) {
		node *s=new node(r2->data);
		r->next=s;
		r=s;
		r2=r2->next;
	}
	r=ans->next;
	if (r==NULL) printf("NULL");
	else {
		printf("%d",r->data);
		r=r->next;
		while (r!=NULL) {
			printf(" %d",r->data);
			r=r->next;
		}
	}
	return 0;
}
