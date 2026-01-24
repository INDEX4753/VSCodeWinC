/**
 * @file number_decomposition.cpp
 * @brief 求解将整数n分解为k个非递减正整数之和的所有组合
 *
 * 程序通过深度优先搜索(DFS)算法，找出所有满足条件的组合：
 * 1. 组合包含k个正整数
 * 2. 这k个正整数之和等于n
 * 3. 组合中的数字按非递减顺序排列（每个数不小于前一个数）
 *
 * 若不存在满足条件的组合或输入不合法（n < k），则输出"Invalid"
 */

#include <cstdio>   ///< 包含标准输入输出函数，如scanf_s、printf
#include <vector>   ///< 包含vector容器，用于存储中间结果和最终解
#define _CRT_SECURE_NO_WARNINGS  ///< 禁用VS编译器的安全函数警告（如scanf_s替代scanf）
using namespace std;  ///< 使用标准命名空间，简化代码编写

/**
 * @var int n
 * @brief 待分解的目标整数（所有数的总和）
 */
int n,
/**
 * @var int k
 * @brief 分解后的正整数个数
 */
    k;

/**
 * @var vector<vector<int>> solutions
 * @brief 存储所有满足条件的分解组合
 * 外层vector的每个元素是一个内层vector，内层vector表示一个分解组合（含k个元素）
 */
vector<vector<int>> solutions;

/**
 * @var vector<int> current
 * @brief 存储当前正在构建的分解组合（DFS过程中的临时结果）
 */
vector<int> current;

/**
 * @brief 深度优先搜索函数，用于递归构建分解组合
 *
 * 递归地选择每个位置的数字，确保组合满足非递减、总和为n、长度为k的条件
 *
 * @param remaining 剩余需要分配的数值（当前已选数字之和与n的差值）
 * @param count 当前已选择的数字个数
 * @param start 下一个数字的最小取值（确保非递减，即不小于上一个选择的数字）
 */
void dfs(int remaining, int count, int start) {
    // 递归终止条件：已选择k个数字
    if (count == k) {
        // 若剩余数值为0，说明当前组合总和为n，是有效解
        if (remaining == 0) {
            solutions.push_back(current);  ///< 将当前有效组合存入解集合
        }
        return;  ///< 结束当前递归分支
    }

    // 计算当前位置数字的最小取值：不小于start（保证非递减）
    int min_val = start;
    // 计算当前位置数字的最大取值：
    // 剩余的(k - count - 1)个数字至少取当前值（非递减），因此当前数字最大为remaining减去剩余位置的最小和
    int max_val = remaining - (k - count - 1);

    // 遍历当前位置可能的取值（从min_val到max_val）
    for (int i = min_val; i <= max_val; i++) {
        // 若当前数字已超过剩余数值，后续无法分配，提前退出循环
        if (i > remaining) break;

        current.push_back(i);  ///< 将当前数字加入临时组合
        // 递归处理下一个位置：剩余数值减少i，已选个数+1，下一个数字最小为当前i（保证非递减）
        dfs(remaining - i, count + 1, i);
        current.pop_back();  ///< 回溯：移除当前数字，尝试下一个可能值
    }
}

/**
 * @brief 主函数，处理输入、调用搜索函数并输出结果
 *
 * @return int 程序执行状态（0表示正常结束）
 */
int main() {
    scanf_s("%d %d", &n, &k);  ///< 读取输入的n（目标和）和k（数字个数）

    // 若n < k，不可能分解为k个正整数之和（最小和为1*k = k），直接输出Invalid
    if (n < k) {
        printf("Invalid\n");
        return 0;  ///< 提前结束程序
    }

    // 调用DFS开始搜索：初始剩余值为n，已选0个数字，第一个数字最小为1
    dfs(n, 0, 1);

    // 若解集合为空，说明没有满足条件的组合
    if (solutions.empty()) {
        printf("Invalid\n");
    }
    else {
        // 遍历所有解，按格式输出每个组合
        for (const auto& sol : solutions) {  ///< 遍历每个分解组合
            for (int i = 0; i < k; i++) {    ///< 遍历组合中的每个数字
                printf("%d", sol[i]);        ///< 输出当前数字
                if (i < k - 1) printf(" ");  ///< 数字间用空格分隔（最后一个数字后无空格）
            }
            printf("\n");  ///< 每个组合输出后换行
        }
    }

    return 0;  ///< 程序正常结束
}