#ifndef _POSITION_FORM
#define _POSITION_FORM

#include <QApplication>
#include <QWidget>
#include <QPushButton>

class PositionForm : public QWidget // On hérite de QWidget (IMPORTANT)
{
public:
	PositionForm();

private:
	QPushButton *m_bouton;
};

#endif