#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <qabstractitemmodel.h>
#include <qhash.h>



class CustomTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CustomTableModel(QObject *parent = 0);
private:
    enum Column {
        Product,
        Description,
        Price,
        Status,
        LAST
    };

    typedef QHash<Column, QVariant> Item;
    typedef QList<Item> Items;
    Items items;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    void appendItem(const QString &product, const QString &desc,
                    const float &price, const QString &status);

    // QAbstractItemModel interface
public:
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // CUSTOMTABLEMODEL_H
