#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* ÊµÏÖÏ¸½ÚºöÂÔ */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}

void PreorderTraversal( BinTree BT )
{
	if (BT==NULL) return;
	printf(" %c",BT->Data);
	PreorderTraversal(BT->Left);
	PreorderTraversal(BT->Right);
}
void InorderTraversal( BinTree BT )
{
	if (BT==NULL) return;
	InorderTraversal(BT->Left);
	printf(" %c",BT->Data);
	InorderTraversal(BT->Right);
}
void PostorderTraversal( BinTree BT )
{
	if (BT==NULL) return;
	PostorderTraversal(BT->Left);
	PostorderTraversal(BT->Right);
	printf(" %c",BT->Data);
}
void LevelorderTraversal( BinTree BT )
{
	BinTree temp[1000]={NULL};
	int in=0,out=0;
	temp[in++]=BT;
	while (in>out) {
		if (temp[out]!=NULL) {
			printf(" %c",temp[out]->Data);
			if (temp[out]->Left!=NULL) temp[in++]=temp[out]->Left;
			if (temp[out]->Right!=NULL) temp[in++]=temp[out]->Right;
		}
		out++;
	}
}
