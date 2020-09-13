#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    errno = ENOENT;
    
    char *tmp = strerror(errno);
    
    // - Not thread safe (so only use if you are running one thing at a time)
    // - You can't modify the string without copying it first
    // - Future calls to strerror will modify the buffer
    printf("/tmp/ex: %s\n", tmp);

    errno = ENOATTR;
    strerror(errno);

    printf("/tmp/ex: %s\n", tmp);

    char buf[1024];
    // - Most secure of the bunch, thread safe
    // - It is your buffer so you can modify afterwards
    strerror_r(errno, buf, 1024);
    printf("/tmp/ex: %s\n", buf);

    // - safe but uses errno which can make it non-threadsafe
    //   if you aren't in a thread_local errno env
    perror("/tmp/ex");
    
    return 0;
}
