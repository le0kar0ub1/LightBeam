#ifndef _DRIVER_H_
#define _DRIVER_H_

struct driver_t
{
    char name;
    void (*probe)(void);
    void (*remove)(void);
    void (*suspend)(void);
    void (*resume)(void);
};

#endif