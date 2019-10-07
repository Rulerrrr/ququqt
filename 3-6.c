#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main(char **args)
{

    FILE *file;
    char buffer[1000];
    char *hello = "%%beg%%#include <stdio.h> int main(){printf(\"Hello, world!\");return 0; }%%end%%";

    if( (file = fopen("./3-4.txt", "rt+")) == NULL )
    {
		perror("open file failed");
        return 0;
    }

    if( fseek(file, 10, SEEK_SET) != 0 )
    {
		perror("fseek failed");
        return 0;
    }

    fwrite(hello, sizeof(char)*strlen(hello), 1, file);
    fclose(file);

    if( (file = fopen("./3-4.txt", "rt+")) == NULL )
    {
		perror("open file failed");
        return 0;
    }

    if( fseek(file, 10, SEEK_SET) != 0 )
    {
		perror("fseek failed");
        return 0;
    }

    if( fread(buffer, sizeof(char)*strlen(hello), 1, file) <= 0 )
    {
        perror("fread failed\n");
        return 0;
    }
    printf("%s", buffer);
    fclose(file);

    return 0;
}