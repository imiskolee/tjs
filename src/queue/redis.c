#include "redis.h"
#include <hiredis/hiredis.h>

typedef struct redis_connection{

    redisContext    *context;

} redis_connection;


tjs_bool redis_queue_is_connect(tjs_queue_t *queue){

    if(queue->connection == NULL){

        return tjs_false;

    }

    redis_connection *connection = (redis_connection *)queue->connection;

    if(!connection->context){

        return tjs_false;
    }

    return tjs_true;

}

tjs_bool    redis_queue_connect(tjs_queue_t *queue){

    redis_connection *connection = (redis_connection *)queue->connection;

    if(!connection->context) {

        redisContext *context = redisConnect("127.0.0.1", 6379);

        if (context) {

            connection->context = context;

            return tjs_true;
        }

        return tjs_false;

    }

    return     redis_queue_reconnect(queue);

}

tjs_bool    redis_queue_reconnect(tjs_queue_t *queue){

    redis_connection *connection = (redis_connection *)queue->connection;

    if(connection->context){

        redisFree(connection->context);

        connection->context = NULL;

    }

    return redis_queue_connect(queue);

}

tjs_bool    redis_queue_disconnect(tjs_queue_t *queue){


}

tjs_task_t  *redis_queue_get_next_task(tjs_queue_t *queue){

    redis_connection *connection = (redis_connection *)queue->connection;

    char command_buffer[256] = {0};

    sprintf(command_buffer,"POP %s%s",TJS_QUEUE_NAME_PREFIX,queue->name);

    redisReply *reply = redisCommand(connection->context,command_buffer);

    if(!reply || reply->type != REDIS_REPLY_STRING){

        return NULL;
    }

    tjs_task_t *new_task = tjs_task_create();

    tjs_task_set_message(new_task,reply->str,reply->len);

    redisFree(reply);

    return new_task;

}

tjs_bool    redis_queue_ack_task(tjs_queue_t *queue,tjs_task_t *task){

    return tjs_true;
}

tjs_bool    redis_queue_flush_all_task(tjs_queue_t *queue){

    return tjs_true;

}

tjs_bool    redis_queue_heart(tjs_queue_t *queue){

    return tjs_true;

}
