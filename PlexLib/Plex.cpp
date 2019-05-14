#include "Plex.h"
#include "Line.h"
#include <iostream>
#include "Exception.h"
#include "StackList.h"
using namespace std;

TPlex::TPlex()
{
	right = NULL;
	left = NULL;
}

TPlex::TPlex(TPoint* l, TPoint* r)
{
	right = r;
	left = l;
}

TPlex::TPlex(TPlex& P)
{
	TPlex *pl, *pr;
	pl = dynamic_cast<TPlex*>(P.left);
	pr = dynamic_cast<TPlex*>(P.right);
	
	if (pl != 0)//Plex
		left = new TPlex(*pl);
	else
		left = new TPoint(*pl);

	if (pr != 0)//Plex
		right = new TPlex(*pr);
	else
		right = new TPoint(*pr);
}

TPoint* TPlex::GetRight()
{
	return right;
}

TPoint* TPlex::GetLeft()
{
	return left;
}

void TPlex::SetRight(TPoint* R)
{
	right = R;
}

void TPlex::SetLeft(TPoint* L)
{
	left = L;
}

void TPlex::Add(TPoint* A, TPoint* B)
{
	if (right == 0 && left == 0)
	{
		right = A;
		left = B;
	}
	else
	{
		TStackList<TPoint*> point;
		TStackList<TPlex*> plex;
		point.Put(right);
		point.Put(left);
		plex.Put(this);
		plex.Put(this);
		bool flag = true;
		while (flag && (!point.IsEmpty() || !plex.IsEmpty()))
		{
			TPoint* t = point.Get();
			TPlex* p = dynamic_cast<TPlex*>(t);
			TPlex* par = plex.Get();
			if (t->GetX() == A->GetX() && t->GetY() == A->GetY())
			{
				if (par->left == t)
					par->left = new TPlex(B, A);
				else
					par->right = new TPlex(B, A);
				flag = false;
			}
			else if (t->GetX() == B->GetX() && t->GetY() == B->GetY())
			{
				if (par->left == t)
					par->left = new TPlex(A, B);
				else
					par->right = new TPlex(A, B);
				flag = false;
			}
			else if (p != 0)
			{
				point.Put(p->left);
				point.Put(p->right);
				plex.Put(p);
				plex.Put(p);
			}
		}
		if (flag)
			throw TException("Line is not connected with plex", "Plex", "Add", 3);
	}
}

//void TPlex::Show()
//{
//	if ((left == 0) && (right == 0))
//		throw TException("Empty plex", "Plex", "Show", 2);
//	TStackList<TPlex*> plex;
//	TStackList<TPoint*> point;
//	TPlex* pr;
//	TPlex* pl;
//	TPoint* tr = NULL;
//	TPoint* tl = NULL;
//	TPlex* cur = this;
//	plex.Put(cur);
//	while (!(plex.IsEmpty()))
//	{
//		cur = plex.Get();
//		while (tr == NULL)
//		{
//			pr = dynamic_cast<TPlex*> (cur->right);
//			pl = dynamic_cast<TPlex*>(cur->left);
//			if (pr != 0 && pl != 0)
//			{
//				
//			}
//		}
//	}
//}

TPoint* TPlex::Show(TPlex* P)
{
	TPlex *pl, *pr;
	TPoint *tl, *tr;

	pl = dynamic_cast<TPlex*>(P->left);
	pr = dynamic_cast<TPlex*>(P->right);

	if (pl != 0)
		tl = Show(pl);
	else
		tl = P->left;

	if (pr != 0)
		tr = Show(pr);
	else
		tr = P->right;
	TLine L(*tr, *tl);
	L.Show();
	return tr;
}