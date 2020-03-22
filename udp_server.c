/* Includes ------------------------------------------------------------------*/
#include <udp_server.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint16_t ServerPort;
/* Private function prototypes -----------------------------------------------*/
void udp_server_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);

/* Private functions ---------------------------------------------------------*/
void udp_server_init(uint16_t _ServerPort)
{
	struct udp_pcb *upcb;
	err_t err;

	upcb = udp_new();
	ServerPort = _ServerPort;
   
   if (upcb)
   {
      err = udp_bind(upcb, IP_ADDR_ANY, ServerPort);
      
      if(err == ERR_OK)
      {
        udp_recv(upcb, udp_server_receive_callback, NULL);
      }
   }
}

void udp_server_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{

  UDP_Server_Recieve(upcb,p->payload,p->len,addr,port);
	
  pbuf_free(p);
   
}

void udp_Server_SendString(struct udp_pcb *upcb,uint8_t * str , uint16_t _Len, const ip_addr_t *addr, u16_t port)
{
	if(_Len == 0)
	{
		while(str[_Len] != 0)_Len++;
	}
	struct pbuf *p;
  
  p = pbuf_alloc(PBUF_TRANSPORT,_Len, PBUF_POOL);
  
  if (p != NULL)
  {
    pbuf_take(p, str, _Len);
    
		udp_connect(upcb, addr, port);
		
    udp_send(upcb, p); 
		
		udp_disconnect(upcb);
    
    pbuf_free(p);
  }
}

__weak void UDP_Server_Recieve(struct udp_pcb *upcb,uint8_t *Buf,uint32_t _Len, const ip_addr_t *addr, u16_t port)
{
	
}

/*****************************END OF FILE****/
