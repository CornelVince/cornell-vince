#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf ("Please enter file to open\n");
        return 1;
    }
    FILE*file = fopen(argv[1],"r");
    if(file == NULL)
    {
        printf("not a file\n");
    }
    int filecount = 0;
    int jpg_found = 0;
    unsigned char buffer[512];
    FILE*img = NULL;
    char filename[8];
    while (fread(buffer, 512,1, file) == 0)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg_found == 1)
            {
                fclose(img);
            }
            else
            {
                jpg_found = 1;
            }
            sprintf(filename,"%03i.jpg", filecount);
            img = fopen(filename, "w");
            filecount++;
        }
        if (jpg_found == 1)
        {
            fwrite(&buffer, 512, 1, img);
        }
    }
    fclose(file);
    fclose(img);
    return 0;
}
