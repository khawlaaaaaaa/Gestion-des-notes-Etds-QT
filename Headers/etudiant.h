#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QDialog>
#include "dbHeader.h"

namespace Ui {
class etudiant;
}

class etudiant : public QDialog
{
    Q_OBJECT

public:
    explicit etudiant(QWidget *parent = nullptr);
    ~etudiant();

private slots:
    void on_Echercher_clicked();

private:
    Ui::etudiant *ui;
    QSqlQueryModel *model;
};

#endif // ETUDIANT_H
