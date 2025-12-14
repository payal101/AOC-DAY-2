#include<bits/stdc++.h>
using namespace std;


long long sum=0;
void generate(vector<int>&halfDigits,int pos,int halfLen,long long start,long long end)
{
    if(pos==halfLen)
    {
        long long num=0;
        for(int d: halfDigits)  num = num*10+d;
        for(int d:halfDigits) num=num*10+d;
        if(num>=start && num<=end)
        {
            cout<<num<<" ";
            sum+=num;
        }
        return;
    }


int from = (pos==0) ?1:0;
for(int d=from;d<=9;d++)
{
    halfDigits[pos]=d;
    generate(halfDigits,pos+1,halfLen,start,end);
}
}

int main(int argc,char*argv[])
{
    if(argc<2)
    {
        cout<<"Usage ./aocd";
        return 0;
    }
string input=argv[1];
stringstream ss(input);
string range;

cout<<"INPUT"<<input<<endl;
while(getline(ss,range,','))
{
    range.erase(remove(range.begin(),range.end(),' '),range.end());
    size_t dash=range.find('-');
    if(dash==string::npos) continue;
    long long start=stoll(range.substr(0,dash));
    long long end=stoll(range.substr(dash+1));

    int minLen=to_string(start).size();
    int maxLen=to_string(end).size();
    for(int len=minLen;len<=maxLen;len++)
    {
        if(len%2!=0)
        {
            continue;
        }
    int halfLen=len/2;
    vector<int>halfDigits(halfLen);
    generate(halfDigits,0,halfLen,start,end);

    }
}
cout<<"Sum of valid numbers"<<sum<<endl;
return 0;
}