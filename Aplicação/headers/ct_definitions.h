#ifndef CT_DEFINITIONS_H
#define CT_DEFINITIONS_H

// CONVENTIONS FOR CT HEADERS.


typedef enum eAppState
{
    APS_EXIT = 0,
    APS_RUNNING

} APP_STATE;


// KEY VALUES REGARDING ASCII TABLE:
// CTK : CT Key Type

typedef int CTK;

#define CTK_FUNCTION_FLAG 0
#define CTK_ARROW_FLAG 0xe0

#define CTK_ESC 0x1b
#define CTK_F1 0x03b
#define CTK_CARRIAGE_RETURN 0xd
#define CTK_EOL 0xd0a
#define CTK_BACKSPACE 0x8
#define CTK_LEFT_ARROW 0x4b
#define CTK_RIGHT_ARROW 0x4d
#define CTK_DOWN_ARROW 0x50
#define CTK_UP_ARROW 0x48


// FUNCTION RETURNING STATUS:

typedef short int F_STATUS;

#define F_SUCCESS 0

#define F_ERROR -1
#define F_ALLOCATION_ERROR -2


#endif // CT_DEFINITIONS_H
