#include <stdio.h>

int main (void) {
    int t, h, w, n, i, count_h=0, count_w=1;
    
    scanf("%d", &t);
    
    for(i=0;i<t;i++){
        scanf("%d %d %d", &h, &w, &n);
        
        for(int j=0;j<n;j++){
            count_h++;
            if(count_h==h+1){
                count_h=1;
                count_w++;
            }
        }
        
        
        if(count_w<10){
            printf("%d0%d\n", count_h, count_w);
            count_h=0;
            count_w=1;
        } else {
            printf("%d%d\n", count_h, count_w);
            count_h=0;
            count_w=1;
        }
    }
    return 0;
}