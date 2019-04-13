#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
struct node
{
	double num;
	char op;
	bool isnum;
	node(double a,char b,bool c) {
		num=a;
		op=b;
		isnum=c;
	}
};
stack<double> st;
deque<node> q;
double strtodbl(string s)
{
	stringstream ss(s);
	double a;
	ss>>a;
	return a;
}
int main()
{
	char c='\0';
	string s;
	while (1) {
		if (c=='\n') break;
		cin>>s;
		c=getchar();
		if (isdigit(s[0])) q.push_front(node(strtodbl(s),'\0',1));
		else q.push_front(node(0,s[0],0));
	}
	while (!q.empty()) {
		node tt=q.front();
		q.pop_front();
		if (tt.isnum) st.push(tt.num);
		else {
			double num2=st.top();
			st.pop();
			double num1=st.top();
			st.pop();
			double ans;
			switch (tt.op) {
				case '+':{
					ans=num1+num2;
					break;
				}
				case '-':{
					ans=num1-num2;
					break;
				}
				case '*':{
					ans=num1*num2;
					break;
				}
				case '/':{
					if (num2==0.0f) {
						printf("ERROR");
						exit(0);
					}
					ans=num1/num2;
					break;
				}
			}
			st.push(ans);
		}
	}
	printf("%.1f",st.top());
	return 0;
}
