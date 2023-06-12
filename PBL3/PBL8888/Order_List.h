#ifndef D9795C9C_1461_49E2_93B7_0C8E9D83A8AF
#define D9795C9C_1461_49E2_93B7_0C8E9D83A8AF

#include "Set_Color.h"
#include "Head.h"
//Xem 1 đơn hàng của khách hàng
void Computer_Store::Order_List()
    {
        int num;
        bool Found=FALSE;
        
        wstring str=L"\t\t==============================================\n";
        
        system("cls");

        Head();

        Set_Color(1 << 8 | 0 << 7 | 6);
        
        Node *Tempp=Start_Ptr;
        //Không có đơn hàng
        if(Tempp == NULL)
            {
                wcout<<endl<<"\t\t"<<str;
                wcout<<L"\t\t\t\t\t Danh sách order đang trống!!!\n";
                wcout<<"\t\t"<<str<<endl;
            }  
            
        else
            {
                //Nhập mã đơn hàng cần xem
                wcout<<L"\n\t\t\t\t Nhập mã đơn hàng cần in: ";
                wcin>>num;
                wcout<<"\n";
                
                while(Tempp !=NULL && !Found)
                    {
                        if(Tempp->Receipt_Number == num)
                            Found=true;
                        
                        else
                            Tempp=Tempp->PNext;
                    }        
                    //Nếu tìm thấy đơn hàng cần xem
                        if(Found)
                            {
                                wcout<<L"\t\t\t========================================================================"<<endl;
                                wcout<<L"\t\t\t\t\t\t Thông tin đơn hàng cần xem\n";
                                wcout<<L"\t\t\t========================================================================\n"<<endl;
                                
                                wcout<<L"Mã đơn hàng: "
                                    <<Tempp->Receipt_Number<<endl;
                                wcout<<L"Tên khách hàng: "
                                    <<Tempp->Customer_Name<<endl;
                                wcout<<L"Ngày mua hàng: "
                                    <<Tempp->Date<<endl
                                    <<endl;
                                    
                                wcout<<L"==============================================================================================================="<<endl;
                                wcout<<L"|      Tên Laptop      |          CPU         |     RAM     |      ROM      |   SL   |        Tổng giá        |"<<endl;
                                wcout<<L"|======================|======================|=============|===============|========|========================|"<<endl;
                                
                                for(int i=0;i<Tempp->X;i++)
                                    {
                                        wcout<<L"|      "<<Tempp->Computer_Name[i]
                                            <<L"\t     "<<Tempp->CPU[i]
                                            <<L"\t   "<<Tempp->RAM[i]
                                            <<L"\t\t"<<Tempp->ROM[i]
                                            <<L"\t"<<Tempp->Quantity[i]
                                            <<L"\t"<<Tempp->Amount[i]
                                            <<L".000.000 VND"
                                            <<endl;
                                            
                                        wcout<<L"|======================|======================|=============|===============|========|========================|"<<endl;
                                        
                                    }
                                
                            }
                    
                // Không tìm thấy đơn hàng cần xem
                if(!Found)
                    {
                        wcout<<"\t\t"<<str;
                        wcout<<"\t\t"<<L"\t\t\t Không tìm thấy mã đơn hàng"<<endl;
                        wcout<<"\t\t"<<str<<endl;
                    }
            }
    }

#endif /* D9795C9C_1461_49E2_93B7_0C8E9D83A8AF */
