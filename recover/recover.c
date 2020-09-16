#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define BFR_SIZE 512
int main(int argc, char *argv[])
{
        if (argc < 2) 
        {
                printf("Usage: recover <image_path>\n");
                exit(1);
        }
        FILE *img = fopen(argv[1], "r");
        if (img == NULL)
        {
                perror("Error: ");
                exit(2);
        }
        FILE *tmp = NULL;
        char filename[8];
        uint8_t buf[512];
        int num = 1;
        while (!feof(img))
        {
                fread(&buf, sizeof(uint8_t), BFR_SIZE, img);
                if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xe0) == 0xe0)
                {
                        if (tmp != NULL) fclose(tmp);
                        sprintf(filename, "%03d.jpg", num++);
                        tmp = fopen(filename, "w");
                }
                if (tmp != NULL) fwrite(&buf, BFR_SIZE, 1, tmp);
        }
        fclose(tmp);
        fclose(img);
        return 0;
}
