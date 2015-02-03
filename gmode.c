#define INCL_VIO
#define INCL_NOPM
#include <os2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
        VIOMODEINFO old_vmi,new_vmi,info_vmi;
        APIRET rc;
        old_vmi.cb     = sizeof(old_vmi);
        VioGetMode(&old_vmi, 0);

        memset(&new_vmi, 0, sizeof(new_vmi));
        new_vmi.cb     = 12;
        new_vmi.fbType = 3;
        new_vmi.color  = 8; //16 colors
        new_vmi.col    = 80;
        new_vmi.row    = 25;
        new_vmi.hres   = 640;
        new_vmi.vres   = 400;
        rc = VioSetMode(&new_vmi, 0);
        if(rc==0) {
                info_vmi.cb=sizeof(info_vmi);
                VioGetMode(&info_vmi, 0);

                VioSetMode(&old_vmi, 0);

                printf("info_vmi.cb              = %d\n",     info_vmi.cb             );
                printf("info_vmi.fbType          = %d\n",     info_vmi.fbType         );
                printf("info_vmi.color           = %d\n",     info_vmi.color          );
                printf("info_vmi.col             = %d\n",     info_vmi.col            );
                printf("info_vmi.row             = %d\n",     info_vmi.row            );
                printf("info_vmi.hres            = %d\n",     info_vmi.hres           );
                printf("info_vmi.vres            = %d\n",     info_vmi.vres           );
                printf("info_vmi.fmt_ID          = %d\n",     info_vmi.fmt_ID         );
                printf("info_vmi.attrib          = %d\n",     info_vmi.attrib         );
                printf("info_vmi.buf_addr        = %08lX\n",  info_vmi.buf_addr       );
                printf("info_vmi.buf_length      = %ld\n",    info_vmi.buf_length     );
                printf("info_vmi.full_length     = %ld\n",    info_vmi.full_length    );
                printf("info_vmi.partial_length  = %ld\n",    info_vmi.partial_length );
                printf("info_vmi.ext_data_addr   = %p\n",     info_vmi.ext_data_addr  );

                return 0;
        } else {
                printf("Could not switch to that mode\n");
                return 1;
        }
}


