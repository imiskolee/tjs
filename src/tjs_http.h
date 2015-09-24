#include <time.h>
#include <curl/easy.h>

#include "tjs_defined.h"
#include "tjs_types.h"

typedef struct tjs_http_request_s tjs_http_request_t;

typedef struct tjs_http_response_s tjs_http_response_t;

typedef struct tjs_http_s tjs_http_t;

struct tjs_http_request_s
{

    raw body;

    uint length;

};

struct tjs_http_response_s
{

    raw             body;

    uint            length;

    time_t          start_time;

    time_t          end_time;


};

enum tjs_http_opt
{

    CONNECT_TIMEOUT = 1,

    TIMEOUT         = 2

};

struct tjs_http_s
{

    tjs_http_request_t      *request;

    tjs_http_response_t     *response;

    CURL                    *curl_handler;

    char                    url[TJS_HTTP_URL_MAX_LENGTH];

    uint                    connect_timeout;

    uint                    timeout;

};

tjs_http_t*  tjs_http_create();

tjs_bool     tjs_http_set_url(tjs_http_t *http,char *url);

tjs_bool     tjs_http_set_opt(hts_http_t *http,tjs_http_opt opt,uint val);

tjs_bool     tjs_http_set_request(tjs_http_t *http,raw body,uint length);

tjs_bool     tjs_http_read_request(tjs_http_t *http,raw *body,uint *length);

tjs_bool     tjs_http_set_response(tjs_http_t *http,raw body,uint length);

tjs_bool     tjs_http_read_response(tjs_http_t *http,raw *body, uint *length);

tjs_bool     tjs_http_destroy(tjs_http_t *http);

tjs_bool     tjs_http_post(tjs_http_t *http);
