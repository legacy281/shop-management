#include "Header.h"
#include "Class.h"
#include "Structure.h"
#include "Take_Order.h"
#include "Modify_order.h"
#include "Delete_order.h"
#include "Order_List.h"
#include "Set_Unicode.h"
#include "Customer.h"
#include "Employee.h"
#include "Head.h"
#include "Change_Structure.h"
#include "Change_Quantity.h"
#include "Add_Laptop.h"
#include "Delete_Laptop.h"
#include "Pay.h"
#include "All_Order.h"
#include "Revenue.h"
#include "Change_Password.h"
#include "Hide_Pass.h"

int main()
    {
        Set_Unicode();

        Computer_Store Computer;

        int Start;

        do
        {
            system("cls");

            Head();

            Set_Color(1 << 8 | 0 << 7 | 6);
            wcout<<L"\t\t\t\t============================================\n";
            wcout<<L"\t\t\t\t   WELCOME TO LAPTOP STORE AN NGỌC MẠNH ♥\n";
            wcout<<L"\t\t\t\t============================================\n";

            wcout<<L"\t\t\t\t---------------------------------------------\n";
            wcout<<L"\t\t\t\t||          1.Nhân viên                     ||"<<endl;
            wcout<<L"\t\t\t\t||          2.Khách hàng                    ||"<<endl;
            wcout<<L"\t\t\t\t||          3.Thoát                         ||"<<endl;
            wcout<<L"\t\t\t\t---------------------------------------------\n";
            
            wcout<<L"\t\t\t\tBạn là: ";
            wcin>>Start;
            
            switch(Start)
                {
                    case 1: 
                        {
                            Computer.Employee();
                            break;
                        }

                    case 2: 
                        {
                            Computer.Customer();
                            system("Pause");
                            break;
                        }

                    case 3:
                        {
                            wcout<<L"\t\t\t\t==========================================\n";
                            wcout<<L"\t\t\t\t      Cảm ơn bạn đã sử dụng dịch vụ        "<<endl;
                            wcout<<L"\t\t\t\t     Chúc bạn 1 ngày thật tốt lành ♥       "<<endl;
                            wcout<<L"\t\t\t\t==========================================\n";
                            system("pause");
                            break;
                        }

                    default:   
                        {
                            wcout<<endl<<endl;
                            wcout<<L"\t\t\t\t Không có tùy chọn mà bạn đã nhập\n";
                            wcout<<L"\t\t\t\t      Xin vui lòng nhập lại!!!";
                            wcout<<endl;
                            system("pause");
                            break;
                        }
                }

        }while(Start != 3);

        return 0;
    }