#if !defined(AFX_DGTREECTRL_H__F3DA1CC2_7018_4971_A2DA_AFB9352C2FD8__INCLUDED_)
#define AFX_DGTREECTRL_H__F3DA1CC2_7018_4971_A2DA_AFB9352C2FD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DGTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDGTreeCtrl window
typedef struct _tagDragData
{
	char*	pBuf;
	int		nDLen;
	CLIPFORMAT	cfFormat;
}DragData_S;


#define TREECTRL_STATE_NONE		0
#define TREECTRL_STATE_UNCHECK	1
#define TREECTRL_STATE_CHECKING	2
#define TREECTRL_STATE_CHECKED	3
class CDGTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CDGTreeCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDGTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDGTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDGTreeCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnStateIconClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

public:
	void	SetMsgBeginDrag(UINT nMsg) { m_nMsgBeginDrag = nMsg; }
	void	SetMsgRClick(UINT nMsg) { m_nMsgRClick = nMsg; }
	void	SetMsgToolhit(UINT nMsg) { m_nMsgToolhit = nMsg; }

	BOOL	SetItemState( HTREEITEM hItem, UINT nState, UINT nStateMask, BOOL bSearch=TRUE);
	void	SetCheckStateChanageMsg(int nMsg) { m_nCheckStateChanageMsg = nMsg; }
	void	SetIocnClickMsg(int nMsg) { m_nIconClickMsg = nMsg; }

	BOOL	GetMaskSelected(HTREEITEM hItem);

	// У��ĳ���ڵ��״̬,���޸�״̬,��������ʾ�Ƿ�У�鸸�׽ڵ�
	// ����ֵ:У����ɺ��״̬
	static int CheckItemState(CTreeCtrl& tree, HTREEITEM hItem, BOOL bCheckParent);

	// ��ȡ�ڵ�Ӧ����ʾ��״̬,�����޸�״̬
	static int GetItemRealState(CTreeCtrl& tree, HTREEITEM hItem);

	static void OnNMCustiondrawEx(NMHDR *pNMHDR, LRESULT *pResult);

	void	SetRClickSel(bool bRClickSel = true) { m_bRClickSel = bRClickSel; }
	HTREEITEM GetLastRClickItem() { return m_hLastRClickItem; }

	bool GetShieldTravel() const { return m_bShieldTravel; }
	void SetShieldTravel(bool val) { m_bShieldTravel = val; }
private:
	UINT m_uFlags;
	void TravelSiblingAndParent(HTREEITEM hItem, int nState);
	void TravelChild(HTREEITEM hItem,int nState);


private:
	UINT	m_nMsgBeginDrag;
	UINT	m_nMsgRClick;
	UINT	m_nMsgToolhit;
	int			m_nCheckStateChanageMsg;	//״̬�ı���Ϣ
	int			m_nIconClickMsg;	
//	CImageList* m_pDragImage;
	bool		m_bDragging;


	bool		m_bRClickSel;				//�Ҽ�����Զ�ѡ�нڵ�(Ĭ��:false��ѡ��)
	HTREEITEM	m_hLastRClickItem;			//�Ҽ�����ڵ�

	bool		m_bShieldTravel;			//ѡ��ڵ�ʱ����ѡ�ӽڵ�(�ͻ���ʹ��)
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DGTREECTRL_H__F3DA1CC2_7018_4971_A2DA_AFB9352C2FD8__INCLUDED_)