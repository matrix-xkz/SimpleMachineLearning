#include <stdio.h>
#include <math.h>

int count_digits(int n) {
    if (n == 0) return 1;   // 特殊处理：0 是 1 位数

    int count = 0;
    while (n != 0) {
        n = n / 10;   // 每次去掉最后一位
        count++;
    }
    return count;
}

int get_max_length( int *matrix , int length )
{ //length的数值取任意正整数
    int i = 0 ;
    int max = matrix[0];
    while (i < length){
        if (matrix[i] > max) {
            max = matrix[i];
        }
        i++;
    }
    int len = count_digits(max);
    return len;
}

int matrix2_output( int *matrix , int x , int y ) 
{//定义matrix为输入的矩阵指针，x为该矩阵横向的长度，y为该矩阵纵向的长度，函数先检查列后检查行，x和y的取值均从1开始
        int i = 0 ; //定义i为横向扫描的坐标，j为纵向扫描的坐标
    int j = 0 ;
    while(j < y){
        i = 0 ;
        while(i < x){
            printf("%d ", matrix[i + j * x]);
            int t = 0; //尝试补齐空格
            while( t < get_max_length( matrix , x * y ) - count_digits( matrix[i + j * x] ) ){
                printf(" ");
                t++;
            }
            i++;
        }
        printf("\n");
        j++;
    }
    return 0;
}

int main()
{
    int matrix[3][4] = {
        {1,2,3,4},
        {5,1000,7,8},
        {9,10,11,12}
    };
    matrix2_output( (int *)matrix , 4 , 3);
    return 0;
}

