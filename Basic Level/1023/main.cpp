#include <iostream>
#include <deque>
#include <memory.h>
using namespace std;
unsigned short countt[10];
deque<unsigned short> arr;
void scan()
{
	for (unsigned short k=0;k<10;k++)
		if (countt[k]!=0) {
			arr.push_back(k);
			countt[k]--;
			scan();
		}
}
int main()
{
	memset(countt,0,sizeof(countt));
	for (unsigned short i=0;i<10;i++) cin>>countt[i];
	for (unsigned short i=1;i<10;i++)
		if (countt[i]!=0) {
			arr.push_back(i);
			countt[i]--;
			break;
		}
	scan();
	for (unsigned short i=0;i<arr.size();i++) cout<<arr.at(i);
	cout<<endl;
	return 0;
}
