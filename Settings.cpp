#include<fsm-editor/Settings.h>

#include <QCoreApplication>
#include <QRegExp>

void Settings::initializeCodeHighlighter(QTextDocument* document)
{}

QString Settings::getExportExtension() const
{
  return "fsm";
}

QString Settings::getOrganizationName() const
{
  QString res = QCoreApplication::organizationName();
  if (res.isEmpty())
  {
    res = "FSM Editor Corp.";
  }
  return res;
}

QString Settings::getApplicationName() const
{
  QString res = QCoreApplication::applicationName();
  if (res.isEmpty())
  {
    res = "FSM Editor";
  }
  return res;
}

QString Settings::validateStateName(const QString& name)
{
  return "";
}

bool Settings::showMenu()
{
  return true;
}

bool Settings::showFileActions()
{
  return true;
}

QString Settings::validateCode(const QString& valid)
{
  if (valid.count("{") > valid.count("}"))
    return QObject::tr("Missing %1 closing curly brace(s)").arg(valid.count("{") - valid.count("}"));
  if (valid.count("{") < valid.count("}"))
    return QObject::tr("Missing %1 opening curly brace(s)").arg(valid.count("}") - valid.count("{"));
  return "";
}
