/*****************************************************************************
 * Copyright: 2011-2013 Michael Zanetti <michael_zanetti@gmx.net>            *
 *            2014      Robert Meijers <robert.meijers@gmail.com>            *
 *                                                                           *
 * This file is part of Xbmcremote                                           *
 *                                                                           *
 * Xbmcremote is free software: you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation, either version 3 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * Xbmcremote is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License for more details.                              *
 *                                                                           *
 * You should have received a copy of the GNU General Public License         *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
 *                                                                           *
 ****************************************************************************/

import QtQuick 2.0
import Sailfish.Silica 1.0

Row {
    id: playerControls

    property QtObject player: xbmc.activePlayer
    property QtObject currentItem: player ? player.currentItem : null

    anchors.horizontalCenter: parent.horizontalCenter
    visible: player

    IconButton {
        icon.source: "image://theme/icon-m-previous"
        onClicked: playerControls.player.skipPrevious()
    }

    IconButton {
        icon.source: "../icons/icon-m-stop.png"
        onClicked: playerControls.player.stop()
    }

    IconButton {
        icon.source: "image://theme/icon-m-" + (playerControls.player && playerControls.player.state === "playing" ? "pause" : "play")
        onClicked: playerControls.player.playPause()
    }

    IconButton {
        icon.source: "image://theme/icon-m-next"
        onClicked: playerControls.player.skipNext()
    }
}
