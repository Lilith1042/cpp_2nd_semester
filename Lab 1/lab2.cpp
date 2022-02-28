#include <chrono>
#include <iostream>
#include <random>

const int n = 5;
const int m = 5;
std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

int num = 3; // number of initial dislocations

void matrix(int a[n][m]) {
    int done = 0;
    while (done != num) {
        std::uniform_int_distribution<int> distn(0, n - 1);
        std::uniform_int_distribution<int> distm(0, m - 1);
        int x = distn(rng);
        int y = distm(rng);
        if (a[x][y] == 0) {
            a[x][y] = 1;
            ++done;
        }
    }
}

void move(int a[n][m]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) {
                continue;
            }
            if (j == 0 || j == m - 1) {
                continue;
            }
            if (n != 1) {
                if (i == 0 || i == n - 1) {
                    continue;
                }
            }
            if (n != 1) {
                if (a[i + 1][j] == 1 || a[i - 1][j] == 1)
                    continue;
            }
            if (a[i][j + 1] == 1 || a[i][j - 1] == 1)
                continue;
            a[i][j] = 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 2) {
                std::uniform_int_distribution<int> dist(0, 3);
                std::uniform_int_distribution<int> dist_1(0, 1);
                if (n != 1) {
                    int random = dist(rng);
                    if (random == 0 && a[i + 1][j] == 0) {
                        a[i][j] = 0;
                        a[i + 1][j] = 1;
                    }
                    if (random == 1 && a[i - 1][j] == 0) {
                        a[i][j] = 0;
                        a[i - 1][j] = 1;
                    }
                    if (random == 2 && a[i][j + 1] == 0) {
                        a[i][j] = 0;
                        a[i][j + 1] = 1;
                    }
                    if (random == 3 && a[i][j - 1] == 0) {
                        a[i][j] = 0;
                        a[i][j - 1] = 1;
                    }
                } else {
                    int random = dist_1(rng);
                    if (random == 0 && a[i][j + 1] == 0) {
                        a[i][j] = 0;
                        a[i][j + 1] = 1;
                    }
                    if (random == 1 && a[i][j - 1] == 0) {
                        a[i][j] = 0;
                        a[i][j - 1] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 2)
                a[i][j] = 1;
        }
    }
}


int main() {
    int steps = 0;
    int coincidence = 0;
    int a[n][m] = {};
    int b[n][m] = {};
    matrix(a);
    bool allDead = false;
    while (!allDead) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                b[i][j] = a[i][j];
                std::cout << a[i][j] << " ";
            }
            std::cout << std::endl;
        }
        move(a);
        std::cout << std::endl;
        allDead = true;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] != b[i][j])
                    allDead = false;
        if (!allDead)
            ++steps;
    }
    std::cout << "steps = "<< steps << " ";
}