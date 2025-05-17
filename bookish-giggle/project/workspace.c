#include<stdio.h>
#include<stdlib.h>
// #include<wchar.h>
// #include<locale.h>
// int main(){
    // setlocale(LC_CTYPE,"");
    // wchar_t ch=L'\u2659';
    // wprintf(L"%lc\n",ch);
// }

void main(){
    // char mat[8][8];
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         if(i==1||i==6)
    //         mat[i][j]='p';
    //         else
    //         mat[i][j]=' ';
    //     }
    //     printf("\n");
    //     // printf("\n♔");
    // }
    // mat[0][0]='R';//white pieces.
	// mat[0][1]='N';
	// mat[0][2]='B';
	// mat[0][3]='Q';
	// mat[0][4]='K';
	// mat[0][5]='B';
	// mat[0][6]='N';
	// mat[0][7]='R';
	// //blackpieces.
	// mat[7][0]='r';
	// mat[7][1]='n';
	// mat[7][2]='b';
	// mat[7][3]='q';
	// mat[7][4]='k';
	// mat[7][5]='b';
	// mat[7][6]='n';
	// mat[7][7]='r';
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         printf("%c\t",mat[i][j]);
    //     }
    //     printf("\n");
    // }
    char a,b;
    while(1){
        printf("before\n");
        a = getchar();//fgetc(stdin);
        b = getchar();//fgetc(stdin);
        printf("after\n");
        fflush(stdin);
        printf("%d.%d\n",a,b);
    }    
}