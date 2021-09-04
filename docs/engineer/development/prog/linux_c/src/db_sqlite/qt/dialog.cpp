#include <QtSql>
#include <QTableView>
#include <QMessageBox>

// dialog.cpp
bool Dialog::SqliteTest()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.dat");
    if (!db.open())
    {
        QMessageBox::warning(0, QObject::tr("Database Error"),
                             db.lastError().text());
        return false;
    }
    QSqlQuery rs(db);
    rs.exec("CREATE TABLE person (firstname varchar(20), lastname varchar(20))");
    QByteArray strSql("insert into person(firstname,lastname) \
                   values('Ира', 'Chen')");
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString string = codec->toUnicode(strSql);
    rs.exec(string);

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM person");
    model->setHeaderData(0, Qt::Horizontal, "firstname");
    model->setHeaderData(1, Qt::Horizontal, "lastname");

    QTableView *view = new QTableView;
    view->setWindowTitle("QSqlQueryModel");
    view->setModel(model);
    view->show();

    db.close();
}