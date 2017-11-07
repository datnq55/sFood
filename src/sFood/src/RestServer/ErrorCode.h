#ifndef ERRORCODE_H
#define ERRORCODE_H

enum ErrorCode
{
    SUCCESSS            = 200,
    JSON_INVALID        = 500,
    ERROR_CREATE_DEVICE = 500,
    ERROR_DELETE_DEVICE = 500,
    ERROR_WRITE         = 500,
    ERROR_READ          = 501,
    NOT_FOUND           = 404
};

#endif // ERRORCODE_H
