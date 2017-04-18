/*
 *
 *		ADX Sample Program (Playing Multi-streams)
 *
 */

/***************************************************************************
 *      �C���N���[�h�t�@�C��
 *      Include file
 ***************************************************************************/

#include	"shinobi.h"
#include	"cri_adxf.h"
#include	"cri_adxt.h"
#include	"usr.h"

/***************************************************************************
 *      �萔�}�N��
 *      MACRO CONSTANT
 ***************************************************************************/

/*	The number of ADXT handles	*/
#define	NADXT		(4)

/*	�ő�`�����l����				*/
/*	The number of maximum channels	*/
#define	MAX_CH		(2)

/*	�����Đ��ő�CD�X�g���[����									*/
/*	The number of maximum CD streams playing at the same time	*/
#define	MAX_CDSTM	(NADXT)

/*	�ō��T���v�����O���g��		*/
/*	Maximum sampling frequency	*/
#define	MAX_SFREQ		(44100)

/*	�t�@�C���Đ��p���[�N�̈�̑傫��	*/
/*	Work area size of CD stream play	*/
#define	WKSIZE		(ADXT_CALC_WORK(MAX_CH, 1, MAX_CDSTM, MAX_SFREQ))

/***************************************************************************
 *      �����}�N��
 *      Process MACRO
 ***************************************************************************/

/*	�t���OON/OFF�̔��]		*/
/*	Turn over flag(ON/OFF)	*/
#define NOT_FLAG(flag)		(((flag) == OFF) ? ON : OFF)

/***************************************************************************
 *      �ϐ���`
 *		Variable Declaration
 ***************************************************************************/
/*	�A�v���P�[�V�����\����											*/
/*	Application structure											*/
typedef struct {
	Sint32	term_flag;				//	Application terminate flag
	Sint32	disp_flag;				//	Display information flag
	Sint32	pause_flag;				//	Pause flag
	ADXT	adxt[NADXT];			//	ADXT handle
	char	*fname[NADXT];			//	File name
	char	work[NADXT][WKSIZE];	//	Work area
} AP_OBJ, *AP;

/*	�A�v���P�[�V�����I�u�W�F�N�g									*/
/*	Application Object												*/
AP_OBJ ap_obj = {
	OFF,						//	Execute App.
	ON,							//	Display Info.
	OFF,						//	not puase
	NULL, NULL, NULL, NULL,		//	ADXT handle
	"music4.adx","ambi.adx","ambi2.adx","speech.adx",
};

/***************************************************************************
 *      �֐���`
 *      Function Declaration
 ***************************************************************************/

/***
 *			�T���v���v���O����
 *			Sample program
 ***/

/*	GD�t�@�C���V�X�e���̃G���[�������ɋN������֐�			*/
/*	Callback function when an error occur in GD file system	*/
void ApGdErrFunc(void *obj, Sint32 errcode)
{
	AP ap = (AP)obj;
	
	if (errcode == GDD_ERR_TRAYOPEND || errcode == GDD_ERR_UNITATTENT)
		ap->term_flag = ON;			/*	�A�v���P�[�V�����̏I��		*/
									/*	Terminate application		*/
}

/*	ADXT�G���[�������ɋN������֐�					*/
/*	Callback function when an error occur in ADXT	*/
void ap_adx_err_func(void *obj, char *msg)
{
	/*	
	 *	ADX�ŁA�G���[����������Ƃ��̊֐����Ăяo����܂��B
	 *	msg �ɃG���[���b�Z�[�W���n����܂��B
	 *	msg�́AR5���W�X�^�Ɋi�[����Ă���̂ŁAR5���W�X�^�̃A�h���X��
	 *	�_���v���邱�Ƃɂ���ăG���[���b�Z�[�W��m�邱�Ƃ��ł��܂��B
	 *	���̊֐��́AV-Sync���荞�݂���Ăяo����邱�Ƃ�����܂��̂ŁA
	 *	Ninja�̊֐��͎g�p���Ȃ��ł��������B
	 *	�܂��A�A�v���P�[�V�����������[�X����Ƃ��́A���������ɖ߂�悤��
 	 *	�֐��ɂ��Ă��������B
	 *	This function call when error occur in ADX library.
	 *	Error message is put into 'msg' variable.
	 *	'msg' house R5 register. You can look error message in address of 
	 *	R5 register.
	 *	You cannot call Ninja function because this function is called 
	 *	from V-Int.
	 *	You must change this to no operation function when you release 
	 *	the application.
	 */

	for (;;);		/*	�����[�X���ɂ͖�����					*/
					/*	Delete when you release application.	*/
}

/*	�~�h���E�F�A�̏�����				*/
/*	Initialize Middleware				*/
void ApInitMw(AP ap)
{
	/*	ADX���C�u����������		*/
	/*	Initialize ADX library	*/
	ADXT_Init();
	
	/*	�G���[�R�[���o�b�N�֐��̓o�^		*/
	/*	Entry ADX error callback function	*/
	ADXT_EntryErrFunc(ap_adx_err_func, NULL);
}

/*	�A�v���P�[�V�����J�n����	*/
/*	Start application		*/
void ApStart(AP ap)
{
	long	i;

	/*	ADXT �n���h���̐���	*/
	/*	Create ADXT handle	*/
	for (i=0; i<NADXT; i++)
		if ( (ap->adxt[i]=ADXT_Create(2, ap->work[i], WKSIZE)) == NULL )
			for (;;);
	
	/*	�Đ��J�n		*/
	/*	Start to play	*/
	for (i=0; i<NADXT; i++)
		ADXT_StartFname(ap->adxt[i], ap->fname[i]);
}

/*	�A�v���P�[�V������~����	*/
/*	Stop application		*/
void ApStop(AP ap)
{
	long	i;

	/*	ADXT �n���h���̏���	*/
	/*	Destroy ADXT handle	*/
	for (i=0; i<NADXT; i++) {
		ADXT_Destroy(ap->adxt[i]);
		ap->adxt[i] = NULL;
	}
}

/*	���̕\��			*/
/*	Display infomation	*/
void ap_disp_info(AP ap)
{
	char *ststr[6] =
		{"STOP   ", "DECINFO", "PREP   ", "PLAYING", "DECEND ", "PLAYEND"};
	long		stat, sfreq, cnt, td, i, vol;
	long		hh, mm, ss, ff;
	extern long	adxt_svrcnt;

	UsrPrintf(3, 2, "ADX Sample Program");
	UsrPrintf(3, 3, "   ADX Playing Multi-Stream from GD-ROM");
	for (i=0; i<NADXT; i++) {
		stat = ADXT_GetStat(ap->adxt[i]);
		UsrPrintf(3, 5+i*2, "ADXT%2d: Stat=%s", i, ststr[stat]);
		ADXT_GetTime(ap->adxt[i], &cnt, &sfreq);
		UsrSfcnt2time(sfreq,  cnt, &hh, &mm, &ss, &ff);
		vol = ADXT_GetOutVol(ap->adxt[i]);
		UsrPrintf(24, 5+i*2, "Time=%d:%02d:%02d.%02d %s",
								hh, mm, ss, ff, (vol == 0) ? "ON  " : "MUTE");
		
	}
	td = syTmrCountToMicro(adxt_svrcnt);
	UsrPrintf(3, 15, "CPU Load = %4d (%2d p.c.)", td, td*100/16667);
}

/*	ADFX�̍Đ�			*/
/*	Playing the ADXT	*/
Sint32 ApExec(AP ap)
{
	long					i;
	const PDS_PERIPHERAL	*per;

	per = pdGetPeripheral(PDD_PORT_A0);
	if (per->press & PDD_DGT_ST) {
		ap->pause_flag = NOT_FLAG(ap->pause_flag);
		for (i=0; i<NADXT; i++)
			ADXT_Pause(ap->adxt[i], ap->pause_flag);/* �ꎞ��~����         */
													/* Release pause status */
	}
	if (per->press & PDD_DGT_TA)
		ADXT_StartFname(ap->adxt[0], ap->fname[0]);
	if (per->press & PDD_DGT_TB)
		ADXT_StartFname(ap->adxt[1], ap->fname[1]);
	if (per->press & PDD_DGT_TX)
		ADXT_StartFname(ap->adxt[2], ap->fname[2]);
	if (per->press & PDD_DGT_TY)
		ADXT_StartFname(ap->adxt[3], ap->fname[3]);

	if (per->press & PDD_DGT_KU) {
		for (i=0; i<NADXT; i++)
			ADXT_SetOutVol(ap->adxt[i], -999);
		ADXT_SetOutVol(ap->adxt[0], 0);
	}
	if (per->press & PDD_DGT_KD) {
		for (i=0; i<NADXT; i++)
			ADXT_SetOutVol(ap->adxt[i], -999);
		ADXT_SetOutVol(ap->adxt[1], 0);
	}
	if (per->press & PDD_DGT_KL) {
		for (i=0; i<NADXT; i++)
			ADXT_SetOutVol(ap->adxt[i], -999);
		ADXT_SetOutVol(ap->adxt[2], 0);
	}
	if (per->press & PDD_DGT_KR) {
		for (i=0; i<NADXT; i++)
			ADXT_SetOutVol(ap->adxt[i], -999);
		ADXT_SetOutVol(ap->adxt[3], 0);
	}
	if (per->press & PDD_DGT_TR) {
		for (i=0; i<NADXT; i++)
			ADXT_SetOutVol(ap->adxt[i], 0);
	}
	if (per->press & PDD_DGT_TL) {
		for (i=0; i<NADXT; i++)
			ADXT_Stop(ap->adxt[i]);
	}
	/*	���̕\��			*/
	/*	Display infomation	*/
	ap_disp_info(ap);
	
	return TRUE;
}

/*	�~�h���E�F�A�̏I��					*/
/*	Finalize Middleware					*/
void ApFinishMw(AP ap)
{
	ADXT_Finish();
}

/*	���[�U��V-SYNC���荞�݂ɓo�^����֐�	*/
/*	Callback function when V-sync interrupt	*/
void ApVsyncFunc(void)
{
	UsrCheckDoorOpen();
}

/***
 *		���C������
 *		MAIN
 ***/
void main(void)
{
	AP 		ap = &ap_obj;
	void	*vtxbuf;
	Sint32	mode, frame, count, latency;
	Bool	ret;

#ifdef __GNUC__
	shinobi_workaround();
#endif

	/*	�E���C�u�����ƃr�f�I�̏�����								*/
	/*	Initialize SHINOBI & Video Sysytem							*/
	vtxbuf = UsrInitVideo(&mode, &frame, &count, &latency);

	/*	GD�t�@�C���V�X�e���G���[�R�[���o�b�N�֐��̓o�^				*/
	/*	Entry callback function of GD file system error				*/
	gdFsEntryErrFuncAll((void *)ApGdErrFunc, ap);

	/*	�T�E���h�V�X�e���̏�����									*/
	/*	Initialize sound system										*/
	UsrInitSound();

	/*	V-Sync ���荞�ݏ����̓o�^									*/
	/*	Register V-Sync interrupt func								*/
	UsrSetVsyncFunc((void (*)(void))ApVsyncFunc);

	/*	�~�h���E�F�A���C�u����������								*/
	/*	Initialize middleware										*/
	ApInitMw(ap);

	/*	Frame Work	*/
	while ( ap->term_flag == OFF ) {
		ApStart(ap);
		for (;;) {
			UsrBeginDraw();
			ret = ApExec(ap);
			UsrEndDraw();
			if ( ret == FALSE || ap->term_flag == ON )
				break;
			UsrWaitVBlank();
		}
		ApStop(ap);
	}
	/*	�A�v���P�[�V�����I������	*/
	/*	Finalize application		*/
	ApFinishMw(ap);		/*	�~�h���E�F�A�̏I��					*/
							/*	Finalize Middleware					*/
	UsrFinishSound();		/*	�T�E���h�V�X�e���̏I������			*/
							/*	Finalize sound system				*/
	UsrFinishVideo();		/*	�E���C�u�����ƃr�f�I�̏I������		*/
							/*	Finalize SHINOBI & Video system		*/
	syBtExit();				/*	�V���v���v���C���փW�����v			*/
							/*	Jump to Simple player				*/
}

/* End of file */