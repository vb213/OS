#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define ERROR_CODE 1


int run_program(char *file_path, char *arguments[])
{
    int pid = fork();

    

    if(pid == 0){
        execvp(file_path, arguments);
        exit(7);
    } else {

        int exitStatus;
        int wait_pid = waitpid(pid, &exitStatus, 0);
        printf("Exitstatus = %d; Wait_Pid %d\n", exitStatus, wait_pid);
        if(exitStatus == 0){
            printf("success\n");
            return 0;
        } else {
            printf("failure\n");
            return ERROR_CODE;
        }
    }
}



