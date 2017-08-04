#include "entitiesfxs.h"



EntitiesFxs::EntitiesFxs()
{

}

QString EntitiesFxs::getCode()
{
    for(int i=0;i<9;i++)
    {
    int r=gen_ch();
    if (i==4)
        code+='-';
    else
        code+=r;
    }
    return code;
}

int EntitiesFxs::gen_ch()
{
    int ch;
    ch=0x67+qrand()%((0x7a+1)-0x67); //donde 0x67 es g y 0x7a es z; la formula es [ m + rand()%((n+1)-m) ] donde m es inicial y n final.
    return ch;
}
