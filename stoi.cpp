#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
void swapnum(int &a, int&b)
{
	int temp = a;
	a=b;
	b=temp;
}

void reversed(int a[], int size)
{
	for(int i=0; i<size/2; i++)
		swapnum(a[i],a[size-(i+1)]);
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int string_to_int(string str)
{
	int len = str.length();
	int sum = 0;

	for(int i=0; i<len; i++)
		sum=sum*10 + (str[i]-'0');

	return sum;
}

string int_to_string(int num)
{

	string str;
	while(num>0)
	{
		str += ((char)(num%10+'0'));
		num=num/10;
	}
	cout<<str.length()<<endl;
	reverse(str.begin(), str.end());
	return str;
}

int main() 
{
	// int a[5]={1,2,3,4,5};
	// reversed(a,5);

	// int num = string_to_int("");
	// cout<<num+5<<endl;
	// int a;
	// cin >> a;
	// string str = int_to_string(a);
	// cout<<str<<endl;
	string inp;
	cin>>inp;
	cout<<string_to_int(inp)<<endl;
	return 0;
}