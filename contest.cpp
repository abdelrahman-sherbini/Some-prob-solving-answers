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
int main()
{

    //     ll number;
    //     string s;
    //     getline(cin,s);
    //     vector<string> temp = split(s,'$',true);
    //     vector<int> temp2;
    // for(auto i:temp){
    //    temp2.pb(stoi(i));
    // }
    // sortas(temp2);
    // for(auto i:temp2){
    //    cout<<i;
    // }

 int n;
cin >>n;
vector<int> pr;
vector<int> primes = primess(n,pr);
bool flag =false;
for(int i = 0; i < n; i++)
{
    if (n%primes[i]==0){
        flag = true;
        break;
    }
}
if(!flag){
    cout<<"NO";
}else cout<<"YES";
////////1st question
// int n ;
// cin >>n;

// string s ;
// flush
// getline(cin,s);
// vector<string> temp = split(s,' ',true);
// vector<int> temp2;
// for(auto i :temp){
//     temp2.pb(stoi(i));
// }
// sortas(temp2);
// cout<<temp2[0]+temp2.back();


////////2nd question
// int n ;
// cin >>n;
// vector<int> odd;
// vector<int> even;
// for (int i = 1; i < n+1; i++)
// {
// if(i%2==0){
// even.pb(i);

// } 
// else odd.pb(i);
// }
// for(auto i:odd){
//     if (i ==odd.back()) cout<<i<<endl;
//     else cout<<i<<" ";
// }

// for(auto i:even){
//     if (i ==even.back()) cout<<i;
//     else cout<<i<<" ";
// }

    ///////////3rd question
    // int n,old,old1, sum = 0;
    // cin >> n;
    // auto max = [&](int m,int n)
    // {
    //     if(m>n)
    //     return m;
    //     else
    //     return n;
        
    // };
    // for (size_t i = 0; i < n+1; i++)
    // {
    //     if (i==0)
    //     old = 0,old1=0;
    //     else if(i==1)
    //     old = 0,old1=1;

    //     sum = old + old1; 
    //     old1 = old;old = sum;
    //     /* code */
    // }
    // cout << sum;

    ///////4th question
    // string in;
    // getline(cin,in);
    // vector<string> temp = split(in,' ',true);
    // int sum = 0;
    // for(auto i:temp){
    // sum += stoi(i);
    // }
    // for(auto i:itos(sum)){
    //     if (i ==itos(sum)[itos(sum).length()-1]) cout<<i;
    //     else cout<<i<<" ";
    // }

    //////////////5th question
    //     int n,sum=0;
    //     cin >> n;
    // flush
    //     for (size_t i = 0; i < n; i++)
    //     {
    //         string s;
    //         getline(cin, s);
    //         vector<string> temp = split(s, ' ', true);
    //         vector<int> temp2;
    //         for (auto j : temp)
    //         {
    //             temp2.pb(stoi(j));
    //         }
    //         sum += temp2[i];
    //     }
    //     cout<<sum;

    //     return 0;
}