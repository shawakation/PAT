/*
1.打表大法好。。
2.不懂不懂懂懂多多多多多多多多多
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;
string numtomar[170];
string low[]= {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string high[]= {"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
unordered_map<string,int> my;
void init()
{
	for (int i=0; i<13; i++) {
		numtomar[i]=low[i];
		my[low[i]]=i;
		numtomar[i*13]=high[i];
		my[high[i]]=i*13;
	}
	for (int i=1; i<13; i++)
		for (int j=1; j<13; j++) {
			string ans=high[i]+" "+low[j];
			int dd=i*13+j;
			numtomar[dd]=ans;
			my[ans]=dd;
		}
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	getchar();
	for (int i=0; i<n; i++) {
		string s;
		getline(cin,s,'\n');
		if (isdigit(s[0])) cout<<numtomar[stoi(s)]<<endl;
		else cout<<my[s]<<endl;
	}
	return 0;
}
