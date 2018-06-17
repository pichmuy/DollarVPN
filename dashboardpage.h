#ifndef DASHBOARDPAGE_H
#define DASHBOARDPAGE_H


#include <memory>
#include <QWidget>

namespace Ui {
class DashBoardPage;
}

class DashBoardPage : public QWidget
{
    Q_OBJECT

public:
    explicit DashBoardPage(QWidget *parent = 0);
    static DashBoardPage * instance();
    ~DashBoardPage();
    static bool IsExists()
    {
        return (mInstance.get() != NULL);
    }

private:
    Ui::DashBoardPage *ui;
    static std::auto_ptr<DashBoardPage> mInstance;
};

#endif // DASHBOARDPAGE_H
