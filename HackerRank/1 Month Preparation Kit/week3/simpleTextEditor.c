#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 1000000



typedef struct {
    char *text;
} State;

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int Q;
    scanf("%d", &Q);

    char S[MAX_LEN + 1] = "";
    State stack[Q];
    int top = -1;

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char W[MAX_LEN + 1];
            scanf("%s", W);
            stack[++top].text = strdup(S);
            strcat(S, W);
        } 
        else if (type == 2) {
            int k;
            scanf("%d", &k);
            stack[++top].text = strdup(S);
            int len = strlen(S);
            S[len - k] = '\0';
        } 
        else if (type == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        } 
        else if (type == 4) {
            if (top >= 0) {
                strcpy(S, stack[top].text);
                free(stack[top].text);
                top--;
            }
        }
    }

    while (top >= 0) {
        free(stack[top].text);
        top--;
    }

    return 0;
}
