#ifndef HTTPCLIENT_GLOBAL_H
#define HTTPCLIENT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HTTPCLIENT_LIBRARY)
#  define HTTPCLIENTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define HTTPCLIENTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // HTTPCLIENT_GLOBAL_H
