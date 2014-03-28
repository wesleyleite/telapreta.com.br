#include <stdio.h>
#include <regex.h>
#include <string.h>

#define MAX_MAT 4
#define BUFF 100

void main()
{
    char *res;
    char String[BUFF];
    char buff_output[BUFF];
    regex_t reg;
    regmatch_t matches[MAX_MAT];
    FILE *fd;
    int rv;
    int i;

    fd = fopen("T2.txt", "r");
    rv = regcomp(&reg, "[ctag ]{6,}", REG_EXTENDED|REG_ICASE);

    while (!feof(fd)) {
        res = fgets(String, 100, fd);
        if (res != NULL) {
            if( regexec(&reg, res, MAX_MAT, matches, 0 ) == 0 ) {
               // strncpy(buff_output,res + matches[0].rm_so , matches[0].rm_eo - matches[0].rm_so);
                strncpy(buff_output,res + matches[0].rm_so , matches[0].rm_eo ); // - matches[0].rm_so);
                buff_output[matches[0].rm_eo - matches[0].rm_so] = '\n';
                //printf("=== %d  %d ==== %s", matches[0].rm_so, matches[0].rm_eo, res);
                for ( i = matches[0].rm_so ; i< matches[0].rm_eo ; i++) {
                    printf("%c",res[i]);
                }
                printf("\n");

                bzero(buff_output, BUFF);
                bzero(res,BUFF);
                bzero(String,BUFF);
            }
        }
    }
    regfree(&reg);
}

