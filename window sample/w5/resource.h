MYMENU MENU
BEGIN
	POPUP "�t�@�C��(&F)"
	BEGIN
		MENUITEM "�I��(&X)",		IDM_END
	END
	POPUP "�I�v�V����(&O)"
	BEGIN
		MENUITEM "�_�C�A���O���J��(&D)\tF5",	IDM_DLG
		MENUITEM "�_�C�A���O�����(&C)\tF6",  IDM_CLOSEDLG
	END
END
MYDLG DIALOGEX 0, 0, 182, 63
STYLE DS_SETFONT | DS_MEDALFRAME | DS_FIXEDSYS | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "���[�h���X�E�_�C�A���O�{�b�N�X"
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
	EDITTEXT		IDC_EDIT1,21,22,189,16,ES_AUTOSCROLL
	DEPUSHBUTTON	"OK",IDOK,7,42,50,14
	PUSHBUTTOM		"�N���A",IDCANCEL,63,42,50,14
	PUSHBUTTOM		"����",IDC_CLOSE<119,42,50,14
	LTEXT			"���������",IDC_STATIC,23,7,73,8
END
MYACCEL ACCELERATORS
BEGIN
	VK_F5,			IDM_DLG,			VIRTKEY, NOINVERT
	VK_F6,			IDM_CLOSEDLG,		VIRTKEY, NOINVERT
END