


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ԥ����
#pragma once
#include <Windows.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �궨��
#define _Lang(n, a)				CLanguage::TranslateText(TEXT(#n), TEXT(a))
#define _TLang(n, t)			CLanguage::TranslateText(TEXT(#n), t)
#define _LangEx(n, a)			CLanguage::TranslateTextEx(TEXT(#n), TEXT(a))
#define _TLangEx(n, t)			CLanguage::TranslateTextEx(TEXT(#n), t)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CLanguage ��
class CLanguage
{
public:
	static UINT m_uLang;					// ���Բ˵���
	static TCHAR m_tzText[1024];			// ��ʱ�ַ���

private:
	static UINT m_uMax;						// ��������
	static HFONT m_hFont;					// �Ի�������
	static TCHAR m_tzFileName[MAX_PATH];	// �����ļ�����

public:
	// ��ʼ������
	static LANGID Initialize();

	// �г�����
	static UINT List(HMENU hMenu);

	// ��������
	static VOID Set(HMENU hMenu, UINT uLang);

	// ��ȡ��������
	static PTSTR GetDescription(HMENU hMenu, UINT uLang);

	// ��ȡ�����ַ���
	static PTSTR TranslateText(PCTSTR ptzName, PCTSTR ptzDefault = NULL);

	// ��ȡ�����ַ��������滻�����ַ�
	static PTSTR TranslateTextEx(PCTSTR ptzName, PCTSTR ptzDefault = NULL);

	// ��ȡ��Դ�ַ���
	static PTSTR TranslateString(UINT uResID);

	// ���²˵�
	static VOID TranslateMenu(HMENU hMenu, PCTSTR ptzResName);

	// ���¶Ի���
	static VOID TranslateDialog(HWND hWnd, PCTSTR ptzResName);

public:
	// ����
	inline static VOID Destroy()
	{
		if (m_hFont)
		{
			DeleteObject(m_hFont);
		}
	}

private:
	// ���ò˵��ַ���
	static BOOL SetMenuString(HMENU hMenu, UINT uItemID, PCTSTR ptzString, BOOL bByPosition = FALSE);

	// �������ļ��и��²˵�
	static VOID UpdateMenuFromLanguage(HMENU hMenu, PCTSTR ptzSection, PCTSTR ptzPath = TEXT(""));

	// ����Դ�и��²˵�
	static VOID UpdateMenuFromResource(HMENU hMenu, PCTSTR ptzResName);

	// �������ļ��и��¶Ի���
	static BOOL CALLBACK UpdateDialogFromLanguage(HWND hWnd, PCTSTR ptzSection);
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////