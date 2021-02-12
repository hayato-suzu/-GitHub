/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
//���y�̍Đ�
//�v���W�F�N�g������MUSIC�t�H���_���쐬
//�Đ����������y�t�@�C�����AMUSIC�t�H���_�ɓ����

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"

//########## �}�N����` ##########
#define GAME_WIDTH			800	//��ʂ̉��̑傫��
#define GAME_HEIGHT			600	//��ʂ̏c�̑傫��
#define GAME_COLOR			32	//��ʂ̃J���[�r�b�g

#define GAME_WINDOW_BAR		0	//�^�C�g���o�[�̓f�t�H���g�ɂ���
#define GAME_WINDOW_NAME	"�W�c�����N�@�N���x"	//�E�B���h�E�̃^�C�g��

#define GAME_FPS			60	//FPS�̐��l	

//�}�E�X�̃{�^��
#define MOUSE_BUTTON_CODE	129		//0x0000�`0x0080�܂�

//�p�X�̒���
#define PATH_MAX			255	//255�����܂�
#define NAME_MAX			255	//255�����܂�

//�t�H���g
#define FONT_TANU_PATH			TEXT(".\\FONT\\azukiP.ttf")	//�t�H���g�̏ꏊ
#define FONT_TANU_NAME			TEXT("�������t�H���gP")			//�t�H���g�̖��O


//�G���[���b�Z�[�W
#define FONT_INSTALL_ERR_TITLE	TEXT("�t�H���g�C���X�g�[���G���[")
#define FONT_CREATE_ERR_TITLE	TEXT("�t�H���g�쐬�G���[")

//�G���[���b�Z�[�W
#define IMAGE_LOAD_ERR_TITLE	TEXT("�摜�ǂݍ��݃G���[")

//�摜�̃p�X================================================================================
#define IMAGE_BACK_PATH			TEXT(".\\IMAGE\\bg\\play.png")	       //�v���C�w�i�̉摜
#define IMAGE_TITLE_PATH        TEXT(".\\IMAGE\\bg\\title.png")        //�^�C�g���̔w�i
#define IMAGE_CHOICE_PATH       TEXT(".\\IMAGE\\bg\\choice.png")       //�I����ʂ̔w�i
#define IMAGE_RUSULT_PATH       TEXT(".\\IMAGE\\bg\\rusult.png")       //���U���g�w�i
#define IMAGE_END_PATH          TEXT(".\\IMAGE\\bg\\end.png")          //�G���h�w�i

//�^�C�g�����S�A�I��p�̉摜2.10
#define IMAGE_TITLE_ROGO_PATH   TEXT(".\\IMAGE\\title_rogo.png")  //�^�C�g�����S
#define IMAGE_TITLE_START_PATH  TEXT(".\\IMAGE\\title_start.png")//"�n�߂�"�̉摜
#define IMAGE_TITLE_OWARI_PATH  TEXT(".\\IMAGE\\title_owari.png")//"�����"�̉摜
#define IMAGE_CHOICE_KEN1_PATH  TEXT(".\\IMAGE\\choice_ken.png")//�I���̌��L����1�̉摜
#define IMAGE_CHOICE_KEN2_PATH  TEXT(".\\IMAGE\\choice_ken2.png")//�I���̌��L�����Q�̉摜
#define IMAGE_CHOICE_KOBU1_PATH TEXT(".\\IMAGE\\choice_kobu1.png")//�I���̌��L�����P�̉摜
//#define IMAGE_CHOICE_KOBU2_PATH TEXT



//�G���[���b�Z�[�W
#define MUSIC_LOAD_ERR_TITLE	TEXT("���y�ǂݍ��݃G���[")

//���y�̃p�X================================================================================
#define MUSIC_BGM_PATH			     TEXT(".\\MUSIC\\play.mp3")                 	//�v���CBGM
#define MUSIC_PLAYER_SHOT_PATH	     TEXT(".\\MUSIC\\�V���b�g��.mp3")				//�V���b�g��
#define MUSIC_RUEULT_BGM_PATH        TEXT(".\\MUSIC\\rusult.mp3")               //���U���g��ʂ�BGM
#define MUSIC_TITLE_BGM_PATH         TEXT(".\\MUSIC\\title.mp3")                    //�^�C�g��BGM
#define MUSIC_CHOICE_BGM_PATH        TEXT(".\\MUSIC\\choice.mp3")                   //�I��BGM
#define MUSIC_END_BGM_PATH           TEXT(".\\MUSIC\\end.mp3")                      //�G���hBGM

//===========================================================================================

//�L�����N�^�[�̐ݒ�A�����A�p�X----------2.4
#define IMAGE_PLAYER1_PATH		".\\IMAGE\\player\\player1.png"	   //�v���C���[1�̉摜
#define IMAGE_PLAYER2_PATH      ".\\IMAGE\\player\\player2.png"    //�v���C���[�Q�̉摜
#define IMAGE_PLAYER3_PATH      ".\\IMAGE\\player\\player3.png"    //�v���C���[�R�̉摜
#define IMAGE_PLAYER4_PATH      ".\\IMAGE\\player\\player4.png"    //�v���C���[�S�̉摜
#define PLAYER_TATE_DIV		4	//�v���C���[�̏c�ɕ������鐔
#define PLAYER_YOKO_DIV		3	//�v���C���[�̏c�ɕ������鐔
#define PLAYER_WIDTH		32  //�v���C���̉摜�𕪊����镝�̃T�C�Y
#define PLAYER_HEIGHT		32  //�v���C���̉摜�𕪊����鍂���̃T�C�Y
//----------------------------------------2.4
//�}�b�v=====================================================================================
#define GAME_MAP_TATE_MAX	10	//�}�b�v�̏c�̐�
#define GAME_MAP_YOKO_MAX	13	//�}�b�v�̉��̐�
#define GAME_MAP_KIND_MAX	2	//�}�b�v�̎�ނ̐�

#define GAME_MAP_PATH			TEXT(".\\IMAGE\\MAP\\map1.png")		//�}�b�v�̉摜

#define MAP_DIV_WIDTH		64	//�摜�𕪊����镝�T�C�Y
#define MAP_DIV_HEIGHT		64	//�摜�𕪊����鍂���T�C�Y
#define MAP_DIV_TATE		10	//�摜���c�ɕ������鐔
#define MAP_DIV_YOKO		4	//�摜�����ɕ������鐔
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO	//�摜�𕪊����鑍��

//�e�̐ݒ�----------------------------------------------------��
#define TAMA_CHANGE_MAX      5  //5�t���[���ڂŒe�̉摜��ς���
#define TAMA_MAX            16  //�ő�16���܂�

#define TAMA_RED_PATH       TEXT(".\\IMAGE\\TAMA\\red.png")  //�Ԓe�̉摜

#define TAMA_DIV_WIDTH      16  //�摜�𕪊����镝�T�C�Y
#define TAMA_DIV_HEIGHT     16  //�摜�𕪊����鍂���T�C�Y

#define TAMA_DIV_TATE        3  //�摜���c�ɕ������鐔
#define TAMA_DIV_YOKO        1  //�摜�����ɕ������鐔

#define TAMA_DIV_NUM     TAMA_DIV_TATE*TAMA_DIV_YOKO  //�摜�𕪊����鑍��
//----------------------------------------------------------��

//�G���[���b�Z�[�W
#define START_ERR_TITLE		TEXT("�X�^�[�g�ʒu�G���[")
#define START_ERR_CAPTION	TEXT("�X�^�[�g�ʒu�����܂��Ă��܂���")

//�I���_�C�A���O�p---------------------------------------

#define MOUSE_ERR_CLICK_TITLE     TEXT("�X�^�[�g�ʒu�G���[")
#define MOUSE_ERR_CLICK_CAPTION   TEXT("�X�^�[�g�ʒu�����܂��Ă��܂���")


//�I���_�C�A���O�p----------��
#define MOUSE_R_CLICK_TITLE       TEXT("�Q�[�����f")
#define MOUSE_R_CLICK_CAPTION     TEXT("�Q�[���𒆒f���A�^�C�g����ʂɖ߂�܂����H")
//-------------------------------------------------------��

enum GAME_MAP_KIND
{
	n = -1,
	k = 0,//�u���b�N
	y = 1,//��
	t = 9,//��
	s = 5,//�X�^�[�g
	g = 9,//�S�[��

};//�}�b�v�̎��
//===========================================================================================

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_CHOICE,
	GAME_SCENE_PLAY,
	GAME_SCENE_RUSULT,
	GAME_SCENE_END,
};	//�Q�[���̃V�[��

enum CHARA_SPEED {
	CHARA_SPEED_LOW = 1,
	CHARA_SPEED_MIDI = 2,
	CHARA_SPEED_HIGH = 3
};	//�L�����N�^�[�̃X�s�[�h


enum CHARA_RELOAD {
	CHARA_RELOAD_LOW = 60,
	CHARA_RELOAD_MIDI = 30,
	CHARA_RELOAD_HIGH = 15
};	//�L�����N�^�[�̃����[�h


//int�^��POINT�\����
typedef struct STRUCT_I_POINT
{
	int x = -1;	//���W��������
	int y = -1;	//���W��������
}iPOINT;

//�}�E�X�\����
typedef struct STRUCT_MOUSE
{
	int InputValue = 0;	//GetMouseInput�̒l������
	int WheelValue = 0;	//�}�E�X�z�C�[���̉�]��(���̓v���X�l / ��O�̓}�C�i�X�l)
	iPOINT Point;		//�}�E�X�̍��W������
	iPOINT OldPoint;	//�}�E�X�̍��W(���O)������
	int OldButton[MOUSE_BUTTON_CODE] = { 0 };	//�}�E�X�̃{�^������(���O)������
	int Button[MOUSE_BUTTON_CODE] = { 0 };	//�}�E�X�̃{�^�����͂�����
}MOUSE;

//�t�H���g�\����
typedef struct STRUCT_FONT
{
	char path[PATH_MAX];		//�p�X
	char name[NAME_MAX];		//�t�H���g��
	int handle;					//�n���h��
	int size;					//�傫��
	int bold;					//����
	int type;					//�^�C�v
	//���^�C�v�́Ahttps://dxlib.xsrv.jp/function/dxfunc_graph2.html#R17N10�@���Q��

}FONT;

typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];		//�p�X
	int handle;					//�n���h��
	int x;						//X�ʒu
	int y;						//Y�ʒu
	int width;					//��
	int height;					//����
}IMAGE;	//�摜�\����

typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//�p�X
	int handle;					//�n���h��
}MUSIC;	//���y�\����

//�e--------------��
typedef struct STRUCT_TAMA
{
	char path[PATH_MAX];
	int handle[TAMA_DIV_NUM];
	int x;
	int y;
	int width;
	int height;
	BOOL IsDraw;
	int nowImageKind;
	int changeImageCnt;
	int changeImageCntMAX;
	int speed;
}TAMA;//�e�̍\����
//-----------------��

typedef struct STRUCT_PLAYER
{
	char path[PATH_MAX];         //�p�X
	int handle[PLAYER_TATE_DIV * PLAYER_YOKO_DIV];//�n���h��
	int X;				    //���SX
	int Y;				    //���SY
	int width;			    //��
	int height;			    //����

	RECT coll;              //�����蔻��

	int imagekind;			//�摜�̎�ނ��Ǘ�

	int imageChangeCnt;     //�摜��ς���^�C�~���O�̃J�E���^
	int imageChangeCntMAX;	//�摜��ς���^�C�~���O�̃J�E���^MAX

	BOOL IsJump;			//�W�����v���Ă��邩
	int  JumpTimeCut;		//�W�����v���Ă��鎞��
	int BeforeJump;			//�W�����v���钼�O��Y�ʒu
	int JumpPower;			//�W�����v��

	int speed;					//����
	MUSIC musicShot;			//�v���C���[�̔��ˉ�
	BOOL CanShot;				//�V���b�g�ł��邩
	int ShotReLoadCnt;			//�V���b�g�����[�h����
	int ShotReLoadCntMAX;		//�V���b�g�����[�h����(MAX)
	TAMA tama[TAMA_MAX];         //�V���b�g����e

	
}PLAYER;	//�L�����N�^�[�\����

//�}�b�v�p�X
typedef struct STRUCT_MAP_IMAGE
{
	char path[PATH_MAX];				//�p�X
	int handle[MAP_DIV_NUM];			//���������̒e�̉摜�n���h�����擾
	int kind[MAP_DIV_NUM];				//�}�b�v�̎��
	int width;							//��
	int height;							//����

}MAPCHIP;	//MAP_IMAGE�\����

typedef struct STRUCT_MAP
{
	GAME_MAP_KIND kind;			//�}�b�v�̎��
	int x;						//X�ʒu
	int y;						//Y�ʒu
	int width;					//��
	int height;					//����

}MAP;	//MAP�\����
//=============================================================================

//########## �O���[�o���ϐ� ##########
//FPS�֘A
int StartTimeFps;				//����J�n����
int CountFps;					//�J�E���^
float CalcFps;					//�v�Z����
int SampleNumFps = GAME_FPS;	//���ς����T���v����

//�L�[�{�[�h�̓��͂��擾
char AllKeyState[256] = { '\0' };			//���ׂẴL�[�̏�Ԃ�����
char OldAllKeyState[256] = { '\0' };	//���ׂẴL�[�̏��(���O)������

//�}�E�X�̍��W���擾
MOUSE mouse;

FONT FontTanu32;	//���ʂ������}�W�b�N�F�傫��32�@�̃t�H���g�\����

int GameScene;		//�Q�[���V�[�����Ǘ�

//�摜�֘A===================================================================
IMAGE ImageBack;	//�Q�[���̔w�i
IMAGE ImageTitle;   //�^�C�g���w�i
IMAGE ImageChoice;  //�I����ʂ̔w�i

IMAGE ImagePlay;    //�v���C��ʂ̔w�i
IMAGE ImageRusult;  //���U���g�w�i
IMAGE ImageEnd;     //�G���h�w�i
//------------------------2.4
IMAGE ImageTitleROGO;
PLAYER player1;      //�L�����P�̍\����
PLAYER player2;		 //�L�����Q�̍\����
PLAYER player3;      //�L�����R�̍\����
PLAYER player4;      //�L�����S�̍\����
PLAYER CHOICE_PLAYER1;//�v���C���[�P���I��ł���\����
PLAYER CHOICE_PLAYER2;//�v���C���[�Q���I��ł���\����
#define GAME_GR     4  //�Q�[���̏d��
#define PLAYER1_CHARA_X 0//�v���C��1��x�����ʒu
#define PLAYER1_CHARA_Y 0//�v���C��1��y�����ʒu
#define PLAYER2_CHARA_X 750//�v���C���Q��x�����ʒu
#define PLAYER2_CHARA_Y 0//�v���C���Q��y�����ʒu
BOOL IsMAP_JUMP(VOID);//�n�ʂ̓����蔻��L�����P
BOOL IsMAP_JUMP2(VOID);//�n�ʂ̓����蔻��L�����Q
//-------------------------------------------------
//=============================================================================



//���y�֘A �p�X�p=================================
MUSIC BGM;			//�Q�[����BGM

MUSIC BGM_TITLE;    //�^�C�g����BGM
MUSIC BGM_CHOICE;   //�I����ʂ�BGM
MUSIC BGM_PLAY;     //�v���C��ʂ�BGM
MUSIC BGM_RUSULT;   //���U���g��ʂ�BGM
MUSIC BGM_END;      //�G���h��ʂ�BGM

//================================================

//�}�b�v�̔z�u--------------------------------------
GAME_MAP_KIND mapData[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX]{
	//  0,1,2,3,4,5,6,7,8,9,0,1,2,
		t,t,t,t,t,t,t,t,t,t,t,t,t,	// 0
		t,t,t,t,t,t,t,t,t,t,t,t,t,	// 1
		t,t,t,t,t,t,t,t,t,t,t,t,t,	// 2
		t,t,t,t,t,t,t,t,t,t,t,t,t,	// 3
		t,t,t,t,t,t,t,t,t,t,t,t,t,	// 4
		t,t,t,t,t,t,t,t,t,t,t,t,t,	// 5
		t,t,t,t,t,t,t,t,t,t,t,t,t,	// 6
		y,y,y,y,y,y,y,y,y,y,y,y,y,	// 7
		k,k,k,k,k,k,k,k,k,k,k,k,k,	// 8
		k,k,k,k,k,k,k,k,k,k,k,k,k,  // 9
};	//�Q�[���̃}�b�v

//�Q�[���}�b�v�̏�����
GAME_MAP_KIND mapDataInit[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//�}�b�v�`�b�v�̉摜���Ǘ�
MAPCHIP mapChip;

//�}�b�v�̏ꏊ���Ǘ�
MAP map[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//�X�^�[�g�̈ʒu
iPOINT startPt{ -1,-1 };

//�}�b�v�̓����蔻��--------------��
RECT mapColl[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];
//----------------------------------��
//=======================================================================

//########## �v���g�^�C�v�錾 ##########
VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����
VOID MY_FPS_DRAW(VOID);				//FPS�l��`�悷��
VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����A�҂�

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����
BOOL MY_KEY_DOWN(int);				//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEY_UP(int);				//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����
BOOL MY_KEYDOWN_KEEP(int, int);		//�L�[�����������Ă��邩�A�L�[�R�[�h�Ŕ��f����

VOID MY_MOUSE_UPDATE(VOID);			//�}�E�X�̓��͏����X�V����
BOOL MY_MOUSE_DOWN(int);			//�{�^���������Ă��邩�A�}�E�X�R�[�h�Ŕ��f����
BOOL MY_MOUSE_UP(int);				//�{�^���������グ�����A�}�E�X�R�[�h�Ŕ��f����
BOOL MY_MOUSEDOWN_KEEP(int, int);	//�{�^�������������Ă��邩�A�}�E�X�R�[�h�Ŕ��f����

BOOL MY_FONT_INSTALL_ONCE(VOID);	//�t�H���g�����̃\�t�g�p�ɁA�ꎞ�I�ɃC���X�g�[��
VOID MY_FONT_UNINSTALL_ONCE(VOID);	//�t�H���g�����̃\�t�g�p�ɁA�ꎞ�I�ɃA���C���X�g�[��
BOOL MY_FONT_CREATE(VOID);			//�t�H���g���쐬����
VOID MY_FONT_DELETE(VOID);			//�t�H���g���폜����

VOID MY_START(VOID);		//�X�^�[�g���
VOID MY_START_PROC(VOID);	//�X�^�[�g��ʂ̏���
VOID MY_START_DRAW(VOID);	//�X�^�[�g��ʂ̕`��

VOID MY_CHOICE(VOID);       //�I�����
VOID MY_CHOICE_PROC(VOID);  //�I����ʂ̏���
VOID MY_CHOICE_DRAW(VOID);  //�I����ʂ̕`��

VOID MY_PLAY(VOID);			//�v���C���
VOID MY_PLAY_PROC(VOID);	//�v���C��ʂ̏���
VOID MY_PLAY_DRAW(VOID);	//�v���C��ʂ̕`��

VOID MY_RUSULT(VOID);       //���U���g���
VOID MY_RUSULT_PROC(VOID);  //���U���g��ʂ̏���
VOID MY_RUSULT_DRAW(VOID);  //���U���g��ʂ̕`��

VOID MY_END(VOID);			//�G���h���
VOID MY_END_PROC(VOID);		//�G���h��ʂ̏���
VOID MY_END_DRAW(VOID);		//�G���h��ʂ̕`��

VOID MY_MENYU(VOID);        //���j���[���
VOID MY_MENYU_PROC(VOID);   //���j���[��ʂ̏���
VOID MY_MENYU_DRAW(VOID);   //���j���[��ʂ̕`��

BOOL MY_LOAD_IMAGE(VOID);		//�摜���܂Ƃ߂ēǂݍ��ފ֐�
VOID MY_DELETE_IMAGE(VOID);		//�摜���܂Ƃ߂č폜����֐�


BOOL MY_LOAD_MUSIC(VOID);		//���y���܂Ƃ߂ēǂݍ��ފ֐�
VOID MY_DELETE_MUSIC(VOID);		//���y���܂Ƃ߂č폜����֐�

BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT); //�}�b�v�ƃv���C���[�̓����蔻�������֐�
BOOL MY_CHECK_RECT_COLL(RECT, RECT);  //�̈�̓����蔻�������֐�


//�X�^�[�g��ʂ̕����̈ʒu---------------------1.27
const static int Play_y = 240;  //�u�Q�[���X�^�[�g�v���̈ʒu
const static int Exit_y = 270;  //�uEXIT�v�̂��̈ʒu

typedef enum {      //�X�^�[�g��ʑI��g
	Start_Coice,    //���̉�ʂ�
	Start_Exit,     //EXIT

	Start_Num,      //���ڂ̐�
};

int S_coice_y = 0;    //�I�����̂��̈ʒu

static int Now_coice = Start_Coice;  //������
//--------------1.27
//�I����ʂ̕����̈ʒu----------------------1.29
const static int Coice_ken_y = 100;    //���L�����P�̂��̈ʒu
const static int Coice_kobu_y = 200;   //���L�����P�̂��̈ʒu
const static int Coice_ken2_y = 300;   //���L�����Q�̂��̈ʒu
const static int Coice_kobu2_y = 400;  //���L�����Q�̂��̈ʒu

int Player1_check = 0;//����
int Player2_check = 0;//����

typedef enum {	//�I����ʑI��g
	Coice_ken,	//���L�����P
	Coice_kobu,	//���L�����P
	Coice_ken2,	//���L�����Q
	Coice_kobu2,//���L�����Q

	Coice_Num,  //���ڍ��v
};

int C_1p_coice_y = 0;               //�P�v���C���̑I�����̈ʒu
int C_2p_coice_y = 0;               //�Q�v���C���̑I�����̈ʒu

static int C_1p_NOW_coice = Coice_ken;    //�͂��߂͈�ԏ�
static int C_2p_NOW_coice = Coice_ken;    //�͂��߂͈�ԏ�

//------------------------------1.29
//���U���g��ʂ̕����̈ʒu
const static int Rusult_Play_x = 130;	//�u������x�v��x�̈ʒu
const static int Rusult_Coice_x = 230;	//�u�I������I�ԁv��x�̈ʒu
const static int Rusult_End_x = 330;	//�u�G���h��ʁv��x�̈ʒu

typedef enum {		//���U���g��ʑI��g
	Rusult_Play,	//�O�̉�ʂɖ߂�
	Rusult_Coice,	//�I����ʂɖ߂�
	Rusult_End,		//���̉�ʂ�

	Rusult_Num,		//���ڂ̐�
};

int R_coice_x = 0;//�I�𒆂̂��̈ʒu

static int R_NOW_coice = Rusult_Play;//�͂��߂͈�ԏ�

//----------------------------------------------------------
//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);								//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//�w��̐��l�ŃE�B���h�E��\������
	SetWindowStyleMode(GAME_WINDOW_BAR);				//�^�C�g���o�[�̓f�t�H���g�ɂ���
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//�E�B���h�E�̃^�C�g���̕���
	SetAlwaysRunFlag(TRUE);								//��A�N�e�B�u�ł����s����
	SetWindowIconID(1001);							//�A�C�R���t�@�C����Ǎ�

	if (DxLib_Init() == -1) { return -1; }	//�c�w���C�u��������������

	//�摜��ǂݍ���
	if (MY_LOAD_IMAGE() == FALSE) { return -1; }


	//���y��ǂݍ���
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }

	//�v���C���[�̐ݒ�
	player2.CanShot = TRUE;
	player2.ShotReLoadCnt = 0;
	player2.ShotReLoadCntMAX = CHARA_RELOAD_LOW;


	//�t�H���g���ꎞ�I�ɃC���X�g�[��
	if (MY_FONT_INSTALL_ONCE() == FALSE) { return -1; }
	//�t�H���g�n���h�����쐬
	if (MY_FONT_CREATE() == FALSE) { return -1; }



	GameScene = GAME_SCENE_START;	//�Q�[���V�[���̓X�^�[�g��ʂ���

	SetDrawScreen(DX_SCREEN_BACK);	//Draw�n�֐��͗���ʂɕ`��


	//�������[�v
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��
		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		MY_ALL_KEYDOWN_UPDATE();				//�����Ă���L�[��Ԃ��擾

		MY_MOUSE_UPDATE();						//�}�E�X�̏�Ԃ��擾

		MY_FPS_UPDATE();	//FPS�̏���[�X�V]

		//�V�[�����Ƃɏ������s��
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();	//�X�^�[�g���
			break;
		case GAME_SCENE_CHOICE:
			MY_CHOICE();//�I�����
			break;
		case GAME_SCENE_PLAY:
			MY_PLAY();	//�v���C���
			break;
		case GAME_SCENE_RUSULT:
			MY_RUSULT();//���U���g���
			break;
		case GAME_SCENE_END:
			MY_END();	//�G���h���
			break;
		}

		MY_FPS_DRAW();		//FPS�̏���[�`��]

		ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		MY_FPS_WAIT();		//FPS�̏���[�҂�]
	}

	//�t�H���g�n���h����j��
	MY_FONT_DELETE();

	//�ꎞ�I�ɃC���X�g�[�������t�H���g���A���C���X�g�[��
	MY_FONT_UNINSTALL_ONCE();

	//�摜�n���h����j��
	MY_DELETE_IMAGE();


	//���y�n���h����j��
	MY_DELETE_MUSIC();


	DxLib_End();	//�c�w���C�u�����g�p�̏I������

	return 0;
}

//########## FPS�l���v���A�X�V����֐� ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1�t���[���ڂȂ玞�����L��
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60�t���[���ڂȂ畽�ς��v�Z
	{
		int now = GetNowCount();
		//���݂̎��Ԃ���A0�t���[���ڂ̎��Ԃ������AFPS�̐��l�Ŋ��遁1FPS�ӂ�̕��ώ��Ԃ��v�Z�����
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS�l��`�悷��֐� ##########
VOID MY_FPS_DRAW(VOID)
{
	//�������`��
	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(255, 255, 255), "FPS:%.1f", CalcFps);
	return;
}

//########## FPS�l���v�����A�҂֐� ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//������������
	int waitTime = CountFps * 1000 / GAME_FPS - resultTime;	//�҂ׂ�����

	if (waitTime > 0)		//�w���FPS�l���������ꍇ
	{
		WaitTimer(waitTime);	//�҂�
	}
	return;
}

//########## �L�[�̓��͏�Ԃ��X�V����֐� ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{

	char TempKey[256];	//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����

	//���O�̃L�[���͂��Ƃ��Ă���
	for (int i = 0; i < 256; i++)
	{
		OldAllKeyState[i] = AllKeyState[i];
	}

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
//���@���Fint�F�L�[�R�[�h�FKEY_INPUT_???
BOOL MY_KEY_DOWN(int KEY_INPUT_)
{
	//�L�[�R�[�h�̃L�[�������Ă��鎞
	if (AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;	//�L�[�������Ă���
	}
	else
	{
		return FALSE;	//�L�[�������Ă��Ȃ�
	}
}

//�L�[�������グ�����A�L�[�R�[�h�Ŕ��f����
//���@���Fint�F�L�[�R�[�h�FKEY_INPUT_???
BOOL MY_KEY_UP(int KEY_INPUT_)
{
	if (OldAllKeyState[KEY_INPUT_] >= 1	//���O�͉����Ă���
		&& AllKeyState[KEY_INPUT_] == 0)	//���͉����Ă��Ȃ��Ƃ�
	{
		return TRUE;	//�L�[�������グ�Ă���
	}
	else
	{
		return FALSE;	//�L�[�������グ�Ă��Ȃ�
	}
}

//�L�[�����������Ă��邩�A�L�[�R�[�h�Ŕ��f����
//���@���Fint�F�L�[�R�[�h�FKEY_INPUT_???
//���@���Fint�F�L�[�����������鎞��
BOOL MY_KEYDOWN_KEEP(int KEY_INPUT_, int DownTime)
{
	//���������鎞��=�b���~FPS�l
	//��j60FPS�̃Q�[���ŁA1�b�ԉ���������Ȃ�A1�b�~60FPS
	int UpdateTime = DownTime * GAME_FPS;

	if (AllKeyState[KEY_INPUT_] > UpdateTime)
	{
		return TRUE;	//���������Ă���
	}
	else
	{
		return FALSE;	//���������Ă��Ȃ�
	}
}

//�}�E�X�̓��͏����X�V����
VOID MY_MOUSE_UPDATE(VOID)
{
	//�}�E�X�̈ȑO�̍��W���擾
	mouse.OldPoint = mouse.Point;

	//�}�E�X�̈ȑO�̃{�^�����͂��擾
	for (int i = 0; i < MOUSE_BUTTON_CODE; i++) { mouse.OldButton[i] = mouse.Button[i]; }

	//�}�E�X�̍��W���擾
	GetMousePoint(&mouse.Point.x, &mouse.Point.y);

	//�}�E�X�̉����Ă���{�^�����擾
	mouse.InputValue = GetMouseInput();

	//���{�^���������Ă��邩�`�F�b�N(TRUE��0�ȊO�Ȃ̂ŁA2��4��TRUE)
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) == MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT]++; }		//�����Ă���
	if ((mouse.InputValue & MOUSE_INPUT_LEFT) != MOUSE_INPUT_LEFT) { mouse.Button[MOUSE_INPUT_LEFT] = 0; }		//�����Ă��Ȃ�

	//���{�^���������Ă��邩�`�F�b�N(TRUE��0�ȊO�Ȃ̂ŁA2��4��TRUE)
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) == MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE]++; }	//�����Ă���
	if ((mouse.InputValue & MOUSE_INPUT_MIDDLE) != MOUSE_INPUT_MIDDLE) { mouse.Button[MOUSE_INPUT_MIDDLE] = 0; }	//�����Ă��Ȃ�

	//�E�{�^���������Ă��邩�`�F�b�N(TRUE��0�ȊO�Ȃ̂ŁA2��4��TRUE)
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) == MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT]++; }		//�����Ă���
	if ((mouse.InputValue & MOUSE_INPUT_RIGHT) != MOUSE_INPUT_RIGHT) { mouse.Button[MOUSE_INPUT_RIGHT] = 0; }	//�����Ă��Ȃ�

	//�z�C�[���̉�]�ʂ��擾
	mouse.WheelValue = GetMouseWheelRotVol();

	return;
}

//�{�^���������Ă��邩�A�}�E�X�[�R�[�h�Ŕ��f����
//���@���Fint�F�}�E�X�R�[�h�FMOUSE_INPUT_???
BOOL MY_MOUSE_DOWN(int MOUSE_INPUT_)
{
	//�}�E�X�R�[�h�̃{�^���������Ă��鎞
	if (mouse.Button[MOUSE_INPUT_] != 0)
	{
		return TRUE;	//�{�^���������Ă���
	}
	else
	{
		return FALSE;	//�{�^���������Ă��Ȃ�
	}
}


//�{�^���������グ�����A�}�E�X�R�[�h���f����
//���@���Fint�F�}�E�X�R�[�h�FMOUSE_INPUT_???
BOOL MY_MOUSE_UP(int MOUSE_INPUT_)
{
	if (mouse.OldButton[MOUSE_INPUT_] >= 1	//���O�͉����Ă���
		&& mouse.Button[MOUSE_INPUT_] == 0)	//���͉����Ă��Ȃ��Ƃ�
	{
		return TRUE;	//�{�^���������グ�Ă���
	}
	else
	{
		return FALSE;	//�{�^���������グ�Ă��Ȃ�
	}
}

//�{�^�������������Ă��邩�A�}�E�X�R�[�h���f����
//���@���Fint�F�}�E�X�R�[�h�FMOUSE_INPUT_???
//���@���Fint�F�{�^�������������鎞��
BOOL MY_MOUSEDOWN_KEEP(int MOUSE_INPUT_, int DownTime)
{
	//���������鎞��=�b���~FPS�l
	//��j60FPS�̃Q�[���ŁA1�b�ԉ���������Ȃ�A1�b�~60FPS
	int UpdateTime = DownTime * GAME_FPS;

	if (mouse.Button[MOUSE_INPUT_] > UpdateTime)
	{
		return TRUE;	//���������Ă���
	}
	else
	{
		return FALSE;	//���������Ă��Ȃ�
	}
}

//�t�H���g�����̃\�t�g�p�ɁA�ꎞ�I�ɃC���X�g�[��
BOOL MY_FONT_INSTALL_ONCE(VOID)
{
	//�t�H���g���ꎞ�I�ɓǂݍ���(WinAPI)
	if (AddFontResourceEx(FONT_TANU_PATH, FR_PRIVATE, NULL) == 0)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), FONT_TANU_NAME, FONT_INSTALL_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//�t�H���g�����̃\�t�g�p�ɁA�ꎞ�I�ɃA���C���X�g�[��
VOID MY_FONT_UNINSTALL_ONCE(VOID)
{
	//�ꎞ�I�ɓǂݍ��񂾃t�H���g���폜(WinAPI)
	RemoveFontResourceEx(FONT_TANU_PATH, FR_PRIVATE, NULL);

	return;
}

//�t�H���g��ǂݍ��ފ֐�
//���@���Fconst char *�F�ǂݍ��ރt�H���g�̖��O
//���@���Fint�@�F�t�H���g�̑傫��
//���@���Fint�@�F�t�H���g�̑���
//���@���Fint�@�F�t�H���g�̃^�C�v
//�߂�l�F�Ȃ����ύX���߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_FONT_CREATE(VOID)
{
	//���������ʂ������}�W�b�N�̃t�H���g���쐬������

	//�t�H���g�f�[�^���쐬
	strcpy_s(FontTanu32.path, sizeof(FontTanu32.path), FONT_TANU_PATH);	//�p�X���R�s�[
	strcpy_s(FontTanu32.name, sizeof(FontTanu32.name), FONT_TANU_NAME);	//�t�H���g�����R�s�[
	FontTanu32.handle = -1;								//�n���h����������
	FontTanu32.size = 32;								//�T�C�Y��32
	FontTanu32.bold = 1;								//����1
	FontTanu32.type = DX_FONTTYPE_ANTIALIASING_EDGE;	//�A���`�G�C���A�V���O�t���̃t�H���g

	//�t�H���g�n���h���쐬
	FontTanu32.handle = CreateFontToHandle(FontTanu32.name, FontTanu32.size, FontTanu32.bold, FontTanu32.type);
	//�t�H���g�n���h���쐬�ł��Ȃ��Ƃ��A�G���[
	if (FontTanu32.handle == -1) { MessageBox(GetMainWindowHandle(), FONT_TANU_NAME, FONT_CREATE_ERR_TITLE, MB_OK); return FALSE; }

	//���������ʂ������}�W�b�N�̃t�H���g���쐬������

	return TRUE;
}

//�t�H���g���폜����֐�
VOID MY_FONT_DELETE(VOID)
{
	//�t�H���g�f�[�^���폜
	DeleteFontToHandle(FontTanu32.handle);	//�t�H���g�̃n���h�����폜

	return;
}

//�X�^�[�g���
VOID MY_START(VOID)
{
	MY_START_PROC();	//�X�^�[�g��ʂ̏���
	MY_START_DRAW();	//�X�^�[�g��ʂ̕`��

	return;
}

//�X�^�[�g��ʂ̏���
VOID MY_START_PROC(VOID)
{
	if (MY_KEY_UP(KEY_INPUT_DOWN) == TRUE)//���̃L�[�������ꂽ��
	{
		Now_coice = (Now_coice + 1) % Start_Num;//�I����Ԃ��������
	}
	if (MY_KEY_UP(KEY_INPUT_UP) == TRUE)//��̃L�[�������ꂽ��
	{
		Now_coice = (Now_coice + (Start_Num - 1)) % Start_Num;//�I����Ԃ���グ��
	}

	//�G���^�[�L�[����������A�I���V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
	{
		switch (Now_coice)
		{
		case Start_Coice:
			//BGM������Ă���Ȃ�
			if (CheckSoundMem(BGM_TITLE.handle) != 0)
			{
				StopSoundMem(BGM_TITLE.handle);	//BGM���~�߂�
			}

			GameScene = GAME_SCENE_CHOICE;//���̉�ʂ�
			break;
		case Start_Exit:
			//BGM������Ă���Ȃ�
			if (CheckSoundMem(BGM_TITLE.handle) != 0)
			{
				StopSoundMem(BGM_TITLE.handle);	//BGM���~�߂�
			}
			DxLib_End();//�c�w���C�u�����g�p�̏I������

			break;
		}
		return;
	}
	//BGM������Ă��Ȃ��Ȃ�
	if (CheckSoundMem(BGM_TITLE.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * 50 / 100, BGM_TITLE.handle);	//50%�̉��ʂɂ���

		PlaySoundMem(BGM_TITLE.handle, DX_PLAYTYPE_LOOP);
	}

	return;
}


//�X�^�[�g��ʂ̕`��
VOID MY_START_DRAW(VOID)
{

	//�w�i��`�悷��
	DrawGraph(ImageTitle.x, ImageTitle.y, ImageTitle.handle, TRUE);

	DrawString(200, 150, "�X�^�[�g���", GetColor(255, 255, 255));
	DrawString(200, 170, "�㉺�L�[�������āA�G���^�[�L�[�������Ă�������",GetColor(255, 255, 255));
	DrawString(280, Play_y, "�Q�[���J�n", GetColor(255, 255, 255));
	DrawString(280, Exit_y, "�����",GetColor(255, 255, 255));


	switch (Now_coice)
	{
	case Start_Coice:
		S_coice_y = Play_y;
		break;
	case Start_Exit:
		S_coice_y = Exit_y;
		break;
	}

	DrawString(250, S_coice_y, "��", GetColor(255, 255, 255));
	return;
}

//�I�����
VOID MY_CHOICE(VOID)
{
	MY_CHOICE_PROC();
	MY_CHOICE_DRAW();

	return;
}

//�I����ʂ̏���
VOID MY_CHOICE_PROC(VOID)
{

	if (Player1_check == 0)
	{
		if (MY_KEY_UP(KEY_INPUT_S) == TRUE)    //S�L�[����������
		{
			C_1p_NOW_coice = (C_1p_NOW_coice + 1) % Coice_Num;//�I����Ԃ��������
		}
		if (MY_KEY_UP(KEY_INPUT_W) == TRUE)   //W�L�[����������
		{
			C_1p_NOW_coice = (C_1p_NOW_coice + (Coice_Num - 1)) % Coice_Num;//�I����Ԃ���グ��
		}
	}
	if (Player2_check == 0)
	{
		if (MY_KEY_UP(KEY_INPUT_K) == TRUE)  //I�L�[����������
		{
			C_2p_NOW_coice = (C_2p_NOW_coice + 1) % Coice_Num;//�I����Ԃ��������
		}
		if (MY_KEY_UP(KEY_INPUT_I) == TRUE)  //K�L�[����������
		{
			C_2p_NOW_coice = (C_2p_NOW_coice + (Coice_Num - 1)) % Coice_Num;//�I����Ԃ���グ��
		}
	}


	//D����������A1�v���C���[����
	if (MY_KEY_UP(KEY_INPUT_D) == TRUE)
	{
		Player1_check = 1;
	}

	//L����������A2�v���C���[����
	if (MY_KEY_UP(KEY_INPUT_L) == TRUE)
	{
		Player2_check = 1;
	}

	if (Player1_check == 1 && Player2_check == 1)
	{
		//�G���^�[�L�[����������
		if (MY_KEY_DOWN(KEY_INPUT_RETURN) == TRUE)
		{
			//BGM������Ă���Ȃ�
			if (CheckSoundMem(BGM_CHOICE.handle) != 0)
			{
				StopSoundMem(BGM_CHOICE.handle);	//BGM���~�߂�
			}
			CHOICE_PLAYER1.X = PLAYER1_CHARA_X;
			CHOICE_PLAYER1.Y = PLAYER1_CHARA_Y;
			CHOICE_PLAYER2.X = PLAYER2_CHARA_X;
			CHOICE_PLAYER2.Y = PLAYER2_CHARA_Y;

			GameScene = GAME_SCENE_PLAY;
			return;
		}
	}
		//BGM������Ă��Ȃ��Ȃ�
		if (CheckSoundMem(BGM_CHOICE.handle) == 0)
		{
			//BGM�̉��ʂ�������
			ChangeVolumeSoundMem(255 * 50 / 100, BGM_CHOICE.handle);	//50%�̉��ʂɂ���

			PlaySoundMem(BGM_CHOICE.handle, DX_PLAYTYPE_LOOP);
		}
	
	return;
}
//�I����ʂ̕`��
VOID MY_CHOICE_DRAW(VOID)
{
	//�w�i��`�悷��
	DrawGraph(ImageChoice.x, ImageChoice.y, ImageChoice.handle, TRUE);

	DrawString(300, Coice_ken_y, "�L����1", GetColor(255, 0, 255));
	DrawString(300, Coice_kobu_y, "�L����2", GetColor(255, 0, 255));
	DrawString(300, Coice_ken2_y, "�L����3", GetColor(255, 0, 255));
	DrawString(300, Coice_kobu2_y, "�L����4", GetColor(255, 0, 255));

	switch (C_1p_NOW_coice)
	{
	case Coice_ken:
		C_1p_coice_y = Coice_ken_y;
		if (Player1_check == 1)
		{
			CHOICE_PLAYER1 = player1;
			CHOICE_PLAYER1.X = PLAYER1_CHARA_X;
			CHOICE_PLAYER1.Y = PLAYER1_CHARA_Y;

		}
		break;
	case Coice_kobu:
		C_1p_coice_y =Coice_kobu_y;
		if (Player1_check == 1)
		{
			CHOICE_PLAYER1 = player2;
			CHOICE_PLAYER1.X = PLAYER1_CHARA_X;
			CHOICE_PLAYER1.Y = PLAYER1_CHARA_Y;

		}
		break;
	case Coice_ken2:
		C_1p_coice_y = Coice_ken2_y;
		if (Player1_check == 1)
		{
			CHOICE_PLAYER1 = player3;
			CHOICE_PLAYER1.X = PLAYER1_CHARA_X;
			CHOICE_PLAYER1.Y = PLAYER1_CHARA_Y;

		}
		break;
	case Coice_kobu2:
		C_1p_coice_y = Coice_kobu2_y;
		if (Player1_check == 1)
		{
			CHOICE_PLAYER1 = player4;
			CHOICE_PLAYER1.X = PLAYER1_CHARA_X;
			CHOICE_PLAYER1.Y = PLAYER1_CHARA_Y;

		}

		break;
	}

	switch (C_2p_NOW_coice)
	{
	case Coice_ken:
		C_2p_coice_y = Coice_ken_y;
		if (Player2_check == 1)
		{
			CHOICE_PLAYER2 = player1;
			CHOICE_PLAYER2.X = PLAYER2_CHARA_X;
			CHOICE_PLAYER2.Y = PLAYER2_CHARA_Y;
			CHOICE_PLAYER2.imagekind = 3;
		}
		break;
	case Coice_kobu:
		C_2p_coice_y = Coice_kobu_y;
		if (Player2_check == 1)
		{
			CHOICE_PLAYER2 = player2;
			CHOICE_PLAYER2.X = PLAYER2_CHARA_X;
			CHOICE_PLAYER2.Y = PLAYER2_CHARA_Y;
			CHOICE_PLAYER2.imagekind = 3;
		}
		break;
	case Coice_ken2:
		C_2p_coice_y = Coice_ken2_y;
		if (Player2_check == 1)
		{
			CHOICE_PLAYER2 = player3;
			CHOICE_PLAYER2.X = PLAYER2_CHARA_X;
			CHOICE_PLAYER2.Y = PLAYER2_CHARA_Y;
			CHOICE_PLAYER2.imagekind = 3;
		}
		break;
	case Coice_kobu2:
		C_2p_coice_y = Coice_kobu2_y;
		if (Player2_check == 1)
		{
			CHOICE_PLAYER2 = player4;
			CHOICE_PLAYER2.X = PLAYER2_CHARA_X;
			CHOICE_PLAYER2.Y = PLAYER2_CHARA_Y;
			CHOICE_PLAYER2.imagekind = 3;
		}
		break;
	}


	DrawString(70, C_1p_coice_y, "1p��", GetColor(0, 0, 0));
	DrawString(400, C_2p_coice_y, "��2p", GetColor(0, 0, 0));
	DrawString(0, 0, "1P��W�ŏ�ցAS�ŉ���I���AD�Ŋm��", GetColor(0, 0, 0));
	DrawString(0, 20, "2P��I�ŏ�ցAK�ŉ���I���AL�Ŋm��", GetColor(0, 0,0));
	DrawString(0, 40, "�����m�肵����G���^�[�L�[�������Ă�������", GetColor(0, 0, 0));

	return;
}


//�v���C���
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();	//�v���C��ʂ̏���
	MY_PLAY_DRAW();	//�v���C��ʂ̕`��

	return;
}


//�v���C��ʂ̏���
VOID MY_PLAY_PROC(VOID)
{
	//�X�y�[�X�L�[����������A�G���h�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_SPACE) == TRUE)
	{

		//BGM������Ă���Ȃ�
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);	//BGM���~�߂�
		}



		GameScene = GAME_SCENE_RUSULT;

		return;	//�����I�ɃG���h��ʂɔ��

	}


	//BGM������Ă��Ȃ��Ȃ�
	if (CheckSoundMem(BGM.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * 50 / 100, BGM.handle);	//50%�̉��ʂɂ���

		//BGM�𗬂�
		//DX_PLAYTYPE_NORMAL:�@�m�[�}���Đ�
		//DX_PLAYTYPE_BACK  : �o�b�N�O���E���h�Đ�
		//DX_PLAYTYPE_LOOP  : ���[�v�Đ�
		PlaySoundMem(BGM.handle, DX_PLAYTYPE_LOOP);
	}


	//�d�͂������I�ɔ����L����1
	CHOICE_PLAYER1.Y += GAME_GR;
	//�d�͂������I�ɔ����L�����Q
	CHOICE_PLAYER2.Y += GAME_GR;

	//�����蔻����X�V�L�����P
	CHOICE_PLAYER1.coll.left = CHOICE_PLAYER1.X;
	CHOICE_PLAYER1.coll.right = CHOICE_PLAYER1.X + CHOICE_PLAYER1.width;
	CHOICE_PLAYER1.coll.top = CHOICE_PLAYER1.Y;
	CHOICE_PLAYER1.coll.bottom = CHOICE_PLAYER1.Y + CHOICE_PLAYER1.height;
	//�����蔻����X�V�L�����Q
	CHOICE_PLAYER2.coll.left = CHOICE_PLAYER2.X;
	CHOICE_PLAYER2.coll.right = CHOICE_PLAYER2.X + CHOICE_PLAYER2.width;
	CHOICE_PLAYER2.coll.top = CHOICE_PLAYER2.Y;
	CHOICE_PLAYER2.coll.bottom = CHOICE_PLAYER2.Y + CHOICE_PLAYER2.height;

	

	//�W�����v�@W���������Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_W) == TRUE)
	{
		//�W�����v���Ă��Ȃ��Ƃ��́A�W�����v�́@�t���O�����Ă�
		if (CHOICE_PLAYER1.IsJump == FALSE)
		{
			CHOICE_PLAYER1.IsJump = TRUE;

			CHOICE_PLAYER1.BeforeJump = CHOICE_PLAYER1.Y;   //�W�����v����O��Y�ʒu
			CHOICE_PLAYER1.JumpPower = -10;		  //�����x��10�ň���
		}
	}
	//�W�����v�@I���������Ƃ�
	if (MY_KEY_DOWN(KEY_INPUT_I) == TRUE)
	{
		//�W�����v���Ă��Ȃ��Ƃ��́A�W�����v�́@�t���O�����Ă�
		if (CHOICE_PLAYER2.IsJump == FALSE)
		{
			CHOICE_PLAYER2.IsJump = TRUE;

			CHOICE_PLAYER2.BeforeJump = CHOICE_PLAYER2.Y;   //�W�����v����O��Y�ʒu
			CHOICE_PLAYER2.JumpPower = -10;		  //�����x��10�ň���
		}
	}


	//�W�����v���Ă���Ƃ��L�����P
	if (CHOICE_PLAYER1.IsJump == TRUE)
	{
		CHOICE_PLAYER1.Y -= GAME_GR;                                               //�d�͂ɕ����Ȃ�
		int y_temp = CHOICE_PLAYER1.Y;												//���݂�Y���W���L�^
		CHOICE_PLAYER1.Y += (CHOICE_PLAYER1.Y - CHOICE_PLAYER1.BeforeJump) + CHOICE_PLAYER1.JumpPower;  //��Ɍ��������l���v�Z������
		CHOICE_PLAYER1.JumpPower = 1;                                              //�����x���P�ɂ���
		CHOICE_PLAYER1.BeforeJump = y_temp;                                        //�ȑO�̈ʒu�ɋL�^

		//�n�ʂ̓����蔻��(�������Ă��Ȃ��Ƃ��j
		if (IsMAP_JUMP()==TRUE)
		{
			CHOICE_PLAYER1.IsJump = FALSE;
		}
	}
	//�W�����v���Ă���Ƃ��L�����Q
	if (CHOICE_PLAYER2.IsJump == TRUE)
	{
		CHOICE_PLAYER2.Y -= GAME_GR;                                               //�d�͂ɕ����Ȃ�
		int y_temp = CHOICE_PLAYER2.Y;												//���݂�Y���W���L�^
		CHOICE_PLAYER2.Y += (CHOICE_PLAYER2.Y - CHOICE_PLAYER2.BeforeJump) + CHOICE_PLAYER2.JumpPower;  //��Ɍ��������l���v�Z������
		CHOICE_PLAYER2.JumpPower = 1;                                              //�����x���P�ɂ���
		CHOICE_PLAYER2.BeforeJump = y_temp;                                        //�ȑO�̈ʒu�ɋL�^

		//�n�ʂ̓����蔻��(�������Ă��Ȃ��Ƃ��j
		if (IsMAP_JUMP2() == TRUE)
		{
			CHOICE_PLAYER2.IsJump = FALSE;
		}
	}


	IsMAP_JUMP();//�n�ʂ̔���L�����P
	IsMAP_JUMP2();//�n�ʂ̔���L�����Q

	//A�ō�������
	if (MY_KEY_DOWN(KEY_INPUT_A) == TRUE)
	{
		if (CHOICE_PLAYER1.imageChangeCnt == CHOICE_PLAYER1.imageChangeCntMAX)
		{
			//�����I�ɍ�������
			if (CHOICE_PLAYER1.imagekind < 3 || CHOICE_PLAYER1.imagekind >= 5)
			{
				CHOICE_PLAYER1.imagekind = 3;
			}
			else
			{
				//���������Ă���
				CHOICE_PLAYER1.imagekind++;
			}

			CHOICE_PLAYER1.imageChangeCnt = 0;
		}
		else
		{
			CHOICE_PLAYER1.imageChangeCnt++;
		}

		//�E�Ɉړ�
		CHOICE_PLAYER1.X--;
	}


	//D�ŉE������
	if (MY_KEY_DOWN(KEY_INPUT_D) == TRUE)
	{
		if (CHOICE_PLAYER1.imageChangeCnt == CHOICE_PLAYER1.imageChangeCntMAX)
		{

			//�����I�ɉE������
			if (CHOICE_PLAYER1.imagekind < 6 || CHOICE_PLAYER1.imagekind >= 8)
			{
				CHOICE_PLAYER1.imagekind = 6;
			}
			else
			{
				//�E�������Ă���
				CHOICE_PLAYER1.imagekind++;
			}
			CHOICE_PLAYER1.imageChangeCnt = 0;
		}
		else
		{
			CHOICE_PLAYER1.imageChangeCnt++;
		}
		//���Ɉړ�
		CHOICE_PLAYER1.X++;

	}
	
	//J�ō�������
	if (MY_KEY_DOWN(KEY_INPUT_J) == TRUE)
	{
		if (CHOICE_PLAYER2.imageChangeCnt == CHOICE_PLAYER2.imageChangeCntMAX)
		{
			//�����I�ɍ�������
			if (CHOICE_PLAYER2.imagekind < 3 || CHOICE_PLAYER2.imagekind >= 5)
			{
				CHOICE_PLAYER2.imagekind = 3;
			}
			else
			{
				//���������Ă���
				CHOICE_PLAYER2.imagekind++;
			}

			CHOICE_PLAYER2.imageChangeCnt = 0;
		}
		else
		{
			CHOICE_PLAYER2.imageChangeCnt++;
		}

		//�E�Ɉړ�
		CHOICE_PLAYER2.X--;
	}


	//L�ŉE������
	if (MY_KEY_DOWN(KEY_INPUT_L) == TRUE)
	{
		if (CHOICE_PLAYER2.imageChangeCnt == CHOICE_PLAYER2.imageChangeCntMAX)
		{

			//�����I�ɉE������
			if (CHOICE_PLAYER2.imagekind < 6 || CHOICE_PLAYER2.imagekind >= 8)
			{
				CHOICE_PLAYER2.imagekind = 6;
			}
			else
			{
				//�E�������Ă���
				CHOICE_PLAYER2.imagekind++;
			}
			CHOICE_PLAYER2.imageChangeCnt = 0;
		}
		else
		{
			CHOICE_PLAYER2.imageChangeCnt++;
		}
		//���Ɉړ�
		CHOICE_PLAYER2.X++;

	}

	

	return;
}

BOOL IsMAP_JUMP(VOID)
{
	BOOL check = FALSE;//�n�ʂɓ����������`�F�b�N

	//�n�ʂ̔���i�n�ʂɓ������Ă���Ƃ��j
	if (MY_CHECK_MAP1_PLAYER_COLL(CHOICE_PLAYER1.coll) == TRUE)
	{
		while (MY_CHECK_MAP1_PLAYER_COLL(CHOICE_PLAYER1.coll) == TRUE)
		{


			//���Ƃɖ߂��߂荞�񂾕���߂�
			CHOICE_PLAYER1.Y--;

			//�����蔻����X�V
			CHOICE_PLAYER1.coll.left = CHOICE_PLAYER1.X;
			CHOICE_PLAYER1.coll.right = CHOICE_PLAYER1.X + CHOICE_PLAYER1.width;
			CHOICE_PLAYER1.coll.top = CHOICE_PLAYER1.Y;
			CHOICE_PLAYER1.coll.bottom = CHOICE_PLAYER1.Y + CHOICE_PLAYER1.height;
		}
		check = TRUE;//�n�ʂɓ�������
	}
	return check;
}

BOOL IsMAP_JUMP2(VOID)
{
	BOOL check = FALSE;//�n�ʂɓ����������`�F�b�N

	//�n�ʂ̔���i�n�ʂɓ������Ă���Ƃ��j
	if (MY_CHECK_MAP1_PLAYER_COLL(CHOICE_PLAYER2.coll) == TRUE)
	{
		while (MY_CHECK_MAP1_PLAYER_COLL(CHOICE_PLAYER2.coll) == TRUE)
		{


			//���Ƃɖ߂��߂荞�񂾕���߂�
			CHOICE_PLAYER2.Y--;

			//�����蔻����X�V
			CHOICE_PLAYER2.coll.left = CHOICE_PLAYER2.X;
			CHOICE_PLAYER2.coll.right = CHOICE_PLAYER2.X + CHOICE_PLAYER2.width;
			CHOICE_PLAYER2.coll.top = CHOICE_PLAYER2.Y;
			CHOICE_PLAYER2.coll.bottom = CHOICE_PLAYER2.Y + CHOICE_PLAYER2.height;
		}
		check = TRUE;//�n�ʂɓ�������
	}
	return check;
}


//�v���C��ʂ̕`��
VOID MY_PLAY_DRAW(VOID)
{

		


		//�w�i��`�悷��========================================================
		DrawGraph(ImageBack.x, ImageBack.y, ImageBack.handle, TRUE);

		//�}�b�v�̕`��
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//�}�b�v��`��
				DrawGraph(
					map[tate][yoko].x,
					map[tate][yoko].y,
					mapChip.handle[map[tate][yoko].kind],
					TRUE);
			}
		}
		//====================================================================


		//�����蔻��̕`��i�f�o�b�O�p�j----------------��
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//�ǂȂ��
				if (mapData[tate][yoko] == k)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
				}


				//y�Ȃ��
				if (mapData[tate][yoko] == y)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
				}

				//�ʘH�Ȃ��
				if (mapData[tate][yoko] == t)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
				}
			}
		}
		//�v���C��1�̕`��
		DrawGraph(CHOICE_PLAYER1.X, CHOICE_PLAYER1.Y, CHOICE_PLAYER1.handle[CHOICE_PLAYER1.imagekind], TRUE);
		//�v���C��2�̕`��
		DrawGraph(CHOICE_PLAYER2.X, CHOICE_PLAYER2.Y, CHOICE_PLAYER2.handle[CHOICE_PLAYER2.imagekind], TRUE);

		//�����蔻��`��i�f�o�b�O�j----------------��
		DrawBox(CHOICE_PLAYER1.coll.left, CHOICE_PLAYER1.coll.top, CHOICE_PLAYER1.coll.right, CHOICE_PLAYER1.coll.bottom, GetColor(255, 0, 0), FALSE);
		DrawBox(CHOICE_PLAYER2.coll.left, CHOICE_PLAYER2.coll.top, CHOICE_PLAYER2.coll.right, CHOICE_PLAYER2.coll.bottom, GetColor(255, 0, 0), FALSE);









		DrawString(0, 0, "�v���C���(�X�y�[�X�L�[�������ĉ�����)", GetColor(255, 255, 255));

	//}

	//------------------------------------------------

	
	
	return;
}

//���U���g���
VOID MY_RUSULT(VOID)
{
	MY_RUSULT_PROC();
	MY_RUSULT_DRAW();

	return;
}

//���U���g��ʂ̏���
VOID MY_RUSULT_PROC(VOID)
{

	//G����������A�v���C�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_K) != 0)
	{

		//BGM������Ă���Ȃ�
		if (CheckSoundMem(BGM_RUSULT.handle) != 0)
		{
			StopSoundMem(BGM_RUSULT.handle);	//BGM���~�߂�
		}


		GameScene = GAME_SCENE_END;
		return;
	}

	//BGM������Ă��Ȃ��Ȃ�


	if (CheckSoundMem(BGM_RUSULT.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * 50 / 100, BGM_RUSULT.handle);	//50%�̉��ʂɂ���

		//BGM�𗬂�
		//DX_PLAYTYPE_NORMAL:�@�m�[�}���Đ�
		//DX_PLAYTYPE_BACK  : �o�b�N�O���E���h�Đ�
		//DX_PLAYTYPE_LOOP  : ���[�v�Đ�
		PlaySoundMem(BGM_RUSULT.handle, DX_PLAYTYPE_LOOP);
	}

	if (MY_KEY_UP(KEY_INPUT_DOWN) == TRUE)//�E����������
	{
		R_NOW_coice = (R_NOW_coice + 1) % Rusult_Num;//�I����Ԃ������
	}
	if (MY_KEY_UP(KEY_INPUT_UP) == TRUE)//���������ꂽ��
	{
		R_NOW_coice = (R_NOW_coice + (Rusult_Num - 1)) % Rusult_Num;//�I����Ԃ���グ��
	}


	return;
}
//���U���g��ʂ̕`��
VOID MY_RUSULT_DRAW(VOID)
{
	//�w�i��`�悷��
	DrawGraph(ImageRusult.x, ImageRusult.y, ImageRusult.handle, TRUE);

	DrawString(100,500,"������x",GetColor(255,255,255));
	DrawString(200,500,"�I����ʂ����蒼��",GetColor(255,255,255));
	DrawString(400,500,"�I���",GetColor(255,255,255));

	switch (Rusult_Num)
	{
	case Rusult_Play:
		R_coice_x = Rusult_Play_x;
		break;
	case Rusult_Coice:
		R_coice_x = Rusult_Coice_x;
		break;
	case Rusult_End:
		R_coice_x = Rusult_End_x;
		break;
	}

	DrawString(R_coice_x, 500, "��", GetColor(255, 255, 0));

	DrawString(0, 0, "���U���g���(K�������ĉ�����)", GetColor(255, 255, 255));

	return;
}

//�G���h���
VOID MY_END(VOID)
{
	MY_END_PROC();	//�G���h��ʂ̏���
	MY_END_DRAW();	//�G���h��ʂ̕`��
	return;
}

//�G���h��ʂ̏���
VOID MY_END_PROC(VOID)
{
	//�G�X�P�[�v�L�[����������A�X�^�[�g�V�[���ֈړ�����
	if (MY_KEY_DOWN(KEY_INPUT_ESCAPE) == TRUE)
	{
		//BGM������Ă���Ȃ�
		if (CheckSoundMem(BGM_END.handle) != 0)
		{
			StopSoundMem(BGM_END.handle);	//BGM���~�߂�
		}


		GameScene = GAME_SCENE_START;
		return;
	}

	//BGM������Ă��Ȃ��Ȃ�
	if (CheckSoundMem(BGM_END.handle) == 0)
	{
		//BGM�̉��ʂ�������
		ChangeVolumeSoundMem(255 * 50 / 100, BGM_END.handle);	//50%�̉��ʂɂ���

		//BGM�𗬂�
		//DX_PLAYTYPE_NORMAL:�@�m�[�}���Đ�
		//DX_PLAYTYPE_BACK  : �o�b�N�O���E���h�Đ�
		//DX_PLAYTYPE_LOOP  : ���[�v�Đ�
		PlaySoundMem(BGM_END.handle, DX_PLAYTYPE_LOOP);
	}


	return;
}

//�G���h��ʂ̕`��
VOID MY_END_DRAW(VOID)
{
	//�w�i��`�悷��
	DrawGraph(ImageEnd.x, ImageEnd.y, ImageEnd.handle, TRUE);

	DrawString(0, 0, "�G���h���(�G�X�P�[�v�L�[�������ĉ�����)", GetColor(255, 255, 255));
	return;
}


//�摜���܂Ƃ߂ēǂݍ��ފ֐�
BOOL MY_LOAD_IMAGE(VOID)
{
	//�w�i�摜===================================================================================
	strcpy_s(ImageBack.path, IMAGE_BACK_PATH);		//�p�X�̐ݒ�
	ImageBack.handle = LoadGraph(ImageBack.path);	//�ǂݍ���
	if (ImageBack.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), IMAGE_BACK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageBack.handle, &ImageBack.width, &ImageBack.height);	//�摜�̕��ƍ������擾
	ImageBack.x = GAME_WIDTH / 2 - ImageBack.width / 2;		//���E��������
	ImageBack.y = GAME_HEIGHT / 2 - ImageBack.height / 2;	//�㉺��������

	//============================================================================================

	//�^�C�g���w�i�摜
	strcpy_s(ImageTitle.path, IMAGE_TITLE_PATH);
	ImageTitle.handle = LoadGraph(ImageTitle.path);
	if (ImageTitle.handle == -1)
	{
		//�G���[���b�Z�[�W
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitle.handle, &ImageTitle.width, &ImageTitle.height);
	ImageTitle.x = GAME_WIDTH / 2 - ImageTitle.width / 2;
	ImageTitle.y = GAME_HEIGHT / 2 - ImageTitle.height / 2;
	//==============================================================================================

	//�I��w�i�摜
	strcpy_s(ImageChoice.path, IMAGE_CHOICE_PATH);
	ImageChoice.handle = LoadGraph(ImageChoice.path);
	if (ImageChoice.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_CHOICE_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageChoice.handle, &ImageChoice.width, &ImageChoice.height);
	ImageChoice.x = GAME_WIDTH / 2 - ImageChoice.width / 2;
	ImageChoice.y = GAME_HEIGHT / 2 - ImageChoice.height / 2;
	//==============================================================================================

	//���U���g�w�i�摜
	strcpy_s(ImageRusult.path, IMAGE_RUSULT_PATH);
	ImageRusult.handle = LoadGraph(ImageRusult.path);
	if (ImageRusult.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_RUSULT_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageRusult.handle, &ImageRusult.width, &ImageRusult.height);
	ImageRusult.x = GAME_WIDTH / 2 - ImageRusult.width / 2;
	ImageRusult.y = GAME_HEIGHT / 2 - ImageRusult.height / 2;
	//==============================================================================================

	//�G���h�w�i�摜
	strcpy_s(ImageEnd.path, IMAGE_END_PATH);
	ImageEnd.handle = LoadGraph(ImageEnd.path);
	if (ImageEnd.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEnd.handle, &ImageEnd.width, &ImageEnd.height);
	ImageEnd.x = GAME_WIDTH / 2 - ImageEnd.width / 2;
	ImageEnd.y = GAME_HEIGHT / 2 - ImageEnd.height / 2;
	//==============================================================================================



	//�L�����N�^�P���摜��ǂݍ���-------------2.4
	strcpy_s(player1.path, IMAGE_PLAYER1_PATH);
	LoadDivGraph(
		player1.path,
		PLAYER_YOKO_DIV * PLAYER_TATE_DIV,
		PLAYER_YOKO_DIV,
		PLAYER_TATE_DIV,
		PLAYER_WIDTH,
		PLAYER_HEIGHT,
		&player1.handle[0]
	);

	//�v���C���[�̈ʒu�ݒ�
	player1.X = 0;
	player1.Y = 0;

	//�v���C���̃T�C�Y
	GetGraphSize(player1.handle[0], &player1.width, &player1.height);//�摜�̕��ƍ������擾

	//�v���C���[�̍ŏ��̉摜
	player1.imagekind = 6;

	//�v���C���̉摜��ς���^�C�~���O
	player1.imageChangeCnt = 0;
	player1.imageChangeCntMAX = 10;

	//�v���C���̓����蔻��𐶐�
	player1.coll.left = player1.X;
	player1.coll.right = player1.X + player1.width;
	player1.coll.top = player1.Y;
	player1.coll.bottom = player1.Y + player1.height;

	//�W�����v
	player1.IsJump = FALSE;

	//------------------2.4
	//�L�����N�^�[�Q�̓Ǎ�

	strcpy_s(player2.path, IMAGE_PLAYER2_PATH);
	LoadDivGraph(
		player2.path,
		PLAYER_YOKO_DIV* PLAYER_TATE_DIV,
		PLAYER_YOKO_DIV,
		PLAYER_TATE_DIV,
		PLAYER_WIDTH,
		PLAYER_HEIGHT,
		&player2.handle[0]
	);

	//�v���C���[�̈ʒu�ݒ�
	player2.X = 0;
	player2.Y = 0;

	//�v���C���̃T�C�Y
	GetGraphSize(player2.handle[0], &player2.width, &player2.height);//�摜�̕��ƍ������擾

	//�v���C���[�̍ŏ��̉摜
	player2.imagekind = 6;

	//�v���C���̉摜��ς���^�C�~���O
	player2.imageChangeCnt = 0;
	player2.imageChangeCntMAX = 10;

	//�v���C���̓����蔻��𐶐�
	player2.coll.left = player2.X;
	player2.coll.right = player2.X + player2.width;
	player2.coll.top = player2.Y;
	player2.coll.bottom = player2.Y + player2.height;

	//�W�����v
	player2.IsJump = FALSE;
	//------------------------------------------------------
	//�L�����N�^�[�R�̓Ǎ�
	strcpy_s(player3.path, IMAGE_PLAYER3_PATH);
	LoadDivGraph(
		player3.path,
		PLAYER_YOKO_DIV * PLAYER_TATE_DIV,
		PLAYER_YOKO_DIV,
		PLAYER_TATE_DIV,
		PLAYER_WIDTH,
		PLAYER_HEIGHT,
		&player3.handle[0]
	);

	//�v���C���[�̈ʒu�ݒ�
	player3.X = 0;
	player3.Y = 0;

	//�v���C���̃T�C�Y
	GetGraphSize(player3.handle[0], &player3.width, &player3.height);//�摜�̕��ƍ������擾

	//�v���C���[�̍ŏ��̉摜
	player3.imagekind = 6;

	//�v���C���̉摜��ς���^�C�~���O
	player3.imageChangeCnt = 0;
	player3.imageChangeCntMAX = 10;

	//�v���C���̓����蔻��𐶐�
	player3.coll.left = player3.X;
	player3.coll.right = player3.X + player3.width;
	player3.coll.top = player3.Y;
	player3.coll.bottom = player3.Y + player3.height;

	//�W�����v
	player3.IsJump = FALSE;
	//---------------------------------------------------------------------
	//�L�����N�^�[�S�̓Ǎ�
	strcpy_s(player4.path, IMAGE_PLAYER4_PATH);
	LoadDivGraph(
		player4.path,
		PLAYER_YOKO_DIV* PLAYER_TATE_DIV,
		PLAYER_YOKO_DIV,
		PLAYER_TATE_DIV,
		PLAYER_WIDTH,
		PLAYER_HEIGHT,
		&player4.handle[0]
	);

	//�v���C���[�̈ʒu�ݒ�
	player4.X = 0;
	player4.Y = 0;

	//�v���C���̃T�C�Y
	GetGraphSize(player4.handle[0], &player4.width, &player4.height);//�摜�̕��ƍ������擾

	//�v���C���[�̍ŏ��̉摜
	player4.imagekind = 6;

	//�v���C���̉摜��ς���^�C�~���O
	player4.imageChangeCnt = 0;
	player4.imageChangeCntMAX = 10;

	//�v���C���̓����蔻��𐶐�
	player4.coll.left = player4.X;
	player4.coll.right = player4.X + player4.width;
	player4.coll.top = player4.Y;
	player4.coll.bottom = player4.Y + player4.height;

	//�W�����v
	player4.IsJump = FALSE;
	//---------------------------------------------------------




	//�}�b�v�̉摜�𕪊�����--------------------------------------------------------------
	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,										//�Ԓe�̃p�X
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//�Ԓe�𕪊����鐔
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//�摜�𕪊�����̕��ƍ���
		&mapChip.handle[0]);								//���������摜������n���h��

	if (mapRes == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���ƍ������擾
	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//�}�b�v�f�[�^�������p�ɏ����R�s�[
			mapDataInit[tate][yoko] = mapData[tate][yoko];

			//�}�b�v�̎�ނ��R�s�[
			map[tate][yoko].kind = mapData[tate][yoko];

			//�}�b�v�̕��ƍ������R�s�[
			map[tate][yoko].width = mapChip.width;
			map[tate][yoko].height = mapChip.height;

			//�}�b�v�̍��W��ݒ�
			map[tate][yoko].x = yoko * map[tate][yoko].width;
			map[tate][yoko].y = tate * map[tate][yoko].height;
		}
	}

	//-----------------------------------------------------------------------------------------------
		//�Ԓe�̉摜�𕪊�����[�[�[�[�[�[�[�[�[�[��
	int tamaRedRes = LoadDivGraph(
		TAMA_RED_PATH,										//�Ԓe�̃p�X
		TAMA_DIV_NUM, TAMA_DIV_TATE, TAMA_DIV_YOKO,			//�Ԓe�𕪊����鐔
		TAMA_DIV_WIDTH, TAMA_DIV_HEIGHT,					//�摜�𕪊�����̕��ƍ���
		&player2.tama[0].handle[0]);							//���������摜������n���h��

	/*�Ȃ����ǂݍ��߂�H�H�H*/

	if (tamaRedRes == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), TAMA_RED_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���ƍ������擾
	GetGraphSize(player2.tama[0].handle[0], &player2.tama[0].width, &player2.tama[0].height);

	//�e�̏��𐶐�
	for (int cnt = 0; cnt < TAMA_MAX; cnt++)
	{
		//�p�X���R�s�[
		strcpyDx(player2.tama[cnt].path, TEXT(TAMA_RED_PATH));

		for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++)
		{
			//�n���h�����R�s�[
			player2.tama[cnt].handle[i_num] = player2.tama[0].handle[i_num];
		}

		//�����R�s�[
		player2.tama[cnt].width = player2.tama[0].width;

		//�������R�s�[
		player2.tama[cnt].height = player2.tama[0].height;

		//�e��X�ʒu�̓v���C���[�̒��S���甭��
		player2.tama[cnt].x = player2.X - player2.tama[cnt].width / 2;

		//�e��Y�ʒu�̓v���C���[�̏㕔�����甭��
		//player2.tama[cnt].y = player2.image.y;

		//�e�͍ŏ��͔�\��
		player2.tama[cnt].IsDraw = FALSE;

		//�e�̕\���J�E���g��0�ɂ���
		player2.tama[cnt].changeImageCnt = 0;

		//�e�̕\���J�E���gMAX��ݒ肷��
		player2.tama[cnt].changeImageCntMAX = TAMA_CHANGE_MAX;

		//���݂̉摜�̎�ނ�����������
		player2.tama[cnt].nowImageKind = 0;

		//�e�̃X�s�[�h��ݒ肷��
		player2.tama[cnt].speed = CHARA_SPEED_LOW;
	}

	//------------------------------��


	//���ƍ������擾
	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//�}�b�v�f�[�^�������p�ɏ����R�s�[
			mapDataInit[tate][yoko] = mapData[tate][yoko];

			//�}�b�v�̎�ނ��R�s�[
			map[tate][yoko].kind = mapData[tate][yoko];

			//�}�b�v�̕��ƍ������R�s�[
			map[tate][yoko].width = mapChip.width;
			map[tate][yoko].height = mapChip.height;

			//�}�b�v�̍��W��ݒ�
			map[tate][yoko].x = yoko * map[tate][yoko].width;
			map[tate][yoko].y = tate * map[tate][yoko].height;
		}
	}


	//�}�b�v�̓����蔻���ݒ肷��
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//�}�b�v�̓����蔻���ݒ�
			mapColl[tate][yoko].left = (yoko + 0) * mapChip.width + 1;
			mapColl[tate][yoko].top = (tate + 0) * mapChip.height + 1;
			mapColl[tate][yoko].right = (yoko + 1) * mapChip.width - 1;
			mapColl[tate][yoko].bottom = (tate + 1) * mapChip.height - 1;
		}
	}

	//------------------------------------------��
	return TRUE;
}

//�摜���܂Ƃ߂č폜����֐�
VOID MY_DELETE_IMAGE(VOID)
{
	DeleteGraph(ImageBack.handle);
	DeleteGraph(ImageTitle.handle);
	DeleteGraph(ImageChoice.handle);
	DeleteGraph(ImageRusult.handle);
	DeleteGraph(ImageEnd.handle);

	//�}�b�v�폜
	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }
	//-------------------
	for (int i_num = 0; i_num < TAMA_DIV_NUM; i_num++) { DeleteGraph(player2.tama[0].handle[i_num]); }

	//�v���C���̍폜
	for (int i_num = 0; i_num < PLAYER_TATE_DIV*PLAYER_YOKO_DIV; i_num++) { DeleteGraph(player1.handle[i_num]); }
	for (int i_num = 0; i_num < PLAYER_TATE_DIV*PLAYER_YOKO_DIV; i_num++) { DeleteGraph(player2.handle[i_num]); }
	for (int i_num = 0; i_num < PLAYER_TATE_DIV*PLAYER_YOKO_DIV; i_num++) { DeleteGraph(player3.handle[i_num]); }
	for (int i_num = 0; i_num < PLAYER_TATE_DIV*PLAYER_YOKO_DIV; i_num++) { DeleteGraph(player4.handle[i_num]); }

	return;
}


//���y���܂Ƃ߂ēǂݍ��ފ֐�
BOOL MY_LOAD_MUSIC(VOID)
{
	//�w�i���y
	strcpy_s(BGM.path, MUSIC_BGM_PATH);		//�p�X�̐ݒ�
	BGM.handle = LoadSoundMem(BGM.path);	//�ǂݍ���
	if (BGM.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//���U���gBGM
	strcpy_s(BGM_RUSULT.path, MUSIC_RUEULT_BGM_PATH);         //�p�X�̐ݒ�
	BGM_RUSULT.handle = LoadSoundMem(BGM_RUSULT.path);        //�Ǎ�
	if (BGM_RUSULT.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_RUEULT_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	//�^�C�g��BGM
	strcpy_s(BGM_TITLE.path, MUSIC_TITLE_BGM_PATH);      //�p�X�̐ݒ�
	BGM_TITLE.handle = LoadSoundMem(BGM_TITLE.path);     //�Ǎ�
	if (BGM_TITLE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_TITLE_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	//�I��BGM
	strcpy_s(BGM_CHOICE.path, MUSIC_CHOICE_BGM_PATH);//
	BGM_CHOICE.handle = LoadSoundMem(BGM_CHOICE.path);//
	if (BGM_CHOICE.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_CHOICE_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	//�G���hBGM
	strcpy_s(BGM_END.path, MUSIC_END_BGM_PATH);//
	BGM_END.handle = LoadSoundMem(BGM_END.path);//
	if (BGM_END.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), MUSIC_END_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//�v���C���[�̃V���b�g��
	strcpy_s(player2.musicShot.path, MUSIC_PLAYER_SHOT_PATH);			//�p�X�̐ݒ�
	player2.musicShot.handle = LoadSoundMem(player2.musicShot.path);		//�ǂݍ���
	if (player2.musicShot.handle == -1)
	{
		//�G���[���b�Z�[�W�\��
		MessageBox(GetMainWindowHandle(), MUSIC_PLAYER_SHOT_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//���y���܂Ƃ߂č폜����֐�
VOID MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(BGM.handle);
	DeleteSoundMem(player2.musicShot.handle);
	DeleteSoundMem(BGM_TITLE.handle);
	DeleteSoundMem(BGM_CHOICE.handle);
	DeleteSoundMem(BGM_PLAY.handle);
	DeleteSoundMem(BGM_RUSULT.handle);
	DeleteSoundMem(BGM_END.handle);


	return;
}


//�}�b�v�ƃv���C���[�̓����蔻�������֐�--��
BOOL MY_CHECK_MAP1_PLAYER_COLL(RECT player2)
{
	//�}�b�v�̓����蔻���ݒ肷��
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//�v���C���[�ƃ}�b�v���������Ă���Ƃ�
			if (MY_CHECK_RECT_COLL(player2, mapColl[tate][yoko]) == TRUE)
			{
				//�ǂ̂Ƃ��́A�v���C���[�ƃ}�b�v���������Ă���
				if (map[tate][yoko].kind == k) { return TRUE; }
				if (map[tate][yoko].kind == y) { return TRUE; }

			}
		}
	}

	return FALSE;
}

//�̈�̓����蔻�������֐�
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//�������Ă���
	}

	return FALSE;		//�������Ă��Ȃ�
}


