#ifndef SPATIODISTRO_H
#define SPATIODISTRO_H

#include <QtWidgets/QMainWindow>
#include "ui_spatiodistro.h"

class SpatioDistro : public QMainWindow
{
	Q_OBJECT

public:
	SpatioDistro(QWidget *parent = 0);
	~SpatioDistro();

private:
	Ui::SpatioDistroClass ui;
};

#endif // SPATIODISTRO_H
