/*
大数除法的过程
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
	string A;
	short B;
	queue<short> shangque;
	cin>>A>>B;
	short shang=(A[0]-'0')/B;
	short lena=A.length();
	if (lena==1||(lena>1&&shang!=0)) shangque.push(shang);
	short reminder=(A[0]-'0')%B;
	for (short i=1;i<lena;i++) {
		shang=(reminder*10+A[i]-'0')/B;
		reminder=(reminder*10+A[i]-'0')%B;
		shangque.push(shang);
	}
	while (!shangque.empty()) {
		cout<<shangque.front();
		shangque.pop();
	}
	cout<<' '<<reminder;
	return 0;
}
