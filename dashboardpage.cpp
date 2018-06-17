#include "dashboardpage.h"
#include "ui_dashboardpage.h"





std::auto_ptr<DashBoardPage> DashBoardPage::mInstance;
DashBoardPage * DashBoardPage::instance()
{
    if (!mInstance.get())
        mInstance.reset(new DashBoardPage());
    return mInstance.get();
}
DashBoardPage::DashBoardPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashBoardPage)
{
    ui->setupUi(this);
}

DashBoardPage::~DashBoardPage()
{
    delete ui;
}
