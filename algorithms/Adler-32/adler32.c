#include <stdio.h>

#define BASE 65521 /* largest prime smaller than 65536 */

/*
   Update a running Adler-32 checksum with the bytes buf[0..len-1]
 and return the updated checksum. The Adler-32 checksum should be
 initialized to 1.

 Usage example:

   unsigned long adler = 1L;

   while (read_buffer(buffer, length) != EOF) {
     adler = update_adler32(adler, buffer, length);
   }
   if (adler != original_adler) error();
*/

unsigned long update_adler32(unsigned long adler, const unsigned char* buf, int len)
{
    unsigned long s1 = adler & 0xffff;
    unsigned long s2 = (adler >> 16) & 0xffff;
    int n;

    for (n = 0; n < len; n++)
    {
        s1 = (s1 + buf[n]) % BASE;
        s2 = (s2 + s1) % BASE;
    }

    return (s2 << 16) + s1;
}

/* Return the adler32 of the bytes buf[0..len-1] */

unsigned long adler32(const unsigned char* buf, int len)
{
    return update_adler32(1L, buf, len);
}

int main()
{
    const int len = 10;
    const unsigned char buf[] = {
    0xfe, 0x7c, 0x01, 0x02, 0x00, //
    0x23, 0xfe, 0x7c, 0x01, 0x02, //
    };

    printf("adler32: %lul", adler32(buf, len));
}