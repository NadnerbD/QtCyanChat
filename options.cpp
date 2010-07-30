#include "options.h"
#include "cyanchat.h"
#include "ui_options.h"

Options::Options(CyanChat *parent) : QDialog(parent), ui(new Ui::Options), cc(parent) {
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(updateOptions()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));
    ui->minimizeTrayBox->setChecked(cc->minimizeToTray);
    ui->alwaysShowTrayBox->setChecked(cc->alwaysShowTray);
    ui->highlightNickBox->setChecked(cc->highlightLocalName);
    ui->reformatActionsBox->setChecked(cc->reformatActions);
    ui->timestampsBox->setChecked(cc->displayTimestamps);
    ui->timestampFormatBox->setText(cc->timestampFormat);
    ui->autoConnectBox->setChecked(cc->connectOnStartup);
    ui->autoLoginBox->setChecked(cc->setNameOnConnect);
    ui->autoPMBox->setChecked(cc->autoCreatePMTabs);
    ui->plainLogBox->setChecked(cc->writePlainLog);
    ui->htmlLogBox->setChecked(cc->writeHTMLLog);
    ui->logAnnounceBox->setChecked(cc->logClientAnnounce);
    ui->logTimestampsBox->setChecked(cc->logTimestamps);
    ui->hostBox->setText(cc->host);
    ui->portBox->setText(QString::number(cc->port));
    ui->nameBox->setText(cc->defaultName);
    ui->plainFileBox->setText(cc->plainLog);
    ui->htmlFileBox->setText(cc->HTMLLog);
    ui->fontSizeBox->setValue(cc->fontSize);
    ui->showOrigNamesBox->setChecked(cc->showOrigNames);
    // TEMP: disable nonfunctional controls
    ui->listOptionsBox->hide();
    // not sure if I'm going to make the shortcuts modifiable
    ui->setNameShortcutBox->hide();
    ui->closeTabShortcutBox->hide();
    ui->switchTabsShortcutBox->hide();
    ui->setNameLabel->hide();
    ui->closeTabLabel->hide();
    ui->switchTabsLabel->hide();
    // Set the version shown in the about tab
    QString verText = ui->AboutLabel->text();
    verText.replace("%version%", CC_VERSION);
    ui->AboutLabel->setText(verText);
}

Options::~Options() {
    delete ui;
}

void Options::updateOptions() {
    cc->minimizeToTray = ui->minimizeTrayBox->isChecked();
    cc->alwaysShowTray = ui->alwaysShowTrayBox->isChecked();
    cc->setTrayVis(cc->alwaysShowTray);
    cc->highlightLocalName = ui->highlightNickBox->isChecked();
    cc->reformatActions = ui->reformatActionsBox->isChecked();
    cc->displayTimestamps = ui->timestampsBox->isChecked();
    cc->timestampFormat = ui->timestampFormatBox->text();
    cc->connectOnStartup = ui->autoConnectBox->isChecked();
    cc->setNameOnConnect = ui->autoLoginBox->isChecked();
    cc->autoCreatePMTabs = ui->autoPMBox->isChecked();
    cc->writePlainLog = ui->plainLogBox->isChecked();
    cc->writeHTMLLog = ui->htmlLogBox->isChecked();
    cc->logClientAnnounce = ui->logAnnounceBox->isChecked();
    cc->logTimestamps = ui->logTimestampsBox->isChecked();
    cc->host = ui->hostBox->text();
    cc->port = ui->portBox->text().toInt();
    cc->defaultName = ui->nameBox->text();
    cc->plainLog = ui->plainFileBox->text();
    cc->HTMLLog = ui->htmlFileBox->text();
    cc->fontSize = ui->fontSizeBox->value();
    cc->showOrigNames = ui->showOrigNamesBox->isChecked();
    cc->writeSettings();
    cc->refreshUserListSlot();
    close();
}

void Options::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
	ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
