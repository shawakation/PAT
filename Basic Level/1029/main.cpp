#include <iostream>
#include <deque>
using namespace std;
int main()
{
	char input[81]={'\0'},actual[81]={'\0'};
	deque<char> myque;
	cin>>input;
	cin>>actual;
	for (unsigned short k=0,j=0;input[k]!='\0'||actual[j]!='\0';k++)
		if (input[k]==actual[j]) j++;
		else {
			if (input[k]>='a'&&input[k]<='z') input[k]+='A'-'a';
			for (unsigned short i=0;i<myque.size();i++)
				if (myque.at(i)==input[k]) goto aa;
			myque.push_back(input[k]);
			aa:;
		}
	for (unsigned short i=0;i<myque.size();i++) cout<<myque.at(i);
	cout<<endl;
	return 0;
}
