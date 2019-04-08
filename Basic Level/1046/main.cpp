#include <iostream>
using namespace std;
struct Game
{
	unsigned short jiahan;
	unsigned short jiahua;
	unsigned short yihan;
	unsigned short yihua;
};
int main()
{
	unsigned short n;
	unsigned short jiahejiu=0,yihejiu=0;
	cin>>n;
	Game *games=new Game[n];
	for (unsigned short i=0;i<n;i++)
		cin>>games[i].jiahan>>games[i].jiahua>>games[i].yihan>>games[i].yihua;
	for (unsigned short i=0;i<n;i++)
		if (games[i].jiahua==games[i].jiahan+games[i].yihan&&games[i].yihua==games[i].yihan+games[i].jiahan)
			continue;
		else if (games[i].jiahua!=games[i].jiahan+games[i].yihan&&games[i].yihua!=games[i].yihan+games[i].jiahan)
			continue;
		else if (games[i].jiahua==games[i].jiahan+games[i].yihan&&games[i].yihua!=games[i].yihan+games[i].jiahan)
			yihejiu++;
		else if (games[i].jiahua!=games[i].jiahan+games[i].yihan&&games[i].yihua==games[i].yihan+games[i].jiahan)
			jiahejiu++;
	cout<<jiahejiu<<' '<<yihejiu;
	return 0;
}
