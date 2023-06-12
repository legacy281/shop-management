#ifndef FE455AB3_F0C0_4E6B_86C7_88627A18281D
#define FE455AB3_F0C0_4E6B_86C7_88627A18281D
//Thêm Laptop
void Add_Laptop()
    {
        int Add_L; 

        Head();

        Set_Color(1 << 8 | 0 << 10 | 6);
        //Nhập thông tin Laptop cần thêm
        wcout<<L"\t Số Laptop bạn muốn thêm : ";
        wcin>>Add_L;

        for(int i=0; i<Add_L; i++)
            {
                system("cls");

                wcout<<L"\t\t\t======================================="<<endl;
                wcout<<L"\t\t\t        Thêm Laptop vào danh sách"<<endl;
                wcout<<L"\t\t\t======================================="<<endl;

                wcout<<L"\t ID         : ";
                wcin>>Temp->ID[Temp->Quant];
                fflush(stdin);
                wcout<<L"\t Tên Laptop : ";
                getline(wcin,Temp->Computer_Name[Temp->Quant]);
                fflush(stdin);
                wcout<<L"\t CPU        : ";
                getline(wcin,Temp->CPU[Temp->Quant]);
                fflush(stdin);
                wcout<<L"\t RAM        : ";
                getline(wcin,Temp->RAM[Temp->Quant]);
                fflush(stdin);
                wcout<<L"\t ROM        : ";
                getline(wcin,Temp->ROM[Temp->Quant]);
                fflush(stdin);
                wcout<<L"\t Price      : ";
                wcin>>Temp->Price_Computer[Temp->Quant];
                wcout<<L"\t SL         : ";
                wcin>>Temp->All[Temp->Quant];
                //Cập nhập lại vào Mảng Save: Lưu số lượng ban đầu để đánh giá
                Temp->Save[Temp->Quant]=Temp->All[Temp->Quant];

                //Thêm số lượng máy hiện tại
                Temp->Quant=Temp->Quant+1;

                wcout<<L"\t\t\t"<<endl;
                wcout<<L"\t\t\t Thêm Laptop thành công !!!"<<endl;
                wcout<<L"\t\t\t----------------------------------------------------"<<endl;
                system("Pause");
            }
    }

#endif /* FE455AB3_F0C0_4E6B_86C7_88627A18281D */
