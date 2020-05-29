#include "fileinfo.h"
#include "ui_fileinfo.h"
#include<QFileDialog>
#include<QString>
#include<QDateTime>
Fileinfo::Fileinfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Fileinfo)
{
    ui->setupUi(this);
    setWindowTitle("习大大得程序");
}

Fileinfo::~Fileinfo()
{
    delete ui;
}

void Fileinfo::getFileInfo(QString &fileName)
{
    QFileInfo info(fileName);
    int size=info.size();
    QDateTime createTime=info.created();//返回文件创建得时间
    QDateTime lastMTime=info.lastModified();//返回文件最后一次修改得时间
    QDateTime lastTime=info.lastRead();//返回最后一次访问得时间


    bool bIsDir =info.isDir();//返回文件是否为目录
    bool bIsFile=info.isFile();//返回文件是否为文件
    bool bIssymLink=info.isSymLink();//返回文件是否是一个链接
    bool bIsHidden=info.isHidden();//返回文件是否隐藏
    bool bIsReadable=info.isReadable();//返回文件是否可读
    bool bIsWritable=info.isWritable();//返回文件是否可写
    bool bIsExcutable=info.isExecutable();//返回文件是否为可读文件

    ui->fileSizeLineEdit->setText(QString::number(size));
    ui->fileCreatELinrRdit->setText(createTime.toString());
    ui->fileModifuLineEdit->setText(lastMTime.toString());
    ui->fileReadLinrEdit->setText(lastTime.toString());



    ui->isDirCheckbox->setChecked(bIsDir);
    ui->isFileCheckaBox->setChecked(bIsFile);
    ui->isSymLinkCheckBox->setChecked(bIssymLink);
    ui->isHiddenCheckBox->setChecked(bIsHidden);
    ui->isWritadleCheckBox->setChecked(bIsWritable);
    ui->isWitableCheckBox->setChecked(bIsReadable);
    ui->isExrcutableCheckBox->setChecked(bIsExcutable);
}


void Fileinfo::on_browseFleBtn_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,"文件对话框",".","files(*)");
    ui->fileNameLineEdit->setText(fileName);
    getFileInfo(fileName);

}
