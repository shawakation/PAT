/*
1.注意字符循环输入的方法  char c; while((c=getchar())!='\n')
                                或 while ((c=cin.get())!='\n')
2.标记数组的思想：本题用字母的ascii码为下标的数组表示
*/
#include <cstdio>
#include <cctype>
#include <memory.h>
int main()
{
	bool list[128];
	memset(list,true,sizeof(list));
	char input;
	short bad_key;
	while ((bad_key=getchar())!='\n') {
		list[bad_key]=0;
		list[tolower(bad_key)]=0;
	}
	if (list['+']==0)
		for (short i='A';i<='Z';i++) list[i]=0;
	while ((input=getchar())!='\n') {
		if (list[input]) printf("%c",input);
	}
	printf("\n");
	return 0;
}
