#include "run_program.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define ERROR_CODE 127

/*remove
int main(){
    char *argv1[] = {
        "/",
        NULL
    };
    int result1 = run_program("/bin/ls", argv1);

    char * argv2[] = {
        NULL
    };
    int result2 = run_program("/bin/false", argv2);

    (void)
}
*/

/*
 *Returns size of arrays that are terminated with NULL
 */
int getArraySize(char *array[]){
    int size = 0;
    while (*array != NULL)
    {
        size++;
        array++;
    }

    return size + 1;
    
}

int run_program(char *file_path, char *arguments[])
{
    int pid = fork();

    

    if(pid == 0){
        execvp(file_path, arguments);
        exit(-1);
    } else {

        int exitStatus;
        if(waitpid(pid, &exitStatus, 0) == -1){
            return ERROR_CODE;
        } else {
            return 0;
        }
    }
}
/*
void schmutz() {
    int argLength = getArraySize(arguments);
    
    //Argument array starting with the file path
    char *argsWithFilePath[argLength + 1];
    *argsWithFilePath[0] = *file_path;

    for (size_t i = 0; i < argLength; i++)
    {
        *argsWithFilePath[i + 1] = *arguments[i];
        printf("%s", *argsWithFilePath[i + 1]);
    }
    
    
}
*/


