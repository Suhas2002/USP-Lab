//1. Program to demonstrate the creation of hard links and the various properties of hard links


#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
        int main(int argc, char*argv[]){
        if(argc==3){
                printf("Hard linking %s and %s",argv[1],argv[2]);
                if(link(argv[1],argv[2])==0){
                        printf("\nHard link created\n");
                        system("ls -li");
                }
                else
                        printf("\nLink not created\n");
        }
        else if(argc==4){
                printf("Soft linking %s and %s",argv[2],argv[3]);
                if(symlink(argv[2],argv[3])==0){
                        printf("\nSoft link created\n");
                        system("ls -li");
                }
                else
                        printf("\nLink not created\n");
        }
}


// Output

// gcc p1hardlink.c -o hardlink

// //file f1 created
// cat > f1
// helooo
// geooo
// ^C

// //f5 and f2 doesn't exist
// ./hardlink f1 f5
// Hard linking f1 and f5
// Hard link created
// total 44
// 141690954 -rw-rw-r-- 3 cs6c27 cs6c27   13 Mar 21 15:21 f1
// 141690954 -rw-rw-r-- 3 cs6c27 cs6c27   13 Mar 21 15:21 f5
// 141690921 -rwxrwxr-x 1 cs6c27 cs6c27 7304 Mar 21 15:23 hardlink
// 141689494 -rw-rw-r-- 1 cs6c27 cs6c27  589 Mar 21 15:23 p1hardlink.c

// ./hardlink -s f1 f2
// Soft linking f1 and f2
// Soft link created
// total 56
// 141690954 -rw-rw-r-- 3 cs6c27 cs6c27   13 Mar 21 15:21 f1
// 141690960 lrwxrwxrwx 1 cs6c27 cs6c27    2 Mar 21 15:54 f2 -> f1
// 141690921 -rwxrwxr-x 1 cs6c27 cs6c27 7304 Mar 21 15:23 hardlink
// 141689494 -rw-rw-r-- 1 cs6c27 cs6c27  589 Mar 21 15:23 p1hardlink.c