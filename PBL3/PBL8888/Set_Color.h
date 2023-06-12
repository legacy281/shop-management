#ifndef EEB0C444_CB0B_4CFB_B258_62D948581E10
#define EEB0C444_CB0B_4CFB_B258_62D948581E10

//Giao diện màu
void Set_Color(int Code)
    {
        HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute( color , Code );
    }

#endif /* EEB0C444_CB0B_4CFB_B258_62D948581E10 */
