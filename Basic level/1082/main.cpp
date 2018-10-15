#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;
class Player
{
	public:
		char bianhao[5];
		short x;
		short y;
	public:
		Player()
		{
			memset(this->bianhao,'\0',sizeof(char)*5);
			x=0;
			y=0;
		}
		double lengthto()
		{
			return sqrt(pow(this->x,2)+pow(this->y,2));
		}
};
int main()
{
	unsigned short n;
	cin>>n;
	Player *arr=new Player[n];
	for (unsigned short i=0;i<n;i++) cin>>arr[i].bianhao>>arr[i].x>>arr[i].y;
	Player max=arr[0];
	Player min=arr[0];
	for (unsigned short i=1;i<n;i++) {
		if (arr[i].lengthto()>max.lengthto()) {
			max=arr[i];
		}
		if (arr[i].lengthto()<min.lengthto()) {
			min=arr[i];
		}
	}
	cout<<min.bianhao;
	cout<<' ';
	cout<<max.bianhao;
	return 0;
}
