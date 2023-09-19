#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 60

struct nuocDi
{
    char n; // S? ô có th? ði ti?p
    char x, y; // V? trí
};

int danhDau[MAX + 1][MAX + 1];

char dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
char dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
nuocDi tam;

int kichThuoc;
int thoat = 0;

void xuat()
{
    int i, j;
    for (i = 1; i <= kichThuoc; i++)
    {
        for (j = 1; j <= kichThuoc; j++)
            cout << setw(3) << danhDau[i][j] << " ";
        cout << endl;
    }
    thoat = 1;
}

int tinhSoNuocDi(int x, int y)
{
    int i, j, n = 0;
    for (int k = 0; k < 8; k++)
    {
        i = x + dx[k];
        j = y + dy[k];
        if (i >= 1 && i <= kichThuoc && j >= 1 && j <= kichThuoc && danhDau[i][j] == 0)
            n++;
    }
    return n;
}

void diTuan(char x, char y, int buoc)
{
    if (buoc == kichThuoc * kichThuoc)
    {
        xuat();
    }
    else
    {
        char i, j, soNuocDi = 0;
        nuocDi luaChon[8];

        for (char k = 0; k < 8; k++)
        {
            i = x + dx[k];
            j = y + dy[k];
            if (i >= 1 && i <= kichThuoc && j >= 1 && j <= kichThuoc && danhDau[i][j] == 0)
            {
                tam.n = tinhSoNuocDi(i, j);
                tam.x = i;
                tam.y = j;
                luaChon[soNuocDi++] = tam;
            }
        }

        if (soNuocDi > 0)
        {
            // S?p x?p các ný?c ði tãng d?n theo s? ô có th? ði ti?p
            for (char i = 0; i < soNuocDi - 1; i++)
                for (char j = i + 1; j < soNuocDi; j++)
                    if (luaChon[i].n > luaChon[j].n)
                    {
                        tam = luaChon[i];
                        luaChon[i] = luaChon[j];
                        luaChon[j] = tam;
                    };
            for (char i = 0; i < soNuocDi && !thoat; i++)
            {
                danhDau[luaChon[i].x][luaChon[i].y] = buoc + 1;
                diTuan(luaChon[i].x, luaChon[i].y, buoc + 1);
                danhDau[luaChon[i].x][luaChon[i].y] = 0;
            }
        }
    }
}

int main()
{
    int x, y;
    cout << "Nhap kich thuoc ban co: ";
    cin >> kichThuoc;
    cout << "Vi tri xuat phat:" << endl;
    cout << " dong = ";
    cin >> x;
    cout << " cot = ";
    cin >> y;

    for (int i = 0; i <= kichThuoc; i++)
    {
        for (int j = 0; j <= kichThuoc; j++)
        {
            danhDau[i][j] = 0;
        }
    }

    danhDau[x][y] = 1;
    diTuan(x, y, 1);
    
    if (!thoat)
    {
        cout << "Khong tim thay loi giai." << endl;
    }

    return 0;
}

