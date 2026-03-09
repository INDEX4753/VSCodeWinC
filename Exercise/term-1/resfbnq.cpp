//-------------------------------------------
//	简单递归实现斐波那契数列的输出
//	作者：ABYSSOvO
//-------------------------------------------
#include <iostream>
#include <cstdlib>
//-------------------------------------------
int fbnq(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}
	return fbnq(n - 1) + fbnq(n - 2);
}
//-------------------------------------------
int main() {
	int n = 1;
	std::cin >> n;
	std::cout << fbnq(n) << "\n" << std::endl;
	system("pause");
}