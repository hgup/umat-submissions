/*This is the main file for c mini project
V Ram Sai Deep
211216*/

#include"header.h"

// My main function

void main(int argc,char**argv){
    
    // Intializing the srand time because it help us in generating the randing numbers
    // Otherwise it will generate same numbers which is not useful for generating the prime numbers
    
    srand(time(NULL));

    // Intializing the varaibles.
    char x,filename[200], *name, y[] = "_encrypted.txt",z[]="_decrypted.txt",*file;
    
    int a=100,b=1000,p1,p2,n,e,d,flag=1,var,c;
    // Check no file names are asked, it will ask for the file name
    // Otherwise it will take the filenames given during the command

    if(argc==1){
        while(flag){
            printf("Do you want to encrypt or decrypt your file(1/2):\t");
            scanf("%d",&var);
            printf("\n");
            getchar();

            if(var==1){

                printf("Please enter your file name:\t");
                scanf("%199[^\n]", filename);
                getchar();

                name = malloc(strlen(filename) + strlen(y) + 2);
                if(name == NULL){
                    printf("No memory");
                    return;
                }

                strcpy(name,filename);
                strcat(name,y);
                printf("%s\n",name);

                p1=generate_prime_num(a,b);
                p2=generate_prime_num(a,b);

                generatekeys(p1,p2,&n,&e,&d);

                c=encrypt_file(filename,name,e,n);
                if(c==0){
                    return ;
                }

                printf("Your public key:%d\nYou private key:%d\n",n,d);
                printf("Press any key to continue");
                getchar();
                printf("\e[1;1H\e[2J");
                free(name);
            }
            else if(var==2){

                printf("Please enter your file name:\t");
                scanf("%[^\n]s",filename);
                getchar();

                printf("Enter your public and private key\t");
                scanf("%d %d",&n,&d);
                getchar();

                name = malloc(strlen(filename) + strlen(z) + 2);

                strcpy(name,filename);
                strcat(name,z);
                printf("%s\n",name);

                decrypt_file(filename, name, d, n);
            }
            else{
                printf("Not entered properly\nEXITING THE PROGRAM");
                flag=0;
            }

            printf("Do you wnat to continue?");
            scanf("%c",&x);

            if(x=='y')  
                continue;
            else    
                flag=0;
        }
    }
    else if(argc>1){
        printf("Do you want to encrypt or decrypt your files(1/2):\t");
        scanf("%d",&var);
        printf("\n");
        getchar();
        if(var==1){
            for(int i=1;i<argc;i++){
                p1=generate_prime_num(a,b);
                p2=generate_prime_num(a,b);

                generatekeys(p1,p2,&n,&e,&d);

                file=*(argv+i);

                name = malloc(strlen(file) + strlen(y) + 2);
                if(name == NULL){
                    printf("No memory");
                    return;
                }
                
                strcpy(name,file);
                strcat(name,y);

                c=encrypt_file(file,name,e,n);
                if(c=0){
                    continue;
                }

                printf("Your public key:%d\nYou private key:%d\n",n,d);
                printf("Press any key to continue");
                getchar();
                printf("\e[1;1H\e[2J");
            }
        }
        else if(var==2){
            for(int i=1;i<argc;i++){

                file=*(argv+i);

                name = malloc(strlen(file) + strlen(z) + 2);
                if(name == NULL){
                    printf("No memory");
                    return;
                }

                strcpy(name,file);
                strcat(name,z);

                printf("Enter your public and private key for %d file\t",i);
                scanf("%d %d",&n,&d);
                getchar();
                decrypt_file(file, name, d, n);
            }
        }
        else{
                printf("Not entered properly\nEXITING THE PROGRAM");
                flag=0;
        }
    }
}