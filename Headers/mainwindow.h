#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Administration.h"
#include "Enseignant.h"
#include "Etudiant.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_I_Administration_clicked();

    void on_I_Enseignant_clicked();

    void on_I_Etudiant_clicked();

private:
    Ui::MainWindow *ui;
    Administration *ptrAdministration;
    etudiant *ptrEtudiant;
    Enseignant *ptrEnseignant;

};

#endif // MAINWINDOW_H
