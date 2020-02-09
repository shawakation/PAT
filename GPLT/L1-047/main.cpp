#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		char name[6];
		int num1,num2;
		scanf("%s %d %d",name,&num1,&num2);
		if ((15>num1||20<num1)||(50>num2||70<num2)) printf("%s\n",name);
	}
	return 0;
}
