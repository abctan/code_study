#include <stdio.h>
#include <string.h>


//cp 拷贝 format cp srcfilename destfilename
//  srcfilename  => argv[1] => r => fgetc fgets fread
//  destfilename => argv[2] => w => fputc fputs fwrite
int main(int argc, char *argv[])
{
	char ch;
	FILE *fpr = NULL;//argv[1]
	FILE *fpw = NULL;//argv[2]
	int count = 0;

	//打开源文件
	fpr = fopen(argv[1], "r");
	if (fpr == NULL)
	{
		perror("fopen read");
		return -1;
	}

	//打开目标文件 w
	fpw = fopen(argv[2], "w");
	if (fpw == NULL)
	{
		perror("fopen write");
		fclose(fpr);
		return -1;
	}

	//按字符操作
	while(1)
	{
		ch = fgetc(fpr);
		if (ch == EOF)
		{
			break;
		}
		/*count++;*/
		/*putchar(ch);*/
		if (fputc(ch, fpw) == EOF)
			break;
	}

	/*printf("count : %d\n", count);*/
	fclose(fpr);
	fclose(fpw);
	return 0;
}
