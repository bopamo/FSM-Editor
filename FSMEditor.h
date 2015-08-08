#pragma once

/**
 * Main class of the FSM Editor project.
 * Include this QWidget in your application to use it.
 * The FSMEditor takes a Settings object in its constructor, that allows to customize the
 * editor, depending on the use-case.
 */

#include <QSplitter>

#include <fsm-editor/FSMScene.h>

#include <QGraphicsView>
#include <QUndoStack>

class QToolBar;
class QUndoCommand;
class QPlainTextEdit;
class Settings;
class FSMEditor : public QSplitter
{
  Q_OBJECT;
public:
  FSMEditor(Settings& settings);
  virtual ~FSMEditor();

  /**
   * Zoom in, in the graph view.
   */
  Q_SLOT void zoomIn();
  /**
  * Zoom out, in the graph view.
  */
  Q_SLOT void zoomOut();

  /**
   * Call a file dialog and save in the selected file.
   */
  Q_SLOT void saveAs();
  /**
   * Call a file dialog and load from the selected file.
   */
  Q_SLOT void load();

private:
  Q_SLOT void stackCommand(QUndoCommand* command);
  Q_SLOT void transferCodeChanged();
  Q_SLOT void displaySetCode(const QString& code);
  Q_SLOT void hideCode();

  void saveLastDir(QString fileName);

private:
  QWidget* makeViewPanel();
  void makeLuaEditor();

  void createSceneActions(QToolBar* toolbar);

  void loadSettings();
  void saveSettings();

private:
  static const QString LAST_DIR_KEY;
  static const QString LAST_ZOOM;
  static const QString LAST_SPLITS;
  static const QString LAST_GEOMETRY;

private:
  Settings& settings_;
  FSMScene scene_;
  QGraphicsView fsmView_;

  QUndoStack undoStack_;
  QPlainTextEdit* editor_;
  QString lastDir_;
};
