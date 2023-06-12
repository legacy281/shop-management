#ifndef E1B46C84_51AB_4717_B9F7_461F663E02F2
#define E1B46C84_51AB_4717_B9F7_461F663E02F2
/*Thuộc tính Customer: Khách hàng
Khách hàng chỉ quản lý được đơn hàng
*/
void Computer_Store::Customer()
    {
        Set_Unicode();

        Computer_Store Computer;

        int Menu;

        do
        {
            system("cls");

            Head();

            Set_Color(1 << 8 | 0 << 7 | 6);
            wcout<<L"\t\t\t\t============================================\n";
            wcout<<L"\t\t\t\t   WELCOME TO LAPTOP STORE AN NGỌC MẠNH ♥\n";
            wcout<<L"\t\t\t\t============================================\n";
            
            wcout<<L"\t\t\t\t---------------------------------------------\n";
            wcout<<L"\t\t\t\t||          1.Tạo đơn hàng                  ||"<<endl;
            wcout<<L"\t\t\t\t||          2.Xóa đơn hàng                  ||"<<endl;
            wcout<<L"\t\t\t\t||          3.Sửa đơn hàng                  ||"<<endl;
            wcout<<L"\t\t\t\t||          4.Xem đơn hàng                  ||"<<endl;
            wcout<<L"\t\t\t\t||          5.Thoát                         ||"<<endl;
            wcout<<L"\t\t\t\t---------------------------------------------\n";
    
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
                            wcout<<L"\t\t\t\t==========================================\n";
                            wcout<<L"\t\t\t\t Cảm ơn quý khách đã mua hàng tại của hàng"<<endl;
                            wcout<<L"\t\t\t\t  Chúc quý khách 1 ngày thật tốt lành ♥"<<endl;
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
            
        } while (Menu !=5);

    }

#endif /* E1B46C84_51AB_4717_B9F7_461F663E02F2 */
