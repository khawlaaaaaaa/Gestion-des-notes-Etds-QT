#include "enseignant.h"
#include "ui_enseignant.h"
#include <QMessageBox>
Enseignant::Enseignant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Enseignant)
{
    ui->setupUi(this);
}

Enseignant::~Enseignant()
{
    delete ui;
}

void Enseignant::on_AjouterNote_clicked()
{
    QString ref = ui->refEtud->text();
    QString noteStr = ui->noteEtud->text();
    QString idcours = ui->crsEtud->text();

    bool ok;
    int note = noteStr.toInt(&ok);
    if (!ok || note < 0 || note > 20) {
        QMessageBox::critical(this, "Error", "Invalid note value. Please enter a number between 0 and 20.");
        return;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/kh/OneDrive/Bureau/Projet 4/db/data.db");

    if (!db.open()) {
        qDebug() << "Error: Cannot open database";
        return;
    } else {
        qDebug() << "Database opened successfully";
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO note (note, idCours, refEtudiant) VALUES (:note, :idcours, :ref)");
    query.bindValue(":note", note);
    query.bindValue(":idcours", idcours);
    query.bindValue(":ref", ref);
    if (!query.exec()) {
        qDebug() << "Error: " << query.lastError().text();
    } else {
        qDebug() << "Record inserted successfully";
    }
    db.close();
}


void Enseignant::on_cnotes_clicked()
{
    QString text = ui->ChercherCours->text();
    bool ok;
    int intValue = text.toInt(&ok);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/kh/OneDrive/Bureau/Projet 4/db/data.db");
    if (!db.open()) {
        qDebug() << "Error: Cannot open database";
        return;
    } else {
        qDebug() << "Database opened successfully";
    }
    QSqlQuery query(db);
    query.prepare("SELECT note, idCours, refEtudiant FROM note WHERE idCours = :intValue");
    query.bindValue(":intValue", intValue);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        qDebug() << "Query executed: " << query.lastQuery();
    } else {
        qDebug() << "Record inserted successfully";
    }
    if (model == NULL) {
        model = new QSqlQueryModel();
    }
    model->setQuery(std::move(query));
    ui->notes->setModel(model);
    ui->notes->setColumnWidth(0,100);
    ui->notes->setColumnWidth(1,100);
    ui->notes->setColumnWidth(2,100);
    db.close();
}

void Enseignant::on_chercherE_clicked()
{
    QString intValue = ui->chercherRef->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/kh/OneDrive/Bureau/Projet 4/db/data.db");
    if (!db.open()) {
        qDebug() << "Error: Cannot open database";
        return;
    } else {
        qDebug() << "Database opened successfully";
    }
    QSqlQuery query(db);
    query.prepare("SELECT note, idCours, refEtudiant FROM note WHERE refEtudiant = :intValue");
    query.bindValue(":intValue", intValue);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        qDebug() << "Query executed: " << query.lastQuery();
    } else {
        if (model == nullptr) {
            model = new QSqlQueryModel();
        }
        model->setQuery(std::move(query));
        ui->note->setModel(model);
        ui->note->setColumnWidth(0, 100);
        ui->note->setColumnWidth(1, 100);
        ui->note->setColumnWidth(2, 100);
    }
    db.close();
}

