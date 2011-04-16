#ifndef XBMC_H
#define XBMC_H

#include <QList>
#include <QObject>
#include <QVariantMap>

namespace Xbmc
{

class AudioLibrary;
class Files;
class Player;

class Xbmc: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)
    Q_PROPERTY(QString state READ state NOTIFY stateChanged)
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(QString vfsPath READ vfsPath NOTIFY vfsPathChanged)

public:
    Xbmc(QObject *parent = 0);

    QString state();

    int volume();

    Player *audioPlayer();
    Player *videoPlayer();

    Player *activePlayer();

    AudioLibrary *audioLibrary();

    Files *files();

    bool connected();

    QString vfsPath();

public slots:
    void setVolume(int volume);
    void toggleMute();

signals:
    void connectedChanged();
    void vfsPathChanged();
    void stateChanged();
    void activePlayerChanged(Player *player);
    void volumeChanged(int volume);

private:
    enum Request {
        RequestActivePlayer,
        RequestVolume
    };

    Player *m_audioPlayer;
    Player *m_videoPlayer;
    Player *m_activePlayer;
    Files *m_files;

    AudioLibrary *m_audioLibrary;

    int m_volume;

    QMap<int, Request> m_requestMap;

private slots:
    void parseAnnouncement(const QVariantMap &map);
    void responseReceived(int id, const QVariantMap &rsp);

};

}
#endif // XBMC_H

