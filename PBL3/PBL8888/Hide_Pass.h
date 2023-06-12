#ifndef EE68D847_7D1A_4059_AEEB_4710AF9D02CF
#define EE68D847_7D1A_4059_AEEB_4710AF9D02CF

#include <conio.h>
#include <iostream>
using namespace std;
//Ẩn mật khẩu
enum IN
    {
        IN_BACK=8,
        IN_RET=13
    };

wstring Hide_Pass()
    {
        wstring Check=L"";
        char sp='*';
        char in_pass;
        
        while(true) 
            {
                in_pass=getch();

                if(in_pass== IN::IN_RET)
                    {
                        wcout<<endl;
                        return Check;
                    }

                else if(in_pass== IN::IN_BACK && Check.length() != 0)
                    {
                        Check.pop_back();
                        wcout<<"\b \b";
                        continue;
                    }
                
                else if(in_pass== IN::IN_BACK && Check.length()==0)
                    {
                        continue;
                    }

                Check.push_back(in_pass);
                wcout<<sp;
            }
    }

#endif /* EE68D847_7D1A_4059_AEEB_4710AF9D02CF */
