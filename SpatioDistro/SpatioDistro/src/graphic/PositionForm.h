#ifndef _POSITION_FORM
#define _POSITION_FORM

#include <QApplication>
#include <QWidget>
#include <QPushButton>

class PositionForm : public QWidget // On h�rite de QWidget (IMPORTANT)
{
public:
	PositionForm();

private:
	QPushButton *m_bouton;
};

#endif