#include <iostream>
using namespace std;
int main()
{
	unsigned short N,M;
	cin>>N>>M;
	unsigned short *score=new unsigned short [M];
	short **input=new short*[N];
	for (unsigned short i=0;i<N;i++)
		input[i]=new short[M];
	short *answer=new short[M];
	for (unsigned short i=0;i<M;i++) cin>>score[i];
	for (unsigned short i=0;i<M;i++) cin>>answer[i];
	for (unsigned short i=0;i<N;i++)
		for (unsigned short j=0;j<M;j++) cin>>input[i][j];
	for (unsigned short i=0;i<N;i++) {
		unsigned short defen=0;
		for (unsigned short j=0;j<M;j++)
			if (input[i][j]==answer[j]) defen+=score[j];
		cout<<defen<<endl;
	}
	return 0;
}
