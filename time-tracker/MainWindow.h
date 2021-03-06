#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSystemTrayIcon>

#include "Statistics.h"
#include "IssueManager.h"

class IssueTableWidget;
class QTableWidget;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow() override;
	void login();

private slots:
	void on_btn_update_issues_clicked();
	void on_issue_selected(Issue::Id id);
	void on_stop_watch_stopped();
	void on_stop_watch_time_updated(const QString& str);
	void on_btn_apply_times_clicked();
	void on_btn_add_issue_clicked();
	void on_issue_added(Issue::Id id);
	void on_issue_edit_triggered(Issue::Id id);

	void on_btn_about_clicked();

protected:
	void keyPressEvent(QKeyEvent *event) override;
	void closeEvent(QCloseEvent* event) override;

private:
	void open_database();
	void create_system_tray_menu();

	Ui::MainWindow *ui;
	IssueManager issue_manager;
	QSystemTrayIcon tray_icon;
	QAction* stop_action;
};

#endif // MAINWINDOW_H
