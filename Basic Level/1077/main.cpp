#include <iostream>
using namespace std;
int main()
{
	unsigned short N,M;
	cin>>N>>M;
	for (unsigned short i=0;i<N;i++) {
		unsigned short Gteacher,Gstusum,Gsum=0,Gmin=M,Gmax=0,Gcount=0;
		short Gstu;
		cin>>Gteacher;
		for (unsigned short j=0;j<N-1;j++) {
			cin>>Gstu;
			if (Gstu>=0&&Gstu<=M) Gcount++;
			else continue;
			if (Gstu>Gmax) Gmax=Gstu;
			if (Gstu<Gmin) Gmin=Gstu;
			Gsum+=Gstu;
		}
		Gstusum=(Gsum-Gmax-Gmin)/(Gcount-2);
		cout<<(Gteacher+Gstusum+1)/2<<endl;		//+1再/2 可以实现四舍五入 
	}
	return 0;
}
