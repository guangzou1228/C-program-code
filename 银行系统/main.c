
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                          定义银行数据结构体
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct other
{
    int age;
    char sex[10];
    char email[20];
    char nation[20];
};


struct bankaccount 
{
    char accountname[20];
    char accountnumber[20];
    char accountpassword[20];
    double balance;
    struct other  otherinformation;

};





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//主界面
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char maininterface()
{
    char choice;

    puts("    --------------------------------------------------------     ");
    puts("    -                   Bank    System                     -     ");
    puts("    -                                                      -     ");
    puts("    -                                                      -     ");
    puts("    -                                                      -     ");
    puts("    -                                                      -     ");
    puts("    -        [1]  register         [2]  login              -     ");
    puts("    -                                                      -     ");
    puts("    -                                                      -     ");
    puts("    -                                                      -     ");
    puts("    -                                                      -     ");
    puts("    -                                                      -     ");
    puts("    --------------------------------------------------------     ");
    printf(" please enter your choice >>> ");

    scanf("%c",&choice);  fflush( stdin );

    return choice;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//注册用户
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Registeroperation( )
{

		struct bankaccount  accountA;
        char creatfilename[30];
        FILE *creatfp;


        printf(" please input your acountname ");    
        scanf("%s", accountA.accountname);  fflush(stdin);

        printf(" please input your phonenumber ");   
        scanf("%s", accountA.accountnumber );   fflush(stdin);

        printf(" please input your password ");      
        scanf("%s", accountA.accountpassword );     fflush(stdin);

        accountA.balance = 0;                              



        strcpy( creatfilename , accountA.accountnumber );                
        creatfp = fopen( strcat( creatfilename , ".bat" ) , "w" );      

         if ( fwrite( &accountA , sizeof( struct bankaccount ) , 1 , creatfp ) != 0 ) 
         {
            printf(" The account is successfully created !!! ");                  
         }
         else 
         {
            printf(" Account creation failed !!! ");
         }                       
        

        fclose( creatfp );                                          
    

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//some operation 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void nextoperation( char choice ,struct bankaccount  * account )
{
    switch( choice )
    {
        case '1':  
        {

            printf("**************************** personal information ****************************");
            printf("   *                                                                         *");
            printf("   *    Account name :  %s                                                   *", account->accountname );
            printf("   *                                                                         *");
            printf("   *    Account number:  %s                                                  *", account->accountnumber );
            printf("   *                                                                         *");
            printf("   *    Account password:  %s                                                *", account->accountpassword );
            printf("   *                                                                         *");
            printf("   *    Age :  %s                                                            *", account->otherinformation.age);
            printf("   *                                                                         *");
            printf("   *    Sex :  %s                                                            *", account->otherinformation.sex );
            printf("   *                                                                         *");
            printf("   *    Nation :  %s                                                         *", account->otherinformation.nation );
            printf("   *                                                                         *");
            printf("   *    Email :   %s                                                         *", account->otherinformation.email );
            printf("   *                                                                         *");
            printf("   *                                                                         *");
            printf("   *                                                                         *");
            printf("   *                                                                         *");
            printf("*********************************************************************************");



        } break;
        case '2': 
        {
            printf(" Balance : %lf "  , account->balance );





        } break;
        case '3':  
        {
            double howmuch ;
			FILE *fp;

			fp=fopen( strcat( account->accountnumber ,".obt") , "w" );

			printf(" How much do you want to deposit :  ");
			scanf("%f",&howmuch);       fflush(stdin);

			account->balance=account->balance + howmuch;

			fwrite( account , sizeof(account) , 1 , fp );
			fclose(fp);


        } break;
        case '4':    
        {
            
                int howmuch;
				FILE *fp;

				fp=fopen(strcat(account->accountnumber ,".obt"),"w");
				
				printf("How much do you want to get ? \n");
				printf(">>  ");
				scanf("%d", &howmuch);      fflush(stdin);
				
				fread( account , sizeof(account) , 1 , fp);
				if(account->balance < howmuch )
				{
					printf(" sorry dont too much money ! ");
				
				}
				else
				{
					account->balance = account->balance - howmuch;			
					fwrite(account, sizeof(account) , 1 , fp);
					
				}
						
				fclose(fp);



        } break;
        case '5':   
        {
            
			struct bankaccount transferaccount;         
		//	char Aaccountname[20];
			int temp; 

			FILE *fp , *transferfp ;
			
		A:	printf(" please input you want to transfer's account : ");
			scanf( "%s" ,transferaccount.accountnumber );       fflush(stdin);

                              
            if( ( transferfp=fopen(strcat( transferaccount.accountnumber , ".obt" ) , "r" ) ) == NULL )
            {
                printf(" This account does not exist !!! ");
                printf(" Please re-enter a valid account !!! ");

                goto A;
            }
			// transferfp = fopen( strcat( transferaccount.accountnumber , ".obt" ) , "r" );
			fread( & transferaccount , sizeof( struct bankaccount ) , 1 , transferfp );                  
            fclose( transferfp );

			printf(" How much do you want to transfer :");
			scanf( "%d" , &temp );      fflush(stdin);
			
			if( temp > account->balance )
			{
				printf("dont enough money !!!");
			}
			else
			{
			
			fp = fopen(strcat( account->accountnumber , ".obt" ), "w" ); 
            account->balance -= temp ;
			fwrite( account , sizeof( struct bankaccount ) , 1 , fp );                 
            fclose( fp );

            
            transferfp = fopen( strcat( transferaccount.accountnumber , ".obt" ) , "w" );
			//transferaccount.balance = transferaccount.balance - temp ;
			transferaccount.balance += temp ;
            fwrite( &transferaccount , sizeof( struct bankaccount ) , 1 , transferfp );
            fclose( transferfp );

			}
			


			

        } break;
        case '6':    
        {
            char midpassword[20];
            FILE *fp;
                                                                        //************ some bug ***********//


            printf(" Please enter your old password :");
            scanf("%s",midpassword);        fflush(stdin);
            if( strcmp( account->accountpassword , midpassword ) == 0 )
            {
                printf(" Please enter your new password :");
                scanf("%s",midpassword);        fflush(stdin);
                fp=fopen(account->accountnumber,"w");
                strcpy( account->accountpassword,midpassword );
                fwrite( account , sizeof( struct bankaccount ) , 1 , fp );
                fclose(fp);

            }
            printf(" Please enter your new password :");

        } break;
        case '7':   
        {
            
            exit(0);

        } break;
        case '8':   
        {
            system("cls");

        } break;
        default :
        {
            printf(" You entered the wrong option, please re-enter it !!! ");

        } 
    }


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//用户功能界面
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char  userfunctioninterface( struct bankaccount  account )
{

    char choice ;
    system("color 02");
    printf("        welcome  NO. %s                          ",account.accountnumber);

    puts(" ************************************************");
    puts(" *                                              *");
    puts(" *       1)  Basic Information                  *");         // 1.  鏌ヨ璐︽埛浣欓
    puts(" *       2)  Check your balance                 *");                 // 2.  瀛橀挶
    puts(" *       3)  Saving                             *");                // 3.  鍙栭挶
    puts(" *       4)  Withdraw money                     *");               // 4.  鍦ㄧ嚎杞处
    puts(" *       5)  Transfer                           *");           // 5.  淇敼瀵嗙爜
    puts(" *       6)  Change your password               *");
    puts(" *       7)  Sign out                           *");
    puts(" *                                              *");
    puts(" *                                              *");
    puts(" ************************************************");
    printf(" please enter your choice  >>>  ");
    scanf( "%c" , &choice ); fflush(stdin);
	return choice;
   // nextoperation( choice ,  account );

}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//登录用户
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct bankaccount Signinoperation(  )
{
                                  
        struct bankaccount midaccount,account;  
        char midfilename[30];   
        FILE *midfp;

        A:  printf( " please input your phonenumber : " );     
            scanf( "%s" , midaccount.accountnumber );       fflush(stdin);

            printf(" please input your password  :");   
            scanf( "%s" , midaccount.accountpassword );  fflush(stdin); 

            strcpy( midfilename , midaccount.accountnumber );                  
            midfp=fopen( strcat( midfilename , ".bat" ) , "r" );    

            if( midfp == NULL )           
            {
                printf(" The account does not exist !!!");       
                printf(" Please re-enter your account and password !!! ");
                goto A ;
            }
            else
            {
                fread( &account , sizeof( struct bankaccount ) , 1 ,midfp);        fclose( midfp );   
                if( strcmp( account.accountpassword , midaccount.accountpassword ) == 0 )     
                {
                  //  system("cls");
                  printf(" login successfully !!! ");    
                //  userfunctioninterface( & account );   

				return  ( account ) ;


                }
                else
                {
                    printf("login fail !!! ");
                }  

            }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//主函数
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{   

    char choice;
	char choice2;
	static struct bankaccount   revice;
    
    choice=maininterface();
    if( choice == '1' )
    {
        Registeroperation( );    
    }
    else if( choice == '2' )
        {
            revice = Signinoperation( );  
            system("cls");
            while(1)
            {

                choice2=userfunctioninterface(  revice  );
                nextoperation( choice ,  &revice );
                system("cls");

            } 
			
        }


    getch();

}


//////////////////////////////////////////////////////////////////////////////////////////
//程序结束
//////////////////////////////////////////////////////////////////////////////////////////



/*
Bank system

2023-12-14

tsoukuang

*/
