#pragma once

#include "event_loop.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FuriEventLoopItem FuriEventLoopItem;

/* Link between Event Loop  */

typedef struct {
    FuriEventLoopItem* item_in;
    FuriEventLoopItem* item_out;
} FuriEventLoopLink;

void furi_event_loop_link_notify(FuriEventLoopLink* instance, FuriEventLoopEvent event);

/* Contract between event loop and an object */

typedef FuriEventLoopLink* (*FuriEventLoopContractGetLink)(FuriEventLoopObject* object);

typedef bool (
    *FuriEventLoopContractGetLevel)(FuriEventLoopObject* object, FuriEventLoopEvent event);

typedef struct {
    const FuriEventLoopContractGetLink get_link;
    const FuriEventLoopContractGetLevel get_level;
} FuriEventLoopContract;

#ifdef __cplusplus
}
#endif
