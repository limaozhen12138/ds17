#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct UnionSet{
    int *color;
    int n;
}UnionSet;

UnionSet *init(int n){
    UnionSet *u = (UnionSet *) malloc(sizeof (UnionSet));
    u -> color = (int *) malloc(sizeof (int ) * (n + 1 ));
    u -> n = n ;
    for (int i = 0; i <= n; ++i) {
        u -> color[i] = i;
    }
    return u;
}


void clear(UnionSet *u){
    if(u == NULL) return;
    free(u -> color);
    free(u);
    return;

}

int find(UnionSet *u, int n){
    return u -> color[n];
}

int merge(UnionSet *u, int a, int b){
    if(find(u, b) == find(u, b))return 0;
    int color_a = u -> color[a];
    for (int i = 1; i <= u -> n ; ++i) {
        if(u -> color[i] - color_a)continue;
        u -> color[i] = u -> color[b];
    }
    return 1;

}

int main() {
   int n, m;
    scanf("%d %d\n",&n, &m);
    UnionSet  *u = init(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d\n", &a, &b, &c);
        switch (a) {
            case 1:
                merge(u , b, c);
                break;
            case 2:{
                printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No");
            }break;
        }
    }
    return 0;
}
