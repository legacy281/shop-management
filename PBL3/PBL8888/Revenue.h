#ifndef C09FDDF6_33F4_4249_9148_9F347DA8E150
#define C09FDDF6_33F4_4249_9148_9F347DA8E150

//Tính doanh thu và đánh giá việc kinh doanh của Cửa hàng
void Computer_Store::Revenue()
    {

        int Min=50;
        int Max=0;
        int in,ax,Count=0;
        system("cls");


        wstring strr=L"\t\t\t\t=======================================================\n";
        if(Start_Ptr == NULL)
            {
                wcout<<endl;
                wcout<<strr;
                wcout<<L"\t\t\t\t    Không thể thống kê vì chưa bán Laptop nào !!!\n";
                wcout<<strr;
                wcout<<endl;
                system("Pause");
                return ;
            }

        wstring str1=L"**************************************************************************************************************************";
        wstring str2=L"|--------|-----------------------|-----------------------|---------------|---------------|-----------------------|-------|";

        wstring str=L"--------------------------------------------------------------------------------------------------------------\n";

        Head();

        Set_Color(1 << 8 | 0 << 10 | 6);

        wcout<<str;

        wcout<<str1<<endl;
        
        wcout<<L"   ID  "
             <<L"\t|\tTên Laptop"
             <<L"\t|\t  CPU\t"
             <<L"\t|\tRAM"
             <<L"\t|\tROM"
             <<L"\t|\t   Giá      "
             <<L"\t|  Đã bán|"<<endl;

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
                        <<Temp->Save[i]-Temp->All[i]<<endl;
                        wcout<<str2<<endl;
                    }

        for(int i=0;i<Temp->Quant;i++)
            {
                if(Temp->Save[i]-Temp->All[i]>0)
                    {
                        if(Min>Temp->Save[i]-Temp->All[i])
                            {
                                Min=Temp->Save[i]-Temp->All[i];
                                in=i;
                            }
                        if(Max<Temp->Save[i]-Temp->All[i])
                            {
                                Max=Temp->Save[i]-Temp->All[i];
                                ax=i;
                            }
                        Count++;
                    }
            }
        
        wcout<<L"Có "<<Temp->Quant-Count<<L" Laptop không bán được đơn hàng nào."<<endl;

        wcout<<L"Laptop bán được ít nhất "<<endl;
        wcout<<L"ID             : "<<Temp->ID[in]<<endl;
        wcout<<L"Tên Laptop     : "<<Temp->Computer_Name[in]<<endl;
        wcout<<L"CPU            : "<<Temp->CPU[in]<<endl;
        wcout<<L"RAM            : "<<Temp->RAM[in]<<endl;
        wcout<<L"ROM            : "<<Temp->ROM[in]<<endl;
        wcout<<L"Giá            : "<<Temp->Price_Computer[in]<<endl;
        wcout<<L"Số lượng đã bán: "<<Min<<endl<<endl<<endl;

        wcout<<L"Laptop bán được nhiều nhất "<<endl;
        wcout<<L"ID             : "<<Temp->ID[ax]<<endl;
        wcout<<L"Tên Laptop     : "<<Temp->Computer_Name[ax]<<endl;
        wcout<<L"CPU            : "<<Temp->CPU[ax]<<endl;
        wcout<<L"RAM            : "<<Temp->RAM[ax]<<endl;
        wcout<<L"ROM            : "<<Temp->ROM[ax]<<endl;
        wcout<<L"Giá            : "<<Temp->Price_Computer[ax]<<endl;
        wcout<<L"Số lượng đã bán: "<<Max<<endl<<endl<<endl;

        wcout<<L"Doanh thu : "<<Temp->Revenue<<L".000.000 VND "<<endl;

        system("pause");
        
    }

#endif /* C09FDDF6_33F4_4249_9148_9F347DA8E150 */
