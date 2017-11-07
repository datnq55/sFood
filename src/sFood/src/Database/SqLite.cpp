#include "SqLite.h"

SqLite::SqLite()
{
    m_database = QSqlDatabase::addDatabase(DRIVER);
}

SqLite::~SqLite()
{

}

bool SqLite::isExistDriver()
{
    if( !QSqlDatabase::isDriverAvailable(DRIVER) )
    {
        qDebug() << "ERROR: " << "SQLite driver is not available!";
        return false;
    }
    return true;
}

bool SqLite::isExistTable(QString nameTable)
{
    if ( m_database.tables().contains(nameTable)) {
        qDebug() << nameTable << " is exist";
        return true;
    }
    else
    {
        return false;
    }
}

void SqLite::initDb()
{
    if (QDir(DATABASE_FOLDER_PATH).exists())
    {
        m_database.setDatabaseName(DATABASE_FILE_PATH);
    }
    else
    {
        QDir().mkdir(DATABASE_FOLDER_PATH);
        m_database.setDatabaseName(DATABASE_FILE_PATH);
    }
}

bool SqLite::isExistDb(QString nameDb)
{
    if(QFile::exists(nameDb))
    {
        qDebug() << "Database is exist.";
        return true;
    }
    else
    {
        qDebug() << "Database created.";
        return false;
    }
}

void SqLite::createDb()
{

}

bool SqLite::openDb(QString hostDb, QString portDb)
{
    Q_UNUSED(hostDb)
    Q_UNUSED(portDb)
    if( !m_database.open() )
    {
        qDebug() << "ERROR: " << "Can not open database";
        qDebug() << "ERROR: " << m_database.lastError().text();
        return false;
    }
    return true;
}

bool SqLite::closeDb()
{
    return false;
}

bool SqLite::executeCommand(QSqlQuery& query)
{
    query.exec();
    if( !query.isActive() )
    {
        qDebug() << "ERROR: " << "Can not execute command: " << query.lastQuery();
        qDebug() << "ERROR: " << query.lastError().text();
        return false;
    }
    return true;
}

bool SqLite::executeCommand(const QString &queryString)
{
    QSqlQuery query(m_database);
    query.exec(queryString);
    if( !query.isActive() )
    {
        qDebug() << "ERROR: " << "Can not execute command: " << queryString;
        qDebug() << "ERROR: " << query.lastError().text();
        return false;
    }
    return true;
}

bool SqLite::hasNextResult(QSqlQuery& query)
{
    return query.next();
}

QVariantHash SqLite::nextResult(QSqlQuery& query)
{
    QVariantHash rowData;
    //QJsonObject
    int columns = query.record().count();
    for(int i = 0; i < columns; i++ )
    {
        rowData.insert(query.record().fieldName(i), query.value(i));
    }
    return rowData;
}

// ALL TABLE

bool SqLite::creatAllTables()
{
    m_database.removeDatabase(DATABASE_FILE_PATH);
    if ( isExistDriver())
    {
        initDb();
        if (!openDb("127.0.0.1","6000"))
        {
            return false;
        }
        if (!isExistDb(DATABASE_FILE_PATH))
        {
            qDebug() << "Create All Table";
            executeCommand(QString("CREATE TABLE %1 (%2 INTEGER PRIMARY KEY, %3 TEXT, %4 TEXT)").arg(DB_TABLE_SENSORDRIVER, ID, NAME, COMMONNAME));
            //creatSensorDrivers();

            QStringList paramKey;
            paramKey.append(QString("%1 INTEGER PRIMARY KEY").arg(ID));
            paramKey.append(QString("%1 NTEXT").arg(NAME));
            paramKey.append(QString("%1 NTEXT").arg(COMMONNAME));
            paramKey.append(QString("%1 NTEXT").arg(IP));
            paramKey.append(QString("%1 NTEXT").arg(PORT));
            paramKey.append(QString("%1 INTEGER").arg(TIMEOUT));
            paramKey.append(QString("%1 BOOLEAN").arg(ISACTIVE));
            paramKey.append(QString("%1 INTEGER").arg(DEVICESUBTYPE));
            paramKey.append(QString("%1 INTEGER").arg(SENSORDRIVERID));
            paramKey.append(QString("FOREIGN KEY(%1) REFERENCES %2(%3)").arg(SENSORDRIVERID,DB_TABLE_SENSORDRIVER,ID));

            executeCommand(QString("CREATE TABLE %1 (%2)").arg(DB_TABLE_SENSOR, paramKey.join(",")));
        }
        else
        {
            qDebug() << "Create All Table";
            if (!m_database.tables().contains(QLatin1String(DB_TABLE_SENSORDRIVER)))
            {
                executeCommand(QString("CREATE TABLE %1 (%2 INTEGER PRIMARY KEY, %3 TEXT, %4 TEXT)").arg(DB_TABLE_SENSORDRIVER, ID, NAME, COMMONNAME));
                //creatSensorDrivers();
            }

            if (!m_database.tables().contains(QLatin1String(DB_TABLE_SENSOR)))
            {
                QStringList paramKey;
                paramKey.append(QString("%1 INTEGER PRIMARY KEY").arg(ID));
                paramKey.append(QString("%1 NTEXT").arg(NAME));
                paramKey.append(QString("%1 NTEXT").arg(COMMONNAME));
                paramKey.append(QString("%1 NTEXT").arg(IP));
                paramKey.append(QString("%1 NTEXT").arg(PORT));
                paramKey.append(QString("%1 INTEGER").arg(TIMEOUT));
                paramKey.append(QString("%1 BOOLEAN").arg(ISACTIVE));
                paramKey.append(QString("%1 INTEGER").arg(DEVICESUBTYPE));
                paramKey.append(QString("%1 INTEGER").arg(SENSORDRIVERID));
                paramKey.append(QString("FOREIGN KEY(%1) REFERENCES %2(%3)").arg(SENSORDRIVERID,DB_TABLE_SENSORDRIVER,ID));

                executeCommand(QString("CREATE TABLE %1 (%2)").arg(DB_TABLE_SENSOR, paramKey.join(",")));
            }
        }

        return true;
    }
    return false;
}

//// DRIVER TABLE

//void SqLite::creatSensorDrivers()
//{
//    SensorDriverModel driver;
//    driver.id = (int)DriverType::DRIVER_BCTANKSOUNDING;
//    driver.name = DRIVER_NAME_BC_TANK_SOUNDING;
//    driver.commonName = DRIVER_NAME_BC_TANK_SOUNDING;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_BILGEPUMP;
//    driver.name = DRIVER_NAME_BILGE_PUMP;
//    driver.commonName = DRIVER_NAME_BILGE_PUMP;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_GENERATOR;
//    driver.name = DRIVER_NAME_GENERATOR;
//    driver.commonName = DRIVER_NAME_GENERATOR;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_GENERICIO;
//    driver.name = DRIVER_NAME_GENERICIO;
//    driver.commonName = DRIVER_NAME_GENERICIO;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_BALLASTSYSTEM;
//    driver.name = DRIVER_NAME_BALLAST_SYSTEM;
//    driver.commonName = DRIVER_NAME_BALLAST_SYSTEM;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_HATCH;
//    driver.name = DRIVER_NAME_HATCH;
//    driver.commonName = DRIVER_NAME_HATCH;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_ORBIT;
//    driver.name = DRIVER_NAME_ORBIT;
//    driver.commonName = DRIVER_NAME_ORBIT;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_INCLINOMETER;
//    driver.name = DRIVER_NAME_INCLINOMETER;
//    driver.commonName = DRIVER_NAME_INCLINOMETER;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_THERMOLICER;
//    driver.name = DRIVER_NAME_THERMOLICER;
//    driver.commonName = DRIVER_NAME_THERMOLICER;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_KNX;
//    driver.name = DRIVER_NAME_KNX;
//    driver.commonName = DRIVER_NAME_KNX;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_THERMOLICER1;
//    driver.name = DRIVER_NAME_THERMOLICER1;
//    driver.commonName = DRIVER_NAME_THERMOLICER1;
//    driver.isActive = true;

//    insertSensorDriver(driver);

//    driver.id = (int)DriverType::DRIVER_THERMOLICER2;
//    driver.name = DRIVER_NAME_THERMOLICER2;
//    driver.commonName = DRIVER_NAME_THERMOLICER2;
//    driver.isActive = true;

//    insertSensorDriver(driver);
//}

//SensorDriverModels SqLite::getListDrivers()
//{
//    SensorDriverModels drivers;
//    SensorDriverModel driver;
//    QSqlQuery query(m_database);
//    query.prepare(QString("SELECT * FROM %1").arg(DB_TABLE_SENSORDRIVER));
//    if (executeCommand(query)) {
//        while (hasNextResult(query)) {
//            driver.id = query.record().value(ID).toInt();
//            driver.name = query.record().value(NAME).toString();
//            driver.commonName = query.record().value(COMMONNAME).toString();
//            drivers.drivers.append(driver);
//        }
//    }
//    return drivers;
//}

//SensorDriverModel SqLite::getDriverByID(int id)
//{
//    SensorDriverModel driver;
//    QSqlQuery query(m_database);
//    query.prepare(QString("SELECT * FROM %1 WHERE %2 = %3").arg(DB_TABLE_SENSORDRIVER, ID, QString::number(id)));
//    if (executeCommand(query)) {
//        if (hasNextResult(query))
//        {
//            driver.id = query.record().value(ID).toInt();
//            driver.name = query.record().value(NAME).toString();
//            driver.commonName = query.record().value(COMMONNAME).toString();
//        }
//    }
//    return driver;
//}

//SensorDriverModel SqLite::getDriverByName(QString name)
//{
//    SensorDriverModel driver;
//    QSqlQuery query(m_database);
//    query.prepare(QString("SELECT * FROM %1 WHERE %2 = '%3'").arg(DB_TABLE_SENSORDRIVER, NAME, name));
//    if (executeCommand(query)) {
//        if (hasNextResult(query))
//        {
//            driver.id = query.record().value(ID).toInt();
//            driver.name = query.record().value(NAME).toString();
//            driver.commonName = query.record().value(COMMONNAME).toString();
//        }
//    }
//    return driver;
//}

//int SqLite::insertSensorDriver(SensorDriverModel driver)
//{
//    QStringList paramValue;
//    paramValue.append(QString("'%1'").arg(driver.name));
//    paramValue.append(QString("'%1'").arg(driver.commonName));

//    QStringList paramKey;
//    paramKey.append(NAME);
//    paramKey.append(COMMONNAME);

//    QSqlQuery query(m_database);
//    query.prepare(QString("INSERT INTO %1(%2) VALUES (%3)").arg(DB_TABLE_SENSORDRIVER, paramKey.join(",") ,paramValue.join(",")));
//    if (executeCommand(query))
//    {
//        return query.lastInsertId().toInt();
//    }
//    else
//    {
//        return -1;
//    }
//}

//bool SqLite::updateSensorDriver(SensorDriverModel driver)
//{
//    QStringList paramValue;
//    paramValue.append(QString("%1 = '%2'").arg(NAME,driver.name));
//    paramValue.append(QString("%1 = '%2'").arg(COMMONNAME,driver.commonName));
//    return executeCommand(QString("UPDATE %1 SET %2 WHERE %3 = %4").arg(DB_TABLE_SENSOR, paramValue.join(","), ID, QString::number(driver.id)));
//}

//bool SqLite::deleteSensorDriver(SensorDriverModel driver)
//{
//    return executeCommand(QString("DELETE FROM %1 WHERE %2 = %3").arg(DB_TABLE_SENSORDRIVER, ID, QString::number(driver.id)));
//}
