#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include"interface.c"
struct user 
{
    char accountname[50];   //账号
    char phone[50];     // 账户号码
    char password[50];  // 密码
    float money;         // 钱

};
int main()
{
      struct user  user1 , user2;    // 定义两个用户
      char filename[30],filename1[30];      // 打开文件的载体数组
      FILE *fp,*fp1;                      // 文件指针
      char  opt;                     //  界面选择登录还是注册
      char  conl;                 // 账户的状态  是激活还是 禁止
      char choice;                    // 登录后的用户选项
      char phoneA[50],passwordA[50];    // 登陆时临时的账号和密码的载体
      float amount;                     // 存款或者取钱online transfer 时的钱的载体
    jiemian();
    scanf("%c",&opt);       fflush(stdin);  // 清楚输入流中的回车

    system("cls");  //清屏进入用户选择的界面

    if(opt=='1')                          //  创建一个用户
    {
        printf(" please input your acountname ");    //用户的名字
        scanf("%s",user1.accountname);

        printf(" please input your phonenumber ");   //用户的账号
        scanf("%s",user1.phone);

        printf(" please input your password ");      //用户的密码
        scanf("%s", user1.password);

        user1.money=0;                               //用户余额为0



        strcpy(filename,user1.phone);                // 将账号赋值到filename数组中
        fp=fopen(strcat(filename,".bat"),"w");         // 创建一个 账号+.bat 的文件

         if (fwrite(&user1,sizeof(struct user),1,fp)!=0)      // 将user1中的数据写入 fp文件中（账号+.bat）
         {
            puts(" Created successful !!! ");                  // 打开无误 ---》 creat successful !!!
         }
         else {puts(" creat faile !!!");}                        // 打开出错  --》》error
        
        fclose(fp);                                           // 无论成功与否    都关闭打开的文件
    }


    else if(opt=='2')                                  // 登录用户 
        {
            printf(" please input your phonenumber : ");     // 输入用户的账号
            scanf("%s",phoneA);

            printf(" please input your password  :");    // 输入用户的密码
            scanf("%s",passwordA);  getchar(); // 读取最后一个字符

            strcpy(filename,phoneA);                   // 将账号复制到filename中
            fp=fopen(strcat(filename,".bat"),"r");     // 打开filename.bat 的用户文件

            if(fp==NULL)             // 打开是否成功----》用户是否存在
            {
                printf(" This account is not exist !!!");       // 用户不存在
            }
            else
            {
                fread(&user1,sizeof(struct user),1,fp);         fclose(fp);    // 成功打开 ，将用户的信息写入user1中
                if(strcmp(user1.password, passwordA)==0)      // 核对密码是否正确
                {
                    system("cls");
                    function();    // user jiemian 
                   
                    scanf("%c",&choice);  getchar(); // 输入想要选择的服务


                    while(choice!='6')
                    {   
                        
                         switch(choice)  // 根据选择 进行不同的操作
                        {
                            case '1':  printf("The acount have %d money",user1.money);break;


                            case '2': 
                            {
                                    printf(" \nplease input how much you want to deposit :");
                                    scanf("%f",&amount); fflush(stdin);
                                    user1.money+=amount;
                                    fp=fopen(filename,"w");
                                    if(fwrite(&user1,sizeof(struct user),1,fp)!=0)
                                    {
                                        puts(" deposit is successfull");
                                    }
                                    fclose(fp);

                            }  break;


                            case '3':
                            {
                                    printf(" \nhow much money do you want to draw :");
                                    scanf("%f",&amount); fflush(stdin);
                                    user1.money-=amount;
                                    fp=fopen(filename,"w");
                                    if(fwrite(&user1,sizeof(struct user),1,fp)!=0)
                                    {
                                        puts(" draw money  is successfull");
                                    }
                            }break;


                            case '4':
                            {
                                printf(" \nplease input you want to transfer account phone :");
                                scanf("%s",phoneA);  fflush(stdin);
                                strcpy(filename1,phoneA);
                                fp1=fopen(strcat(filename,".bat"),"r");
                                fread(&user2, sizeof(struct user),1,fp);
                                fclose(fp);
                                if(fp==NULL)
                                {
                                    puts(" \nThis account phone is not exist !!!");

                                }
                                printf("\n please input you how much want to transfer:");
                                scanf("%f",&amount); fflush(stdin);

                                        if(amount > user1.money)
                                        {
                                            puts(" \nyour money is not enough ");
                                        }
                                        user2.money+=amount;
                                        fp1=fopen(filename1,"w");
                                        fwrite(&user2, sizeof(struct user ),1,fp1);


                                        user1.money-=amount;
                                        fp=fopen(strcat(user1.phone,".bat"),"w");
                                        fwrite(&user1,sizeof(struct user),1,fp);


                            }break;


                            case '5':
                            {

                                printf("please input the new password :");
                                scanf("%s",phoneA); fflush(stdin);
                                    fopen(strcat(user1.phone,".bat"),"w");
                                    strcpy(user1.password,phoneA);
                                    fwrite(&user1, sizeof(struct user ),1,fp);

                            }break;


                            case '6' : exit(0); break;


                            default :printf(" choice is woring !!!");
                        
                         }  
                          
                           // function(); // 功能选项界面
                            printf(" \nplease enter your choice >>> ");
                            scanf("%c",&choice); getchar();


                       

                     }

                }
                
                else {    // 账号密码错误
                puts("password is error !!!");
                }


            }




        }
        else printf(" input is error !!!");








    getch();

    return 0;
}