#include <stdio.h>
#include <string.h>

//���峣�� 
#define MAX_BUF_LEN 5000 //��ȡ�ַ��������� 

// ��������
int countChars(FILE *fp); //ͳ���ַ��� 
int countWords(FILE *fp); // ͳ�Ƶ����� 

int main(int argc, char** argv) {
	
    char *filename;  //��ȡ�ļ��� 
    char *parameter;  //��ȡ����ָ�� 
    FILE *fp;  //�ļ�����ָ�� 
    
    int count = 0; //���� 

    if (argc == 3) {
    	//argv[0] �� exeName.exe 
        parameter = argv[1];       
        filename = argv[2]; 
    } else {
    	printf(stderr, "PS(���벻���ϸ�ʽҪ��):\nexeName.exe [-c|-w] [input_file_name]\n", argv[0]);
        exit(1);    
    }

    if ((fp = fopen(filename, "r")) == NULL) {	
        fprintf(stderr, "Cannot open file %s\n", filename);
        exit(1);
    }

    if (strcmp(parameter, "-c") == 0) {	
        count = countChars(fp);
		printf("�ַ�����%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {	
        count = countWords(fp);
        printf("��������%d\n", count);   
    } else {    	
    	fprintf(stderr, "��Чָ�� %s\n", parameter);
        exit(1);       
    }
    
    fclose(fp);
    return 0;
}

// ͳ���ַ�
int countChars(FILE *fp) {
	
    int count = 0;
    char buff[MAX_BUF_LEN];

    while (fgets(buff, MAX_BUF_LEN, fp) != NULL) {
    	
        count += strlen(buff);
        
    }

    return count;
}

// ͳ�Ƶ���
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

