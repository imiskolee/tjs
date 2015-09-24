#include "tjs_defined.h"
#include "tjs_types.h"

typedef struct tjs_task_s tjs_task_t;

enum tjs_task_state
{
    failed  = 0,
    success = 1,
    replay  = 2,
};

struct tjs_task_s
{

    char id[TJS_TASK_ID_MAX_LENGTH];

    char url[TJS_TASK_URL_MAX_LENGTH];

    uint connect_timeout;

    uint timeout;

    uint reply_count;

    char *message;

    char *response;

    uint used_time;

    tjs_task_state state;

};