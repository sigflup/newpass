#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *fp;
int n = 0;

unsigned char get_rand(void) {
 unsigned char ret;
 fread(&ret, sizeof(unsigned char), 1, fp);
 return ret;
}

void usage(void) {
 printf("usage:\n"
	"\tnewpass [-l length][-n]\n"
	"\t\t-n disables new-line\n");
 exit(0); 
}

int main(int argc, char *argv[]) {
 int i, opt;
 int l = 12;

 while((opt = getopt(argc, argv, "nhl:")) != -1) {
  switch(opt) {
   case 'h':
    usage();
    break;
   case 'l':
    l = atoi(optarg);
    break;
   case 'n':
    n = 1;
    break;
   default:
    usage();
    break;
  }
 }

 if(!(fp=fopen("/dev/random", "rb"))) {
  perror("/dev/random");
  exit(0);
 }

 for(i=0;i<l;i++)
  putchar(33+(get_rand()%95));

 if(n==0) putchar('\n');
 fclose(fp);
}	
