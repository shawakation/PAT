#include <iostream>
#include <stack>
using namespace std;
stack<int> s1,s2;
int n1,n2;
void inqueue(int n)
{
	if (s1.size()<n1) s1.push(n);
	else if (s1.size()==n1&&s2.empty()) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(n);
	} else if (s1.size()==n1&&!s2.empty()) printf("ERROR:Full\n");
}
void outqueue()
{
	if (!s2.empty()) {
		printf("%d\n",s2.top());
		s2.pop();
	} else if (s2.empty()&&!s1.empty()) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		printf("%d\n",s2.top());
		s2.pop();
	} else if (s2.empty()&&s1.empty()) printf("ERROR:Empty\n");
}
int main()
{
	int num;
	char c;
	scanf("%d%d",&n1,&n2);
	if (n1>n2) swap(n1,n2);
	while (1) {
		cin>>c;
		if (c=='A') {
			scanf("%d",&num);
			inqueue(num);
		} else if (c=='D') outqueue();
		else if (c=='T') break;
	}
	return 0;
}
