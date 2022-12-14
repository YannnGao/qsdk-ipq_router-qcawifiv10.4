/*****< hfreapi.h >************************************************************/
/*      Copyright 2000 - 2014 Stonestreet One.                                */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*  HFREAPI -  Stonestreet One Bluetooth Stack Hands-Free Profile API Type    */
/*             Definitions, Constants, and Prototypes.                        */
/*                                                                            */
/*  Author:  Damon Lange                                                      */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   08/18/01  D. Lange       Initial creation.                               */
/*   01/29/02  R. Sledge      Altered for Hands-Free Profile.                 */
/*   11/06/07  J. Toole       Modifications for HFRE 1.5 Support.             */
/******************************************************************************/
#ifndef __HFREAPIH__
#define __HFREAPIH__

#include "SS1BTPS.h"            /* Bluetooth Stack API Prototypes/Constants.  */

   /* Error Return Codes.                                               */

   /* Error Codes that are smaller than these (less than -1000) are     */
   /* related to the Bluetooth Protocol Stack itself (see BTERRORS.H).  */
#define BTHFRE_ERROR_INVALID_PARAMETER                           (-1000)
#define BTHFRE_ERROR_NOT_INITIALIZED                             (-1001)
#define BTHFRE_ERROR_INVALID_BLUETOOTH_STACK_ID                  (-1002)
#define BTHFRE_ERROR_LIBRARY_INITIALIZATION_ERROR                (-1003)
#define BTHFRE_ERROR_INSUFFICIENT_RESOURCES                      (-1004)
#define BTHFRE_ERROR_INVALID_OPERATION                           (-1005)
#define BTHFRE_ERROR_INVALID_CODEC_ID                            (-1006)

   /* SDP Service Classes for the Hands-Free Profile.                   */

   /* The following MACRO is a utility MACRO that assigns the Hands-Free*/
   /* Service Class Bluetooth Universally Unique Identifier             */
   /* (HANDSFREE_PROFILE_UUID_16) to the specified UUID_16_t variable.  */
   /* This MACRO accepts one parameter which is the UUID_16_t variable  */
   /* that is to receive the HANDSFREE_PROFILE_UUID_16 Constant value.  */
#define SDP_ASSIGN_HANDSFREE_PROFILE_UUID_16(_x)             ASSIGN_SDP_UUID_16((_x), 0x11, 0x1E)

   /* The following MACRO is a utility MACRO that assigns the Hands-Free*/
   /* Service Class Bluetooth Universally Unique Identifier             */
   /* (HANDSFREE_PROFILE_UUID_32) to the specified UUID_32_t variable.  */
   /* This MACRO accepts one parameter which is the UUID_32_t variable  */
   /* that is to receive the HANDSFREE_PROFILE_UUID_32 Constant value.  */
#define SDP_ASSIGN_HANDSFREE_PROFILE_UUID_32(_x)             ASSIGN_SDP_UUID_32((_x), 0x00, 0x00, 0x11, 0x1E)

   /* The following MACRO is a utility MACRO that assigns the Hands-Free*/
   /* Service Class Bluetooth Universally Unique Identifier             */
   /* (HANDSFREE_PROFILE_UUID_128) to the specified UUID_128_t variable.*/
   /* This MACRO accepts one parameter which is the UUID_128_t variable */
   /* that is to receive the HANDSFREE_PROFILE_UUID_128 Constant value. */
#define SDP_ASSIGN_HANDSFREE_PROFILE_UUID_128(_x)            ASSIGN_SDP_UUID_128((_x), 0x00, 0x00, 0x11, 0x1E, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5F, 0x9B, 0x34, 0xFB)

   /* The following MACRO is a utility MACRO that assigns the Hands-Free*/
   /* Audio Gateway Service Class Bluetooth Universally Unique          */
   /* Identifier (HANDSFREE_AUDIO_GATEWAY_PROFILE_UUID_16) to the       */
   /* specified UUID_16_t variable.  This MACRO accepts one parameter   */
   /* which is the UUID_16_t variable that is to receive the            */
   /* HANDSFREE_AUDIO_GATEWAY_PROFILE_UUID_16 Constant value.           */
#define SDP_ASSIGN_HANDSFREE_AUDIO_GATEWAY_PROFILE_UUID_16(_x) ASSIGN_SDP_UUID_16((_x), 0x11, 0x1F)

   /* The following MACRO is a utility MACRO that assigns the Hands-Free*/
   /* Audio Gateway Service Class Bluetooth Universally Unique          */
   /* Identifier (HANDSFREE_AUDIO_GATEWAY_PROFILE_UUID_32) to the       */
   /* specified UUID_32_t variable.  This MACRO accepts one parameter   */
   /* which is the UUID_32_t variable that is to receive the            */
   /* HANDSFREE_AUDIO_GATEWAY_PROFILE_UUID_32 Constant value.           */
#define SDP_ASSIGN_HANDSFREE_AUDIO_GATEWAY_PROFILE_UUID_32(_x) ASSIGN_SDP_UUID_32((_x), 0x00, 0x00, 0x11, 0x1F)

   /* The following MACRO is a utility MACRO that assigns the Hand-Free */
   /* Audio Gateway Service Class Bluetooth Universally Unique          */
   /* Identifier (HANDSFREE_AUDIO_GATEWAY_PROFILE_UUID_128) to the      */
   /* specified UUID_128_t variable.  This MACRO accepts one parameter  */
   /* which is the UUID_128_t variable that is to receive the           */
   /* HANDSFREE_AUDIO_GATEWAY_PROFILE_UUID_128 Constant value.          */
#define SDP_ASSIGN_HANDSFREE_AUDIO_GATEWAY_PROFILE_UUID_128(_x) ASSIGN_SDP_UUID_128((_x), 0x00, 0x00, 0x11, 0x1F, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5F, 0x9B, 0x34, 0xFB)

   /* Defines the Profile Version Number used within the SDP Record for */
   /* Handsfree Profile Servers (both Audio Gateway and Handsfree).     */
#define HFRE_PROFILE_VERSION                                    (0x0106)

   /* The following Bit Definitions represent the Hands-Free Server     */
   /* supported features.  These Bit Definitions are used with the      */
   /* HFRE_Open_HandsFree_Server_Port() function to specify the features*/
   /* supported by the server.                                          */
#define HFRE_HF_SOUND_ENHANCEMENT_SUPPORTED_BIT                 0x00000001
#define HFRE_CALL_WAITING_THREE_WAY_CALLING_SUPPORTED_BIT       0x00000002
#define HFRE_CLI_SUPPORTED_BIT                                  0x00000004
#define HFRE_HF_VOICE_RECOGNITION_SUPPORTED_BIT                 0x00000008
#define HFRE_REMOTE_VOLUME_CONTROL_SUPPORTED_BIT                0x00000010
#define HFRE_HF_ENHANCED_CALL_STATUS_SUPPORTED_BIT              0x00000020
#define HFRE_HF_ENHANCED_CALL_CONTROL_SUPPORTED_BIT             0x00000040
#define HFRE_HF_CODEC_NEGOTIATION_SUPPORTED_BIT                 0x00000080

#define HFRE_DEFAULT_HANDSFREE_BIT_MASK                         0x00000000

   /* The following Bit Definitions represent the Audio Gateway Server  */
   /* supported features.  These Bit Definitions are used with the      */
   /* HFRE_Open_Audio_Gateway_Server_Port() function to specify the     */
   /* features supported by the server.                                 */
#define HFRE_THREE_WAY_CALLING_SUPPORTED_BIT                    0x00000001
#define HFRE_AG_SOUND_ENHANCEMENT_SUPPORTED_BIT                 0x00000002
#define HFRE_AG_VOICE_RECOGNITION_SUPPORTED_BIT                 0x00000004
#define HFRE_INBAND_RINGING_SUPPORTED_BIT                       0x00000008
#define HFRE_VOICE_TAGS_SUPPORTED_BIT                           0x00000010
#define HFRE_REJECT_CALL_SUPPORT_BIT                            0x00000020
#define HFRE_AG_ENHANCED_CALL_STATUS_SUPPORTED_BIT              0x00000040
#define HFRE_AG_ENHANCED_CALL_CONTROL_SUPPORTED_BIT             0x00000080
#define HFRE_AG_EXTENDED_ERROR_RESULT_CODES_SUPPORTED_BIT       0x00000100
#define HFRE_AG_CODEC_NEGOTIATION_SUPPORTED_BIT                 0x00000200

#define HFRE_DEFAULT_AUDIO_GATEWAY_BIT_MASK                     (HFRE_THREE_WAY_CALLING_SUPPORTED_BIT | HFRE_INBAND_RINGING_SUPPORTED_BIT)

   /* The following Bit Definition can be set in the supported features */
   /* mask that is passed to the HFRE_Open_Audio_Gateway_Server_Port()  */
   /* and HFRE_Open_Remote_HandsFree_Port() APIs.  When this bit is set */
   /* then an etHFRE_Control_Indicator_Request_Indication event will be */
   /* dispatched to the Audio Gateway event callback whenever the remote*/
   /* Hands Free devices queries the current values of the control      */
   /* indicators.  It is then the responsibility of the application to  */
   /* update the control indicators and call the                        */
   /* HFRE_Send_Control_Indicator_Request_Response() API to respond to  */
   /* the query.                                                        */
#define HFRE_AG_QUERY_INDICATOR_REQUEST_SUPPORTED_BIT           0x80000000

   /* The following Bit Definitions define the call hold and multiparty */
   /* support handling which can be supported by the Audio Gateway.     */
#define HFRE_RELEASE_ALL_HELD_CALLS                             0x00000001
#define HFRE_RELEASE_ALL_ACTIVE_CALLS_ACCEPT_WAITING_CALL       0x00000002
#define HFRE_PLACE_ALL_ACTIVE_CALLS_ON_HOLD_ACCEPT_THE_OTHER    0x00000004
#define HFRE_ADD_A_HELD_CALL_TO_CONVERSATION                    0x00000008
#define HFRE_CONNECT_TWO_CALLS_DISCONNECT_SUBSCRIBER            0x00000010
#define HFRE_RELEASE_SPECIFIED_ACTIVE_CALL_ONLY                 0x00000020
#define HFRE_REQUEST_PRIVATE_CONSULTATION_MODE                  0x00000040

#define HFRE_CALL_HOLD_MULTIPARTY_SUPPORTED_FEATURES_ERROR      0x00000000

   /* The following constant represents the Maximum Control Indicator   */
   /* Description Length.  Note that this value must be at least greater*/
   /* then the length of the longest mandatory Control Indicator        */
   /* Descriptor.                                                       */
#define HFRE_CONTROL_INDICATOR_DESCRIPTION_LENGTH_MAXIMUM               32

   /* The following constant represents the Minimum and Maximum         */
   /* allowable lengths for phone number strings when used with         */
   /* functions requiring phone number as a parameter.                  */
#define HFRE_PHONE_NUMBER_LENGTH_MINIMUM                                 1
#define HFRE_PHONE_NUMBER_LENGTH_MAXIMUM                                64

   /* The following constant represents the Minimum and Maximum         */
   /* allowable lengths for phonebook name strings when used with       */
   /* functions requiring a phonebook name as a parameter.              */
#define HFRE_PHONEBOOK_NAME_LENGTH_MINIMUM                               1
#define HFRE_PHONEBOOK_NAME_LENGTH_MAXIMUM                              64

   /* The following constant represents the Minimum and Maximum         */
   /* allowable lengths for the network operator strings when used with */
   /* function requiring network operators as a parameter.              */
#define HFRE_NETWORK_OPERATOR_LENGTH_MINIMUM                             1
#define HFRE_NETWORK_OPERATOR_LENGTH_MAXIMUM                            16

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the Speaker Gain.                            */
#define HFRE_SPEAKER_GAIN_MINIMUM                                        0
#define HFRE_SPEAKER_GAIN_MAXIMUM                                       15

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the Microphone Gain.                         */
#define HFRE_MICROPHONE_GAIN_MINIMUM                                     0
#define HFRE_MICROPHONE_GAIN_MAXIMUM                                    15

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the service Indicator.                       */
#define HFRE_SERVICE_INDICATOR_MINIMUM                                   0
#define HFRE_SERVICE_INDICATOR_MAXIMUM                                   1

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the call Indicator.                          */
#define HFRE_CALL_INDICATOR_MINIMUM                                      0
#define HFRE_CALL_INDICATOR_MAXIMUM                                      1

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the callsetup Indicator.                     */
#define HFRE_CALLSETUP_INDICATOR_MINIMUM                                 0
#define HFRE_CALLSETUP_INDICATOR_MAXIMUM                                 3

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the callheld Indicator.                      */
#define HFRE_CALLHELD_INDICATOR_MINIMUM                                  0
#define HFRE_CALLHELD_INDICATOR_MAXIMUM                                  2

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the signal (Signal Strength) Indicator.      */
#define HFRE_SIGNAL_INDICATOR_MINIMUM                                    0
#define HFRE_SIGNAL_INDICATOR_MAXIMUM                                    5

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the roam Indicator.                          */
#define HFRE_ROAM_INDICATOR_MINIMUM                                      0
#define HFRE_ROAM_INDICATOR_MAXIMUM                                      1

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the battchg (Battery Charge) Indicator.      */
#define HFRE_BATTCHG_INDICATOR_MINIMUM                                   0
#define HFRE_BATTCHG_INDICATOR_MAXIMUM                                   5

   /* The following constant define the service types that can be used  */
   /* for subscriber number information.                                */
#define HFRE_SERVICE_TYPE_VOICE                                          4
#define HFRE_SERVICE_TYPE_FAX                                            5

   /* The following BIT definitions are used to denote the possible     */
   /* Handsfree Profile Server Modes that can be applied to a Handsfree */
   /* Profile Client Connection.  These BIT definitions are used with   */
   /* the HFRE_Set_Server_Mode() and HFRE_Get_Server_Mode() mode        */
   /* functions.                                                        */
#define HFRE_SERVER_MODE_AUTOMATIC_ACCEPT_CONNECTION                     0x00000000
#define HFRE_SERVER_MODE_MANUAL_ACCEPT_CONNECTION                        0x00000001

   /* The following BIT MASK is used to mask the Server Mode Accept     */
   /* Connection settings from other (undefined) Server Mode bits.      */
#define HFRE_SERVER_MODE_CONNECTION_MASK                                 0x00000001

   /* The following constants represent the Port Open Status Values     */
   /* that are possible in the Port Open Confirmation Event.            */
#define HFRE_OPEN_PORT_STATUS_SUCCESS                                  0x00
#define HFRE_OPEN_PORT_STATUS_CONNECTION_TIMEOUT                       0x01
#define HFRE_OPEN_PORT_STATUS_CONNECTION_REFUSED                       0x02
#define HFRE_OPEN_PORT_STATUS_UNKNOWN_ERROR                            0x03

   /* The following constants represent the Port Close Status Values    */
   /* that are possible in the Port Close Indication Event.             */
#define HFRE_CLOSE_PORT_STATUS_SUCCESS                                 0x00
#define HFRE_CLOSE_PORT_STATUS_SERVICE_LEVEL_CONNECTION_ERROR          0x01

#define HFRE_AUDIO_CONNECTION_STATUS_SUCCESS                           0x00
#define HFRE_AUDIO_CONNECTION_STATUS_UNKNOWN_ERROR                     0x01

   /* The following constants represent the Network Type Values that are*/
   /* possible for use with the HFRE_Register_Audio_Gateway_SDP_Record()*/
   /* function.                                                         */
#define HFRE_NETWORK_TYPE_NO_ABILITY_TO_REJECT_CALLS                   0x00
#define HFRE_NETWORK_TYPE_ABILITY_TO_REJECT_CALLS                      0x01

   /* The following constant is the default numbering format provided   */
   /* for application usage in cases where the numbering format is a    */
   /* domestic (not international) numbering format.  See the GSM       */
   /* specifications for more information.                              */
#define HFRE_DEFAULT_NUMBER_FORMAT                                     (129)

   /* The following constant is the default numbering format provided   */
   /* for application usage in cases where the numbering format is an   */
   /* international (+) numbering format.  See the GSM specifications   */
   /* for more information.                                             */
#define HFRE_DEFAULT_NUMBER_FORMAT_INTERNATIONAL                       (145)

   /* The following constant define the values that can be used for     */
   /* network mode information.  Generally this information is ignored  */
   /* by HFRE.                                                          */
#define HFRE_NETWORK_MODE_AUTOMATIC                                    (0)
#define HFRE_NETWORK_MODE_MANUAL                                       (1)
#define HFRE_NETWORK_MODE_DEREGISTER                                   (2)
#define HFRE_NETWORK_MODE_SETONLY                                      (3)
#define HFRE_NETWORK_MODE_MANUAL_AUTO                                  (4)

   /* The following constants define the values that can be used for the*/
   /* Extended Error Result codes.                                      */
#define HFRE_EXTENDED_ERROR_RESULT_AG_FAILURE                          (0)
#define HFRE_EXTENDED_ERROR_RESULT_NO_CONNECTION_TO_PHONE              (1)
#define HFRE_EXTENDED_ERROR_RESULT_OPERATION_NOT_ALLOWED               (3)
#define HFRE_EXTENDED_ERROR_RESULT_OPERATION_NOT_SUPPORTED             (4)
#define HFRE_EXTENDED_ERROR_RESULT_PH_SIM_PIN_REQUIRED                 (5)
#define HFRE_EXTENDED_ERROR_RESULT_SIM_NOT_INSERTED                    (10)
#define HFRE_EXTENDED_ERROR_RESULT_SIM_PIN_REQUIRED                    (11)
#define HFRE_EXTENDED_ERROR_RESULT_SIM_PUK_REQUIRED                    (12)
#define HFRE_EXTENDED_ERROR_RESULT_SIM_FAILURE                         (13)
#define HFRE_EXTENDED_ERROR_RESULT_SIM_BUSY                            (14)
#define HFRE_EXTENDED_ERROR_RESULT_INCORRECT_PASSWORD                  (16)
#define HFRE_EXTENDED_ERROR_RESULT_SIM_PIN2_REQUIRED                   (17)
#define HFRE_EXTENDED_ERROR_RESULT_SIM_PUK2_REQUIRED                   (18)
#define HFRE_EXTENDED_ERROR_RESULT_MEMORY_FULL                         (20)
#define HFRE_EXTENDED_ERROR_RESULT_INVALID_INDEX                       (21)
#define HFRE_EXTENDED_ERROR_RESULT_MEMORY_FAILURE                      (23)
#define HFRE_EXTENDED_ERROR_RESULT_TEXT_STRING_TOO_LONG                (24)
#define HFRE_EXTENDED_ERROR_RESULT_INVALID_CHARACTERS_IN_TEXT_STRING   (25)
#define HFRE_EXTENDED_ERROR_RESULT_DIAL_STRING_TOO_LONG                (26)
#define HFRE_EXTENDED_ERROR_RESULT_INVALID_CHARACTERS_IN_DIAL_STRING   (27)
#define HFRE_EXTENDED_ERROR_RESULT_NO_NETWORK_SERVICE                  (30)
#define HFRE_EXTENDED_ERROR_RESULT_NETWORK_TIMEOUT                     (31)
#define HFRE_EXTENDED_ERROR_RESULT_EMERGENCY_CALLS_ONLY                (32)

   /* The following defines the maximum number of Codecs that are       */
   /* supported in this implementation.                                 */
   /* * NOTE * This value is used to identify that amount of RAM        */
   /*          required to manage the CODECs.  There is a MAX limit for */
   /*          this implementation that will prevent this from being    */
   /*          larger than 32.                                          */
#define HFRE_MAX_SUPPORTED_CODECS                                      2

   /* The following defines the CODEC IDs that are supported by this    */
   /* implementation.                                                   */
#define HFRE_CVSD_CODEC_ID                                             1
#define HFRE_MSBC_CODEC_ID                                             2

   /* The following enumerated type represents the available types for  */
   /* the controlling of multiple concurrent calls.                     */
typedef enum
{
   chReleaseAllHeldCalls,
   chReleaseAllActiveCallsAcceptWaitingCall,
   chPlaceAllActiveCallsOnHoldAcceptTheOther,
   chAddAHeldCallToConversation,
   chConnectTwoCallsAndDisconnect,
   chReleaseSpecifiedCallIndex,
   chPrivateConsultationMode
} HFRE_Call_Hold_Multiparty_Handling_Type_t;

   /* The following enumerated type represents all of the allowable     */
   /* types that may be parsed from an Indicator Control Response.      */
typedef enum
{
   ciBoolean,
   ciRange
} HFRE_Control_Indicator_Type_t;

   /* The following structure is used hold the Current Indicator Value  */
   /* for Indicators of the ciBoolean Type.                             */
typedef struct _tagHFRE_Control_Indicator_Boolean_Type_t
{
   Boolean_t CurrentIndicatorValue;
} HFRE_Control_Indicator_Boolean_Type_t;

#define HFRE_CONTROL_INDICATOR_BOOLEAN_TYPE_SIZE   (sizeof(HFRE_Control_Indicator_Boolean_Type_t))

   /* The following structure is used hold the start and end range      */
   /* values as well as the Current Indicator Value for Indicators of   */
   /* the ctRange Type.                                                 */
typedef struct _tagHFRE_Control_Indicator_Range_Type_t
{
   unsigned int RangeStart;
   unsigned int RangeEnd;
   unsigned int CurrentIndicatorValue;
} HFRE_Control_Indicator_Range_Type_t;

#define HFRE_CONTROL_INDICATOR_RANGE_TYPE_SIZE     (sizeof(HFRE_Control_Indicator_Range_Type_t))

   /* The following structure represents the Range Value Type.          */
typedef struct _tagHFRE_Control_Indicator_Range_Value_Type_t
{
   unsigned int CurrentIndicatorValue;
} HFRE_Control_Indicator_Range_Value_Type_t;

#define HFRE_CONTROL_INDICATOR_RANGE_VALUE_TYPE_SIZE  (sizeof(HFRE_Control_Indicator_Range_Value_Type_t))

   /* The following structure is used to hold all information related to*/
   /* the information describing the indicators supported including the */
   /* current value of that indicator.  Note that the Indicator         */
   /* Description length must not exceed                                */
   /* HFRE_CONTROL_INDICATOR_DESCRIPTION_LENGTH_MAXIMUM.                */
typedef struct _tagHFRE_Control_Indicator_Entry_t
{
   char                                     *IndicatorDescription;
   HFRE_Control_Indicator_Type_t             ControlIndicatorType;
   union
   {
      HFRE_Control_Indicator_Range_Type_t    ControlIndicatorRangeType;
      HFRE_Control_Indicator_Boolean_Type_t  ControlIndicatorBooleanType;
   } Control_Indicator_Data;
} HFRE_Control_Indicator_Entry_t;

#define HFRE_CONTROL_INDICATOR_ENTRY_SIZE          (sizeof(HFRE_Control_Indicator_Entry_t))

   /* The following structure is used to hold all information related to*/
   /* the update of control indicators.                                 */
typedef struct _tagHFRE_Indicator_Update_t
{
   char                                        *IndicatorDescription;
   union
   {
     HFRE_Control_Indicator_Boolean_Type_t      CurrentBooleanValue;
     HFRE_Control_Indicator_Range_Value_Type_t  CurrentRangeValue;
   } Indicator_Update_Data;
} HFRE_Indicator_Update_t;

#define HFRE_INDICATOR_UPDATE_SIZE                 (sizeof(HFRE_Indicator_Update_t))

   /* The following structure is used to hold all information related to*/
   /* the Update Remote Indicator Notification State                    */
typedef struct _tagHFRE_Notification_Update_t
{
   char      *IndicatorDescription;
   Boolean_t  NotificationEnabled;
} HFRE_Notification_Update_t;

#define HFRE_NOTIFICATION_UPDATE_SIZE          (sizeof(HFRE_Notification_Update_t))

   /* The following enumerated type represents all of the allowable call*/
   /* direction types that are sent or received as part of a Query Call */
   /* List Response.                                                    */
typedef enum
{
   cdMobileOriginated,
   cdMobileTerminated
} HFRE_Call_Direction_t;

   /* The following enumerated type represents all of the allowable call*/
   /* status types that are sent or received as part of a Query Call    */
   /* List Response.                                                    */
typedef enum
{
   csActive,
   csHeld,
   csDialing,
   csAlerting,
   csIncoming,
   csWaiting
} HFRE_Call_Status_t;

   /* The following enumerated type represents all of the allowable call*/
   /* mode types that are sent or received as part of a Query Call List */
   /* Response.                                                         */
typedef enum
{
   cmVoice,
   cmData,
   cmFAX
} HFRE_Call_Mode_t;

   /* The following enumerated type represents all of the possible      */
   /* defined return values from AT command execution.  All except      */
   /* 'erOK' can also be received as unsolicited result codes.          */
typedef enum
{
   erOK,
   erError,
   erNoCarrier,
   erBusy,
   erNoAnswer,
   erDelayed,
   erBlacklisted,
   erResultCode
} HFRE_Extended_Result_t;

   /* The following structure is used to hold all information related to*/
   /* a current call list entry.  Note that PhoneNumber member String   */
   /* Length *MUST* be between the values of                            */
   /* HFRE_PHONE_NUMBER_LENGTH_MINIMUM and                              */
   /* HFRE_PHONE_NUMBER_LENGTH_MAXIMUM.                                 */
typedef struct _tagHFRE_Current_Call_List_Entry_t
{
   unsigned int          Index;
   HFRE_Call_Direction_t CallDirection;
   HFRE_Call_Status_t    CallStatus;
   HFRE_Call_Mode_t      CallMode;
   Boolean_t             Multiparty;
   char                 *PhoneNumber;
   unsigned int          NumberFormat;
   char                 *PhonebookName;
} HFRE_Current_Call_List_Entry_t;

#define HFRE_CURRENT_CALL_LIST_ENTRY_SIZE          (sizeof(HFRE_Current_Call_List_Entry_t))

   /* The following enumerated type represents all of the allowable call*/
   /* state types that are sent or received as part of a Response and   */
   /* Hold Status Response.                                             */
typedef enum
{
   csHold,
   csAccept,
   csReject,
   csNone
} HFRE_Call_State_t;

   /* Hands-Free Event API Types.                                       */
typedef enum
{
   etHFRE_Open_Port_Indication,
   etHFRE_Open_Port_Confirmation,
   etHFRE_Open_Service_Level_Connection_Indication,
   etHFRE_Control_Indicator_Status_Indication,
   etHFRE_Control_Indicator_Status_Confirmation,
   etHFRE_Call_Hold_Multiparty_Support_Confirmation,
   etHFRE_Call_Hold_Multiparty_Selection_Indication,
   etHFRE_Call_Waiting_Notification_Activation_Indication,
   etHFRE_Call_Waiting_Notification_Indication,
   etHFRE_Call_Line_Identification_Notification_Activation_Indication,
   etHFRE_Call_Line_Identification_Notification_Indication,
   etHFRE_Disable_Sound_Enhancement_Indication,
   etHFRE_Dial_Phone_Number_Indication,
   etHFRE_Dial_Phone_Number_From_Memory_Indication,
   etHFRE_ReDial_Last_Phone_Number_Indication,
   etHFRE_Ring_Indication,
   etHFRE_Generate_DTMF_Tone_Indication,
   etHFRE_Answer_Call_Indication,
   etHFRE_InBand_Ring_Tone_Setting_Indication,
   etHFRE_Voice_Recognition_Notification_Indication,
   etHFRE_Speaker_Gain_Indication,
   etHFRE_Microphone_Gain_Indication,
   etHFRE_Voice_Tag_Request_Indication,
   etHFRE_Voice_Tag_Request_Confirmation,
   etHFRE_Hang_Up_Indication,
   etHFRE_Audio_Connection_Indication,
   etHFRE_Audio_Disconnection_Indication,
   etHFRE_Audio_Data_Indication,
   etHFRE_Audio_Transmit_Buffer_Empty_Indication,
   etHFRE_Close_Port_Indication,
   etHFRE_Current_Calls_List_Indication,
   etHFRE_Current_Calls_List_Confirmation,
   etHFRE_Network_Operator_Selection_Format_Indication,
   etHFRE_Network_Operator_Selection_Indication,
   etHFRE_Network_Operator_Selection_Confirmation,
   etHFRE_Extended_Error_Result_Activation_Indication,
   etHFRE_Subscriber_Number_Information_Indication,
   etHFRE_Subscriber_Number_Information_Confirmation,
   etHFRE_Response_Hold_Status_Indication,
   etHFRE_Response_Hold_Status_Confirmation,
   etHFRE_Incoming_Call_State_Indication,
   etHFRE_Incoming_Call_State_Confirmation,
   etHFRE_Command_Result,
   etHFRE_Open_Port_Request_Indication,
   etHFRE_Arbitrary_Command_Indication,
   etHFRE_Arbitrary_Response_Indication,
   etHFRE_Control_Indicator_Request_Indication,
   etHFRE_Available_Codec_List_Indication,
   etHFRE_Codec_Select_Request_Indication,
   etHFRE_Codec_Select_Confirmation,
   etHFRE_Codec_Connection_Setup_Indication
} HFRE_Event_Type_t;

   /* The following Event is dispatched when a Remote Client Requests a */
   /* Connection to a Local Server.  The HFREPortID member specifies the*/
   /* Identifier of the Connection to the Local Server.  The BD_ADDR    */
   /* member specifies the address of the Remote Client requesting the  */
   /* connection to the Local Server.                                   */
   /* ** NOTE ** This event is only dispatched to servers that are in   */
   /*            Manual Accept Mode.                                    */
   /* ** NOTE ** This event must be responded to with the               */
   /*            HFRE_Open_Port_Request_Response() function in order to */
   /*            accept or reject the outstanding Open Request.         */
typedef struct _tagHFRE_Open_Port_Request_Indication_Data_t
{
   unsigned int HFREPortID;
   BD_ADDR_t    BD_ADDR;
} HFRE_Open_Port_Request_Indication_Data_t;

#define HFRE_OPEN_PORT_REQUEST_INDICATION_DATA_SIZE     (sizeof(HFRE_Open_Port_Request_Indication_Data_t))

   /* The following Server Event is dispatched when a Client Connects   */
   /* to a registered Server.  The HFRE Port ID member specifies the    */
   /* Local Server that has been connected to and the BD_ADDR member    */
   /* specifies the Client Bluetooth Device that has connected to the   */
   /* specified Server.                                                 */
typedef struct _tagHFRE_Open_Port_Indication_Data_t
{
   unsigned int HFREPortID;
   BD_ADDR_t    BD_ADDR;
} HFRE_Open_Port_Indication_Data_t;

#define HFRE_OPEN_PORT_INDICATION_DATA_SIZE             (sizeof(HFRE_Open_Port_Indication_Data_t))

   /* The following Client Event is dispatched when a Client receives   */
   /* the Connection Response from a Remote Server which was previously */
   /* attempted to be connected to.  The HFRE Port ID member specifies  */
   /* the Local Client that has requested the connection, the Port Open */
   /* Status represents the Connection Status of the Request.           */
typedef struct _tagHFRE_Open_Port_Confirmation_Data_t
{
   unsigned int HFREPortID;
   unsigned int PortOpenStatus;
} HFRE_Open_Port_Confirmation_Data_t;

#define HFRE_OPEN_PORT_CONFIRMATION_DATA_SIZE           (sizeof(HFRE_Open_Port_Confirmation_Data_t))

   /* The following event acts as an indication to inform the current   */
   /* state of the Service Level Connection.  The HFRE Port ID member   */
   /* specifies the identifier for the local device.  The Remote        */
   /* Supported Features Valid member specifies if the Remote Support   */
   /* Feartures member is valid.  The Remote Supported Features member  */
   /* specifies supported features which are supported by the remote    */
   /* device.  The Remote Call Hold Multiparty Supported member         */
   /* specifies the support of this feature by the remote device.  This */
   /* indication must be received before performing any other action on */
   /* this port.  If an error occurs during the establishment of the    */
   /* Service Level Connection the Port will be closed and local device */
   /* will receive an Close Port Indication with a Port Close Status of */
   /* HFRE_CLOSE_PORT_STATUS_SERVICE_LEVEL_CONNECTION_ERROR.            */
   /* *** NOTE ***  The Remote Supported Features Valid, Remote         */
   /*               Supported Features, and Remote Call Hold Multiparty */
   /*               Support members are only used when the remote device*/
   /*               supported the "AT+BRSF" Command as documented in the*/
   /*               adopted Version 1.0 Hands-Free Profile.  If the     */
   /*               remote device operates using an earlier version of  */
   /*               Hands-Free Profile these values will be set to a    */
   /*               state indicating that they are not used and this    */
   /*               information must be obtained by other means by the  */
   /*               application (SDP Record, Query_xxx_() function).    */
   /* *** NOTE ***  The Remote Call Hold Multiparty Support member will */
   /*               only be valid if the local and remote device both   */
   /*               have the "Three-way Calling Support" bit set in     */
   /*               their supported features.  See note above for       */
   /*               additional requirements.                            */
   /* *** NOTE ***  The Remote Call Hold Multipary Support member will  */
   /*               always be set to                                    */
   /*               HFRE_CALL_HOLD_MULTIPARTY_SUPPORTED_FEATURES_ERROR  */
   /*               in the case when this indication is received by an  */
   /*               Audio Gateway as Hands-Free units have no Call Hold */
   /*               Multiparty Supported Features to query.             */
typedef struct _tagHFRE_Open_Service_Level_Connection_Indication_Data_t
{
   unsigned int  HFREPortID;
   Boolean_t     RemoteSupportedFeaturesValid;
   unsigned long RemoteSupportedFeatures;
   unsigned long RemoteCallHoldMultipartySupport;
} HFRE_Open_Service_Level_Connection_Indication_Data_t;

#define HFRE_OPEN_SERVICE_LEVEL_CONNECTION_INDICATION_DATA_SIZE (sizeof(HFRE_Open_Service_Level_Connection_Indication_Data_t))

   /* The following event is dispatched when the remote device          */
   /* disconnects from the local device.  The HFRE Port ID member       */
   /* specifies the identifier for the local device being disconnected, */
   /* the Port Close Status represents the status of the disconnection. */
   /* This Event is NOT Dispatched in response to the local device      */
   /* requesting the disconnection.  This Event is dispatched only when */
   /* the remote device terminates the Connection (and/or Bluetooth     */
   /* Link).                                                            */
typedef struct _tagHFRE_Close_Port_Indication_Data_t
{
   unsigned int HFREPortID;
   unsigned int PortCloseStatus;
} HFRE_Close_Port_Indication_Data_t;

#define HFRE_CLOSE_PORT_INDICATION_DATA_SIZE            (sizeof(HFRE_Close_Port_Indication_Data_t))

   /* The following event is dispatched to a local Hands-Free unit when */
   /* a Control Indicator changes on the remote Audio Gateway and       */
   /* Control Indicator Change Notification is Enabled.  The HFRE Port  */
   /* ID member specifies the identifier of the local device receiving  */
   /* this indication.  The HFRE Control Indicator Entry structure      */
   /* contains the information about the Control Indicator that changed.*/
typedef struct _tagHFRE_Control_Indicator_Status_Indication_Data_t
{
   unsigned int                   HFREPortID;
   HFRE_Control_Indicator_Entry_t HFREControlIndicatorEntry;
} HFRE_Control_Indicator_Status_Indication_Data_t;

#define HFRE_CONTROL_INDICATOR_STATUS_INDICATION_DATA_SIZE (sizeof(HFRE_Control_Indicator_Status_Indication_Data_t))

   /* The following event is dispatched to a local Hands-Free unit when */
   /* the remote Audio Gateway responds to a request for the current    */
   /* Control Indicator Status.  The HFRE Port ID member specifies the  */
   /* identifier of the local device receiving this confirmation.  The  */
   /* HFRE Control Indicator Entry structure contains the information   */
   /* about the current Control Indicator Status.                       */
typedef struct _tagHFRE_Control_Indicator_Status_Confirmation_Data_t
{
   unsigned int                   HFREPortID;
   HFRE_Control_Indicator_Entry_t HFREControlIndicatorEntry;
} HFRE_Control_Indicator_Status_Confirmation_Data_t;

#define HFRE_CONTROL_INDICATOR_STATUS_CONFIRMATION_DATA_SIZE (sizeof(HFRE_Control_Indicator_Status_Confirmation_Data_t))

   /* The following event is dispatched to a local Hands-Free unit when */
   /* the remote Audio Gateway responds to a request for the remote Call*/
   /* Hold and Multiparty Supported Features.  The HFRE Port ID member  */
   /* specifies the identifier of the local device receiving this       */
   /* confirmation.  The Call Hold Support Mask is a bit mask containing*/
   /* the Call Hold and Multiparty Supported Features of the Remote     */
   /* Audio Gateway.  If the remote Audio Gateway does not have Call    */
   /* Hold and Mulitparty Support the Call Hold Support Mask will be    */
   /* HFRE_CALL_HOLD_MULTIPARTY_SUPPORTED_FEATURES_ERROR.               */
typedef struct _tagHFRE_Call_Hold_Multiparty_Support_Confirmation_Data_t
{
   unsigned int  HFREPortID;
   unsigned long CallHoldSupportMask;
} HFRE_Call_Hold_Multiparty_Support_Confirmation_Data_t;

#define HFRE_CALL_HOLD_MULTIPARTY_SUPPORT_CONFIRMATION_DATA_SIZE (sizeof(HFRE_Call_Hold_Multiparty_Support_Confirmation_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit responds to a Call Waiting notification*/
   /* by selecting how to handle the waiting call.  The HFRE Port ID    */
   /* member specifies the identifier of the local device receiving this*/
   /* indication.  The Call Hold Multiparty Handling member specifies   */
   /* the requested action to take regarding the waiting call.  If the  */
   /* CallHoldMultipartyHandling indicates an extended type then Index  */
   /* will contain the call index to which the operation refers.        */
typedef struct _tagHFRE_Call_Hold_Multiparty_Selection_Indication_Data_t
{
   unsigned int                               HFREPortID;
   HFRE_Call_Hold_Multiparty_Handling_Type_t  CallHoldMultipartyHandling;
   unsigned int                               Index;
} HFRE_Call_Hold_Multiparty_Selection_Indication_Data_t;

#define HFRE_CALL_HOLD_MULTIPARTY_SELECTION_INDICATION_DATA_SIZE (sizeof(HFRE_Call_Hold_Multiparty_Selection_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit issues the command to Enable or Disable*/
   /* Call Waiting Notification.  The HFRE Port ID member specifies the */
   /* identifier of the local device receiving this indication.  The    */
   /* Enabled member specifies whether this is an indication to Enable  */
   /* or Disable Call Waiting Notification.                             */
typedef struct _tagHFRE_Call_Waiting_Notification_Activation_Indication_Data_t
{
   unsigned int HFREPortID;
   Boolean_t    Enabled;
} HFRE_Call_Waiting_Notification_Activation_Indication_Data_t;

#define HFRE_CALL_WAITING_NOTIFICATION_ACTIVATION_INDICATION_DATA_SIZE (sizeof(HFRE_Call_Waiting_Notification_Activation_Indication_Data_t))

   /* The following event is dispatched to a local Hands-Free unit when */
   /* the remote Audio Gateway receives a call while there is an on     */
   /* going call.  Note that Call Waiting Notification must be active in*/
   /* order to receive this event.  The HFRE Port ID member specifies   */
   /* the identifier of the local device receiving this indication.  The*/
   /* Phone Number member is a NULL terminated string representing the  */
   /* Phone Number of the Waiting Call.                                 */
typedef struct _tagHFRE_Call_Waiting_Notification_Indication_Data_t
{
   unsigned int  HFREPortID;
   char         *PhoneNumber;
} HFRE_Call_Waiting_Notification_Indication_Data_t;

#define HFRE_CALL_WAITING_NOTIFICATION_INDICATION_DATA_SIZE (sizeof(HFRE_Call_Waiting_Notification_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit issues the command to Enable or Disable*/
   /* Call Line Identification Notification.  The HFRE Port ID member   */
   /* specifies the identifier of the local device receiving this       */
   /* indication.  The Enable member specifies whether this is an       */
   /* indication to Enable or Disable Call Line Identification          */
   /* Notification.                                                     */
typedef struct _tagHFRE_Call_Line_Identification_Notification_Activation_Indication_Data_t
{
   unsigned int HFREPortID;
   Boolean_t    Enabled;
} HFRE_Call_Line_Identification_Notification_Activation_Indication_Data_t;

#define HFRE_CALL_LINE_IDENTIFICATION_NOTIFICATION_ACTIVATION_INDICATION_DATA_SIZE (sizeof(HFRE_Call_Line_Identification_Notification_Activation_Indication_Data_t))

   /* The following event is dispatched to a local Hands-Free unit when */
   /* the remote Audio Gateway receives Call Line Identification.  Note */
   /* that Call Line Identification Notification must be active in order*/
   /* to receive this event.  The HFRE Port ID member specifies the     */
   /* identifier of the local device receiving this indication.  The    */
   /* Phone Number member is a NULL terminated string representing the  */
   /* Phone Number of the Incoming Caller.                              */
typedef struct _tagHFRE_Call_Line_Identification_Notification_Indication_Data_t
{
   unsigned int  HFREPortID;
   char         *PhoneNumber;
} HFRE_Call_Line_Identification_Notification_Indication_Data_t;

#define HFRE_CALL_LINE_IDENTIFICATION_NOTIFICATION_INDICATION_DATA_SIZE (sizeof(HFRE_Call_Line_Identification_Notification_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit requests turning off the Audio Gateways*/
   /* Echo Canceling and Noise Reduction functions.  The HFRE Port ID   */
   /* member specifies the identifier of the local device receiving this*/
   /* indication.                                                       */
typedef struct _tagHFRE_Disable_Sound_Enhancement_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Disable_Sound_Enhancement_Indication_Data_t;

#define HFRE_DISABLE_SOUND_ENHANCEMENT_INDICATION_DATA_SIZE (sizeof(HFRE_Disable_Sound_Enhancement_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit issues the command to place a call to a*/
   /* phone number.  The HFRE Port ID member specifies the identifier of*/
   /* the local device receiving this indication.  The Phone Number     */
   /* member is a NULL terminated string representing the Phone Number  */
   /* in which to place the call.                                       */
typedef struct _tagHFRE_Dial_Phone_Number_Indication_Data_t
{
   unsigned int  HFREPortID;
   char         *PhoneNumber;
} HFRE_Dial_Phone_Number_Indication_Data_t;

#define HFRE_DIAL_PHONE_NUMBER_INDICATION_DATA_SIZE     (sizeof(HFRE_Dial_Phone_Number_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit issues the command for memory dialing. */
   /* The HFRE Port ID member specifies the identifier of the local     */
   /* device receiving this indication.  The Memory Location member     */
   /* specifies the memory location in which the phone number to dial   */
   /* exists.                                                           */
typedef struct _tagHFRE_Dial_Phone_Number_From_Memory_Indication_Data_t
{
   unsigned int  HFREPortID;
   unsigned int  MemoryLocation;
} HFRE_Dial_Phone_Number_From_Memory_Indication_Data_t;

#define HFRE_DIAL_PHONE_NUMBER_FROM_MEMORY_INDICATION_DATA_SIZE (sizeof(HFRE_Dial_Phone_Number_From_Memory_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit issues the command to redial the last  */
   /* number dialed.  The HFRE Port ID member specifies the identifier  */
   /* of the local device receiving this indication.                    */
typedef struct _tagHFRE_ReDial_Last_Phone_Number_Indication_Data_t
{
   unsigned int  HFREPortID;
} HFRE_ReDial_Last_Phone_Number_Indication_Data_t;

#define HFRE_REDIAL_LAST_PHONE_NUMBER_INDICATION_DATA_SIZE (sizeof(HFRE_ReDial_Last_Phone_Number_Indication_Data_t))

   /* The following event is dispatched to a local Hands-Free unit when */
   /* the remote Audio Gateway sends a RING indication to the local     */
   /* device.  The HFRE Port ID member specifies the identifier of the  */
   /* local device receiving this indication.                           */
typedef struct _tagHFRE_Ring_Indication_Data_t
{
   unsigned int  HFREPortID;
} HFRE_Ring_Indication_Data_t;

#define HFRE_RING_INDICATION_DATA_SIZE                  (sizeof(HFRE_Ring_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit issues the command to transmit a DTMF  */
   /* Code.  The HFRE Port ID member specifies the identifier of the    */
   /* local deivce receiving this indication.  The DTMF Code member     */
   /* specifies the DTMF Code to generate.                              */
typedef struct _tagHFRE_Generate_DTMF_Tone_Indication_Data_t
{
   unsigned int HFREPortID;
   char         DTMFCode;
} HFRE_Generate_DTMF_Tone_Indication_Data_t;

#define HFRE_GENERATE_DTMF_TONE_INDICATION_DATA_SIZE    (sizeof(HFRE_Generate_DTMF_Tone_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit issues the command to answer an        */
   /* incoming call.  The HFRE Port ID member specifies the identifier  */
   /* of the local device receiving this indication.                    */
typedef struct _tagHFRE_Answer_Call_Indication_Data_t
{
   unsigned int  HFREPortID;
} HFRE_Answer_Call_Indication_Data_t;

#define HFRE_ANSWER_CALL_INDICATION_DATA_SIZE           (sizeof(HFRE_Answer_Call_Indication_Data_t))

   /* The following event is dispatched to a local Hands-Free when the  */
   /* remote Audio Gateway wants to change the In-Band Ring Tone Setting*/
   /* during an ongoing Service Level Connection.  The HFRE Port ID     */
   /* member specifies the identifier of the local device receiving this*/
   /* indication.  The Enable member specifies whether this is an       */
   /* indication that In-Band Ringing is Enabled or Disabled.           */
typedef struct _tagHFRE_InBand_Ring_Tone_Setting_Indication_Data_t
{
   unsigned int HFREPortID;
   Boolean_t    Enabled;
} HFRE_InBand_Ring_Tone_Setting_Indication_Data_t;

#define HFRE_INBAND_RING_TONE_SETTING_INDICATION_DATA_SIZE (sizeof(HFRE_InBand_Ring_Tone_Setting_Indication_Data_t))

   /* The following event may be dispatched to either a local Hands-Free*/
   /* unit or a local Audio Gateway.  When this event is received by a  */
   /* local Hands-Free unit it is to inform the local Hands-Free unit of*/
   /* the Remote Audio Gateways current Voice Recognition Activation    */
   /* State.  When this event is received by a local Audio Gateway it is*/
   /* responsible for Activating or Deactivating the Voice Recognition  */
   /* functions which reside locally.  The HFRE Port ID member specifies*/
   /* the identifier of the local device receiving this indication.  On */
   /* a Hands-Free unit the Voice Recognition Active member is used to  */
   /* inform the local device of the remote devices Voice Recognition   */
   /* Activation State.  On an Audio Gateway the Voice Recognition      */
   /* Active member is used to activate or deactivate the local Voice   */
   /* Recognition functions.                                            */
typedef struct _tagHFRE_Voice_Recognition_Notification_Indication_Data_t
{
   unsigned int HFREPortID;
   Boolean_t    VoiceRecognitionActive;
} HFRE_Voice_Recognition_Notification_Indication_Data_t;

#define HFRE_VOICE_RECOGNITION_NOTIFICATION_INDICATION_DATA_SIZE (sizeof(HFRE_Voice_Recognition_Notification_Indication_Data_t))

   /* The following event may be dispatched to either a local Hands-Free*/
   /* unit or a local Audio Gateway.  When this event is received by a  */
   /* local Hands-Free unit it is to set the local Speaker Gain.  When  */
   /* this event is received by a local Audio Gateway it is used in     */
   /* Volume Level Synchronization to inform the local Audio Gateway of */
   /* the current Speaker Gain on the remote Hands-Free unit.  The HFRE */
   /* Port ID member specifies the identifier of the local device       */
   /* receiving this indication.  The Speaker Gain member is used to set*/
   /* or inform the device of the Speaker Gain respectively.            */
typedef struct _tagHFRE_Speaker_Gain_Indication_Data_t
{
   unsigned int HFREPortID;
   unsigned int SpeakerGain;
} HFRE_Speaker_Gain_Indication_Data_t;

#define HFRE_SPEAKER_GAIN_INDICATION_DATA_SIZE          (sizeof(HFRE_Speaker_Gain_Indication_Data_t))

   /* The following event may be dispatched to either a local Hands-Free*/
   /* unit or a local Audio Gateway.  When this event is received by a  */
   /* local Hands-Free unit it is to set the local Microphone Gain.     */
   /* When this event is received by a local Audio Gateway it is used in*/
   /* Volume Level Synchronization to inform the local Audio Gateway of */
   /* the current Microphone Gain on teh remote Hands-Free unit.  The   */
   /* HFRE Port ID member specifies the identifier of the local device  */
   /* receiving this indication.  The Microphone Gain member is used to */
   /* set or inform the device of the Microphone Gain respectively.     */
typedef struct _tagHFRE_Microphone_Gain_Indication_Data_t
{
   unsigned int HFREPortID;
   unsigned int MicrophoneGain;
} HFRE_Microphone_Gain_Indication_Data_t;

#define HFRE_MICROPHONE_GAIN_INDICATION_DATA_SIZE       (sizeof(HFRE_Microphone_Gain_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit makes a request for a phone number to  */
   /* attach to a voice tag.  Upon reception of this event the local    */
   /* Audio Gateway must respond to it with the                         */
   /* HFRE_Voice_Tag_Response() function (see function below for        */
   /* details).  The HFRE Port ID member specifies the identifier of the*/
   /* local device receiving this indication.                           */
typedef struct _tagHFRE_Voice_Tag_Request_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Voice_Tag_Request_Indication_Data_t;

#define HFRE_VOICE_TAG_REQUEST_INDICATION_DATA_SIZE     (sizeof(HFRE_Voice_Tag_Request_Indication_Data_t))

   /* The following event is dispatched to a local Hands-Free unit when */
   /* the remote Audio Gateway responds to a request for a phone number */
   /* to attach to a voice tag.  The HFRE Port ID member specifies the  */
   /* identifier of the local device receiving this confirmation.  The  */
   /* Phone Number member is a NULL terminated string representing the  */
   /* phone number to attach to the voice tag.  If the remote Audio     */
   /* Gateway rejects the request the Phone Number member will be NULL  */
   /* to indicate this condition.                                       */
typedef struct _tagHFRE_Voice_Tag_Request_Confirmation_Data_t
{
   unsigned int  HFREPortID;
   char         *PhoneNumber;
} HFRE_Voice_Tag_Request_Confirmation_Data_t;

#define HFRE_VOICE_TAG_REQUEST_CONFIRMATION_DATA_SIZE   (sizeof(HFRE_Voice_Tag_Request_Confirmation_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit issues the command to Hang-Up an       */
   /* ongoing call or to reject and incoming call request.  The HFRE    */
   /* Port ID member specifies the identifier of the local device       */
   /* receiving this indication.                                        */
typedef struct _tagHFRE_Hang_Up_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Hang_Up_Indication_Data_t;

#define HFRE_HANG_UP_INDICATION_DATA_SIZE               (sizeof(HFRE_Hang_Up_Indication_Data_t))

   /* The following event is dispatched to the local device when an     */
   /* audio connection is established.  The HFRE Port ID member         */
   /* specifies the identifier of the local device receiving this       */
   /* indication.  The Audio Connection Open Status member indicates the*/
   /* Open Status with this indication.                                 */
typedef struct _tagHFRE_Audio_Connection_Indication_Data_t
{
   unsigned int HFREPortID;
   unsigned int AudioConnectionOpenStatus;
   Word_t       SCO_Connection_Handle;
} HFRE_Audio_Connection_Indication_Data_t;

#define HFRE_AUDIO_CONNECTION_INDICATION_DATA_SIZE      (sizeof(HFRE_Audio_Connection_Indication_Data_t))

   /* The following event is dispatched to the local device when an     */
   /* audio connection is disconnected.  The HFRE Port ID member        */
   /* specifies the identifier of the local device receiving this       */
   /* indication.                                                       */
typedef struct _tagHFRE_Audio_Disconnection_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Audio_Disconnection_Indication_Data_t;

#define HFRE_AUDIO_DISCONNECTION_INDICATION_DATA_SIZE   (sizeof(HFRE_Audio_Disconnection_Indication_Data_t))

   /* The following event is dispatched to the local device upon the    */
   /* reception of Audio Data.  The HFRE Port ID member specifies the   */
   /* identifier of the local device receiving this indication.  The    */
   /* Audio Data Length member represents the size of the Audio Data    */
   /* pointed to by the next member.  The final parameter, PacketStatus */
   /* defines the status (as reported by the baseband) of the packet.   */
   /* Valid values are one of the following:                            */
   /*                                                                   */
   /*    HCI_SCO_FLAGS_PACKET_STATUS_MASK_CORRECTLY_RECEIVED_DATA       */
   /*    HCI_SCO_FLAGS_PACKET_STATUS_MASK_POSSIBLY_INVALID_DATA         */
   /*    HCI_SCO_FLAGS_PACKET_STATUS_MASK_NO_DATA_RECEIVED              */
   /*    HCI_SCO_FLAGS_PACKET_STATUS_MASK_DATA_PARTIALLY_LOST           */
   /*                                                                   */
   /* See the Bluetooth HCI specification for more information on these */
   /* flags (Bluetooth 2.1 + EDR specification or greater).             */
typedef struct _tagHFRE_Audio_Data_Indication_Data_t
{
   unsigned int  HFREPortID;
   Byte_t        AudioDataLength;
   Byte_t       *AudioData;
   Word_t        PacketStatus;
} HFRE_Audio_Data_Indication_Data_t;

#define HFRE_AUDIO_DATA_INDICATION_DATA_SIZE            (sizeof(HFRE_Audio_Data_Indication_Data_t))

   /* The following event is dispatched to the local device when the    */
   /* Audio Transmit buffer for the specified HFRE Port is empty.  The  */
   /* HFRE Port ID member specifies the identifier of the local device  */
   /* receiving this indication.                                        */
typedef struct _tagHFRE_Audio_Transmit_Buffer_Empty_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Audio_Transmit_Buffer_Empty_Indication_Data_t;

#define HFRE_AUDIO_TRANSMIT_BUFFER_EMPTY_INDICATION_DATA_SIZE  (sizeof(HFRE_Audio_Transmit_Buffer_Empty_Indication_Data_t))

   /* The following event is dispatched to a local Audio gateway when it*/
   /* receives a request for the current call list (+CLCC).  This is a  */
   /* HFRE 1.5 only feature.  The HFRE Port ID member specifies the     */
   /* identifier of the local device service receiving the indication.  */
typedef struct _tagHFRE_Current_Calls_List_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Current_Calls_List_Indication_Data_t;

#define HFRE_CURRENT_CALLS_LIST_INDICATION_DATA_SIZE    (sizeof(HFRE_Current_Calls_List_Indication_Data_t))

   /* The following event is dispatched to a local Hands-Free service   */
   /* when a remote Audio gateway responds to a request for the list of */
   /* current calls (+CLCC).  The service will recieve a seperate       */
   /* notification for each call entry the remote device sends.  The    */
   /* HFRECurrentCallList member contains the information parsed from   */
   /* this entry.  This is a HFRE 1.5 feature only.                     */
typedef struct _tagHFRE_Current_Calls_List_Confirmation_Data_t
{
   unsigned int                   HFREPortID;
   HFRE_Current_Call_List_Entry_t HFRECurrentCallListEntry;
} HFRE_Current_Calls_List_Confirmation_Data_t;

#define HFRE_CURRENT_CALLS_LIST_CONFIRMATION_DATA_SIZE  (sizeof(HFRE_Current_Calls_List_Confirmation_Data_t))

   /* This event is dispatched to a local Audio Gateway service when the*/
   /* remote hands-free device issues a Set Operator Selection Format   */
   /* command (+COPS=3,n).  The Format member contains the format value */
   /* provided in this operation.  The HFRE specification requires that */
   /* the remote device choose format 0.  As a result, this event can   */
   /* generaly be ignored.  This is a HFRE 1.5 only feature.            */
typedef struct _tagHFRE_Network_Operator_Selection_Format_Indication_Data_t
{
   unsigned int HFREPortID;
   unsigned int Format;
} HFRE_Network_Operator_Selection_Format_Indication_Data_t;

#define HFRE_NETWORK_OPERATOR_SELECTION_FORMAT_INDICATION_DATA_SIZE (sizeof(HFRE_Network_Operator_Selection_Format_Indication_Data_t))

   /* This event is dispatched to a local Audio Gateway service when the*/
   /* remote Hands-Free device has requested the current operator       */
   /* selection (+COPS?).  This is a HFRE 1.5 only feature.             */
typedef struct _tagHFRE_Network_Operator_Selection_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Network_Operator_Selection_Indication_Data_t;

#define HFRE_NETWORK_OPERATOR_SELECTION_INDICATION_DATA_SIZE (sizeof(HFRE_Network_Operator_Selection_Indication_Data_t))

   /* This event is dispatched to a local Hands-Free service when a     */
   /* remote Audio Gateway responds to the request for current operator */
   /* selection (+COPS?).  The NetworkMode member contains the mode     */
   /* returned in the response.  The NetworkOperator member is a pointer*/
   /* to a null-terminated ASCII string that contains the returned      */
   /* operator name.  This is a HFRE 1.5 only feature.                  */
typedef struct _tagHFRE_Network_Operator_Selection_Confirmation_Data_t
{
   unsigned int  HFREPortID;
   unsigned int  NetworkMode;
   char         *NetworkOperator;
} HFRE_Network_Operator_Selection_Confirmation_Data_t;

#define HFRE_NETWORK_OPERATOR_SELECTION_CONFIRMATION_DATA_SIZE (sizeof(HFRE_Network_Operator_Selection_Confirmation_Data_t))

   /* This event is dispatched to a local Audio Gateway service when a  */
   /* remote Hands-Free device sends a command activate extended error  */
   /* reporting (+CMEE).  The Enabled member contains a boolean value   */
   /* which indicates the current state of extended error reporting.    */
   /* This is a HFRE 1.5 only feature.                                  */
typedef struct _tagHFRE_Extended_Error_Result_Activation_Indication_Data_t
{
   unsigned int HFREPortID;
   Boolean_t    Enabled;
} HFRE_Extended_Error_Result_Activation_Indication_Data_t;

#define HFRE_EXTENDED_ERROR_RESULT_ACTIVATION_INDICATION_DATA_SIZE (sizeof(HFRE_Extended_Error_Result_Activation_Indication_Data_t))

   /* This event is dispatched to a local Audio Gateway service when a  */
   /* remote Hands-Free device requests the current subscriber number   */
   /* (+CNUM?).  This is a HFRE 1.5 only feature.                       */
typedef struct _tagHFRE_Subscriber_Number_Information_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Subscriber_Number_Information_Indication_Data_t;

#define HFRE_SUBSCRIBER_NUMBER_INFORMATION_INDICATION_DATA_SIZE (sizeof(HFRE_Subscriber_Number_Information_Indication_Data_t))

   /* This event is dispatched to a local Hands-Free service when a     */
   /* remote Audio Gateway responds to the request for the current      */
   /* subscriber number (+CNUM).  The ServiceType member contains the   */
   /* Service Type value included in the response.  The NumberFormat    */
   /* value contains the number format included in the response.  The   */
   /* PhoneNumber member is a pointer to a null-termianted, ASCII string*/
   /* that contains the current subscriber phone number.  This is a HFRE*/
   /* 1.5 only feature.                                                 */
typedef struct _tagHFRE_Subscriber_Number_Information_Confirmation_Data_t
{
   unsigned int  HFREPortID;
   unsigned int  ServiceType;
   unsigned int  NumberFormat;
   char         *PhoneNumber;
} HFRE_Subscriber_Number_Information_Confirmation_Data_t;

#define HFRE_SUBSCRIBER_NUMBER_INFORMATION_CONFIRMATION_DATA_SIZE (sizeof(HFRE_Subscriber_Number_Information_Confirmation_Data_t))

   /* This event is dispatched to a local Audio Gateway service when a  */
   /* remote Hands-Free device requests the current Response/Hold Status*/
   /* (+BTRH?).  This is a HFRE 1.5 only feature.                       */
typedef struct _tagHFRE_Response_Hold_Status_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Response_Hold_Status_Indication_Data_t;

#define HFRE_RESPONSE_HOLD_STATUS_INDICATION_DATA_SIZE  (sizeof(HFRE_Response_Hold_Status_Indication_Data_t))

   /* This event is dispatched to a local Hands-Free service when a     */
   /* remote Audio Gateway device responds to a request for the current */
   /* Response/Hold status (+BTRH).  The CallState member contains the  */
   /* call state sent in the repsonse.  This is a HFRE 1.5 only feature.*/
typedef struct _tagHFRE_Response_Hold_Status_Confirmation_Data_t
{
   unsigned int      HFREPortID;
   HFRE_Call_State_t CallState;
} HFRE_Response_Hold_Status_Confirmation_Data_t;

#define HFRE_RESPONSE_HOLD_STATUS_CONFIRMATION_DATA_SIZE (sizeof(HFRE_Response_Hold_Status_Confirmation_Data_t))

   /* This event is dispatched to a local Audio Gateway service when a  */
   /* remote Hands-Free device sends a command to set the current call  */
   /* state (+BTRH=).  This can also be received by a local Hands-Free  */
   /* device when the remote Audio Gateway sends a notification on a    */
   /* change in the current Response/Hold Status (+BTRH:).  The         */
   /* CallState member contains the call state requested by the remote  */
   /* device.  This is a HFRE 1.5 only feature.                         */
typedef struct _tagHFRE_Incoming_Call_State_Indication_Data_t
{
   unsigned int      HFREPortID;
   HFRE_Call_State_t CallState;
} HFRE_Incoming_Call_State_Indication_Data_t;

#define HFRE_INCOMING_CALL_STATE_INDICATION_DATA_SIZE (sizeof(HFRE_Incoming_Call_State_Indication_Data_t))

   /* This event is dispatched to a local Hands-Free service when a     */
   /* remote Audio Gateway device responds to a request for the current */
   /* Response/Hold status (+BTRH).  The CallState member contains the  */
   /* call state returned by the remote device.  This is a HFRE 1.5 only*/
   /* feature.                                                          */
typedef struct _tagHFRE_Incoming_Call_State_Confirmation_Data_t
{
   unsigned int      HFREPortID;
   HFRE_Call_State_t CallState;
} HFRE_Incoming_Call_State_Confirmation_Data_t;

#define HFRE_INCOMING_CALL_STATE_CONFIRMATION_DATA_SIZE (sizeof(HFRE_Incoming_Call_State_Confirmation_Data_t))

   /* The following event is dispatched to a local Hands-Free unit when */
   /* the remote Audio Gateway responds to a commmand sent by the       */
   /* Hands-Free unit or generates an unsolicited result code.  The HFRE*/
   /* Port ID member specifies the identifier of the local device       */
   /* receiving this confirmation.  The ResultValue member contains the */
   /* actual result code value if the ResultType parameter indicates    */
   /* that a result code is expected (erResultCode).                    */
typedef struct _tagHFRE_Command_Result_Data_t
{
   unsigned int           HFREPortID;
   HFRE_Extended_Result_t ResultType;
   unsigned int           ResultValue;
} HFRE_Command_Result_Data_t;

#define HFRE_COMMAND_RESULT_DATA_SIZE             (sizeof(HFRE_Command_Result_Data_t))

   /* The following event is dispatched to a local Audio Gateway unit   */
   /* when the remote Hands Free Device issues a commmand that is not   */
   /* recognized by the local Audio Gateway (i.e. an arbitrary AT       */
   /* Command).  The HFRE Port ID member specifies the identifier of the*/
   /* local device receiving this indication.  The Command Data member  */
   /* is a pointer to a NULL terminated string that represents the      */
   /* actual command data that was received.                            */
typedef struct _tagHFRE_Arbitrary_Command_Indication_Data_t
{
   unsigned int  HFREPortID;
   char         *HFRECommandData;
} HFRE_Arbitrary_Command_Indication_Data_t;

#define HFRE_ARBITRARY_COMMAND_INDICATION_DATA_SIZE   (sizeof(HFRE_Arbitrary_Command_Indication_Data_t))

   /* The following event is dispatched to a local Hands Free unit when */
   /* the remote Audio Gateway issues either a non-solicited arbitrary  */
   /* response OR a solicited arbitrary response that is not recognized */
   /* by the local Hands Free unit (i.e.  an arbitrary AT Response).    */
   /* The HFRE Port ID member specifies the identifier of the local     */
   /* device receiving this indication.  The Response Data member is a  */
   /* pointer to a NULL terminated string that represents the actual    */
   /* response data that was received.                                  */
typedef struct _tagHFRE_Arbitrary_Response_Indication_Data_t
{
   unsigned int  HFREPortID;
   char         *HFREResponseData;
} HFRE_Arbitrary_Response_Indication_Data_t;

#define HFRE_ARBITRARY_RESPONSE_INDICATION_DATA_SIZE  (sizeof(HFRE_Arbitrary_Response_Indication_Data_t))

   /* The following event is dispatched to the local device when an     */
   /* audio connection request is received.  The HFRE Port ID member    */
   /* specifies the identifier of the local device receiving this       */
   /* indication.                                                       */
typedef struct _tagHFRE_Audio_Connect_Request_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Audio_Connect_Request_Indication_Data_t;

#define HFRE_AUDIO_CONNECT_REQUEST_INDICATION_DATA_SIZE      (sizeof(HFRE_Audio_Connect_Request_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands Free unit send a list of available codeds.  The  */
   /* HFRE Port ID member specifies the identifier of the local device  */
   /* receiving this indication.  The NumSupportedCodecs denotes the    */
   /* number of elements that are provided in the SupportedCodecList.   */
   /* The SupportedCodecList contains an array of bytes where each bytes*/
   /* represents a Codec ID of a Codec that is supported by the         */
   /* Handsfree device.                                                 */
typedef struct _tagHFRE_Available_Codec_List_Indication_Data_t
{
   unsigned int   HFREPortID;
   unsigned int   NumSupportedCodecs;
   unsigned char *AvailableCodecList;
} HFRE_Available_Codec_List_Indication_Data_t;

#define HFRE_AVAILABLE_CODEC_LIST_INDICATION_DATA_SIZE  (sizeof(HFRE_Available_Codec_List_Indication_Data_t))

   /* The following event is dispatched to a local Handsfree device when*/
   /* the remote Audio Gateway selects a Codec for use.  The HFRE Port  */
   /* ID member specifies the identifier of the local device receiving  */
   /* this indication.  The CodecID identifies the Codec that has been  */
   /* chosen byb the Audio Gateway.                                     */
typedef struct _tagHFRE_Codec_Select_Indication_t
{
   unsigned int  HFREPortID;
   unsigned char CodecID;
} HFRE_Codec_Select_Indication_t;

#define HFRE_CODEC_SELECT_INDICATION_DATA_SIZE  (sizeof(HFRE_Codec_Select_Indication_t))

   /* The following event is dispatched to a local Handsfree device when*/
   /* the remote Audio Gateway responds to the Codec Selection.  The    */
   /* HFRE Port ID member specifies the identifier of the local device  */
   /* receiving this indication.  The CodecAccepted indicates whether   */
   /* the requested Codec was accepted by the Audio Gateway             */
typedef struct _tagHFRE_Codec_Select_Confirmation_t
{
   unsigned int  HFREPortID;
   Boolean_t     AcceptedCodec;
} HFRE_Codec_Select_Confirmation_t;

#define HFRE_CODEC_SELECT_CONFIRMATION_DATA_SIZE  (sizeof(HFRE_Codec_Select_Confirmation_t))

   /* The following event is dispatched to a local Audio Gateway when   */
   /* the remote Hands-Free unit issues the command to start the codec  */
   /* selection process.  The HFRE Port ID member specifies the         */
   /* identifier of the local device receiving this indication.         */
typedef struct _tagHFRE_Codec_Connection_Setup_Indication_Data_t
{
   unsigned int  HFREPortID;
} HFRE_Codec_Connection_Setup_Indication_Data_t;

#define HFRE_CODEC_CONNECTION_SETUP_INDICATION_DATA_SIZE  (sizeof(HFRE_Codec_Connection_Setup_Indication_Data_t))

   /* The following event is dispatched to a local Audio Gateway unit   */
   /* when the remote Hands Free issues a request for the current       */
   /* control indicators.  The HFRE Port ID member specifies the        */
   /* identifier of the local device receiving this indication.         */
   /* * NOTE * The local Audio Gateway unit will only receive this event*/
   /*          if the                                                   */
   /*                                                                   */
   /*              HFRE_AG_QUERY_INDICATOR_REQUEST_SUPPORTED_BIT        */
   /*                                                                   */
   /*          bit is set in the SupportedFeatures mask when either the */
   /*          HFRE_Open_Remote_HandsFree_Port() or                     */
   /*          HFRE_Open_Audio_Gateway_Server_Port() API was called.    */
   /* * NOTE * If an application receives this event then it must call  */
   /*          HFRE_Update_Current_Control_Indicator_Status() API to    */
   /*          update the value of all of the supported control         */
   /*          indicators and then call the                             */
   /*          HFRE_Send_Control_Indicator_Request_Response() API to    */
   /*          respond to the request.                                  */
typedef struct _tagHFRE_Control_Indicator_Request_Indication_Data_t
{
   unsigned int HFREPortID;
} HFRE_Control_Indicator_Request_Indication_Data_t;

#define HFRE_CONTROL_INDICATOR_REQUEST_INDICATION_DATA_SIZE (sizeof(HFRE_Control_Indicator_Request_Indication_Data_t))

   /* The following structure represents the container structure for    */
   /* Holding all Hands-Free Event Data Data.                           */
typedef struct _tagHFRE_Event_Data_t
{
   HFRE_Event_Type_t  Event_Data_Type;
   Word_t             Event_Data_Size;
   union
   {
      HFRE_Open_Port_Request_Indication_Data_t                                *HFRE_Open_Port_Request_Indication_Data;
      HFRE_Open_Port_Indication_Data_t                                        *HFRE_Open_Port_Indication_Data;
      HFRE_Open_Port_Confirmation_Data_t                                      *HFRE_Open_Port_Confirmation_Data;
      HFRE_Open_Service_Level_Connection_Indication_Data_t                    *HFRE_Open_Service_Level_Connection_Indication_Data;
      HFRE_Control_Indicator_Status_Indication_Data_t                         *HFRE_Control_Indicator_Status_Indication_Data;
      HFRE_Control_Indicator_Status_Confirmation_Data_t                       *HFRE_Control_Indicator_Status_Confirmation_Data;
      HFRE_Call_Hold_Multiparty_Support_Confirmation_Data_t                   *HFRE_Call_Hold_Multiparty_Support_Confirmation_Data;
      HFRE_Call_Hold_Multiparty_Selection_Indication_Data_t                   *HFRE_Call_Hold_Multiparty_Selection_Indication_Data;
      HFRE_Call_Waiting_Notification_Activation_Indication_Data_t             *HFRE_Call_Waiting_Notification_Activation_Indication_Data;
      HFRE_Call_Waiting_Notification_Indication_Data_t                        *HFRE_Call_Waiting_Notification_Indication_Data;
      HFRE_Call_Line_Identification_Notification_Activation_Indication_Data_t *HFRE_Call_Line_Identification_Notification_Activation_Indication_Data;
      HFRE_Call_Line_Identification_Notification_Indication_Data_t            *HFRE_Call_Line_Identification_Notification_Indication_Data;
      HFRE_Disable_Sound_Enhancement_Indication_Data_t                        *HFRE_Disable_Sound_Enhancement_Indication_Data;
      HFRE_Dial_Phone_Number_Indication_Data_t                                *HFRE_Dial_Phone_Number_Indication_Data;
      HFRE_Dial_Phone_Number_From_Memory_Indication_Data_t                    *HFRE_Dial_Phone_Number_From_Memory_Indication_Data;
      HFRE_ReDial_Last_Phone_Number_Indication_Data_t                         *HFRE_ReDial_Last_Phone_Number_Indication_Data;
      HFRE_Ring_Indication_Data_t                                             *HFRE_Ring_Indication_Data;
      HFRE_Answer_Call_Indication_Data_t                                      *HFRE_Answer_Call_Indication_Data;
      HFRE_InBand_Ring_Tone_Setting_Indication_Data_t                         *HFRE_InBand_Ring_Tone_Setting_Indication_Data;
      HFRE_Generate_DTMF_Tone_Indication_Data_t                               *HFRE_Generate_DTMF_Tone_Indication_Data;
      HFRE_Voice_Recognition_Notification_Indication_Data_t                   *HFRE_Voice_Recognition_Notification_Indication_Data;
      HFRE_Speaker_Gain_Indication_Data_t                                     *HFRE_Speaker_Gain_Indication_Data;
      HFRE_Microphone_Gain_Indication_Data_t                                  *HFRE_Microphone_Gain_Indication_Data;
      HFRE_Voice_Tag_Request_Indication_Data_t                                *HFRE_Voice_Tag_Request_Indication_Data;
      HFRE_Voice_Tag_Request_Confirmation_Data_t                              *HFRE_Voice_Tag_Request_Confirmation_Data;
      HFRE_Hang_Up_Indication_Data_t                                          *HFRE_Hang_Up_Indication_Data;
      HFRE_Audio_Connection_Indication_Data_t                                 *HFRE_Audio_Connection_Indication_Data;
      HFRE_Audio_Disconnection_Indication_Data_t                              *HFRE_Audio_Disconnection_Indication_Data;
      HFRE_Audio_Data_Indication_Data_t                                       *HFRE_Audio_Data_Indication_Data;
      HFRE_Audio_Transmit_Buffer_Empty_Indication_Data_t                      *HFRE_Audio_Transmit_Buffer_Empty_Indication_Data;
      HFRE_Close_Port_Indication_Data_t                                       *HFRE_Close_Port_Indication_Data;
      HFRE_Current_Calls_List_Indication_Data_t                               *HFRE_Current_Calls_List_Indication_Data;
      HFRE_Current_Calls_List_Confirmation_Data_t                             *HFRE_Current_Calls_List_Confirmation_Data;
      HFRE_Network_Operator_Selection_Format_Indication_Data_t                *HFRE_Network_Operator_Selection_Format_Indication_Data;
      HFRE_Network_Operator_Selection_Indication_Data_t                       *HFRE_Network_Operator_Selection_Indication_Data;
      HFRE_Network_Operator_Selection_Confirmation_Data_t                     *HFRE_Network_Operator_Selection_Confirmation_Data;
      HFRE_Extended_Error_Result_Activation_Indication_Data_t                 *HFRE_Extended_Error_Result_Activation_Indication_Data;
      HFRE_Subscriber_Number_Information_Indication_Data_t                    *HFRE_Subscriber_Number_Information_Indication_Data;
      HFRE_Subscriber_Number_Information_Confirmation_Data_t                  *HFRE_Subscriber_Number_Information_Confirmation_Data;
      HFRE_Response_Hold_Status_Indication_Data_t                             *HFRE_Response_Hold_Status_Indication_Data;
      HFRE_Response_Hold_Status_Confirmation_Data_t                           *HFRE_Response_Hold_Status_Confirmation_Data;
      HFRE_Incoming_Call_State_Indication_Data_t                              *HFRE_Incoming_Call_State_Indication_Data;
      HFRE_Incoming_Call_State_Confirmation_Data_t                            *HFRE_Incoming_Call_State_Confirmation_Data;
      HFRE_Command_Result_Data_t                                              *HFRE_Command_Result_Data;
      HFRE_Arbitrary_Command_Indication_Data_t                                *HFRE_Arbitrary_Command_Indication_Data;
      HFRE_Arbitrary_Response_Indication_Data_t                               *HFRE_Arbitrary_Response_Indication_Data;
      HFRE_Available_Codec_List_Indication_Data_t                             *HFRE_Available_Codec_List_Indication_Data;
      HFRE_Codec_Select_Indication_t                                          *HFRE_Codec_Select_Indication_Data;
      HFRE_Codec_Select_Confirmation_t                                        *HFRE_Codec_Select_Confirmation_Data;
      HFRE_Codec_Connection_Setup_Indication_Data_t                           *HFRE_Codec_Connection_Setup_Indication_Data;
      HFRE_Control_Indicator_Request_Indication_Data_t                        *HFRE_Control_Indicator_Request_Indication_Data;
   } Event_Data;
} HFRE_Event_Data_t;

#define HFRE_EVENT_DATA_SIZE                                      (sizeof(HFRE_Event_Data_t))

   /* The following declared type represents the Prototype Function for */
   /* a Hands-Free Profile Event Receive Data Callback.  This function  */
   /* will be called whenever a Hands-Free Event occurs that is         */
   /* associated with the specified Bluetooth Stack ID.  This function  */
   /* passes to the caller the Bluetooth Stack ID, the Hands-Free Event */
   /* Data that occurred and the Hands-Free Event Callback Parameter    */
   /* that was specified when this Callback was installed.  The caller  */
   /* is free to use the contents of the Hands-Free Event Data ONLY in  */
   /* the context of this callback.  If the caller requires the Data for*/
   /* a longer period of time, then the callback function MUST copy the */
   /* data into another Data Buffer.  This function is guaranteed NOT to*/
   /* be invoked more than once simultaneously for the specified        */
   /* installed callback (i.e. this function DOES NOT have be           */
   /* reentrant).  It Needs to be noted however, that if the same       */
   /* Callback is installed more than once, then the callbacks will be  */
   /* called serially.  Because of this, the processing in this function*/
   /* should be as efficient as possible.  It should also be noted that */
   /* this function is called in the Thread Context of a Thread that the*/
   /* User does NOT own.  Therefore, processing in this function should */
   /* be as efficient as possible (this argument holds anyway because   */
   /* another Hands-Free Profile Event will not be processed while this */
   /* function call is outstanding).                                    */
   /* ** NOTE ** This function MUST NOT Block and wait for events that  */
   /*            can only be satisfied by Receiving Hands-Free Event    */
   /*            Packets.  A Deadlock WILL occur because NO Hands-Free  */
   /*            Event Callbacks will be issued while this function is  */
   /*            currently outstanding.                                 */
typedef void (BTPSAPI *HFRE_Event_Callback_t)(unsigned int BluetoothStackID, HFRE_Event_Data_t *HFRE_Event_Data, unsigned long CallbackParameter);

   /* The following function is responsible for Opening a Hands-Free    */
   /* Server on the specified Bluetooth SPP Serial Port.  This function */
   /* accepts as input the Bluetooth Stack ID of the Bluetooth Stack    */
   /* Instance to use for the Hands-Free Server, the Local Serial Port  */
   /* Server Number to use, a bit mask that specifies the features in   */
   /* which the Hands-Free unit supports, the Number of Additional      */
   /* Indicators, a list of Additional Indicators to Support, and the   */
   /* HFRE Event Callback function (and parameter) to associate with the*/
   /* specified Hands-Free Port.  The ServerPort parameter *MUST* be    */
   /* between SPP_PORT_NUMBER_MINIMUM and SPP_PORT_NUMBER_MAXIMUM.  This*/
   /* function returns a positive, non-zero, value if successful or a   */
   /* negative return error code if an error occurs.  A successful      */
   /* return code will be a HFRE Port ID that can be used to reference  */
   /* the Opened HFRE Port in ALL other functions in this module except */
   /* for the HFRE_Register_Audio_Gateway_SDP_Record() function which is*/
   /* specific to an Audio Gateway Server NOT a Hands-Free Server.  Once*/
   /* a Server HFRE Port is opened, it can only be Un-Registered via a  */
   /* call to the HFRE_Close_Server_Port() function (passing the return */
   /* value from this function).  The HFRE_Close_Port() function can be */
   /* used to Disconnect a Client from the Server Port (if one is       */
   /* connected, it will NOT Un-Register the Server Port however).      */
   /* * NOTE * The Mandatory Hands-Free Indicators (call, service, and  */
   /*          call_setup) are automatically added to the list and need */
   /*          not be specified as additional indicators.               */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Open_HandsFree_Server_Port(unsigned int BluetoothStackID, unsigned int ServerPort, unsigned long SupportedFeaturesMask, unsigned int NumberAdditionalIndicators, char *AdditionalSupportedIndicators[], HFRE_Event_Callback_t EventCallback, unsigned long CallbackParameter);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Open_HandsFree_Server_Port_t)(unsigned int BluetoothStackID, unsigned int ServerPort, unsigned long SupportedFeaturesMask, unsigned int NumberAdditionalIndicators, char *AdditionalSupportedIndicators[], HFRE_Event_Callback_t EventCallback, unsigned long CallbackParameter);
#endif

   /* The following function is responsible for Opening an Audio Gateway*/
   /* Server on the specified Bluetooth SPP Serial Port.  This function */
   /* accepts as input the Bluetooth Stack ID of the Bluetooth Stack    */
   /* Instance to use for the Audio Gateway Server, the Local Serial    */
   /* Port Server Number to use, a bit mask that specifies the features */
   /* in which the Audio Gateway supports, a bit mask that specifies the*/
   /* Call Hold and Multiparty Support features which the Audio Gateway */
   /* supports, the Number of Additional Indicators, a list of          */
   /* Additional Indicators to Support, and the HFRE Event Callback     */
   /* function (and parameter) to associate with the specified Audio    */
   /* Gateway Port.  The ServerPort parameter *MUST* be between         */
   /* SPP_PORT_NUMBER_MINIMUM and SPP_PORT_NUMBER_MAXIMUM.  This        */
   /* function returns a positive, non-zero, value if successful or a   */
   /* negative return error code if an error occurs.  A successful      */
   /* return code will be a HFRE Port ID that can be used to reference  */
   /* the Opened HFRE Port in ALL other functions in this module except */
   /* for the HFRE_Register_HandsFree_SDP_Record() function which is    */
   /* specific to a HandsFree Server NOT an Audio Gateway.  Once a      */
   /* Server HFRE Port is opened, it can only be Un-Registered via a    */
   /* call to the HFRE_Close_Server_Port() function (passing the return */
   /* value from this function).  The HFRE_Close_Port() function can be */
   /* used to Disconnect a Client from the Server Port (if one is       */
   /* connected, it will NOT Un-Register the Server Port however).      */
   /* * NOTE * The Mandatory Hands-Free Indicators (call, service, and  */
   /*          call_setup) are automatically added to the list and need */
   /*          not be specified as additional indicators.               */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Open_Audio_Gateway_Server_Port(unsigned int BluetoothStackID, unsigned int ServerPort, unsigned long SupportedFeaturesMask, unsigned long CallHoldingSupportMask, unsigned int NumberAdditionalIndicators, HFRE_Control_Indicator_Entry_t AdditionalSupportedIndicators[], HFRE_Event_Callback_t EventCallback, unsigned long CallbackParameter);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Open_Audio_Gateway_Server_Port_t)(unsigned int BluetoothStackID, unsigned int ServerPort, unsigned long SupportedFeaturesMask, unsigned long CallHoldingSupportMask, unsigned int NumberAdditionalIndicators, HFRE_Control_Indicator_Entry_t AdditionalSupportedIndicators[], HFRE_Event_Callback_t EventCallback, unsigned long CallbackParameter);
#endif

   /* The following function is responsible for Un-Registering a HFRE   */
   /* Port Server (which was Registered by a successful call to either  */
   /* the HFRE_Open_HandsFree_Server_Port() or the                      */
   /* HFRE_Open_Audio_Gateway_Server_Port() function).  This function   */
   /* accepts as input the Bluetooth Stack ID of the Bluetooth Protocol */
   /* Stack that the HFRE Port specified by the Second Parameter is     */
   /* valid for.  This function returns zero if successful, or a        */
   /* negative return error code if an error occurred (see BTERRORS.H). */
   /* Note that this function does NOT delete any SDP Service Record    */
   /* Handles.                                                          */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Close_Server_Port(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Close_Server_Port_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is responsible for responding to requests  */
   /* to connect to a Server (either Handsfree or an Audio Gateway).    */
   /* This function accepts as input the Bluetooth Stack ID of the Local*/
   /* Bluetooth Protocol Stack, the HF/AG Port ID (which *MUST* have    */
   /* been obtained by calling either the                               */
   /* HFRE_Open_HandsFree_Server_Port() or the                          */
   /* HFRE_Open_Audio_Gateway_Server_Port() functions), and as the final*/
   /* parameter whether to accept the pending connection request.  This */
   /* function returns zero if successful, or a negative return value if*/
   /* there was an error.                                               */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Open_Port_Request_Response(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t AcceptConnection);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Open_Port_Request_Response_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t AcceptConnection);
#endif

   /* The following function is provided to allow a means to add a      */
   /* Generic Hands-Free Service Record to the SDP Database.  This      */
   /* function takes as input the Bluetooth Stack ID of the Local       */
   /* Bluetooth Protocol Stack, the HFRE Port ID (which *MUST* have been*/
   /* obtained by calling the HFRE_Open_HandsFree_Server_Port()         */
   /* function).  The third parameter specifies the Service Name to     */
   /* associate with the SDP Record.  The final parameter is a pointer  */
   /* to a DWord_t which receives the SDP Service Record Handle if this */
   /* function successfully creates an SDP Service Record.  If this     */
   /* function returns zero, then the SDPServiceRecordHandle entry will */
   /* contain the Service Record Handle of the added SDP Service Record.*/
   /* If this function fails, a negative return error code will be      */
   /* returned (see BTERRORS.H) and the SDPServiceRecordHandle value    */
   /* will be undefined.                                                */
   /* * NOTE * This function should only be called with the HFRE Port   */
   /*          ID that was returned from the                            */
   /*          HFRE_Open_HandsFree_Server_Port() function.  This        */
   /*          function should NEVER be used with HFRE Port ID          */
   /*          returned from the HFRE_Open_Audio_Gateway_Server_Port()  */
   /*          function.                                                */
   /* * NOTE * The Service Record Handle that is returned from this     */
   /*          function will remain in the SDP Record Database until    */
   /*          it is deleted by calling the SDP_Delete_Service_Record() */
   /*          function.                                                */
   /* * NOTE * A MACRO is provided to Delete the Service Record from    */
   /*          the SDP Data Base.  This MACRO maps the                  */
   /*          HFRE_Un_Register_SDP_Record() to                         */
   /*          SDP_Delete_Service_Record().                             */
   /* * NOTE * The Service Name is always added at Attribute ID 0x0100. */
   /*          A Language Base Attribute ID List is created that        */
   /*          specifies that 0x0100 is UTF-8 Encoded, English Language.*/
BTPSAPI_DECLARATION int BTPSAPI HFRE_Register_HandsFree_SDP_Record(unsigned int BluetoothStackID, unsigned int HFREPortID, char *ServiceName, DWord_t *SDPServiceRecordHandle);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Register_HandsFree_SDP_Record_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, char *ServiceName, DWord_t *SDPServiceRecordHandle);
#endif

   /* The following function is provided to allow a means to add a      */
   /* Generic Audio Gateway Service Record to the SDP Database.  This   */
   /* function takes as input the Bluetooth Stack ID of the Local       */
   /* Bluetooth Protocol Stack, the HFRE Port ID (which *MUST* have been*/
   /* obtained by calling the HFRE_Open_Audio_Gateway_Server_Port()     */
   /* function). The third parameter specifies the Network Type in which*/
   /* the Audio Gateway is attached or being attached to.  The fourth   */
   /* parameter specifies the Service Name to associate with the SDP    */
   /* Record.  The final parameter is a pointer to a DWord_t which      */
   /* receives the SDP Service Record Handle if this function           */
   /* successfully creates an SDP Service Record.  If this function     */
   /* returns zero, then the SDPServiceRecordHandle entry will contain  */
   /* the Service Record Handle of the added SDP Service Record.  If    */
   /* this function fails, a negative return error code will be returned*/
   /* (see BTERRORS.H) and the SDPServiceRecordHandle value will be     */
   /* undefined.                                                        */
   /* * NOTE * This function should only be called with the HFRE Port   */
   /*          ID that was returned from the                            */
   /*          HFRE_Open_Audio_Gateway_Server_Port() function.  This    */
   /*          function should NEVER be used with HFRE Port ID          */
   /*          returned from the HFRE_Open_HandsFree_Server_Port()      */
   /*          function.                                                */
   /* * NOTE * The Service Record Handle that is returned from this     */
   /*          function will remain in the SDP Record Database until    */
   /*          it is deleted by calling the SDP_Delete_Service_Record() */
   /*          function.                                                */
   /* * NOTE * A MACRO is provided to Delete the Service Record from    */
   /*          the SDP Data Base.  This MACRO maps the                  */
   /*          HFRE_Un_Register_SDP_Record() to                         */
   /*          SDP_Delete_Service_Record().                             */
   /* * NOTE * The Service Name is always added at Attribute ID 0x0100. */
   /*          A Language Base Attribute ID List is created that        */
   /*          specifies that 0x0100 is UTF-8 Encoded, English Language.*/
BTPSAPI_DECLARATION int BTPSAPI HFRE_Register_Audio_Gateway_SDP_Record(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int NetworkType, char *ServiceName, DWord_t *SDPServiceRecordHandle);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Register_Audio_Gateway_SDP_Record_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int NetworkType, char *ServiceName, DWord_t *SDPServiceRecordHandle);
#endif

   /* The following MACRO is a utility MACRO that simply deletes the    */
   /* HFRE SDP Service Record (specified by the third parameter) from   */
   /* the SDP Database.  This MACRO simply maps to the                  */
   /* SDP_Delete_Service_Record() function.  This MACRO is only         */
   /* provided so that the caller doesn't have to sift through the SDP  */
   /* API for very simplistic applications.  This function accepts as   */
   /* input the Bluetooth Stack ID of the Bluetooth Protocol Stack that */
   /* the Service Record exists on, the HFRE Port ID (returned from     */
   /* a successful call to the HFRE_Open_HandsFree_Server_Port() or the */
   /* HFRE_Open_Audio_Gateway_Server_Port() functions), and the SDP     */
   /* Service Record Handle.  The SDP Service Record Handle was         */
   /* returned via a succesful call to the                              */
   /* HFRE_Register_HandsFree_SDP_Record() or the                       */
   /* HFRE_Register_Audio_Gateway_SDP_Record() function.  See the       */
   /* HFRE_Register_xxxx_SDP_Record() functions for more information.   */
   /* This MACRO returns the result of the SDP_Delete_Service_Record()  */
   /* function, which is zero for success or a negative return error    */
   /* code (see BTERRORS.H).                                            */
#define HFRE_Un_Register_SDP_Record(__BluetoothStackID, __HFREPortID, __SDPRecordHandle) \
        (SDP_Delete_Service_Record(__BluetoothStackID, __SDPRecordHandle))

   /* The following function is responsible for Opening a Remote        */
   /* Hands-Free Port on the specified Remote Device.  This function    */
   /* accepts the Bluetooth Stack ID of the Bluetooth Stack which is to */
   /* open the HFRE Connection as the first parameter.  The second      */
   /* parameter specifies the Board Address (NON NULL) of the Remote    */
   /* Bluetooth Device to connect with.  The third parameter specifies  */
   /* the features the local Audio Gateway supports.  The next parameter*/
   /* is a bit mask which specifies the Call Hold and Multiparty        */
   /* Handling Features that are supported.  The fifth parameter to this*/
   /* function is the number of indicator names which appear in the list*/
   /* represented by the previous parameter.  The next parameter is a   */
   /* list of additional indicators in which this Audio Gateway will    */
   /* support.  If the Additional Indicators parameter is NULL and      */
   /* Number Additional Indicators is zero no additional parameters will*/
   /* be supported.  The final two parameters specify the HFRE Event    */
   /* Callback function, and callback parameter, respectively, of the   */
   /* HFRE Event Callback that is to process any further interaction    */
   /* with the specified Remote Port (Opening Status, Close Status,     */
   /* etc).  This function returns a non-zero, positive, value if       */
   /* successful, or a negative return error code if this function is   */
   /* unsuccessful.  If this function is successful, the return value   */
   /* will represent the HFRE Port ID that can be passed to all other   */
   /* functions that require it.  Once a Remote Hands-Free unit is      */
   /* opened, it can only be closed via a call to the HFRE_Close_Port() */
   /* function (passing the return value from this function).           */
   /* * NOTE * The Mandatory Hands-Free Indicators (call, service, and  */
   /*          call_setup) are automatically added to the list and need */
   /*          not be specified as additional indicators.               */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Open_Remote_HandsFree_Port(unsigned int BluetoothStackID, BD_ADDR_t BD_ADDR, unsigned int RemoteServerPort, unsigned long SupportedFeaturesMask, unsigned long CallHoldSupportMask, unsigned int NumberAdditionalIndicators, HFRE_Control_Indicator_Entry_t AdditionalSupportedIndicators[], HFRE_Event_Callback_t EventCallback, unsigned long CallbackParameter);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Open_Remote_HandsFree_Port_t)(unsigned int BluetoothStackID, BD_ADDR_t BD_ADDR, unsigned int RemoteServerPort, unsigned long SupportedFeaturesMask, unsigned long CallHoldSupportMask, unsigned int NumberAdditionalIndicators, HFRE_Control_Indicator_Entry_t AdditionalSupportedIndicators[], HFRE_Event_Callback_t EventCallback, unsigned long CallbackParameter);
#endif

   /* The following function is responsible for Opening a Remote Audio  */
   /* Gateway Port on the specified Remote Device.  This function       */
   /* accepts the Bluetooth Stack ID of the Bluetooth Stack which is to */
   /* open the HFRE Connection as the first parameter.  The second      */
   /* parameter specifies the Board Address (NON NULL) of the Remote    */
   /* Bluetooth Device to connect with.  The third parameter specifies  */
   /* the features in which the local Hands-Free unit supports.  The    */
   /* fourth parameter to this function is the number of indicator      */
   /* names.  The fifth parameter is a list of additional indicator     */
   /* names in which this Hands-Free unit will support.  If the         */
   /* Additional Indicators parameter is NULL and Number Additional     */
   /* Indicators is zero no additional parameters will be supported.    */
   /* The final two parameters specify the HFRE Event Callback function,*/
   /* and callback parameter, respectively, of the HFRE Event Callback  */
   /* that is to process any further interaction with the specified     */
   /* Remote Port (Opening Status, Close Status, etc).  This function   */
   /* returns a non-zero, positive, value if successful, or a negative  */
   /* return error code if this function is unsuccessful.  If this      */
   /* function is successful, the return value will represent the HFRE  */
   /* Port ID that can be passed to all other functions that require it.*/
   /* Once a Remote Audio Gateway is opened, it can only be closed via a*/
   /* call to the HFRE_Close_Port() function (passing the return value  */
   /* from this function).                                              */
   /* * NOTE * The Mandatory Hands-Free Indicators (call, service, and  */
   /*          call_setup) are automatically added to the list and need */
   /*          not be specified as additional indicators.               */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Open_Remote_Audio_Gateway_Port(unsigned int BluetoothStackID, BD_ADDR_t BD_ADDR, unsigned int RemoteServerPort, unsigned long SupportedFeaturesMask, unsigned int NumberAdditionalIndicators, char *AdditionalSupportedIndicators[], HFRE_Event_Callback_t EventCallback, unsigned long CallbackParameter);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Open_Remote_Audio_Gateway_Port_t)(unsigned int BluetoothStackID, BD_ADDR_t BD_ADDR, unsigned int RemoteServerPort, unsigned long SupportedFeaturesMask, unsigned int NumberAdditionalIndicators, char *AdditionalSupportedIndicators[], HFRE_Event_Callback_t EventCallback, unsigned long CallbackParameter);
#endif

   /* The following function exists to close a HFRE Port that was       */
   /* previously opened by any of the following mechanisms:             */
   /*   - Successful call to HFRE_Open_Remote_HandsFree_Port() function.*/
   /*   - Successful call to HFRE_Open_Remote_Audio_Gateway_Port()      */
   /*     function.                                                     */
   /*   - Incoming open request (Hands-Free or Audio Gateway) which the */
   /*     server was opened with either the                             */
   /*     HFRE_Open_HandsFree_Server_Port() or the                      */
   /*     HFRE_Open_Audio_Gateway_Server_Port() functions.              */
   /* This function accepts as input the Bluetooth Stack ID of the      */
   /* Bluetooth Stack which the Open HFRE Port resides and the          */
   /* HFRE Port ID (return value from one of the above mentioned Open   */
   /* functions) of the Port to Close.  This function returns zero if   */
   /* successful, or a negative return value if there was an error.     */
   /* This function does NOT Un-Register a HFRE Server Port from the    */
   /* system, it ONLY disconnects any connection that is currently      */
   /* active on the Server Port.  The HFRE_Close_Server_Port()          */
   /* function can be used to Un-Register the HFRE Server Port.         */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Close_Port(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Close_Port_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is responsible for Querying the Remote     */
   /* Control Indicator Status.  This function may only be performed by */
   /* a Hands-Free unit with a valid Service Level Connection.  The     */
   /* results to this Query will be returned as part of the Control     */
   /* Indicator Status Confirmation.  The function accepts the Bluetooth*/
   /* Stack ID for which the HFRE Port ID is valid as well as the HFRE  */
   /* Port ID.  This function returns zero if successful or a negative  */
   /* return error code if there was an error.                          */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Query_Remote_Control_Indicator_Status(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Query_Remote_Control_Indicator_Status_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is responsible for responding to a request */
   /* from a remote Hands Free device for the current control indicators*/
   /* of the local Audio Gateway unit.  This function may only be       */
   /* performed by Audio Gateways that have received a request for the  */
   /* current control indicators (the event is of type                  */
   /* etHFRE_Control_Indicator_Request_Indication).  This function      */
   /* accepts as its input parameters the Bluetooth Stack ID for which  */
   /* the HFRE Port ID is valid as well as the HFRE Port ID.  This      */
   /* function returns zero if successful or a negative return error    */
   /* code if there was an error.                                       */
   /* * NOTE * This function may only be called if the                  */
   /*                                                                   */
   /*              HFRE_AG_QUERY_INDICATOR_REQUEST_SUPPORTED_BIT        */
   /*                                                                   */
   /*          bit was set in the SupportedFeaturesMask parameter that  */
   /*          was passed to the HFRE_Open_Audio_Gateway_Server_Port()  */
   /*          or HFRE_Open_Remote_HandsFree_Port() API call that       */
   /*          returned the specified HFREPortID and then only in       */
   /*          response to a                                            */
   /*          etHFRE_Control_Indicator_Request_Indication event.       */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Control_Indicator_Request_Response(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Control_Indicator_Request_Response_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is responsible for Updating the Current    */
   /* Control Indicator Status.  This function may only be performed by */
   /* Audio Gateways that have a valid Service Level Connection or by   */
   /* Audio Gateways that have received the                             */
   /* etHFRE_Control_Indicator_Request_Indication event.  This function */
   /* accepts as its input parameters the Bluetooth Stack ID for which  */
   /* the HFRE Port ID is valid as well as the HFRE Port ID.  The third */
   /* parameter to this function is the number of name/value pairs that */
   /* are present in the list.  The final parameter to this function is */
   /* a list of name/value pairs for the indicators to be updated.  This*/
   /* function returns zero if successful or a negative return error    */
   /* code if there was an error.                                       */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Update_Current_Control_Indicator_Status(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int NumberUpdateIndicators, HFRE_Indicator_Update_t UpdateIndicators[]);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Update_Current_Control_Indicator_Status_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int NumberUpdateIndicators, HFRE_Indicator_Update_t UpdateIndicators[]);
#endif

   /* The following function is responsible for Updating the Current    */
   /* Control Indicator Status.  This function may only be performed by */
   /* Audio Gateways.  The function will initially set the specified    */
   /* indicator, then, if a valid Service Level Connection exists and   */
   /* event reporting is activated (via the Set Remote Event Indicator  */
   /* Event Notification function by the remote device) an event        */
   /* notification will be sent to the remote device.  This function    */
   /* accepts as its first input parameter the Bluetooth Stack Id.  The */
   /* second input parameter identifies the HFRE Port ID.  The third    */
   /* parameter to this function is a string indicator name.  The final */
   /* parameter to this function is the new indicator value.  This      */
   /* function returns zero if successful or a negative return error    */
   /* code if there was an error.                                       */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Update_Current_Control_Indicator_Status_By_Name(unsigned int BluetoothStackID, unsigned int HFREPortID, char *IndicatorName, unsigned int IndicatorValue);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Update_Current_Control_Indicator_Status_By_Name_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, char *IndicatorName, unsigned int IndicatorValue);
#endif

   /* This function is responsible for Enabling or Disabling the        */
   /* Indicator Event Notification on the Remote Device.  When Enabled  */
   /* the Remote device will send Unsolicited Responses to Update the   */
   /* local device of the Current Control Indicator Values.  This       */
   /* function may only be performed by Hands-Free units that have a    */
   /* valid Service Level Connection.  This function accepts as its     */
   /* input parameters the Bluetooth Stack ID for which the HFRE Port ID*/
   /* is valid as well as the HFRE Port ID.  The final parameter,       */
   /* EnableEventNotification, is a Boolean flag used to Enable or      */
   /* Disable Event Notification.  This function returns zero if        */
   /* successful or a negative return error code if there was an error. */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Enable_Remote_Indicator_Event_Notification(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t EnableEventNotification);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Set_Remote_Indicator_Event_Notification_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t ActivateEventNotification);
#endif

   /* The following function is responsible for Updating the Remote     */
   /* Indicator State.  This function may only be performed by          */
   /* Hands-Free units that have a valid Service Level Connection.  This*/
   /* function accepts as its input parameters the Bluetooth Stack ID   */
   /* for which the HFRE Port ID is valid as well as the HFRE Port ID.  */
   /* The third parameter to this function is the number of name/state  */
   /* pairs that are present in the list.  The final parameter to this  */
   /* function is a list of name/state pairs for the indicators to be   */
   /* updated.  This function returns zero if successful or a negative  */
   /* return error code if there was an error.                          */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Update_Remote_Indicator_Notification_State(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int NumberUpdateIndicators, HFRE_Notification_Update_t UpdateIndicators[]);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Update_Remote_Indicator_Notification_State_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int NumberUpdateIndicators, HFRE_Notification_Update_t UpdateIndicators[]);
#endif

   /* This function is responsible for Querying the Call Holding and    */
   /* Multiparty Services which are supported by the remote device.     */
   /* This function should be used by Hands-Free units which support    */
   /* Three Way Calling and Call Waiting to determine the features      */
   /* supported by the Audio Gateway.  This function can only be used if*/
   /* a valid Service Level Connection exists.  This function accepts as*/
   /* its input parameters the Bluetooth Stack ID for which the HFRE    */
   /* Port ID is valid as well as the HFRE Port ID.  This function      */
   /* returns zero if successful or a negative return error code if     */
   /* there was an error.                                               */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Query_Remote_Call_Holding_Multiparty_Service_Support(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Query_Remote_Call_Holding_Multiparty_Service_Support_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* This function is responsible for allowing the control of multiple */
   /* concurrent calls and provides a means for holding calls, releasing*/
   /* calls, switching between two calls and adding a call to a         */
   /* multiparty conference.  This function may only be performed by    */
   /* Hands-Free units that support call waiting and multiparty services*/
   /* as well as have a valid Service Level Connection.  The selection  */
   /* which is made should be one that is supported by the remote Audio */
   /* Gateway as queried via a call to the                              */
   /* HFRE_Query_Remote_Call_Holding_Multiparty_Service_Support()       */
   /* function.  This function accepts as its input parameters the      */
   /* Bluetooth Stack ID for which the HFRE Port ID is valid as well as */
   /* the HFRE Port ID.  The next parameter is the selection of how to  */
   /* handle the currently waiting call.  If the selected handling type */
   /* requires an index it should be provided in the last parameter.    */
   /* Otherwise the final paramter is ignored.  This function returns   */
   /* zero if successful or a negative return error code if there was an*/
   /* error.                                                            */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Call_Holding_Multiparty_Selection(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Call_Hold_Multiparty_Handling_Type_t CallHoldMultipartyHandling, unsigned int Index);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Call_Holding_Multiparty_Selection_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Call_Hold_Multiparty_Handling_Type_t CallHoldMultipartyHandling, unsigned int Index);
#endif

   /* This function is responsible for Enabling or Disabling Call       */
   /* Waiting Notification on the Remote Audio Gateway.  By default the */
   /* Call Waiting Notification is Enabled in the network but Disabled  */
   /* for notification via the Service Level Connection.  This function */
   /* may only be performed by a Hands-Free unit for which a valid      */
   /* Service Level Connection exists.  This function may only be used  */
   /* to enable call waiting notifications if the Local Hands-Free unit */
   /* supports Call Waiting and Multiparty Services, it may however be  */
   /* used to disable these services by all Hands-Free units.  This     */
   /* function accepts as its input parameters the Bluetooth Stack ID   */
   /* for which the HFRE Port ID is valid as well as the HFRE Port ID.  */
   /* The final parameter is a Boolean flag specifying if this is a call*/
   /* to Enable or Disable this functionality.  This function returns   */
   /* zero if successful or a negative return error code if there was an*/
   /* error.                                                            */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Enable_Remote_Call_Waiting_Notification(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t EnableNotification);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Enable_Remote_Call_Waiting_Notification_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t EnableNotification);
#endif

   /* This function is responsible for Sending Call Waiting             */
   /* Notifications to the Remote Device.  This function may only be    */
   /* performed by Audio Gateways which have Call Waiting Notification  */
   /* Enabled and have a valid Service Level Connection.  This function */
   /* accepts as its first input parameter the HFRE Port ID.  The final */
   /* parameter is the Phone Number required as one of the parameters   */
   /* within this response.  This parameter should be a pointer to a    */
   /* NULL terminated string (if specified) and must have a length less */
   /* than HFRE_PHONE_NUMBER_LENGTH_MAXIMUM.  This function returns zero*/
   /* if successful or a negative return error code if there was an     */
   /* error.                                                            */
   /* * NOTE * It is valid to either pass a NULL for the PhoneNumber    */
   /*          parameter of a blank string to specify that there is no  */
   /*          phone number present.                                    */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Call_Waiting_Notification(unsigned int BluetoothStackID, unsigned int HFREPortID, char *PhoneNumber);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Call_Waiting_Notification_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, char *PhoneNumber);
#endif

   /* This function is responsible for Enabling or Disabling Call Line  */
   /* Identification Notification on the Remote Audio Gateway.  By      */
   /* default the Call Line Identification notification via the Service */
   /* Level Connection is Disabled.  This function may only be performed*/
   /* by Hands-Free units for which a valid Service Level Connection    */
   /* exists.  This function may only be used to enable call line       */
   /* notifications if the Local Hands-Free unit supports Call Line     */
   /* Identification, it may however be used to disable this service by */
   /* all Hands-Free units.  This function accepts as its input         */
   /* parameters the Bluetooth Stack ID for which the HFRE Port ID is   */
   /* valid as well as the HFRE Port ID.  The final parameter is a      */
   /* Boolean flag specifying if this is a call to Enable or Disable    */
   /* this functionality.  This function returns zero if successful or a*/
   /* negative return error code if there was an error.                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Enable_Remote_Call_Line_Identification_Notification(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t EnableNotification);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Enable_Remote_Call_Line_Identification_Notification_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t EnableNotification);
#endif

   /* This function is responsible for sending Call Line Identification */
   /* Notifications to the Remote device.  This function may only be    */
   /* performed by Audio Gateways which have Call Line Identification   */
   /* Notification Enabled and have a valid Service Level Connection.   */
   /* This function accepts as its input parameters the Bluetooth Stack */
   /* ID for which the HFRE Port ID is valid as well as the HFRE Port   */
   /* ID.  The final parameter is the Phone Number required as one of   */
   /* the parameters within this response.  This parameter should be a  */
   /* pointer to a NULL terminated string and its length *MUST* be      */
   /* between the values of HFRE_PHONE_NUMBER_LENGTH_MINIMUM and        */
   /* HFRE_PHONE_NUMBER_LENGTH_MAXIMUM.  This function return zero if   */
   /* successful or a negative return error code if there was an error. */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Call_Line_Identification_Notification(unsigned int BluetoothStackID, unsigned int HFREPortID, char *PhoneNumber);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Call_Line_Identification_Notification_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, char *PhoneNumber);
#endif

   /* This function is responsible for Disabling Echo Cancelation and   */
   /* Noise Reduction on the Remote Device.  This function may be       */
   /* performed by both the Hands-Free unit and the Audio Gateway for   */
   /* which a valid Service Level Connection exist but no Audio         */
   /* Connection exists.  This function accepts as its input parameters */
   /* the Bluetooth Stack ID for which the HFRE Port ID is valid as well*/
   /* as the HFRE Port ID.  This function returns zero if successful or */
   /* a negative return error code if there was an error.               */
   /* ** NOTE ** It is not possible to enable this feature once it has  */
   /*            been disbled because the specification provides no     */
   /*            means to re-enable this feature.  This feature will    */
   /*            remained disabled until the current Service Level      */
   /*            Connection has been dropped.                           */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Disable_Remote_Echo_Cancelation_Noise_Reduction(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Disable_Remote_Echo_Cancelation_Noise_Reduction_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* This function is responsible for Dialing a Phone Number on the    */
   /* Remote Audio Gateway.  This function may only be performed by     */
   /* Hands-Free units for which a valid Service Level Connection       */
   /* exists.  This function accepts as its input parameters the        */
   /* Bluetooth Stack ID for which the HFRE Port ID is valid as well as */
   /* the HFRE Port ID.  The final parameter is the Phone Number to dial*/
   /* on the Remote Audio Gateway.  This parameter should be a pointer  */
   /* to a NULL terminated string and its length *MUST* be between the  */
   /* values of HFRE_PHONE_NUMBER_LENGTH_MINIMUM and                    */
   /* HFRE_PHONE_NUMBER_LENGTH_MAXIMUM.  This function returns zero if  */
   /* successful or a negative return error code if there was an error. */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Dial_Phone_Number(unsigned int BluetoothStackID, unsigned int HFREPortID, char *PhoneNumber);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Dial_Phone_Number_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, char *PhoneNumber);
#endif

   /* This function is responsible for Dialing a Phone Number at a      */
   /* Memory Location found on the Remote Audio Gateway.  This function */
   /* may only be performed by Hands-Free units for which a valid       */
   /* Service Level Connection exists.  This function accepts as its    */
   /* input parameters the Bluetooth Stack ID for which HFRE Port ID is */
   /* valid as well as the HFRE Port ID.  The final parameter is the    */
   /* Memory Location for which the Phone Number to Dial exists on the  */
   /* Remote Audio Gateway.  This function returns zero if successful or*/
   /* a negative return error code if there was an error.               */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Dial_Phone_Number_From_Memory(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int MemoryLocation);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Dial_Phone_Number_From_Memory_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int MemoryLocation);
#endif

   /* This function is responsible for Redialing the Last Number Dialed */
   /* on the Remote Audio Gateway.  This function may only be performed */
   /* by Hands-Free units for which a valid Service Level Connection    */
   /* exists.  This function accepts as its input parameters the        */
   /* Bluetooth Stack ID for which the HFRE Port ID is valid as well as */
   /* the HFRE Port ID.  This function returns zero if successful or a  */
   /* negative return error code if there was an error.                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Redial_Last_Phone_Number(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Redial_Last_Phone_Number_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* This function is responsible for sending a Ring Indication to the */
   /* Remote Hands-Free unit.  This function may only be performed by   */
   /* Audio Gateways for which a valid Service Level Connection exists. */
   /* This function accepts as its input parameters the Bluetooth Stack */
   /* ID for which the HFRE Port ID is valid as well as the HFRE Port   */
   /* ID.  This function returns zero if successful or a negative return*/
   /* error code if there was an error.                                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Ring_Indication(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Ring_Indication_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* This function is responsible for sending the command to Answer an */
   /* Incoming call on a Remote Audio Gateway.  This function may only  */
   /* be performed by Hands-Free units for which a valid Service Level  */
   /* Connection exists.  This function accepts as its input parameters */
   /* the Bluetooth Stack ID for which the HFRE Port ID is valid as well*/
   /* as the HFRE Port ID.  This function return zero if successful or a*/
   /* negative return error code if there was an error.                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Answer_Incoming_Call(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Answer_Incoming_Call_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* This function is responsible for Enabling or Disabling In-Band    */
   /* Ring Tone Capabilities for the Local Device.  This function may   */
   /* only be performed by Audio Gateways for which a valid Service     */
   /* Level Connection exists.  This function may only be used to enable*/
   /* In-Ring Tone Capabilities if the Local Audio Gateway supports this*/
   /* feature.  This function accepts as its input parameters the       */
   /* Bluetooth Stack ID for which the HFRE Port ID is valid as well as */
   /* the HFRE Port ID.  The final parameter is a Boolean flag          */
   /* specifying if this is a call to Enable or Disable this            */
   /* functionality.  This function returns zero if successful or a     */
   /* negative return error code if there was an error.                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Enable_Remote_InBand_Ring_Tone_Setting(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t EnableInBandRing);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Enable_Remote_InBand_Ring_Tone_Setting_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t EnableInBandRing);
#endif

   /* This function is responsible for Transmitting DTMF Codes to the   */
   /* Remote Audio Gateway to be sent as a DTMF Tone over an on-going   */
   /* call.  This function may only be performed by Hands-Free units for*/
   /* which a valid Service Level Connection exists and an ongoing call */
   /* in the Audio Gateway exists.  This function accepts as its input  */
   /* parameters the Bluetooth Stack ID for which the HFRE Port ID is   */
   /* valid as well as the HFRE Port ID.  The final parameter is the    */
   /* DTMF Code to be transmitted, this Code must be a character 0-9, *,*/
   /* #, or A-D.  This function returns zero if successful or a negative*/
   /* return error code if there was an error.                          */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Transmit_DTMF_Code(unsigned int BluetoothStackID, unsigned int HFREPortID, char DTMFCode);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Transmit_DTMF_Code_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, char DTMFCode);
#endif

   /* This function is responsible for activation and deactivation of   */
   /* the Voice Recognition which resides on the Remote Audio Gateway   */
   /* when called by a Hands-Free unit.  When called by an Audio Gateway*/
   /* this function is responsible for informing the remote Hands-Free  */
   /* unit of the current activation state of the local Voice           */
   /* Recognition function.  This function may only be called by local  */
   /* devices that were opened with the Supported Feature Bit set for   */
   /* Voice Recognition.  This function accepts as its input parameters */
   /* the Bluetooth Stack ID for which the HFRE Port ID is valid as well*/
   /* as the HFRE Port ID.  The final parameter is a Boolean flag       */
   /* specifying if this is a call to Activate or Deactivate this       */
   /* function on a Remote Audio Gateway, or to specify that Voice      */
   /* Recoginition is locally Activated or Deactivated to a Remote      */
   /* Hands-Free unit.  When active the Voice Recognition function on   */
   /* the Audio Gateway is turned on, when inactive the Voice           */
   /* Recognition function on the Audio Gateway is turned off.  This    */
   /* function returns zero if successful or a negative return error    */
   /* code if there was an error.                                       */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Set_Remote_Voice_Recognition_Activation(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t VoiceRecognitionActive);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Set_Remote_Voice_Recognition_Activation_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t EnableVoiceRecognition);
#endif

   /* This function is responsible for allowing synchronization and     */
   /* setting of the Remote Devices Speaker Gain.  This function may    */
   /* only be performed if a valid Service Level Connection exists.     */
   /* When called by a Hands-Free unit this function is provided as a   */
   /* means to inform the Remote Audio Gateway of the current Speaker   */
   /* Gain value.  When called by an Audio Gateway this function        */
   /* provides a means for the Audio Gateway to control the Speaker Gain*/
   /* of the Remote Hands-Free unit.  This function accepts as its input*/
   /* parameters the Bluetooth Stack ID for which the HFRE Port ID is   */
   /* valid as well as the HFRE Port ID.  The final parameter is the    */
   /* Speaker Gain to be sent to the Remote Device.  The Speaker Gain   */
   /* Parameter *MUST* be between the values of                         */
   /* HFRE_SPEAKER_GAIN_MINIMUM and HFRE_SPEAKER_GAIN_MAXIMUM.  This    */
   /* function returns zero if successful or a negative return error    */
   /* code if there was an error.                                       */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Set_Remote_Speaker_Gain(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int SpeakerGain);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Set_Remote_Speaker_Gain_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int SpeakerGain);
#endif

   /* This function is responsible for allowing synchronization and     */
   /* setting of the Remote Devices Microphone Gain.  This function may */
   /* only be performed if a valid Service Level Connection exists.     */
   /* When called by a Hands-Free unit this function is provided as a   */
   /* means to inform the Remote Audio Gateway of the current Microphone*/
   /* Gain value.  When called by an Audio Gateway this function        */
   /* provides a means for the Audio Gateway to control the Microphone  */
   /* Gain of the Remote Hands-Free unit.  This function accepts as its */
   /* input parameters the Bluetooth Stack ID for which the HFRE Port ID*/
   /* is valid as well as the HFRE Port ID.  The final parameter is the */
   /* Microphone Gain to be sent to the Remote Device.  The Microphone  */
   /* Gain Parameter *MUST* be between the values of                    */
   /* HFRE_MICROPHONE_GAIN_MINIMUM and HFRE_MICROPHONE_GAIN_MAXIMUM.    */
   /* This function returns zero if successful or a negative return     */
   /* error code if there was an error.                                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Set_Remote_Microphone_Gain(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int MicrophoneGain);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Set_Remote_Microphone_Gain_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int MicrophoneGain);
#endif

   /* This function is responsible for retrieving a Phone Number to     */
   /* associate with a unique voice tag to be stored in memory by the   */
   /* Local Hands-Free unit.  This function may only be performed by a  */
   /* Hands-Free unit for which a valid Service Level Connection Exists.*/
   /* The Hands-Free unit must also support Voice Recognition to be able*/
   /* to use this function.  This function accepts as its input         */
   /* parameters the Bluetooth Stack ID for which the HFRE Port ID is   */
   /* valid as well as the HFRE Port ID.  This function returns zero if */
   /* successful or a negative return error code if there was an error. */
   /* ** NOTE ** When this function is called no other function may be  */
   /*            called until a Voice Tag Response is received from the */
   /*            Remote Audio Gateway.                                  */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Voice_Tag_Request(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Voice_Tag_Request_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* This function is responsible for responding to a request that was */
   /* received for a Phone Number to be associated with a unique Voice  */
   /* Tag by the Remote Hands-Free Unit.  This function may only be     */
   /* performed by Audio Gateways that have received a Voice Tag Request*/
   /* Indication.  This function accepts as its input parameters the    */
   /* Bluetooth Stack ID for which the HFRE Port ID is valid as well as */
   /* the HFRE Port ID.  The final parameter to this function if the    */
   /* Request is accepted is the Phone Number to be associated with the */
   /* Voice Tag.  The Phone Number Parameter String Length *MUST* be    */
   /* between the values of HFRE_PHONE_NUMBER_LENGTH_MINIMUM and        */
   /* HFRE_PHONE_NUMBER_LENGTH_MAXIMUM.  If the caller wished to Reject */
   /* the request, the Phone Number parameter should be set to NULL to  */
   /* indicate this.  This function returns zero if successful or a     */
   /* negative return error code if there was an error.                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Voice_Tag_Response(unsigned int BluetoothStackID, unsigned int HFREPortID, char *PhoneNumber);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Voice_Tag_Response_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, char *PhoneNumber);
#endif

   /* This function is responsible for sending a Hang-Up Command to the */
   /* Remote Audio Gateway.  This function may be used to Reject an     */
   /* incoming call, or to terminate an ongoing call.  This function may*/
   /* only be performed by Hands-Free units for which a valid Service   */
   /* Level Connection exists.  This function accepts as its input      */
   /* parameters the Bluetooth Stack ID for which the HFRE Port ID is   */
   /* valid as well as the HFRE Port ID.  This function returns zero if */
   /* successful or a negative return error code if there was an error. */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Hang_Up_Call(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Hang_Up_Call_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* This function is responsible for Setting Up an Audio Connection   */
   /* between the Local and Remote Device.  This function may be used by*/
   /* either an Audio Gateway or a Hands-Free unit for which a valid    */
   /* Service Level Connection Exists.  This function accepts as its    */
   /* input parameters the Bluetooth Stack ID for which the HFRE Port ID*/
   /* is valid as well as the HFRE Port ID.  This function returns zero */
   /* if successful or a negative return error code if there was an     */
   /* error.                                                            */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Setup_Audio_Connection(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Setup_Audio_Connection_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* This function is responsible for Releasing an Audio Connection    */
   /* which was previously established by the Remote Device or by a call*/
   /* to the HFRE_Setup_Audio_Connection() function.  This function may */
   /* be used by either an Audio Gateway or a Hands-Free unit.  This    */
   /* function accepts as its input parameters the Bluetooth Stack ID   */
   /* for which the HFRE Port ID is valid as well as the HFRE Port ID.  */
   /* This function returns zero if successful or a negative return     */
   /* error code if there was an error.                                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Release_Audio_Connection(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Release_Audio_Connection_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is provided to provide the local entity a  */
   /* mechanism of sending SCO Audio Data to the Remote entity.  This   */
   /* function can only be called once an Audio Connection has been     */
   /* established.  This function accepts as input the Bluetooth Stack  */
   /* ID of the Bluetooth Stack which the HFRE Port ID (second          */
   /* parameter) is valid for, the HFRE Port ID, the Length (in Bytes)  */
   /* of the Audio Data to send, and a pointer to the Audio Data to send*/
   /* to the Remote Entity.  This function returns zero if successful or*/
   /* a negative return error code if there was an error.               */
   /* ** NOTE ** This function is only applicable for Bluetooth Devices */
   /*            that support Packetized SCO Audio.  This function will */
   /*            have no effect on Codec based Bluetooth Devices.       */
   /* * NOTE * If this function returns the Error Code:                 */
   /*          BTPS_ERROR_INSUFFICIENT_BUFFER_SPACE then this is a      */
   /*          signal to the caller that the requested data could NOT be*/
   /*          sent because the requested data could not be queued in   */
   /*          the Outgoing Audio Queue.  The caller then, must wait for*/
   /*          the etHFRE_Audio_Data_Indication Event before trying to  */
   /*          send any more data.                                      */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Audio_Data(unsigned int BluetoothStackID, unsigned int HFREPortID, Byte_t AudioDataLength, Byte_t *AudioData);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Audio_Data_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, Byte_t AudioDataLength, Byte_t *AudioData);
#endif

   /* The following function is responsible for Querying the Current    */
   /* Call List of the remote device.  This function may only be        */
   /* performed by a Hands-Free unit with a valid Service Level         */
   /* Connection.  This function accepts as its input parameters the    */
   /* Bluetooth Stack ID for which the HFRE Port ID is valid as well as */
   /* the HFRE Port ID.  This function returns zero if successful or a  */
   /* negative return error code if there was an error.                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Query_Remote_Current_Calls_List(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Query_Remote_Current_Calls_List_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is responsible for Sending Current Calls   */
   /* List Entries to the Remote Device.  This function may only be     */
   /* performed by Audio Gateways that have received a request to query */
   /* the remote current calls list.  This function accepts as its input*/
   /* parameters the Bluetooth Stack ID for which the HFRE Port ID is   */
   /* valid as well as the HFRE Port ID.  The third parameter to this   */
   /* function is the current call list entry to be sent.  The final    */
   /* parameter to this function is a boolean indicating if this is the */
   /* last call list entry to be sent therefore requiring that an OK be */
   /* sent as well.  This function returns zero if successful or a      */
   /* negative return error code if there was an error.                 */
   /* * NOTE * If the third parameter is specified as NULL, then the    */
   /*          Final parameter *MUST* specify that this is the Final    */
   /*          Entry.  In this case, no call list entry will be sent,   */
   /*          however, the terminating response will be sent.          */
   /* * NOTE * This function does not send the Phonebook Name as part of*/
   /*          the Call List Entry.  Use                                */
   /*          HFRE_Send_Current_Calls_List_With_Phonebook_Name if you  */
   /*          wish to also send the Phonebook Name with the entry.     */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Current_Calls_List(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Current_Call_List_Entry_t *CurrentCallListEntry, Boolean_t FinalEntry);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Current_Calls_List_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Current_Call_List_Entry_t *CurrentCallListEntry, Boolean_t FinalEntry);
#endif

   /* The following function is responsible for Sending Current Calls   */
   /* List Entries to the Remote Device.  This function may only be     */
   /* performed by Audio Gateways that have received a request to query */
   /* the remote current calls list.  This function accepts as its input*/
   /* parameters the Bluetooth Stack ID for which the HFRE Port ID is   */
   /* valid as well as the HFRE Port ID.  The third parameter to this   */
   /* function is the current call list entry to be sent.  The final    */
   /* parameter to this function is a boolean indicating if this is the */
   /* last call list entry to be sent therefore requiring that an OK be */
   /* sent as well.  This function returns zero if successful or a      */
   /* negative return error code if there was an error.                 */
   /* * NOTE * If the third parameter is specified as NULL, then the    */
   /*          Final parameter *MUST* specify that this is the Final    */
   /*          Entry.  In this case, no call list entry will be sent,   */
   /*          however, the terminating response will be sent.          */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Current_Calls_List_With_Phonebook_Name(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Current_Call_List_Entry_t *CurrentCallListEntry, Boolean_t FinalEntry);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Current_Calls_List_With_Phonebook_Name_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Current_Call_List_Entry_t *CurrentCallListEntry, Boolean_t FinalEntry);
#endif

   /* The following function is responsible for setting the network     */
   /* operator format to long alphanumeric.  This function may only be  */
   /* performed by a Hands-Free unit with a valid Service Level         */
   /* Connection.  This function accepts as its input parameters the    */
   /* Bluetooth Stack ID for which the HFRE Port ID is valid as well as */
   /* the HFRE Port ID.  This function returns zero if successful or a  */
   /* negative return error code if there was an error.                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Set_Network_Operator_Selection_Format(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Set_Network_Operator_Selection_Format_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is responsible for reading the network     */
   /* operator.  This function may only be performed by a Hands-Free    */
   /* unit with a valid Service Level Connection.  This function accepts*/
   /* as its input parameters the Bluetooth Stack ID for which the HFRE */
   /* Port ID is valid as well as the HFRE Port ID.  This function      */
   /* returns zero if successful or a negative return error code if     */
   /* there was an error.                                               */
   /* ** NOTE ** The network operator format must be set before querying*/
   /*            the current network operator.                          */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Query_Remote_Network_Operator_Selection(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Query_Remote_Network_Operator_Selection_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is responsible for sending the network     */
   /* operator.  This function may only be performed by Audio Gateways  */
   /* that have received a request to query the remote network operator */
   /* selection.  This function accepts as its input parameters the     */
   /* Bluetooth Stack ID for which the HFRE Port ID is valid as well as */
   /* the HFRE Port ID.  The third parameter to this function is the    */
   /* current Network Mode.  The final parameter The final parameter is */
   /* the current Network Operator.  This parameter should be a pointer */
   /* to a NULL terminated string (if specified) and must have a length */
   /* less than HFRE_NETWORK_OPERATOR_LENGTH_MAXIMUM.  This function    */
   /* returns zero if successful or a negative return error code if     */
   /* there was an error.                                               */
   /* * NOTE * It is valid to either pass a NULL for the NetworkOperator*/
   /*          parameter of a blank string to specify that there is no  */
   /*          Network Operator present.                                */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Network_Operator_Selection(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int NetworkMode, char *NetworkOperator);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Operator_Selection_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int NetworkMode, char *NetworkOperator);
#endif

   /* The following function is responsible for Enabling or Disabling   */
   /* Extended Error Results Reporting.  This function may only be      */
   /* performed by a Hands-Free unit with a valid Service Level         */
   /* Connection.  This function accepts as its input parameters the    */
   /* Bluetooth Stack ID for which the HFRE Port ID is valid as well as */
   /* the HFRE Port ID.  This function returns zero if successful or a  */
   /* negative return error code if there was an error.                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Enable_Remote_Extended_Error_Result(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t EnableExtendedErrorResults);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Enable_Remote_Extended_Error_Result_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, Boolean_t EnableExtendedErrorResults);
#endif

   /* The following function is responsible for Extended Error Results. */
   /* This function may only be performed by an Audio Gateway with a    */
   /* valid Service Level Connection.  This function accepts as its     */
   /* input parameters the Bluetooth Stack ID for which the HFRE Port ID*/
   /* is valid as well as the HFRE Port ID.  The final parameter to this*/
   /* function is the Result Code to send as part of the Error Message. */
   /* This function returns zero if successful or a negative return     */
   /* error code if there was an error.                                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Extended_Error_Result(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int ResultCode);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Extended_Error_Result_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int ResultCode);
#endif

   /* The following function is responsible for retrieving the          */
   /* subscriber number information.  This function may only be         */
   /* performed by a Hands-Free with a valid Service Level Connection.  */
   /* This function accepts as its input parameters the Bluetooth Stack */
   /* ID for which the HFRE Port ID is valid as well as the HFRE Port   */
   /* ID.  This function returns zero if successful or a negative return*/
   /* error code if there was an error.                                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Query_Subscriber_Number_Information(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Query_Subscriber_Number_Information_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is responsible for sending Subscriber      */
   /* Number Information.  This function may only be performed by Audio */
   /* Gateways that have received a request to query the subscriber     */
   /* number information.  This function accepts as its input parameters*/
   /* the Bluetooth Stack ID for which the HFRE Port ID is valid as well*/
   /* as the HFRE Port ID.  The third parameter to this function is the */
   /* phone number to be sent as part of this response.  The Phone      */
   /* Number Parameter String Length *MUST* be between the values of    */
   /* HFRE_PHONE_NUMBER_LENGTH_MINIMUM and                              */
   /* HFRE_PHONE_NUMBER_LENGTH_MAXIMUM.  The fourth parameter to this   */
   /* function is the Service type related to the specified Phone       */
   /* Number.  The fifth paramter to this function is the Number Format */
   /* to use for this number, The final parameter to this function is a */
   /* boolean indicating if this is the last subscriber number          */
   /* information entry to be sent therefore requiring that an OK be    */
   /* sent as well.  This function returns zero if successful or a      */
   /* negative return error code if there was an error.                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Subscriber_Number_Information(unsigned int BluetoothStackID, unsigned int HFREPortID, char *PhoneNumber, unsigned int ServiceType, unsigned int NumberFormat, Boolean_t FinalEntry);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Subscriber_Number_Information_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, char *PhoneNumber, unsigned int ServiceType, unsigned int NumberFormat, Boolean_t FinalEntry);
#endif

   /* The following function is responsible for retrieving the current  */
   /* response and hold status.  This function may only be performed by */
   /* a Hands-Free unit with a valid Service Level Connection.  This    */
   /* function accepts as its input parameters the Bluetooth Stack ID   */
   /* for which the HFRE Port ID is valid as well as the HFRE Port ID.  */
   /* This function returns zero if successful or a negative return     */
   /* error code if there was an error.                                 */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Query_Response_Hold_Status(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Query_Response_Hold_Status_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is responsible for setting the state of an */
   /* incoming call.  This function may only be performed by a          */
   /* Hands-Free unit with a valid Service Level Connection.  This      */
   /* function accepts as its input parameters the Bluetooth Stack ID   */
   /* for which the HFRE Port ID is valid as well as the HFRE Port ID.  */
   /* The final parameter to this function indicates the call state to  */
   /* set as part of this message.  This function returns zero if       */
   /* successful or a negative return error code if there was an error. */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Set_Incoming_Call_State(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Call_State_t CallState);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Set_Incoming_Call_State_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Call_State_t CallState);
#endif

   /* The following function is responsible for sending information     */
   /* about the incoming call state.  This function may only be         */
   /* performed by Audio Gateways that have a valid Service Level       */
   /* Connection.  This function accepts as its input parameters the    */
   /* Bluetooth Stack ID for which the HFRE Port ID is valid as well as */
   /* the HFRE Port ID.  The final parameter to this function indicates */
   /* the call state to set as part of this message.  This function     */
   /* returns zero if successful or a negative return error code if     */
   /* there was an error.                                               */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Incoming_Call_State(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Call_State_t CallState);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Incoming_Call_State_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Call_State_t CallState);
#endif

   /* The following function is responsible for sending a terminating   */
   /* response code from the AG to a remote HF.  This function may only */
   /* be performed by Audio Gateways that have a valid Service Level    */
   /* Connection.  This function can be called in any context where a   */
   /* normal AG response function is called if the intention is to      */
   /* generate an error in response to the request.  It also must be    */
   /* called after certain requests that previously automatically       */
   /* generated an OK response.  In general, either this function or an */
   /* explicit response must be called after each request to the AG.    */
   /* This function accepts as its input parameters the Bluetooth Stack */
   /* ID for which the HFRE Port ID is valid as well as the HFRE Port   */
   /* ID.  The next parameter to this function indicates the type of    */
   /* result to return in the terminating response.  This this          */
   /* ResultType indicates an extended error code value, the final      */
   /* parameter is an unsigned integer containing the error code to     */
   /* return.  This function returns zero if successful or a negative   */
   /* return error code if there was an error.                          */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Terminating_Response(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Extended_Result_t ResultType, unsigned int ResultValue);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Terminating_Response_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, HFRE_Extended_Result_t ResultType, unsigned int ResultValue);
#endif

   /* The following function is responsible for enabling the processing */
   /* of arbitrary commands from the remote Hands Free device.  Once    */
   /* this function is called the etHFRE_Arbitrary_Command_Indication   */
   /* event will be dispatched when an Arbitrary command is received    */
   /* (i.e. a non Hands Free Profile command).  If this function is not */
   /* called, the Audio Gateway will silently respond to any arbitrary  */
   /* commands with an error response ("ERROR").  If support is enabled,*/
   /* then the caller is responsible for responding TO ALL arbitrary    */
   /* command indications (etHFRE_Arbitrary_Command_Indication).  If the*/
   /* arbitrary command is not supported, then the caller should simply */
   /* respond with                                                      */
   /*                                                                   */
   /*   HFRE_Send_Terminating_Response()                                */
   /*                                                                   */
   /* specifying the erError response.  This function accepts as its    */
   /* input parameters the Bluetooth Stack ID for which the HFRE Port ID*/
   /* is valid as well as the HFRE Port ID.  This function returns zero */
   /* if successful or a negative return error code if there was an     */
   /* error.                                                            */
   /* * NOTE * Once Arbitrary Command processing is enabled for an      */
   /*          Audio Gateway (server or client) it cannot be disabled.  */
   /* * NOTE * The default value is disabled (i.e. the                  */
   /*          etHFRE_Arbitrary_Command_Indication will NEVER be        */
   /*          dispatched and the Audio Gateway will always respond     */
   /*          with an error response ("ERROR") when an Arbitrary       */
   /*          command is received.                                     */
   /* * NOTE * If support is enabled, the caller is guaranteed that a   */
   /*          etHFRE_Arbitrary_Command_Indication will NOT be          */
   /*          dispatched before a Service Level Indication is present. */
   /*          If an arbitrary command is received, it will be          */
   /*          responded with silently with an error response ("ERROR").*/
   /* * NOTE * This function is not applicable to Hands Free devices,   */
   /*          as Hands Free devices will always receive the            */
   /*          etHFRE_Arbitrary_Response_Indication.  No action is      */
   /*          required and the event can simply be ignored.            */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Enable_Arbitrary_Command_Processing(unsigned int BluetoothStackID, unsigned int HFREPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Enable_Arbitrary_Command_Processing_t)(unsigned int BluetoothStackID, unsigned int HFREPortID);
#endif

   /* The following function is responsible for sending an arbitrary    */
   /* command to the remote Audio Gateway (i.e. non Bluetooth Hands     */
   /* Free Profile command).  This function may only be performed by a  */
   /* Hands-Free with a valid Service Level Connection.  This function  */
   /* accepts as its input parameters the Bluetooth Stack ID for which  */
   /* the HFRE Port ID is valid as well as the HFRE Port ID.  The final */
   /* parameter to this function specifies a NULL terminated ASCII      */
   /* string that represents the arbitrary command to send.  This       */
   /* function returns zero if successful or a negative return error    */
   /* code if there was an error.                                       */
   /* * NOTE * The Command string passed to this function *MUST* begin  */
   /*          with AT and *MUST* end with the a carriage return ('\r') */
   /*          if this is the first portion of an arbitrary command     */
   /*          that will span multiple writes.  Subsequent calls (until */
   /*          the actual status reponse is received) can begin with    */
   /*          any character, however, they must end with a carriage    */
   /*          return ('\r').                                           */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Arbitrary_Command(unsigned int BluetoothStackID, unsigned int HFREPortID, char *ArbitraryCommand);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Arbitrary_Command_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, char *ArbitraryCommand);
#endif

   /* The following function is responsible for sending an arbitrary    */
   /* response to the remote Hands Free device (i.e. non Bluetooth      */
   /* Hands Free Profile response) - either solicited or non-solicited. */
   /* This function may only be performed by an Audio Gateway with a    */
   /* valid Service Level Connection.  This function accepts as its     */
   /* input parameters the Bluetooth Stack ID for which the HFRE Port ID*/
   /* is valid as well as the HFRE Port ID.  The final parameter to this*/
   /* function specifies a NULL terminated ASCII string that represents */
   /* the arbitrary response to send.  This function returns zero if    */
   /* successful or a negative return error code if there was an error. */
   /* * NOTE * The Response string passed to this function *MUST* begin */
   /*          with a carriage return/line feed ("\r\n").               */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Arbitrary_Response(unsigned int BluetoothStackID, unsigned int HFREPortID, char *ArbitraryResponse);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Arbitrary_Response_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, char *ArbitraryResponse);
#endif

   /* The following function is responsible for retrieving the current  */
   /* HF/AG Server Server Mode for a specified HF/AG Gateway server.    */
   /* This function accepts as its first parameter the Bluetooth Stack  */
   /* ID of the Bluetooth Stack on which the server exists.  The second */
   /* parameter is the HF/AG Port ID that specifies the individual      */
   /* Server (this *MUST* be a value that was obtained by calling either*/
   /* the HFRE_Open_HandsFree_Server_Port() or the                      */
   /* HFRE_Open_Audio_Gateway_Server_Port() functions).  The final      */
   /* parameter to this function is a pointer to a Server Mode variable */
   /* which will receive the current Server Mode.  This function returns*/
   /* zero if successful, or a negative return error code if an error   */
   /* occurred.                                                         */
   /* ** NOTE ** The Default Server Mode is                             */
   /*               HFRE_SERVER_MODE_AUTOMATIC_ACCEPT_CONNECTION.       */
   /* ** NOTE ** This function is used for HF/AG Servers which use      */
   /*            Bluetooth Security Mode 2.                             */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Get_Server_Mode(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned long *ServerModeMask);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Get_Server_Mode_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned long *ServerModeMask);
#endif

   /* The following function is responsible for setting the HF/AG Server*/
   /* Mode for the specifed HF/AG server.  This function accepts as its */
   /* first parameter the Bluetooth Stack ID of the Bluetooth Stack on  */
   /* which the server exists.  The second parameter is the HF/AG Port  */
   /* ID that specifies the individual Server (this *MUST* be a value   */
   /* that was obtained by calling either the                           */
   /* HFRE_Open_HandsFree_Server_Port() or the                          */
   /* HFRE_Open_Audio_Gateway_Server_Port() functions).  The final      */
   /* parameter to this function is the new Server Mode to set the      */
   /* Server to use.  This function returns zero if successful, or a    */
   /* negative return error code if an error occurred.                  */
   /* ** NOTE ** The Default Server Mode is                             */
   /*               HFRE_SERVER_MODE_AUTOMATIC_ACCEPT_CONNECTION.       */
   /* ** NOTE ** This function is used for HF/AG Servers which use      */
   /*            Bluetooth Security Mode 2.                             */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Set_Server_Mode(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned long ServerModeMask);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Set_Server_Mode_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned long ServerModeMask);
#endif

   /* The following function is responsible for specifying the available*/
   /* Codecs that are supported by the Handsfree Unit.  The CVSD Codec  */
   /* is supported by default.  This function may only be performed by  */
   /* an Handsfree Unit.  This function accepts as its input parameters */
   /* the Bluetooth Stack ID for which the HFRE Port ID is valid as well*/
   /* as the HFRE Port ID.  The final two parameters to this function   */
   /* are the number of Codec IDs that are being specified and a pointer*/
   /* to an array of the Codec ID that is being supported.  This        */
   /* function returns zero if successful, or a negative return error   */
   /* code if an error occurred.                                        */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Available_Codecs(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int NumberAvailableCodecs, unsigned char *CodecIDList);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Available_Codecs_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned int NumberAvailableCodecs, unsigned char *CodecIDList);
#endif

   /* The following function is responsible for selecting an available  */
   /* Codec to be used in a subsequent Audio Connection.  This function */
   /* may only be performed with a valid Service Level Connection.  When*/
   /* called by an Audio Gateway, this function requests the use of the */
   /* specified Codec.  When called by a Handsfree, this function       */
   /* acknowledges the selected Codec.  This function accepts as its    */
   /* input parameters the Bluetooth Stack ID for which the HFRE Port ID*/
   /* is valid as well as the HFRE Port ID.  The final parameter to this*/
   /* function is the Codec ID of the Codec that is being selected.     */
   /* This function returns zero if successful, or a negative return    */
   /* error code if an error occurred.                                  */
BTPSAPI_DECLARATION int BTPSAPI HFRE_Send_Select_Codec(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned char CodecID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HFRE_Send_Select_Codec_t)(unsigned int BluetoothStackID, unsigned int HFREPortID, unsigned char CodecID);
#endif

#endif
