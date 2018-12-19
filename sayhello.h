#ifndef SAYHELLO_H
#define SAYHELLO_H

///
/// \brief initSayHello allocates memory for strings.
/// \param str main message.
/// \param endLine symbols of end of line. Default is "\n"
/// \return length of main message.
///
int initSayHello(const char *str, const char *endLine = "\n");

///
/// \brief closeSayHello free memory.
///
void closeSayHello(void);

///
/// \brief sayHello print message to stdout.
///
void sayHello(void);

///
/// \brief version
/// \return number of current version.
///
int version(void);


#endif //SAYHELLO_H
