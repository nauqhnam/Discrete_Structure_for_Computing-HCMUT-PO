#include "tsm.h"
#ifndef BELLMAN_H
#define BELLMAN_H

void BF(int G[30][30], int numV, char startV, int BFValue[], int BFPrevious[]);
string BF_Path(int G[30][30], int numV, char startV, char goalV);

#endif
