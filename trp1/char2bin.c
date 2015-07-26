#include<stdio.h>
void char2bin(unsigned char uc, char *sbin)
{
    union u
    {
       unsigned char uc;
       struct
       {
          unsigned char b0:1;
          unsigned char b1:1;
          unsigned char b2:1;
          unsigned char b3:1;
          unsigned char b4:1;
          unsigned char b5:1;
          unsigned char b6:1;
          unsigned char b7:1;
       } bits;
    }  u;

    u.uc = uc;
    sbin[0] = '0' + u.bits.b7;
    sbin[1] = '0' + u.bits.b6;
    sbin[2] = '0' + u.bits.b5;
    sbin[3] = '0' + u.bits.b4;
    sbin[4] = '0' + u.bits.b3;
    sbin[5] = '0' + u.bits.b2;
    sbin[6] = '0' + u.bits.b1;
    sbin[7] = '0' + u.bits.b0;
    sbin[8] = 0;    // terminate with 0
}
void main()
{
	char ch=65,sbin[9];
	char2bin(ch,sbin);
	printf("%s",sbin);

}
