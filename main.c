#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *fp;

unsigned char get_rand(void) {
 unsigned char ret;
 fread(&ret, sizeof(unsigned char), 1, fp);
 return ret;
}

void usage(void) {
 printf("usage:\n"
	"\tnewpass [-l length]\n");
 exit(0); 
}

int main(int argc, char *argv[]) {
 int i, opt;
 int l = 12;

 while((opt = getopt(argc, argv, "hl:")) != -1) {
  switch(opt) {
   case 'h':
    usage();
    break;
   case 'l':
    l = atoi(optarg);
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
  putchar(32+(get_rand()%96));

 fclose(fp);
}	
