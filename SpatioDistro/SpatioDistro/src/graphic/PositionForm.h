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

class ColonieGroupBar : public QGroupBox
{
public:
	ColonieGroupBar(QWidget *parent = 0) : QGroupBox("Données d'une colonie", parent)
	{
		m_name = createNameLayout();
		MTlayout *tmp_def = new MTlayout("Consommation des défenses :");
		m_def_layout = qobject_cast<QGridLayout *>(tmp_def);
		MTlayout *tmp_fusion = new MTlayout("Consommation de la fusion :");
		m_fusion_layout = qobject_cast<QGridLayout *>(tmp_fusion);
		MTlayout *tmp_pontons = new MTlayout("Gain des pontons :");
		m_ponton_layout = qobject_cast<QGridLayout *>(tmp_pontons);

		QVBoxLayout *vbox = new QVBoxLayout;
		vbox->addLayout(m_name, 0);
		vbox->addLayout(m_def_layout, 1);
		vbox->addLayout(m_fusion_layout, 2);
		vbox->addLayout(m_ponton_layout, 3);
		this->setLayout(vbox);
	}

private:
	QGridLayout *m_name;
	QGridLayout *m_def_layout;
	QGridLayout *m_fusion_layout;
	QGridLayout *m_ponton_layout;
	QGridLayout *createNameLayout();
};

class PositionForm : public QWidget
{
	Q_OBJECT
public:
	PositionForm();

private:
	QPushButton *m_bouton;
	CommonGroupBar *m_common;
	ColonieGroupBar *m_colo;
	QGridLayout *m_main_layout;
};

#endif