#include "serie.h"
#include <string>
#include <iostream>
using namespace std;
Serie::Serie(std::string _title, int _length, std::string _genre, int _currentEpisode, int _totalEpisodes)
{
   title = _title;
   length = _length;
   genre = _genre;
   currentEpisode = _currentEpisode;
   totalEpisodes = _totalEpisodes;
   avgrating = 0;
   totalratings = 0;
}

void Serie::playback()
{
    currentEpisode += 1;
    if(currentEpisode > totalEpisodes) // start over
    {
        currentEpisode = 1;
    }
    std::cout <<"INFO : SERIES : "<< title<<": Now watching EP "<<currentEpisode<<"/"<<totalEpisodes<<"."<<std::endl;
}

void Serie::showMeta()
{
    cout << ">> SERIES : Information on movie"<<endl;
    cout << "|--Title: " << title << endl;
    cout << "|--Avg. Duration (min): " << length << endl;
    cout << "|--Rating: " << avgrating <<" (based off "<< ratings.size() << " ratings)"<< endl;
    cout << "|--Genre: " << genre << endl;
    cout << "|--Episodes: " << totalEpisodes << endl;
}
