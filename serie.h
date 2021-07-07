#ifndef SERIE_H
#define SERIE_H
#include "mediafile.h"

class Serie : public Mediafile
{
private:
    int currentEpisode;
    int totalEpisodes;
public:
    Serie(std::string _title, int _length, std::string _genre, int _currentEpisode, int _totalEpisodes);
    void playback();
    void showMeta();
};

#endif // SERIE_H
