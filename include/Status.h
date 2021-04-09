#ifndef _STATUS_H
#define _STATUS_H

enum Status { ERR_NONE = 0, ERR_PARAM, ERR_IO, ERR_INVALID_TRANSACTION };

#define IF_ERROR_RETURN( x ) { \
    Status status = x; \
    if( status != ERR_NONE ){ \
        return status ; \
    } \
};

#endif //_STATUS_H
