#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "main.c"

static char *read_file(char *file_name)
{
  FILE *fp;
  char *content = NULL;
  int fsize = 0;

  fp = fopen(file_name, "r+");
  if (fp)
  {
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    printf("fsize: %d\n", fsize);
    rewind(fp);

    content = (char *)malloc(sizeof(char) * (fsize + 1));
    fread(content, fsize, 1, fp);
    content[fsize] = '\0';
    fclose(fp);
  }
  return content;
}

int main(int argc, char **argv)
{
  char *content = NULL;

  printf("file_name: %s\n", FILE_NAME);
  content = read_file(FILE_NAME);

  printf("content: \n%s", content);

  free(content);
  content = NULL;

  return 0;
}
