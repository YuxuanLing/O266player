/*****************************************************************************
 * main_inteface.cpp : Main interface
 ****************************************************************************
 * Copyright (C) 2000-2005 the VideoLAN team
 * $Id: wxwidgets.cpp 15731 2006-05-25 14:43:53Z zorglub $
 *
 * Authors: Clément Stenac <zorglub@videolan.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA. *****************************************************************************/

#include "dialogs_provider.hpp"
#include "qt4.hpp"
#include <QEvent>
#include "dialogs/playlist.hpp"

DialogsProvider* DialogsProvider::instance = NULL;

DialogsProvider::DialogsProvider( intf_thread_t *_p_intf ) : QObject(),
                                  p_intf( _p_intf )
{
    fprintf( stderr, "QT DP" );
}
DialogsProvider::~DialogsProvider()
{
}

void DialogsProvider::customEvent( QEvent *event )
{
    if( event->type() == DialogEvent_Type )
    {
        DialogEvent *de = dynamic_cast<DialogEvent*>(event);
        switch( de->i_dialog )
        {
            case INTF_DIALOG_FILE:
            case INTF_DIALOG_DISC:
            case INTF_DIALOG_NET:
            case INTF_DIALOG_CAPTURE:
                openDialog( de->i_dialog ); break;
            case INTF_DIALOG_PLAYLIST:
                playlistDialog(); break;
            case INTF_DIALOG_MESSAGES:
                messagesDialog(); break;
            case INTF_DIALOG_PREFS:
               prefsDialog(); break;
            case INTF_DIALOG_POPUPMENU:
            case INTF_DIALOG_AUDIOPOPUPMENU:
            case INTF_DIALOG_VIDEOPOPUPMENU:
            case INTF_DIALOG_MISCPOPUPMENU:
               popupMenu( de->i_dialog ); break;
            case INTF_DIALOG_VLM:
            case INTF_DIALOG_INTERACTION:
            case INTF_DIALOG_BOOKMARKS:
            case INTF_DIALOG_FILEINFO:
            case INTF_DIALOG_WIZARD:
            default:
               fprintf( stderr, "Unimplemented dialog\n");
        }
        fprintf( stderr, "Showing dialog\n");
    }
}

void DialogsProvider::playlistDialog()
{
    PlaylistDialog::getInstance( p_intf )->toggleVisible();
}

void DialogsProvider::openDialog( int i_dialog )
{
}

void DialogsProvider::prefsDialog()
{
}

void DialogsProvider::messagesDialog()
{
}

void DialogsProvider::popupMenu( int i_dialog )
{

}
