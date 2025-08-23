#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// 获取next数组
int* GetNextArray(char* partern){
    int i = 1;
    int j = 0;
    int length = strlen(partern);
    int* next = (int*)malloc(sizeof(int)*length);
    next[0] = 0;
    while (i < length){
        if(j == 0 || partern[i] == partern[j]){
            if(partern[i] == partern[j]){
                j++;
            }
            next[i] = j;
            i++;
        }else{
            j = next[j - 1];
        }
    }
    return next;
}

// KMP字符串匹配算法
int KMP(char* string, char* partern){
    int* next = GetNextArray(partern);
    int i = 0;
    int j = 0;
    int str_length = strlen(string);
    int par_length = strlen(partern);
    while(i < str_length && j < par_length){
        if(j == 0 || string[i] == partern[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j == par_length){
        return i - par_length;
    }else{
        return -1;
    }
   
}
