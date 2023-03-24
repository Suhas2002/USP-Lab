// 3. Write a program to implement ls –li command which list the files in a specified directory.
// Your program should Print 5 attributes of files.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>

int main(int argc, char* argv[]){
		struct dirent *dir;
    struct stat mystat;
    DIR *dp;
    dp = opendir(".");
    if(dp){
		    while(dir = readdir(dp)){
        stat(dir->d_name,&mystat); //inode mode uid guid access_time
        printf("%ld %o %d %d %s %s\n",mystat.st_ino,mystat.st_mode,mystat.st_uid,mystat.st_gid,ctime(&mystat.st_atime),dir->d_name);
        }
    }
}


// ./printattributes 
// 141690901 40775 2852 2852 Tue Mar 21 16:05:01 2023
//  .
// 139724638 40775 2852 2852 Tue Mar 21 15:04:39 2023
//  ..
// 141690921 100775 2852 2852 Tue Mar 21 15:23:50 2023
//  hardlink
// 141690954 100664 2852 2852 Tue Mar 21 15:21:36 2023
//  f1
// 141690989 100664 2852 2852 Tue Mar 21 16:01:31 2023
//  p3fileattri.c
// 141690954 100664 2852 2852 Tue Mar 21 15:21:36 2023
//  fs1
// 141690973 100664 2852 2852 Tue Mar 21 15:32:31 2023
//  p1hardlink.c
// 141689494 100775 2852 2852 Tue Mar 21 16:05:06 2023
//  printattributes
// 41690954 100664 2852 2852 Tue Mar 21 15:21:36 2023
//  f5
// 141690932 100775 2852 2852 Tue Mar 21 16:01:38 2023
//  a.out
// 141690981 100664 2852 2852 Tue Mar 21 15:35:54 2023
//  testargc.c