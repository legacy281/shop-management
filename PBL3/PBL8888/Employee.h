#ifndef D874FA30_322E_45DA_8589_B309ABBDAFDD
#define D874FA30_322E_45DA_8589_B309ABBDAFDD

#include "Check.h"
/*Thuộc tính Employee: Nhân viên
Có thể quản lý 
*/
void Computer_Store::Employee()
    {
        Set_Unicode();

        Computer_Store Computer;

        int Menu;

        Set_Color(1 << 8 | 0 << 10 | 6);

        Check();

        if(Temp->Pass==false)
            return;

        do
        {
            system("cls");

            Head();

            Set_Color(1 << 8 | 0 << 7 | 6);
            wcout<<L"\t\t\t\t   ============================================\n";
            wcout<<L"\t\t\t\t      WELCOME TO LAPTOP STORE AN NGỌC MẠNH ♥\n";
            wcout<<L"\t\t\t\t   ============================================\n";
            
            wcout<<L"\t\t\t\t-----------------------------------------------------\n";
            wcout<<L"\t\t\t\t||          1.Tạo đơn hàng cho khách                 ||"<<endl;
            wcout<<L"\t\t\t\t||          2.Xóa đơn hàng cho khách                 ||"<<endl;
            wcout<<L"\t\t\t\t||          3.Sửa đơn hàng cho khách                 ||"<<endl;
            wcout<<L"\t\t\t\t||          4.Xem đơn hàng cho khách                 ||"<<endl;
            wcout<<L"\t\t\t\t||          5.Xem toàn bộ đơn hàng                   ||"<<endl;
            wcout<<L"\t\t\t\t||          6.Thanh toán đơn hàng                    ||"<<endl;
            wcout<<L"\t\t\t\t||          7.Chỉnh sửa danh sách Laptop             ||"<<endl;
            wcout<<L"\t\t\t\t||          8.Doanh thu và đánh giá                  ||"<<endl;
            wcout<<L"\t\t\t\t||          9.Thay đổi mật khẩu                      ||"<<endl;
            wcout<<L"\t\t\t\t||          10.Thoát                                 ||"<<endl;
            wcout<<L"\t\t\t\t-----------------------------------------------------\n";

            wcout<<L"\t\t\t\tMời quý khách chọn lựa chọn: ";
            wcin>>Menu;

            switch(Menu)
                {
                    case 1: 
                        {
                            Computer.Take_Order();
                            break;
                        }

                    case 2: 
                        {
                            Computer.Delete_Order();
                            system("pause");
                            break;
                        }

                    case 3: 
                        {
                            Computer.Modify_Order();
                            break;
                        }
                    
                    case 4: 
                        {
                            Computer.Order_List();
                            system("pause");
                            break;
                        }

                    case 5: 
                        {
                            Computer.All_Order();
                            system("pause");
                            break;
                        }
                    
                    case 6: 
                        {
                            Computer.Pay();
                            break;
                        }
                    
                    case 7:
                        {
                            Computer.Change_Structure();
                            break;
                        }

                    case 8:
                        {
                            Computer.Revenue();
                            break;
                        }

                    case 9:
                        {
                            Computer.Change_Password();
                            break;
                        }

                    case 10:
                        {
                            wcout<<L"\t\t\t\t==========================================\n";
                            wcout<<L"\t\t\t\t      Cảm ơn bạn đã sử dụng dịch vụ        "<<endl;
                            wcout<<L"\t\t\t\t      Chúc bạn 1 ngày thật tốt lành ♥      "<<endl;
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
                        }
                }
            
        } while (Menu !=10);

    }

#endif /* D874FA30_322E_45DA_8589_B309ABBDAFDD */
