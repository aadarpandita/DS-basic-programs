#include<iostream>
#include<iomanip>

using namespace std;

int main()
{

cout<<setw(8)<<"Aadar"<<endl;
cout<<setw(4)<<123.45<<endl;
cout<<setprecision(5)<<123.457891<<endl;
cout<<setprecision(2)<<12.3<<endl;
cout<<setprecision(2)<<1<<endl;
cout.setf(ios::fixed);
cout<<setprecision(5)<<123.457891<<endl;

return 0;
}

