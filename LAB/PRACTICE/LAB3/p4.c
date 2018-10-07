/*
google OSTEP > chapter 5 > page 7 >
exec family of system call
    .execl
    .execp
    .execv
    .execvp

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();

    if (rc < 0) {          // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
} else if (rc == 0) { // child: redirect standard output to a file
    //close(STDOUT_FILENO);
    //open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

// now exec "wc"...

char *myargs[3];
myargs[0] = strdup("wc");   // program: "wc" (word count)
myargs[1] = strdup("destination.txt"); // argument: file to count
myargs[2] = strdup("p4.c"); 
myargs[3] = NULL;           // marks end of array
execvp(myargs[0], myargs);  // runs word count
} else {              // parent goes down this path (main)
    int rc_wait = wait(NULL);
}

return 0;
}
