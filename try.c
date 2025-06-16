#include <stdio.h>
#include <stdlib.h>
int x = 5;
int *p = &x;

int change(int a){
    a = 50;
    return a;
}
void change2(int *a){
    *a = 50;
}
int main(){
    printf("%d\n",*p);
    printf("%d\n",x);
    printf("%d\n",p);

    int a = change(x);
    printf("%d\n",a);

    printf("%d\n",x);
    change2(&x);
    printf("%d\n",x);
    return 0;
}

