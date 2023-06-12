#ifndef CFE32516_DB4E_4ED1_823A_C1A430C7AA7B
#define CFE32516_DB4E_4ED1_823A_C1A430C7AA7B

#include "Set_Color.h"
#include "Head.h"
#include "Resume.h"
//Sửa đơn hàng
void Computer_Store::Modify_Order()
    {
        int Mod;
        bool Found=FALSE;
        Tempp= Start_Ptr ;
        wstring str=L"---------------------------------------------------------------------------------\n";
        wstring str1=L"**************************************************************************************************************************";
        wstring str2=L"|--------|-----------------------|-----------------------|---------------|---------------|-----------------------|-------|";
        
        system("cls");
        
        Head();

        Set_Color(1 << 8 | 0 << 7 | 6);

        //Không có đơn hàng cần sửa 
        if(Tempp == NULL )
            {
                wcout<<L"\n\t\t\t\t\t====================================\n";
                wcout<<L"\t\t\t\t\t       Hiện không có đơn hàng  \n";
                wcout<<L"\t\t\t\t\t====================================\n\n";
                system("pause");
            }
        
        else
            {
                //Bắt đầu nhập thông tin mã đơn hàng cần sửa
                wcout<<L"\n\t\t\t\t Nhập mã đơn hàng cần sửa đơn :  ";
                wcin>>Mod;
                
                while(Tempp !=NULL && !Found)
                    {
                        if(Tempp->Receipt_Number == Mod)
                            Found=true;
                            
                        else 
                            Tempp=Tempp->PNext;
                    }    
                    /*Sau khi tìm thấy đơn hàng, thực hiện lựa chọn 
                    - sửa tên 
                    - thay đổi Laptop
                    */
                        if(Found)
                            {
                                wcout<<L"\n\n\t\t\t\tQuý khách muốn sửa thông tin: \n"
                                    <<L"\t\t\t\t1.Họ và tên"<<endl
                                    <<L"\t\t\t\t2.Số lượng Laptop"<<endl;
                                wcout<<L"\t\t\t\tLựa chọn của quý khách : "    ;
                                int Choice;
                                wcin>>Choice;

                                //Thay đổi tên
                                if(Choice==1)
                                    {
                                        wcout<<L"\n\n\t\t\t\tMời quý khách nhập lại tên:  ";
                                        wcin>>Tempp->Customer_Name;
                                    }
                                //Thay đổi Laptop trong đơn hàng
                                if(Choice ==2 )
                                    {
                                        
                                        Resume(Mod);

                                        wcout<<L"\t\t\t\t\tMời quý khách chọn lại Laptop"<<endl;
                                        wcout<<"\t\t"<<str;
                                        
                                        int X;
                                        wcout<<L"\t\t\t\tSố loại Laptop mà bạn muốn mua"<<endl
                                            <<L"\t\t\t\tTối đa bạn có thể mua "<<Temp->Quant<<L" loại khác nhau: ";
                                        wcin>>Tempp->X;
                                        
                                        if(Tempp->X<0)
                                            {
                                                wcout<<L"\t\t\t\tKhông thể thực hiện thủ tục order vì số lượng bạn order nhỏ hơn 0"<<endl;
                                                wcout<<str;
                                                system("pause");
                                            }
                                            
                                        else if(Tempp->X>Temp->Quant)
                                                {
                                                    wcout<<L"\t\t\t\tXin lỗi quý khách,hiện tại Cửa Hàng chỉ có tối đa "<<Temp->Quant<<L" sản phẩm khác loại"<<endl;
                                                    wcout<<str;
                                                    system("pause");
                                                }
                                    
                                            else
                                                {
                                                    wcout<<"\t\t"<<str;
                                                    
                                                    wcout<<L"\t\t\t\t       Mời quý khách nhập thông tin order"<<endl;
                                                    wcout<<"\t\t"<<str;
                                    
                                                    for(int i=0;i<Tempp->X;i++)
                                                        {
                                                            
                                                            wcout<<str1<<endl;
                                                            wcout<<L"   ID  "
                                                                <<L"\t|\tTên Laptop"
                                                                <<L"\t|\t  CPU\t"
                                                                <<L"\t|\tRAM"
                                                                <<L"\t|\tROM"
                                                                <<L"\t|\t   Giá      "
                                                                <<L"\t|   SL\t |"<<endl;
                                                            wcout<<str1<<endl;
                                                            
                                                            int Q= Temp-> Quant;

                                                            for(int i=0;i<Q;i++)
                                                                {
                                                                    wcout<<L"   ";
                                                                    wcout<<Temp->ID[i]
                                                                    <<"\t\t"
                                                                    <<Temp->Computer_Name[i]
                                                                    <<"\t\t"
                                                                    <<Temp->CPU[i]
                                                                    <<"\t\t"
                                                                    <<Temp->RAM[i]
                                                                    <<"\t     "
                                                                    <<Temp->ROM[i]
                                                                    <<"\t\t"
                                                                    <<Temp->Price_Computer[i]
                                                                    <<L".000.000 VND\t"
                                                                    <<"    "
                                                                    <<Temp->All[i]<<endl;
                                                                    wcout<<str2<<endl;
                                                                }
                                    
                                                            wcout<<L"\n\t\t\t\tNhập mã Laptop mà quý khách muốn mua : ";
                                                            wcin>>Temp->Menu2[i];
                                                            Tempp->Menu2[i]=Temp->Menu2[i];

                                                            int k;
                                                            for(int j=0;j<Temp->Quant;j++)  
                                                                if(Temp->ID[j]==Tempp->Menu2[i])
                                                                    {
                                                                        k=j;
                                                                        break;
                                                                    }
                                                            
                                                            wcout<<L"\t\t\t\t--------Thông tin Laptop mà bạn đã chọn--------"<<endl;
                                                            
                                                            wcout<<L"\t\t\t\tTên Laptop :  "<<Temp->Computer_Name[k]<<endl;
                                                            wcout<<L"\t\t\t\tCPU        :  "<<Temp->CPU[k]<<endl;
                                                            wcout<<L"\t\t\t\tRAM        :  "<<Temp->RAM[k]<<endl;
                                                            wcout<<L"\t\t\t\tROM        :  "<<Temp->ROM[k]<<endl;
                                                            wcout<<L"\t\t\t\tGiá        :  "<<Temp->Price_Computer[k]<<L".000.000 VND"<<endl;
                                                            
                                                            wcout<<L"\t\t\t\tSố lượng mà quý khách muốn mua: ";
                                                            wcin>>Tempp->Quantity[i];
                                    
                                                            if(Tempp->Quantity[i] > Temp->All[k])
                                                                {
                                                                    wcout<<"\t\t"<<str;
                                                                    wcout<<L"\t\t\t\tXin lỗi quý khách,hiện tại cửa hàng chỉ còn lại "
                                                                        <<Temp->All[k]
                                                                        <<L" Laptop."<<endl;
                                                                    
                                                                    system("pause");
                                                                    return;
                                                                }
                                    
                                                            Temp->All[k]-=Tempp->Quantity[i];
                                    
                                                            Tempp->Amount[i]=Temp->Price_Computer[k]*Tempp->Quantity[i];
                                                            wcout<<L"\t\t\t\tSố tiền mà quý khách cần trả là : "<<Tempp->Amount[i]<<L".000.000 VND";
                                                            
                                                            wcout<<endl;
                                                            wcout<<str;
                                                            system("pause");
                                                            system("cls");
                                                        }
                                                        
                                                    Tempp=Tempp->PNext;
                                                    system("cls");
                                                }
                                    }
                                    
                                wcout<<L"\n\t\t\t\t==========================================================================\n";
                                wcout<<L"\t\t\t\t                 Sửa thông tin đơn hàng thành công!!!"<<endl;
                                wcout<<L"\t\t\t\t==========================================================================\n";
                                wcout<<L"\t\t\t\t       Quý khách đến quầy thanh toán để thanh toán hóa đơn và nhận hàng";
                                wcout<<L"\n\t\t\t\t==========================================================================\n";
                                
                                system("pause");

                            }
                        //Nhập sai mã đơn hàng => không thấy đơn hàng
                        else
                            {
                                wcout<<L"\n\t\t\t\t===============================\n";
                                wcout<<L"\t\t\t\t   Không tìm thấy mã khách hàng"<<endl;
                                wcout<<L"\t\t\t\t===============================\n";

                                system("pause");
                                return;
                            }
                    
            }
    }

#endif /* CFE32516_DB4E_4ED1_823A_C1A430C7AA7B */
