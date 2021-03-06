//=============================================================================
//  MusE Score
//  Linux Music Score Editor
//  $Id: editpitch.cpp 3775 2010-12-17 23:55:35Z miwarre $
//
//  Copyright (C) 2002-2009 Werner Schweer and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=============================================================================

#include "editpitch.h"

namespace Ms {

//---------------------------------------------------------
//   EditPitch
//    To select a MIDI pitch code using human-readable note names
//---------------------------------------------------------

EditPitch::EditPitch(QWidget *parent)
   : QDialog(parent)
      {
      setupUi(this);
      setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
      tableWidget->setCurrentCell(4, 0);                    // select centre C by default
      }

EditPitch::EditPitch(QWidget *parent, int midiCode)
   : QDialog(parent)
      {
      setupUi(this);
      setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
      tableWidget->setCurrentCell(9-(midiCode/12), midiCode%12);
      }

EditPitch::~EditPitch()
{

}

void EditPitch::changeEvent(QEvent *e)
      {
      QDialog::changeEvent(e);
      switch (e->type()) {
            case QEvent::LanguageChange:
                  retranslateUi(this);
                  break;
            default:
            break;
            }
      }

void EditPitch::accept()
      {
      int   col = tableWidget->currentColumn();
      int   row = tableWidget->currentRow();

      // topmost row contains notes for 9-th MIDI octave (numbered as '8')
      done( (9 - row)*12 + col);
      }

void EditPitch::on_tableWidget_cellDoubleClicked(int row, int col)
      {
      done( (9 - row)*12 + col);
      }
}

