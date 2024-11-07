#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define vi vector<int>
#define vll vector<ll>
#define vss vector<string>
#define el '\n'
#define pb push_back
#define st string
#define clos 3
#define an &&
#define loop for (int i=0;i<n;i++)

using namespace std;


class MEMORY {
private:
    static const ll size = 256;
    vector<pair<ll, st>> cells;

public:
    MEMORY();
    void set_memoryvalue(ll ad, st value);
    st get_meoryvalue(ll ad);
    void print();
};

#endif // MEMORY_H