#include <stdio.h>
#include <regex.h>
#include <string.h>

void main()
{
   char T1[100] = "Meu nome é Wesley Leite moro na Rua: ABCDEFGHIJ KLMNOPQR 3311, CEP: 19283-983 e Gosto de pêra";
   char buffer[100];
   regex_t reg;
   regmatch_t match;
   regcomp(&reg,"Rua:.+([0-9]){5}.([0-9]){3}",REG_EXTENDED);
   regexec(&reg,T1,1,&match,0);
   strncpy(buffer,T1 + match.rm_so, match.rm_eo - match.rm_so);
   buffer[match.rm_eo - match.rm_so] = 0x00;
   printf("%s\n",buffer);
   regfree(&reg);
}

