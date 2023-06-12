#ifndef CC1DBA71_2BF8_4B70_893E_E3503B548656
#define CC1DBA71_2BF8_4B70_893E_E3503B548656
#include "Add_Laptop.h"
#include "Change_Quantity.h"
#include "Delete_Laptop.h"
//Thay đổi kho hàng
void Computer_Store::Change_Structure()
    {
        system("cls");

        wstring str1=L"**************************************************************************************************************************";
        wstring str2=L"|--------|-----------------------|-----------------------|---------------|---------------|-----------------------|-------|";

        Head();

        wstring str=L"--------------------------------------------------------------------------------------------------------------\n";
        
        wcout<<str;

        Set_Color(1 << 8 | 0 << 10 | 6);
        //Xuất danh sách Laptop
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
        
        wcout<<endl;
        wcout<<L"\t\t\t\t               Bạn muốn sửa  "<<endl;
        wcout<<L"\t\t\t\t ------------------------------------------"<<endl;
        wcout<<L"\t\t\t\t ||    1.Thay đổi số lượng Laptop đã có  ||"<<endl;
        wcout<<L"\t\t\t\t ||    2.Thêm Laptop vào danh sách       ||"<<endl;
        wcout<<L"\t\t\t\t ||    3.Xóa Laptop                      ||"<<endl;
        wcout<<L"\t\t\t\t ------------------------------------------ "<<endl;
        wcout<<L"\t\t\t\t       Lựa chọn của bạn : ";

        int Choice;

        wcin>>Choice;

        switch(Choice)
            {
                case 1: 
                    {
                        Change_Quantity();  
                        break;
                    }

                case 2: 
                    {
                        Add_Laptop();
                        break;
                    }

                case 3: 
                    {
                        Delete_Laptop();
                    }

                default:
                    {
                        wcout<<L"\t Bạn đã nhập sai tùy chọn.Trở lại Menu chính và thao tác lại"<<endl;+
                        system("pause");
                    }

            }
    }

#endif /* CC1DBA71_2BF8_4B70_893E_E3503B548656 */
