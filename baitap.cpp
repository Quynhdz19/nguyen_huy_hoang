#include <iostream>
using namespace std;

static int grid[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int d, N;
        cin >> d >> N;

        // Reset grid
        for (int i = 0; i <= 1024; i++)
            for (int j = 0; j <= 1024; j++)
                grid[i][j] = 0;

        // Nhập các tổ chuột
        vector<tuple<int,int,int>> nests(N);
        for (int i = 0; i < N; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            nests[i] = {x, y, z};
        }

        // Cộng ảnh hưởng vào từng vị trí đặt bom
        for (auto &t : nests) {
            int x, y, z;
            tie(x, y, z) = t;

            int minx = max(0, x - d);
            int maxx = min(1024, x + d);
            int miny = max(0, y - d);
            int maxy = min(1024, y + d);

            for (int px = minx; px <= maxx; px++)
                for (int py = miny; py <= maxy; py++)
                    grid[px][py] += z;
        }

        // Tìm vị trí tốt nhất
        int best = -1;
        int bx = 0, by = 0;

        for (int i = 0; i <= 1024; i++) {
            for (int j = 0; j <= 1024; j++) {
                int val = grid[i][j];
                if (val > best || (val == best && (i < bx || (i == bx && j < by)))) {
                    best = val;
                    bx = i;
                    by = j;
                }
            }
        }

        cout << bx << " " << by << " " << best << "\n";
    }

    return 0;
}