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
#define MAX 100005
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int arr[2*MAX]; //array to store the postions of the christmas trees
set<int> ppl[2*MAX];//an array of set to store the nearest people for each of the ith tree
bool vis[2*MAX][2];//to check if there are people whose nearest possible tree is the ith tree 
                   //there 2 columns: vis[i][0] if its possible on the left of the ith tree , vis[i][1] if its possible on the right of the ith tree.
set<int> valid;//a set of the indices of the trees whose (vis[i][0] && vis[i][1])!=0


int solve(int n, int m);
/* in this function we sequentially add the points which are the closest to the trees, i.e, points which are at distance 1, then distance 2, then distance
3 so on until there are m such points. ppl stores all such points for each of the christamas trees and res calculates the ans as we proceed with out algorithm
*/






// d is our closest distance between a person and ith tree, we increment it until we get m points. flag is for breaking out of the outer loop once we get  m points
    // k1 keeps a count of points which gives us the least distance and res stores the minimum sum of distances to the nearest tree for all people.
    //#include "1283D.h"