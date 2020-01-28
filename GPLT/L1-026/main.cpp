#include <iostream>
using namespace std;
int main()
{
	char s[]="I Love GPLT";
	for (int i=0;*(s+i)!='\0';i++) printf("%c\n",*(s+i));
	return 0;
}
