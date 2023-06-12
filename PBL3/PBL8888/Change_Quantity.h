#ifndef F7C33B19_32C9_41A4_91D4_B54202BCEE8E
#define F7C33B19_32C9_41A4_91D4_B54202BCEE8E
//Thay đổi số lượng Laptop trong kho 
void Change_Quantity()
    {
        int C_ID;

        Head();

        Set_Color(1 << 8 | 0 << 10 | 6);
        
        wstring str1=L"**************************************************************************************************************************";
        wstring str2=L"|--------|-----------------------|-----------------------|---------------|---------------|-----------------------|-------|";

        //Xuất danh sách laptop hiện tại
        wcout<<L"\t\t\t====================================================\n";
        wcout<<L"\t\t\t       Danh sách Laptop hiện đang có tại cửa hàng    "<<endl;
        wcout<<L"\t\t\t====================================================\n";

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
        //Bắt đầu thay đổi số lượng của ID được chọn
        wcout<<L"\t Mời bạn nhập ID Laptop cần thay đổi ";
        wcin>>C_ID;

        bool Found = false;

        for(int i=0;i<Q;i++)
            if(Temp->ID[i] == C_ID)
                {
                    wcout<<L"\t--------Thông tin Laptop mà bạn đã chọn--------"<<endl;
                                                            
                    wcout<<L"\tTên Laptop :  "<<Temp->Computer_Name[i]<<endl;
                    wcout<<L"\tCPU        :  "<<Temp->CPU[i]<<endl;
                    wcout<<L"\tRAM        :  "<<Temp->RAM[i]<<endl;
                    wcout<<L"\tROM        :  "<<Temp->ROM[i]<<endl;
                    wcout<<L"\tGiá        :  "<<Temp->Price_Computer[i]<<L".000.000 VND"<<endl;

                    wcout<<L"\t Bạn muốn thay đổi số lượng thành : ";
                    wcin>>Temp->All[i];
                    Temp->Save[i]=Temp->All[i];

                    system("cls");

                    wcout<<L"\t\t\t       Bạn đã thay đổi thành công số lượng Laptop "<<endl;
                    wcout<<L"\t\t\t------------------------------------------------------------------"<<endl;

                    system("pause");
                }
    }

#endif /* F7C33B19_32C9_41A4_91D4_B54202BCEE8E */
