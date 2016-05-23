
// cgProjectDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "cgProject.h"
#include "cgProjectDlg.h"
#include "afxdialogex.h"
#include "Plot3D.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcgProjectDlg �Ի���



CcgProjectDlg::CcgProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_cgProject_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcgProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDERepsilon, m_SLIDERepsilon);
}

BEGIN_MESSAGE_MAP(CcgProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONcreatedotfont, &CcgProjectDlg::OnBnClickedButtoncreatedotfont)
	ON_BN_CLICKED(IDC_BUTTONdisp1x, &CcgProjectDlg::OnBnClickedButtondisp1x)
	ON_BN_CLICKED(IDC_BUTTONdisp2x, &CcgProjectDlg::OnBnClickedButtondisp2x)
	ON_BN_CLICKED(IDC_BUTTONdisp4x, &CcgProjectDlg::OnBnClickedButtondisp4x)
	ON_BN_CLICKED(IDC_BUTTONcreatevector, &CcgProjectDlg::OnBnClickedButtoncreatevector)
	ON_BN_CLICKED(IDC_BUTTONloadvector, &CcgProjectDlg::OnBnClickedButtonloadvector)
	ON_BN_CLICKED(IDC_BUTTONdispvect1, &CcgProjectDlg::OnBnClickedButtondispvect1)
	ON_BN_CLICKED(IDC_BUTTONdispvect2, &CcgProjectDlg::OnBnClickedButtondispvect2)
	ON_BN_CLICKED(IDC_BUTTONdispvect3, &CcgProjectDlg::OnBnClickedButtondispvect3)
	ON_BN_CLICKED(IDC_BUTTONcreatevectorauto, &CcgProjectDlg::OnBnClickedButtoncreatevectorauto)
	ON_BN_CLICKED(IDC_BUTTONvectfill, &CcgProjectDlg::OnBnClickedButtonvectfill)
	ON_BN_CLICKED(IDC_BUTTON1, &CcgProjectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcgProjectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTONdispvectB1, &CcgProjectDlg::OnBnClickedButtondispvectb1)
	ON_BN_CLICKED(IDC_BUTTONdispvectB2, &CcgProjectDlg::OnBnClickedButtondispvectb2)
	ON_BN_CLICKED(IDC_BUTTONcreateBfont, &CcgProjectDlg::OnBnClickedButtoncreatebfont)
	ON_BN_CLICKED(IDC_BUTTONdispvectB3, &CcgProjectDlg::OnBnClickedButtondispvectb3)
	ON_BN_CLICKED(IDC_BUTTONvectfillB, &CcgProjectDlg::OnBnClickedButtonvectfillb)
	ON_BN_CLICKED(IDC_BUTTONteapot, &CcgProjectDlg::OnBnClickedButtonteapot)
	ON_BN_CLICKED(IDC_BUTTON3Dtext, &CcgProjectDlg::OnBnClickedButton3dtext)
	ON_BN_CLICKED(IDC_BUTTON3Dtexttexture, &CcgProjectDlg::OnBnClickedButton3dtexttexture)
END_MESSAGE_MAP()


// CcgProjectDlg ��Ϣ�������

BOOL CcgProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	ShowWindow(SW_SHOW);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_SLIDERepsilon.SetRange(1, 5);
	m_SLIDERepsilon.SetPos(2);

	SetDlgItemText(IDC_MFCEDITBROWSE1, CString("words.bmp"));
	SetDlgItemText(IDC_MFCEDITBROWSE2, CString("myvectorfont.bin"));
	SetDlgItemText(IDC_EDITcontent, CString("ͼ��ѧ�ֿ�"));
	SetDlgItemText(IDC_EDITcontentB, CString("ͼ��ѧ�ֿ�"));
	((CComboBox*)GetDlgItem(IDC_COMBOFONT))->SetCurSel(0);
	((CButton *)GetDlgItem(IDC_RADIOmanual))->SetCheck(true);
	((CButton *)GetDlgItem(IDC_RADIOauto))->SetCheck(false);

	edgecnt = 0;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcgProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcgProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcgProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//��ȡcv::Mat��ָ����Ԫ�ص�ָ��
inline uchar* MatAt(cv::Mat &mat, int row, int col)
{
	return (mat.data + mat.step[0] * row + mat.step[1] * col);
}

void CcgProjectDlg::MatSmooth(cv::Mat &map1, cv::Mat &map2)
{
	int n1 = map1.rows, n2 = map2.rows, i, j;
	assert(n2 == 2 * n1);
	//б��Ϊ1�ľ�ݴ���
	for (i = 0;i < n1-2;i++)
		for (j = 0;j < n1;j++)
		{
			if (!check(map1, i, j))
				continue;
			//ֱ������
			if ((j > 1) && check(map1, i + 1, j - 1) && check(map1, i + 2, j - 2))
			{
				//���Ͽհ�
				if (!check(map1, i, j - 1) && !check(map1, i, j - 2) && !check(map1, i + 1, j - 2))
				{
					*MatAt(map2, 2 * i + 1, 2 * j - 1) = 1;
					*MatAt(map2, 2 * i + 3, 2 * j - 3) = 1;
				}
				//���¿հ�
				if (!check(map1, i + 1, j) && !check(map1, i + 2, j) && !check(map1, i + 2, j - 1))
				{
					*MatAt(map2, 2 * i + 2, 2 * j) = 1;
					*MatAt(map2, 2 * i + 4, 2 * j - 2) = 1;
				}
			}
			//ֱ������
			if ((j < n1 - 2) && check(map1, i + 1, j + 1) && check(map1, i + 2, j + 2))
			{
				//���Ͽհ�
				if (!check(map1, i, j + 1) && !check(map1, i, j + 2) && !check(map1, i + 1, j + 2))
				{
					*MatAt(map2, 2 * i + 1, 2 * j + 2) = 1;
					*MatAt(map2, 2 * i + 3, 2 * j + 4) = 1;
				}
				//���¿հ�
				if (!check(map1, i + 1, j) && !check(map1, i + 2, j) && !check(map1, i + 2, j + 2))
				{
					*MatAt(map2, 2 * i + 2, 2 * j + 1) = 1;
					*MatAt(map2, 2 * i + 4, 2 * j + 3) = 1;
				}
				
				
			}
		}
	//б��Ϊ0.5��2�ľ��
	for (i = 0;i < n1 - 1;i++)
		for (j = 0;j < n1;j++)
		{
			if (!check(map1, i, j))
				continue;
			if (j < n1 - 2 && check(map1, i, j + 1) && check(map1, i, j + 2))
			{
				//��⵽�˳�����
				//���ϻ�����
				if (i > 0 && (check(map1, i - 1, j) || check(map1, i - 1, j + 2)) && !check(map1, i - 1, j + 1))
				{
					*MatAt(map2, 2 * i - 1, 2 * j + 2) = 1;
					*MatAt(map2, 2 * i - 1, 2 * j + 3) = 1;
				}
				//���»�����
				if (i < n1 - 1 && (check(map1, i + 1, j) || check(map1, i + 1, j + 2)) && !check(map1, i + 1, j + 1))
				{
					*MatAt(map2, 2 * i + 2, 2 * j + 2) = 1;
					*MatAt(map2, 2 * i + 2, 2 * j + 3) = 1;
				}
			}
			if (i < n1 - 2 && check(map1, i + 1, j) && check(map1, i + 2, j))
			{
				//��⵽�˳�����
				//���ϻ�����
				if (j > 0 && (check(map1, i, j - 1) || check(map1, i + 2, j - 1)) && !check(map1, i + 1, j - 1))
				{
					*MatAt(map2, 2 * i + 2, 2 * j - 1) = 1;
					*MatAt(map2, 2 * i + 3, 2 * j - 1) = 1;
				}
				//���ϻ�����
				if (j < n1 - 1 && (check(map1, i, j + 1) || check(map1, i + 2, j + 1)) && !check(map1, i + 1, j + 1))
				{
					*MatAt(map2, 2 * i + 2, 2 * j + 2) = 1;
					*MatAt(map2, 2 * i + 3, 2 * j + 2) = 1;
				}
			}
		}
}

void CcgProjectDlg::OnBnClickedButtoncreatedotfont()
{
	FILE *HZK, *fp;
	if ((HZK = fopen("HZK24", "rb")) == NULL)
		MessageBox(_T("HZK24�ֿ��ȡʧ�ܣ�"));
	else
	{
		//����Ϊ�ֿ��ļ�
		if ((fp = fopen("mydotfont.bin", "wb")) == NULL)
			MessageBox(_T("mydotfont.binд��ʧ�ܣ�"));
		else
		{
			// ��ȡ�ı������ݣ����ɵ����ֿ�
			CString str;
			GetDlgItem(IDC_EDITcontent)->GetWindowText(str);
			//Unicode�ַ�תΪ���ֽ��ַ�
			int nLength = str.GetLength();
			int nBytes = WideCharToMultiByte(CP_ACP, 0, str, nLength, NULL, 0, NULL, NULL);
			char* ch = new char[nBytes + 1];
			memset(ch, 0, sizeof(ch));
			WideCharToMultiByte(CP_OEMCP, 0, str, nLength, ch, nBytes, NULL, NULL);
			ch[nBytes] = 0;

			int i, j, k;
			unsigned char bitmap[24][3];
			char chinese[3];
			//���ദ��5������
			int chcount = nBytes / 2;
			if (chcount > 5)
				chcount = 5;
			//������ʾ�ľ���
			cv::Mat disp(24, 24 * chcount, CV_8U, cv::Scalar(0));
			for (int t = 0;t < chcount;t++)
			{
				memset(chinese, 0, sizeof(chinese));
				chinese[0] = ch[2 * t];
				chinese[1] = ch[2 * t + 1];
				//���������λ��
				i = (unsigned char)chinese[0] - 0xa0, j = (unsigned char)chinese[1] - 0xa0;
				fseek(HZK, (94 * (i - 1) + (j - 1)) * 72L, SEEK_SET);
				fread(bitmap, 72, 1, HZK);
				for (i = 0;i < 24;i++)
					for (j = 0;j < 3;j++)
						for (k = 0;k < 8;k++)
							if (bitmap[i][j] & (0x80 >> k))
								//����Ϊ1��λ����Ϊ1
								*MatAt(disp, i, 24*t+j * 8 + k) = 1;
				fwrite(bitmap, 72, 1, fp);
			}
			//��ʾ���֣�1*255Ϊ��ɫ
			cvDestroyAllWindows();
			cvNamedWindow("DisplayDotFont");
			cv::imshow("DisplayDotFont", 255 * disp);
		}
		fclose(HZK);
		fclose(fp);
	}
}


void CcgProjectDlg::OnBnClickedButtondisp1x()
{
	// �����ֿ�1X��ʾ
	int i, j, k, chcount;
	unsigned char bitmap[24][3];
	FILE *fp;
	if ((fp = fopen("mydotfont.bin", "rb")) == NULL)
		MessageBox(_T("mydotfont.bin��ȡʧ�ܣ��������ɵ����ֿ⣡"));
	else
	{
		fseek(fp, 0, SEEK_END);
		chcount = ftell(fp) / 72;
		fseek(fp, 0, SEEK_SET);
		cv::Mat map(24, 24 * chcount, CV_8U, cv::Scalar(0));
		for (int t = 0;t < chcount;t++)
		{
			fread(bitmap, 72, 1, fp);
			for (i = 0;i < 24;i++)
				for (j = 0;j < 3;j++)
					for (k = 0;k < 8;k++)
						if (bitmap[i][j] & (0x80 >> k))
							//����Ϊ1��λ����Ϊ1
							*MatAt(map, i, 24 * t + j * 8 + k) = 1;
			//��ʾ���֣�1*255Ϊ��ɫ
			cvDestroyAllWindows();
			cvNamedWindow("DisplayDotFont");
			cv::imshow("DisplayDotFont", 255 * map);
		}
		fclose(fp);
	}
}

void CcgProjectDlg::OnBnClickedButtondisp2x()
{
	// �����ֿ�2X��ʾ
	int i, j, k, chcount;
	unsigned char bitmap[24][3];
	FILE *fp;
	if ((fp = fopen("mydotfont.bin", "rb")) == NULL)
		MessageBox(_T("mydotfont.bin��ȡʧ�ܣ��������ɵ����ֿ⣡"));
	else
	{
		fseek(fp, 0, SEEK_END);
		chcount = ftell(fp) / 72;
		fseek(fp, 0, SEEK_SET);
		cv::Mat dispall(48, 48 * chcount, CV_8U, cv::Scalar(0));
		for (int t = 0;t < chcount;t++)
		{
			cv::Mat map1(24, 24, CV_8U, cv::Scalar(0));
			cv::Mat map2(48, 48, CV_8U, cv::Scalar(0));
			fread(bitmap, 72, 1, fp);
			for (i = 0;i < 24;i++)
				for (j = 0;j < 3;j++)
					for (k = 0;k < 8;k++)
						if (bitmap[i][j] & (0x80 >> k))
							//����Ϊ1��λ����Ϊ1
							*MatAt(map1, i, j * 8 + k) = 1;
			//�Ŵ�Ϊ2X
			for (i = 0;i < 24;i++)
				for (j = 0;j < 24;j++)
				{
					if (check(map1, i, j))
					{
						*MatAt(map2, 2 * i, 2 * j) = 1;
						*MatAt(map2, 2 * i, 2 * j + 1) = 1;
						*MatAt(map2, 2 * i + 1, 2 * j) = 1;
						*MatAt(map2, 2 * i + 1, 2 * j + 1) = 1;
					}
				}
			//����Բ��
			MatSmooth(map1, map2);

			cv::Mat disp(255 * map2);
			//ģ��ƽ��
			//for (i = 1;i < 47;i++)
			//	for (j = 1;j < 47;j++)
			//	{
			//		int temp = *MatAt(disp, i, j) * 4 + *MatAt(disp, i + 1, j) * 1 + *MatAt(disp, i, j + 1) * 1 + *MatAt(disp, i - 1, j) * 1 + *MatAt(disp, i, j - 1) * 1;
			//		*MatAt(disp, i, j) = round(float(temp) / float(8));
			//	}
			for (i = 0;i < 48;i++)
				for (j = 0;j < 48;j++)
					*MatAt(dispall, i, 48 * t + j) = *MatAt(disp, i, j);
			
		}
		cvDestroyAllWindows();
		cvNamedWindow("DisplayDotFont");
		cv::imshow("DisplayDotFont", dispall);

		fclose(fp);
	}
}


void CcgProjectDlg::OnBnClickedButtondisp4x()
{
	// �����ֿ�4X��ʾ
	int i, j, k, chcount;
	unsigned char bitmap[24][3];
	FILE *fp;
	if ((fp = fopen("mydotfont.bin", "rb")) == NULL)
		MessageBox(_T("mydotfont.bin��ȡʧ�ܣ��������ɵ����ֿ⣡"));
	else
	{
		fseek(fp, 0, SEEK_END);
		chcount = ftell(fp) / 72;
		fseek(fp, 0, SEEK_SET);
		cv::Mat dispall(96, 96 * chcount, CV_8U, cv::Scalar(0));
		for (int t = 0;t < chcount;t++)
		{
			cv::Mat map1(24, 24, CV_8U, cv::Scalar(0));
			cv::Mat map2(48, 48, CV_8U, cv::Scalar(0));
			cv::Mat map3(96, 96, CV_8U, cv::Scalar(0));
			fread(bitmap, 72, 1, fp);
			for (i = 0;i < 24;i++)
				for (j = 0;j < 3;j++)
					for (k = 0;k < 8;k++)
						if (bitmap[i][j] & (0x80 >> k))
							//����Ϊ1��λ����Ϊ1
							*MatAt(map1, i, j * 8 + k) = 1;
			//�Ŵ�Ϊ2X
			for (i = 0;i < 24;i++)
				for (j = 0;j < 24;j++)
				{
					if (check(map1, i, j))
					{
						*MatAt(map2, 2 * i, 2 * j) = 1;
						*MatAt(map2, 2 * i, 2 * j + 1) = 1;
						*MatAt(map2, 2 * i + 1, 2 * j) = 1;
						*MatAt(map2, 2 * i + 1, 2 * j + 1) = 1;
					}
				}
			//����Բ��
			MatSmooth(map1, map2);
			//�Ŵ�Ϊ4X
			for (i = 0;i < 48;i++)
				for (j = 0;j < 48;j++)
				{
					if (check(map2, i, j))
					{
						*MatAt(map3, 2 * i, 2 * j) = 1;
						*MatAt(map3, 2 * i, 2 * j + 1) = 1;
						*MatAt(map3, 2 * i + 1, 2 * j) = 1;
						*MatAt(map3, 2 * i + 1, 2 * j + 1) = 1;
					}
				}
			//����Բ��
			MatSmooth(map2, map3);

			cv::Mat disp(255 * map3);
			//ģ��ƽ��
			//for (i = 1;i < 95;i++)
			//	for (j = 1;j < 95;j++)
			//	{
			//		int temp = *MatAt(disp, i, j) * 4 + *MatAt(disp, i + 1, j) * 1 + *MatAt(disp, i, j + 1) * 1 + *MatAt(disp, i - 1, j) * 1 + *MatAt(disp, i, j - 1) * 1;
			//		*MatAt(disp, i, j) = round(float(temp) / float(8));
			//	}
			for (i = 0;i < 96;i++)
				for (j = 0;j < 96;j++)
					*MatAt(dispall, i, 96 * t + j) = *MatAt(disp, i, j);
		}
		cvDestroyAllWindows();
		cvNamedWindow("DisplayDotFont");
		cv::imshow("DisplayDotFont", dispall);

		fclose(fp);
	}
}

//�ֹ�ֱ����ϱ�Ե
void find_edge(int event, int x, int y, int flags, void* ustc)
{
	CcgProjectDlg* ptr = (CcgProjectDlg*)ustc;
	if (event == CV_EVENT_LBUTTONDOWN)
	{
		CvPoint pt = cvPoint(x, y);
		ptr->keydots[ptr->keydotcnt][0] = x;
		ptr->keydots[ptr->keydotcnt][1] = y;
		cvCircle(ptr->edge, pt, 2, cv::Scalar(128), CV_FILLED, CV_AA, 0);
		if (ptr->keydotcnt)
			cvLine(ptr->edge, pt, cvPoint(ptr->keydots[ptr->keydotcnt - 1][0], ptr->keydots[ptr->keydotcnt - 1][1]), cv::Scalar(128), 1);
		cvShowImage("FindEdges", ptr->edge);
		

		if (ptr->keydotcnt && (ptr->keydots[ptr->keydotcnt][0] - ptr->keydots[0][0])*(ptr->keydots[ptr->keydotcnt][0] - ptr->keydots[0][0]) +
			(ptr->keydots[ptr->keydotcnt][1] - ptr->keydots[0][1])*(ptr->keydots[ptr->keydotcnt][1] - ptr->keydots[0][1]) <= 4)
		{
			//���һ����͵�һ�����㹻��ʱ����Ϊ������ͬһ����
			ptr->keydots[ptr->keydotcnt][1] = ptr->keydots[0][1];
			ptr->keydots[ptr->keydotcnt][0] = ptr->keydots[0][0];
			FILE *fp;
			if ((fp = fopen("myvectorfont.bin", "ab")))
			{
				ptr->keydotcnt++;
				fwrite(&(ptr->keydotcnt), sizeof(int), 1, fp);
				fwrite(ptr->keydots, sizeof(int), (ptr->keydotcnt) * 2, fp);
				ptr->keydotcnt = 0;
				fclose(fp);
			}
		}
		else
			ptr->keydotcnt++;
	}
}

void CcgProjectDlg::OnBnClickedButtoncreatevector()
{
	// ����ʸ���ֿ� ����Ϊ�ֿ��ļ�
	FILE *fp;
	if ((fp = fopen("myvectorfont.bin", "wb")) == NULL)
		MessageBox(_T("myvectorfont.binд��ʧ�ܣ�"));
	else
	{
		// ��ȡͼƬ���ݣ����ɵ����ֿ�
		CString pathstr;
		GetDlgItemText(IDC_MFCEDITBROWSE1, pathstr);
		//Unicode�ַ�תΪ���ֽ��ַ�
		int nLength = pathstr.GetLength();
		if (!nLength)
		{
			MessageBox(_T("��ѡ��ͼƬ�ļ���"));
			return;
		}
		int nBytes = WideCharToMultiByte(CP_ACP, 0, pathstr, nLength, NULL, 0, NULL, NULL);
		char* ch = new char[nBytes + 1];
		memset(ch, 0, sizeof(ch));
		WideCharToMultiByte(CP_OEMCP, 0, pathstr, nLength, ch, nBytes, NULL, NULL);
		ch[nBytes] = 0;
		IplImage* img;
		img = cvLoadImage(ch,1);
		delete[]ch;

		//��Ե���
		edge = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
		cvCanny(img, edge, 10, 150, 3);
		//����
		keydotcnt = 0;
		cvDestroyAllWindows();
		cvNamedWindow("FindEdges", 1);
		cvSetMouseCallback("FindEdges", find_edge, this);
		cvShowImage("FindEdges", edge);


		cvReleaseImage(&img);

		fclose(fp);

	}
}

void CcgProjectDlg::OnBnClickedButtoncreatevectorauto()
{
	// ����ʸ���ֿ� ����Ϊ�ֿ��ļ�
	FILE *fp;
	if ((fp = fopen("myvectorfont.bin", "wb")) == NULL)
		MessageBox(_T("myvectorfont.binд��ʧ�ܣ�"));
	else
	{
		// ��ȡͼƬ���ݣ����ɵ����ֿ�
		CString pathstr;
		GetDlgItemText(IDC_MFCEDITBROWSE1, pathstr);
		//Unicode�ַ�תΪ���ֽ��ַ�
		int nLength = pathstr.GetLength();
		if (!nLength)
		{
			MessageBox(_T("��ѡ��ͼƬ�ļ���"));
			return;
		}
		int nBytes = WideCharToMultiByte(CP_ACP, 0, pathstr, nLength, NULL, 0, NULL, NULL);
		char* ch = new char[nBytes + 1];
		memset(ch, 0, sizeof(ch));
		WideCharToMultiByte(CP_OEMCP, 0, pathstr, nLength, ch, nBytes, NULL, NULL);
		ch[nBytes] = 0;
		
		//����ͼƬ������
		cv::Mat imgmat = cv::imread(ch);
		cv::cvtColor(imgmat, imgmat, CV_BGR2GRAY);
		imgmat = 255 - imgmat;
		//���ұ�Ե
		std::vector<std::vector<cv::Point>> *contours = new std::vector<std::vector<cv::Point>>;
		contours->clear();
		cv::findContours(imgmat, *contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
		// draw 
		cv::Mat result(imgmat.size(), CV_8U, cv::Scalar(0));
		//cv::drawContours(result, *contours, -1, cv::Scalar(255), 1);

		// ������ʾΪһ�������
		std::vector<cv::Point> *poly=new std::vector<cv::Point>;
		for (int i = 0;i < contours->size();++i)
		{
			poly->clear();
			keydotcnt = 0;
			cv::approxPolyDP(cv::Mat((*contours)[i]), *poly, m_SLIDERepsilon.GetPos(), true);
			std::vector<cv::Point>::const_iterator itp = poly->begin();
			while (itp != (poly->end() - 1))
			{
				cv::line(result, *itp, *(itp + 1), cv::Scalar(255), 1);
				keydots[keydotcnt][0] = itp->x;
				keydots[keydotcnt++][1] = itp->y;
				++itp;
			}
			cv::line(result, *itp, *(poly->begin()), cv::Scalar(255), 1);
			keydots[keydotcnt][0] = itp->x;
			keydots[keydotcnt++][1] = itp->y;
			keydots[keydotcnt][0] = poly->begin()->x;
			keydots[keydotcnt++][1] = poly->begin()->y;
			fwrite(&keydotcnt, sizeof(int), 1, fp);
			fwrite(keydots, sizeof(int), 2 * keydotcnt, fp);
		}
		cvDestroyAllWindows();
		cvNamedWindow("AutoFindEdges", 1);
		cv::imshow("AutoFindEdges", result);

		delete poly;
		delete contours;
		fclose(fp);

	}
}

void CcgProjectDlg::OnBnClickedButtonloadvector()
{
	// ����ʸ���ֿ�
	CString pathstr;
	GetDlgItemText(IDC_MFCEDITBROWSE2, pathstr);
	//Unicode�ַ�תΪ���ֽ��ַ�
	int nLength = pathstr.GetLength();
	if (!nLength)
	{
		MessageBox(_T("��ѡ��ʸ���ֿ��ļ���"));
		return;
	}
	int nBytes = WideCharToMultiByte(CP_ACP, 0, pathstr, nLength, NULL, 0, NULL, NULL);
	char* ch = new char[nBytes + 1];
	memset(ch, 0, sizeof(ch));
	WideCharToMultiByte(CP_OEMCP, 0, pathstr, nLength, ch, nBytes, NULL, NULL);
	ch[nBytes] = 0;

	FILE *fp;
	if ((fp = fopen(ch, "rb")) == NULL)
		GetDlgItem(IDC_STATIC8)->SetWindowText(_T("����ʧ�ܣ�"));
	else
	{
		//��ȡÿ���ʻ�
		int cnt;
		edgecnt = 0;
		while (fread(&cnt, sizeof(int), 1, fp))
		{
			edges[edgecnt][0][0] = cnt;
			fread(&edges[edgecnt][1][0], sizeof(int), cnt * 2, fp);
			++edgecnt;
		}
		if (edgecnt)
			GetDlgItem(IDC_STATIC8)->SetWindowText(_T("����ɹ���"));
		else
			GetDlgItem(IDC_STATIC8)->SetWindowText(_T("���ļ������������ֿ⣡"));
		fclose(fp);
	}
	if (ch)
		delete[]ch;
}

void flood_fill(cv::Mat *m, int i0, int j0)
{
	int i, x, y;
	bool spanUp, spanDown;
	//Floodfill�㷨
	std::queue<int> qx, qy;
	qx.push(i0);
	qy.push(j0);
	while (!qx.empty())
	{
		x = qx.front();
		y = qy.front();
		qx.pop();
		qy.pop();
		//���������
		i = y;
		while (i >= 0 && !check(*m, x, i))
			--i;
		++i;
		spanUp = spanDown = false;
		while (i < VECTW && !check(*m, x, i))
		{
			*MatAt(*m, x, i) = 1;
			if (!spanUp && x>0 && !check(*m, x - 1, i))
			{
				qx.push(x - 1);
				qy.push(i);
				spanUp = true;
			}
			else
				if (spanUp && x>0 && check(*m, x - 1, i))
				{
					spanUp = false;
				}
			if (!spanDown && x<VECTH - 1 && !check(*m, x + 1, i))
			{
				qx.push(x + 1);
				qy.push(i);
				spanDown = true;
			}
			else
				if (spanDown && x<VECTH - 1 && check(*m, x + 1, i))
				{
					spanDown = false;
				}
			++i;
		}
	}
}

//�ֹ����ʻ�
//ע��˴�ʹ��cv::Mat���в����������������x y�����õ�j0 i0
void fill_area(int event, int j0, int i0, int flags, void* ustc)
{
	cv::Mat* m = &(((CcgProjectDlg*)ustc)->vecmat);
	if (event == CV_EVENT_LBUTTONDOWN)
	{
		flood_fill(m, i0, j0);
		//��ʾ�����
		cv::imshow("DisplayVectorFont", 255 * *m);
		
	}
}

//Bresenhamֱ�������㷨
void CcgProjectDlg::line_bresenham(cv::Mat &vecmat, CvPoint t1, CvPoint t2)
{
	int dx = t2.x - t1.x, dy = t2.y - t1.y;
	int ux = ((dx > 0) << 1) - 1;//x����������ȡ��-1
	int uy = ((dy > 0) << 1) - 1;//y����������ȡ��-1
	int x = t1.x, y = t1.y, eps;//epsΪ�ۼ����
	
	eps = 0; dx = abs(dx); dy = abs(dy);
	if (dx > dy)
	{
		for (x = t1.x; x != t2.x + ux; x += ux)
		{
			*MatAt(vecmat, y, x) = 1;
			eps += dy;
			if ((eps << 1) >= dx)
			{
				y += uy; eps -= dx;
			}
		}
	}
	else
	{
		for (y = t1.y; y != t2.y + uy; y += uy)
		{
			*MatAt(vecmat, y, x) = 1;
			eps += dx;
			if ((eps << 1) >= dy)
			{
				x += ux; eps -= dy;
			}
		}
	}
}

void CcgProjectDlg::OnBnClickedButtondispvect1()
{
	// ʸ���ֿ�1x��ʾ
	if (!edgecnt)
	{
		MessageBox(_T("��������ʸ���ֿ⣡"));
		return;
	}
	vecmat = cv::Mat(VECTH, VECTW, CV_8U, cv::Scalar(0));
	//vecdisp = IplImage(vecmat);
	for (int i = 0;i < edgecnt;++i)
	{
		int lastx = edges[i][1][0], lasty = edges[i][1][1];
		for (int j = 2;j <= edges[i][0][0];++j)
		{
			line_bresenham(vecmat, CvPoint(lastx, lasty), CvPoint(edges[i][j][0], edges[i][j][1]));
			lastx = edges[i][j][0];
			lasty = edges[i][j][1];
		}
		line_bresenham(vecmat, CvPoint(lastx, lasty), CvPoint(edges[i][1][0], edges[i][1][1]));
	}
	cvDestroyAllWindows();
	cvNamedWindow("DisplayVectorFont", 1);
	//�������
	cvSetMouseCallback("DisplayVectorFont", fill_area, this);
	cv::imshow("DisplayVectorFont",255*vecmat);

}


void CcgProjectDlg::OnBnClickedButtondispvect2()
{
	// ʸ���ֿ�2x��ʾ
	if (!edgecnt)
	{
		MessageBox(_T("��������ʸ���ֿ⣡"));
		return;
	}
	vecmat = cv::Mat(VECTH, VECTW, CV_8U, cv::Scalar(0));
	//vecdisp = IplImage(vecmat);
	for (int i = 0;i < edgecnt;++i)
	{
		int lastx = edges[i][1][0], lasty = edges[i][1][1];
		for (int j = 2;j <= edges[i][0][0];++j)
		{
			line_bresenham(vecmat, CvPoint(2 * lastx, 2 * lasty), CvPoint(2 * edges[i][j][0], 2 * edges[i][j][1]));
			lastx = edges[i][j][0];
			lasty = edges[i][j][1];
		}
		line_bresenham(vecmat, CvPoint(2 * lastx, 2 * lasty), CvPoint(2 * edges[i][1][0], 2 * edges[i][1][1]));
	}
	cvDestroyAllWindows();
	cvNamedWindow("DisplayVectorFont", 1);
	//�������
	cvSetMouseCallback("DisplayVectorFont", fill_area, this);
	cv::imshow("DisplayVectorFont", 255 * vecmat);
}


void CcgProjectDlg::OnBnClickedButtondispvect3()
{
	// ʸ���ֿ�3x��ʾ
	if (!edgecnt)
	{
		MessageBox(_T("��������ʸ���ֿ⣡"));
		return;
	}
	vecmat = cv::Mat(VECTH, VECTW, CV_8U, cv::Scalar(0));
	//vecdisp = IplImage(vecmat);
	for (int i = 0;i < edgecnt;++i)
	{
		int lastx = edges[i][1][0], lasty = edges[i][1][1];
		for (int j = 2;j <= edges[i][0][0];++j)
		{
			line_bresenham(vecmat, CvPoint(3 * lastx, 3 * lasty), CvPoint(3 * edges[i][j][0], 3 * edges[i][j][1]));
			lastx = edges[i][j][0];
			lasty = edges[i][j][1];
		}
		line_bresenham(vecmat, CvPoint(3 * lastx, 3 * lasty), CvPoint(3 * edges[i][1][0], 3 * edges[i][1][1]));
	}
	cvDestroyAllWindows();
	cvNamedWindow("DisplayVectorFont", 1);
	//�������
	cvSetMouseCallback("DisplayVectorFont", fill_area, this);
	cv::imshow("DisplayVectorFont", 255 * vecmat);
}

//OpenCV�������
void CcgProjectDlg::fillcontour(cv::Mat &imgmat)
{
	cv::Mat result(imgmat.size(), CV_8U, cv::Scalar(0));
	imgmat = 255 * imgmat;
	//���ұ�Ե
	std::vector<std::vector<cv::Point>> *contours = new std::vector<std::vector<cv::Point>>;
	std::vector<cv::Vec4i> *hierarchy = new std::vector<cv::Vec4i>;
	cv::findContours(imgmat, *contours, *hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE);
	cv::drawContours(result, *contours, -1, cv::Scalar(255), -1, 8, *hierarchy, 1);
	
	imgmat = result / 255;
}

//ɨ�����������
void TRANSNET(int edges[1][100][2], net** a, int m)
{
	int flag[1000] = {};
	for (int i = 0; i <= m; i++)
		a[i] = NULL;
	net *head;
	net *p1;
	net *p2;
	net *p3;
	net *p_inf;
	//����ÿ���ߵ�����,�����ɨ���ߵķ�Χ
	int max = 0;
	int min = 0;
	edge e[100];
	for (int i = 1; i < edges[0][0][0]; i++)
	{
		e[i].x1 = edges[0][i][0];
		e[i].y1 = edges[0][i][1];
		e[i].x2 = edges[0][i + 1][0];
		e[i].y2 = edges[0][i + 1][1];
	}
	int row = 0;
	for (int i = 1; i < edges[0][0][0]; i++)
	{
		p1 = new net;
		if (e[i].y1 <= e[i].y2)
		{
			row = e[i].y1;
			p1->x = e[i].x1;
			p1->ymax = e[i].y2;
		}
		else
		{
			row = e[i].y2;
			p1->x = e[i].x2;
			p1->ymax = e[i].y1;
		}
		p1->dx = (double)(e[i].x2 - e[i].x1) / (e[i].y2 - e[i].y1);
		p1->next = NULL;
		if (flag[row] == 0)
			head = NULL;
		//��ȫˮƽ�ı߽������Ϊ2����
		if (e[i].y2 == e[i].y1)
		{
			p_inf = new net;
			p_inf->dx = p1->dx;
			p_inf->x = p1->x;
			p_inf->ymax = p1->ymax;
			p_inf->next = p1;
			if (head == NULL)
			{
				head = p_inf;
				flag[row] = 1;
				p2 = p1;
				a[row] = head;
			}
			else
			{
				p2 = a[row];
				p3 = a[row];
				while (p2 != NULL && (p1->x > p2->x))
				{
					p3 = p2;
					p2 = p2->next;
				}
				p1->next = p2;
				if (p3 == NULL || p2 == p3)
					a[row] = p_inf;
				else
					p3->next = p_inf;
			}
		}
		else
		{
			if (head == NULL)
			{
				head = p1;
				flag[row] = 1;
				p2 = p1;
				a[row] = head;
			}
			else
			{
				p2 = a[row];
				p3 = a[row];
				while (p2 != NULL && (p1->x > p2->x))
				{
					p3 = p2;
					p2 = p2->next;
				}
				p1->next = p2;
				if (p3 == NULL || p2 == p3)
					a[row] = p1;
				else
					p3->next = p1;
			}
		}
	}
}

void TRANSAET(net** a, int m)
{
	for (int i = 0; i <= m; i++)
	{
		net *search;
		search = a[i];
		while (search != NULL)
		{
			double x0 = search->x;
			for (int j = i + 1; j < search->ymax; j++)
			{
				net* p1;
				net* p2;
				net* p3;
				p1 = new net;//(net*)malloc(sizeof(net));
				x0 = x0 + search->dx;
				p1->x = x0;
				p1->dx = search->dx;
				p1->ymax = search->ymax;
				//��p1����������λ��
				p2 = a[j];
				p3 = a[j];
				while (p2 != NULL && (p1->x > p2->x))
				{
					p3 = p2;
					p2 = p2->next;
				}
				int same = 0;
				if (p2 != NULL)
				{
					if (p1->dx == p2->dx&&p1->x == p2->x&&p1->ymax == p2->ymax)
						same = 1;
				}
				if (p3 != NULL)
				{
					if (p1->dx == p3->dx&&p1->x == p3->x&&p1->ymax == p3->ymax)
						same = 1;
				}
				if (same == 0)
				{
					p1->next = p2;
					if (p3 == NULL || p2 == p3)
						a[j] = p1;
					else
						p3->next = p1;
				}
			}
			search = search->next;
		}
	}
}

void CcgProjectDlg::OnBnClickedButtonvectfill()
{
	// �Զ����ʵ����
	if (!edgecnt)
	{
		MessageBox(_T("��������ʸ���ֿ⣡"));
		return;
	}
	
	//OnBnClickedButtondispvect3();
	//fillcontour(vecmat);
	//ɨ��������㷨
	vecmat = cv::Mat(VECTH, VECTW, CV_8U, cv::Scalar(0));

	for (int n = 0; n < edgecnt; n++)//��ÿ����·����ɨ�裬���
	{
		if (edges[n][0][0] < 4)
			continue;
		int EDGES[1][100][2];
		for (int i1 = 0; i1 < 100; i1++)
			for (int i2 = 0; i2 < 2; i2++)
				if (i1 != 0)
					EDGES[0][i1][i2] = edges[n][i1][1 - i2] * 3;
				else
					EDGES[0][i1][i2] = edges[n][i1][i2];
		int max = EDGES[0][1][1];
		int min = EDGES[0][1][1];
		for (int i1 = 1; i1 <= EDGES[0][0][0]; i1++)
		{
			if (EDGES[0][i1][1] > max)
				max = EDGES[0][i1][1];
			if (EDGES[0][i1][1] < min)
				min = EDGES[0][i1][1];
		}
		net** NET = new net*[max + 1];
		TRANSNET(EDGES, NET, max);
		TRANSAET(NET, max);
		for (int j = 0; j < max; j++)
		{
			net* search;
			search = NET[j];
			while (search != NULL)
			{
				int start, end;
				start = search->x;
				search = search->next;
				end = search->x;
				for (int k = start + 1; k < end; k++)
					*MatAt(vecmat, k, j) = 1 - *MatAt(vecmat, k, j);
				search = search->next;
			}
		}
	}

	cvDestroyAllWindows();
	cvNamedWindow("DisplayVectorFont", 1);
	cv::imshow("DisplayVectorFont", 255 * vecmat);

}


void CcgProjectDlg::OnBnClickedButton1()
{
	// ���ڶԻ���
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


void CcgProjectDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	cvDestroyAllWindows();
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}

//�������ʽ��ϵ��C(nn,k)  
double CcgProjectDlg::CalcCoeff(int nn, int k)
{
	int i;
	double sum = 1;
	for (i = 1; i <= k; i++)
		sum = sum * (nn - i + 1) / i;
	return sum;
}
//����Bezier�����ϵ������
void CcgProjectDlg::DrawBezierPoint(cv::Mat &vecmat, int points[][2],double t, int n)
{
	double x = 0, y = 0, Ber;
	int k;
	for (k = 0;k < n;k++)
	{
		Ber = CalcCoeff(n - 1, k)*pow(t, k)*pow(1 - t, n - 1 - k);
		x += points[k][0]*Ber;
		y += points[k][1]*Ber;
	}
	*MatAt(vecmat, int(y), int(x) ) = 1;
}
//���ݿ��Ƶ㣬�������ϵ�m����
void CcgProjectDlg::DrawBezier(cv::Mat &vecmat, int points[][2], int n)
{
	int m = 500, i;
	for (i = 0;i <= m;i++)
		DrawBezierPoint(vecmat, points, (double)i / (double)m, n);
}



void CcgProjectDlg::OnBnClickedButtondispvectb1()
{
	// Bezier�����ֿ�1x��ʾ
	const int step = 80;
	vecmat = cv::Mat(VECTH, VECTW, CV_8U, cv::Scalar(0));
	cv::Point brush, brush_new, origin(0, step);
	
	int (*points)[2];
	short x, y, x0, y0;
	short type, dotnum;

	FILE *fp;
	if ((fp = fopen("mybezierfont.bin", "rb")) == NULL)
		MessageBox(_T("mybezierfont.bin��ȡʧ�ܣ�"));
	else
	{
		fread(&x, sizeof(short), 1, fp);
		while (x != short(-3))
		{
			//�ֿ�δ����
			if (x == short(-2))
			{
				//��һ������
				origin.x += step;
				if (origin.x > VECTW - step)
				{
					origin.x = 0;
					origin.y += step;
				}
				fread(&x, sizeof(short), 1, fp);
				continue;
			}
			fread(&y, sizeof(short), 1, fp);
			x0 = x;   y0 = y;

			brush = cv::Point(origin.x + x0, origin.y - y0);

			fread(&type, sizeof(short), 1, fp);
			
			while (type != -1)
			{
				fread(&dotnum, sizeof(short), 1, fp);
				switch (type)
				{
				case TT_PRIM_LINE:
					for (int i = 0; i < dotnum; ++i)
					{
						fread(&x, sizeof(short), 1, fp);
						fread(&y, sizeof(short), 1, fp);
						brush_new = cv::Point(origin.x + x, origin.y - y);
						line_bresenham(vecmat, brush, brush_new);
						brush = brush_new;
					}
					break;
				case TT_PRIM_QSPLINE:
				case TT_PRIM_CSPLINE:
					points = new int[dotnum + 1][2];
					points[0][0] = brush.x;
					points[0][1] = brush.y;
					for (int i = 0; i < dotnum; ++i)
					{
						fread(&x, sizeof(short), 1, fp);
						fread(&y, sizeof(short), 1, fp);
						points[i + 1][0] = origin.x + x;
						points[i + 1][1] = origin.y - y;
					}
					DrawBezier(vecmat, points, dotnum + 1);
					delete[]points;
					brush = cv::Point(origin.x + x, origin.y - y);

					break;
				}
				fread(&type, sizeof(short), 1, fp);
			}
			line_bresenham(vecmat, brush, cv::Point(origin.x + x0, origin.y - y0));
			fread(&x, sizeof(short), 1, fp);
		}
		fclose(fp);
	}
	cvDestroyAllWindows();
	cvNamedWindow("DisplayVectorFont", 1);
	//�������
	cvSetMouseCallback("DisplayVectorFont", fill_area, this);
	cv::imshow("DisplayVectorFont", 255 * vecmat);
}


void CcgProjectDlg::OnBnClickedButtondispvectb2()
{
	// Bezier�����ֿ�2x��ʾ
	const int step = 160;
	vecmat = cv::Mat(VECTH, VECTW, CV_8U, cv::Scalar(0));
	cv::Point brush, brush_new, origin(0, step);

	int(*points)[2];
	short x, y, x0, y0;
	short type, dotnum;

	FILE *fp;
	if ((fp = fopen("mybezierfont.bin", "rb")) == NULL)
		MessageBox(_T("mybezierfont.bin��ȡʧ�ܣ�"));
	else
	{
		fread(&x, sizeof(short), 1, fp);
		while (x != short(-3))
		{
			//�ֿ�δ����
			if (x == short(-2))
			{
				//��һ������
				origin.x += step;
				if (origin.x > VECTW - step)
				{
					origin.x = 0;
					origin.y += step;
				}
				fread(&x, sizeof(short), 1, fp);
				continue;
			}
			fread(&y, sizeof(short), 1, fp);
			x0 = x;   y0 = y;

			brush = cv::Point(origin.x + x0 * 2, origin.y - y0 * 2);

			fread(&type, sizeof(short), 1, fp);

			while (type != -1)
			{
				fread(&dotnum, sizeof(short), 1, fp);
				switch (type)
				{
				case TT_PRIM_LINE:
					for (int i = 0; i < dotnum; ++i)
					{
						fread(&x, sizeof(short), 1, fp);
						fread(&y, sizeof(short), 1, fp);
						brush_new = cv::Point(origin.x + x * 2, origin.y - y * 2);
						line_bresenham(vecmat, brush, brush_new);
						brush = brush_new;
					}
					break;
				case TT_PRIM_QSPLINE:
				case TT_PRIM_CSPLINE:
					points = new int[dotnum + 1][2];
					points[0][0] = brush.x;
					points[0][1] = brush.y;
					for (int i = 0; i < dotnum; ++i)
					{
						fread(&x, sizeof(short), 1, fp);
						fread(&y, sizeof(short), 1, fp);
						points[i + 1][0] = origin.x + x * 2;
						points[i + 1][1] = origin.y - y * 2;
					}
					DrawBezier(vecmat, points, dotnum + 1);
					delete[]points;
					brush = cv::Point(origin.x + x * 2, origin.y - y * 2);

					break;
				}
				fread(&type, sizeof(short), 1, fp);
			}
			line_bresenham(vecmat, brush, cv::Point(origin.x + x0 * 2, origin.y - y0 * 2));
			fread(&x, sizeof(short), 1, fp);
		}
		fclose(fp);
	}
	cvDestroyAllWindows();
	cvNamedWindow("DisplayVectorFont", 1);
	//�������
	cvSetMouseCallback("DisplayVectorFont", fill_area, this);
	cv::imshow("DisplayVectorFont", 255 * vecmat);
}

void CcgProjectDlg::OnBnClickedButtondispvectb3()
{
	// Bezier�����ֿ�3x��ʾ
	const int step = 240;
	vecmat = cv::Mat(VECTH, VECTW, CV_8U, cv::Scalar(0));
	cv::Point brush, brush_new, origin(0, step);

	int(*points)[2];
	short x, y, x0, y0;
	short type, dotnum;

	FILE *fp;
	if ((fp = fopen("mybezierfont.bin", "rb")) == NULL)
		MessageBox(_T("mybezierfont.bin��ȡʧ�ܣ�"));
	else
	{
		fread(&x, sizeof(short), 1, fp);
		while (x != short(-3))
		{
			//�ֿ�δ����
			if (x == short(-2))
			{
				//��һ������
				origin.x += step;
				if (origin.x > VECTW - step)
				{
					origin.x = 0;
					origin.y += step;
				}
				fread(&x, sizeof(short), 1, fp);
				continue;
			}
			fread(&y, sizeof(short), 1, fp);
			x0 = x;   y0 = y;

			brush = cv::Point(origin.x + x0 * 3, origin.y - y0 * 3);

			fread(&type, sizeof(short), 1, fp);

			while (type != -1)
			{
				fread(&dotnum, sizeof(short), 1, fp);
				switch (type)
				{
				case TT_PRIM_LINE:
					for (int i = 0; i < dotnum; ++i)
					{
						fread(&x, sizeof(short), 1, fp);
						fread(&y, sizeof(short), 1, fp);
						brush_new = cv::Point(origin.x + x * 3, origin.y - y * 3);
						line_bresenham(vecmat, brush, brush_new);
						brush = brush_new;
					}
					break;
				case TT_PRIM_QSPLINE:
				case TT_PRIM_CSPLINE:
					points = new int[dotnum + 1][2];
					points[0][0] = brush.x;
					points[0][1] = brush.y;
					for (int i = 0; i < dotnum; ++i)
					{
						fread(&x, sizeof(short), 1, fp);
						fread(&y, sizeof(short), 1, fp);
						points[i + 1][0] = origin.x + x * 3;
						points[i + 1][1] = origin.y - y * 3;
					}
					DrawBezier(vecmat, points, dotnum + 1);
					delete[]points;
					brush = cv::Point(origin.x + x * 3, origin.y - y * 3);

					break;
				}
				fread(&type, sizeof(short), 1, fp);
			}
			line_bresenham(vecmat, brush, cv::Point(origin.x + x0 * 3, origin.y - y0 * 3));
			fread(&x, sizeof(short), 1, fp);
		}
		fclose(fp);
	}
	cvDestroyAllWindows();
	cvNamedWindow("DisplayVectorFont", 1);
	//�������
	cvSetMouseCallback("DisplayVectorFont", fill_area, this);
	cv::imshow("DisplayVectorFont", 255 * vecmat);
}


void CcgProjectDlg::OnBnClickedButtoncreatebfont()
{
	// ����Bezier�����ֿ�
	FILE *fp;
	short temp = -2;
	// ��ȡ�ı�������
	CString str;
	GetDlgItem(IDC_EDITcontentB)->GetWindowText(str);
	if (!str.GetLength())
	{
		MessageBox(_T("�������ֿ����ݣ�"));
		return;
	}
	if ((fp = fopen("mybezierfont.bin", "wb")) == NULL)
		MessageBox(_T("mybezierfont.binд��ʧ�ܣ�"));
	else
	{
		CClientDC dc(this);

		for (int t = 0;t < str.GetLength();t++)
		{
			LOGFONT logfont;
			memset(&logfont, 0, sizeof(LOGFONT));
			logfont.lfHeight = 65;
			logfont.lfCharSet = GB2312_CHARSET;
			CString fontname;
			GetDlgItemText(IDC_COMBOFONT, fontname);
			_tcscpy(logfont.lfFaceName, fontname);
			CFont font;
			font.CreateFontIndirect(&logfont);
			CFont* pOldFont = dc.SelectObject(&font);
			MAT2 mat2 = { { 0,1 },{ 0,0 },{ 0,0 },{ 0,1 } };
			POINT buffer[1024];
			GLYPHMETRICS gm;

			wchar_t thisChar = str[t];
			DWORD returnBytes = GetGlyphOutlineW(dc.GetSafeHdc(), thisChar, GGO_BEZIER, &gm, sizeof(buffer), buffer, &mat2);
			if (returnBytes != GDI_ERROR)
			{
				TTPOLYGONHEADER* pTTPH = (TTPOLYGONHEADER*)buffer;
				_ASSERTE(pTTPH->dwType == TT_POLYGON_TYPE);
				//�Ապ�·������ѭ��
				while (returnBytes > 0)
				{
					fwrite(&pTTPH->pfxStart.x.value, sizeof(short), 1, fp);
					fwrite(&pTTPH->pfxStart.y.value, sizeof(short), 1, fp);
					TTPOLYCURVE* pCurrentCurve = (TTPOLYCURVE*)(pTTPH + 1);
					int remainBytes = pTTPH->cb - sizeof(TTPOLYGONHEADER);
					while (remainBytes > 0)
					{
						fwrite(&pCurrentCurve->wType, sizeof(short), 1, fp);
						fwrite(&pCurrentCurve->cpfx, sizeof(short), 1, fp);

						for (int i = 0; i < pCurrentCurve->cpfx; ++i)
						{
							fwrite(&pCurrentCurve->apfx[i].x.value, sizeof(short), 1, fp);
							fwrite(&pCurrentCurve->apfx[i].y.value, sizeof(short), 1, fp);
						}

						int count = sizeof(TTPOLYCURVE) + (pCurrentCurve->cpfx - 1)*sizeof(POINTFX);
						pCurrentCurve = (TTPOLYCURVE*)((char*)pCurrentCurve + count);
						remainBytes -= count;
					}
					temp = -1;
					fwrite(&temp, sizeof(short), 1, fp);
					returnBytes -= pTTPH->cb;
					pTTPH = (TTPOLYGONHEADER*)((char*)pTTPH + pTTPH->cb);
				}
			}
			dc.SelectObject(pOldFont);
			temp = -2;
			fwrite(&temp, sizeof(short), 1, fp);
		}
		temp = -3;
		fwrite(&temp, sizeof(short), 1, fp);
		fclose(fp);
	}
}

void CcgProjectDlg::OnBnClickedButtonvectfillb()
{
	// �Զ����ʵ����
	OnBnClickedButtondispvectb3();
	fillcontour(vecmat);
	cvDestroyAllWindows();
	cvNamedWindow("DisplayVectorFont", 1);
	cv::imshow("DisplayVectorFont", 255 * vecmat);
}

void CcgProjectDlg::OnBnClickedButtonteapot()
{
	//���Ʋ��
	CButton *pBtnTeapot = (CButton *)GetDlgItem(IDC_BUTTONteapot);
	CButton *pBtn3DText = (CButton *)GetDlgItem(IDC_BUTTON3Dtext);
	CButton *pBtn3DTextT = (CButton *)GetDlgItem(IDC_BUTTON3Dtexttexture);
	if (pBtnTeapot != NULL)
	{
		pBtnTeapot->EnableWindow(false);
	}
	if (pBtn3DText != NULL)
	{
		pBtn3DText->EnableWindow(false);
	}
	if (pBtn3DTextT != NULL)
	{
		pBtn3DTextT->EnableWindow(false);
	}
	
	change_model(this, TEAPOT, true);
	plot3d();

	if (pBtnTeapot != NULL)
	{
		pBtnTeapot->EnableWindow(true);
	}
	if (pBtn3DText != NULL)
	{
		pBtn3DText->EnableWindow(true);
	}
	if (pBtn3DTextT != NULL)
	{
		pBtn3DTextT->EnableWindow(true);
	}
}

void CcgProjectDlg::OnBnClickedButton3dtext()
{
	if (!edgecnt)
	{
		MessageBox(_T("��������ʸ���ֿ⣡"));
		return;
	}
	// ������ά����
	CButton *pBtnTeapot = (CButton *)GetDlgItem(IDC_BUTTONteapot);
	CButton *pBtn3DText = (CButton *)GetDlgItem(IDC_BUTTON3Dtext);
	CButton *pBtn3DTextT = (CButton *)GetDlgItem(IDC_BUTTON3Dtexttexture);
	if (pBtnTeapot != NULL)
	{
		pBtnTeapot->EnableWindow(false);
	}
	if (pBtn3DText != NULL)
	{
		pBtn3DText->EnableWindow(false);
	}
	if (pBtn3DTextT != NULL)
	{
		pBtn3DTextT->EnableWindow(false);
	}

	if (((CButton *)GetDlgItem(IDC_RADIOauto))->GetCheck())
		change_model(this, TEXT, false);
	else
		change_model(this, TEXT, true);
	plot3d();
	
	if (pBtnTeapot != NULL)
	{
		pBtnTeapot->EnableWindow(true);
	}
	if (pBtn3DText != NULL)
	{
		pBtn3DText->EnableWindow(true);
	}
	if (pBtn3DTextT != NULL)
	{
		pBtn3DTextT->EnableWindow(true);
	}
}




void CcgProjectDlg::OnBnClickedButton3dtexttexture()
{
	// ������ά��������
	if (!edgecnt)
	{
		MessageBox(_T("��������ʸ���ֿ⣡"));
		return;
	}
	CButton *pBtnTeapot = (CButton *)GetDlgItem(IDC_BUTTONteapot);
	CButton *pBtn3DText = (CButton *)GetDlgItem(IDC_BUTTON3Dtext);
	CButton *pBtn3DTextT = (CButton *)GetDlgItem(IDC_BUTTON3Dtexttexture);
	if (pBtnTeapot != NULL)
	{
		pBtnTeapot->EnableWindow(false);
	}
	if (pBtn3DText != NULL)
	{
		pBtn3DText->EnableWindow(false);
	}
	if (pBtn3DTextT != NULL)
	{
		pBtn3DTextT->EnableWindow(false);
	}

	if (((CButton *)GetDlgItem(IDC_RADIOauto))->GetCheck())
		change_model(this, TEXTURE, false);
	else
		change_model(this, TEXTURE, true);
	plot3d();

	if (pBtnTeapot != NULL)
	{
		pBtnTeapot->EnableWindow(true);
	}
	if (pBtn3DText != NULL)
	{
		pBtn3DText->EnableWindow(true);
	}
	if (pBtn3DTextT != NULL)
	{
		pBtn3DTextT->EnableWindow(true);
	}
}
