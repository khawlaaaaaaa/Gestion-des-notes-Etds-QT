#include "administration.h"
#include "ui_administration.h"


Administration::Administration(QWidget *parent)
    : QDialog(parent), ui(new Ui::Administration)
{
    ui->setupUi(this);
}

Administration::~Administration()
{
    delete ui;
    delete model;
}

void Administration::on_AjouterUtilisateur_clicked()
{
    // Handle AjouterUtilisateur button click if needed
}

void Administration::on_btnSave_clicked()
{
    QString ref = ui->txtRef->text();
    QString nom = ui->txtNom->text();
    QString prenom = ui->txtPrenom->text();
    QString cours = ui->txtCours->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/driss/OneDrive/Desktop/Emsi/CPP/Projet/db/data.db");

    if (!db.open()) {
        qDebug() << "Error: Cannot open database";
        return;
    } else {
        qDebug() << "Database opened successfully";
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO USER (ref, nom, prenom, cours) VALUES ('" + ref + "','" + nom + "','" + prenom + "','" + cours + "')");
    if (!query.exec()) {
        qDebug() << "Error: " << query.lastError().text();
    } else {
        qDebug() << "Record inserted successfully";
    }
    db.close();
}

void Administration::on_btnSave1_clicked()
{
    QString ref = ui->txtRef1->text();
    QString nom = ui->txtNom1->text();
    QString prenom = ui->txtPrenom1->text();
    QString specialite = ui->txtSpecialite->text();
    qDebug() << "Reference: " << ref;
    qDebug() << "Nom: " << nom;
    qDebug() << "Prenom: " << prenom;
    qDebug() << "specialite: " << specialite;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/kh/OneDrive/Bureau/Projet 4/db/data.db");

    if (!db.open()) {
        qDebug() << "Error: Cannot open database";
        return;
    } else {
        qDebug() << "Database opened successfully";
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO Etudiant (ref, nom, prenom, specialite) VALUES ('" + ref + "','" + nom + "','" + prenom + "','" + specialite + "')");
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        qDebug() << "Query executed: " << query.lastQuery();
    } else {
        qDebug() << "Record inserted successfully";
    }
    db.close();
}


void Administration::on_btnFind_clicked()
{
    QString ref = ui->txtFind->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/kh/OneDrive/Bureau/Projet 4/db/data.db");

    if (!db.open()) {
        qDebug() << "Error: Cannot open database";
        return;
    } else {
        qDebug() << "Database opened successfully";
    }
    QSqlQuery query(db);
    //query.prepare("SELECT * FROM Etudiant ,USER WHERE ref like '%" + ref + "%'");
    query.prepare("SELECT * FROM Etudiant WHERE ref = :ref UNION SELECT * FROM USER WHERE ref = :ref");
    query.bindValue(":ref", ref);
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
    ui->tabfind->setModel(model);
    ui->tabfind->setColumnWidth(0,100);
    ui->tabfind->setColumnWidth(1,100);
    ui->tabfind->setColumnWidth(2,100);
    ui->tabfind->setColumnWidth(3,100);
    ui->tabfind->setColumnWidth(4,100);
    db.close();
}

void Administration::on_lister_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/kh/OneDrive/Bureau/Projet 4/db/data.db");
    if (!db.open()) {
        qDebug() << "Error: Cannot open database";
        return;
    } else {
        qDebug() << "Database opened successfully";
    }
    QSqlQuery query(db);
     query.prepare("SELECT * FROM Etudiant");
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
    ui->listEtu->setModel(model);
    ui->listEtu->setColumnWidth(0,100);
    ui->listEtu->setColumnWidth(1,100);
    ui->listEtu->setColumnWidth(2,100);
    ui->listEtu->setColumnWidth(3,100);
    ui->listEtu->setColumnWidth(4,100);
    db.close();
}


void Administration::on_lister1_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/kh/OneDrive/Bureau/Projet 4/db/data.db");
    if (!db.open()) {
        qDebug() << "Error: Cannot open database";
        return;
    } else {
        qDebug() << "Database opened successfully";
    }
    QSqlQuery query(db);
    query.prepare("SELECT * FROM USER");
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
    ui->listPro->setModel(model);
    ui->listPro->setColumnWidth(0,100);
    ui->listPro->setColumnWidth(1,100);
    ui->listPro->setColumnWidth(2,100);
    ui->listPro->setColumnWidth(3,100);
    ui->listPro->setColumnWidth(4,100);
    db.close();
}

