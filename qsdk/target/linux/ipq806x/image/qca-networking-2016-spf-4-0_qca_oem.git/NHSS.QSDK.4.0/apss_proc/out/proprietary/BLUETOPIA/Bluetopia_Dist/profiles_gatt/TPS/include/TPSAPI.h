/*****< tpsapi.h >*************************************************************/
/*      Copyright 2012 - 2014 Stonestreet One.                                */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*  TPSAPI - Stonestreet One Bluetooth Tx Power Service (GATT based)          */
/*           API Type Definitions, Constants, and Prototypes.                 */
/*                                                                            */
/*  Author:  Jay Wheeler                                                      */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   08/15/12  J. Wheeler     Initial creation.                               */
/******************************************************************************/
#ifndef __TPSAPIH__
#define __TPSAPIH__

#include "SS1BTPS.h"        /* Bluetooth Stack API Prototypes/Constants.      */
#include "SS1BTGAT.h"       /* Bluetooth Stack GATT API Prototypes/Constants. */
#include "TPSTypes.h"       /* Tx Power Service Types/Constants.              */

   /* Error Return Codes.                                               */

   /* Error Codes that are greater than these (between 0 and -1000) are */
   /* related to the Bluetooth Protocol Stack itself (see BTERRORS.H).  */
#define TPS_ERROR_INVALID_PARAMETER                      (-1000)
#define TPS_ERROR_INVALID_BLUETOOTH_STACK_ID             (-1001)
#define TPS_ERROR_INSUFFICIENT_RESOURCES                 (-1002)
#define TPS_ERROR_SERVICE_ALREADY_REGISTERED             (-1003)
#define TPS_ERROR_INVALID_INSTANCE_ID                    (-1004)
#define TPS_ERROR_MALFORMATTED_DATA                      (-1005)
#define TPS_ERROR_UNKNOWN_ERROR                          (-1007)

#define TPS_TX_POWER_LEVEL_SIZE                          (sizeof(SByte_t))

   /* The following structure contains the Handles that will need to be */
   /* cached by a TPS client in order to only do service discovery once.*/
typedef struct _tagTPS_Client_Information_t
{
   Word_t Tx_Power_Level;
} TPS_Client_Information_t;

#define TPS_CLIENT_INFORMATION_DATA_SIZE                (sizeof(TPS_Client_Information_t))

   /* TPS Server API.                                                   */

   /* The following function is responsible for opening a TPS Server.   */
   /* The first parameter is the Bluetooth Stack ID on which to open the*/
   /* server.  The second parameter is a pointer to store the GATT      */
   /* Service ID of the registered TPS service.  This can be used to    */
   /* include the service registered by this call.  This function       */
   /* returns the positive, non-zero, Instance ID or a negative error   */
   /* code.                                                             */
   /* * NOTE * Only 1 TPS Server may be open at a time, per Bluetooth   */
   /*          Stack ID.                                                */
BTPSAPI_DECLARATION int BTPSAPI TPS_Initialize_Service(unsigned int BluetoothStackID, unsigned int *ServiceID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_TPS_Initialize_Service_t)(unsigned int BluetoothStackID, unsigned int *ServiceID);
#endif

   /* The following function is responsible for opening a TPS Server.   */
   /* The first parameter is the Bluetooth Stack ID on which to open the*/
   /* server.  The second parameter is a pointer to store the GATT      */
   /* Service ID of the registered TPS service.  This can be used to    */
   /* include the service registered by this call.  The final parameter */
   /* is a pointer, that on input can be used to control the location of*/
   /* the service in the GATT database, and on ouput to store the       */
   /* service handle range.  This function returns the positive,        */
   /* non-zero, Instance ID or a negative error code.                   */
   /* * NOTE * Only 1 TPS Server may be open at a time, per Bluetooth   */
   /*          Stack ID.                                                */
BTPSAPI_DECLARATION int BTPSAPI TPS_Initialize_Service_Handle_Range(unsigned int BluetoothStackID, unsigned int *ServiceID, GATT_Attribute_Handle_Group_t *ServiceHandleRange);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_TPS_Initialize_Service_Handle_Range_t)(unsigned int BluetoothStackID, unsigned int *ServiceID, GATT_Attribute_Handle_Group_t *ServiceHandleRange);
#endif

   /* The following function is responsible for closing a previously    */
   /* opened TPS Server.  The first parameter is the Bluetooth Stack ID */
   /* on which to close the server.  The second parameter is the        */
   /* InstanceID that was returned from a successful call to            */
   /* TPS_Initialize_Service().  This function returns a zero if        */
   /* successful or a negative return error code if an error occurs.    */
BTPSAPI_DECLARATION int BTPSAPI TPS_Cleanup_Service(unsigned int BluetoothStackID, unsigned int InstanceID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_TPS_Cleanup_Service_t)(unsigned int BluetoothStackID, unsigned int InstanceID);
#endif

   /* The following function is used to perform a suspend of the        */
   /* Bluetooth stack.  This function accepts as input the Bluetooth    */
   /* Stack ID of the Bluetooth Stack that the Device is associated     */
   /* with.  The final two parameters are the buffer size and buffer    */
   /* that Bluetopia is to use to collapse it's state information into. */
   /* This function can be called with BufferSize and Buffer set to 0   */
   /* and NULL, respectively.  In this case this function will return   */
   /* the number of bytes that must be passed to this function in order */
   /* to successfully perform a suspend (or 0 if an error occurred, or  */
   /* this functionality is not supported).  If the BufferSize and      */
   /* Buffer parameters are NOT 0 and NULL, this function will attempt  */
   /* to perform a suspend of the stack.  In this case, this function   */
   /* will return the amount of memory that was used from the provided  */
   /* buffers for the suspend (or zero otherwise).                      */
BTPSAPI_DECLARATION unsigned long BTPSAPI TPS_Suspend(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef unsigned long (BTPSAPI *PFN_TPS_Suspend_t)(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);
#endif

   /* The following function is used to perform a resume of the         */
   /* Bluetooth stack after a successful suspend has been performed (see*/
   /* TPS_Suspend()).  This function accepts as input the Bluetooth     */
   /* Stack ID of the Bluetooth Stack that the Device is associated     */
   /* with.  The final two parameters are the buffer size and buffer    */
   /* that contains the memory that was used to collapse Bluetopia      */
   /* context into with a successfull call to TPS_Suspend().  This      */
   /* function returns ZERO on success or a negative error code.        */
BTPSAPI_DECLARATION int BTPSAPI TPS_Resume(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_TPS_Resume_t)(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);
#endif

   /* The following function is responsible for querying the number of  */
   /* attributes that are contained in the TPS Service that is          */
   /* registered with a call to TPS_Initialize_Service().  This function*/
   /* returns the non-zero number of attributes that are contained in a */
   /* TPS Server or zero on failure.                                    */
BTPSAPI_DECLARATION unsigned int BTPSAPI TPS_Query_Number_Attributes(void);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef unsigned int (BTPSAPI *PFN_TPS_Query_Number_Attributes_t)(void);
#endif

   /* The following function is responsible for setting the Tx Power    */
   /* Level on the specified TPS Instance.  The first parameter is the  */
   /* Bluetooth Stack ID of the Bluetooth Device.  The second parameter */
   /* is the InstanceID returned from a successful call to              */
   /* TPS_Initialize_Server().  The final parameter is the Tx Power     */
   /* Level to set for the specified TPS Instance.  This function       */
   /* returns a zero if successful or a negative return error code if   */
   /* an error occurs.                                                  */
BTPSAPI_DECLARATION int BTPSAPI TPS_Set_Tx_Power_Level(unsigned int BluetoothStackID, unsigned int InstanceID, SByte_t Tx_Power_Level);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_TPS_Set_Tx_Power_Level_t)(unsigned int BluetoothStackID, unsigned int InstanceID, SByte_t Tx_Power_Level);
#endif

   /* The following function is responsible for querying the current    */
   /* Tx Power Level on the specified TPS Instance.  The first          */
   /* parameter is the Bluetooth Stack ID of the Bluetooth Device.  The */
   /* second parameter is the InstanceID returned from a successful call*/
   /* to TPS_Initialize_Server().  The final parameter is a pointer to  */
   /* return the current Tx Power Level for the specified TPS Instance. */
   /* This function returns a zero if successful or a negative return   */
   /* error code if an error occurs.                                    */
BTPSAPI_DECLARATION int BTPSAPI TPS_Query_Tx_Power_Level(unsigned int BluetoothStackID, unsigned int InstanceID, SByte_t *Tx_Power_Level);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_TPS_Query_Tx_Power_Level_t)(unsigned int BluetoothStackID, unsigned int InstanceID, SByte_t *Tx_Power_Level);
#endif

#endif
