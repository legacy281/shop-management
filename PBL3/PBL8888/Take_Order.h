#ifndef B9A5CA72_66A3_4FA5_980D_7513DA4A47BA
#define B9A5CA72_66A3_4FA5_980D_7513DA4A47BA

#include "Set_Color.h"
#include "Head.h"
//Tạo đơn hàng
void Computer_Store::Take_Order()
    {

        system("cls");

        wstring str1=L"**************************************************************************************************************************";
        wstring str2=L"|--------|-----------------------|-----------------------|---------------|---------------|-----------------------|-------|";

        Head();

        wstring str=L"--------------------------------------------------------------------------------------------------------------\n";
        
        wcout<<str;

        Node *Tempp;
        Tempp=new Node;

        Set_Color(1 << 8 | 0 << 10 | 6);
        
        //Nhập thông tin đơn hàng
        fflush(stdin);
        wcout<<L"Mã đơn hàng (Só điện thoại của quý khách): ";
        wcin>>Tempp->Receipt_Number;
        
        fflush(stdin);
        wcout<<L"Tên Khách Hàng: ";
        getline(wcin,Tempp->Customer_Name);

        fflush(stdin);
        wcout<<L"Ngày mua: ";
        wcin>>Tempp->Date;

        wcout<<str;

        wcout<<str1<<endl;
        //Xuất danh sách Laptop trong kho
        wcout<<L"   ID  "
             <<L"\t|\tTên Laptop"
             <<L"\t|\t  CPU\t"
             <<L"\t|\tRAM"
             <<L"\t|\tROM"
             <<L"\t|\t   Giá      "
             <<L"\t|   SL\t |"<<endl;

             wcout<<str1<<endl;

            int Q = Temp-> Quant;

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
                        <<L"    "
                        <<Temp->All[i]<<endl;
                        wcout<<str2<<endl;
                    }
        //Chọn số, loại Laptop muốn mua
        wcout<<L"Số loại Laptop mà bạn muốn mua"<<endl
            <<L"Tối đa bạn có thể mua "<<Temp->Quant<<L" loại khác nhau: ";
        wcin>>Tempp->X;
        
        if(Tempp->X<0)
            {
                wcout<<L"Không thể thực hiện thủ tục order vì số lượng bạn order nhỏ hơn 0"<<endl;
                wcout<<str;
                system("pause");
            }
            
        else if(Tempp->X>Temp->Quant)
            {
                wcout<<L"Xin lỗi quý khách,hiện tại Cửa Hàng chỉ có tối đa "<<Temp->Quant<<L" sản phẩm khác loại"<<endl;
                wcout<<str;
                system("pause");
            }

        else
            {
                wcout<<str;
                
                wcout<<L"\t\t\t\t       Mời quý khách nhập thông tin order"<<endl;
                wcout<<str;

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
                                <<L"    "
                                <<Temp->All[i]<<endl;
                                wcout<<str2<<endl;
                            }

                        wcout<<L"\nNhập mã Laptop mà quý khách muốn mua : ";
                        wcin>>Temp->Menu2[i];
                        Tempp->Menu2[i]=Temp->Menu2[i];

                        int k;
                        for(int j=0;j<Temp->Quant;j++)  
                            if(Temp->ID[j]==Temp->Menu2[i])
                                {
                                    k=j;
                                    break;
                                }
                        
                        wcout<<L"--------Thông tin Laptop mà bạn đã chọn--------"<<endl;
                        
                        wcout<<L"Tên Laptop :  "<<Temp->Computer_Name[k]<<endl;
                        wcout<<L"CPU        :  "<<Temp->CPU[k]<<endl;
                        wcout<<L"RAM        :  "<<Temp->RAM[k]<<endl;
                        wcout<<L"ROM        :  "<<Temp->ROM[k]<<endl;
                        wcout<<L"Giá        :  "<<Temp->Price_Computer[k]<<L".000.000 VND"<<endl;
                        
                        //Tempp: Lưu lại dữ liệu máy tính của các loại máy tính trong 1 đơn hàng
                        Tempp->Computer_Name[i]=Temp->Computer_Name[k];
                        Tempp->CPU[i]=Temp->CPU[k];
                        Tempp->RAM[i]=Temp->RAM[k];
                        Tempp->ROM[i]=Temp->ROM[k];

                        wcout<<L"Số lượng mà quý khách muốn mua: ";
                        wcin>>Tempp->Quantity[i];

                        if(Tempp->Quantity[i] > Temp->All[k])
                            {
                                wcout<<str;
                                wcout<<L"Xin lỗi quý khách,hiện tại cửa hàng chỉ còn lại "
                                    <<Temp->All[k]
                                    <<L" Laptop."<<endl;
                                
                                system("pause");
                                return;
                            }

                        Temp->All[k]-=Tempp->Quantity[i];

                        Tempp->Amount[i]=Temp->Price_Computer[k]*Tempp->Quantity[i];
                        wcout<<L"Số tiền mà quý khách cần trả là : "<<Tempp->Amount[i]<<L".000.000 VND";
                        
                        wcout<<endl;
                        wcout<<str;
                        system("pause");
                        system("cls");
                    }
                wcout<<L"\n\t\t=======================================================================================\n";
                wcout<<L"\t\t                                  Order thành công....                           "<<endl;
                wcout<<L"\t\t=======================================================================================\n";
                wcout<<L"\t\t              Quý khách đến quầy thanh toán để thanh toán hóa đơn và nhận hàng          "<<endl;
                wcout<<L"\t\t=======================================================================================\n";
                system("pause");

                //Để trống Node đầu cho đơn hàng, Cấp phát vùng nhớ cho các đơn hàng tiếp theo
                Tempp->PNext=NULL;
                //Đưa con trỏ start trỏ đến đơn hàng hiện tại 
                if(Start_Ptr != NULL)
                    Tempp->PNext=Start_Ptr;
                
                Start_Ptr=Tempp;
            }
    }

#endif /* B9A5CA72_66A3_4FA5_980D_7513DA4A47BA */
