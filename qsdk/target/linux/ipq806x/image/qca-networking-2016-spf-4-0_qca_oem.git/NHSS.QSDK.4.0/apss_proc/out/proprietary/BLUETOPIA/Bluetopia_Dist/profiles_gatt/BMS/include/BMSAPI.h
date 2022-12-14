/*
* Copyright (c) 2016 Qualcomm Technologies, Inc.
* All Rights Reserved.
* Confidential and Proprietary - Qualcomm Technologies, Inc.
*/
/****< bmsapi.h >**************************************************************/
/*      Copyright 2015 - 2016 Qualcomm Technologies, Inc.                     */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*  BMSAPI - Qualcomm Technologies Bluetooth Bond Management Service (GATT    */
/*           based) API Type Definitions, Constants, and Prototypes.          */
/*                                                                            */
/*  Author:  Michael Rougeux                                                  */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   01/05/15  M. Rougeux     Initial creation.                               */
/******************************************************************************/
#ifndef __BMSAPIH__
#define __BMSAPIH__

#include "SS1BTPS.h"       /* Bluetooth Stack API Prototypes/Constants.       */
#include "SS1BTGAT.h"      /* Bluetooth Stack GATT API Prototypes/Constants.  */
#include "BMSTypes.h"      /* Bond Management Service Types/Constants.        */

   /* Error Return Codes.                                               */

   /* Error Codes that are smaller than these (less than -1000) are     */
   /* related to the Bluetooth Protocol Stack itself (see BTERRORS.H).  */
#define BMS_ERROR_INVALID_PARAMETER                      (-1000)
#define BMS_ERROR_INVALID_BLUETOOTH_STACK_ID             (-1001)
#define BMS_ERROR_INSUFFICIENT_RESOURCES                 (-1002)
#define BMS_ERROR_INSUFFICIENT_BUFFER_SPACE              (-1003)
#define BMS_ERROR_SERVICE_ALREADY_REGISTERED             (-1004)
#define BMS_ERROR_INVALID_INSTANCE_ID                    (-1005)
#define BMS_ERROR_MALFORMATTED_DATA                      (-1006)
#define BMS_ERROR_INVALID_FEATURE_FLAGS                  (-1007)

   /* The following defines the values of the Flags parameter that is   */
   /* provided in the BMS_Initialize_Service_...() API's.               */
#define BMS_FLAGS_SUPPORT_LE                             (BMS_SERVICE_FLAGS_LE)
#define BMS_FLAGS_SUPPORT_BR_EDR                         (BMS_SERVICE_FLAGS_BR_EDR)
#define BMS_FLAGS_SUPPORT_DUAL_MODE                      (BMS_SERVICE_FLAGS_DUAL_MODE)

   /* The following structure contains the handles that will need to be */
   /* cached by a BMS client in order to only do service discovery      */
   /* once.                                                             */
typedef struct _tagBMS_Client_Information_t
{
   Word_t  BM_Control_Point;
   Word_t  BM_Feature;
} BMS_Client_Information_t;

#define BMS_CLIENT_INFORMATION_DATA_SIZE                 (sizeof(BMS_Client_Information_t))

   /* The following enumerates the values that may be set as the value  */
   /* for the CommandType field of the BM Control Point Format Data.    */
typedef enum
{
   bmcDeleteBondRequestingBREDR_LE = BMS_BM_CONTROL_POINT_DELETE_BOND_REQUESTING_DEVICE_BREDR_LE,
   bmcDeleteBondRequestingBREDR    = BMS_BM_CONTROL_POINT_DELETE_BOND_REQUESTING_DEVICE_BREDR,
   bmcDeleteBondRequestingLE       = BMS_BM_CONTROL_POINT_DELETE_BOND_REQUESTING_DEVICE_LE,
   bmcDeleteAllBondsBREDR_LE       = BMS_BM_CONTROL_POINT_DELETE_BOND_ALL_DEVICES_BREDR_LE,
   bmcDeleteAllBondsBREDR          = BMS_BM_CONTROL_POINT_DELETE_BOND_ALL_DEVICES_BREDR,
   bmcDeleteAllBondsLE             = BMS_BM_CONTROL_POINT_DELETE_BOND_ALL_DEVICES_LE,
   bmcDeleteAllOtherBondsBREDR_LE  = BMS_BM_CONTROL_POINT_DELETE_BOND_OTHER_DEVICES_BREDR_LE,
   bmcDeleteAllOtherBondsBREDR     = BMS_BM_CONTROL_POINT_DELETE_BOND_OTHER_DEVICES_BREDR,
   bmcDeleteAllOtherBondsLE        = BMS_BM_CONTROL_POINT_DELETE_BOND_OTHER_DEVICES_LE
} BMS_BMCP_Command_Type_t;

   /* The following structure defines the format of the BMS BM Control  */
   /* Point Command Data. This structure is passed as a parameter to    */
   /* BMS_Format_BM_Control_Point_Command API.                          */
typedef struct _tagBMS_BM_Control_Point_Format_Data_t
{
   BMS_BMCP_Command_Type_t  CommandType;
   unsigned int             AuthorizationCodeLength;
   Byte_t                  *AuthorizationCode;
} BMS_BM_Control_Point_Format_Data_t;

#define BMS_BM_CONTROL_POINT_FORMAT_DATA_SIZE            (sizeof(BMS_BM_Control_Point_Format_Data_t))

   /* The following enumeration covers all the events generated by the  */
   /* BMS Service. These are used to determine the type of each event   */
   /* generated and to ensure the proper union element is accessed for  */
   /* the BMS_Event_Data_t structure.                                   */
typedef enum
{
   etBMS_BM_Control_Point_Command
} BMS_Event_Type_t;

   /* The following is dispatched to a BMS Server in response to the    */
   /* reception of a request from a Client to write to the BM Control   */
   /* Point.                                                            */
typedef struct _tagBMS_BM_Control_Point_Command_Data_t
{
   unsigned int                       InstanceID;
   unsigned int                       ConnectionID;
   unsigned int                       TransactionID;
   GATT_Connection_Type_t             ConnectionType;
   BD_ADDR_t                          RemoteDevice;
   BMS_BM_Control_Point_Format_Data_t FormatData;
} BMS_BM_Control_Point_Command_Data_t;

#define BMS_BM_CONTROL_POINT_COMMAND_DATA_SIZE           (sizeof(BMS_BM_Control_Point_Command_Data_t))

   /* The following structure holds all BMS Service Event Data. This    */
   /* structure is received for each event generated. The               */
   /* Event_Data_Type member is used to determine the appropriate union */
   /* member element to access the contained data. The Event_Data_Size  */
   /* member contains the total size of the data contained in this      */
   /* event.                                                            */
typedef struct _tagBMS_Event_Data_t
{
   BMS_Event_Type_t Event_Data_Type;
   Word_t           Event_Data_Size;
   union
   {
      BMS_BM_Control_Point_Command_Data_t    *BMS_BM_Control_Point_Command_Data;
   } Event_Data;
} BMS_Event_Data_t;

#define BMS_EVENT_DATA_SIZE                              (sizeof(BMS_Event_Data_t))

   /* The following declared type represents the Prototype Function for */
   /* a BMS Service Event Callback. This function will be called        */
   /* whenever a BMS Service Event occurs that is associated with the   */
   /* specified Bluetooth Stack ID. This function passes to the caller  */
   /* the Bluetooth Stack ID, the BMS Event Data that occurred, and the */
   /* BMS Service Event Callback Parameter that was specified when this */
   /* Callback was installed. The caller is free to use the contents of */
   /* the BMS Service Event Data ONLY in the context of this callback.  */
   /* If the caller requires the Data for a longer period of time, then */
   /* the callback function MUST copy the data into another Data        */
   /* Buffer. This function is guaranteed NOT to be invoked more than   */
   /* once simultaneously for the specified installed callback (i.e.    */
   /* this function DOES NOT have be re-entrant). It needs to be noted  */
   /* however, that if the same Callback is installed more than once,   */
   /* then the callbacks will be called serially. Because of this, the  */
   /* processing in this function should be as efficient as possible.   */
   /* It should also be noted that this function is called in the       */
   /* Thread Context of a Thread that the User does NOT own. Therefore, */
   /* processing in this function should be as efficient as possible    */
   /* (this argument holds anyway because another BMS Service Event     */
   /* will not be processed while this function call is outstanding).   */
   /* * NOTE * This function MUST NOT block and wait for events that    */
   /*          can only be satisfied by receiving BMS Service Event     */
   /*          Packets. A Deadlock WILL occur because NO BMS Event      */
   /*          Callbacks will be issued while this function is          */
   /*          currently outstanding.                                   */
typedef void (BTPSAPI *BMS_Event_Callback_t)(unsigned int BluetoothStackID, BMS_Event_Data_t *BMS_Event_Data, unsigned long CallbackParameter);

   /* BMS Server API.                                                   */

   /* The following function is responsible for opening a BMS Server.   */
   /* The first parameter is the Bluetooth Stack ID on which to open the*/
   /* server.  The second parameter will specify the BMS Service Flags  */
   /* (BMS_FLAGS_...).  These flags MUST be used to register the GATT   */
   /* service for LE, BR/EDR, or both.  The third parameter is the      */
   /* Callback function to call when an event occurs on this Server     */
   /* Port.  The fourth parameter is a user-defined callback parameter  */
   /* that will be passed to the callback function with each event.  The*/
   /* final parameter is a pointer to store the GATT Service ID of the  */
   /* registered BMS service.  This function returns the positive,      */
   /* non-zero, Instance ID or a negative error code.                   */
   /* * NOTE * Only 1 BMS Server may be open at a time, per Bluetooth   */
   /*          Stack ID.                                                */
   /* * NOTE * All Client Requests will be dispatched to the            */
   /*          EventCallback function that is specified by the second   */
   /*          parameter to this function.                              */
   /* * NOTE * If BR/EDR is not supported by the Bluetopia configuration*/
   /*          then the BMS_SERVICE_FLAGS_BR_EDR bit will be cleared in */
   /*          the Flags parameter and the SDP Record will not be       */
   /*          registered.  If the BMS_SERVICE_FLAGS_LE bit is also set,*/
   /*          then this function will still return success even though */
   /*          the GATT service was not registered for BR/EDR.          */
BTPSAPI_DECLARATION int BTPSAPI BMS_Initialize_Service(unsigned int BluetoothStackID, unsigned int Flags, BMS_Event_Callback_t EventCallback, unsigned long CallbackParameter, unsigned int *ServiceID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_BMS_Initialize_Service_t)(unsigned int BluetoothStackID, unsigned int Flags, BMS_Event_Callback_t EventCallback, unsigned long CallbackParameter, unsigned int *ServiceID);
#endif

   /* The following function is responsible for opening a BMS Server.   */
   /* The first parameter is the Bluetooth Stack ID on which to open the*/
   /* server.  The second parameter will specify the BMS Service Flags  */
   /* (BMS_FLAGS_...).  These flags MUST be used to register the GATT   */
   /* service for LE, BR/EDR, or both.  The third parameter is the      */
   /* Callback function to call when an event occurs on this Server     */
   /* Port.  The fourth parameter is a user-defined callback parameter  */
   /* that will be passed to the callback function with each event.  The*/
   /* fifth parameter is a pointer to store the GATT Service ID of the  */
   /* registered BMS service.  The final parameter is a pointer, that on*/
   /* input can be used to control the location of the service in the   */
   /* GATT database, and on ouput to store the service handle range.    */
   /* This function returns the positive, non-zero, Instance ID or a    */
   /* negative error code.                                              */
   /* * NOTE * Only 1 BMS Server may be open at a time, per Bluetooth   */
   /*          Stack ID.                                                */
   /* * NOTE * All Client Requests will be dispatched to the            */
   /*          EventCallback function that is specified by the second   */
   /*          parameter to this function.                              */
   /* * NOTE * If BR/EDR is not supported by the Bluetopia configuration*/
   /*          then the BMS_SERVICE_FLAGS_BR_EDR bit will be cleared in */
   /*          the Flags parameter and the SDP Record will not be       */
   /*          registered.  If the BMS_SERVICE_FLAGS_LE bit is also set,*/
   /*          then this function will still return success even though */
   /*          the GATT service was not registered for BR/EDR.          */
BTPSAPI_DECLARATION int BTPSAPI BMS_Initialize_Service_Handle_Range(unsigned int BluetoothStackID, unsigned int Flags, BMS_Event_Callback_t EventCallback, unsigned long CallbackParameter, unsigned int *ServiceID, GATT_Attribute_Handle_Group_t *ServiceHandleRange);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_BMS_Initialize_Service_Handle_Range_t)(unsigned int BluetoothStackID, unsigned int Flags, BMS_Event_Callback_t EventCallback, unsigned long CallbackParameter, unsigned int *ServiceID, GATT_Attribute_Handle_Group_t *ServiceHandleRange);
#endif

   /* The following function is responsible for closing a previously    */
   /* opened BMS Server. The first parameter is the Bluetooth Stack ID  */
   /* on which to close the server. The second parameter is the         */
   /* InstanceID that was returned from a successfull call to           */
   /* BMS_Initialize_Service(). This function returns zero if           */
   /* successful or a negative error code.                              */
BTPSAPI_DECLARATION int BTPSAPI BMS_Cleanup_Service(unsigned int BluetoothStackID, unsigned int InstanceID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_BMS_Cleanup_Service_t)(unsigned int BluetoothStackID, unsigned int InstanceID);
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
BTPSAPI_DECLARATION unsigned long BTPSAPI BMS_Suspend(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef unsigned long (BTPSAPI *PFN_BMS_Suspend_t)(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);
#endif

   /* The following function is used to perform a resume of the         */
   /* Bluetooth stack after a successful suspend has been performed (see*/
   /* BMS_Suspend()).  This function accepts as input the Bluetooth     */
   /* Stack ID of the Bluetooth Stack that the Device is associated     */
   /* with.  The final two parameters are the buffer size and buffer    */
   /* that contains the memory that was used to collapse Bluetopia      */
   /* context into with a successfully call to BMS_Suspend().  This     */
   /* function returns ZERO on success or a negative error code.        */
BTPSAPI_DECLARATION int BTPSAPI BMS_Resume(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_BMS_Resume_t)(unsigned int BluetoothStackID, unsigned long BufferSize, void *Buffer);
#endif

   /* The following function is responsible for querying the number of  */
   /* attributes that are contained in the BMS Service that is          */
   /* registered with a call to BMS_Initialize_Service().  This function*/
   /* returns the non-zero number of attributes that are contained in a */
   /* BMS Server or zero on failure.                                    */
BTPSAPI_DECLARATION unsigned int BTPSAPI BMS_Query_Number_Attributes(void);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef unsigned int (BTPSAPI *PFN_BMS_Query_Number_Attributes_t)(void);
#endif

   /* The following function is responsible for setting the supported BM*/
   /* features on the specified BMS Instance.  The first parameter is   */
   /* the Bluetooth Stack ID of the Bluetooth Device.  The second       */
   /* parameter is the InstanceID returned from a successful call to    */
   /* BMS_Initialize_Server().  The final parameter is the supported    */
   /* features to set for the specified BMS Instance.  This function    */
   /* returns zero if successful or a negative error code.              */
   /* * NOTE * The SupportedFeatures parameter is a bitmask made up of  */
   /*          bits of the from BMS_BM_FEATURE_FLAG_XXX.  The           */
   /*          SupportedFeatures MUST include flags for the transport   */
   /*          being used by the service                                */
   /* * NOTE * This function will clear any SupportedFeatures that do   */
   /*          not correspond to the transport being used by the        */
   /*          service.  The error BMS_ERROR_INVALID_FEATURE_FLAGS will */
   /*          be returned if all the bits are cleared for the          */
   /*          SupportedFeatures.                                       */
BTPSAPI_DECLARATION int BTPSAPI BMS_Set_BM_Features(unsigned int BluetoothStackID, unsigned int InstanceID, DWord_t SupportedFeatures);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_BMS_Set_BM_Features_t)(unsigned int BluetoothStackID, unsigned int InstanceID, DWord_t SupportedFeatures);
#endif

   /* The following function is responsible for querying the BMS        */
   /* Features on the specified BMS Instance. The first parameter is    */
   /* the Bluetooth Stack ID of the Bluetooth Device. The second        */
   /* parameter is the InstanceID returned from a successful call to    */
   /* BMS_Initialize_Server(). The final parameter is a pointer to      */
   /* return the BMS Features for the specified BMS Instance. This      */
   /* function returns zero if successful or a negative error code.     */
   /* * NOTE * The SupportedFeatures parameter is a bitmask made up of  */
   /*          bits of the form BMS_BM_FEATURE_FLAG_XXX.                */
BTPSAPI_DECLARATION int BTPSAPI BMS_Query_BM_Features(unsigned int BluetoothStackID, unsigned int InstanceID, DWord_t *SupportedFeatures);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_BMS_Query_BM_Features_t)(unsigned int BluetoothStackID, unsigned int InstanceID, DWord_t *SupportedFeatures);
#endif

   /* The following function is responsible for responding to a BM      */
   /* Control Point Command received from a remote device. The first    */
   /* parameter is the Bluetooth Stack ID of the Bluetooth Device. The  */
   /* second parameter is the TransactionID that was received in the BM */
   /* Control Point event. The final parameter is an error code that is */
   /* used to determine if the Request is being accepted by the server  */
   /* or if an error response should be issued instead. This function   */
   /* returns zero if successful or a negative error code.              */
   /* * NOTE * The ResponseCode provided must match the following       */
   /*          evaluation criteria in the FOLLOWING ORDER:              */
   /*          1) If the Operation was successful, ResponseCode should  */
   /*          be set to BMS_ERROR_CODE_SUCCESS.                        */
   /*          2) If the Operation is not supported, ResponseCode       */
   /*          should be set to                                         */
   /*          BMS_ERROR_CODE_OPCODE_NOT_SUPPORTED.                     */
   /*          3) If Authorization is required, and the Authorization   */
   /*          Code Parameter does not match the required Code stored   */
   /*          by the server (or the user denies Authorization through  */
   /*          the server's UI), then ResponseCode should be set to     */
   /*          ATT_PROTOCOL_ERROR_CODE_INSUFFICIENT_AUTHORIZATION.      */
   /*          4) If the operation fails for any reason not specified   */
   /*          above then the ResponseCode should be set to             */
   /*          BMS_ERROR_CODE_OPERATION_FAILED.                         */
BTPSAPI_DECLARATION int BTPSAPI BMS_BM_Control_Point_Response(unsigned int BluetoothStackID, unsigned int TransactionID, Byte_t ResponseCode);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_BMS_BM_Control_Point_Response_t)(unsigned int BluetoothStackID, unsigned int TransactionID, Byte_t ResponseCode);
#endif

   /* BMS Client API.                                                   */

   /* The following function is responsible for formatting a BM Control */
   /* Point Command into a user specified buffer. The first parameter   */
   /* is the input command to format. The second parameter is the size  */
   /* of the input BM Control Point Command Data. The final parameter   */
   /* is the output that will contain data in Buffer after formatting.  */
   /* This function returns zero if successful or a negative error.     */
   /* * NOTE * The BufferLength is the size of FormatData, and will     */
   /*          also hold the size of the output Buffer after            */
   /*          formatting.                                              */
BTPSAPI_DECLARATION int BTPSAPI BMS_Format_BM_Control_Point_Command(BMS_BM_Control_Point_Format_Data_t *FormatData, unsigned int *BufferLength, Byte_t *Buffer);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_BMS_Format_BM_Control_Point_Command_t)(BMS_BM_Control_Point_Format_Data_t *FormatData, unsigned int *BufferLength, Byte_t *Buffer);
#endif

#endif
