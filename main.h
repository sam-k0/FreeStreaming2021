#ifndef MAIN_H
#define MAIN_H
#include <string>

void playAllVideos();
void showVideoLibrary();
bool playOneVideo();
void addRatingToVideo();
bool loadVideoDatabase(std::string _defaultPath);
bool saveVideoDatabase(std::string _defaultPath);
void end();

void showMenu();

#endif // MAIN_H
