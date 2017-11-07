#ifndef SQLITE_H
#define SQLITE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QCoreApplication>
#include "QFile"
#include <QDir>

#define DB_HOST ""
#define DB_PORT ""
#define DB_TABLE_SENSOR "SensorTable"
#define DB_TABLE_SENSORDRIVER "SensorDriverTable"

#define ID "Id"
#define NAME "Name"
#define COMMONNAME "CommonName"
#define IP "Ip"
#define PORT "Port"
#define ISACTIVE "IsActive"
#define TIMEOUT "Timeout"
#define DEVICESUBTYPE "DeviceSubType"
#define SENSORDRIVERID "SensorDriverId"
#define DATABASE_FOLDERNAME     "DB"
#define DATABASE_NAME           "SENSORMANAGER"


#if defined(Q_OS_WIN)
    #define PATH_CONFIG_FILE "C:/sensor-manager"
#elif defined(Q_OS_LINUX)
    #define PATH_CONFIG_FILE "/etc/sensor-manager"
#else
    #define PATH_CONFIG_FILE ""
#endif

const QString DRIVER("QSQLITE");

class SqLite
{
public:
    SqLite();
    virtual ~SqLite();

private:
    QSqlDatabase m_database;

    const QString DATABASE_FOLDER_PATH =(QString(PATH_CONFIG_FILE) + "/" + DATABASE_FOLDERNAME );
    const QString DATABASE_FILE_PATH = (QString(PATH_CONFIG_FILE) + "/" + DATABASE_FOLDERNAME + "/" + DATABASE_NAME );

    bool isExistDriver();
    bool isExistTable(QString nameTable);
    void initDb();
    // IDataBase interface
public:
    bool isExistDb(QString nameDb);
    void createDb();
    bool openDb(QString hostDb, QString portDb);
    bool closeDb();

    // My class virtual Interface
    bool executeCommand(QSqlQuery& query);
    bool executeCommand(const QString& queryString);
    bool hasNextResult(QSqlQuery& query);
    QVariantHash nextResult(QSqlQuery& query);

    // IDataBase interface
public:
    bool creatAllTables();

//    // driver table
//    void creatSensorDrivers();
//    SensorDriverModels getListDrivers();
//    SensorDriverModel getDriverByID(int);
//    SensorDriverModel getDriverByName(QString);
//    int insertSensorDriver(SensorDriverModel);
//    bool updateSensorDriver(SensorDriverModel);
//    bool deleteSensorDriver(SensorDriverModel);

};

#endif // SQLITE_H
