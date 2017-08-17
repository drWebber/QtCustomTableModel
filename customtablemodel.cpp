#include "customtablemodel.h"

CustomTableModel::CustomTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{

}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return items.count();
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return LAST;
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        return items[index.row()][Column(index.column())];
    } else {
        return QVariant();
    }
}

bool CustomTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role == Qt::EditRole) {
        return false;
    }

    items[index.row()][Column(index.column())] = value;
    emit dataChanged(index, index);
    return true;
}

void CustomTableModel::appendItem(const QString &product, const QString &desc,
                                  const float &price, const QString &status)
{
    Item item;
    item[Product] = product;
    item[Description] = desc;
    item[Price] = price;
    item[Status] = status;

    int row = items.count();
    beginInsertRows(QModelIndex(), row, row);
    items.append(item);
    endInsertRows();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Vertical) {
        return section+1;
    }
    switch (section) {
    case Product:
        return "Продукт";
    case Description:
        return "Описание";
    case Price:
        return "Цена";
    case Status:
        return "Статус";
    }
    return QVariant();
}
