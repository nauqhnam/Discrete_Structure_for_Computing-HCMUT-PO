#include "tsm.h"

#define MAX_VALUE 999999

int tsp(int MaTran[30][30], int SoDinh, int DinhBatDau, vector<vector<int>>& GiatriMin, vector<vector<int>>& DuongDi) {
    int TongSoMaTran = 1 << SoDinh;
    GiatriMin[1 << DinhBatDau][DinhBatDau] = 0;

    for (int mask = 0; mask < TongSoMaTran; ++mask) {
        for (int u = 0; u < SoDinh; ++u) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < SoDinh; ++v) {
                if (mask & (1 << v) || MaTran[u][v] == 0) continue;
                int maskMoi = mask | (1 << v);
                int chiPhiMoi = GiatriMin[mask][u] + MaTran[u][v];
                if (chiPhiMoi < GiatriMin[maskMoi][v]) {
                    GiatriMin[maskMoi][v] = chiPhiMoi;
                    DuongDi[maskMoi][v] = u;
                }
            }
        }
    }
    return TongSoMaTran;
}

string Traveling(int MaTran[30][30], int SoDinh, char DinhBatDau) {
    int DinhBatDauIndex = DinhBatDau - 'A';
    int TongSoMaTran = 1 << SoDinh;

    vector<vector<int>> GiatriMin(TongSoMaTran, vector<int>(SoDinh, MAX_VALUE));
    vector<vector<int>> DuongDi(TongSoMaTran, vector<int>(SoDinh, -1));

    GiatriMin[1 << DinhBatDauIndex][DinhBatDauIndex] = 0;

    int SoDuongDi = tsp(MaTran, SoDinh, DinhBatDauIndex, GiatriMin, DuongDi);

    int ChiPhiMin = MAX_VALUE, DinhCuoi = -1;
    for (int u = 0; u < SoDinh; ++u) {
        if (MaTran[u][DinhBatDauIndex] == 0) continue;
        int chiPhi = GiatriMin[SoDuongDi - 1][u] + MaTran[u][DinhBatDauIndex];
        if (chiPhi < ChiPhiMin) {
            ChiPhiMin = chiPhi;
            DinhCuoi = u;
        }
    }

    if (ChiPhiMin == MAX_VALUE) {
        return "";
    }

    vector<int> Duong;
    for (int mask = SoDuongDi - 1, currentDinh = DinhCuoi; currentDinh != DinhBatDauIndex;) {
        Duong.push_back(currentDinh);
        int temp = currentDinh;
        currentDinh = DuongDi[mask][currentDinh];
        mask -= (1 << temp);
    }
    Duong.push_back(DinhBatDauIndex);

    string ketQua;
    for (auto it = Duong.rbegin(); it != Duong.rend(); ++it) {
        ketQua += (char)('A' + *it);
        if (it + 1 != Duong.rend()) ketQua += " ";
    }
    ketQua += " " + string(1, DinhBatDau);

    return ketQua;
}