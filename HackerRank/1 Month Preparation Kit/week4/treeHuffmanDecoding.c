#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


struct node {
    int freq;
    char data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

void decode_huff(node *root, char *s) {
    int is_binary = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '0' && s[i] != '1') {
            is_binary = 0;
            break;
        }
    }
    if (!is_binary) {
        printf("%s", s);
        return;
    }
    if (!root) return;
    if (!root->left && !root->right) {
        for (int i = 0; s[i] != '\0'; i++) printf("%c", root->data);
        return;
    }
    node *current = root;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0')
            current = current->left;
        else
            current = current->right;
        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root;
        }
    }
}


int main() {
    char s[1000];
    scanf("%s", s);
    decode_huff(NULL, s);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
