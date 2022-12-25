#include <stdio.h>
#include <windows.h>
void  check_number();
char ch;
int er;
int main() {
    int n_str, str_size, arr, i, j;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do {
        er=0;
       printf("Enter how many symbol in string\n");
       scanf("%i%c", &str_size, &ch);
       check_number();
    } while (er);
    ch=0;

    do {
        er=0;
      printf("Enter how many string\n");
      scanf("%i%c", &n_str, &ch);
      check_number();
    } while (er);

    char list [n_str][str_size];
    char* addr[n_str];

    for(i=0;i<n_str;i++)
        addr [i] = (char*)malloc(sizeof(char));

    printf("Enter strings (max %d characters):\n", str_size);
    for ( i = 0; i < n_str; i++) {
        scanf("%s",list[i]);
        addr[i]=list[i];
    }
    fflush(stdin);

    do {
        er=0;
        printf("Enter 1 if arrange from greater to lesser\n"
           "Enter 0 if arrange from smaller to larger  \n");
        scanf("%d", &arr);
        if ((arr!=1)&&(arr!=0)) {
            er=1;
            while ((getchar()) != '\n');
            printf("Enter correct number\n");
        }
    } while (er);


    if(arr==0) {
        for (i = 0; i < n_str - 1; i++) {
            for (j = i + 1; j < n_str; j++) {
                if (strcmp(addr[i], addr[j]) > 0) {
                    char *tmp;
                    tmp = addr[i];
                    addr[i] = addr[j];
                    addr[j] = tmp;
                }
            }
        }
    } else {
        for (i = 0; i < n_str - 1; i++) {
            for (j = i + 1; j < n_str; j++) {
                if (strcmp(addr[i], addr[j]) < 0) {
                    char *tmp;
                    tmp = addr[i];
                    addr[i] = addr[j];
                    addr[j] = tmp;
                }
            }
        }
    }

    for (i = 0; i < n_str; i++) {
        for( j=0;j<str_size;j++) {
                printf("%c", addr[i][j]);
            }
        printf("\n");
    }


    free(*addr);

    return 0;
}

void check_number()  { //checking for characters
    if (ch != '\n') {
        er = 1;
        while ((getchar()) != '\n');
        printf("Enter number without symbol\n");
    }
}
