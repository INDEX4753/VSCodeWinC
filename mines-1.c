#include<stdio.h>
#define MAX_LEN 101
int main() {
	int org_map[MAX_LEN][MAX_LEN] = { 0 };
	int copy_map[MAX_LEN][MAX_LEN] = { 0 };

	int n = 1;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char ch = 'o';
			scanf(" %c", &ch);
			switch(ch) {
				case 'o': org_map[i][j] = 'o'; break;
				case '*': org_map[i][j] = '*'; break;
                default: break;
			}
		}
	}

	int vectors[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0},{1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (org_map[i][j] == 'o'){
				int count = 0;
				for (int k = 0; k < 8; ++k) {
					int newI = i + vectors[k][0];
					int newJ = j + vectors[k][1];
					if (org_map[newI][newJ] == '*') {
						count++;
					}
				}
				copy_map[i][j] = count;
			}
			else
				copy_map[i][j] = '*';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (copy_map[i][j] == '*') {
				printf("*");
			}
			else
				printf("%d", copy_map[i][j]);
		}
		printf("\n");
	}

}