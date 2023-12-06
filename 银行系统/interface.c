#include<stdio.h>
#include<conio.h>
#include<windows.h>



void jiemian()
{
     system("color 02");

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

}
void function()
{
    system("color 02");
    puts(" ************************************************");
    puts(" *                                              *");
    puts(" *       1)  check account balance              *");         // 1.  查询账户余额
    puts(" *       2)  deposit money                      *");                 // 2.  存钱
    puts(" *       3)  draw the money                     *");                // 3.  取钱
    puts(" *       4)  onlion transfer                    *");               // 4.  在线转账
    puts(" *       5)  change the password                *");           // 5.  修改密码
    puts(" *       6)  ESC                                *");
    puts(" *                                              *");
    puts(" ************************************************");
    printf(" please enter your choice  >>>  ");

}


// void registeraccount()  // 注册账户
// {
//         system("cls");

//         printf(" please input your acountname  >>>");    //用户的名字
//         scanf("%s",user1.account); 

//         printf(" please input your phonenumber >>>");   //用户的账号
//         scanf("%s",user1.phone);

//         printf(" please input your password    >>>");      //用户的密码
//         scanf("%s", user1.password);

//         user1.money=0;                               //用户余额为0

//         strcpy(filename,user1.phone);                // 将账号赋值到filename数组中
//         fp=fopen(strcat(filename,".bat"),"w");         // 创建一个 账号+.bat 的文件

//          if (fwrite(&user1,sizeof(struct user),1,fp)!=0)      // 将user1中的数据写入 fp文件中（账号+.bat）
//          {
//             puts(" Created successful !!! ");                  // 打开无误 ---》 creat successful !!!
//          }
//          else {puts(" creat faile !!!");}                        // 打开出错  --》》error
        
//         fclose(fp);                                           // 无论成功与否    都关闭打开的文件



// }

// void loginaccount()
// {

//             printf("please input your phonenumber : ");     // 输入用户的账号
//             scanf("%s",phoneA);

//             printf("please input your password  :");    // 输入用户的密码
//             scanf("%s",passwordA);

//             strcpy(filename,phoneA);                   // 将账号复制到filename中
//             fp=fopen(strcat(filename,".bat"),"r");     // 打开filename.bat 的用户文件

//             if(fp==NULL)             // 打开是否成功----》用户是否存在
//             {
//                 printf(" This account is not exist !!!");       // 用户不存在
//             }
//             else
//             {
//                 fread(&user1,sizeof(struct user),1,fp);         fclose(fp);    // 成功打开 ，将用户的信息写入user1中
//                 if(strcmp(user1.password, passwordA)==0)      // 核对密码是否正确
//                 {
//                    function();  // 功能列表

                    
                   
//                 }






// }
// int main()
// {
//     jiemian();
//     getch();
//     system("cls");
//     function();
//     getch();

//     getch();
//     return 0;






// }