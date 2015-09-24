#include "../tjs_queue.h"

tjs_bool    redis_queue_connect(tjs_queue_t *queue);

tjs_bool    redis_queue_reconnect(tjs_queue_t *queue);

tjs_bool    redis_queue_disconnect(tjs_queue_t *queue);

tjs_task_t  *redis_queue_get_next_task(tjs_queue_t *queue);

tjs_bool    redis_queue_ack_task(tjs_queue_t *queue,tjs_task_t *task);

tjs_bool    redis_queue_flush_all_task(tjs_queue_t *queue);

tjs_bool    redis_queue_heart(tjs_queue_t *queue);

