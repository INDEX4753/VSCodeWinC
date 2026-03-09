#include <stdio.h>

int main(){
    int n, T, W;
    scanf("%d %d %d", &n, &T, &W);

    long long total = 0;
    long long used_space = 0;
    for (int i = 0; i < n; i++){
        int t, w, v;
        scanf("%d %d %d", &t, &w, &v);

        int all_containers = 1 + t / T;

        long long all_space = all_containers * W;

        long long left_space = all_space - used_space ;

        long long load = (w < left_space) ? w : left_space;//使用三元运算符简化判断

        used_space += load;

        total += load * v;
    }

    printf("%lld\n",total);

    return 0;
    
}