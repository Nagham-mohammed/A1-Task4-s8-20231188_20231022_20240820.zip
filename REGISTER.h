#ifndef REGISTER_H
#define REGISTER_H

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



class REGISTER {
private:
    static const ll size = 16;
    vector<pair<ll, st>> regester;

public:
    REGISTER();
    void set_regester(ll a, st value);
    st get_regvalue(ll a);
    void print();
};

#endif // REGISTER_H