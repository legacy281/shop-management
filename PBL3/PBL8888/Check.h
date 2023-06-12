#ifndef FDABF9B5_9663_43EB_8C35_D73F6ABBE576
#define FDABF9B5_9663_43EB_8C35_D73F6ABBE576

#include "Hide_Pass.h"
//Kiểm tra mật khẩu khi đăng nhập vào giao diện Nhân viên
void Check()
    {

        Set_Color(1 << 8 | 0 << 10 | 6);
        
        wstring Check;
        bool Y=true;
        static int Count=0;

        do
        {
            system("cls");
            
            wcout<<L"\t\t\t\t   ============================================\n";
            wcout<<L"\t\t\t\t      WELCOME TO LAPTOP STORE AN NGỌC MẠNH ♥\n";
            wcout<<L"\t\t\t\t   ============================================\n";



            bool SH=false;

            char S;


            wcout<<L"\n\n\t\t\t\t           Nhấn '#' để hiện mật khẩu";

            S=getch();
            if(S=='#')
                SH=true;

            if(SH)
                {
                    wcout<<L"\n\n\n\t\t\t\t   Nhập mật khẩu xác thực nhân viên : ";
                    wcin>>Check;
                }
            else
                {
                    wcout<<L"\n\n\n\t\t\t\t   Nhập mật khẩu xác thực nhân viên : ";
                    Check=Hide_Pass();
                }


            /*wcout<<endl<<endl<<endl;
            wcout<<L"\t\t\t\t   Bạn muốn : "<<endl;
            wcout<<L"\t\t\t\t      1. Hiện mật khẩu khi xác thực "<<endl;
            wcout<<L"\t\t\t\t      2. Ẩn mật khẩu khi xác thực "<<endl;
            
            int SH;
            wcout<<L"\t\t\t\t      Lựa chọn :  ";
            wcin>>SH;

            wcout<<endl<<endl;
            if(SH==1)
                {
                    wcout<<L"\t\t\t\t   Nhập mật khẩu xác thực nhân viên : ";
                    wcin>>Check;
                }
            
            if(SH==2)
                {
                    wcout<<L"\t\t\t\t   Nhập mật khẩu xác thực nhân viên : ";
                    Check=Hide_Pass();
                }
            
            if(SH!=2 && SH!= 1)
                {
                    wcout<<L"\t\t\t\t Không đúng lựa chọn. Vui lòng thử lại"<<endl;
                    system("pause");
                    break;
                }*/

            if(Check==Temp->Password && Count <8)
                {
                    wcout<<endl<<endl;
                    wcout<<L"\t\t\t\t         Xác thực thành công!!! "<<endl;
                    Temp->Pass=true;
                    Count=0;
                    system("pause");
                    break;
                }
            
            else if(Count <5 )
                    {
                        wcout<<L"\t\t\t\t        Bạn đã nhập sai mật khẩu "<<endl;
                        wcout<<L"\t\t\t\t             Vui lòng thử lại "<<endl;
                        system("pause");
                        Count++;
                        Y=false;
                    }
            
            if(Count==3)
                {
                    wcout<<L"\t\t\t\t   Bạn đã nhập sai mật khẩu quá số lần cho phép "<<endl;
                    wcout<<L"\t\t\t\t         Vui lòng thử lại sau 5s "<<endl;
                    Y=false;
                    Sleep(5000);
                    system("pause");
                }

            if(Count==5)
                {
                    wcout<<L"\t\t\t\t   Bạn đã nhập sai mật khẩu quá số lần cho phép "<<endl;
                    wcout<<L"\t\t\t\t           Thoát khỏi giao diện Nhân viên"<<endl;
                    Count++;
                    system("pause");
                    break;
                }

            if( Count >5 && Count<=8)
                {
                    wcout<<L"\t\t\t\t        Bạn đã nhập sai mật khẩu "<<endl;
                    wcout<<L"\t\t\t\t             Vui lòng thử lại "<<endl;
                    system("pause");
                    Count++;
                    Y=false;
                }

            if(Count == 9)
                {
                    wcout<<L"\t\t\t\t   Bạn đã nhập sai mật khẩu quá số lần cho phép "<<endl;
                    wcout<<L"\t\t\t\t             Hệ thống sẽ tự thoát"<<endl;
                    system("pause");
                    exit(0);
                }

        } while (Y==false);


    }

#endif /* FDABF9B5_9663_43EB_8C35_D73F6ABBE576 */
