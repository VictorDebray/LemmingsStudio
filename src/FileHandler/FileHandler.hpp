#ifndef			FILE_HANDLER_H
# define		FILE_HANDLER_H

# include		<fstream>

/*
** FileHandler class
**
** Constructor:		@param path/to/file
**			@param error message
**
** getPath()		@return file path.
** getLine()		@return next line of the file.
*/

class			FileHandler
{
  private:
    std::string		_path;
    std::fstream	_file;
  public:
  			FileHandler(const std::string &);
			~FileHandler();
    std::string		getLine(const char delim = '\n');
    static bool		fileExists(const std::string&);
};

#endif			/* !FILE_HANDLER_H */
