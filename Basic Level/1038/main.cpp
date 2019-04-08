#include <iostream>
#include <memory.h>
using namespace std;
int main()
{
	unsigned int n;
	cin>>n;
	short *grades=new short[n];
	for (unsigned int i=0;i<n;i++) cin>>grades[i];
	unsigned int k;
	cin>>k;
	short *searchgrade=new short[k];
	unsigned short *countt=new unsigned short[k];
	memset(countt,0,sizeof(countt));
	for (unsigned int i=0;i<k;i++) cin>>searchgrade[i];
	for (unsigned int i=0;i<n;i++)
		for (unsigned int j=0;j<k;j++)
			if (grades[i]==searchgrade[j]) countt[j]++;
	for (unsigned int i=0;i<k;i++) {
		cout<<countt[i];
		if (i!=k-1) cout<<' ';
	}
	return 0;
}
