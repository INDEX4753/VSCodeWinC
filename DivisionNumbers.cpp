#include <cstdio>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int n, k;
vector<vector<int>> solutions;
vector<int> current;

void dfs(int remaining, int count, int start) {
    if (count == k) {
        if (remaining == 0) {
            solutions.push_back(current);
        }
        return;
    }

    int min_val = start;
    int max_val = remaining - (k - count - 1);

    for (int i = min_val; i <= max_val; i++) {
        if (i > remaining) break;

        current.push_back(i);
        dfs(remaining - i, count + 1, i);
        current.pop_back();
    }
}

int main() {
    scanf_s("%d %d", &n, &k);

    if (n < k) {
        printf("Invalid\n");
        return 0;
    }

    dfs(n, 0, 1);

    if (solutions.empty()) {
        printf("Invalid\n");
    }
    else {
        for (const auto& sol : solutions) {
            for (int i = 0; i < k; i++) {
                printf("%d", sol[i]);
                if (i < k - 1) printf(" ");
            }
            printf("\n");
        }
    }
}