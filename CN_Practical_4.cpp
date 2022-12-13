#include<bits/stdc++.h>
using namespace std;
#define N 5000000
vector<vector<int>> v(N);

vector<char> parity(string s,int r,int n)
{
    vector<char> ans;
    int c=0;

    for(int i=0; i<r; i++)
    {
        int j=pow(2,i),k;
        int l=pow(2,i+1);
        int o=j,t=j;
        while(j<=n)
        {
            k=j;
            t=o;
            while(t-- && k<=n)
            {
                v[i].push_back(k);
                k++;
            }
            j=j+l;
        }
    }

    for(int i=0; i<r; i++)
    {
        c=0;
        for(int j=0; j<v[i].size(); j++)
        {
            if(s[v[i][j] - 1] == '1')
            {
                c++;
            }
        }
        char h=char(c%2  + 48);
        ans.push_back(h);
    }
    return ans;
}

int main()
{
    string s,d="";
    int m,r=0,n;
    cout<<endl;
    cout<<"Enter the size of data bits: ";
    cin>>m;
    cout<<"Enter the data bit         : ";  // 1011001
    cin>>s;
    cout<<endl;

    while(1)
    {
       int p=pow(2,r);
       if(p>= m+r+1)
       {
          break;
       }
       else
       {
          r++;
       }
    }

    n=m+r;
    cout<<"Total number of Redundant bit is :  "<<r<<endl;
    cout<<"Total number of data bit is      :  "<<m<<endl;
    cout<<"Total number of message bit is   :  "<<n<<endl;
    cout<<endl;
    int j=1,k=m-1,l=0;
    for(int i=1; i<=n; i++)
    {
        if(i==j)
        {
            d+='i';
            l++;
            j=pow(2,l);
         }
         else
         {
            d+=s[k];
            k--;
         }
     }

     vector<char> ans=parity(d,r,n);
     j=1,k=0,l=0;
     for(int i=0; i<n; i++)
     {
         if(i== j-1)
         {
            d[i]=ans[l];
            l++;
            j=pow(2,l);
         }
     }

     reverse(d.begin(), d.end());
     cout<<"The generated Hamming Code is               : "<<d<<endl;
     cout<<"Enter the received Hamming Code by receiver : ";
     cin>>s;
     cout<<endl;

     reverse(s.begin() , s.end());
     vector<int> check;

     for(int i=0; i<r; i++)
     {
        int c=0;
        for(int j=0; j<v[i].size(); j++)
        {
            c += s[v[i][j] - 1] - 48 ;
        }
        check.push_back(c%2);
     }

     int error=0;
     j=1;
     for(int i=0; i<check.size(); i++)
     {
        error += check[i]*j;
        j=pow(2,i+1);
     }

     if(error==0)
     {
        cout<<"--> No Error Detected on receiver side"<<endl;
        cout<<endl;
     }
     else
     {
       cout<<"--> Error Detected at position "<<error<<" on receiver side"<<endl;
      if(s[error - 1]=='0')
      {
        s[error - 1]='1';
      }
      else
      {
        s[error - 1]='0';
      }
      reverse(s.begin() , s.end());
      cout<<"--> your Original data is: "<<s<<endl;
      cout<<endl;
     }
    return 0;
}