#ifndef D1ED6DA8_8A34_4C3A_810D_87B13CFC7DC4
#define D1ED6DA8_8A34_4C3A_810D_87B13CFC7DC4

//Hỗ trợ nhập, xuất tiếng Việt
void Set_Unicode() 
    {
        _setmode(_fileno(stdin), _O_U16TEXT);
        _setmode(_fileno(stdout), _O_U16TEXT);
    }

#endif /* D1ED6DA8_8A34_4C3A_810D_87B13CFC7DC4 */
