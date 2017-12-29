#include <cstring>
#include <iostream>
#include <sys/stat.h>
#include "FileHandler.hpp"

/*
** META
*/

FileHandler::FileHandler(const std::string & path)
{
  _file.open(path.c_str(), std::ios::in|std::ios::out);
  if (!_file.good()) {
    std::cerr << strerror(errno) << std::endl;
  }
  _path = path;
}

FileHandler::~FileHandler()
{
  if (_file.is_open()) {
    _file.close();
  }
}

/*
** MEMBER FUNCTIONS
*/

std::string		FileHandler::getLine(const char delim)
{
  std::string		line("");
  char			c;

  if (_file.is_open()) {
    while ((c = _file.get()) != EOF) {
      if (c != '\n') {
	line.push_back(c);
      }
      if (c == delim) {
	break;
      }
    }
  }
  return line;
}

bool			FileHandler::fileExists(const std::string& path)
{
  struct stat		buff;

  return (!stat(path.c_str(), &buff));
}