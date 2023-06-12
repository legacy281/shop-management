#ifndef FE0D6F61_CF5C_4D98_ACE1_D64276193545
#define FE0D6F61_CF5C_4D98_ACE1_D64276193545

#include "Set_Color.h"
#include "Head.h"
//Xem toàn bộ các đơn hàng
void Computer_Store::All_Order()
    {
        int num;
        bool Found=FALSE;
        
        wstring str=L"\t\t==============================================\n";
        
        system("cls");

        Head();

        Set_Color(1 << 8 | 0 << 7 | 6);
        
        Node *Tempp=Start_Ptr;
        
        if(Tempp == NULL)
            {
                wcout<<endl<<"\t\t  "<<str;
                wcout<<"\t\t"<<L"\t\t\t Danh sách order đang trống!!!\n";
                wcout<<"\t\t  "<<str<<endl;
            }  
        else
            {
                wcout<<L"\t\t========================================================================"<<endl;
                wcout<<L"\t\t\t\t Danh sách đơn hàng đã mua trong ngày\n";
                wcout<<L"\t\t========================================================================\n"<<endl;

                while(Tempp != NULL )
                    {
                        wcout<<"\n\n"<<endl;
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
                                    <<L"\t     "<<Tempp->CPU[i]
                                    <<L"\t   "<<Tempp->RAM[i]
                                    <<L"\t\t"<<Tempp->ROM[i]
                                    <<L"\t"<<Tempp->Quantity[i]
                                    <<L"\t"<<Tempp->Amount[i]
                                    <<L".000.000 VND"
                                    <<endl;
                                            
                                wcout<<L"|======================|======================|=============|===============|========|========================|"<<endl;
                                    
                            }

                            Tempp=Tempp->PNext;
                    }
            }
    }
#endif /* FE0D6F61_CF5C_4D98_ACE1_D64276193545 */
