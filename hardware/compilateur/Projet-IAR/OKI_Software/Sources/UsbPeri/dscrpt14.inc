/*******************************************************************************
    dscrpt14.inc
    JOB60842�T���v���v���O���� 
    �f�B�X�N���v�^��`(Bulk In/Out and Interrupt)

    Copyright(C) 2003, Oki Electric Industry Co.,Ltd.
      All rights reserved.

    �X�V����
    Mar.31,2003 rev1.00:�V�K�쐬
*******************************************************************************/

#if defined(OTG_ENABLE)
static OTG_Desc Otg_Desc = {
	3,
	OTG,
	(USBP_HNP_SUPPORT|USBP_SRP_SUPPORT)
};
#endif
#define	NUM_ENDPOINT	5
/* BULK In/Out and Interrupt */

/*	=======================================================
	1.	Endpoint Descriptor
	=======================================================
*/
static Endpoint_Desc EP_desc[NUM_ENDPOINT] = {
	{ /*EP1*/
		/*fix*/	7,			/* 1: bLength : �f�B�X�N���v�^�� */
		/*fix*/	ENDPOINT,	/* 2: bDescriptorType : �f�B�X�N���v�^�^�C�v */
		EPA_WITH_DIR,		/* 3: bEndpointAddress:�G���h�|�C���g�A�h���X����ѓ]������ */
		BULK,				/* 4: bmAttributes : �G���h�|�C���g���� */
		WordSet(EPA_PLD),	/* 5: wMaxPacketSize : �ő�p�P�b�g�T�C�Y */
		0,					/* 6: bInterval : �|�[�����O�Ԋu */
	},
	{ /*EP2*/
		/*fix*/	7,			/* 1: bLength : �f�B�X�N���v�^�� */
		/*fix*/	ENDPOINT,	/* 2: bDescriptorType : �f�B�X�N���v�^�^�C�v */
		EPB_WITH_DIR,		/* 3: bEndpointAddress:�G���h�|�C���g�A�h���X����ѓ]������ */
		BULK,				/* 4: bmAttributes : �G���h�|�C���g���� */
		WordSet(EPB_PLD),	/* 5: wMaxPacketSize : �ő�p�P�b�g�T�C�Y */
		0,					/* 6: bInterval : �|�[�����O�Ԋu */
	},
	{ /*EP3*/
		/*fix*/	7,			/* 1: bLength : �f�B�X�N���v�^�� */
		/*fix*/	ENDPOINT,	/* 2: bDescriptorType : �f�B�X�N���v�^�^�C�v */
		EPINT_WITH_DIR,		/* 3: bEndpointAddress:�G���h�|�C���g�A�h���X����ѓ]������ */
#if defined(USBP_USB_CHECK)
		BULK,				/* 4: bmAttributes : �G���h�|�C���g���� */
#else
		INTERRUPT,			/* 4: bmAttributes : �G���h�|�C���g���� */
#endif
		WordSet(EPINT_PLD),	/* 5: wMaxPacketSize : �ő�p�P�b�g�T�C�Y */
		EP_INT_INTERVAL,	/* 6: bInterval : �|�[�����O�Ԋu */
	},
	{ /*EP4*/
		/*fix*/	7,			/* 1: bLength : �f�B�X�N���v�^�� */
		/*fix*/	ENDPOINT,	/* 2: bDescriptorType : �f�B�X�N���v�^�^�C�v */
		EPC_WITH_DIR,		/* 3: bEndpointAddress:�G���h�|�C���g�A�h���X����ѓ]������ */
		BULK,				/* 4: bmAttributes : �G���h�|�C���g���� */
		WordSet(EPC_PLD),	/* 5: wMaxPacketSize : �ő�p�P�b�g�T�C�Y */
		0,					/* 6: bInterval : �|�[�����O�Ԋu */
	},
	{ /*EP5*/
		/*fix*/	7,			/* 1: bLength : �f�B�X�N���v�^�� */
		/*fix*/	ENDPOINT,	/* 2: bDescriptorType : �f�B�X�N���v�^�^�C�v */
		EPD_WITH_DIR,		/* 3: bEndpointAddress:�G���h�|�C���g�A�h���X����ѓ]������ */
		BULK,				/* 4: bmAttributes : �G���h�|�C���g���� */
		WordSet(EPD_PLD),	/* 5: wMaxPacketSize : �ő�p�P�b�g�T�C�Y */
		0,					/* 6: bInterval : �|�[�����O�Ԋu */
	},
};

/*	=======================================================
	4.	Interface Descriptor
	=======================================================
*/
static Interface_Desc IF_desc0[1] = {
	{ /*Bulk In/Out, Interrupt In*/
		/*fix*/	9,			/* 1: bLength : �f�B�X�N���v�^�� */
		/*fix*/	INTERFACE,	/* 2: bDescriptor : �f�B�X�N���v�^�^�C�v */
		0,					/* 3: bInterfacesNumber : InterfaceNumber */
		0,					/* 4: bAlternateSetting : 0����V���A���ɕt���� */
		NUM_ENDPOINT,		/* 5: bNumEndpoints : �G���h�|�C���g�� */
		0xFF,				/* 6: bInterfaceClass : �N���X�R�[�h (by USB) */
		0xFF,				/* 7: bInterfaceSubClass : �T�u�N���X�R�[�h (by USB) */
		0xFF,				/* 8: bInterfaceProtocol : �v���g�R���R�[�h (by USB) */
		4,					/* 9: iInterface : StringDescriptor�̃C���f�b�N�X */
		&EP_desc[0],		/* Endpoint Descriptor�ւ̃|�C���^ */
	},
};
#undef	NUM_ENDPOINT
/*	=======================================================
	5.	Config to Interface Bridge / Config_if
	=======================================================
*/
/*
	Configuration Descriptor������Interface Descriptor�̎��
	����bInterfaceNumber�ňႤbAlternateSetting�l������
	InterfaceDescriptor���ݒ�ł��邽�߁C���̍\���̂Œ����
*/
#define	NUM_INTERFACE	1

static Config_if CFG_if[NUM_INTERFACE] = {
	{ /*Interface#0*/
		0,					/* 1: bInterfaceNumber */
		1,					/* 2: AlternateSetting�� */
		0,					/* 3: ���݂̑�֐ݒ�l�i�ϐ��j */
		&IF_desc0[0],		/* InteraceDescriptor�ւ̃|�C���^ */
#if defined(OTG_ENABLE)
		&Otg_Desc,
#endif
	},
};

/*	=======================================================
	6.	Configuration Descrptor
	=======================================================
*/
#define	NUM_CONFIG	1

static Config_Desc CFG_desc[NUM_CONFIG] = {
	{
		/*fix*/	9,				/* 1: bLength : �f�B�X�N���v�^�� */
		/*fix*/	CONFIGURATION,	/* 2: bDescriptor : �f�B�X�N���v�^�^�C�v */
		WordSet(39+3+14),		/* 3: wTotalLength:�SDescriptor��(Config+Interface+Endpoint)*/
		NUM_INTERFACE,			/* 4: bNumInterfaces : Interface�� */
		1,						/* 5: bConfigurationValue :�ݒ�I��l(1����V���A���ɂ���)*/
		3,						/* 6: iConfiguration : StringDescriptor�̃C���f�b�N�X */
		0xc0,					/* 7: bmAttributes : �\���̓��� */
		50, /*100mA*/			/* 8: MaxPower : �d�͏���� */
		&CFG_if[0],				/* Configuration to Interface Bridge�ւ̃|�C���^ */
	},
};

#undef	NUM_INTERFACE

/*	=======================================================
	7.	Device Descrptor
	=======================================================
*/
Device_Desc device_descriptor1 = {
		/*fix*/	18,			/* 1:  bLength : �f�B�X�N���v�^�� */
		/*fix*/	DEVICE,		/* 2:  bDescriptor : �f�B�X�N���v�^�^�C�v */
#if defined(USBP_USB_CHECK)
		WordSet(0x110),		/* 3:  bcdUSB : USB�d�l�����[�X�ԍ� */
#else
		WordSet(0x200),		/* 3:  bcdUSB : USB�d�l�����[�X�ԍ� */
#endif
		0,					/* 4:  bDeviceClass : �N���X�R�[�h (by USB) */
		0,					/* 5:  bDeviceSubClass : �T�u�N���X�R�[�h (by USB) */
		0,					/* 6:  bDeviceProtocol : �v���g�R���R�[�h (by USB) */
		32,					/* 7:  bMaxPacketSize0 : EP0��MaxPacketSize*/
		WordSet(VID),		/* 8:  idVender : �x���_ID (by USB) */
		WordSet(PID),		/* 9:  idProduct : �v���_�N�gID (by ������) */
		WordSet(0x100),		/* 10: bcdDevice : �f�o�C�X�E�����[�X�ԍ� */
		1,					/* 11: iManufacturer:�����҂�\��StringDescriptorIndex*/
		2,					/* 12: iProduct : ���i��\��SrtingDescriptor�̃C���f�b�N�X */
		0,					/* 13: iSerialNumber : �f�o�C�X���i�ԍ���\��StringDescriptorIndex */
		NUM_CONFIG,			/* 14: bNumConfiguration : ConfigurationDescriptor�� */
		&CFG_desc[0],		/* Configuration Descriptor�ւ̃|�C���^ */
};

#undef	NUM_CONFIG

const ushort	Language_ID[1] = {0x409};
const ushort	Manufacturer_String[4] = {'O','K','I',' '};
const ushort	Product_String[9] = {'J','O','B','-','6','0','8','4','2'};
const ushort	Config_String[14] = {'B','u','l','k','&','I','n','t','e','r','r','u','p','t'};
const ushort	If_String[13] = {'B','u','l','k','-','L','o','o','p','B','a','c','k'};

String_Desc string_desc[5]=
{
	{
		4,
		STRING,
		(ushort *)Language_ID
	},
	{
		10,
		STRING,
		(ushort *)Manufacturer_String
	},
	{
		20,
		STRING,
		(ushort *)Product_String
	},
	{
		30,
		STRING,
		(ushort *)Config_String
	},
	{
		28,
		STRING,
		(ushort *)If_String
	},

};

/* end of descriptor include file */