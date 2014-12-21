#ifndef _POSITION_FORM
#define _POSITION_FORM

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QRadioButton>

/*
Ce fichier contient toutes les classes personnalisées
utilisées pour la création du widget PositionForm.

Décomposition du Widget (en terme de widget personnalisés)
PositionForm
- CommonGroupBar
-- MTlayout
- ColonieGroupBar
-- MTlayout
- ButtonGroupBar
*/

class MTlayout : public QGridLayout
{
public:
	MTlayout(const QString& texte, QWidget *parent = 0) : QGridLayout(parent)
	{
		m_label_ligne = new QLabel(texte);
		this->addWidget(m_label_ligne, 0, 0);
		m_enter_metal = new QLineEdit();
		this->addWidget(m_enter_metal, 0, 1);
		m_metal = new QLabel(" Métal");
		this->addWidget(m_metal, 0, 2);
		m_enter_tri = new QLineEdit();
		this->addWidget(m_enter_tri, 0, 3);
		m_tri = new QLabel(" Tritium");
		this->addWidget(m_tri, 0, 4);
	}

private:
	QLabel *m_label_ligne;
	QLabel *m_metal;
	QLabel *m_tri;
	QLineEdit *m_enter_metal;
	QLineEdit *m_enter_tri;
};

class SelectionType : public QGridLayout
{
public:
	SelectionType(QWidget *parent = 0) : QGridLayout(parent)
	{
		m_label_ligne = new QLabel("Type : ");
		this->addWidget(m_label_ligne, 0, 0);
		boutton_colonie = new QRadioButton("Colonie");
		this->addWidget(boutton_colonie, 0, 1);
		boutton_secteur = new QRadioButton("Secteur");
		this->addWidget(boutton_secteur, 0, 2);
	}

private:
	QLabel *m_label_ligne;
	QRadioButton *boutton_colonie;
	QRadioButton *boutton_secteur;
};

class EntrerCoordonnees : public QGridLayout
{
public:
	EntrerCoordonnees(QWidget *parent = 0) : QGridLayout(parent)
	{
		m_label_ligne = new QLabel("Coordonnées : ");
		this->addWidget(m_label_ligne, 0, 0);
		m_region = new QLineEdit();
		this->addWidget(m_region, 0, 1);
		m_constellation = new QLineEdit();
		this->addWidget(m_constellation, 0, 2);
		m_systeme = new QLineEdit();
		this->addWidget(m_systeme, 0, 3);
		m_position = new QLineEdit();
		this->addWidget(m_position, 0, 4);
	}

private:
	QLabel *m_label_ligne;
	QLineEdit *m_region;
	QLineEdit *m_constellation;
	QLineEdit *m_systeme;
	QLineEdit *m_position;
};

class NiveauSpatio : public QGridLayout
{
public:
	NiveauSpatio(QWidget *parent = 0) : QGridLayout(parent)
	{
		m_label_ligne = new QLabel("Niveau du spatioport : ");
		this->addWidget(m_label_ligne, 0, 0);
		m_lvl_spatio = new QLineEdit();
		this->addWidget(m_lvl_spatio, 0, 1);
	}

private:
	QLabel *m_label_ligne;
	QLineEdit *m_lvl_spatio;
};

class CommonGroupBar : public QGroupBox
{
public:
	CommonGroupBar(QWidget *parent = 0) : QGroupBox("Données générales", parent)
	{
		m_select = createSelectLayout();
		m_coord = createCoordLayout();
		m_prod_layout = createProdLayout("Production de la position : ");
		m_spatio = createSpatioLayout();

		QVBoxLayout *vbox = new QVBoxLayout;
		vbox->addLayout(m_select, 0);
		vbox->addLayout(m_coord, 1);
		vbox->addLayout(m_prod_layout, 2);
		vbox->addLayout(m_spatio, 3);
		this->setLayout(vbox);
	}

private:
	QGridLayout *m_prod_layout;
	QGridLayout *m_select;
	QGridLayout *m_coord;
	QGridLayout *m_spatio;
	QGridLayout *createProdLayout(const QString& desc);
	QGridLayout *createSelectLayout();
	QGridLayout *createCoordLayout();
	QGridLayout *createSpatioLayout();
};

class PositionForm : public QWidget
{
	Q_OBJECT
public:
	PositionForm();

private:
	QPushButton *m_bouton;
	CommonGroupBar *m_common;
	QGridLayout *m_main_layout;
};

#endif