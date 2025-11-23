#include "bellman.h"

void BF(int G[30][30], int numV, char startV, int BFValue[], int BFPrevious[]){
    for (int i=0; i<numV; i++){
        if(BFValue[i]==-1) BFValue[i]=10000;
    }
    if (BFValue[(int)startV-(int)'A'==10000]) BFValue[(int)startV-(int)'A']=0;
    int temp[30];
    for (int i=0; i<numV; i++) {
        temp[i]=BFValue[i];
    }
    
    for (int i=0; i<numV; i++){
        if(BFPrevious[i]==-1) BFPrevious[i]=-1;
    }
    
    for (int i=0; i<numV; i++) {
        for (int j=0; j<numV; j++) {
            if (G[i][j]==0) continue;
            if (BFValue[i] + G[i][j] < temp[j]) {
                temp[j] = BFValue[i] + G[i][j];
                BFPrevious[j] = i;
            }
        }
    }
    for (int i=0; i<numV; i++){
        BFValue[i]=temp[i];
        if (BFValue[i]==10000) BFValue[i] = -1;
    }
}
string BF_Path(int G[30][30], int numV, char startV, char goalV){
    int startIndex = startV - 'A', goalIndex = goalV - 'A';
    int BFValue[30], BFPrevious[30];
    for(int i=0; i<numV; i++){
        BFValue[i]=-1;
        BFPrevious[i]=-1;
    }
    for (int i=0; i<numV-1; i++){
        BF(G, numV, startV, BFValue, BFPrevious);
    }
    
    string result;
    int currentIndex = goalIndex;
    while (currentIndex != startIndex) {
        result = char(currentIndex + 'A') + result;
        result = ' ' + result;
        currentIndex = BFPrevious[currentIndex];
    }
    
    result = startV + result;
    return result;
}