#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAdministration = new Administration();
    ptrEnseignant = new Enseignant();
    ptrEtudiant = new etudiant();

}

MainWindow::~MainWindow()
{
    delete ptrAdministration;
    delete ptrEnseignant;
    delete ptrEtudiant;
    delete ui;
}

void MainWindow::on_I_Administration_clicked()
{
    ptrAdministration->show();
}


void MainWindow::on_I_Enseignant_clicked()
{
    ptrEnseignant->show();
}


void MainWindow::on_I_Etudiant_clicked()
{
    ptrEtudiant->show();
}

