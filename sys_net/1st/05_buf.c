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
	char buf[10] = {};
	int ret;

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

	/*printf("buf : %s\n", buf);*/
	//按字符操作
	while(1)
	{
		ret = fread(buf, sizeof(char), sizeof(buf), fpr);
		if (ret <= 0)
		{
			/*printf("fread data false!\n");*/
			break;
		}

		fwrite(buf, sizeof(char), ret, fpw);
	}

	/*printf("count : %d\n", count);*/
	fclose(fpr);
	fclose(fpw);
	return 0;
}
