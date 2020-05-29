#ifndef FILEINFO_H
#define FILEINFO_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Fileinfo; }
QT_END_NAMESPACE

class Fileinfo : public QWidget
{
    Q_OBJECT

public:
    Fileinfo(QWidget *parent = nullptr);
    ~Fileinfo();
    void getFileInfo(QString &fileName);

private slots:
    void on_browseFleBtn_clicked();

private:
    Ui::Fileinfo *ui;
};
#endif // FILEINFO_H
