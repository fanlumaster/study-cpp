// UVa12171 Sculpture
// Rujia Liu
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 50 + 5;
const int maxc = 1000 + 1;

// original data
int n, X0[maxn], Y0[maxn], Z0[maxn], X1[maxn], Y1[maxn], Z1[maxn];

// discretization related
int nx, ny, nz;
int xs[maxn * 2], ys[maxn * 2], zs[maxn * 2];

// floodfill related
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
int color[maxn * 2][maxn * 2][maxn * 2];

struct Cell {
    int x, y, z;
    Cell(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
    bool valid() const { return x >= 0 && x < nx - 1 && y >= 0 && y < ny - 1 && z >= 0 && z < nz - 1; }
    bool solid() const {
        return color[x][y][z] == 1;  // solid
    }
    bool getVis() const {
        return color[x][y][z] == 2;  // visited
    }
    void setVis() const { color[x][y][z] = 2; }
    Cell neighbor(int dir) const { return Cell(x + dx[dir], y + dy[dir], z + dz[dir]); }
    int volume() const { return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]); }
    int area(int dir) const {
        if (dx[dir] != 0)
            return (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
        else if (dy[dir] != 0)
            return (xs[x + 1] - xs[x]) * (zs[z + 1] - zs[z]);
        return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]);
    }
};

void discretize(int* x, int& n) {
    sort(x, x + n);
    n = unique(x, x + n) - x;
}

int ID(int* x, int n, int x0) { return lower_bound(x, x + n, x0) - x; }

void floodfill(int& v, int& s) {
    v = 0;
    s = 0;
    Cell c;
    c.setVis();
    queue<Cell> q;
    q.push(c);
    while (!q.empty()) {
        Cell c = q.front();
        q.pop();
        v += c.volume();
        for (int i = 0; i < 6; i++) {
            Cell c2 = c.neighbor(i);
            if (!c2.valid()) continue;
            if (c2.solid())
                s += c.area(i);
            else if (!c2.getVis()) {
                c2.setVis();
                q.push(c2);
            }
        }
    }
    v = maxc * maxc * maxc - v;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        nx = ny = nz = 2;
        xs[0] = ys[0] = zs[0] = 0;
        xs[1] = ys[1] = zs[1] = maxc;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d%d%d", &X0[i], &Y0[i], &Z0[i], &X1[i], &Y1[i], &Z1[i]);
            X1[i] += X0[i];
            Y1[i] += Y0[i];
            Z1[i] += Z0[i];
            xs[nx++] = X0[i];
            xs[nx++] = X1[i];
            ys[ny++] = Y0[i];
            ys[ny++] = Y1[i];
            zs[nz++] = Z0[i];
            zs[nz++] = Z1[i];
        }
        discretize(xs, nx);
        discretize(ys, ny);
        discretize(zs, nz);

        // paint
        memset(color, 0, sizeof(color));
        for (int i = 0; i < n; i++) {
            int X1_idx = ID(xs, nx, X0[i]);
            int X2_idx = ID(xs, nx, X1[i]);
            int Y1_idx = ID(ys, ny, Y0[i]);
            int Y2_idx = ID(ys, ny, Y1[i]);
            int Z1_idx = ID(zs, nz, Z0[i]);
            int Z2_idx = ID(zs, nz, Z1[i]);
            for (int X = X1_idx; X < X2_idx; X++)
                for (int Y = Y1_idx; Y < Y2_idx; Y++)
                    for (int Z = Z1_idx; Z < Z2_idx; Z++) color[X][Y][Z] = 1;
        }

        int v, s;
        floodfill(v, s);
        printf("%d %d\n", s, v);
    }

    return 0;
}
