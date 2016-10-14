/**
******************************************************************************
* @file       list.c
* @author     yearnext
* @version    1.0.0
* @date       2016��10��05��
* @brief      list Դ�ļ�
* @par        ����ƽ̨
*                  WIN32                
* @par        ����ƽ̨
* 				   VS2015
******************************************************************************
* @note
* 1.XXXXX
******************************************************************************
*/

/**
* @defgroup list ģ��
* @{
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef struct _USER_NODE_
{
	struct _USER_NODE_ *next;
	void *data;
}NODE, *LIST_NODE, **LIST_HEAD;

typedef enum
{
	DEVICE_COORD = 0x00,
	DEVICE_LIGHT,
	DEVICE_SOCKET,
	DEVICE_CURTAIN,
	//    DEVICE_END,
}DEVICE_TYPE;

typedef struct
{
	DEVICE_TYPE device;
	uint16_t shortaddr;
	uint8_t tick;
}DEVICE_INFO;

typedef bool(*visit_func)(void **ctx, void **list);

typedef LIST_NODE DEVICE_LIST_HEAD;

/* Exported variables --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static DEVICE_LIST_HEAD head = NULL;

/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/**
*******************************************************************************
* @brief       �����ڵ�
* @param       [in/out]  head    ����ͷ
			   [in/out]  func    ������ʺ���
			   [in/out]  ctx     ������
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool list_foreach(void **list_head, visit_func visit, void **ctx)
{
	bool status = false;
	LIST_HEAD list = (LIST_HEAD)list_head;

	while (1)
	{
		status = visit(ctx, list);

		if (status == true || *list == NULL)
		{
			break;
		}

		list = &((LIST_NODE)(*list))->next;
	}

	return status;
}

/**
*******************************************************************************
* @brief       ���ӽڵ�
* @param       [in/out]  ctx     ������
               [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool node_add(void **ctx, void **list)
{
	bool status = false;

	if (*list == NULL)
	{
		*list = *ctx;
		status = true;
	}

	return status;
}

/**
*******************************************************************************
* @brief       ɾ���ڵ�
* @param       [in/out]  ctx     ������
               [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool node_del(void **ctx, void **list)
{
	bool status = false;
	LIST_NODE node = (LIST_NODE)(*ctx);

	if (*list == *ctx)
	{
		*list = node->next;
		node->next = NULL;
		status = true;
	}

	return status;
}

/**
*******************************************************************************
* @brief       ��ȡ�ڵ�����
* @param       [in/out]  ctx     ������
			   [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool get_node_num(void **crx, void **list)
{
	uint8_t *num = (uint8_t *)(crx);
	bool status = false;

	if (*list == NULL)
	{
		status = true;
	}
	else
	{
		(*num)++;
	}

	return status;
}

/**
*******************************************************************************
* @brief       ��ѯ�ڵ��Ƿ����б���
* @param       [in/out]  ctx     ������
			   [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool node_find(void **ctx, void **list)
{
	bool status = false;

	if (*list == *ctx)
	{
		status = true;
	}

	return status;
}

/**
*******************************************************************************
* @brief       ��ѯ�豸�Ƿ�������豸�б���
* @param       [in/out]  ctx     ������
               [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool find_device_inlist(void **ctx, void **list)
{
	bool status = false;
	DEVICE_INFO *list_info = NULL;
	DEVICE_INFO *device_info = (DEVICE_INFO *)ctx;

	if (*list != NULL)
	{
		list_info = ((LIST_NODE)(*list))->data;

		if (list_info->device == device_info->device \
			&& list_info->shortaddr == device_info->shortaddr)
		{
			status = true;
		}
	}

	return status;
}

/**
*******************************************************************************
* @brief       ��ȡ�豸���б��еĽڵ�
* @param       [in/out]  ctx     ������
               [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool get_device_addr(void **ctx, void **list)
{
	bool status = false;
	DEVICE_INFO *list_info = NULL;
	DEVICE_INFO *device_info = (DEVICE_INFO *)*ctx;

	if (*list != NULL)
	{
		list_info = ((LIST_NODE)(*list))->data;

		if (list_info->device == device_info->device \
			&& list_info->shortaddr == device_info->shortaddr)
		{
			*ctx = *list;
			status = true;
		}
	}

	return status;
}

/**
*******************************************************************************
* @brief       �����豸��������
* @param       [in/out]  ctx     ������
               [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool add_device_tick(void **ctx, void **list)
{
	bool status = false;
	DEVICE_INFO *device_info = (DEVICE_INFO *)ctx;
	DEVICE_INFO *node_info = NULL;

	if (*list != NULL)
	{
		node_info = ((LIST_NODE)*list)->data;

		if (device_info->device == node_info->device \
			&& device_info->shortaddr == node_info->shortaddr)
		{
			node_info->tick++;
			status = true;
		}
	}

	return status;
}

/**
*******************************************************************************
* @brief       ����豸����������
* @param       [in/out]  ctx     ������
               [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool clr_device_tick(void **ctx, void **list)
{
	bool status = false;
	DEVICE_INFO *device_info = (DEVICE_INFO *)ctx;
	DEVICE_INFO *node_info = NULL;

	if (*list != NULL)
	{
		node_info = ((LIST_NODE)*list)->data;

		if (device_info->device == node_info->device \
			&& device_info->shortaddr == node_info->shortaddr)
		{
			node_info->tick = 0;
			status = true;
		}
	}

	return status;
}

/**
*******************************************************************************
* @brief       ��������豸����������
* @param       [in/out]  ctx     ������
               [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool clr_all_device_tick(void **ctx, void **list)
{
	bool status = false;
	DEVICE_INFO *node_info = NULL;

	if (*list != NULL)
	{
		node_info = ((LIST_NODE)*list)->data;
		node_info->tick = 0;
	}
	else
	{
		status = true;
	}

	return status;
}

/**
*******************************************************************************
* @brief       ����豸���豸�б���
* @param       [in/out]  ctx     ������
               [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool Add_Device_Forlist(DEVICE_INFO info)
{
	bool status = false;
	DEVICE_INFO *device_info = NULL;
	NODE *list_node = NULL;

	if (list_foreach((void **)&head, find_device_inlist, (void **)&info) == false)
	{
		device_info = (DEVICE_INFO *)malloc(sizeof(DEVICE_INFO));
		list_node = (NODE *)malloc(sizeof(NODE));

		if (device_info != NULL && list_node != NULL)
		{
			device_info->device = info.device;
			device_info->shortaddr = info.shortaddr;
			device_info->tick = 1;

			list_node->data = (void *)device_info;
			list_node->next = NULL;

			status = list_foreach((void **)&head, node_add, (void **)&list_node);
		}
		else
		{
			(device_info != NULL) ? free(device_info), 1 : 0;
			(list_node != NULL) ? free(list_node), 1 : 0;

			status = false;
		}
	}
	else
	{
		status = true;
	}

	return status;
}

/**
*******************************************************************************
* @brief       ɾ���豸�б��е��豸
* @param       [in/out]  ctx     ������
               [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool Del_Device_ForList(DEVICE_INFO *info)
{
	bool status = false;
	LIST_NODE node = (LIST_NODE)info;

	if (list_foreach((void **)&head, get_device_addr, (void *)&node) == true)
	{
		list_foreach((void **)&head, node_del, (void **)&node);
		free(node->data);
		free(node);
		status = true;
	}

	return status;
}

/**
*******************************************************************************
* @brief       ����б��е�һ̨��ʬ�豸
* @param       [in/out]  ctx     ������
               [in/out]  list    ����
* @return      [in/out]  status  ״̬
* @note        None
*******************************************************************************
*/
bool clr_zombie_device(void **ctx, void **list)
{
	bool status = false;
	LIST_NODE node = (LIST_NODE)*list;
	DEVICE_INFO *device_info = NULL;

	if (node != NULL)
	{
		device_info = node->data;

		if (device_info->tick == 0)
		{
			node_del((void **)&node,list);
			free(node->data);
			free(node);
			
			status = true;
		}
	}

	return status;
}

/**
*******************************************************************************
* @brief       ����б��е����н�ʬ�豸
* @param       [in/out]  void
* @return      [in/out]  void
* @note        None
*******************************************************************************
*/
void Del_ZombieDevice_ForList(void)
{
	uint8_t device_num = 0;
	list_foreach((void **)&head, get_node_num, (void **)&device_num);

	for (uint8_t i = 0; i < device_num; i++)
	{
		list_foreach((void **)&head, clr_zombie_device, NULL);
	}
}

/************************************����Ϊ��ʾ����*******************************/
static DEVICE_INFO device[10];

// ��ӽڵ���ʾ����
void add_node_demo( void )
{
	device[0].device = DEVICE_LIGHT;
	device[0].shortaddr = 0x2016;

	device[1].device = DEVICE_SOCKET;
	device[1].shortaddr = 0x2017;

	device[2].device = DEVICE_CURTAIN;
	device[2].shortaddr = 0x2018;

	device[3].device = DEVICE_LIGHT;
	device[3].shortaddr = 0x2019;

	device[4].device = DEVICE_SOCKET;
	device[4].shortaddr = 0x201A;

	device[5].device = DEVICE_CURTAIN;
	device[5].shortaddr = 0x201B;

	for (uint8_t i = 0; i < 6; i++)
	{
		Add_Device_Forlist(device[i]);
	}
}

// ɾ���ڵ���ʾ����
void del_node_demo( void )
{
	for (uint8_t i = 0; i < 6; i++)
	{
		Del_Device_ForList(&device[i]);
	}
}

// �豸������ʾ����
void device_tick_demo(void)
{
	DEVICE_INFO drv;

	drv.device = DEVICE_LIGHT;
	drv.shortaddr = 0x2016;
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);

	drv.device = DEVICE_SOCKET;
	drv.shortaddr = 0x2017;
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);

	drv.device = DEVICE_CURTAIN;
	drv.shortaddr = 0x2018;
	list_foreach((void **)&head, add_device_tick, (void **)&drv);

	drv.device = DEVICE_LIGHT;
	drv.shortaddr = 0x2019;
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);

	drv.device = DEVICE_SOCKET;
	drv.shortaddr = 0x201A;
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);


	drv.device = DEVICE_CURTAIN;
	drv.shortaddr = 0x201B;
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);
	list_foreach((void **)&head, add_device_tick, (void **)&drv);

	list_foreach((void **)&head, clr_all_device_tick, NULL);
	Del_ZombieDevice_ForList();
}

int main(void)
{
	add_node_demo();
	device_tick_demo();
	add_node_demo();
	del_node_demo();

	while (1);

	return 0;
}