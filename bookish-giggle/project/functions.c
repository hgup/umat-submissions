/*The functions file for the chess game.*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>
#include"header.h"
// The function to create the file to start the game.
void startGame(char mat[8][8]){
	FILE *file;
	int i,j;
	file=fopen("game.txt","w+");
	if(file==NULL){
		puts("**********Unable to open the file.********");
		return;
	}
	else{
			fprintf(file,"\n\t\t\t\t\t     1    2     3     4     5     6     7     8");
			fprintf(file,"\n\t\t\t\t\t  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			fprintf(file,"\n\t\t\t\t\t1 |  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|",mat[0][0],mat[0][1],mat[0][2],mat[0][3],mat[0][4],mat[0][5],mat[0][6],mat[0][7]);
			// fprintf(file,"\n\t\t\t\t\t  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			fprintf(file,"\n\t\t\t\t\t  -------------------------------------------------");
			fprintf(file,"\n\t\t\t\t\t2 |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |",mat[1][0],mat[1][1],mat[1][2],mat[1][3],mat[1][4],mat[1][5],mat[1][6],mat[1][7]);
			// fprintf(file,"\n\t\t\t\t\t  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			fprintf(file,"\n\t\t\t\t\t  -------------------------------------------------");
			fprintf(file,"\n\t\t\t\t\t3 |  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|",mat[2][0],mat[2][1],mat[2][2],mat[2][3],mat[2][4],mat[2][5],mat[2][6],mat[2][7]);
			fprintf(file,"\n\t\t\t\t\t  -------------------------------------------------");
			// fprintf(file,"\n\t\t\t\t\t  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			fprintf(file,"\n\t\t\t\t\t4 |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |",mat[3][0],mat[3][1],mat[3][2],mat[3][3],mat[3][4],mat[3][5],mat[3][6],mat[3][7]);
			fprintf(file,"\n\t\t\t\t\t  -------------------------------------------------");
			// fprintf(file,"\n\t\t\t\t\t  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			fprintf(file,"\n\t\t\t\t\t5 |  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|",mat[4][0],mat[4][1],mat[4][2],mat[4][3],mat[4][4],mat[4][5],mat[4][6],mat[4][7]);
			fprintf(file,"\n\t\t\t\t\t  -------------------------------------------------");
			// fprintf(file,"\n\t\t\t\t\t  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			fprintf(file,"\n\t\t\t\t\t6 |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |",mat[5][0],mat[5][1],mat[5][2],mat[5][3],mat[5][4],mat[5][5],mat[5][6],mat[5][7]);
			fprintf(file,"\n\t\t\t\t\t  -------------------------------------------------");
			// fprintf(file,"\n\t\t\t\t\t  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			fprintf(file,"\n\t\t\t\t\t7 |  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|",mat[6][0],mat[6][1],mat[6][2],mat[6][3],mat[6][4],mat[6][5],mat[6][6],mat[6][7]);
			fprintf(file,"\n\t\t\t\t\t  -------------------------------------------------");
			// fprintf(file,"\n\t\t\t\t\t  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
			fprintf(file,"\n\t\t\t\t\t8 |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |█ %c █|  %c  |",mat[7][0],mat[7][1],mat[7][2],mat[7][3],mat[7][4],mat[7][5],mat[7][6],mat[7][7]);
			fprintf(file,"\n\t\t\t\t\t  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	}
	fclose(file);
}
// The function to display the file.
void display(void){
	FILE *file;
	char ch;
	file=fopen("game.txt","r");
	if(file==NULL){
		puts("********Unable to access the file, sorry************");
		return;
	}
	/*while(!feof(file)){		printf("erro");
		//fgets(s,1,file);
		fscanf(file,"%s",s);
		printf("%s\n",s);
	}*/
	while((ch=fgetc(file))!=EOF){
		//if(ch=='P'){
		//	printf("♙");
		//}
		//else
			putchar(ch);
	}
	printf("\n♔");
	fclose(file);
}
// The function for the matrix input first time.
void matrix(char mat[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==1)    mat[i][j]='P';
            else if(i==6)   mat[i][j]='p';
            else    mat[i][j]=' ';
        }
    }
    mat[0][0]='R';//white pieces.
    mat[0][1]='N';
    mat[0][2]='B';
    mat[0][3]='Q';
    mat[0][4]='K';
    mat[0][5]='B';
    mat[0][6]='N';
    mat[0][7]='R';
    //blackpieces.
    mat[7][0]='r';
    mat[7][1]='n';
    mat[7][2]='b';
    mat[7][3]='q';
    mat[7][4]='k';
    mat[7][5]='b';
    mat[7][6]='n';
    mat[7][7]='r';
}

// The function to move the white soilder.
int P_soilder(int r, int c, int i, int j, char mat[8][8]){
	
	if(j==c&&i>r){
		if(r==1&&(i==2||i==3)){
			if(!islower(mat[i][j]))
        		return 1;
		}
		else if(i==r+1){
			if(!islower(mat[i][j]))
				return 1;
		}
	}
	
	if((j==c+1||j==c-1)&&i==r+1){
		if(mat[i][j]!=' '){
			return 1;
		}
	}
	else{
		return 0;
	}
}

// The function to move the black soilder.
int p_soilder(int r, int c, int i, int j, char mat[8][8]){

	if(j==c&&i<r){
		if(r==6&&(i==5||i==4)){
			if(!isupper(mat[i][j]))
        		return 1;
		}
		else if(i==r-1){
			if(!isupper(mat[i][j]))
				return 1;
		}
	}
	
	if((j==c-1||j==c+1)&&i==r-1){
		if(mat[i][j]!=' '){
			return 1;
		}
	}
	else{
		printf("invalid position to move");
		return 0;
	}
}
// The function to move the rock.
int R_rock(int r,int c, int i, int j, char mat[8][8]){
	int k;
	if(i==r){
		if(j>c){
			k=c+1;
			while(k<j){
				if(isupper(mat[r][k]||islower(mat[r][k]))){
					printf("1");
					return 0;
				}k++;
			}
			if(islower(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
		if(j<c){
			k=c-1;
			while(k>j){
				if(isupper(mat[r][k])||islower(mat[r][k])){
					printf("2");
					return 0;
				}k--;
			}
			if(islower(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
	}
	else if(j==c){
			if(i>r){
				for(k=r+1;k<i;k++){
					if(isupper(mat[k][c])||islower(mat[k][c])){
						printf("3");
						return 0;
					}
				}
				if(islower(mat[i][j])||mat[i][j]==' ')
					return 1;
			}
			else if(i<r){
					k=r-1;
					while(k>i){
						if(isupper(mat[k][c])||islower(mat[k][c])){
							printf("4");
							return 0;
						}
						k--;
					}
					if(islower(mat[i][j])||mat[i][j]==' ')
						return 1;
				}
		}
	else 
		printf("error:::::::");	
		return 0;
}
// The to move the black rock.
int r_rock(int r,int c, int i, int j,char mat[8][8]){
	int k;
	
	if(i==r){
		if(j>c){
			k=c+1;
		while(k<j){
			if(islower(mat[i][k])||isupper(mat[i][k])){
				return 0;
			} k++;
		}
		if(isupper(mat[i][j])||mat[i][j]==' ')
			return 1;
		}
		else if(j<c){
			k=c-1;
			while(k>j){
				if(islower(mat[i][k])||isupper(mat[i][k])){
					return 0;
				}k--;
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
	}
	else if(j==c){
		if(i>r){
			k=r+1;
			while(k<i){
				if(islower(mat[k][j])||isupper(mat[k][j])){
					return 0;
				}k++;
				
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
		if(i<r){
			k=r-1;
			while(k>i){
				if(islower(mat[k][j])||isupper(mat[k][j])){
					return 0;
				}k--;
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
	}
	else 
			return 0;
}
// The function to check the move of the bishop.
int B_bishop(int r, int c, int i, int j, char mat[8][8]){
	int l,m;
	if(r>i){
		if(i<=j){
			l=r-1;m=c+1;
			while(l>i){
				if(isupper(mat[l][m])||islower(mat[l][m])){
					printf("1");
					return 0;
				}
				else
					{l--; m++;}
			}
			if(islower(mat[i][j])||mat[i][j]==' '){
				printf("b1");
				return 1;}
		}
		else if(i>=j){
			m=c-1;l=r-1;
			while(l>i){
				if(isupper(mat[l][m])||islower(mat[l][m])){
					printf("2");
					return 0;
				}
				else{
					l--;
					m--;
				}
			}
			if(islower(mat[i][j])||mat[i][j]==' '){
				printf("b2");
				return 1;}
		}
	}
	else if(r<i){
		//printf("a");
		if(i>=j){
			//printf("b");
			m=c+1;l=r+1;
			while(l<i){
				if(isupper(mat[l][m])||islower(mat[l][m])){
					//printf("3");
					return 0;
				}
				else{
				l++;
				m--;
				}
			}
			if(islower(mat[i][j])||mat[i][j]==' '){
				printf("b3");
				return 1;}
		}
		else if(i<=j){
			//printf("c");
			m=c+1; l=r+1;
			while(l<i){
				if (isupper(mat[l][m])||islower(mat[l][m])){
					//printf("4");
					return 0;
				}
				else{ 
					l++; m++;
				}
			}
			if(islower(mat[i][j])||mat[i][j]==' '){
				printf("b4");
				return 1;}
		}
	}
	//printf("5");
	return 0;
}
// The function to check the move of the black bishop.
int b_bishop(int r, int c, int i, int j, char mat[8][8]){
	int l,m;
	if(r>i){
		if(i<=j){
			l=r-1;m=c+1;
			while(l>i){
				if(islower(mat[l][m])||isupper(mat[l][m])){
					return 0;
				}
				else{
					l--; m++;
				}
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
		else if(i>=j){
			m=c-1;l=r-1;
			while(l>i){
				if(islower(mat[l][m])||isupper(mat[l][m])){
					return 0;
				}
				else{
					l--;m--;}
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
	}
	else if(r<i){
		if(i>=j){
			m=c+1;l=r+1;
			while(l<i){
				if(islower(mat[l][m])||isupper(mat[l][m])){
					return 0;
				}
				else {
				l++;
				m++;
				}
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
		else if(i<=j){
			m=c-1; l=r+1;
			while(l<i){
				if (islower(mat[l][m])||isupper(mat[l][m])){
					return 0;
				}
				else {
					l++; m--;
				}
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
	}
	return 0;
	
}
//The function to check the move of the queen.
int Q_queen(int r, int c, int i, int j, char mat[8][8]){
	int ch=0;
	if(R_rock(r,c,i,j,mat) || B_bishop(r,c,i,j,mat)){
		return 1;
	}
	else 
		return 0;
}
//The function to check the move of the queen.
int q_queen(int r, int c, int i, int j, char mat[8][8]){
	int ch=0;
	if(r_rock(r,c,i,j,mat) || b_bishop(r,c,i,j,mat)){
		return 1;
	}
	else 
		return 0;
}

// The function to check the white knights move.
int N_knights(int r,int c, int i, int j, char mat[8][8]){
	int ch;
	/*if((abs(r-i)<=2)&&(abs(c-j)<=2)){
		printf("1");
		ch=Q_queen(r,c,i,j,mat);
		printf("%d",ch);
		if(ch==0){
			return 1;
		}
	}*/
	if(((i==r-1||i==r+1)&&(j==c+2||j==c-2))||((i==r+2||i==r-2)&&(j==c+1||j==c-1)))
	{
		printf("g");
		if(isupper(mat[i][j]))
			return 0;
		else	
			return 1;
	}
	return 0;
}
// The function to check the  black knights move.
int n_knights(int r,int c, int i, int j, char mat[8][8]){
	int ch;
	/*if((abs(r-i)<=2)&&(abs(c-j)<=2)){
		ch=q_queen(r,c,i,j,mat);
		if(ch==0){
			return 1;
		}
	}*/
	if(((i==r-1||i==r+1)&&(j==c+2||j==c-2))||((i==r+2||i==r-2)&&(j==c+1||j==c-1)))
	{
		if(islower(mat[i][j]))
			return 0;
		else	
			return 1;
	}
	return 0;
}
// The function to move the king.
int K_king(int r, int c, int i, int j, char mat[8][8]){
	if((i==r+1||i==r-1||i==r)&&(j==c+1||j==c-1||j==c)){
		if(mat[i][j]==' '&&islower(mat[i][j]))
			return 1;
	}
	return 0;
}
// The function to move black king.
int k_king(int r, int c, int i,int j, char mat[8][8]){
	if((i==r+1||i==r-1||i==r)&&(j==c+1||j==c-1||j==c)){
		if(mat[i][j]==' '&&isupper(mat[i][j]))
			return 1;
	}
	return 0;
}
// The function for the checkmate.
/*int check_mate(void){
	int i;
	if(upper_check(mat)&&!K_king()){

	}
}*/
//The function to check weather move is check or not.
/*int check(int r, int c,char mat[8][8]){
	int a,b;
	if(isupper(mat[r][c])){
		// check the position of the k_king and find the path is true or false.
		for (a=0;a<8; a++)
		{
			for(b=0;b<8;b++){
				if(mat[a][b]=='k')
					break;
			}
		}
		switch(mat[r][c]){
			case 'P':
					if(P_soilder(r,c,a,b,mat))
						return 1;
					else
						return 0;
					break;
			case 'R':
					 if(R_rock(r,c,a,b,mat))
					 	return 1;
					else
						return 0;
					break;
			case 'B':
					 if(B_bishop(r,c,a,b,mat))
					 	return 1;
					else
						return 0;
					break;
			case 'N':
						if(N_knights(r,c,a,b,mat))
							return 1;
						else
							return 0;
						break;
			case 'Q':
						if(Q_queen(r,c,a,b,mat))
							return 1;
						else 
							return 0;
						break;
		}
		
		//if true then it is check.
	}
	if(islower(mat[r][c])){
		//same but the opposite king.
		for (a=0;a<8; a++)
		{
			for(b=0;b<8;b++){
				if(mat[a][b]=='K')
					break;
			}
		}
		switch(mat[r][c]){
			case 'p':
					if(p_soilder(r,c,a,b,mat))
						return 1;
					else
						return 0;
					break;
			case 'r':
					 if(r_rock(r,c,a,b,mat))
					 	return 1;
					else
						return 0;
					break;
			case 'b':
					 if(b_bishop(r,c,a,b,mat))
					 	return 1;
					else
						return 0;
					break;
			case 'n':
						if(n_knights(r,c,a,b,mat))
							return 1;
						else
							return 0;
						break;
			case 'q':
						if(q_queen(r,c,a,b,mat))
							return 1;
						else 
							return 0;
						break;
		}
	}
}*/
int lower_check(char mat[8][8]){
	int a,b,c,d;
	for(a=0;a<8;a++){
		for(b=0;b<8;b++){
			if(mat[a][b]=='k')
				break;
		}
		if(mat[a][b]=='k')
			break;
	}
	for(c=0;c<8;c++){
		for(d=0;d<8;d++){
			if(isupper(mat[c][d])){
				switch (mat[c][d])
				{
					case 'P':
							if(P_soilder(c,d,a,b,mat))
								return 1;
							else
								break;
					case 'R':
							 if(R_rock(c,d,a,b,mat))
					 			return 1;
							else
								break;

					case 'B':
					 		if(B_bishop(c,d,a,b,mat))
					 			return 1;
							else
								break;
					case 'N':
							if(N_knights(c,d,a,b,mat))
								return 1;
							else
								break;
					case 'Q':
							if(Q_queen(c,d,a,b,mat))
								return 1;
							else 							
								break;
				
				}
			}
		}
	}
		return 0;
}
int upper_check(char mat[8][8]){
	int a,b,c,d;
	for(a=0;a<8;a++){
		for(b=0;b<8;b++){
			if(mat[a][b]=='K')
				break;
		}
		if(mat[a][b]=='K')
			break;

	}
	printf("%c",mat[a][b]);
	for(c=0;c<8;c++){
		for(d=0;d<8;d++){
			if(islower(mat[c][d])){

				switch (mat[c][d])
				{
					case 'p':

							if(p_soilder(c,d,a,b,mat)){
								printf("1");
								return 1;
							}
							else
								break;
					case 'r':
							 if(r_rock(c,d,a,b,mat)){
								printf("2");
					 			return 1;
							 }
							else
								break;
					case 'b':
					 		if(b_bishop(c,d,a,b,mat)){
								printf("3");
					 			return 1;
							}
							else
								break;
					case 'n':
							if(n_knights(c,d,a,b,mat)){
								printf("4");
								printf("%d %d %d %d",a,b,c,d);
								return 1;
							}
							else
								break;
					case 'q':
							if(q_queen(c,d,a,b,mat)){
								printf("5");
								return 1;
							}
							else 							
								break;
				
				}
			}
		}
	}
	return 0;
}

// The function to take input from the user.
void input(char mat[8][8]){
	char ch,o;
	int r,c,i,j,check=0,a,b;
	printf("Select the position to be moved:......");
	scanf("%d %d", &r,&c);
	getchar();
	if((0<r&&r<9)&&(0<c&&c<9)){
		exit;
	}
	r=r-1; c=c-1;
	/*if(flag==0){
		a=r;
		b=c;
	}*/
	ch=mat[r][c];
	printf("you have selected %c",mat[r][c]);
	if(isupper(ch)){
		switch(ch){
			case 'P':
				do{
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=P_soilder(r,c,i,j,mat);
						if(check){
							o=mat[i][j];	
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							/*if(check(a,b)){
								mat[r][c]=mat[i][j];
								mat[i][j]=' ';
							}*/
							if(upper_check(mat)){
								mat[r][c]=mat[i][j];
								printf(" fuck you");
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
						else
							printf("***************invalid move**********");
					}
					}while(!check);
				break;
			case 'R':
				do{
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=R_rock(r,c,i,j,mat);
						if(check){
							o=mat[i][j];
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(upper_check(mat)){
								mat[r][c]=mat[i][j];
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
						else
							printf("***************invalid move**********");
					}
				}while(!check);
				break;
			case 'N':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=N_knights(r,c,i,j,mat);
						if(check){
							o=mat[i][j];
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(upper_check(mat)){
								mat[r][c]=mat[i][j];
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
					}
				}		
			case 'B':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=B_bishop(r,c,i,j,mat);
						if(check){
							o=mat[i][j];
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(upper_check(mat)){
								mat[r][c]=mat[i][j];
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
					}
				}
			case 'Q':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=Q_queen(r,c,i,j,mat);
						if(check){
							o=mat[i][j];
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(upper_check(mat)){
								mat[r][c]=mat[i][j];
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
					}
				}
			case 'K':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						check=K_king(r,c,i,j,mat);
						if(check){
							o=mat[i][j];
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(upper_check(mat)){
								mat[r][c]=mat[i][j];
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
					}
				}
		}
	}
	else if(islower(ch)){
		switch(ch){
			case 'p':
				do{
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					i=i-1; j=j-1;
					if((0<i&&i<9)&&(0<j&&j<9)){
						check=p_soilder(r,c,i,j,mat);
						if(check){
							o=mat[i][j];
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(lower_check(mat)){
								mat[r][c]=mat[i][j];
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
					}
					else	printf("***************invalid move**********");
				}while(!check);
				break;
			case 'r':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=r_rock(r,c,i,j,mat);
						if(check){
							o=mat[i][j];
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(lower_check(mat)){
								mat[r][c]=mat[i][j];
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
					}
				}
			case 'n':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=n_knights(r,c,i,j,mat);
						if(check){
							o=mat[i][j];
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(lower_check(mat)){
								mat[r][c]=mat[i][j];
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
					}
				}		
			case 'b':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=b_bishop(r,c,i,j,mat);
						if(check){
							o=mat[i][j];
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(lower_check(mat)){
								mat[r][c]=mat[i][j];
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
					}
				}
			case 'q':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=q_queen(r,c,i,j,mat);
						if(check){
							o=mat[i][j];
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(lower_check(mat)){
								mat[r][c]=mat[i][j];
								mat[i][j]=o;
								input(mat);
							}
							startGame(mat);
						}
					}
				}
			case 'k':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=k_king(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
				}
		}
		if(ch==' ')
			input(mat);
	}				
}
// The goto function to move to the specific position.
void gotoxy(int x,int y)
	{
		printf("%c[%d;%df",0x1B,y,x);
	}
// The main menu function to display.
int mainMenu(void)
{
	int x = 10, y = 5;
	int yStart = y;
	
	int selected;
	
	printf("\e[1;H\e[2J"); //clear the console.
	gotoxy(x,y++);
	printf("New Game\n");
	gotoxy(x,y++);
	printf("Controls\n");
	gotoxy(x,y++);
	printf("Exit\n");
	gotoxy(x,y++);

	selected = menuSelector(x, y, yStart);

	return(selected);
}
// The function to select the part of the menu.
int menuSelector(int x, int y, int yStart)
{
	char key;
	int i = 0;
	x = x - 2;
	gotoxy(x,yStart);
	
	printf(">");
	
	gotoxy(10,5);

	
	do
	{
		key = waitForAnyKey();
		//printf("%c %d", key, (int)key);
		if ( key == (char)UP_ARROW )
		{
			gotoxy(x,yStart+i);
			printf(" ");
			
			if (yStart >= yStart+i ) 
				i = y - yStart - 2;
			else
				i--;
			gotoxy(x,yStart+i);
			printf(">");
		}
		else
			if ( key == (char)DOWN_ARROW )
			{
				gotoxy(x,yStart+i);
				printf(" ");
				
				if (i+2 >= y - yStart ) 
					i = 0;
				else
					i++;
				gotoxy(x,yStart+i);
				printf(">");				
			}	
			//gotoxy(1,1);
			//printf("%d", key);
	} while(key != (char)ENTER_KEY); //While doesn't equal enter... (13 ASCII code for enter) - note ubuntu is 10
	return(i);
}

// The function to exit from the game.
void exitYN(void)
{
	char pressed;
	gotoxy(9,8);
	printf("Are you sure you want to exit(Y/N)\n");
	
	do
	{
		pressed = waitForAnyKey();
		pressed = tolower(pressed);
	} while (!(pressed == 'y' || pressed == 'n'));
	
	if (pressed == 'y')
	{
		printf("\e[1;H\e[2J"); //clear the console
		exit(1);
	}
	return;
}
// The function to load the game.
void loadgame(void){
	char mat[8][8];
    printf("\e[1;H\e[2J");
    matrix(mat);
    startGame(mat);
    display();
    while(1){
        printf("The player1's turn to play please selete the pown to move\n:");
        input(mat);
        //clrscr();
        printf("\e[1;H\e[2J");
        display();

        printf("The player 2's turn to play, please selete the pown to move\n");
        input(mat);
        //clrscr();
        printf("\e[1;H\e[2J");
        display();
    }
}
// 
char waitForAnyKey(void)
{
	int pressed;
	
	while(!kbhit());
	
	pressed = getch();
	//pressed = tolower(pressed);
	return((char)pressed);
}

void controls(void)
{
	int x = 10, y = 5;
    printf("\e[1;H\e[2J"); //clear the console
	gotoxy(x,y++);
	printf("Controls\n");
	gotoxy(x++,y++);
	printf("#first player is asked for the selection of the position to be moved:::::: ");
	gotoxy(x,y++);
	printf("#Then the position to which he wants to move is asked by the program if vaild it move or the repeats.");
	gotoxy(x,y++);
	printf("#how to select the postion to be moved which is first selet left displayed number->ENTER and then top one->ENTER.");
	gotoxy(x,y++);
	gotoxy(x,y++);
	printf("#If the check is given the player is contnously asked to move the suitable move to avoid the check. ");
	gotoxy(x,y++);
	gotoxy(x,y++);
	printf("#after the player 1 makes his move the player to given chance to move with same steps and rules.");
	gotoxy(x,y++);
	gotoxy(x,y++);
	printf("P & Esc pauses the game.");
	gotoxy(x,y++);
	gotoxy(x,y++);
	printf("Press any key to continue...");
	waitForAnyKey();
	return;
}


int kbhit(void)
	{
	  struct termios oldt, newt;
	  int ch;
	  int oldf;

	  tcgetattr(STDIN_FILENO, &oldt);
	  newt = oldt;
	  newt.c_lflag &= ~(ICANON | ECHO);
	  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	  ch = getchar();

	  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	  fcntl(STDIN_FILENO, F_SETFL, oldf);

	  if(ch != EOF)
	  {
		ungetc(ch, stdin);
		return 1;
	  }

	  return 0;
	}

	//http://www.experts-exchange.com/Programming/Languages/C/Q_10119844.html - posted by jos
	char getch()
	{
		char c;
		system("stty raw");
		c= getchar();
		system("stty sane");
		//printf("%c",c);
		return(c);
	}