#ifndef TSM_H
#define TSM_H
#include <iostream>  
#include <vector>
#include <cstring> 
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm> 

using namespace std;

int tsp(int MaTran[30][30], int SoDinh, int DinhBatDau, 
        vector<vector<int>>& GiatriMin, 
        vector<vector<int>>& DuongDi);
string Traveling(int MaTran[30][30], int SoDinh, char DinhBatDau);

#endif 
