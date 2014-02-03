/*****************************************************************************
 * Copyright: 2011-2013 Michael Zanetti <michael_zanetti@gmx.net>            *
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

Dialog {
    id: authenticationDialog

    property string hostname

    DialogHeader {
        id: header
        acceptText: qsTr("Authenticate")
    }

    Column {
        anchors {top: header.bottom; bottom: parent.bottom; left: parent.left; right: parent.right; margins: Theme.paddingMedium }

        Label {
            text: qsTr("XBMC on %1 requires authentication:").arg(hostname);
            wrapMode: Text.WordWrap
            font.family: Theme.fontFamilyHeading
            color: Theme.highlightColor
        }

        Label {
            text: qsTr("Username:")
        }

        TextField {
            id: username
            width: parent.width
        }

        Label {
            text: qsTr("Password:")
        }
        TextField {
            id: password
            width: parent.width
        }
    }

    onAccepted: {
        xbmc.setAuthCredentials(username.text, password.text);
    }
}
