#include "tjs_defined.h"
#include "tjs_types.h"
#include "tjs_task.h"

typedef struct tjs_queue_s tjs_queue_t;

struct tjs_queue_s
{

    void        *connection;

    char        name[TJS_QUEUE_NAME_MAX_LENGTH];

    tjs_task_t* (*get_next_task)(tjs_queue_s *self);

    tjs_bool    (*ack_task)(tjs_queue_s *self,tjs_task_t *task);

    tjs_bool    (*replay_task)(tjs_queue_s *self,tjs_task_t *task);

    tjs_bool    (flush_all_task(tjs_queue_s *self));

    tjs_bool    (*connect)(tjs_queue_s *self);

    tjs_bool    (*reconnect)(tjs_queue_s *self);

    tjs_bool    (*disconnect)(tjs_queue_s *self);

};

enum tjs_queue_opt
{

    get_next_task   = 1,

    ack_task        = 2,

    replay_task     = 3,

    flush_all_task  = 4,

    connect         = 5,

    reconnect       = 6,

    disconnect      = 7

};

tjs_queue_t*   tjs_queue_create();

tjs_bool       tjs_queue_set_handler(tjs_queue_t *queue, tjs_queue_opt opt,void *handler);

tjs_bool       tjs_queue_destroy();
