#ifndef BC2B2F9E_4D7E_46AC_A682_58EAE5B3A3A7
#define BC2B2F9E_4D7E_46AC_A682_58EAE5B3A3A7

#include "Set_Color.h"
#include "Head.h"
//XÓa đơn hàng 
void Computer_Store::Delete_Order()
    {
        system("cls");

        Head();

        Set_Color(1 << 8 | 0 << 7 | 6);

        int num;
        //Không có đơn hàng cần xóa 
        wstring str=L"\t\t\t\t=======================================================\n";
        if(Start_Ptr == NULL)
            {
                wcout<<endl;
                wcout<<str;
                wcout<<L"\t\t\t\t    Không thể xóa vì danh sách đơn hàng đang rỗng !!!\n";
                wcout<<str;
                wcout<<endl;
            }
        else 
            {
                //Bắt đầu chọn đơn hàng muốn xóa trong Cửa hàng
                wcout<<L"\n\t\t\t\t Nhập mã đơn hàng mà bạn muốn xóa : ";
                wcin>>num;

                bool Found=FALSE;
                
                if(Start_Ptr->Receipt_Number == num)                   
                    {

                        P=Start_Ptr;
                        Start_Ptr=Start_Ptr->PNext;
                        
                        if(Start_Ptr==NULL)
                            PTail=NULL;
                            
                        delete P;
                        
                        wcout<<L"\n\t\t\t\t =========================================\n";
                        wcout<<L"\t\t\t\t           Xóa đơn hàng thành công!!! ";
                        wcout<<L"\n\t\t\t\t =========================================\n";
                        
                    }
                
                else 
                    {

                        Tempp=Start_Ptr;
                        P=Start_Ptr->PNext;
                        
                        while( (!Found) && (P != NULL))
                            {
                                if(P->Receipt_Number != num)
                                    {
                                        Tempp = P;
                                        P=P->PNext;
                                    }
                                
                                else 
                                    Found =true;
                            }
                        
                        if( Found )
                            {

                                Tempp->PNext=P->PNext;

                                if(PTail == P)
                                    PTail=Tempp;
                                delete P;
                                
                                wcout<<L"\n\t\t\t\t =========================================\n";
                                wcout<<L"\t\t\t\t           Xóa đơn hàng thành công!!! ";
                                wcout<<L"\n\t\t\t\t =========================================\n";

                            }
                        
                        //Nếu không tìm thấy đơn hàng => Found = False =>
                        else 
                            {
                                wcout<<L"\n\t\t\t\t ==========================================\n";
                                wcout<<L"\t\t\t\t    Không tìm thấy đơn hàng cần xóa";
                                wcout<<L"\n\t\t\t\t ===========================================\n";
                            }
                    }
            }
    }

#endif /* BC2B2F9E_4D7E_46AC_A682_58EAE5B3A3A7 */
