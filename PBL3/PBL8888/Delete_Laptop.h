#ifndef EB6372FE_EF3C_4966_98E4_18496AC35FE9
#define EB6372FE_EF3C_4966_98E4_18496AC35FE9
//Xóa Laptop trong kho hàng 
void Delete_Laptop() 
    {
        int N;
        wcout<<L"Số lượng Laptop bạn muốn xóa: ";
        wcin>>N;

        int Del[N+1];

        wcout<<L"Nhập danh sách ID[] Laptop bạn muốn xóa: "<<endl;

        for(int i=0;i<N;i++)
           {
                wcout<<i+1<<". ";
                wcin>>Del[i];
           }

        int Count = 0;
        for(int k=0;k<N;k++)
            {
                for(int i=0;i<Temp->Quant;i++)
                    if(Temp->ID[i]==Del[k])
                        {
                            for(int j=i;j<Temp->Quant;j++)  
                                {
                                    Temp->ID[j]=Temp->ID[j+1];
                                    Temp->Computer_Name[j]=Temp->Computer_Name[j+1];
                                    Temp->CPU[j]=Temp->CPU[j+1];
                                    Temp->RAM[j]=Temp->RAM[j+1];
                                    Temp->ROM[j]=Temp->ROM[j+1];
                                    Temp->Price_Computer[j]=Temp->Price_Computer[j+1];
                                    Temp->All[j]=Temp->All[j+1];
                                    Temp->Save[j]=Temp->All[j];
                                }

                            Temp->Quant--;
                            Count++;
                            break;
                        }
            }
        if(Count==N)
            {
                wcout<<"---------------------------------------------------"<<endl;
                wcout<<L"            Bạn đã xóa thành công!!"<<endl;
                wcout<<"------------------------------------------------"<<endl;
            }
        else
            {
                wcout<<"---------------------------------------------------"<<endl;
                wcout<<L"     Bạn đã xóa thành công "<<Count<<" Laptop!!"<<endl;
                wcout<<L"        Có "<<N-Count<<L" ID không tìm thấy!!"<<endl;
                wcout<<"---------------------------------------------------"<<endl;
            }
        system("pause");
    }

#endif /* EB6372FE_EF3C_4966_98E4_18496AC35FE9 */
