#include "tjs_http.h"
#include "tjs_thread.h"
#include "tjs_task.h"
#include "tjs_queue.h"

typedef struct tjs_worker_s tjs_worker_t;


struct tjs_worker_s
{

    tjs_http_t      *http_client;

    tjs_thread_t    *worker_thread;

    tjs_queue_t     *queue;

    tjs_task_t      *task;

};

tjs_worker_t*       tjs_worker_create();

tjs_bool            tjs_worker_heart(tjs_worker_t *worker);

tjs_bool            tjs_worker_set_task(tjs_worker_t *worker, tjs_task_t *task);

tjs_bool            tjs_worker_get_next_task(tjs_worker_t *worker);

tjs_bool            tjs_worker_destroy(tjs_worker_t *worker);






