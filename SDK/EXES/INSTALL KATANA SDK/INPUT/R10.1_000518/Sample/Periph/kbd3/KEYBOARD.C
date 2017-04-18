/********************************************************************
 *  Shinobi Library Sample
 *  Copyright (c) 1998 SEGA
 *
 *  Library : Controller Library
 *  Module  : Keyboard functions
 *  File    : keyboard.c
 *  Date    : 1999-05-27
 *  Version : 1.00
 *  Note    : This file provides a middle level keyboard interface
 *            to your application.
 ********************************************************************/

#include <shinobi.h>
#include "keyboard.h"

/*-------------------------------------------------------------------------*/
#define KBD_BUFSIZE          16 /* �L�[�R�[�h���i�[����o�b�t�@�̃T�C�Y    */
                                /* Key data buffer size                    */

#define INITIAL_REPEAT_COUNT  2 /* �L�[���s�[�g�Ԋu�̏����l(�t���[����)    */
                                /* Key repeat initial value                */
#define INITIAL_DELAY_COUNT  10 /* ���s�[�g�f�B���C�̏����l(�t���[����)    */
                                /* Repeat delay initial value              */

/*-------------------------------------------------------------------------*/
#define KTBL_NORMAL   0         /* �ʏ��Ԃ̃L�[�e�[�u���ւ̃C���f�b�N�X  */
                                /* Index to the normal state key table     */
#define KTBL_SHIFT    1         /* �V�t�g�L�[�������        �V            */
                                /* Index to the shifted state key table    */

/*-------------------------------------------------------------------------*/
extern const Uint8 KeyTbl_NormalJp[];      /* �ʏ���                     */
                                           /* Normal state key table       */
extern const Uint8 KeyTbl_ShiftJp[];       /* �V�t�g�L�[�������           */
                                           /* Shifted state key table      */

/*-------------------------------------------------------------------------*/
/* �L�[�e�[�u�� */
/* Key table    */
static const Uint8* KeyTbl[] = {
	KeyTbl_NormalJp,
	KeyTbl_ShiftJp,
};

/* �|�[�g�ԍ�����z��C���f�b�N�X�ւ̕ϊ��e�[�u��          */
/* Conversion table from port number to index of the array */
static const Sint32 KbdPort2No[] = {
	0, -1, -1, -1, -1, -1,
	1, -1, -1, -1, -1, -1,
	2, -1, -1, -1, -1, -1,
	3, -1, -1, -1, -1, -1,
};


/*-------------------------------------------------------------------------*/
static KEYBOARD KbdState[4];
static Uint16 KbdBuf[4][KBD_BUFSIZE];

/*-------------------------------------------------------------------------*/
static void KbdServerOne(HKBD hKbd);

/*-------------------------------------------------------------------------*/

/*===============================================================*/
/*      ������                                                   */
/*      Initialization                                           */
/*===============================================================*/
void KbdInit(void)
{
	pdKbdInit();

	memset(KbdState, 0, sizeof(KbdState));
	memset(KbdBuf, 0, sizeof(KbdBuf));
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �f�B���C�^�C���ƃ��s�[�g�^�C���̐ݒ�                     */
/*      Set delay and repeat time                                */
/*===============================================================*/

void KbdSetState(HKBD hKbd, Uint8 rate, Uint8 delay)
{
	hKbd->rate = rate;
	hKbd->delay = delay;
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �f�B���C�^�C���ƃ��s�[�g�^�C���̎擾                     */
/*      Get delay and repeat time                                */
/*===============================================================*/
void KbdGetState(HKBD hKbd, Uint8* rate, Uint8* delay)
{
	*rate = hKbd->rate;
	*delay = hKbd->delay;
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �L�[�e�[�u���̐ݒ�                                       */
/*      Set key table                                            */
/*===============================================================*/
void KbdSetKeyTable(HKBD hKbd, const char** keytbl)
{
	if (keytbl) {
		hKbd->keytbl = (unsigned char **) keytbl;
	} else {
		hKbd->keytbl = KeyTbl;
	}
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �L�[�o�b�t�@�Ƀf�[�^�����邩�ǂ����̃`�F�b�N             */
/*    Check whether some key datas are ready in key data buffer  */
/*===============================================================*/
Sint32 KbdIsHit(HKBD hKbd)
{
	return (hKbd->getp == hKbd->putp) ? FALSE : TRUE;
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �L�[�{�[�h���ڑ�����Ă��邩�ǂ����̃`�F�b�N             */
/*      Check whether a keyboard is connected                    */
/*===============================================================*/
Sint32 KbdIsReady(HKBD hKbd)
{
	return hKbd->ready;
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �T�[�o�֐�(�Ȃ�ׂ����荞�݂ŌĂ�ł�������)             */
/*      Server function(If possible, please call at interrupt    */
/*===============================================================*/
void KbdServer(void)
{
	Sint32 i;
	HKBD kbd;

	kbd = KbdState;
	for (i = 0; i < 4; i++, kbd++) {
		if (kbd->used) {
			KbdServerOne(kbd);
		}
	}
}

static Sint32 kbd_comp(Uint8* dst, Uint8* src)
{
	Sint32 i;

	for(i = 0; i < 6; i++, dst++, src++) {
		if (*dst != *src) return FALSE;
	}

	return TRUE;
}

static Sint32 search_predata(HKBD hKbd)
{
	Sint32 i;

	for (i = 0; i < 6; i++) {
		if (hKbd->predata == hKbd->old_data[i + 2]) return TRUE;
	}
	return FALSE;
}

/*-------------------------------------------------------------------------*/
static void KbdServerOne(HKBD hKbd)
{
	const PDS_KEYBOARD* kbd;
	const Uint8* keytbl;
	Uint8 data;
	Sint32 i;
	Sint32 input_flag;
	Sint32 shift;

	input_flag = FALSE;
	kbd = pdKbdGetData(hKbd->port);
	if (kbd == NULL) {
		hKbd->ready = 0;
		hKbd->rawdata = NULL;
		return;
	}

	hKbd->rawdata = kbd;
	hKbd->ready = 1;
	for (i = 0; i < 6; i++) {
		data = kbd->key[5 - i];
		switch (data) {
			case 0x00:
				break;
			case 0x01:
				break;
			default:
				if (((hKbd->putp + 1) & (hKbd->bufsize - 1)) == hKbd->getp) {
					/* �����O�o�b�t�@�t�� */
					return;
				}
				goto skip;
		}
	}

	hKbd->delay_count = 0;
	hKbd->repeat_flag = FALSE;
	hKbd->predata = 0;
	return;
skip:
	if (data == hKbd->predata) {
		/* ���������� */
		hKbd->delay_count++;
		if (hKbd->delay_count > hKbd->delay) {
			hKbd->repeat_flag = TRUE;
		}
	} else {
		/* ����� */
		hKbd->delay_count = 0;
		hKbd->repeat_flag = FALSE;
		input_flag = TRUE;
	}


	if (hKbd->repeat_flag) {
		hKbd->rate_count++;
		if (hKbd->rate_count >= hKbd->rate) {
			input_flag = TRUE;
			hKbd->rate_count = 0;
		}
	} else {
		hKbd->rate_count = 0;
	}
	if (input_flag) {
		Uint16 tmp;

		/* �V�t�g�L�[�̏�Ԃɂ���ăL�[�e�[�u����؂�ւ��� */
		tmp = kbd->ctrl & 0xf8;
		tmp |= (kbd->ctrl & 0x07) << 4;

		shift = (tmp & 0x20) ? 1 : 0;

		if (shift) keytbl = hKbd->keytbl[KTBL_SHIFT];
		else keytbl = hKbd->keytbl[KTBL_NORMAL];

		hKbd->buf[hKbd->putp++] = keytbl[data] | (tmp << 8);

		hKbd->putp &= (hKbd->bufsize - 1);
		hKbd->predata = data;
	}
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �L�[�{�[�h�n���h���̐���                                 */
/*      Create a keyboard handle                                 */
/*===============================================================*/
HKBD KbdCreate(Uint32 port)
{
	Sint32 no;
	HKBD kbd;

	if ((no = KbdPort2No[port]) < 0) return NULL;
	kbd = &KbdState[no];
	if (kbd->used) return NULL;

	kbd->used = TRUE;
	kbd->rate = INITIAL_REPEAT_COUNT;
	kbd->delay = INITIAL_DELAY_COUNT;
	kbd->rate_count = 0;
	kbd->delay_count = 0;
	kbd->repeat_flag = 1;
	kbd->port = port;
	kbd->putp = 0;
	kbd->getp = 0;
	kbd->bufsize = KBD_BUFSIZE;
	kbd->buf = KbdBuf[no];
	kbd->predata = 0xff;
	kbd->keytbl = KeyTbl;

	return kbd;
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �L�[�{�[�h�n���h���̍폜                                 */
/*      Delete a keyboard handle                                 */
/*===============================================================*/
void KbdDestroy(HKBD kbd)
{
	kbd->used = FALSE;
}



/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �L�[�R�[�h�̎擾                                         */
/*      Get a key code                                           */
/*===============================================================*/
Uint16 KbdGetChar(HKBD hKbd)
{
	Uint16 data;

	if (hKbd->getp == hKbd->putp) {
		/* �����O�o�b�t�@�G���v�e�B */
		return 0;
	}

	data = hKbd->buf[hKbd->getp++];
	hKbd->getp &= hKbd->bufsize - 1;

	return data;
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �჌�x���L�[�f�[�^�̎擾                                 */
/*      Get low level keyboard data                              */
/*===============================================================*/
const PDS_KEYBOARD* KbdGetRawData(HKBD hKbd)
{
	return hKbd->rawdata;
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �L�[�o�b�t�@�̃t���b�V��                                 */
/*      Flush the key buffer                                     */
/*===============================================================*/
void KbdFlush(HKBD kbd)
{
	kbd->putp = 0;
	kbd->getp = 0;
}

/*-------------------------------------------------------------------------*/
/*===============================================================*/
/*      �I��                                                     */
/*      Finalization                                             */
/*===============================================================*/
void KbdExit(void)
{
	pdKbdExit();

	memset(KbdState, 0, sizeof(KbdState));
	memset(KbdBuf, 0, sizeof(KbdBuf));
}


/*-------------------------------------------------------------------------*/
