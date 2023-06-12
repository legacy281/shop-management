#ifndef EA487599_F423_4AAE_9C6C_A3ABCEE24BE1
#define EA487599_F423_4AAE_9C6C_A3ABCEE24BE1
//Thanh đoán đơn hàng 
void Computer_Store::Pay()
    {
        int num;
        bool Found=FALSE;
        
        wstring str=L"\t\t==============================================\n";
        
        system("cls");

        Head();

        Set_Color(1 << 8 | 0 << 7 | 6);
        
        Node *Tempp=Start_Ptr;
        
        //Không có đơn hàng trong Kho
        if(Tempp == NULL)
            {
                wcout<<endl<<"\t\t"<<str;
                wcout<<"\t\t"<<L"\t\t\t Danh sách order đang trống!!!\n";
                wcout<<"\t\t"<<str<<endl;
            }  
            
        else
            {
                //Nhập mã đơn hàng cần thanh toán
                wcout<<L"\n Nhập mã đơn hàng cần thanh toán: ";
                wcin>>num;
                wcout<<"\n";
                
                while(Tempp !=NULL && !Found)
                    {
                        if(Tempp->Receipt_Number == num)
                            Found=true;
                        
                        else
                            Tempp=Tempp->PNext;
                    }        
                        if(Found)
                            {
                                wcout<<L"\t\t========================================================================"<<endl;
                                wcout<<L"\t\t\t\t\t Thông tin đơn hàng thanh toán\n";
                                wcout<<L"\t\t========================================================================\n"<<endl;
                                
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
                                        wcout<<L"|     "<<Tempp->Computer_Name[i]
                                            <<L"\t       "<<Tempp->CPU[i]
                                            <<L"\t   "<<Tempp->RAM[i]
                                            <<L"\t\t"<<Tempp->ROM[i]
                                            <<L"\t"<<Tempp->Quantity[i]
                                            <<L"\t"<<Tempp->Amount[i]
                                            <<L".000.000 VND"
                                            <<endl;
                                            
                                        wcout<<L"|======================|======================|=============|===============|========|========================|"<<endl;
                                        
                                        Tempp->Total+= Tempp->Amount[i];
                                    }
                                Temp->Revenue += Tempp->Total;
                                
                                wcout<<L"\n Tổng tiền quý khách phải thanh toán: "<<Tempp->Total<<".000.000 VND"<<endl;

                                float Money;
                                wcout<<L"Tiền khách đưa (Triệu đồng) : ";
                                wcin>>Money;
                                
                                wcout<<L"Tiền trả lại khách : "<<Money-Tempp->Total<<".000.000 VND"<<endl;

                                wcout<<L"\n\n";
                                wcout<<L"\t\t\tCảm ơn quý khách đã mua hàng tại cửa hàng ♥♥♥"<<endl;
                                wcout<<L"\t\t\t-----------------------------------------------"<<endl;
                            }
                    
                    
                if(!Found)
                    {
                        wcout<<str;
                        wcout<<L"\t\t\t Không tìm thấy mã đơn hàng"<<endl;
                        wcout<<str<<endl;
                    }
            }

        system("pause");
    }

#endif /* EA487599_F423_4AAE_9C6C_A3ABCEE24BE1 */
