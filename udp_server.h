#ifndef __UDP_SERVER_H__
#define __UDP_SERVER_H__

#include "main.h"
#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"
#include <string.h>
#include <stdio.h>

void udp_server_init(uint16_t _ServerPort);
void udp_Server_SendString(struct udp_pcb *upcb,uint8_t * str , uint16_t _Len, const ip_addr_t *addr, u16_t port);
__weak void UDP_Server_Recieve(struct udp_pcb *upcb,uint8_t *Buf,uint32_t _Len, const ip_addr_t *addr, u16_t port);

#endif /* __TCP_SERVER_H__ */
