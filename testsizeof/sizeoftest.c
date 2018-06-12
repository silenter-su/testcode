/*
 * =====================================================================================
 *
 *       Filename:  sizeoftest.c
 *
 *    Description:  测试结构体数据大小.
 *
 *        Version:  1.0
 *        Created:  06/08/2018 06:04:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/* DNP3 application request function codes. */
#define DNP3_APP_FC_CONFIRM                0x00
#define DNP3_APP_FC_READ                   0x01
#define DNP3_APP_FC_WRITE                  0x02
#define DNP3_APP_FC_SELECT                 0x03
#define DNP3_APP_FC_OPERATE                0x04
#define DNP3_APP_FC_DIR_OPERATE            0x05
#define DNP3_APP_FC_DIR_OPERATE_NR         0x06
#define DNP3_APP_FC_FREEZE                 0x07
#define DNP3_APP_FC_FREEZE_NR              0x08
#define DNP3_APP_FC_FREEZE_CLEAR           0x09
#define DNP3_APP_FC_FREEZE_CLEAR_NR        0x0a
#define DNP3_APP_FC_FREEZE_AT_TIME         0x0b
#define DNP3_APP_FC_FREEZE_AT_TIME_NR      0x0c
#define DNP3_APP_FC_COLD_RESTART           0x0d
#define DNP3_APP_FC_WARM_RESTART           0x0e
#define DNP3_APP_FC_INITIALIZE_DATA        0x0f
#define DNP3_APP_FC_INITIALIZE_APPLICATION 0x10
#define DNP3_APP_FC_START_APPLICATION      0x11
#define DNP3_APP_FC_STOP_APPLICATION       0x12
#define DNP3_APP_FC_SAVE_CONFIGURATION     0x13
#define DNP3_APP_FC_ENABLE_UNSOLICITED     0x14
#define DNP3_APP_FC_DISABLE_UNSOLICTED     0x15
#define DNP3_APP_FC_ASSIGN_CLASS           0x16
#define DNP3_APP_FC_DELAY_MEASUREMENT      0x17
#define DNP3_APP_FC_RECORD_CURRENT_TIME    0x18
#define DNP3_APP_FC_OPEN_TIME              0x19
#define DNP3_APP_FC_CLOSE_FILE             0x1a
#define DNP3_APP_FC_DELETE_FILE            0x1b
#define DNP3_APP_FC_GET_FILE_INFO          0x1c
#define DNP3_APP_FC_AUTHENTICATE_FILE      0x1d
#define DNP3_APP_FC_ABORT_FILE             0x1e
#define DNP3_APP_FC_ACTIVATE_CONFIG        0x1f
#define DNP3_APP_FC_AUTH_REQ               0x20
#define DNP3_APP_FC_AUTH_REQ_NR            0x21

/* DNP3 application response function codes. */
#define DNP3_APP_FC_RESPONSE               0x81
#define DNP3_APP_FC_UNSOLICITED_RESP       0x82
#define DNP3_APP_FC_AUTH_RESP              0x83


typedef struct Dnp3FuncMap_ {
     uint8_t func;
     char *name;
} Dnp3FuncMap;


/* function code 对应的字符串. */
const Dnp3FuncMap dnp3_func_map[] = {
    /* DNP3 application request function codes. */
    { DNP3_APP_FC_CONFIRM                ,"confirm"             },
    { DNP3_APP_FC_READ                   ,"read"                },
    { DNP3_APP_FC_WRITE                  ,"write"               },
    { DNP3_APP_FC_SELECT                 ,"select"              },
    { DNP3_APP_FC_OPERATE                ,"operate"             },
    { DNP3_APP_FC_DIR_OPERATE            ,"direct_operate"      },
    { DNP3_APP_FC_DIR_OPERATE_NR         ,"direct_operate_nr"   },
    { DNP3_APP_FC_FREEZE                 ,"immed_freeze"        },
    { DNP3_APP_FC_FREEZE_NR              ,"immed_freeze_nr"     },
    { DNP3_APP_FC_FREEZE_CLEAR           ,"freeze_clear"        },
    { DNP3_APP_FC_FREEZE_CLEAR_NR        ,"freeze_clear_nr"     },
    { DNP3_APP_FC_FREEZE_AT_TIME         ,"freeze_at_time"      },
    { DNP3_APP_FC_FREEZE_AT_TIME_NR      ,"freeze_at_time_nr"   },
    { DNP3_APP_FC_COLD_RESTART           ,"cold_restart"        },
    { DNP3_APP_FC_WARM_RESTART           ,"warm_restart"        },
    { DNP3_APP_FC_INITIALIZE_DATA        ,"initialize_data"     },
    { DNP3_APP_FC_INITIALIZE_APPLICATION ,"initialize_appl"     },
    { DNP3_APP_FC_START_APPLICATION      ,"start_appl"          },
    { DNP3_APP_FC_STOP_APPLICATION       ,"stop_appl"           },
    { DNP3_APP_FC_SAVE_CONFIGURATION     ,"save_config"         },
    { DNP3_APP_FC_ENABLE_UNSOLICITED     ,"enable_unsolicited"  },
    { DNP3_APP_FC_DISABLE_UNSOLICTED     ,"disable_unsolicited" },
    { DNP3_APP_FC_ASSIGN_CLASS           ,"assign_class"        },
    { DNP3_APP_FC_DELAY_MEASUREMENT      ,"delay_measure"       },
    { DNP3_APP_FC_RECORD_CURRENT_TIME    ,"record_current_time" },
    { DNP3_APP_FC_OPEN_TIME              ,"open_file"           },
    { DNP3_APP_FC_CLOSE_FILE             ,"close_file"          },
    { DNP3_APP_FC_DELETE_FILE            ,"delete_file"         },
    { DNP3_APP_FC_GET_FILE_INFO          ,"get_file_info"       },
    { DNP3_APP_FC_AUTHENTICATE_FILE      ,"authenticate_file"   },
    { DNP3_APP_FC_ABORT_FILE             ,"abort_file"          },
    { DNP3_APP_FC_ACTIVATE_CONFIG        ,"activate_config"     },
    { DNP3_APP_FC_AUTH_REQ               ,"authenticate_req"    },
    { DNP3_APP_FC_AUTH_REQ_NR            ,"authenticate_err"    },

    /* DNP3 application response function codes. */
    { DNP3_APP_FC_RESPONSE               ,"response"            },
    { DNP3_APP_FC_UNSOLICITED_RESP       ,"unsolicited_response"},
    { DNP3_APP_FC_AUTH_RESP              ,"authenticate_resp"   }

};




void main ()
{
	
	printf("DnpfuncMap size is %ld.\n",sizeof(dnp3_func_map)/sizeof(Dnp3FuncMap));
	Dnp3FuncMap a;
	a.func = 3;
	a.name = "xxx";
	a.name = "bbb";



	for(int i = 0; i < sizeof(dnp3_func_map)/sizeof(Dnp3FuncMap); i ++)
	{
		printf("func:%d:%s.\n",dnp3_func_map[i].func,dnp3_func_map[i].name);
	}

	return;








	
}
