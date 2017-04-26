#include <stdio.h>
#include <string.h>

#define STRLEN 1000

int main (int argc)
{
FILE *fp;
FILE *fo;
char str[STRLEN];
char *cc;

if (argc!=2)
	{
	printf("usage cms gen\n");
	return 2;
	}

fp=fopen("text.txt","r");
if (fp==NULL) {printf("can't open text\n"); return 3;}

fo=fopen("body","w");
if (fp==NULL) {printf("can't open body\n"); return 3;}

while(!feof(fp))
    {
    str[0]=0;
    fgets(str,STRLEN,fp);
    cc=strchr(str,'\n'); if (cc) *cc=0;
    cc=strchr(str,'\r'); if (cc) *cc=0;
    if (str[0]==']')
	{
	if (!memcmp(str,"]title",strlen("]title"))) {fprintf(fo,"<h1>%s</h1>\n",str+strlen("]title"));}
	else if (!memcmp(str,"]date",strlen("]date"))) {fprintf(fo,"<p>Дата %s</p>\n",str+strlen("]date"));}
	else if (!memcmp(str,"]end",strlen("]end"))) {fprintf(fo,"<hr>\n");}
	}
    else
	{
	fprintf(fo,"%s\n",str);
	}
    }
fclose(fp);
fclose(fo);
}
