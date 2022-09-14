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
int lon(vector<string> fam,string mem,int sum,vector<int>& summ){
    for(int i = 0; i < mem.size(); i++)
    {
        string mem2 = mem;
        mem2.erase(mem2.begin()+i);
        if((find(fam.begin(), fam.end(), mem2) != fam.end())){
            sum += lon(fam,mem2,1,summ);
        }
    }
            summ.pb(sum);
    return sum;
}
int main()
{

int n;
cin>>n;
flush
string nn;
vector<string> stt;
for(int i = 0; i < n; i++)
{
cin>>nn;
stt.pb(nn);
nn.clear();
}
vector<int> summ;
vector<int> summm;
int oure,ou;
for(int i = 0; i < stt.size(); i++)
{
    
lon(stt,stt[i],1,summ);
oure = *max_element(summ.begin(), summ.end()-1);
summm.pb(oure);
summ.clear();
}

ou = *max_element(summm.begin(),summm.end());
cout<<ou;
}
