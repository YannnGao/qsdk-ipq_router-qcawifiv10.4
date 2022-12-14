/*
* Copyright (c) 2016 Qualcomm Technologies, Inc.
* All Rights Reserved.
* Confidential and Proprietary - Qualcomm Technologies, Inc.
*/
/*****< ipspapi.h >************************************************************/
/*      Copyright 2015 - 2016 Qualcomm Technologies, Inc.                     */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*  IPSPAPI - Qualcomm Technologies Bluetooth Internet Protocol Support       */
/*            Profile (GATT based) API Type Definitions, Constants, and       */
/*            Prototypes.                                                     */
/*                                                                            */
/*  Author:  Ryan McCord                                                      */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   07/21/15  R. McCord      Initial creation.                               */
/******************************************************************************/
#ifndef __IPSPAPIH__
#define __IPSPAPIH__

#include "SS1BTPS.h"         /* Bluetooth Stack API Prototypes/Constants.     */
#include "SS1BTGAT.h"        /* Bluetooth Stack GATT API Prototypes/Constants.*/
#include "IPSPTypes.h"       /* Internet Protocol Support Profile Profile     */
                             /* Types/Constants.                              */

   /* Error Codes that are smaller than these (less than -1000) are     */
   /* related to the Bluetooth Protocol Stack itself (see BTERRORS.H).  */
#define IPSP_ERROR_INVALID_PARAMETER                      (-1000)
#define IPSP_ERROR_INVALID_BLUETOOTH_STACK_ID             (-1001)
#define IPSP_ERROR_INSUFFICIENT_RESOURCES                 (-1002)
#define IPSP_ERROR_NODE_ALREADY_INITIALIZED               (-1003)
#define IPSP_ERROR_NODE_NOT_INITIALIZED                   (-1004)
#define IPSP_ERROR_NODE_IPSS_NOT_REGISTERED               (-1005)
#define IPSP_ERROR_MALFORMATTED_DATA                      (-1006)
#define IPSP_ERROR_UNKNOWN_ERROR                          (-1007)
#define IPSP_ERROR_NO_CONNECTION_INFORMATION              (-1008)
#define IPSP_ERROR_CONNECTION_NOT_READY                   (-1009)
#define IPSP_ERROR_CONNECTION_NOT_PENDING                 (-1010)


   /* The following constants represent the Open Status Values that are */
   /* possible in the IPSP Open Confirmation Event Data Information.    */
#define IPSP_OPEN_STATUS_SUCCESS                          0x00
#define IPSP_OPEN_STATUS_CONNECTION_TIMEOUT               0x01
#define IPSP_OPEN_STATUS_CONNECTION_REFUSED               0x02
#define IPSP_OPEN_STATUS_UNKNOWN_ERROR                    0x03

   /* The following enumerated type represents the supported Server     */
   /* Connection Modes supported by an IPSP Node.                       */
typedef enum
{
   cmAutomaticAccept,
   cmAutomaticReject,
   cmManualAccept
} IPSP_Node_Connection_Mode_t;

#define IPSP_DEFAULT_SERVER_CONNECTION_MODE               (BTPS_CONFIGURATION_IPSP_DEFAULT_NODE_CONNECTION_MODE)

   /* The following enumerated type represents the supported connection */
   /* roles for IPSP.                                                   */
typedef enum _tagIPSP_Connection_Role_t
{
   crNode,
   crRouter
} IPSP_Connection_Role_t;

   /* The following enumeration covers all the events generated by the  */
   /* IPSP Service.These are used to determine the type of each event   */
   /* generated, and to ensure the proper union element is accessed for */
   /* the IPSP_Event_Data_t structure.                                  */
typedef enum _tagIPSS_Event_Type_t
{
   etIPSP_Open_Indication,
   etIPSP_Open_Request_Indication,
   etIPSP_Open_Confirmation,
   etIPSP_Close_Indication,
   etIPSP_Close_Confirmation,
   etIPSP_Data_Indication,
   etIPSP_Buffer_Empty_Indication
} IPSP_Event_Type_t;

   /* The following defines the event data for the open indication      */
   /* event.                                                            */
typedef struct _tagIPSP_Open_Indication_Data_t
{
   BD_ADDR_t              RemoteDevice;
   IPSP_Connection_Role_t Role;
   Word_t                 CID;
   Word_t                 MaxSDUSize;
   Word_t                 MaxPDUSize;
   Word_t                 InitialCredits;
} IPSP_Open_Indication_Data_t;

#define IPSP_OPEN_INDICATION_DATA_SIZE                    (sizeof(IPSP_Open_Indication_Data_t))

   /* The following defines the event data for the open request         */
   /* indication event.                                                 */
typedef struct _tagIPSP_Open_Request_Indication_Data_t
{
   BD_ADDR_t              RemoteDevice;
   IPSP_Connection_Role_t Role;
   Word_t                 CID;
   Word_t                 MaxSDUSize;
   Word_t                 MaxPDUSize;
   Word_t                 InitialCredits;
} IPSP_Open_Request_Indication_Data_t;

#define IPSP_OPEN_REQUEST_INDICATION_DATA_SIZE            (sizeof(IPSP_Open_Request_Indication_Data_t))

   /* The following defines the event data for the open confirmation    */
   /* event.                                                            */
typedef struct _tagIPSP_Open_Confirmation_Data_t
{
   BD_ADDR_t              RemoteDevice;
   IPSP_Connection_Role_t Role;
   Word_t                 CID;
   unsigned int           ConnectionStatus;
   Word_t                 MaxSDUSize;
   Word_t                 MaxPDUSize;
   Word_t                 InitialCredits;
} IPSP_Open_Confirmation_Data_t;

#define IPSP_OPEN_CONFIRMATION_DATA_SIZE                  (sizeof(IPSP_Open_Confirmation_Data_t))

   /* The following defines the event data for the close indication     */
   /* event.                                                            */
typedef struct _tagIPSP_Close_Indication_Data_t
{
   unsigned int  Reason;
   Word_t        CID;
} IPSP_Close_Indication_Data_t;

#define IPSP_CLOSE_INDICATION_DATA_SIZE                   (sizeof(IPSP_Close_Indication_Data_t))

   /* The following defines the event data for the close confirmation   */
   /* event.                                                            */
typedef struct _tagIPSP_Close_Confirmation_Data_t
{
   unsigned int  Result;
   Word_t        CID;
} IPSP_Close_Confirmation_Data_t;

#define IPSP_CLOSE_CONFIRMATION_DATA_SIZE                 (sizeof(IPSP_Close_Confirmation_Data_t))

   /* The following defines the event data for the data indication      */
   /* event.                                                            */
typedef struct _tagIPSP_Data_Indication_Data_t
{
   BD_ADDR_t              RemoteDevice;
   IPSP_Connection_Role_t Role;
   Word_t                 CID;
   Word_t                 CreditsConsumed;
   Word_t                 DataLength;
   Byte_t                *Data;
} IPSP_Data_Indication_Data_t;

#define IPSP_DATA_INDICATION_DATA_SIZE                    (sizeof(IPSP_Data_Indication_Data_t))

   /* The following defines the event data for the empty buffer         */
   /* indication event.                                                 */
typedef struct _tagIPSP_Buffer_Empty_Indication_Data_t
{
   BD_ADDR_t              RemoteDevice;
   IPSP_Connection_Role_t Role;
   Word_t                 CID;
} IPSP_Buffer_Empty_Indication_Data_t;

#define IPSP_BUFFER_EMPTY_INDICATION_DATA_SIZE    (sizeof(IPSP_Buffer_Empty_Indication_Data_t))

   /* The following structure represents the container structure for    */
   /* holding all IPSP Profile Event Data.  This structure is received  */
   /* for each event generated.  The Event_Data_Type member is used to  */
   /* determine the appropriate union member element to access the      */
   /* contained data.  The Event_Data_Size member contains the total    */
   /* size of the data contained in this event.                         */
typedef struct _tagIPSP_Event_Data_t
{
   IPSP_Event_Type_t Event_Data_Type;
   Byte_t            Event_Data_Size;
   union
   {
      IPSP_Open_Indication_Data_t           *IPSP_Open_Indication_Data;
      IPSP_Open_Request_Indication_Data_t   *IPSP_Open_Request_Indication_Data;
      IPSP_Open_Confirmation_Data_t         *IPSP_Open_Confirmation_Data;
      IPSP_Close_Indication_Data_t          *IPSP_Close_Indication_Data;
      IPSP_Close_Confirmation_Data_t        *IPSP_Close_Confirmation_Data;
      IPSP_Data_Indication_Data_t           *IPSP_Data_Indication_Data;
      IPSP_Buffer_Empty_Indication_Data_t   *IPSP_Buffer_Empty_Indication_Data;
   } Event_Data;
} IPSP_Event_Data_t;

#define IPSP_EVENT_DATA_SIZE                              (sizeof(IPSP_Event_Data_t))

   /* The following declared type represents the Prototype Function for */
   /* a IPSP Service Event Receive Data Callback.  This function will be*/
   /* called whenever an IPSP Service Event occurs that is associated   */
   /* with the specified Bluetooth Stack ID.  This function passes to   */
   /* the caller the Bluetooth Stack ID, the IPSP Event Data that       */
   /* occurred and the IPSP Service Event Callback Parameter that was   */
   /* specified when this Callback was installed.  The caller is free to*/
   /* use the contents of the IPSP Service Event Data ONLY in context of*/
   /* this callback.  If the caller requires the Data for a longer      */
   /* period of time, then the callback function MUST copy the data into*/
   /* another Data Buffer This function is guaranteed NOT to be invoked */
   /* more than once simultaneously for the specified installed callback*/
   /* (i.e.  this function DOES NOT have be re-entrant).  It needs to be*/
   /* noted however, that if the same Callback is installed more than   */
   /* once, then the callbacks will be called serially.  Because of     */
   /* this, the processing in this function should be as efficient as   */
   /* possible.  It should also be noted that this function is called in*/
   /* the Thread Context of a Thread that the User does NOT own.        */
   /* Therefore, processing in this function should be as efficient as  */
   /* possible (this argument holds anyway because another IPSP Service */
   /* Event will not be processed while this function call is           */
   /* outstanding).                                                     */
   /* ** NOTE ** This function MUST NOT Block and wait for events that  */
   /*            can only be satisfied by Receiving IPSP Service Event  */
   /*            Packets.  A Deadlock WILL occur because NO IPSP Event  */
   /*            Callbacks will be issued while this function is        */
   /*            currently outstanding.                                 */
typedef void (BTPSAPI *IPSP_Event_Callback_t)(unsigned int BluetoothStackID, IPSP_Event_Data_t *IPSP_Event_Data, unsigned long CallbackParameter);

   /* IPSP Node API.                                                    */

   /* The following function is responsible for initializing an IPSP    */
   /* Node (will wait for an IPSP connection to be established by a     */
   /* remote IPSP Router).  This function will register the required    */
   /* IPSS service for an IPSP Node.  The first parameter is the        */
   /* Bluetooth Stack ID on which to register IPSS and initialize the   */
   /* IPSP Node.  The second parameter contains the IPSP Node's default */
   /* channel parameters to use for the IPSP connection when it is      */
   /* established by the IPSP Router.  The third parameter is the       */
   /* Callback function to call when an IPSP event occurs for this IPSP */
   /* Node.  The fourth parameter is a user-defined callback parameter  */
   /* that will be passed to the callback function with each IPSP event.*/
   /* The final parameter is a pointer, that on input can be used to    */
   /* control the location of the IPSS in the GATT database, and on     */
   /* ouput to store the service handle range.  This function returns   */
   /* zero if successful or a negative return error code if an error    */
   /* occurs.                                                           */
   /* *** NOTE *** Only 1 IPSS Server may be open at a time, per        */
   /*            Bluetooth Stack ID.                                    */
BTPSAPI_DECLARATION int BTPSAPI IPSP_Initialize_Node_Role(unsigned int BluetoothStackID, L2CA_LE_Channel_Parameters_t *ChannelParameters, IPSP_Event_Callback_t EventCallback, unsigned long CallbackParameter, GATT_Attribute_Handle_Group_t *ServiceHandleRange);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IPSP_Initialize_Node_Role_t)(unsigned int BluetoothStackID, L2CA_LE_Channel_Parameters_t *ChannelParameters, IPSP_Event_Callback_t EventCallback, unsigned long CallbackParameter, GATT_Attribute_Handle_Group_t *ServiceHandleRange);
#endif

   /* The following function is responsible for closing a previously    */
   /* opened IPSP Node.  The first parameter is the Bluetooth Stack ID  */
   /* on which to close the IPSP Node.  This function returns zero if   */
   /* successful or a negative return error code if an error occurs.    */
BTPSAPI_DECLARATION int BTPSAPI IPSP_Cleanup_Node_Role(unsigned int BluetoothStackID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IPSP_Cleanup_Node_Role_t)(unsigned int BluetoothStackID);
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
BTPSAPI_DECLARATION unsigned long BTPSAPI IPSP_Suspend(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef unsigned long (BTPSAPI *PFN_IPSP_Suspend_t)(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);
#endif

   /* The following function is used to perform a resume of the         */
   /* Bluetooth stack after a successful suspend has been performed (see*/
   /* IPSP_Suspend()).  This function accepts as input the Bluetooth    */
   /* Stack ID of the Bluetooth Stack that the Device is associated     */
   /* with.  The final two parameters are the buffer size and buffer    */
   /* that contains the memory that was used to collapse Bluetopia      */
   /* context into with a successfull call to IPSP_Suspend().  This     */
   /* function returns ZERO on success or a negative error code.        */
BTPSAPI_DECLARATION int BTPSAPI IPSP_Resume(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IPSP_Resume_t)(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);
#endif

   /* The following function is responsible for responding to requests  */
   /* to connect to a IPSP Node.  This function accepts as input the    */
   /* Bluetooth Stack ID of the Local Bluetooth Protocol Stack.  The    */
   /* second parameter is the IPSP Channel Identifier (CID) for the     */
   /* currently pending IPSP Connection.  The final parameter is a      */
   /* boolean for whether to accept the pending connection request or   */
   /* reject it.  This function returns zero if successful or a negative*/
   /* return error code if an error occurs.  .                          */
BTPSAPI_DECLARATION int BTPSAPI IPSP_Open_Connection_Request_Response(unsigned int BluetoothStackID, Word_t CID, Boolean_t AcceptConnection);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IPSP_Open_Connection_Request_Response_t)(unsigned int BluetoothStackID, Word_t CID, Boolean_t AcceptConnection);
#endif

   /* The following function is responsible for allowing a mechanism to */
   /* query the IPSP Node Connection Mode.  This function accepts as    */
   /* input the Bluetooth Stack ID of the Local Bluetooth Protocol Stack*/
   /* and as the final parameter a pointer to a Node Connection Mode    */
   /* variable which will receive the current Node Connection Mode.     */
   /* This function returns zero if successful, or a negative return    */
   /* value if there was an error.                                      */
BTPSAPI_DECLARATION int BTPSAPI IPSP_Get_Node_Connection_Mode(unsigned int BluetoothStackID, IPSP_Node_Connection_Mode_t *ConnectionMode);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IPSP_Get_Node_Connection_Mode_t)(unsigned int BluetoothStackID, IPSP_Node_Connection_Mode_t *ConnectionMode);
#endif

   /* The following function is responsible for allowing a mechanism to */
   /* change the current IPSP Node Connection Mode.  This function      */
   /* accepts as input the Bluetooth Stack ID of the Local Bluetooth    */
   /* Protocol Stack and as the final parameter the new Node Connection */
   /* Mode to use.  This function returns zero if successful, or a      */
   /* negative return value if there was an error.                      */
BTPSAPI_DECLARATION int BTPSAPI IPSP_Set_Node_Connection_Mode(unsigned int BluetoothStackID, IPSP_Node_Connection_Mode_t ConnectionMode);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IPSP_Set_Node_Connection_Mode_t)(unsigned int BluetoothStackID, IPSP_Node_Connection_Mode_t ConnectionMode);
#endif

   /* IPSP Router API.                                                  */


   /* The following function is responsible for requesting the creation */
   /* of an IPSP connection to a remote Node.  This function, accepts as*/
   /* input the Bluetooth Stack ID of the Bluetooth Stack to create the */
   /* IPSP connection.  The second parameter to this function is the    */
   /* Bluetooth address of the remote Node to establish the IPSP        */
   /* connection with.  The third parameter contains the IPSP Router's  */
   /* channel parameters to use for the IPSP connection.  The fourth    */
   /* parameter is the Callback function to call when an IPSP event     */
   /* occurs for this IPSP Node.  The final parameter is a user-defined */
   /* callback parameter that will be passed to the callback function   */
   /* with each IPSP event.  This function returns the positive,        */
   /* non-zero, channel identifier (CID) for the IPSP connection if     */
   /* successful or a negative return error code if an error occurs.    */
   /* * NOTE * Once a Connection is opened to a Remote Device it can    */
   /*          only be closed via a call to the IPSP_Close_Connection() */
   /*          function.                                                */
   /* * NOTE * A Positive return value does NOT mean that a IPSP        */
   /*          connection already exists, only that the IPSP connection */
   /*          request has been successfully submitted.                 */
   /* * NOTE * The ACL connection to the remote device must already     */
   /*          exist before calling this function.                      */
BTPSAPI_DECLARATION int BTPSAPI IPSP_Connect_Remote_Node(unsigned int BluetoothStackID, BD_ADDR_t BD_ADDR, L2CA_LE_Channel_Parameters_t *ChannelParameters, IPSP_Event_Callback_t EventCallback, unsigned long CallbackParameter);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IPSP_Connect_Remote_Node_t)(unsigned int BluetoothStackID, BD_ADDR_t BD_ADDR, L2CA_LE_Channel_Parameters_t *ChannelParameters, IPSP_Event_Callback_t EventCallback, unsigned long CallbackParameter);
#endif

   /* IPSP Common Role API.                                             */

   /* The following function is responsible for requesting an IPSP      */
   /* connection disconnection from a IPSP remote device.  The first    */
   /* parameter to this function is the Bluetooth stack ID of the       */
   /* Bluetooth Stack that is maintaining the IPSP Connection.  The     */
   /* second parameter is the Channel Identifier (CID) for the IPSP     */
   /* connection to close.  This function returns a zero value if the   */
   /* IPSP connection was terminated, or a negative, return error code  */
   /* if unsuccessful.  If this function completes successfully then an */
   /* IPSP Close Indication (etIPSP_Close_Indication) event will be sent*/
   /* to the IPSP Callback Function that was handling the IPSP Events   */
   /* for this connection.                                              */
BTPSAPI_DECLARATION int BTPSAPI IPSP_Close_Connection(unsigned int BluetoothStackID, Word_t CID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IPSP_Close_Connection_t)(unsigned int BluetoothStackID, Word_t CID);
#endif

   /* The following function is responsible for sending a packet over   */
   /* the established IPSP connection to the specified IPSP remote      */
   /* device.  This function provides additional functionality to       */
   /* control the amount of buffer usage for the IPSP connection.  The  */
   /* first parameter is the Bluetooth stack ID of the Bluetooth Stack  */
   /* that is maintaining the IPSP Connection.  The second parameter is */
   /* the Channel Identifier for the IPSP Connection (CID).  The third  */
   /* parameter is optional and is a pointer to a structure that        */
   /* contains conditional queueing parameters to control the handling  */
   /* of data packets.  The fourth and fifth parameters are the         */
   /* Data_Length of the Data Buffer and a pointer to the Data Buffer to*/
   /* Send.  If the QueueingParameters is NULL then this function       */
   /* returns a zero if the data was successfully sent.  If the         */
   /* QueueingParameters is not NULL then see below for possible return */
   /* values.  This function returns a negative return error code if    */
   /* unsuccessful.                                                     */
   /* * NOTE * If this function returns the Error Code:                 */
   /*          BTPS_ERROR_INSUFFICIENT_BUFFER_SPACE then this is a      */
   /*          signal to the caller that the requested data could NOT be*/
   /*          sent because the requested data could not be queued for  */
   /*          the IPSP connection.  The caller then, must wait for the */
   /*          etIPSP_Buffer_Empty_Indication Event before trying to    */
   /*          send any more data.                                      */
   /* * NOTE * If this function is called with a non-NULL               */
   /*          QueueingParameters then the data is queued conditionally.*/
   /*          If successful, the return value will indicate the number */
   /*          of packets/bytes that are currently queued for the IPSP  */
   /*          connection at the time the function returns.             */
BTPSAPI_DECLARATION int BTPSAPI IPSP_Send_Packet(unsigned int BluetoothStackID, Word_t CID, L2CA_Queueing_Parameters_t *QueueingParameters, Word_t Data_Length, Byte_t *Data);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IPSP_Send_Packet_t)(unsigned int BluetoothStackID, Word_t CID, L2CA_Queueing_Parameters_t *QueueingParameters, Word_t Data_Length, Byte_t *Data);
#endif

   /* The following function is responsible for allowing a mechanism of */
   /* granting the specified amount of credits for the IPSP Connection. */
   /* The first parameter is the Bluetooth Stack ID that identifies the */
   /* stack in which the data is currently queued.  The second parameter*/
   /* is the Channel Identifier (CID) for the IPSP Connection.  The     */
   /* final parameter is the total number of credits to grant for the   */
   /* IPSP connection.  This function returns zero if successful or a   */
   /* negative return error code if an error occurs.                    */
BTPSAPI_DECLARATION int BTPSAPI IPSP_Grant_Credits(unsigned int BluetoothStackID, Word_t CID, Word_t Credits);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IPSP_Grant_Credits_t)(unsigned int BluetoothStackID, Word_t CID, Word_t Credits);
#endif

#endif
