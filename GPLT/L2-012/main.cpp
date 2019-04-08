#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int heap[maxn]={0};
void upadjust(int low,int high)
{
	int i=high,j=i/2;
	while (j>=low) {
		if (heap[j]>heap[i]) {
			swap(heap[i],heap[j]);
			i=j;
			j=i/2;
		}
		else break;
	}
}
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
bool check2(int a,int b)
{
	int anum=1,bnum=1;
	while (heap[anum]!=a) anum++;
	while (heap[bnum]!=b) bnum++;
	int a1=heap[anum/2],b1=heap[bnum/2];
	if (a1==b1) return 1;
	else return 0;
}
bool check3(int a,int b) //a is the parent of b
{
	int anum=1,bnum=1;
	while (heap[anum]!=a) anum++;
	while (heap[bnum]!=b) bnum++;
	if (anum==bnum/2) return 1;
	else return 0;
}
bool check4(int a,int b) //a is a child of b
{
	int anum=1,bnum=1;
	while (heap[anum]!=a) anum++;
	while (heap[bnum]!=b) bnum++;
	if (bnum==anum/2) return 1;
	else return 0;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		int t;
		scanf("%d",&t);
		heap[i]=t;
		if (i>1) upadjust(1,i);
	}
	cin.clear();
	cin.sync();
	for (int i=0;i<m;i++) {
		int nodea;
  		string s;
		cin>>nodea;
		cin.ignore();
  		getline(cin,s,'\n');
  		if (s.find("root")!=string::npos) {
			if (heap[1]==nodea) printf("T\n");
			else printf("F\n");
		}
		else if (s.find("siblings")!=string::npos) {
			bool isfu=0;
			int nodeb=0;
			for (int h=0;h<s.length();h++) {
				if (isdigit(s[h])) nodeb=nodeb*10+s[h]-'0';
				if (s[h]=='-') isfu=1;
			}
			if (isfu) nodeb=-nodeb;
			if (check2(nodea,nodeb)) printf("T\n");
			else printf("F\n");
		}
		else if (s.find("parent")!=string::npos) {
			bool isfu=0;
			int nodeb=0;
			for (int h=0;h<s.length();h++) {
				if (isdigit(s[h])) nodeb=nodeb*10+s[h]-'0';
				if (s[h]=='-') isfu=1;
			}
			if (isfu) nodeb=-nodeb;
			if (check3(nodea,nodeb)) printf("T\n");
			else printf("F\n");
		}
		else {
			bool isfu=0;
			int nodeb=0;
			for (int h=0;h<s.length();h++) {
				if (isdigit(s[h])) nodeb=nodeb*10+s[h]-'0';
				if (s[h]=='-') isfu=1;
			}
			if (isfu) nodeb=-nodeb;
			if (check4(nodea,nodeb)) printf("T\n");
			else printf("F\n");
		}
	}
	return 0;
}
