//------------------------------------------
#include <stdio.h>
//------------------------------------------
int checkLine(int checkl[]);
//------------------------------------------
int main() {
	int a[9][9] = { 0 };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int check = 1;

	for (int i = 0; i < 9; i++) {
		int checkl[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			checkl[j] = a[i][j];

		}
		if (!checkLine(checkl)) {
			check = 0;
		}
	}

	for (int i = 0; i < 9; i++) {
		int checkl[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			checkl[j] = a[j][i];
		}
		if (!checkLine(checkl)) {
			check = 0;
		}
	}

	for (int i = 0; i < 9; i = i + 3) {
		for (int j = 0; j < 9; j = j + 3) {
			int checkl[9] = { 0 };
            int idx = 0;
			for (int m = i; m < i + 3; m++) {
				for (int n = j; n < j + 3; n++) {					
						checkl[idx] = a[m][n];
                        idx++;
				}
			}
			if (!checkLine(checkl)) {
				check = 0;
			}
		}
	}

    printf("%s", check ? "YES" : "NO");

}
//----------------------------------------------------
int checkLine(int checkl[]) {
	/*
	for (int i = 0; i < 9; i++) {
        if (checkl[i] < 1 || checkl[i] > 9) {
            return 0;
        }
    }
	*/
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (checkl[i] == checkl[j]) {
				return 0;
			}
		}
	}
	return 1;
}