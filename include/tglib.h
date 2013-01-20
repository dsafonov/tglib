#ifndef _TGLIB_H
#define _TGLIB_H

#include <stddef.h>

class TGLSImpl;
class TGLCImpl;

void TGLib_start();
void TGLib_end();

class TGLPort
{
public:
    TGLPort(const char *host = NULL, int port = 0);
    TGLPort();
    ~TGLPort();

    //const char *getHost();
    //void setHost(const char *host);
    //
    //void setPort(int port);
    //int getPort();

    
//_timeoutMillis_ parameter can have the following values:
// - -1 - block forever
// - 0 - non-blocking mode, not supported in _connect()_
// - any positive value - block for at most _timeoutMillis_
    /**
     * Connect to remote host, using host and port supplied.
     * @return true on success and false on failure
     */
    bool connect(char* host, int port, int timeoutMs);
    bool connect(int timeoutMs);

    //virtual bool isBlocking();
    //virtual void setBLocking(bool blocking);

    bool send(const char *data, size_t *len, int timeoutMs);
    bool recv(char *data, size_t *len, int timeoutMs = 0);
    void close();

    int getLastError();
public:
    TGLCImpl *pimpl;
};

/** 
 * Server port class.
 */


class TGLServerPort
{
public:
    TGLServerPort();
    TGLServerPort(const char *host, int port);
    ~TGLServerPort();

    /**
     * Start listening to connections on a specified port.
     * @return true on successful start and false on failure
     */
    bool bind();
    bool bind(const char *port, int host);

    bool accept(TGLPort *port, int timeoutMs);

    int getLastError();

    void close();
private:
    TGLSImpl *pimpl;
};
#endif
