#include "etudiant.h"
#include "ui_etudiant.h"

etudiant::etudiant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::etudiant)
{
    ui->setupUi(this);
}

etudiant::~etudiant()
{
    delete ui;
}

void etudiant::on_Echercher_clicked()
{
    QString intValue = ui->Enote->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/kh/OneDrive/Bureau/Projet 4/db/data.db");
    if (!db.open()) {
        qDebug() << "Error: Cannot open database";
        return;
    } else {
        qDebug() << "Database opened successfully";
    }
    QSqlQuery query(db);
    query.prepare("SELECT note, cours.label AS coursLabel, refEtudiant FROM note "
                  "INNER JOIN cours ON note.idCours = cours.id "
                  "WHERE refEtudiant = :intValue");
    query.bindValue(":intValue", intValue);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        qDebug() << "Query executed: " << query.lastQuery();
        return;
    }
    if (model == nullptr) {
        model = new QSqlQueryModel();
    }
    model->setQuery(std::move(query));
    ui->Eliste->setModel(model);
    ui->Eliste->setColumnWidth(0, 100);
    ui->Eliste->setColumnWidth(1, 100);
    ui->Eliste->setColumnWidth(2, 100);
    db.close();
}


