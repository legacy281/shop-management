#ifndef F9AE9D10_5495_412E_9917_1E049DB24615
#define F9AE9D10_5495_412E_9917_1E049DB24615

//Thay đổi mật khẩu (Nhân viên)
void Computer_Store::Change_Password()
    {
        system("cls");

        Head();

        Set_Color(1 << 8 | 0 << 7 | 6); 

        wstring Check=L"",Change=L"",Re_Change=L"";

        wcout<<endl<<endl<<endl;
        wcout<<L"\t\t\t\t   Bạn muốn : "<<endl;
        wcout<<L"\t\t\t\t      1. Hiện mật khẩu khi xác thực "<<endl;
        wcout<<L"\t\t\t\t      2. Ẩn mật khẩu khi xác thực "<<endl;
        wcout<<L"\t\t\t\t      Lựa chọn :  ";

        int SH;
        wcin>>SH;

        wcout<<"\n\n";

        if(SH==1)
            {
                wcout<<L"\t\t\t\t  Mật khẩu cũ            : ";
                wcin>>Check;
                wcout<<L"\t\t\t\t  Mật khẩu mới           : ";
                wcin>>Change;
                wcout<<L"\t\t\t\t  Nhập lại mật khẩu mới  : ";
                wcin>>Re_Change;
            }

        if(SH==2)
            {
                wcout<<L"\t\t\t\t  Mật khẩu cũ            : ";
                Check=Hide_Pass();
                wcout<<L"\t\t\t\t  Mật khẩu mới           : ";
                Change=Hide_Pass();
                wcout<<L"\t\t\t\t  Nhập lại mật khẩu mới  : ";
                Re_Change=Hide_Pass();
            }

        if(SH!=2 && SH!= 1)
                {
                    wcout<<L"\t\t\t\t  Không đúng lựa chọn. Vui lòng thử lại"<<endl;
                    system("pause");
                    return;
                }

        if(Check != Temp->Password)
            {
                wcout<<L"\t\t\t\t  Mật khẩu cũ không đúng. Vui lòng kiểm tra lại."<<endl;
                system("Pause");
                return;
            }

        if(Change != Re_Change)
            {
                wcout<<L"\t\t\t\tMật khẩu mới nhập lại không khớp. Vui lòng kiểm tra lại."<<endl;
                system("Pause");
                return;
            }
        
        Temp->Password=Change;

        wcout<<L"\t\t\t\tBạn đã thay đổi mật khẩu thành công !!!"<<endl;
        
        system("Pause");
            
        
    }

#endif /* F9AE9D10_5495_412E_9917_1E049DB24615 */
