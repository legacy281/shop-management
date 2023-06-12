#ifndef EFCF0CB9_5BE9_4C92_9C97_36493D2D51C3
#define EFCF0CB9_5BE9_4C92_9C97_36493D2D51C3
#include<bits/stdc++.h>
using namespace std;

//Cập nhập lại số lượng Laptop sau khi sửa đơn hàng
void Resume(int Mod)
    {
        bool Found = false;

        while(Tempp !=NULL && !Found)
            {

                if(Tempp->Receipt_Number == Mod)
                    Found=true;                   
                else 
                    Tempp=Tempp->PNext;
            }

        for(int i=0;i<Tempp->X;i++)
            {

                int k;

                for(int j=0;j<Temp->Quant;j++)  
                    if(Temp->ID[j]==Tempp->Menu2[i])
                            {
                                k=j;
                                break;
                            }

                Temp->All[k]+=Tempp->Quantity[i];
            }
    }

#endif /* EFCF0CB9_5BE9_4C92_9C97_36493D2D51C3 */
