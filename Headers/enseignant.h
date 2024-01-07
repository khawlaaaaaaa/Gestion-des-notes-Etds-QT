#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include <QDialog>
#include "dbHeader.h"

namespace Ui {
class Enseignant;
}

class Enseignant : public QDialog
{
    Q_OBJECT

public:
    explicit Enseignant(QWidget *parent = nullptr);
    ~Enseignant();

private slots:
    void on_AjouterNote_clicked();

    void on_ChercherCours_2_clicked();

    void on_cnotes_clicked();

    void on_chercherE_clicked();

private:
    Ui::Enseignant *ui;
    QSqlQueryModel *model;
};

#endif // ENSEIGNANT_H
