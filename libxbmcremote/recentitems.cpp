/*****************************************************************************
 * Copyright: 2013 Michael Zanetti <michael_zanetti@gmx.net>                 *
 *                                                                           *
 * This file is part of xbmcremote                                           *
 *                                                                           *
 * xbmcremote is free software: you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation, either version 3 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * xbmcremote is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License for more details.                              *
 *                                                                           *
 * You should have received a copy of the GNU General Public License         *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
 *                                                                           *
 ****************************************************************************/

#include "recentitems.h"

#include "albums.h"
#include "songs.h"
#include "movies.h"
#include "episodes.h"
#include "musicvideos.h"
#include "xbmcconnection.h"
#include "libraryitem.h"

RecentItems::RecentItems(Mode mode, RecentlyWhat what, XbmcLibrary *parent):
    XbmcLibrary(parent),
    m_what(what)
{
    setBusy(false);
    if (mode == ModeAudio) {
        LibraryItem *item = new LibraryItem(tr("Albums"));
        item->setFileType("directory");
        item->setPlayable(false);
        item->setProperty("id", 0);
        m_list.append(item);

        item = new LibraryItem(tr("Songs"));
        item->setFileType("directory");
        item->setPlayable(false);
        item->setProperty("id", 1);
        m_list.append(item);
    } else if (mode == ModeVideo) {
        LibraryItem *item = new LibraryItem(tr("Movies"));
        item->setFileType("directory");
        item->setPlayable(false);
        item->setProperty("id", 2);
        m_list.append(item);

        item = new LibraryItem(tr("Episodes"));
        item->setFileType("directory");
        item->setPlayable(false);
        item->setProperty("id", 3);
        m_list.append(item);

        item = new LibraryItem(tr("Music Videos"));
        item->setFileType("directory");
        item->setPlayable(false);
        item->setProperty("id", 4);
        m_list.append(item);
    }
}

XbmcModel *RecentItems::enterItem(int index)
{
    int id = XbmcModel::ItemIdRecentlyPlayed;
    if (m_what == RecentlyAdded) {
        id = XbmcModel::ItemIdRecentlyAdded;
    }

    switch(m_list.at(index)->property("id").toInt()) {
    case 0:
        return new Albums(id, this);
    case 1:
        return new Songs(id, id, this);
    case 2:
        return new Movies(true, this);
    case 3:
        return new Episodes(id, id, QString(), this);
    case 4:
        return new MusicVideos(true, this);
    }
    return 0;
}

void RecentItems::playItem(int index)
{
    Q_UNUSED(index)
    qDebug() << "cannot play whole recently added items";
}

void RecentItems::addToPlaylist(int index)
{
    Q_UNUSED(index)
}

QString RecentItems::title() const
{
    return tr("Recently added");
}

bool RecentItems::allowSearch()
{
    return false;
}

void RecentItems::refresh()
{
}