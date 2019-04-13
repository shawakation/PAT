#include <cstdio>
using namespace std;
struct node
{
	int data;
	struct node *next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};
int main()
{
	int k,num,nodenum=0;
	scanf("%d",&k);
	node *C=new node(-1);
	node *r=C;
	while (1) {
		scanf("%d",&num);
		if (num<0) break;
		node *s=new node(num);
		r->next=s;
		r=s;
		nodenum++;
	}
	int k1=nodenum+1-k;
	if (k1<1) printf("NULL");
	else {
		r=C;
		for (int i=1;i<=k1;i++) r=r->next;
		printf("%d",r->data);
	}
	return 0;
}
