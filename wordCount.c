#include <stdio.h>
#include <string.h>

//定义常量 
#define MAX_BUF_LEN 5000 //读取字符数量上限 

// 函数声明
int countChars(FILE *fp); //统计字符数 
int countWords(FILE *fp); // 统计单词数 

int main(int argc, char** argv) {
	
    char *filename;  //读取文件名 
    char *parameter;  //读取操作指令 
    FILE *fp;  //文件操作指针 
    
    int count = 0; //计数 

    if (argc == 3) {
    	//argv[0] 是 exeName.exe 
        parameter = argv[1];       
        filename = argv[2]; 
    } else {
    	printf(stderr, "PS(输入不符合格式要求):\nexeName.exe [-c|-w] [input_file_name]\n", argv[0]);
        exit(1);    
    }

    if ((fp = fopen(filename, "r")) == NULL) {	
        fprintf(stderr, "Cannot open file %s\n", filename);
        exit(1);
    }

    if (strcmp(parameter, "-c") == 0) {	
        count = countChars(fp);
		printf("字符数：%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {	
        count = countWords(fp);
        printf("单词数：%d\n", count);   
    } else {    	
    	fprintf(stderr, "无效指令 %s\n", parameter);
        exit(1);       
    }
    
    fclose(fp);
    return 0;
}

// 统计字符
int countChars(FILE *fp) {
	
    int count = 0;
    char buff[MAX_BUF_LEN];

    while (fgets(buff, MAX_BUF_LEN, fp) != NULL) {
    	
        count += strlen(buff);
        
    }

    return count;
}

// 统计单词
int countWords(FILE *fp) {
	
    int count = 0;
	int flag = 0;
	char ch;
	
	while ((ch = fgetc(fp)) != EOF) {
		if (ch ==' ' || ch == ',' || ch == '.') {	
		    flag = 0;		    
		} else {
			
		    if (!flag) { 	
		        flag = 1;
		        count++;   
		    }
		   
		}
	}	
	return count;
}

