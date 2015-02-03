#define INCL_VIO
#define INCL_NOPM
#define INCL_DOSPROCESS
#include <os2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(void)
{
        VIOMODEINFO old_vmi,new_vmi,info_vmi;
        APIRET rc;
        old_vmi.cb     = sizeof(old_vmi);
        VioGetMode(&old_vmi, 0);

        memset(&new_vmi, 0, sizeof(new_vmi));
        new_vmi.cb     = 12;
        new_vmi.fbType = 013;
        new_vmi.color  = 16; //64K colors
        new_vmi.col    = 80;
        new_vmi.row    = 30;
        new_vmi.hres   = 640;
        new_vmi.vres   = 480;
        rc = VioSetMode(&new_vmi, 0);
        if(rc==0) {
                info_vmi.cb=sizeof(info_vmi);
                VioGetMode(&info.vmi, 0);

                VioSetMode(&old_vmi, 0);

      printf("om.cb              = %d\n", om.cb             );
     printf("om.fbType          = %d\n", om.fbType         );
     printf("om.color           = %d\n", om.color          );
     printf("om.col             = %d\n", om.col            );
     printf("om.row             = %d\n", om.row            );
     printf("om.hres            = %d\n", om.hres           );
     printf("om.vres            = %d\n", om.vres           );
     printf("om.fmt_ID          = %d\n", om.fmt_ID         );
     printf("om.attrib          = %d\n", om.attrib         );
     printf("om.buf_addr        = %Fp\n", om.buf_addr       );
     printf("om.buf_length      = %ld\n", om.buf_length     );
     printf("om.full_length     = %ld\n", om.full_length    );
     printf("om.partial_length  = %ld\n", om.partial_length );
     printf("om.ext_data_addr   = %Fp\n", om.ext_data_addr  );
        } else {
                printf("could not switch to that mode\n");
        }
}


