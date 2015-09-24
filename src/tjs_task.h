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

    raw message;

    uint message_length;

    raw response;

    uint response_length;

    uint used_time;

    tjs_task_state state;

};

tjs_task_t*     tjs_task_create();

tjs_bool        tjs_task_set_message(tjs_task_t *task,raw message,uint len);

tjs_bool        tjs_task_set_response(tjs_task_t *task,raw response,uint len);

tjs_bool        tjs_task_destroy(tjs_task_t *task);
