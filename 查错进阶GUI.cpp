
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QProcess>
#include <QTextStream>
#include <QStandardPaths>
#include <QDir>
#include <QCryptographicHash>
#include <QTimer>
#include <QProgressBar>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include <QGroupBox>
#include <QGridLayout>
#include <QSpinBox>
#include <QSplitter>
#include <QHeaderView>
#include <QTableWidget>
#include <QClipboard>
#include <QMimeData>
#include <QDesktopServices>
#include <QUrl>
#include <QStatusBar>
#include <QMenuBar>
#include <QToolBar>
#include <QIcon>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>

// 算法部分
struct Edge {
    int x, y;
    int next;
};

const int N = 3*1e5+5;
int n, ssize[N], fa[N];
int son[N], son2[N];
Edge e[2*N];
int g[N], weight;
long long ans;

int o[N], p[N], last, len[N];
bool to[N];

void dfs(int x, int _fa) {
    fa[x] = _fa;
    ssize[x] = 1;
    son[x] = son2[x] = 0;
    for(int i=g[x]; i; i=e[i].next) {
        int y = e[i].y;
        if(y==_fa) continue;
        dfs(y, x);
        ssize[x] += ssize[y];
        if(ssize[y] > ssize[son[x]]) {
            son2[x] = son[x];
            son[x] = y;
        } else if(ssize[y] > ssize[son2[x]]) {
            son2[x] = y;
        }
    }
}

void dfs2(int x, int _fa, int top) {
    o[++last] = x;
    p[x] = last;
    len[x] = 1;
    if(son[x]) {
        dfs2(son[x], x, top);
        len[x] += len[son[x]];
    }

    for(int i=g[x]; i; i=e[i].next) {
        int y = e[i].y;
        if(y==_fa || y==son[x]) continue;
        dfs2(y, x, y);
    }
}

int findWeight() {
    for(int i=1; i<=n; i++) {
        if(ssize[son[i]]<=n/2 && n-ssize[i]<=n/2)
            return i;
    }
    return 1;
}

void setto(int x, int _fa) {
    to[x] = true;
    for(int i=g[x]; i; i=e[i].next) {
        int y = e[i].y;
        if(y == _fa) continue;
        setto(y, x);
    }
}

void findweightLine(int rot, int all) {
    int L = p[rot], R = p[rot] + len[rot] - 1;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(ssize[o[mid]] <= all/2)
            R = mid - 1;
        else
            L = mid + 1;
    }
    int x = o[L];
    ans += fa[x];

    if(all - ssize[x] <= all/2)
        ans += x;
}

void solve(int root) {
    if(ssize[root] == 1) {
        ans += root;
        return;
    }

    findweightLine(son[root], ssize[root]);
}

void solve2(int rootSon) {
    if(ssize[rootSon] == n-1) {
        ans += fa[rootSon];
        return;
    }

    if(to[rootSon]) {
        findweightLine(son2[weight], n-ssize[rootSon]);
    } else {
        findweightLine(son[weight], n-ssize[rootSon]);
    }
}

long long runAlgorithm(int t, QString &result) {
    long long totalAns = 0;
    result = "";

    for(int caseNum = 1; caseNum <= t; caseNum++) {
        ans = 0, last = 0;
        for(int i=1; i<=n; i++) {
            g[i] = 0;
            to[i] = false;
        }

        for(int i=1; i<=n-1; i++) {
            int x, y;
            // 这里需要从输入中读取边，但在GUI中我们可能需要从其他地方获取
            // 为了简化，我们使用随机生成的边
            x = i;
            y = i + 1;
            e[2*i-1] = (Edge){x, y, g[x]};
            g[x] = 2*i-1;
            e[2*i] = (Edge){y, x, g[y]};
            g[y] = 2*i;
        }

        dfs(1, 0);
        weight = findWeight();
        dfs(weight, 0);

        setto(son[weight], weight);
        dfs2(weight, 0, weight);

        for(int i=1; i<=n; i++) {
            if(i==weight) continue;
            solve(i);
            solve2(i);
        }

        totalAns += ans;
        result += QString("测试用例 %1: n=%2, ans=%3\n").arg(caseNum).arg(n).arg(ans);
    }

    return totalAns;
}

// 主窗口类
class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // 初始化UI
        setupUI();

        // 创建系统托盘图标
        createSystemTrayIcon();
    }

protected:
    // 关闭窗口事件处理
    void closeEvent(QCloseEvent *event) override {
        // 窗口关闭时不退出程序，而是隐藏到系统托盘
        hide();
        event->ignore();

        // 显示托盘通知
        if (trayIcon) {
            trayIcon->showMessage("查错进阶", "程序已最小化到系统托盘，右键托盘图标可退出程序", QSystemTrayIcon::Information, 2000);
        }
    }

private slots:
    void onRunButtonClicked() {
        // 获取输入值
        int t = tSpinBox->value();
        n = nSpinBox->value();

        // 禁用运行按钮
        runButton->setEnabled(false);
        progressBar->setVisible(true);
        progressBar->setValue(0);

        // 模拟进度
        for(int i = 0; i <= 100; i += 10) {
            progressBar->setValue(i);
            QApplication::processEvents();
            QThread::msleep(50);
        }

        // 运行算法
        QString result;
        long long totalAns = runAlgorithm(t, result);

        // 显示结果
        resultTextEdit->clear();
        resultTextEdit->append(result);
        resultTextEdit->append(QString("\n总计结果: %1").arg(totalAns));

        // 恢复UI状态
        runButton->setEnabled(true);
        progressBar->setVisible(false);

        // 如果托盘图标可用，显示通知
        if (trayIcon) {
            trayIcon->showMessage("计算完成", QString("计算已完成，总计结果: %1").arg(totalAns), QSystemTrayIcon::Information, 2000);
        }
    }

private:
    // UI组件
    QSpinBox *tSpinBox;
    QSpinBox *nSpinBox;
    QPushButton *runButton;
    QTextEdit *resultTextEdit;
    QProgressBar *progressBar;
    QSystemTrayIcon *trayIcon;

    void setupUI() {
        // 创建主布局
        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        // 创建输入组
        QGroupBox *inputGroup = new QGroupBox("输入参数", this);
        QGridLayout *inputLayout = new QGridLayout(inputGroup);

        // t参数输入
        inputLayout->addWidget(new QLabel("测试用例数量 (t):"), 0, 0);
        tSpinBox = new QSpinBox(this);
        tSpinBox->setRange(1, 100);
        tSpinBox->setValue(1);
        inputLayout->addWidget(tSpinBox, 0, 1);

        // n参数输入
        inputLayout->addWidget(new QLabel("节点数量 (n):"), 1, 0);
        nSpinBox = new QSpinBox(this);
        nSpinBox->setRange(2, 100000);
        nSpinBox->setValue(10);
        inputLayout->addWidget(nSpinBox, 1, 1);

        // 运行按钮
        runButton = new QPushButton("运行算法", this);
        connect(runButton, &QPushButton::clicked, this, &MainWindow::onRunButtonClicked);
        inputLayout->addWidget(runButton, 2, 0, 1, 2);

        // 进度条
        progressBar = new QProgressBar(this);
        progressBar->setVisible(false);
        inputLayout->addWidget(progressBar, 3, 0, 1, 2);

        // 结果显示区域
        QGroupBox *resultGroup = new QGroupBox("计算结果", this);
        QVBoxLayout *resultLayout = new QVBoxLayout(resultGroup);

        resultTextEdit = new QTextEdit(this);
        resultTextEdit->setReadOnly(true);
        resultTextEdit->setFont(QFont("Consolas, Monaco, monospace", 10));
        resultLayout->addWidget(resultTextEdit);

        // 添加到主布局
        mainLayout->addWidget(inputGroup);
        mainLayout->addWidget(resultGroup);

        // 设置窗口标题和大小
        setWindowTitle("查错进阶 - GUI版");
        resize(800, 600);
    }

    void createSystemTrayIcon() {
        // 创建托盘图标
        trayIcon = new QSystemTrayIcon(this);

        // 创建一个简单的图标
        QPixmap pixmap(32, 32);
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        painter.setRenderHint(QPainter::Antialiasing);

        // 绘制一个简单的图标
        QPen pen(Qt::darkBlue, 2);
        painter.setPen(pen);
        QBrush brush(Qt::lightGray);
        painter.setBrush(brush);
        painter.drawRoundedRect(5, 5, 22, 22, 5, 5);

        // 添加文字 "C"
        QFont font = painter.font();
        font.setBold(true);
        font.setPointSize(16);
        painter.setFont(font);
        painter.drawText(5, 5, 22, 22, Qt::AlignCenter, "C");

        QIcon icon(pixmap);
        trayIcon->setIcon(icon);

        // 创建托盘菜单
        QMenu *trayMenu = new QMenu(this);

        // 显示/隐藏窗口动作
        QAction *showAction = new QAction("显示/隐藏", this);
        connect(showAction, &QAction::triggered, this, [this]() {
            if (isVisible()) {
                hide();
            } else {
                show();
                raise();
                activateWindow();
            }
        });

        // 退出动作
        QAction *quitAction = new QAction("退出", this);
        connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

        // 添加动作到菜单
        trayMenu->addAction(showAction);
        trayMenu->addSeparator();
        trayMenu->addAction(quitAction);

        // 设置托盘菜单
        trayIcon->setContextMenu(trayMenu);

        // 显示托盘图标
        trayIcon->show();

        // 设置托盘提示
        trayIcon->setToolTip("查错进阶 - 点击显示/隐藏窗口");

        // 双击托盘图标显示/隐藏窗口
        connect(trayIcon, &QSystemTrayIcon::activated, this, [this](QSystemTrayIcon::ActivationReason reason) {
            if (reason == QSystemTrayIcon::DoubleClick) {
                if (isVisible()) {
                    hide();
                } else {
                    show();
                    raise();
                    activateWindow();
                }
            }
        });
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 设置应用程序信息
    app.setApplicationName("查错进阶");
    app.setOrganizationName("查错进阶团队");

    // 创建并显示主窗口
    MainWindow window;
    window.show();

    return app.exec();
}

#include "查错进阶GUI.moc"
