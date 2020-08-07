#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define v vector
#define p pair
#define fr(i, a, b) for (int i = a; i < b; ++i)
#define frn(i, a, b) for (int i = a; i > b; --i)
#define MAX 10000005
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
ll arr[2*MAX];
set<ll> ppl[2*MAX];
bool vis[2*MAX][2];
 
int main()
{
    int n,m;
    //cin>>n>>m;
    //fr(i,0,n)cin>>arr[i];
    fstream file;
    string word;
    //remove("MyFile.txt");
    file.open("MyFile.txt",ios::in);
    int k=0;
    while(file>>word)
    {
        word.c_str();
        if(k==0)n=stoi(word);
        else if(k==1)m=stoi(word);
        else arr[k-2]=stoi(word);
        k++;
    }
    file.close();
    sort(arr,arr+n);
    set<int> valid;
    fr(i,0,n)valid.insert(i);
    int d=1,flag=0;
    ll res=0;
    int k1=0,t1=0;
    while(k1!=m)
    {
        v<int> inv;
        for(auto i=valid.begin();i!=valid.end();i++)
        {
            if(*i>0 && !vis[*i][0])
            {
                if(arr[*i]-d>arr[*i-1])
                {
                    if(ppl[*i-1].find(arr[*i]-d)==ppl[*i-1].end())
                    {
                        ppl[*i].insert(arr[*i]-d);
                        res+=d;
                        k1++;
                    }
                    else vis[*i][0]=true;
                }
                else vis[*i][0]=true;
            }
            else if(*i==0)
            {
                ppl[0].insert(arr[*i]-d);
                res+=d;
                k1++;
            }
            if(k1==m)
            {
                flag=1;
                break;
            }
            if(*i<n-1 && !vis[*i][1])
            {
                if(arr[*i]+d<arr[*i+1])
                {
                    if(ppl[*i+1].find(arr[*i]+d)==ppl[*i+1].end())
                    {
                        ppl[*i].insert(arr[*i]+d);
                        res+=d;
                        k1++;
                    }
                    else vis[*i][1]=true;
                }
                else vis[*i][1]=true;
            }
            else if(*i==n-1)
            {
                ppl[n-1].insert(arr[*i]+d);
                res+=d;
                k1++;
            }
            if(k1==m)
            {
                flag=1;
                break;
            }
            
            //cout<<res<<endl;
            if(vis[*i][0]&&vis[*i][1])
            {
                t1++;
                inv.push_back(*i);
            }
        }
        fr(i,0,inv.size())
        {
            if(vis[inv[i]][0]&&vis[inv[i]][1])valid.erase(inv[i]);
        }
        if(flag)break;
        d++;
    }
    /*cout<<res<<endl;
    fr(i,0,n)
    {
        auto it = ppl[i].begin();
        while(it!=ppl[i].end())
        {
            cout<<*it<<" ";
            it++;
        }
    }
    cout<<endl;*/
    fstream outFile;
    remove("OFile.txt");
    outFile.open("OFile.txt", ios::out);
    outFile<<to_string(res)<<"\n";
    fr(i,0,n)
    {
        auto it = ppl[i].begin();
        while(it!=ppl[i].end())
        {
            outFile<<to_string(*it)<<" ";
            it++;
        }
    }
    outFile.close();
    return 0;
}