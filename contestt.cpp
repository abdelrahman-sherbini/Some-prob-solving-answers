#include <iostream>
#include <stdio.h>
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define ll long long
#define pb push_back
#define ld long double
#define INF 1e18
#define sortde(X) sort(X.begin(), X.end(), greater<int>())
#define sortas(X) sort(X.begin(), X.end())
#define flush        \
    {                \
        cin.clear(); \
        cin.sync();  \
    }
#define itos(X) to_string(X)
using namespace std;
vector<string> split(string text, char delim, bool flag)
{
    if (flag)
    {
        vector<string> list;
        string temp = "";
        text.push_back(delim);
        bool tmp = false;
        for (size_t i = 0; i < text.length(); i++)
        {
            if (text[i] == (delim))
            {
                if (tmp)
                    continue;
                if (i != 0)
                    list.pb(temp);
                temp = "";
                tmp = true;
            }
            else
            {
                tmp = false;
                temp.pb(text[i]);
            }
        }
        return list;
    }
    else
    {
        vector<string> list;
        string temp = "";
        text.pb(delim);
        for (size_t i = 0; i < text.length(); i++)
        {
            if (text[i] == (delim))
            {
                list.pb(temp);
                temp = "";
            }
            else
            {
                temp.pb(text[i]);
            }
        }
        return list;
    }
}

vector<int> primess(int n,vector<int> primes){
    for(int i = 1; i < n+1; i++)
    {
        int sum =0;
        for(int j = 1; j < i+1; j++)
        {
            if(i%j!=0) continue;
            sum +=1; 
            if(sum>2)
            break;
            if (j ==i){
                if(sum==2){
                    primes.pb(i);
                }
            }
        }
        
    }
    return primes;
    
}
int shortestPath(vector<vector<int>> graph, int u, int v, int k,int V)
{
    // Table to be filled up using DP. The value sp[i][j][e] will store
    // weight of the shortest path from i to j with exactly k edges
    int sp[V][V][k+1];
 
    // Loop for number of edges from 0 to k
    for (int e = 0; e <= k; e++)
    {
        for (int i = 0; i < V; i++)  // for source
        {
            for (int j = 0; j < V; j++) // for destination
            {
                // initialize value
                sp[i][j][e] = 999;
 
                // from base cases
                if (e == 0 && i == j)
                    sp[i][j][e] = 0;
                if (e == 1 && graph[i][j] != 999)
                    sp[i][j][e] = graph[i][j];
 
                //go to adjacent only when number of edges is more than 1
                if (e > 1)
                {
                    for (int a = 0; a < V; a++)
                    {
                        // There should be an edge from i to a and a
                        // should not be same as either i or j
                        if (graph[i][a] != 999 && i != a &&
                            j!= a && sp[a][j][e-1] != 999)
                          sp[i][j][e] = min(sp[i][j][e], graph[i][a] +
                                                       sp[a][j][e-1]);
                    }
                }
           }
        }
    }
    return sp[u][v][k];
}
int main()
{

int m,n ;
string s1;
getline(cin,s1);
vector<string> s11 = split(s1,' ',true);
m = stoi(s11[0]);n=stoi(s11[1]);
vector<vector<int>> house(n);

flush
vector<string> s22;
for(int i = 0; i < n; i++)
{
    string s2;
getline(cin,s2);
 s22 = split(s2,' ',true);
house[i] = vector<int>(3);
for(int j  = 0; j <3; j++)
{
    house[i][j] = stoi(s22[j]);
}
}
string s;
getline(cin,s);
vector<string> st = split(s,' ',true);
vector<int> friends;
for(auto i:st){
    friends.pb(stoi(i));
}
bool opt = false;
vector<int> swea;
for(int o = 0; o < n; o++)
    {
        swea.pb(house[o][0]);
        swea.pb(house[o][1]);
    }
for(auto q:friends){
    if(!(find(swea.begin(), swea.end(), q) != swea.end())) {
  opt = true  ;
} 
}
if(opt){
    cout<<-1;
}
vector<vector<int>> graph(m+1);

for(int i = 0; i < m+1; i++)
{
    graph[i] = vector<int>(m+1,999);
    for(int j = 0; j < m+1; j++)
    {
        if(i==house[j][0]){
            graph[i][house[j][1]]=house[j][2];
        }

    }

    
    

}
m = m+1;
int q,w,e,r,t,y;
vector<int> minn;
for(int i = 0; i < n+1; i++)
{
q=shortestPath(graph,friends[0],friends[1],i,m);
minn.pb(q);
}
for(int i = 0; i < minn.size(); i++)
{
    if(minn[i]<0) minn[i]*=-1;
}
 q=*min_element(minn.begin(), minn.end());
 minn.clear();
for(int i = 0; i < n+1; i++)
{

w=shortestPath(graph,friends[2],friends[1],i,m);

minn.pb(w);
}
for(int i = 0; i < minn.size(); i++)
{
    if(minn[i]<0) minn[i]*=-1;
}
w=*min_element(minn.begin(), minn.end());
 minn.clear();
for(int i = 0; i < n+1; i++)
{
e=shortestPath(graph,friends[1],friends[2],i,m);
minn.pb(e);
}
for(int i = 0; i < minn.size(); i++)
{
    if(minn[i]<0) minn[i]*=-1;
}
 e=*min_element(minn.begin(), minn.end());
  minn.clear();
for(int i = 0; i < n+1; i++)
{
r=shortestPath(graph,friends[0],friends[2],i,m);
minn.pb(r);
}
for(int i = 0; i < minn.size(); i++)
{
    if(minn[i]<0) minn[i]*=-1;
}

 r=*min_element(minn.begin(), minn.end());
  minn.clear();
for(int i = 0; i < n+1; i++)
{
t=shortestPath(graph,friends[2],friends[0],i,m);
minn.pb(t);
}
for(int i = 0; i < minn.size(); i++)
{
    if(minn[i]<0) minn[i]*=-1;
}
 t=*min_element(minn.begin(), minn.end());
  minn.clear();
for(int i = 0; i < n+1; i++)
{
y=shortestPath(graph,friends[1],friends[0],i,m);
minn.pb(y);
}
for(int i = 0; i < minn.size(); i++)
{
    if(minn[i]<0) minn[i]*=-1;
}
 y=*min_element(minn.begin(), minn.end());

vector<int>res;
res.pb(t+y);
res.pb(q+w);
res.pb(e+r);
int resl = *min_element(res.begin(), res.end());
vector<int> resu;
for(int i = 0; i < 3; i++)
{
    if(res[i]==resl){
        resu.pb(i);
    }
}

vector<int> fino;
for(auto i :resu){
fino.pb(friends[i]);
}
if(fino.size()>1){
    int fin=*min_element(fino.begin(), fino.end());
    cout<<fin <<" "<<resl;
}else if (fino[0]) cout<<fino[0] <<" "<<resl;
else cout<<"-1";
// int n;
// cin >>n;
// vector<int> pr;
// vector<int> primes = primess(n,pr);
// bool flag =false;
// for(int i = 0; i < n; i++)
// {
//     if (n%primes[i]==0){
//         flag = true;
//         break;
//     }
// }
// if(!flag){
//     cout<<"NO";
// }else cout<<"YES";

// int n;
// cin >>n;
// vector<int> array;
// flush
// string s;
// getline(cin,s);
// vector<string> temp = split(s,' ',true);
// for(auto i : temp){
//     array.pb(stoi(i));
// }
// for(int i = 0; i < n; i++)
// {
//     if(i!=n-1){

//     if (array[i]<0){
//         cout<<array[i]+1<<" ";
//     }
//     else{
//         cout<<array[i]<<" ";
//     }
//     }else{
//             if (array[i]<0){
//         cout<<array[i]+1;
//     }
//     else{
//         cout<<array[i];
//     }
//     }
// }




}